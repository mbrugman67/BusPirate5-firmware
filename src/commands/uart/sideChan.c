/*************************************************************
 * commands/uart/sideChan.c
 *************************************************************
 *
 ************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pirate.h"
#include "pirate/bio.h"
#include "pirate/storage.h"
#include "system_config.h"
#include "command_struct.h"
#include "ui/ui_term.h"
#include "ui/ui_help.h"
#include "ui/ui_cmdln.h"
#include "ui/ui_prompt.h"
#include "bytecode.h"
#include "pirate/button.h"

#include "hardware/pio.h"
#include "pio_config.h"
#include "sideChan.pio.h"

// password alphabet
static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// uncomment below if all of the definitions in src/debug_rtt.c/h have
// been done for this
//#define BP_DEBUG_OVERRIDE_DEFAULT_CATEGORY BP_DEBUG_CAT_GLITCH
//

// maximum number of characters to receive in glitch loop
#define RX_CHAR_LIMIT 20
#define MAX_PASSWD_LEN 40

static const char* const usage[] = { "sidechan\t[-h(elp)]",
                                     "UART side channel scanner",
                                     "Exit: press Bus Pirate button" };
// config struct
typedef struct _uart_sidechan_config {
    uint32_t scan_trg;          // character sent from BP UART to trigger the timing scan
    uint32_t max_password_len;  // max password length
} _uart_sidechan_config;

static struct _uart_sidechan_config uart_sidechan_config;

// help text
static const struct ui_help_options options[] = {
    { 1, "", T_HELP_UART_SIDECHAN }, // command help
    { 0, "-h", T_HELP_FLAG }, // help
};

// timer stuffs
static repeating_timer_t ticker;
static uint32_t tick_count_ms = 0;

// pio struct
static struct _pio_config uart_sidechan_pio;

/******************************************************
 * CONFIGURATION PARAMETERS FOR SIDE CHANNEL SCANNING *
 ******************************************************
 * .scan_trg - character to trigger side channel timing
 * .max_password_len - maximum password length for timing
 *****************************************************/
static const struct prompt_item uart_sidechan_trg_menu[] = { { T_UART_SIDECHAN_TRG_MENU_1 } };
static const struct prompt_item uart_sidechan_len_menu[] = { { T_UART_SIDECHAN_LEN_MENU_1 } };

static const struct ui_prompt uart_menu[] = { [0] = { .description = T_UART_SIDECHAN_TRG_MENU_1,
                                                      .menu_items = uart_sidechan_trg_menu,
                                                      .menu_items_count = count_of(uart_sidechan_trg_menu),
                                                      .prompt_text = T_UART_SIDECHAN_TRG_MENU_PROMPT,
                                                      .minval = 1,
                                                      .maxval = 255,
                                                      .defval = 13,
                                                      .menu_action = 0,
                                                      .config = &prompt_int_cfg },
                                              [1] = { .description = T_UART_SIDECHAN_LEN_MENU_1,
                                                      .menu_items = uart_sidechan_len_menu,
                                                      .menu_items_count = count_of(uart_sidechan_len_menu),
                                                      .prompt_text = T_UART_SIDECHAN_LEN_MENU_PROMPT,
                                                      .minval = 1,
                                                      .maxval = MAX_PASSWD_LEN,
                                                      .defval = 8,
                                                      .menu_action = 0,
                                                      .config = &prompt_int_cfg }
                                                      };

void sidechan_settings(void) {
    ui_prompt_mode_settings_int(GET_T(T_UART_SIDECHAN_TRG_MENU), uart_sidechan_config.scan_trg, "(ASCII)");
    ui_prompt_mode_settings_int(GET_T(T_UART_SIDECHAN_LEN_MENU), uart_sidechan_config.max_password_len, 0x00);
}

/******************************************************
 * Load config data, if file exists.  Prompt user to
 * enter config stuff, accept, or get out
 *****************************************************/
