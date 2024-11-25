/*************************************************************
 * commands/uart/glitch.c
 *************************************************************
 * This handles interfacing to a separate device to perform
 * glitching attacks on a target.
 *
 * In this case, the glitch is triggered by the sending of a
 * character over UART.  Starting at the stop bit, there will
 * be a short delay (specified by user), then an output will
 * be fired for a short time (again, specified by user).
 *
 * The glitch output is handled by a PIO to help keep timing
 * where we want it to be.  That's why you won't see the glitch
 * trigger output being directly controlled in the main glitch
 * loop.
 *
 * Typical usage:
 * + The target device is in a mode where it is awaiting a
 *   user-entered password over serial UART.  After the user
 *   sends a <RETURN> over UART, the device's firmware checks
 *   the password.
 * + The target does the password check; if the password is
 *   good, the code execution flow continues to other
 *   functionality.  If the password was wrong, the flow
 *   jumps back to the password prompt.
 * + The goal of the glitching in this case to to cause the
 *   program flow to "skip over" the code jump when there's
 *   a bad password.
 * + Two common methods to cause this "glitch":
 *   + Power glitching - the threat actor "shorts out" supply
 *     power to the microcontroller for a very, very short
 *     time just as that branch instruction should execute;
 *     this causes the microcontroller to skip over that branch
 *   + EMF/EMP glitching - the threat actor induces a short
 *     blast of electromagnetic "noise" at the microcontroller
 *     just as that branch instruction should execute.
 *
 * So, this module is used to time either of those two attacks.
 ************************************************************/

#include <stdio.h>
#include "pico/stdlib.h"
#include <stdint.h>
#include "hardware/uart.h"
#include "pirate.h"
#include "pirate/bio.h"
#include "pirate/storage.h"
#include "system_config.h"
#include "command_struct.h"
#include "ui/ui_term.h"
#include "ui/ui_help.h"
#include "bytecode.h"
#include "mode/hwuart.h"
#include "pirate/button.h"
#include "usb_rx.h"
#include "usb_tx.h"
#include "ui/ui_cmdln.h"
#include "ui/ui_prompt.h"

static const char* const usage[] = { "glitch\t[-h(elp)] [-c(onfig)]",
                                     "UART glitch generator",
                                     "Exit: press Bus Pirate button" };

typedef struct _uart_glitch_config {
    uint32_t glitch_trg;        // character sent from BP UART to trigger the glitch
    uint32_t glitch_delay;      // how long (us) after trigger stop bit to fire trigger
    uint32_t glitch_length;     // how long (us) to keep trigger high
    uint32_t glitch_recycle;    // minimum time (ms) between one glitch cycle and the next
    uint32_t fail_resp;         // first character response from device on bad password
    uint32_t retry_count;       // number of times to try glitching before quitting
} _uart_glitch_config;

static const struct ui_help_options options[] = {
    { 1, "", T_HELP_UART_GLITCH }, // command help
    { 0, "-t", T_HELP_UART_BRIDGE_TOOLBAR },
    { 0, "-h", T_HELP_FLAG }, // help
};

static const char pin_labels[][5] = { "TRG", "RDY" };

static struct _uart_glitch_config uart_glitch_config;


/*************************************************
 *    CONFIGURATION PARAMETERS FOR GLITCHING     *
 *************************************************
 * .glitch_trg - the ASCII character code that
 *    starts the glitch cycle.  Typcially a
 *    carraige return (ASCII code 13, '\n')
 * .glitch_dly - the delay time after sending
 *    the target character before the glitch
 *    ouput is turned on.  Usually a very short
 *    time, typically less than 20 microseconds
 * .glitch_len - the time to keep the glitch
 *    output on.  If power glitching, this should
 *    be very short.  Not enough to trip th
 *    brown-out reset, just enough to glitch the
 *    instruction.
 * .glitch_cyc - a short delay between turning off
 *    the glitch output and sending the character
 *    again.
 * .fail_char - the first ASCII character in
 *    the "normally bad password" response
 * .retry_count - max number of glitch cycles
 *    before giving up
 ************************************************/
