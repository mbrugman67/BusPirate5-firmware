#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#include "n51_common.h"

flash_info_t* n51_flash_info = NULL;
uint32_t n51_device_id = -1;

bool get_device_id(void) {
    printf("get_device_id()\r\n");
    if (!N51PGM_is_init()) {
        printf("Programmer not init'd!\r\n");
        return (false);
    }

    n51_device_id = N51ICP_read_device_id();

    return (true);
}