uint32_t uart_sidechan_setup(void) {
    uint32_t temp;
    prompt_result result;

    const char config_file[] = "usidechn.bp";
    const mode_config_t config_t[] = {
        // clang-format off
        { "$.trigger", &uart_sidechan_config.scan_trg, MODE_CONFIG_FORMAT_DECIMAL },
        { "$.pwlen", &uart_sidechan_config.max_password_len, MODE_CONFIG_FORMAT_DECIMAL }
        // clang-format off
    };

    if (storage_load_mode(config_file, config_t, count_of(config_t))) {
        printf("\r\n\r\n%s%s%s\r\n", ui_term_color_info(),
            GET_T(T_USE_PREVIOUS_SETTINGS),
            ui_term_color_reset());

        sidechan_settings(); 

        bool user_value;
        if (!ui_prompt_bool(&result, true, true, true, &user_value)) {
            return (0);
        }
        if (user_value) {
            return (1); // user said yes, use the saved settings
        }
    }

    ui_prompt_uint32(&result, &uart_menu[0], &temp);
    if (result.exit) {
        return 0;
    }
    uart_sidechan_config.scan_trg = temp;

    ui_prompt_uint32(&result, &uart_menu[1], &temp);
    if (result.exit) {
        return 0;
    }
    uart_sidechan_config.max_password_len = temp;
    printf("\r\n");
    
    return (storage_save_mode(config_file, config_t, count_of(config_t)));
}

/******************************************************** 
 * Enable PIO and get ready to go
 *******************************************************/
bool setup_uart_sidechan_hardware() {
    PRINT_INFO("sidechan::Entering setup_uart_sidechan_hardware()\r\n");
    bio_put(M_UART_RTS, 0);

    uart_sidechan_pio.pio = PIO_MODE_PIO;
    uart_sidechan_pio.sm = 0;
    uart_sidechan_pio.program = &uart_sidechan_program;
    uart_sidechan_pio.offset = pio_add_program(uart_sidechan_pio.pio, uart_sidechan_pio.program);

    uart_sidechan_program_init(uart_sidechan_pio.pio,
                               uart_sidechan_pio.sm,
                               uart_sidechan_pio.offset,
                               bio2bufiopin[M_UART_TX],
                               bio2bufiopin[M_UART_RX]);

    return (true);
}

/********************************************************
 * Remove the PIO program
 *******************************************************/
void teardown_uart_sidechan_hardware() {
    PRINT_INFO("sidechan::Entering teardown_hardware()\r\n");
    bio_put(M_UART_RTS, 1);

    pio_remove_program(uart_sidechan_pio.pio, uart_sidechan_pio.program, uart_sidechan_pio.offset);
}

/******************************************************
 * Main side channel handler.
 ******************************************************/