static const struct prompt_item uart_glitch_trg_menu[] = { { T_UART_GLITCH_TRG_MENU_1 } };
static const struct prompt_item uart_glitch_dly_menu[] = { { T_UART_GLITCH_DLY_MENU_1 } };
static const struct prompt_item uart_glitch_len_menu[] = { { T_UART_GLITCH_LEN_MENU_1 } };
static const struct prompt_item uart_glitch_cyc_menu[] = { { T_UART_GLITCH_CYC_MENU_1 } };
static const struct prompt_item uart_glitch_fail_menu[] = { { T_UART_GLITCH_FAIL_MENU_1 } };
static const struct prompt_item uart_glitch_cnt_menu[] = { { T_UART_GLITCH_CNT_MENU_1 } };

static const struct ui_prompt uart_menu[] = { [0] = { .description = T_UART_GLITCH_TRG_MENU,
                                                      .menu_items = uart_glitch_trg_menu,
                                                      .menu_items_count = count_of(uart_glitch_trg_menu),
                                                      .prompt_text = T_UART_GLITCH_TRG_PROMPT,
                                                      .minval = 1,
                                                      .maxval = 255,
                                                      .defval = 13,
                                                      .menu_action = 0,
                                                      .config = &prompt_int_cfg },
                                              [1] = { .description = T_UART_GLITCH_DLY_MENU,
                                                      .menu_items = uart_glitch_dly_menu,
                                                      .menu_items_count = count_of(uart_glitch_dly_menu),
                                                      .prompt_text = T_UART_GLITCH_DLY_PROMPT,
                                                      .minval = 1,
                                                      .maxval = 255,
                                                      .defval = 1,
                                                      .menu_action = 0,
                                                      .config = &prompt_int_cfg },
                                              [2] = { .description = T_UART_GLITCH_LEN_MENU,
                                                      .menu_items = uart_glitch_len_menu,
                                                      .menu_items_count = count_of(uart_glitch_len_menu),
                                                      .prompt_text = T_UART_GLITCH_LEN_PROMPT,
                                                      .minval = 20,
                                                      .maxval = 500,
                                                      .defval = 20,
                                                      .menu_action = 0,
                                                      .config = &prompt_int_cfg },
                                              [3] = { .description = T_UART_GLITCH_CYC_MENU,
                                                      .menu_items = uart_glitch_cyc_menu,
                                                      .menu_items_count = count_of(uart_glitch_cyc_menu),
                                                      .prompt_text = T_UART_GLITCH_CYC_PROMPT,
                                                      .minval = 10,
                                                      .maxval = 1000,
                                                      .defval = 10,
                                                      .menu_action = 0,
                                                      .config = &prompt_int_cfg },
                                              [4] = { .description = T_UART_GLITCH_FAIL_MENU,
                                                      .menu_items = uart_glitch_fail_menu,
                                                      .menu_items_count = count_of(uart_glitch_fail_menu),
                                                      .prompt_text = T_UART_GLITCH_FAIL_PROMPT,
                                                      .minval = 1,
                                                      .maxval = 255,
                                                      .defval = 35,
                                                      .menu_action = 0,
                                                      .config = &prompt_int_cfg },
                                              [5] = { .description = T_UART_GLITCH_CNT_MENU,
                                                      .menu_items = uart_glitch_cnt_menu,
                                                      .menu_items_count = count_of(uart_glitch_cnt_menu),
                                                      .prompt_text = T_UART_GLITCH_CNT_PROMPT,
                                                      .minval = 1,
                                                      .maxval = 10000,
                                                      .defval = 100,
                                                      .menu_action = 0,
                                                      .config = &prompt_int_cfg },
                                                      };

void glitch_settings(void) {
    ui_prompt_mode_settings_int(GET_T(T_UART_GLITCH_TRG_MENU), uart_glitch_config.glitch_trg, "(ASCII)");
    ui_prompt_mode_settings_int(GET_T(T_UART_GLITCH_DLY_MENU), uart_glitch_config.glitch_delay, "us");
    ui_prompt_mode_settings_int(GET_T(T_UART_GLITCH_LEN_MENU), uart_glitch_config.glitch_length, "us");
    ui_prompt_mode_settings_int(GET_T(T_UART_GLITCH_CYC_MENU), uart_glitch_config.glitch_recycle, "ms");
    ui_prompt_mode_settings_int(GET_T(T_UART_GLITCH_FAIL_MENU), uart_glitch_config.fail_resp, "ASCII");
    ui_prompt_mode_settings_int(GET_T(T_UART_GLITCH_CNT_MENU), uart_glitch_config.retry_count, 0x00);
}

