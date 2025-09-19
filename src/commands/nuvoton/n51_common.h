#ifndef N51_COMMON
#define N51_COMMON

#include "../../lib/nuvoton/config.h"
#include "../../lib/nuvoton/n51_icp.h"
#include "../../lib/nuvoton/n51_pgm.h"
#include "../../lib/nuvoton/device_common.h"

#define APROM_FLASH_ADDR	0x0
#define CFG_FLASH_ADDR		0x30000
#define CFG_FLASH_LEN		5
#define LDROM_MAX_SIZE      (4 * 1024)

extern flash_info_t* n51_flash_info;
extern uint32_t n51_device_id;

bool get_device_id(void);

#endif