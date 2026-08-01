#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pirate.h"
#include "command_struct.h"
#include "ui/ui_term.h"
#include "ui/ui_help.h"
#include "ui/ui_prompt.h"
#include "pirate/button.h"
#include "lib/bp_args/bp_cmd.h"
#include "fatfs/ff.h"
#include "pirate/file.h"

#include "./n51_common.h"
#include "./config.h"


// ============================================================================
// ACTIONS / SUBCOMMANDS
// ============================================================================
// Actions are the first non-flag token after the command name.
// They are matched by bp_cmd_get_action() and returned as an enum value.
// This replaces manual strcmp() parsing of positional arguments.
enum n51_cfg_action {
    N51_CFG_READ = 0,
    N51_CFG_WRITE,
    N51_CFG_ERASE,
    N51_CFG_VERIFY
};

static const bp_command_action_t n51_cfg_actions[] = {
    { N51_CFG_READ, "read", T_NUVO51_READ_CFG },
    { N51_CFG_WRITE, "write", T_NUVO51_WRITE_CFG },
    { N51_CFG_ERASE, "erase", T_NUVO51_ERASE_CFG },
    { N51_CFG_VERIFY, "verify", T_NUVO51_VERIFY_CFG }
};


static const char* const usage[] = {
    "config [read|write|erase|verify] <file>",
    "Read config:%s read cfg.dat",
    "Read config and save to file:%s read cfg.dat",
    "Write config from file:%s write cfg.dat",
    "Verify config contents with file data:%s verify cfg.dat"
};

static const bp_command_positional_t n51_positionals[] = {
    { "file",  NULL, T_HELP_GCMD_DUMP_FILE, true  },
    { 0 }
};

const bp_command_def_t n51_cmd_def = {
    .name = "config",
    .description = T_HELP_NUVO51_CFG,
    .actions = n51_cfg_actions,
    .action_count = count_of(n51_cfg_actions),
    .opts = NULL,
    .positionals = n51_positionals,
    .positional_count = 1,
    .usage = usage,
    .usage_count = count_of(usage),
};

void N51ICP_print_config(config_flags flags, uint32_t flash_size){
  N51ICP_outputf("----- Chip Configuration ----\n");
  uint8_t *raw_bytes = (uint8_t *)&flags;
  N51ICP_outputf("Raw config bytes:\t" );
  for (int i = 0; i < CFG_FLASH_LEN; i++){
    N51ICP_outputf("%02X ", raw_bytes[i]);
  }
  N51ICP_outputf("\nMCU Boot select:\t%s\n", flags.CBS ? "APROM" : "LDROM");
  int ldrom_size = (7 - (flags.LDS & 0x7)) * 1024;
  if (ldrom_size > LDROM_MAX_SIZE){
    ldrom_size = LDROM_MAX_SIZE;
  }
  N51ICP_outputf("LDROM size:\t\t%d Bytes\n", ldrom_size);
  N51ICP_outputf("APROM size:\t\t%d Bytes\n", flash_size - ldrom_size);
  N51ICP_outputf("Security lock:\t\t%s\n", flags.LOCK ? "UNLOCKED" : "LOCKED"); // this is switched, 1 is off and 0 is on
  N51ICP_outputf("P2.0/Nrst reset:\t%s\n", flags.RPD ? "enabled" : "disabled");
  N51ICP_outputf("On-Chip Debugger:\t%s\n", flags.OCDEN ? "disabled" : "enabled"); // this is switched, 1 is off and 0 is on
  N51ICP_outputf("OCD halt PWM output:\t%s\n", flags.OCDPWM ? "tri-state pins are used as PWM outputs" : "PWM continues");
  N51ICP_outputf("Brown-out detect:\t%s\n", flags.CBODEN ? "enabled" : "disabled");
  N51ICP_outputf("Brown-out voltage:\t");
  switch (flags.CBOV) {
    case 0:
      N51ICP_outputf("4.4V\n");
      break;
    case 1:
      N51ICP_outputf("3.7V\n");
      break;
    case 2:
      N51ICP_outputf("2.7V\n");
      break;
    case 3:
      N51ICP_outputf("2.2V\n");
      break;
  }
  N51ICP_outputf("Brown-out reset:\t%s\n", flags.CBORST ? "enabled" : "disabled");

  N51ICP_outputf("WDT status:\t\t");
  switch (flags.WDTEN) {
    case 15: // 1111
      N51ICP_outputf("WDT is Disabled. WDT can be used as a general purpose timer via software control.\n");
      break;
    case 5:  // 0101
      N51ICP_outputf("WDT is Enabled as a time-out reset timer and it STOPS running during Idle or Power-down mode.\n");
      break;
    default:
      N51ICP_outputf("WDT is Enabled as a time-out reset timer and it KEEPS running during Idle or Power-down mode\n");
      break;
  }
}

