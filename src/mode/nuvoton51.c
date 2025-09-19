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

#include "../commands/nuvoton/n51_common.h"
#include "../commands/nuvoton/config.h"

const struct _mode_command_struct n51_commands[] = {
    {   .command="config", 
        .func=&n51_config_handler, 
        .description_text=T_JTAG_BLUETAG_DESCRIPTION, 
        .supress_fala_capture=true
    },
 
};
const uint32_t n51_commands_count = count_of(n51_commands);

uint32_t n51_setup(void) {
 
  return (1);
}

uint32_t n51_setup_exc(void) {
  N51ICP_init();
  return (10000000);
}

void n51_cleanup(void) {
  //N51ICP_deinit(false);
  //bio_init();
}

bool n51_preflight_sanity_check(void){
    return ui_help_sanity_check(true, 0x00);
}

void n51_pins(void){
    printf("RST\tCLK\tDATA\tTRG");
}


void n51_settings(void) {
}


void n51_help(void) {
    printf("Nuvoton 8051 mode for utilities such as flash and config read/write/verify\r\n");
    ui_help_mode_commands(n51_commands, n51_commands_count);
}

uint32_t n51_get_speed(void) {
    return 10000000;
}
