#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pirate.h"
#include "command_struct.h"
#include "ui/ui_term.h"
#include "ui/ui_help.h"
#include "ui/ui_cmdln.h"
#include "ui/ui_prompt.h"
#include "pirate/button.h"

#include "./n51_common.h"
#include "./config.h"

enum n51_cfg_action {
    N51_CFG_READ = 0,
    N51_CFG_WRITE,
    N51_CFG_ERASE,
    N51_CFG_VERIFY
};

const struct cmdln_action_t n51_cfg_actions[] = {
    { N51_CFG_READ, "read" },
    { N51_CFG_WRITE, "write" },
    { N51_CFG_ERASE, "erase"},
    { N51_CFG_VERIFY, "verify" }
};

static const char* const usage[] = {
    "config [read|write|erase|verify] [-f <file>]",
    "Read config:%s read",
    "Read config and save to file:%s read -f cfg.dat",
    "Write config from file:%s write -f cfg.dat",
    "Verify config contents with file data:%s verify -f cfg.dat"
};

static const struct ui_help_options options[] = {
    { 1, "", T_HELP_FLASH },               // flash command help
    //{ 0, "init", T_HELP_FLASH_INIT },      // init
    { 0, "read", T_HELP_FLASH_PROBE },    // probe
    { 0, "write", T_HELP_EEPROM_DUMP }, // dump
    { 0, "erase", T_HELP_FLASH_ERASE },    // erase
    { 0, "verify", T_HELP_FLASH_WRITE }
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
    PRINT_INFO("n51::Starting n51 config handler\r\n");

    if (ui_help_show(res->help_flag, usage, count_of(usage), &options[0], count_of(options))) {
        return;
    }

    if (!ui_help_check_vout_vref()) {
        return;
    }

    printf("\r\n%sNuvoton 8051 ICP programmer - config handler.%s\r\n",
        ui_term_color_info(), ui_term_color_reset());

    uint32_t n51_cfg_action = 0;
    // common function to parse the command line verb or action
    if(cmdln_args_get_action(n51_cfg_actions, count_of(n51_cfg_actions), &n51_cfg_action)){
        ui_help_show(true, usage, count_of(usage), &options[0], count_of(options)); // show help if requested
        return;
    }

    char file[13] = {'\0'};
    command_var_t arg;
    bool file_flag = cmdln_args_find_flag_string('f' | 0x20, &arg, sizeof(file), file);
    if((n51_cfg_action == N51_CFG_VERIFY || n51_cfg_action == N51_CFG_WRITE) && !file_flag) {
        printf("Missing file name (-f)\r\n");
        return;
    }

    printf("Action: %d/%s, filename = %s\r\n", n51_cfg_action, n51_cfg_actions[n51_cfg_action].verb, file);

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
}