uint32_t uart_glitch_setup(void) {
    uint32_t temp;
    prompt_result result;

    const char config_file[] = "uglitch.bp";
    const mode_config_t config_t[] = {
        // clang-format off
        { "$.trigger", &uart_glitch_config.glitch_trg, MODE_CONFIG_FORMAT_DECIMAL },
        { "$.delay", &uart_glitch_config.glitch_delay, MODE_CONFIG_FORMAT_DECIMAL },
        { "$.length", &uart_glitch_config.glitch_length, MODE_CONFIG_FORMAT_DECIMAL },
        { "$.recycle", &uart_glitch_config.glitch_recycle, MODE_CONFIG_FORMAT_DECIMAL },
        { "$.failchar", &uart_glitch_config.fail_resp, MODE_CONFIG_FORMAT_DECIMAL },
        { "$.retries", &uart_glitch_config.retry_count, MODE_CONFIG_FORMAT_DECIMAL },
        // clang-format off
    };

    if (storage_load_mode(config_file, config_t, count_of(config_t))) {
        printf("\r\n\r\n%s%s%s\r\n", ui_term_color_info(), GET_T(T_USE_PREVIOUS_SETTINGS), ui_term_color_reset());
        glitch_settings(); 

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
    uart_glitch_config.glitch_trg = temp;

    ui_prompt_uint32(&result, &uart_menu[1], &temp);
    if (result.exit) {
        return 0;
    }
    uart_glitch_config.glitch_delay = temp;

    ui_prompt_uint32(&result, &uart_menu[2], &temp);
    if (result.exit) {
        return 0;
    }
    uart_glitch_config.glitch_length = temp;

    ui_prompt_uint32(&result, &uart_menu[3], &temp);
    if (result.exit) {
        return 0;
    }
    uart_glitch_config.glitch_recycle = temp;

    ui_prompt_uint32(&result, &uart_menu[4], &temp);
    if (result.exit) {
        return 0;
    }
    uart_glitch_config.fail_resp = temp;

    ui_prompt_uint32(&result, &uart_menu[5], &temp);
    if (result.exit) {
        return 0;
    }
    uart_glitch_config.retry_count = temp;

    printf("\r\n");
    
    storage_save_mode(config_file, config_t, count_of(config_t));
}

/********************************************************
 * Bus Pirate pins 0 and 1 are used for glitchhing:
 * - Pin 0 is the triggered glitch output (to be used to
 *   do the actual glitching by some other device)
 * - Pin 1 is an input used for the external glitching
 *   device to indicate its readiness.  For example, an
 *   EMP type device may need some time to recharge before
 *   its ready again.
 *******************************************************/
void setup_pins() {
    bio_set_function(M_UART_GLITCH_TRG, GPIO_FUNC_SIO);
    bio_set_function(M_UART_GLITCH_RDY, GPIO_FUNC_SIO);
    bio_output(M_UART_GLITCH_TRG);
    bio_input(M_UART_GLITCH_RDY);
    system_bio_claim(true, M_UART_GLITCH_TRG, BP_PIN_MODE, pin_labels[0]);
    system_bio_claim(true, M_UART_GLITCH_RDY, BP_PIN_MODE, pin_labels[1]);

    // set the trigger low right away
    bio_put(M_UART_GLITCH_TRG, 0);
}

void remove_pins() {
    system_bio_claim(false, M_UART_GLITCH_TRG, BP_PIN_MODE, 0);
    system_bio_claim(false, M_UART_GLITCH_RDY, BP_PIN_MODE, 0);
}

void uart_glitch_handler(struct command_result* res) {
    if (ui_help_show(res->help_flag, usage, count_of(usage), &options[0], count_of(options))) {
        return;
    }

    if (!uart_glitch_setup()) {
        printf("%s%s%s\r\n", ui_term_color_error(), GET_T(T_UART_GLITCH_SETUP_ERR), ui_term_color_reset());
        return;
    }

    if (!ui_help_check_vout_vref()) {
        return;
    }

    // the number of rising edges for the PIO to count before turning on
    // the output is the number of high bits in the ASCII value of the
    // glitch trigger character.  Count 'em up.
    uint32_t pio_edge_count = 0;
    bool last_bit_was_high = false;
    for (uint8_t ii = 0; ii < 7; ++ii)
    {
        if (1U << ii & uart_glitch_config.glitch_trg) {
            ++pio_edge_count;

            // oddball case here... if two (or more) consecutive
            // bits are high, the UART TX line doesn't go low
            // in between, so we need to decrement back down
            if (last_bit_was_high) --pio_edge_count;

            last_bit_was_high = true;
        } else {
            last_bit_was_high = false;
        }
    }

    // one more count for the stop bit (TODO - check for zero or two stop bits!)
    ++pio_edge_count;

    // (TODO - remove this)
    printf("Number of edges for %c (%d) is %d\n",
        (char)uart_glitch_config.glitch_trg,
        uart_glitch_config.glitch_trg,
        pio_edge_count);
    // (TODO - end remove this)

    bool toolbar_state = system_config.terminal_ansi_statusbar_pause;
    bool pause_toolbar = !cmdln_args_find_flag('t' | 0x20);
    if (pause_toolbar) {
        system_config.terminal_ansi_statusbar_pause = true;
    }

    printf("%s%s%s\r\n", ui_term_color_notice(), GET_T(T_HELP_UART_GLITCH_EXIT), ui_term_color_reset());
    
    // set up and enable the two hardware pins
    setup_pins();

    bool glitched = false;
    bool cancelled = false;
    bool done = false;
    uint32_t tries = 0;
    char c;
    char trigger_char = (char)uart_glitch_config.glitch_trg;
    char fail_resp_char = (char)uart_glitch_config.fail_resp;

    // The main glitch loop starts here
    // keep going until we either:
    // + succeed in glitching the device
    // + user presses the BP button
    // + we exceeded the max number of tries
    // Basic logic flow:
    // + wait until the device ready input is high
    // + serial out the glitch trigger character
    // + wait for some response
    // + parse that response - if it starts with the "normal bad
    //   password character" then assume glitch failed
    // + increment/test the max retries count
    // + wait for the backoff period before retrying
    while (!glitched && !cancelled && !done) {
        // check for external device ready; allow BP button to
        // exit
        while (!bio_get(M_UART_GLITCH_RDY)) {
            if (button_get(0)) {
                cancelled = true;
                break;
            }
        }

        // serial out the trigger character
        uart_putc_raw(M_UART_PORT, trigger_char);

        // wait for a char to be RX'd.  Allow the button
        // to break us out, if necessary
        while (!uart_is_readable(M_UART_PORT)) {
            if (button_get(0)) {
                cancelled = true;
                break;
            }
        }

        // start parsing the response from the device being glitched.
        // Ignore return & linefeed chars until we get the first
        // "real" character.  If that character is not the "normally
        // expected bad password character", then we consider the
        // glitch successful!
        while (uart_is_readable(M_UART_PORT)) {
            c = uart_getc(M_UART_PORT);

            if (c != '\r' && c != '\n') {
                if (fail_resp_char != c) {
                    glitched = true;
                }
                break;
            }
        }

        // clear the rx buffer for next try
        while (!uart_is_readable(M_UART_PORT)) {
            c = uart_getc(M_UART_PORT);
        }

        // exit when button pressed.
        if (button_get(0)) {
            cancelled = true;
        }

        // stop if we hit the max number of tries
        if (++tries >= uart_glitch_config.retry_count) {
            done = true;
        }

        // backoff wait time between cycles
        busy_wait_ms(uart_glitch_config.glitch_recycle);

    }

    // why did we break out of the glitch loop?
    if (glitched) {
        printf("%s%s%s\r\n", ui_term_color_notice(), GET_T(T_UART_GLITCH_GLITCHED), ui_term_color_reset());
    } else if (cancelled) {
        printf("%s%s%s\r\n", ui_term_color_notice(), GET_T(T_UART_GLITCH_CANCELLED), ui_term_color_reset());
    } else if (done) {
        printf("%s%s%s\r\n", ui_term_color_notice(), GET_T(T_UART_GLITCH_DONE), ui_term_color_reset());
    } else {
        printf("%s%s%s\r\n", ui_term_color_error(), GET_T(T_UART_GLITCH_UNKNOWN), ui_term_color_reset());
    }
    
    // we're done, release the two hardware pins
    remove_pins();

    if (pause_toolbar) {
        system_config.terminal_ansi_statusbar_pause = toolbar_state;
    }
}