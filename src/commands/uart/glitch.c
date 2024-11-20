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
    uint32_t glitch_trg;
    uint32_t glitch_delay;
    uint32_t glitch_length;
} _uart_glitch_config;

static const struct ui_help_options options[] = {
    { 1, "", T_HELP_UART_GLITCH }, // command help
    { 0, "-t", T_HELP_UART_BRIDGE_TOOLBAR },
    { 0, "-h", T_HELP_FLAG }, // help
};

static const char pin_labels[][5] = { "TRG", "RDY" };

static struct _uart_glitch_config uart_glitch_config;
static struct command_attributes periodic_attributes;

static const struct prompt_item uart_glitch_trg_menu[] = { { T_UART_GLITCH_TRG_MENU_1 } };
static const struct prompt_item uart_glitch_dly_menu[] = { { T_UART_GLITCH_DLY_MENU_1 } };

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
                                                      .config = &prompt_int_cfg } };

void glitch_settings(void) {
    ui_prompt_mode_settings_int(GET_T(T_UART_GLITCH_TRG_MENU), uart_glitch_config.glitch_trg, 0x00);
    ui_prompt_mode_settings_int(GET_T(T_UART_GLITCH_DLY_MENU), uart_glitch_config.glitch_delay, 0x00);
}

uint32_t uart_glitch_setup(void) {
    uint32_t temp;
    periodic_attributes.has_value = true;
    periodic_attributes.has_dot = false;
    periodic_attributes.has_colon = false;
    periodic_attributes.has_string = false;
    periodic_attributes.command = 0;       // the actual command called
    periodic_attributes.number_format = 4; // DEC/HEX/BIN
    periodic_attributes.value = 0;         // integer value parsed from command line
    periodic_attributes.dot = 0;           // value after .
    periodic_attributes.colon = 0;         // value after :

    prompt_result result;

    const char config_file[] = "uglitch.bp";
    const mode_config_t config_t[] = {
        // clang-format off
        { "$.trigger", &uart_glitch_config.glitch_trg, MODE_CONFIG_FORMAT_DECIMAL },
        { "$.delay", &uart_glitch_config.glitch_delay, MODE_CONFIG_FORMAT_DECIMAL }
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

    printf("\r\n");
    
    storage_save_mode(config_file, config_t, count_of(config_t));
}

void setup_pins() {
    bio_set_function(M_UART_GLITCH_TRG, GPIO_FUNC_SIO);
    bio_set_function(M_UART_GLITCH_RDY, GPIO_FUNC_SIO);
    bio_output(M_UART_GLITCH_TRG);
    bio_input(M_UART_GLITCH_RDY);
    system_bio_claim(true, M_UART_GLITCH_TRG, BP_PIN_MODE, pin_labels[0]);
    system_bio_claim(true, M_UART_GLITCH_RDY, BP_PIN_MODE, pin_labels[1]);    
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
        return;
    }

    if (!ui_help_check_vout_vref()) {
        return;
    }

    bool toolbar_state = system_config.terminal_ansi_statusbar_pause;
    bool pause_toolbar = !cmdln_args_find_flag('t' | 0x20);
    if (pause_toolbar) {
        system_config.terminal_ansi_statusbar_pause = true;
    }

    printf("%s%s%s\r\n", ui_term_color_notice(), GET_T(T_HELP_UART_GLITCH_EXIT), ui_term_color_reset());
    
    setup_pins();

    while (true) {
        char c;
        if (rx_fifo_try_get(&c)) {
            uart_putc_raw(M_UART_PORT, c);
        }
        if (uart_is_readable(M_UART_PORT)) {
            c = uart_getc(M_UART_PORT);
            tx_fifo_put(&c);
        }
        // exit when button pressed.
        if (button_get(0)) {
            break;
        }
    }
    
    remove_pins();

    if (pause_toolbar) {
        system_config.terminal_ansi_statusbar_pause = toolbar_state;
    }
}