void uart_side_chan_handler(struct command_result* res) {
    PRINT_INFO("sidechan::Starting main side channel handler\r\n");

    if (ui_help_show(res->help_flag, usage, count_of(usage), &options[0], count_of(options))) {
        return;
    }

    // Go get/set up config for glitching
    if (!uart_sidechan_setup()) {
        printf("%s%s%s\r\n", ui_term_color_error(), GET_T(T_UART_SIDECHAN_SETUP_ERR), ui_term_color_reset());
        return;
    }

    if (!ui_help_check_vout_vref()) {
        return;
    }

    // set up and enable the two hardware pins, start the PIO program
    if (!setup_uart_sidechan_hardware())
    {
        return;
    }

    printf("\r\n%sUART side channel scanning.  Press Bus Pirate button to exit.%s\r\n",
        ui_term_color_info(), ui_term_color_reset());

    // get the number of edges in the trigger character.  This is UART
    // serial, so if two consecutive bits are high, it's just one edge;
    // that's what the goofy last_was_high thing is all about.
    uint32_t edges = 0;
    bool last_was_high = false;
    for (uint32_t ii = 0; ii < 8; ++ii) {
        if (uart_sidechan_config.scan_trg & (1U << ii)) {
            ++edges;
            if (last_was_high) {
                --edges;
            }
            last_was_high = true;
        }
        else {
            last_was_high = false;
        }
    }

    bool cancelled = false;
    bool done = false;
    bool success = false;
    size_t alphabet_posn = 0;
    size_t current_pwd_len = 0;
    char password[MAX_PASSWD_LEN] = "";
    char max_char;
    uint32_t max_time = 0;
    uint32_t avg = 0;

    password[0] = alphabet[alphabet_posn];

    const char tests[][15] = {"A", "AA", "H", "HA", "HI", "HIC", "HI2015CHILLL"};
    uint32_t tests_count = 7;
    uint32_t this_test = 0;
    uint32_t this_test_iteration = 0;

    const uint32_t wtf = 170000;

    while (!cancelled && !done && !success) {
        // send the candidate password
        /* MKY MKY MKY
        for (size_t ii = 0; ii < strlen(password); ++ii) {
            uart_putc_raw(M_UART_PORT, password[ii]);
        }
        MKY MKY MKY */

        printf("Sending >%s< iteration %d ", tests[this_test], this_test_iteration + 1);

        for (uint32_t ii = 0; ii < strlen(tests[this_test]); ++ii) {
            uart_putc_raw(M_UART_PORT, tests[this_test][ii]);
        }

        if (done)   break;

        busy_wait_us_32(200 * strlen(tests[this_test]));

        // the statemachie is currently stalled waiting for these tow values to 
        // be stuffed into the FIFO - the first is the preload for the counter
        // which is set to max UINT_16, and the other is the number of edges to 
        // 
        pio_sm_put_blocking(uart_sidechan_pio.pio, uart_sidechan_pio.sm, wtf);
        pio_sm_put_blocking(uart_sidechan_pio.pio, uart_sidechan_pio.sm, edges);

        // now send the "trigger" character
        uart_putc_raw(M_UART_PORT, (char)(uart_sidechan_config.scan_trg & 0xff));

       // wait for a char to be RX'd.  Allow the button
        // to break us out, if necessary
        while (!uart_is_readable(M_UART_PORT) && !cancelled) {
            if (button_get(0)) {
                cancelled = true;
            }
        }

        if (cancelled)  break;

        // if we got a character here, then we should have something in the 
        // FIFO from the PIO SM.
        /* MKY MKY MKY
        uint32_t count = pio_sm_get_blocking(uart_sidechan_pio.pio, uart_sidechan_pio.sm) - 0xffff;
        if (count > max_time) {
            max_time = count;
            max_char = alphabet[alphabet_posn];
            printf("New max count %d for posn %d on char %c\r\n", 
                count, strlen(password), alphabet[alphabet_posn]);
        }
        MKY MKY MKY */

        uint32_t count = wtf - pio_sm_get_blocking(uart_sidechan_pio.pio, uart_sidechan_pio.sm);
        printf("count = %d\r\n", count);
        avg += count;

        ++this_test_iteration;
        if (this_test_iteration > 4) {
            this_test_iteration = 0;
            ++this_test;

            printf("-->Average: %0.1f\r\n", (float)avg / 5.0);
            printf("\r\n");
            avg = 0;
            if (this_test >= tests_count) {
                done = true;
            }
        }

        // read and discard any remaining RX chars before next try
        size_t char_read_count = 0;
        while (uart_is_readable(M_UART_PORT)) {
            char c = uart_getc(M_UART_PORT);
            ++char_read_count;
            busy_wait_us_32(100);
        }

        // next character in the alphabet
        /* MKY MKY MKY
        (++alphabet_posn) % strlen(alphabet);

        if (!alphabet_posn) {
            password[current_pwd_len - 1] = max_char;

            ++current_pwd_len;
            if ((current_pwd_len + 1) > strlen(password)) {
                done = true;
                max_time = 0;
            }
        }

        if (done)   break;

        password[current_pwd_len] = alphabet[alphabet_posn];
        MKY MKY MKY */

        // exit when button pressed.
        if (button_get(0)) {
            cancelled = true;
            break;
        }
    }
}
