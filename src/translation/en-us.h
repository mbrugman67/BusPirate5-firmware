// en-us is our base language translation file
#include "translation/base.h"
static char const * const en_us[]={
	[T_ON]="ON",
	[T_OFF]="OFF",
	[T_GND]="GND",
	[T_INPUT]="INPUT",
	[T_OUTPUT]="OUTPUT",
	[T_EXIT]="Exit",
	[T_LOADED]="Loaded",
	[T_SAVED]="Saved",
	[T_HZ]="Hz",
	[T_KHZ]="kHz",
	[T_MHZ]="MHz",
	[T_SPEED]="Speed",
	[T_WARN_VOUT_VREF_LOW]="VOUT/VREF pin is not powered. Use W to enable power, or attach an external supply",
	[T_USE_PREVIOUS_SETTINGS]="Use previous settings?",
	[T_MODE_ERROR_NO_EFFECT]="ERROR: command has no effect here",
	[T_MODE_ERROR_NO_EFFECT_HIZ]="Command has no effect in HiZ mode, press 'm' to choose a mode",
	[T_MODE_NO_HELP_AVAILABLE]="No help available",
	[T_PRESS_ANY_KEY_TO_EXIT]="Press any key to exit",
	[T_PRESS_ANY_KEY]="Press any key",
	[T_PRESS_BUTTON]="Press button",
	[T_PRESS_X_TO_EXIT]="Press 'x' to exit",
	[T_MODE_MODE_SELECTION]="Mode selection",
	[T_MODE_MODE]="Mode",
	[T_MODE_NUMBER_DISPLAY_FORMAT]="Number display format",
	[T_MODE_INVALID_OPTION]="Invalid option",
	[T_MODE_CHOOSE_AVAILABLE_PIN]="Choose available pin:",
	[T_MODE_ALL_PINS_IN_USE]="All pins in use",
	[T_MODE_PULLUP_RESISTORS]="Pull-up resistors",
	[T_MODE_POWER_SUPPLY]="Power supply",
	[T_MODE_DISABLED]="Disabled",
 	[T_MODE_DISPLAY]="Display",
 	[T_MODE_DISPLAY_SELECTION]="Display selection",
	[T_MODE_ENABLED]="Enabled",
	[T_MODE_BITORDER]="Bitorder",
	[T_MODE_BITORDER_MSB]="MSB",
	[T_MODE_BITORDER_LSB]="LSB",
	[T_MODE_DELAY]="Delay",
	[T_MODE_US]="us",
	[T_MODE_MS]="ms",
	[T_MODE_ADC_VOLTAGE]="Volts on",
	[T_MODE_ERROR_PARSING_MACRO]="Error parsing macro",
	[T_MODE_ERROR_NO_MACROS_AVAILABLE]="No macros available",
	[T_MODE_ERROR_MACRO_NOT_DEFINED]="Macro not defined",
	[T_MODE_TICK_CLOCK]="Tick clock",
	[T_MODE_SET_CLK]="Set clock",
	[T_MODE_SET_DAT]="Set data",
	[T_MODE_READ_DAT]="Read data",
	[T_MODE_NO_VOUT_VREF_ERROR]="No voltage detected on VOUT/VREF pin",
	[T_MODE_NO_VOUT_VREF_HINT]="Hint: Use W to enable power, or attach an external supply",
	[T_MODE_NO_PULLUP_ERROR]="Pull-up not detected on IO pin",
	[T_MODE_NO_PULLUP_HINT]="Hint: Use P to enable pull-up resistors, or use external pull-up",
	//FREQ
	[T_MODE_PWM_GENERATE_FREQUENCY]="Generate frequency",
    [T_MODE_FREQ_MEASURE_FREQUENCY]="Frequency measurement",
    [T_MODE_FREQ_FREQUENCY]="Frequency",
	[T_MODE_FREQ_DUTY_CYCLE]="Duty cycle",
    //POWER SUPPLY
    [T_PSU_DAC_ERROR]="PSU DAC error, please run self-test",
    [T_PSU_CURRENT_LIMIT_ERROR]="Current over limit, power supply disabled",
    [T_PSU_SHORT_ERROR]="Potential short circuit, power supply disabled",
    [T_PSU_ALREADY_DISABLED_ERROR]="Power supply already disabled",
    //SYNTAX
	[T_SYNTAX_EXCEEDS_MAX_SLOTS]="Result exceeds available space (%d slots)",

	//SPI
	[T_HWSPI_SPEED_MENU]="SPI speed",
	[T_HWSPI_SPEED_MENU_1]="1 to 62500kHz",
	[T_HWSPI_SPEED_PROMPT]="kHz (%s%dkHz*%s)",
	[T_HWSPI_BITS_MENU]="Data bits",
	[T_HWSPI_BITS_MENU_1]="4 to 8 bits",
	[T_HWSPI_BITS_PROMPT]="Bits (%s%d*%s)",
	[T_HWSPI_CLOCK_POLARITY_MENU]="Clock polarity",
	[T_HWSPI_CLOCK_POLARITY_MENU_1]="Idle LOW",
	[T_HWSPI_CLOCK_POLARITY_MENU_2]="Idle HIGH",
	[T_HWSPI_CLOCK_POLARITY_PROMPT]="Polarity",
	[T_HWSPI_CLOCK_PHASE_MENU]="Clock phase",
	[T_HWSPI_CLOCK_PHASE_MENU_1]="LEADING edge",
	[T_HWSPI_CLOCK_PHASE_MENU_2]="TRAILING edge",
	[T_HWSPI_CLOCK_PHASE_PROMPT]="Phase",
	[T_HWSPI_CS_IDLE_MENU]="Chip select",
	[T_HWSPI_CS_IDLE_MENU_1]="Active HIGH (CS)",
	[T_HWSPI_CS_IDLE_MENU_2]="Active LOW (/CS)",
	[T_HWSPI_CS_IDLE_PROMPT]="CS",
	[T_HWSPI_ACTUAL_SPEED_KHZ]="Actual speed",
	[T_HWSPI_CS_SELECT]="CS Enabled",
	[T_HWSPI_CS_DESELECT]="CS Disabled",
    //UART
	[T_UART_SPEED_MENU]="UART speed",
	[T_UART_SPEED_MENU_1]="1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200 etc",
	[T_UART_SPEED_PROMPT]="Baud (%s%d*%s)",
	[T_UART_PARITY_MENU]="Parity",
	[T_UART_PARITY_MENU_1]="None",
	[T_UART_PARITY_MENU_2]="Even",
	[T_UART_PARITY_MENU_3]="Odd",
	[T_UART_PARITY_PROMPT]="Parity",
	[T_UART_DATA_BITS_MENU]="Data bits",
	[T_UART_DATA_BITS_MENU_1]="5 to 8 bits",
	[T_UART_DATA_BITS_PROMPT]="Bits (%s%d*%s)",
	[T_UART_STOP_BITS_MENU]="Stop bits",
	[T_UART_STOP_BITS_MENU_1]="1",
	[T_UART_STOP_BITS_MENU_2]="2",
	[T_UART_STOP_BITS_PROMPT]="Bits",
	[T_UART_BLOCKING_MENU]="Use blocking functions?",
	[T_UART_BLOCKING_MENU_1]="No",
	[T_UART_BLOCKING_MENU_2]="Yes",
	[T_UART_BLOCKING_PROMPT]="Block",
	[T_UART_FLOW_CONTROL_MENU]="Hardware flow control",
	[T_UART_FLOW_CONTROL_MENU_1]="None",
	[T_UART_FLOW_CONTROL_MENU_2]="RTS/CTS",
	[T_UART_FLOW_CONTROL_PROMPT]="Flow control",
	[T_UART_INVERT_MENU]="Signal inversion",
	[T_UART_INVERT_MENU_1]="Non-inverted (Standard)",
	[T_UART_INVERT_MENU_2]="Inverted",
	[T_UART_INVERT_PROMPT]="Invert signals",
	[T_UART_ACTUAL_SPEED_BAUD]="Actual speed",
	[T_UART_BAUD]="baud",
	[T_UART_OPEN]="UART OPEN",
	[T_UART_OPEN_WITH_READ]="UART OPEN (ASYNC READ)",
	[T_UART_CLOSE]="UART CLOSE",
	[T_UART_NO_DATA_READ]="No data to read",
	[T_UART_NO_DATA_TIMEOUT]="Data read timeout",
    //I2C
	[T_HWI2C_SPEED_MENU]="I2C speed",
	[T_HWI2C_SPEED_MENU_1]="1kHz to 1000kHz",
	[T_HWI2C_SPEED_PROMPT]="kHz (%s%dkHz*%s)",
	[T_HWI2C_DATA_BITS_MENU]="Data bits",
	[T_HWI2C_DATA_BITS_MENU_1]="8",
	[T_HWI2C_DATA_BITS_MENU_2]="10",
	[T_HWI2C_DATA_BITS_PROMPT]="Bits",
	[T_HWI2C_CLOCK_STRETCH_MENU]="Clock stretching",
	//[T_HWI2C_CLOCK_STRETCH_PROMPT]="(OFF)",
	[T_HWI2C_START]="I2C START",
	[T_HWI2C_REPEATED_START]="I2C REPEATED START",
	[T_HWI2C_STOP]="I2C STOP",
	[T_HWI2C_ACK]="ACK",
	[T_HWI2C_NACK]="NACK",
	[T_HWI2C_NO_PULLUP_DETECTED]="no pull-up detected",
	[T_HWI2C_NO_VOUT_DETECTED]="no power detected",
	[T_HWI2C_TIMEOUT]="I2C timeout",
	[T_HWI2C_I2C_ERROR]="I2C bus error",
	//2WIRE
	[T_HW2WIRE_SPEED_MENU]="2WIRE speed",
	[T_HW2WIRE_RST_LOW]="RST LOW",
	[T_HW2WIRE_RST_HIGH]="RST HIGH",
	//3WIRE
	[T_HW3WIRE_SPEED_MENU_1]="1 to 3900kHz",
    //LEDs
	[T_HWLED_DEVICE_MENU]="LED type",
	[T_HWLED_DEVICE_MENU_1]="WS2812/SK6812/'NeoPixel' (single wire interface)",
	[T_HWLED_DEVICE_MENU_2]="APA102/SK9822 (clock and data interface)",
    [T_HWLED_DEVICE_MENU_3]="Onboard LEDs (18 SK6812s)",
	[T_HWLED_DEVICE_PROMPT]="Type",
	[T_HWLED_NUM_LEDS_MENU]="Number of LEDs in the strip",
	[T_HWLED_NUM_LEDS_MENU_1]="1 to 10000",
	[T_HWLED_NUM_LEDS_PROMPT]="LEDs (%s%d*%s)",
	[T_HWLED_RESET]="RESET",
	[T_HWLED_FRAME_START]="START FRAME (0x00000000)",
	[T_HWLED_FRAME_STOP]="STOP FRAME (0xFFFFFFFF)",
	// 1-WIRE
	[T_HW1WIRE_RESET]="1-Wire RESET",
	[T_HW1WIRE_PRESENCE_DETECT]="Presence detected",
	[T_HW1WIRE_NO_DEVICE]="No device detected",
	//INFRARED
	[T_IR_RX_SENSOR_MENU]="RX sensor",
	[T_IR_RX_SENSOR_MENU_LEARNER]="20-60kHz learner",
	[T_IR_RX_SENSOR_MENU_BARRIER]="38kHz barrier",
	[T_IR_RX_SENSOR_MENU_38K_DEMOD]="36-40kHz demodulator",
	[T_IR_RX_SENSOR_MENU_56K_DEMOD]="56kHz demodulator",
	[T_IR_TX_SPEED_MENU]="TX modulation",
	[T_IR_TX_SPEED_MENU_1]="20kHz to 60kHz",
	[T_IR_TX_SPEED_PROMPT]="kHz (%s%dkHz*%s)",
	[T_IR_PROTOCOL_MENU]="Protocol",
	[T_IR_PROTOCOL_MENU_RAW]="RAW (aIR format)",
	[T_IR_PROTOCOL_MENU_RC5]="RC5",
	[T_IR_PROTOCOL_MENU_NEC]="NEC",
	[T_IR_CMD_TV_BGONE]="TV-B-Gone, turn off many brands of TV",
	[T_IR_CMD_IRRX]="Receive, record, retransmit IR signals (aIR format)",
	[T_IR_CMD_IRTX]="Transmit IR signals (aIR format)",
	[T_HELP_IRTX_FILE_FLAG]="Transmit one or more aIR packets from a file",
	[T_HELP_IRRX_FILE_FLAG]="Specify filename for saved signals",
	[T_HELP_IRRX_SENSOR_FLAG]="Specify sensor for received signals (38B/38D/56D)irtx -h",
	//COMMAND LINE
	[T_CMDLN_INVALID_COMMAND]="Invalid command: %s. Type ? for help.",
	[T_CMDLN_NO_HELP]="Help not currently available for this command.",
	[T_CMDLN_LS]="ls <directory> - list files in the current location or <directory> location.",
	[T_CMDLN_CD]="cd <directory> - change to <directory> location.",
	[T_CMDLN_MKDIR]="mkdir <directory> - create <directory>.",
	[T_CMDLN_RM]="rm <file/directory> - remove file or (empty) directory.",
	[T_CMDLN_CAT]="cat <file> - print the contents of <file>.",
	[T_CMDLN_MODE]="m - change protocol mode. m <mode number> to skip the menu.",
	[T_CMDLN_PSU_EN]="W - enable onboard power supply, show configuration menu.",
	[T_CMDLN_RESET]="# - reset and restart the Bus Pirate.",
	[T_CMDLN_BOOTLOAD]="$ - reset and enter bootloader mode for updates.",
	[T_CMDLN_INT_FORMAT]="= <value> - convert <value> to BIN/DEC/HEX/ASCII.",
	[T_CMDLN_INT_INVERSE]="| <value> - inverse the bits in <value>.",
	[T_CMDLN_HELP]="? - show command and syntax help.",
	[T_CMDLN_CONFIG_MENU]="c - open Bus Pirate configuration menu.",
	[T_CMDLN_FREQ_ONE]="f <IOx> - measure frequency on <IOx> once.",
	[T_CMDLN_FREQ_CONT]="F <IOx> - measure frequency on <IOx> continuously.",
	[T_CMDLN_PWM_CONFIG]="G - configure frequency generator (PWM) on an available IOx pin.",
	[T_CMDLN_PWM_DIS]="g <IOx> - disable frequency generator (PWM) on pin <IOx>.",
	[T_CMDLN_HELP_MODE]="h - show mode specific help screen.",
	[T_CMDLN_HELP_DISPLAY]="hd - show display mode specific help screen.",
	[T_CMDLN_INFO]="i - show Bus Pirate info and status screen.",
	[T_CMDLN_BITORDER_MSB]="l - set Most Significant Bit output order.",
	[T_CMDLN_BITORDER_LSB]="L - set Least Significant Bit ouput order.",
	[T_CMDLN_DISPLAY_FORMAT]="o - configure number output display format.",
	[T_CMDLN_PULLUPS_EN]="P - enable onboard pull-up resistors.",
	[T_CMDLN_PULLUPS_DIS]="p - disable onboard pull-up resistors.",
	[T_CMDLN_PSU_DIS]="w - disable onboard power supply.",
	[T_CMDLN_ADC_CONT]="V <IOx> - continuous voltage measurement on pin <IOx>. Omit the pin number to measure voltage on all pins.",
	[T_CMDLN_ADC_ONE]="v <IOx> - single voltage measurement on pin <IOx>. Omit the pin number to measure voltage on all pins once.",
	[T_CMDLN_SELFTEST]="~ - perform a factory self-test. Disconnect any attached devices and change to HiZ mode before starting the test.",
	[T_CMDLN_AUX_IN]="@ <IOx> - make pin <IOx> input, read the pin state.",
	[T_CMDLN_AUX_LOW]="a <IOx> - make pin <IOx> output and low.",
	[T_CMDLN_AUX_HIGH]="A <IOx> - make pin <IOx> output and high.",
	[T_CMDLN_DUMP]="dump <file> <device> - dump contents of flash <device> to <file>. Warning: currently a prototype that only works with 25LC020 in SPI mode.",
	[T_CMDLN_LOAD]="load <file> <device> - load contents of <file> to flash <device>. Warning: currently a prototype that only works with 25LC020 in SPI mode.",
	[T_CMDLN_DISPLAY]="d - change display mode, show selection menu.",
	[T_CMDLN_LOGIC]="logic <frequency in kHz> <samples> <trigger pin> <trigger level> - logic analyzer. <frequency> 1kHz-62500kHz, <trigger pin> 0:7, <trigger level> 0:1.",
	[T_CMDLN_HEX]="hex <file> - print contents of <file> in HEX",
	//HELP
    //[T_HELP_TITLE]="General CommandsBus Syntax",
	//[T_HELP_GENERAL_COMMANDS]="General Commands",
    //[T_HELP_BUS_SYNTAX]="Bus Syntax",
	//[T_HELP_DISK_COMMANDS]="Disk Commands",
	//[T_HELP_BLANK]="",
	[T_HELP_SECTION_IO]="work with pins, input, output measurement",
	[T_HELP_SECTION_CAPTURE]="measure analog and digital signals",
	[T_HELP_SECTION_CONFIGURE]="configure the terminal, LEDs, display and mode",
	[T_HELP_SECTION_SYSTEM]="restart, firmware updates and diagnostic",
	[T_HELP_SECTION_FILES]="list files and navigate the storage",
	[T_HELP_SECTION_PROGRAMS]="useful commands and mini-programs",
	[T_HELP_SECTION_MODE]="enter a mode to use protocols",
	[T_HELP_SECTION_SYNTAX]="send and receive data in modes using bus syntax",
	[T_HELP_SECTION_HELP]="get more help",
	[T_HELP_GREATER_THAN]="Run bus syntax",
	[T_HELP_SYNTAX_ADC]="Measure volts on IO.x",
	[T_HELP_CMD_LS]="List files",
	[T_HELP_CMD_CD]="Change directory",
	[T_HELP_CMD_MKDIR]="Make directory",
	[T_HELP_CMD_RM]="Remove file/directory",
	[T_HELP_CMD_PAUSE]="Pause until any key is pressed",
	[T_HELP_CMD_FORMAT]="Format storage disk (FAT16)",
	[T_HELP_CMD_CAT]="Print file contents as text",
	[T_HELP_CMD_HEX]="Print file contents in HEX",
	[T_HELP_CAPTURE_SCOPE]="Oscilloscope interface",
	[T_HELP_CAPTURE_LA]="Logic analyzer interface",
	[T_HELP_CMD_FLASH]="Erase, write, read and verify SPI flash chips",
	[T_HELP_CMD_LABEL]="Get or set the disk label",
	[T_HELP_CMD_IMAGE]="Write a bitmap image on the LCD",
	[T_HELP_CMD_DUMP]="Repeat read command, save ouput to storage",
	[T_HELP_1_2]="Converts x/reverse x",
	[T_HELP_1_3]="Self test",
	[T_HELP_1_4]="Reset the Bus Pirate",
	[T_HELP_1_5]="Jump to bootloader",
	[T_HELP_1_6]="Delay 1 us/MS (d:4 to repeat)",
	[T_HELP_1_7]="Set IO.x state (low/HI/READ)",
	[T_HELP_COMMAND_AUX]="Set IO x state (low/HI/READ)",
	[T_HELP_COMMAND_DISPLAY]="Change screen display mode",
	[T_HELP_1_9]="Configure terminal, language, LEDs",
	[T_HELP_1_22]="Show volts on IOx (once/CONT)",
	[T_HELP_1_10]="Show volts all IOs (once/CONT)",
	[T_HELP_1_11]="Measure freq on IOx (once/CONT)",
	[T_HELP_1_23]="Monitor freq (off/ON)",
	[T_HELP_1_12]="Generate frequency (off/ON)",
	[T_HELP_HELP_GENERAL]="Global, mode and display help. Try '?', '? mode' and '? display'",
	[T_HELP_HELP_DISPLAY]="Help with a display mode such as the scope",
	[T_HELP_HELP_COMMAND]="Add -h for command help: ls -h",
	[T_HELP_1_14]="Bus Pirate version and status info",
	[T_HELP_1_15]="Bitorder (msb/LSB)",
	[T_HELP_1_16]="Change to a protocol mode such as I2C",
	[T_HELP_1_17]="Choose how numbers are displayed",
	[T_HELP_1_18]="Pull-up resistors (off/ON)",
	//[T_HELP_1_19]="-",
	[T_HELP_1_20]="Show volts/states",
	[T_HELP_1_21]="Power supply (off/ON)",
	[T_HELP_2_1]="Mode macro x/list all",
	[T_HELP_2_3]="Start/Start II (mode dependent)",
	[T_HELP_2_4]="Stop/Stop II (mode dependent)",
	[T_HELP_2_7]="Write string",
	[T_HELP_2_8]="Write value (decimal)",
	[T_HELP_2_9]="Write value (hex)",
	[T_HELP_2_10]="Write value (binary)",
	[T_HELP_2_11]="Read",
	[T_HELP_SYN_CLOCK_HIGH]="Clock high",
	[T_HELP_SYN_CLOCK_LOW]="Clock low",
	[T_HELP_SYN_CLOCK_TICK]="Clock tick",
	[T_HELP_SYN_DATA_HIGH]="Data high",
	[T_HELP_SYN_DATA_LOW]="Data low",
	[T_HELP_SYN_DATA_READ]="Read data pin state",
	[T_HELP_2_18]="Bit read", //this was !? in the original
	[T_HELP_2_19]="Repeat e.g. r:10",
	[T_HELP_2_20]="Bits to read/write e.g. 0x55.2",
	[T_HELP_2_21]="User macro x/list all",
	[T_HELP_2_22]="User macro assign x",
	[T_HELP_HINT]="Chain multiple commands with ; || &&.",
    //FLASH command help
	[T_HELP_FLASH]="read, write and erase flash chips using SFDP info if available",
	[T_HELP_FLASH_ERASE]="Erase flash chip. flash erase [-v(erify)]",
	[T_HELP_FLASH_WRITE]="Write file to flash chip. flash write -f <file> [-e(rase)] [-v(erify)]",
	[T_HELP_FLASH_READ]="Read flash chip to file. flash read -f <file>",
	[T_HELP_FLASH_VERIFY]="Verify flash chip against file. flash verify -f <file>",
	[T_HELP_FLASH_TEST]="Erase and write full chip with dummy data, verify. flash test",
	[T_HELP_FLASH_PROBE]="Probe flash chip for ID and SFDP info. flash probe",
	[T_HELP_FLASH_INIT]="Reset and initialize flash chip. Default if no options given. flash",
	[T_HELP_FLASH_FILE_FLAG]="File flag. File to write, read or verify. flash verify -f <file>",
	[T_HELP_FLASH_ERASE_FLAG]="Erase flag. Add erase before write. flash write -f <file> -e",
	[T_HELP_FLASH_VERIFY_FLAG]="Verify flag. Add verify after write or erase. flash write -f <file> -v",
	//INFO
	[T_INFO_FIRMWARE]="Firmware",
	[T_INFO_BOOTLOADER]="Bootloader",
	[T_INFO_WITH]="with",
	[T_INFO_RAM]="RAM",
	[T_INFO_FLASH]="FLASH",
	[T_INFO_SN]="S/N",
	[T_INFO_WEBSITE]="https://BusPirate.com/",
	[T_INFO_TF_CARD]="Storage",
	[T_INFO_FILE_SYSTEM]="File System",
	[T_NOT_DETECTED]="Not Detected",
	[T_INFO_AVAILABLE_MODES]="Available modes",
	[T_INFO_CURRENT_MODE]="Active mode",
	[T_INFO_POWER_SUPPLY]="Power supply",
	[T_INFO_CURRENT_LIMIT]="Current limit",
	[T_INFO_PULLUP_RESISTORS]="Pull-up resistors",
	[T_INFO_FREQUENCY_GENERATORS]="Frequency generators",
	[T_INFO_DISPLAY_FORMAT]="Display format",
	[T_INFO_DATA_FORMAT]="Data format",
	[T_INFO_BITS]="bits",
	[T_INFO_BITORDER]="bitorder",
	//CONFIG MENU
	[T_CONFIG_FILE]="Configuration file",
	[T_CONFIG_CONFIGURATION_OPTIONS]="Configuration options",
	[T_CONFIG_LANGUAGE]="Language / Jezik / Lingua / 语言",
	[T_CONFIG_ANSI_COLOR_MODE]="ANSI color mode",
	[T_CONFIG_ANSI_COLOR_FULLCOLOR]="ANSI Full-Color (16M colors)",
	[T_CONFIG_ANSI_COLOR_256]="ANSI-256 color",
	[T_CONFIG_ANSI_TOOLBAR_MODE]="ANSI toolbar mode",
	[T_CONFIG_LANGUAGE_ENGLISH]="Language - English (US)", // do not translate ... always shown in own language
	[T_CONFIG_LANGUAGE_CHINESE]="语言 - 中文（简体）",       // do not translate ... always shown in own language
	[T_CONFIG_LANGUAGE_POLISH]="Język - polski (Polska)",  // do not translate ... always shown in own language
	[T_CONFIG_LANGUAGE_BOSNIAN]="Jezik - bosanski (latinica, Bosna i Hercegovina)", // // do not translate ... always shown in own language
	[T_CONFIG_LANGUAGE_ITALIAN]="Lingua - italiano (Italia)",  // // do not translate ... always shown in own language
	[T_CONFIG_DISABLE]="Disable",
	[T_CONFIG_ENABLE]="Enable",
    [T_CONFIG_SCREENSAVER]="LCD screensaver",
    [T_CONFIG_SCREENSAVER_5]="5 minutes",
    [T_CONFIG_SCREENSAVER_10]="10 minutes",
    [T_CONFIG_SCREENSAVER_15]="15 minutes",
    [T_CONFIG_LEDS_EFFECT]="LED effect",
    [T_CONFIG_LEDS_EFFECT_SOLID]="Solid",
    [T_CONFIG_LEDS_EFFECT_ANGLEWIPE]="Angle wipe",
    [T_CONFIG_LEDS_EFFECT_CENTERWIPE]="Center wipe",
    [T_CONFIG_LEDS_EFFECT_CLOCKWISEWIPE]="Clockwise wipe",
    [T_CONFIG_LEDS_EFFECT_TOPDOWNWIPE]="Top side wipe",
    [T_CONFIG_LEDS_EFFECT_SCANNER]="Scanner",
	[T_CONFIG_LEDS_EFFECT_GENTLE_GLOW]="Gentle glow",
	[T_CONFIG_LEDS_EFFECT_CYCLE]="Party mode",
    [T_CONFIG_LEDS_COLOR]="LED color",
    [T_CONFIG_LEDS_COLOR_RAINBOW]="Rainbow",
    [T_CONFIG_LEDS_COLOR_RED]="Red",
    [T_CONFIG_LEDS_COLOR_ORANGE]="Orange",
    [T_CONFIG_LEDS_COLOR_YELLOW]="Yellow",
    [T_CONFIG_LEDS_COLOR_GREEN]="Green",
    [T_CONFIG_LEDS_COLOR_BLUE]="Blue",
    [T_CONFIG_LEDS_COLOR_PURPLE]="Purple",
    [T_CONFIG_LEDS_COLOR_PINK]="Pink",
	[T_CONFIG_LEDS_COLOR_WHITE]="White",
    [T_CONFIG_LEDS_BRIGHTNESS]="LED brightness",
    [T_CONFIG_LEDS_BRIGHTNESS_10]="10%",
    [T_CONFIG_LEDS_BRIGHTNESS_20]="20%",
    [T_CONFIG_LEDS_BRIGHTNESS_30]="30%",
    [T_CONFIG_LEDS_BRIGHTNESS_40]="40%",
    [T_CONFIG_LEDS_BRIGHTNESS_50]="50%",
    [T_CONFIG_LEDS_BRIGHTNESS_100]="100% ***WARNING: will damage USB port without external power supply***",
	[T_CONFIG_BINMODE_SELECT]="Select binary mode",
	//DUMMY example command
	[T_HELP_DUMMY_COMMANDS]="Dummy commands valid in position 1",
	[T_HELP_DUMMY_INIT]="Dummy init command",
	[T_HELP_DUMMY_TEST]="Dummy test command",
	[T_HELP_DUMMY_FLAGS]="Dummy flags",
	[T_HELP_DUMMY_B_FLAG]="-b require Bus Pirate button to be pushed. Takes no parameters",
	[T_HELP_DUMMY_I_FLAG]="-i <integer>. Requires integer number parameter",
	[T_HELP_DUMMY_FILE_FLAG]="-f <file>. Create/write/read <file>. Requires file string parameter",
	//SLE4442 app
	[T_HELP_SLE4442]="SLE4442 smart card interface",
	[T_HELP_SLE4442_INIT]="Initialize card with ISO7816-3 ATR. Default action",
	[T_HELP_SLE4442_DUMP]="Display main, security and protect memory",
	[T_HELP_SLE4442_UNLOCK]="Unlock card with Programmable Security Code (PSC)",
	[T_HELP_SLE4442_WRITE]="Write data to card (requires unlock)",
	[T_HELP_SLE4442_ERASE]="Erase data from range 0x32-0x255 (requires unlock)",
	[T_HELP_SLE4442_PSC]="Change Programmable Security Code (PSC)",
	[T_HELP_SLE4442_ADDRESS_FLAG]="Write address flag",
	[T_HELP_SLE4442_VALUE_FLAG]="Write value flag",
	[T_HELP_SLE4442_CURRENT_PSC_FLAG]="Current Programmable Security Code (PSC) flag",
	[T_HELP_SLE4442_NEW_PSC_FLAG]="New Programmable Security Code (PSC) flag",
	[T_HELP_SLE4442_FILE_FLAG]="Dump file name flag",
	[T_HELP_GCMD_W]="onboard power supply with programmable fuse",
	[T_HELP_GCMD_W_DISABLE]="Disable onboard power supply",
	[T_HELP_GCMD_W_ENABLE]="Enable onboard power supply, show configuration menu",
	[T_HELP_GCMD_W_VOLTS]="Voltage, 0.8-5.0volts",
	[T_HELP_GCMD_W_CURRENT_LIMIT]="Current limit, 0-500mA",
	[T_HELP_GCMD_P]="onboard pull-up resistors",
	[T_HELP_HELP]="help for Bus Pirate commands and modes",
	[T_HELP_SYS_COMMAND]="Commands to access the help system",
	[T_HELP_SYS_DISPLAY]="Show display mode help (such as oscilloscope)",
	[T_HELP_SYS_MODE]="Show mode specific commands and help",
	[T_HELP_SYS_HELP]="How to use the help system",
	[T_HELP_GCMD_SELFTEST]="run a complete system self-test",
	[T_HELP_GCMD_SELFTEST_CMD]="Run self-test",
	[T_HELP_GCMD_SELFTEST_H_FLAG]="Self-test help",
	[T_HELP_AUXIO]="set IO pin state, read input pins",
	[T_HELP_AUXIO_LOW]="Output, low/0. Reserves pin for output",
	[T_HELP_AUXIO_HIGH]="Output, high/1. Reserves pin for output",
	[T_HELP_AUXIO_INPUT]="Input, read state. Releases reserved pin",
	[T_HELP_AUXIO_IO]="IO pin number, 0-7",
	[T_HELP_DISK_HEX]="Print file contents in HEX format",
	[T_HELP_DISK_HEX_FILE]="Name of file in 8.3 format (example1.bin)",
	[T_HELP_DISK_HEX_ADDR]="Show address offset",
	[T_HELP_DISK_HEX_ASCII]="Show also ASCII dump",
	[T_HELP_DISK_HEX_SIZE]="Set line size in bytes",
	[T_HELP_DISK_HEX_OFF]="Set file read start offset in bytes",
    [T_HELP_DISK_HEX_PAGER_OFF]="Disable the pager for dumping",
	[T_HELP_DISK_CAT]="print file contents as text",
	[T_HELP_DISK_CAT_FILE]="Name of file in 8.3 format (example1.txt)",
	[T_HELP_DISK_MKDIR]="create directory on internal storage",
	[T_HELP_DISK_MKDIR_DIR]="Directory name, 8 characters max",
	[T_HELP_DISK_CD]="change to a directory on local storage",
	[T_HELP_DISK_CD_DIR]="Directory name, 8 characters max",
	[T_HELP_DISK_RM]="delete file or directory on local storage",
	[T_HELP_DISK_RM_FILE]="Name of file to delete, 8.3 format",
	[T_HELP_DISK_RM_DIR]="Name of directory to delete, 8 characters max",
	[T_HELP_DISK_LS]="list files and directories on local storage",
	[T_HELP_DISK_LS_DIR]="List contents of this directory, optional",
	[T_HELP_DISK_FORMAT]="erase and format internal storage in FAT16 format",
	[T_HELP_DISK_FORMAT_CMD]="All data will be lost, answer 'y' twice to continue",
	[T_HELP_DISK_LABEL]="get or set the disk label",
	[T_HELP_DISK_LABEL_GET]="returns the current label of the disk",
	[T_HELP_DISK_LABEL_SET]="sets the current label of the disk",
	[T_HELP_VADC]="measure voltage on IO pins",
	[T_HELP_VADC_SINGLE]="Single measurement",
	[T_HELP_VADC_CONTINUOUS]="Continuous measurement",
	[T_HELP_VADC_IO]="IO pin number, 0-7",
	[T_HELP_I2C_SCAN]="scan I2C addresses, with optional part number",
	[T_HELP_I2C_SCAN_VERBOSE]="Verbose mode, print potential part numbers",
	[T_HELP_FLAG]="Get additional help",
	[T_HELP_I2C_SI7021]="Read temperature and humidity from SI7021/HTU21/SHT21 sensor",
	[T_HELP_I2C_MS5611]="Read temperature and pressure from MS5611 sensor",
	[T_HELP_I2C_TSL2561]="Read light intensity (LUX) from TSL2561 sensor",
	[T_HELP_1WIRE_SCAN]="scan for 1-Wire devices",
	[T_HELP_1WIRE_DS18B20]="Query DS18B20 temperature sensor",
	[T_HELP_UART_BRIDGE]="open UART with raw data IO, usb to serial bridge mode",
	[T_HELP_UART_BRIDGE_EXIT]="UART bridge. Press Bus Pirate button to exit.",
	[T_HELP_UART_BRIDGE_TOOLBAR]="ENABLE toolbar while bridge is active (default: disabled)",
	[T_HELP_UART_BRIDGE_SUPPRESS_LOCAL_ECHO]="Suppress local echo, don't echo back sent data",
	[T_HELP_UART_NMEA]="parse NMEA GPS data",
    [T_HELP_SECTION_SCRIPT]="run scripts, macros and assign button functions",
    [T_HELP_CMD_SCRIPT]="Run script files, automation",
    [T_HELP_CMD_BUTTON]="Assign button functions",
    [T_HELP_CMD_MACRO]="Run macros, load a macro file",
    [T_HELP_CMD_TUTORIAL]="Run tutorial files",
	[T_HELP_CMD_PAUSE]="Pause for user input, optional exit",
	[T_HELP_CMD_PAUSE_KEY]="Press any key to continue (default)",
	[T_HELP_CMD_PAUSE_BUTTON]="Press the Bus Pirate button to continue",
	[T_HELP_CMD_PAUSE_EXIT]="'x' key to exit (e.g. script mode)",
	[T_HELP_BUTTON]="Assign script file to button press",
	[T_HELP_BUTTON_SHORT]="Assign script file to short button press",
	[T_HELP_BUTTON_LONG]="Assign script file to long button press",
	[T_HELP_BUTTON_FILE]="Script file to assign to button press",
	[T_HELP_BUTTON_HIDE]="Hide comments",
	[T_HELP_BUTTON_EXIT]="Exit script on error",
	[T_HELP_LOGIC]="logic analyzer control",
	[T_HELP_LOGIC_START]="start logic analyzer",
	[T_HELP_LOGIC_STOP]="stop logic analyzer",
	[T_HELP_LOGIC_HIDE]="hide logic graph",
	[T_HELP_LOGIC_SHOW]="show logic graph",
	[T_HELP_LOGIC_NAV]="navigate logic graph with arrow keys, x to exit",
	[T_HELP_LOGIC_INFO]="show configuration info",
	[T_HELP_LOGIC_FREQUENCY]="set sample frequency in Hz",
	[T_HELP_LOGIC_OVERSAMPLE]="set oversample rate, multiplies the sample frequency",
	[T_HELP_LOGIC_DEBUG]="set debug level: 0-2",
	[T_HELP_LOGIC_SAMPLES]="set number of samples",
	[T_HELP_LOGIC_TRIGGER_PIN]="set trigger pin, 0-7",
	[T_HELP_LOGIC_TRIGGER_LEVEL]="set trigger level, 0-1",
	[T_HELP_LOGIC_LOW_CHAR]="set character used for low in graph (ex:_)",
	[T_HELP_LOGIC_HIGH_CHAR]="set character used for high in graph (ex:*)",
	[T_HELP_CMD_CLS]="Clear and reset the terminal",
	[T_HELP_SECTION_TOOLS]="tools and utilities",
	[T_HELP_CMD_LOGIC]="Logic analyzer",
	[T_HELP_CMD_SMPS]="Switch mode power supply (plank required)",
	[T_INFRARED_CMD_TEST]="Test IR RX/TX Toy plank",
	[T_UART_CMD_TEST]="Test Dual RS232 plank",
	[T_SPI_CMD_SNIFF]="SPI sniffer",

};

// Since en-us is the base language, the following static assert at least verifies the table size
// However, it does not check that all values are set to non-null.
static_assert(count_of(en_us)==T_LAST_ITEM_ALWAYS_AT_THE_END, "Missing english translations!");
