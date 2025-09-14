# Nuvoton ICP for Bus Pirate
This consists of code from the MIT-licensed project [https://github.com/nikitalita/NuMicro-8051-prog](https://github.com/nikitalita/NuMicro-8051-prog) (which in turn is derived from two other MIT-licensed projects, see nikilita's README)

This library is included to provide ICP (in circuit programming) hardware interface to the Nuvoton 8051 series of microcontrollers.  

## Included files
* `nuvo51icp/`  -- directory where the ICP files are stored
  * `common/`
    * `isp_common.h` -- ICP command definition
  * `config.h` -- configuration bitmap definitions
  * `delay.h` -- bit delay counts based on programmer speed
  * `device_common.h`, `device_common.c` -- MCU specific information (flash size, etc.) (modified)
  * `n51_icp.h`, `n51_icp.c` -- main functions to perform ICP comms from BP to Nuvoton target
  * `n51_pgm.h` -- protos for programming fuctions supplied in `buspirate.c` 

## New files
* `buspirate.c` -- I/O and low-level implementation specific to bus pirate, based on the project-supplied `novo51icp/stub.c`
