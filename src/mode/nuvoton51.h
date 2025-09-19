#ifndef NUVOTON_51_
#define NUVOTON_51_

uint32_t n51_setup(void);
uint32_t n51_setup_exc(void);
void n51_cleanup(void);
bool n51_preflight_sanity_check(void);
void n51_pins(void);
void n51_settings(void);
void n51_help(void);
uint32_t n51_get_speed(void);


extern const struct _mode_command_struct n51_commands[];
extern const uint32_t n51_commands_count;
#endif // NUVOTON_51_