/*
void N51ICP_dump_config()
{
	config_flags flags;
	N51ICP_read_flash(CFG_FLASH_ADDR, CFG_FLASH_LEN, (uint8_t *)&flags);
	N51ICP_print_config(flags);
}
*/

typedef struct _device_info{
	uint16_t devid;
	uint8_t cid;
	uint8_t uid[12];
	uint8_t ucid[16];
} device_info;

device_info get_device_info() {
	device_info info;
	info.devid = N51ICP_read_device_id();
	info.cid = N51ICP_read_cid();
	N51ICP_read_uid(info.uid);
	N51ICP_read_ucid(info.ucid);
	return info;
}

void print_device_info(device_info info){
    const flash_info_t* flash_info = get_flash_info(info.devid);

	printf("Device ID:\t0x%04x (%s)\r\n", info.devid, flash_info->name);
	printf("CID:\t\t0x%02x\r\n", info.cid);
	printf("UID:\t\t");
	for (int i = 0; i < 12; i++) {
		printf("%02x ", info.uid[i]);
	}
	printf("\r\nUCID:\t\t");
	for (int i = 0; i < 16; i++) {
		printf("%02x ", info.ucid[i]);
	}
	printf("\r\n");

    printf("** From flash_info_t **\r\n");
    printf("Flash memory size:\t%d (0x%04x)\r\n", flash_info->memory_size, flash_info->memory_size);
    printf("LDROM size:\t%d (0x%04x)\r\n", flash_info->LDROM_size, flash_info->LDROM_size);
    printf("RAM size:\t%d (0x%04x)\r\n", flash_info->RAM_size, flash_info->RAM_size);
}

void n51_config_handler(struct command_result* res) {
    // we can use the ui_help_show function to display the help text we configured above
    if (bp_cmd_help_check(&n51_cmd_def, res->help_flag)) {
        goto display_help;
    }

    if (!ui_help_check_vout_vref()) {
        goto display_help;
    }

    printf("\r\n%sNuvoton 8051 ICP programmer - config handler.%s\r\n",
        ui_term_color_info(), ui_term_color_reset());

    // parse command line
    uint32_t n51_cfg_action = N51_CFG_READ; // default action
    if (!bp_cmd_get_action(&n51_cmd_def, &n51_cfg_action)) {
        bp_cmd_help_show(&n51_cmd_def);
        goto display_help;
    }

    // get filename argument
    char filename[13];
    if (!bp_file_get_name_positional(&n51_cmd_def, 2, filename, sizeof(filename))) {
        goto display_help;
    }

    printf("Action: %d/%s, filename = %s\r\n", n51_cfg_action, n51_cfg_actions[n51_cfg_action].verb, filename);

    N51ICP_enter_icp_mode(false);

    if (get_device_id()) {
        printf("get_device_id() result %04x\r\n", n51_device_id);
    } else {
        printf("get_device_id() returns false!!\r\n");
    }
    if (n51_device_id == 0xffff) {
        printf("trying glitchy reentry\r\n");
        N51ICP_reentry(5000, 1000, 10);
        if (get_device_id()) {
            printf("get_device_id() result %04x\r\n", n51_device_id);
        } else {
            printf("get_device_id() returns false!!\r\n");
        }
    }

    while (!button_get(0));
    
    N51ICP_exit_icp_mode();

    return;

display_help:
    bp_cmd_help_show(&n51_cmd_def);
}

