#pragma once

#include "./pirate/rgb.h" // for `led_effect_t` enumeration

typedef struct _pwm_config {
    float period;
    float dutycycle;

} _pwm_config;

typedef struct _system_config {
    // NOTE: Most settings are uint32_t due to desire to standardize the JSON parsing.
    // TODO: Put _persisted_ settings into a separate struct.
    bool config_loaded_from_file;
    uint32_t disable_unique_usb_serial_number;

    uint8_t hardware_revision;

    uint32_t terminal_language;

    uint32_t terminal_usb_enable; // enable USB CDC terminal

    uint32_t terminal_uart_enable; // enable UART terminal on IO pins
    uint32_t terminal_uart_number; // which UART to use

    uint32_t debug_uart_enable; // initializes a UART for general developer use
    uint32_t debug_uart_number; // which UART to use

    uint32_t lcd_screensaver_active;
    uint32_t lcd_timeout;

    uint32_t led_color;
    uint32_t led_brightness_divisor;
    union {
        uint32_t led_effect_as_uint32; // for json, which needs this to be uint32 (sigh)
        led_effect_t led_effect;
    };

    uint8_t terminal_ansi_rows;
    uint8_t terminal_ansi_columns;
    uint32_t terminal_ansi_color;
    uint32_t terminal_ansi_statusbar;
    bool terminal_ansi_statusbar_update;
    bool terminal_hide_cursor;
    bool terminal_ansi_statusbar_pause;
    uint8_t terminal_update;

    uint8_t storage_available;
    uint8_t storage_mount_error;
    uint8_t storage_fat_type;
    float storage_size;

    uint32_t display_format; // display format (dec, hex, oct, bin)

    uint8_t hiz;                  // is hiz pin mode?
    uint8_t mode;                 // which mode we are in?
    uint8_t display;              // which display mode we are in?
    const char* subprotocol_name; // can be set if there is a sub protocol

    uint8_t num_bits;        // number of used bits
    uint8_t bit_order;       // bitorder (0=msb, 1=lsb)
    uint8_t write_with_read; // write with read
    uint8_t open_drain;      // open drain pin mode (1=true)
    uint8_t pullup_enabled; // pullup enabled? (0=off, 1=on)

    const char* pin_labels[HW_PINS]; // pointer to labels for each pin on the bus pirate header
    enum bp_pin_func pin_func[HW_PINS];
    uint32_t pin_changed;
    bool info_bar_changed;

    uint8_t mode_active;
    uint8_t pwm_active;                    // pwm active, one bit per PWN channel/pin
    _pwm_config freq_config[BIO_MAX_PINS]; // holds PWM or FREQ settings for easier display later
    uint8_t freq_active;                   // freq measure active, one bit per channel/pin
    uint8_t aux_active;                    // user controlled aux pins are outputs, resets when used as inputs

    uint8_t psu; // psu (0=off, 1=on)
                 // uint8_t psu_dat_bits_readable;  // dac bits in human readable format
    // uint16_t psu_dac_bits_mask;          // 8/10/12 bit psu dac possible, this is the bitmask 0xff 0x3ff or 0x7ff
    uint16_t psu_dac_v_set; // psu voltage adjust DAC setting
    uint16_t psu_dac_i_set; // psu current limit DAC setting
    uint32_t psu_voltage;   // psu voltage output setting in decimal * 10000
    bool psu_current_limit_en;
    uint32_t psu_current_limit; // psu current limit in decimal * 10000
    bool psu_current_error;     // psu over current limit fuse tripped
    bool psu_error;             // error, usually with the dac
    bool psu_irq_en;

    uint8_t error; // error occurred

    // TODO: rework this here and in pin info function
    uint32_t csport; // cs is located on this port/gpio
    uint32_t cspin;
    uint32_t misoport; // cs is located on this port/gpio
    uint32_t misopin;
    uint32_t clkport; // cs is located on this port/gpio
    uint32_t clkpin;
    uint32_t mosiport; // cs is located on this port/gpio
    uint32_t mosipin;

    uint32_t big_buffer_owner;

    bool rts;

    bool binmode_usb_rx_queue_enable; // enable the binmode RX queue, disable to handle USB directly with tinyusb
                                      // functions
    bool binmode_usb_tx_queue_enable; // enable the binmode TX queue, disable to handle USB directly with tinyusb
                                      // functions
    uint8_t binmode_select;           // index of currently active binary mode
    bool binmode_lock_terminal;       // disable terminal while in binmode
    uint32_t bpio_debug_enable;           // enable debug output for BPIO

} _system_config;

extern struct _system_config system_config;

void system_init(void);

// TODO: Refactor to type-safe parameters
//       system_pin_update_purpose_and_label() is only called directly to update the BP_VOUT pin label
void system_pin_update_purpose_and_label(bool enable, uint8_t pin, enum bp_pin_func func, const char* label);
void system_bio_update_purpose_and_label(bool enable, uint8_t bio_pin, enum bp_pin_func func, const char* label);
void system_set_active(bool active, uint8_t bio_pin, uint8_t* function_register);
