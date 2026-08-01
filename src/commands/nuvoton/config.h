#ifndef N51_CONFIG_H
#define N51_CONFIG_H
#include "lib/bp_args/bp_cmd.h"

extern const bp_command_def_t n51_cmd_def;
void n51_config_handler(struct command_result* res);
#endif