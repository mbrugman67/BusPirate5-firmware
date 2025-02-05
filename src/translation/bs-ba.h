#pragma once

// NOTE: GENERATED FILE -- DO NOT EDIT DIRECTLY
//       This file is auto-generated by `src/translations/json2h.py`.
//       Entirely new strings should be added to `src/translations/en-us.h`
//       New or modified translations of a string should be added to the
//       language-specific JSON file, which can be found in directory
//       `src/translations/templates/`.

#include "translation/base.h"
static char const * const bs_ba[T_LAST_ITEM_ALWAYS_AT_THE_END]={
    [ T_ON                             ] = NULL,
    [ T_OFF                            ] = NULL,
    [ T_GND                            ] = NULL,
    [ T_INPUT                          ] = NULL,
    [ T_OUTPUT                         ] = NULL,
    [ T_EXIT                           ] = "Izlaz",
    [ T_LOADED                         ] = "Učitano",
    [ T_SAVED                          ] = "Spremljeno",
    [ T_HZ                             ] = NULL,
    [ T_KHZ                            ] = NULL,
    [ T_MHZ                            ] = NULL,
    [ T_SPEED                          ] = NULL,
    [ T_WARN_VOUT_VREF_LOW             ] = NULL,
    [ T_USE_PREVIOUS_SETTINGS          ] = "Koristi prethodne postavke?",
    [ T_MODE_ERROR_NO_EFFECT           ] = "GREŠKA: naredba nema efekta ovdje",
    [ T_MODE_ERROR_NO_EFFECT_HIZ       ] = "Naredba nema efekta u HiZ modu, pritisnite 'm' za izabir moda",
    [ T_MODE_NO_HELP_AVAILABLE         ] = "Pomoć nije dostupna",
    [ T_PRESS_ANY_KEY_TO_EXIT          ] = "Pritisnite bilo koju tipku za izlaz",
    [ T_PRESS_ANY_KEY                  ] = NULL,
    [ T_PRESS_BUTTON                   ] = NULL,
    [ T_PRESS_X_TO_EXIT                ] = NULL,
    [ T_MODE_MODE_SELECTION            ] = "Izbor moda",
    [ T_MODE_MODE                      ] = "Mod",
    [ T_MODE_NUMBER_DISPLAY_FORMAT     ] = "Format prikaza brojeva",
    [ T_MODE_INVALID_OPTION            ] = "Nevažeći izbor",
    [ T_MODE_CHOOSE_AVAILABLE_PIN      ] = "Izaberite slobodan pin:",
    [ T_MODE_ALL_PINS_IN_USE           ] = "Svi pinovi u upotrebi",
    [ T_MODE_PULLUP_RESISTORS          ] = "Pull-up otpornik",
    [ T_MODE_POWER_SUPPLY              ] = "Napajanje",
    [ T_MODE_DISABLED                  ] = "Onemogućeno",
    [ T_MODE_DISPLAY                   ] = NULL,
    [ T_MODE_DISPLAY_SELECTION         ] = NULL,
    [ T_MODE_ENABLED                   ] = "Omogućeno",
    [ T_MODE_BITORDER                  ] = NULL,
    [ T_MODE_BITORDER_MSB              ] = NULL,
    [ T_MODE_BITORDER_LSB              ] = NULL,
    [ T_MODE_DELAY                     ] = NULL,
    [ T_MODE_US                        ] = NULL,
    [ T_MODE_MS                        ] = NULL,
    [ T_MODE_ADC_VOLTAGE               ] = "Volta na",
    [ T_MODE_ERROR_PARSING_MACRO       ] = "Greška u parsiranju makroa",
    [ T_MODE_ERROR_NO_MACROS_AVAILABLE ] = "Nema dostupnih makroa",
    [ T_MODE_ERROR_MACRO_NOT_DEFINED   ] = "Makro nije definisan",
    [ T_MODE_TICK_CLOCK                ] = NULL,
    [ T_MODE_SET_CLK                   ] = NULL,
    [ T_MODE_SET_DAT                   ] = NULL,
    [ T_MODE_READ_DAT                  ] = NULL,
    [ T_MODE_NO_VOUT_VREF_ERROR        ] = NULL,
    [ T_MODE_NO_VOUT_VREF_HINT         ] = NULL,
    [ T_MODE_NO_PULLUP_ERROR           ] = NULL,
    [ T_MODE_NO_PULLUP_HINT            ] = NULL,
    [ T_MODE_PWM_GENERATE_FREQUENCY    ] = "Generiši frekvenciju",
    [ T_MODE_FREQ_MEASURE_FREQUENCY    ] = "Mjerenje frekvencije",
    [ T_MODE_FREQ_FREQUENCY            ] = "Frekvencija",
    [ T_MODE_FREQ_DUTY_CYCLE           ] = "Radni ciklus",
    [ T_PSU_DAC_ERROR                  ] = "PSU DAC greška, molimo pokrenite self-test",
    [ T_PSU_CURRENT_LIMIT_ERROR        ] = "Struja iznad granice, napajanje onemogućeno",
    [ T_PSU_SHORT_ERROR                ] = "Moguć kratki spoj, napajanje onemogućeno",
    [ T_PSU_ALREADY_DISABLED_ERROR     ] = "Napajanje već onemogućeno",
    [ T_SYNTAX_EXCEEDS_MAX_SLOTS       ] = "Rezultati prekoračuju dostupni prostor (%d slotova)",
    [ T_HWSPI_SPEED_MENU               ] = "SPI brzina",
    [ T_HWSPI_SPEED_MENU_1             ] = "1 do 62500kHz",
    [ T_HWSPI_SPEED_PROMPT             ] = NULL,
    [ T_HWSPI_BITS_MENU                ] = "Data bita",
    [ T_HWSPI_BITS_MENU_1              ] = "4 do 8 bita",
    [ T_HWSPI_BITS_PROMPT              ] = "Bita (%s%d*%s)",
    [ T_HWSPI_CLOCK_POLARITY_MENU      ] = "Clock polaritet",
    [ T_HWSPI_CLOCK_POLARITY_MENU_1    ] = "Prazan LOW",
    [ T_HWSPI_CLOCK_POLARITY_MENU_2    ] = "Prazan HIGH",
    [ T_HWSPI_CLOCK_POLARITY_PROMPT    ] = "Polaritet",
    [ T_HWSPI_CLOCK_PHASE_MENU         ] = "Clock faza",
    [ T_HWSPI_CLOCK_PHASE_MENU_1       ] = NULL,
    [ T_HWSPI_CLOCK_PHASE_MENU_2       ] = NULL,
    [ T_HWSPI_CLOCK_PHASE_PROMPT       ] = "Faza",
    [ T_HWSPI_CS_IDLE_MENU             ] = "Čip select",
    [ T_HWSPI_CS_IDLE_MENU_1           ] = "Aktivan HIGH (CS)",
    [ T_HWSPI_CS_IDLE_MENU_2           ] = "Aktivan LOW (/CS)",
    [ T_HWSPI_CS_IDLE_PROMPT           ] = NULL,
    [ T_HWSPI_ACTUAL_SPEED_KHZ         ] = "Stvarna brzina",
    [ T_HWSPI_CS_SELECT                ] = "CS Omogućen",
    [ T_HWSPI_CS_DESELECT              ] = "CS Onemogućen",
    [ T_UART_SPEED_MENU                ] = "UART brzina",
    [ T_UART_SPEED_MENU_1              ] = NULL,
    [ T_UART_SPEED_PROMPT              ] = NULL,
    [ T_UART_PARITY_MENU               ] = "Paritet",
    [ T_UART_PARITY_MENU_1             ] = NULL,
    [ T_UART_PARITY_MENU_2             ] = "Paran",
    [ T_UART_PARITY_MENU_3             ] = "Neparan",
    [ T_UART_PARITY_PROMPT             ] = "Paritet",
    [ T_UART_DATA_BITS_MENU            ] = "Data bita",
    [ T_UART_DATA_BITS_MENU_1          ] = "5 do 8 bita",
    [ T_UART_DATA_BITS_PROMPT          ] = "Bita (%s%d*%s)",
    [ T_UART_STOP_BITS_MENU            ] = "Stop bita",
    [ T_UART_STOP_BITS_MENU_1          ] = NULL,
    [ T_UART_STOP_BITS_MENU_2          ] = NULL,
    [ T_UART_STOP_BITS_PROMPT          ] = "Bita",
    [ T_UART_BLOCKING_MENU             ] = "Koristite blokirajuće funkcije?",
    [ T_UART_BLOCKING_MENU_1           ] = "Ne",
    [ T_UART_BLOCKING_MENU_2           ] = "Da",
    [ T_UART_BLOCKING_PROMPT           ] = "Blokiraj",
    [ T_UART_FLOW_CONTROL_MENU         ] = NULL,
    [ T_UART_FLOW_CONTROL_MENU_1       ] = NULL,
    [ T_UART_FLOW_CONTROL_MENU_2       ] = NULL,
    [ T_UART_FLOW_CONTROL_PROMPT       ] = NULL,
    [ T_UART_INVERT_MENU               ] = NULL,
    [ T_UART_INVERT_MENU_1             ] = NULL,
    [ T_UART_INVERT_MENU_2             ] = NULL,
    [ T_UART_INVERT_PROMPT             ] = NULL,
    [ T_UART_GLITCH_TRG_MENU           ] = NULL,
    [ T_UART_GLITCH_TRG_MENU_1         ] = NULL,
    [ T_UART_GLITCH_TRG_PROMPT         ] = NULL,
    [ T_UART_GLITCH_DLY_MENU           ] = NULL,
    [ T_UART_GLITCH_DLY_MENU_1         ] = NULL,
    [ T_UART_GLITCH_DLY_PROMPT         ] = NULL,
    [ T_UART_GLITCH_VRY_MENU           ] = NULL,
    [ T_UART_GLITCH_VRY_MENU_1         ] = NULL,
    [ T_UART_GLITCH_VRY_PROMPT         ] = NULL,
    [ T_UART_GLITCH_LNG_MENU           ] = NULL,
    [ T_UART_GLITCH_LNG_MENU_1         ] = NULL,
    [ T_UART_GLITCH_LNG_PROMPT         ] = NULL,
    [ T_UART_GLITCH_CYC_MENU           ] = NULL,
    [ T_UART_GLITCH_CYC_MENU_1         ] = NULL,
    [ T_UART_GLITCH_CYC_PROMPT         ] = NULL,
    [ T_UART_GLITCH_FAIL_MENU          ] = NULL,
    [ T_UART_GLITCH_FAIL_MENU_1        ] = NULL,
    [ T_UART_GLITCH_FAIL_PROMPT        ] = NULL,
    [ T_UART_GLITCH_CNT_MENU           ] = NULL,
    [ T_UART_GLITCH_CNT_MENU_1         ] = NULL,
    [ T_UART_GLITCH_CNT_PROMPT         ] = NULL,
    [ T_UART_GLITCH_NORDY_MENU         ] = NULL,
    [ T_UART_GLITCH_NORDY_MENU_1       ] = NULL,
    [ T_UART_GLITCH_NORDY_PROMPT       ] = NULL,
    [ T_UART_GLITCH_NORDY_DISABLED     ] = NULL,
    [ T_UART_GLITCH_NORDY_ENABLED      ] = NULL,
    [ T_UART_GLITCH_GLITCHED           ] = NULL,
    [ T_UART_GLITCH_CANCELLED          ] = NULL,
    [ T_UART_GLITCH_DONE               ] = NULL,
    [ T_UART_TOOL_TIMEOUT              ] = NULL,
    [ T_UART_GLITCH_UNKNOWN            ] = NULL,
    [ T_UART_GLITCH_SETUP_ERR          ] = NULL,
    [ T_UART_SIDECHAN_TRG_MENU         ] = NULL,
    [ T_UART_SIDECHAN_TRG_MENU_1       ] = NULL,
    [ T_UART_SIDECHAN_TRG_MENU_PROMPT  ] = NULL,
    [ T_UART_SIDECHAN_LEN_MENU         ] = NULL,
    [ T_UART_SIDECHAN_LEN_MENU_1       ] = NULL,
    [ T_UART_SIDECHAN_LEN_MENU_PROMPT  ] = NULL,
    [ T_UART_SIDECHAN_SETUP_ERR        ] = NULL,
    [ T_UART_ACTUAL_SPEED_BAUD         ] = "Stvarna brzina",
    [ T_UART_BAUD                      ] = NULL,
    [ T_UART_OPEN                      ] = NULL,
    [ T_UART_OPEN_WITH_READ            ] = NULL,
    [ T_UART_CLOSE                     ] = NULL,
    [ T_UART_NO_DATA_READ              ] = "Nema podataka za čiranje",
    [ T_UART_NO_DATA_TIMEOUT           ] = "Timeout čitanja podataka",
    [ T_HWI2C_SPEED_MENU               ] = "I2C brzina",
    [ T_HWI2C_SPEED_MENU_1             ] = "1kHz do 1000kHz",
    [ T_HWI2C_SPEED_PROMPT             ] = NULL,
    [ T_HWI2C_DATA_BITS_MENU           ] = "Data bita",
    [ T_HWI2C_DATA_BITS_MENU_1         ] = NULL,
    [ T_HWI2C_DATA_BITS_MENU_2         ] = NULL,
    [ T_HWI2C_DATA_BITS_PROMPT         ] = "Bita",
    [ T_HWI2C_CLOCK_STRETCH_MENU       ] = NULL,
    [ T_HWI2C_CLOCK_STRETCH_PROMPT     ] = NULL,
    [ T_HWI2C_START                    ] = NULL,
    [ T_HWI2C_REPEATED_START           ] = NULL,
    [ T_HWI2C_STOP                     ] = NULL,
    [ T_HWI2C_ACK                      ] = NULL,
    [ T_HWI2C_NACK                     ] = NULL,
    [ T_HWI2C_NO_PULLUP_DETECTED       ] = "pull-up nije detektovan. Koristite P da omogućite pull-up otpornike na ploči",
    [ T_HWI2C_NO_VOUT_DETECTED         ] = NULL,
    [ T_HWI2C_TIMEOUT                  ] = NULL,
    [ T_HWI2C_I2C_ERROR                ] = "I2C bus greška",
    [ T_HW2WIRE_SPEED_MENU             ] = NULL,
    [ T_HW2WIRE_RST_LOW                ] = NULL,
    [ T_HW2WIRE_RST_HIGH               ] = NULL,
    [ T_HW3WIRE_SPEED_MENU_1           ] = NULL,
    [ T_HWLED_DEVICE_MENU              ] = "LED tip",
    [ T_HWLED_DEVICE_MENU_1            ] = NULL,
    [ T_HWLED_DEVICE_MENU_2            ] = "APA102/SK9822 (clock i data interface)",
    [ T_HWLED_DEVICE_MENU_3            ] = "LEDovi na ploči (18 SK6812s)",
    [ T_HWLED_DEVICE_PROMPT            ] = NULL,
    [ T_HWLED_NUM_LEDS_MENU            ] = "Broj LEDova u traci",
    [ T_HWLED_NUM_LEDS_MENU_1          ] = "1 do 10000",
    [ T_HWLED_NUM_LEDS_PROMPT          ] = "LEDovi (%s%d*%s)",
    [ T_HWLED_RESET                    ] = NULL,
    [ T_HWLED_FRAME_START              ] = NULL,
    [ T_HWLED_FRAME_STOP               ] = NULL,
    [ T_HW1WIRE_RESET                  ] = NULL,
    [ T_HW1WIRE_PRESENCE_DETECT        ] = "Uređaj detektovan",
    [ T_HW1WIRE_NO_DEVICE              ] = "Nema detektovanog uređaja",
    [ T_IR_RX_SENSOR_MENU              ] = NULL,
    [ T_IR_RX_SENSOR_MENU_LEARNER      ] = NULL,
    [ T_IR_RX_SENSOR_MENU_BARRIER      ] = NULL,
    [ T_IR_RX_SENSOR_MENU_38K_DEMOD    ] = NULL,
    [ T_IR_RX_SENSOR_MENU_56K_DEMOD    ] = NULL,
    [ T_IR_TX_SPEED_MENU               ] = NULL,
    [ T_IR_TX_SPEED_MENU_1             ] = NULL,
    [ T_IR_TX_SPEED_PROMPT             ] = NULL,
    [ T_IR_PROTOCOL_MENU               ] = NULL,
    [ T_IR_PROTOCOL_MENU_RAW           ] = NULL,
    [ T_IR_PROTOCOL_MENU_RC5           ] = NULL,
    [ T_IR_PROTOCOL_MENU_NEC           ] = NULL,
    [ T_IR_CMD_TV_BGONE                ] = NULL,
    [ T_IR_CMD_IRRX                    ] = NULL,
    [ T_IR_CMD_IRTX                    ] = NULL,
    [ T_HELP_IRTX_FILE_FLAG            ] = NULL,
    [ T_HELP_IRRX_FILE_FLAG            ] = NULL,
    [ T_HELP_IRRX_SENSOR_FLAG          ] = NULL,
    [ T_JTAG_BLUETAG_OPTIONS           ] = NULL,
    [ T_JTAG_BLUETAG_JTAG              ] = NULL,
    [ T_JTAG_BLUETAG_SWD               ] = NULL,
    [ T_JTAG_BLUETAG_FLAGS             ] = NULL,
    [ T_JTAG_BLUETAG_CHANNELS          ] = NULL,
    [ T_JTAG_BLUETAG_VERSION           ] = NULL,
    [ T_JTAG_BLUETAG_DISABLE           ] = NULL,
    [ T_CMDLN_INVALID_COMMAND          ] = "Nevažeća naredba: %s. Unesite ? za pomoć.",
    [ T_CMDLN_NO_HELP                  ] = "Pomoć trenutno nije dostupna za ovu naredbu.",
    [ T_CMDLN_LS                       ] = "ls {direktorij} - listing datoteka u trenutnoj lokaciji ili {direktorij} lokaciji.",
    [ T_CMDLN_CD                       ] = "cd {direktorij} - premjestite se u {direktorij} lokaciju.",
    [ T_CMDLN_MKDIR                    ] = "mkdir {direktorij} - kreirajte {direktorij}.",
    [ T_CMDLN_RM                       ] = "rm {datoteka/direktorij} - uklonite datoteku ili (prazan) direktorij.",
    [ T_CMDLN_CAT                      ] = "cat {datoteka} - prikažite sadržaj {datoteka}.",
    [ T_CMDLN_MODE                     ] = "m - promjenite protokol mod, prikažite izbornik.",
    [ T_CMDLN_PSU_EN                   ] = "W - omogućite napojnu jedinicu na ploči, prikažite konfiguracijski izbornik.",
    [ T_CMDLN_RESET                    ] = "# - poništite postavke i ponovno pokrenite Bus Pirate.",
    [ T_CMDLN_BOOTLOAD                 ] = "$ - poništite postavke i otvorite bootloader mod za ažuriranje.",
    [ T_CMDLN_INT_FORMAT               ] = "= {vrijednost} - konvertujte {vrijednost} u BIN/DEC/HEX/ASCII.",
    [ T_CMDLN_INT_INVERSE              ] = "| {vrijednost} - invertirajte bite u {vrijednost}.",
    [ T_CMDLN_HELP                     ] = "? - prikažite pomoć za naredbe i sintaksu.",
    [ T_CMDLN_CONFIG_MENU              ] = "c - otvorite Bus Pirate konfiguracijski izbornik.",
    [ T_CMDLN_FREQ_ONE                 ] = "f {IOx} - izmjerite frekvenciju na {IOx} jedanput.",
    [ T_CMDLN_FREQ_CONT                ] = "F {IOx} - izmjerite frekvenciju na {IOx} kontinualno.",
    [ T_CMDLN_PWM_CONFIG               ] = "G - konfigurišite frekvencijski generator (PWM) na slobodnom IOx pinu.",
    [ T_CMDLN_PWM_DIS                  ] = "g {IOx} - onemogućite frekvencijski generator (PWM) na pinu {IOx}.",
    [ T_CMDLN_HELP_MODE                ] = "h - prikažite ekran pomoći za izabrani mod.",
    [ T_CMDLN_HELP_DISPLAY             ] = NULL,
    [ T_CMDLN_INFO                     ] = "i - prikažite Bus Pirate informacijski i status ekran.",
    [ T_CMDLN_BITORDER_MSB             ] = "l - zadajte Most Significant Bit red ispisa.",
    [ T_CMDLN_BITORDER_LSB             ] = "L - zadajte Least Significant Bit red ispisa.",
    [ T_CMDLN_DISPLAY_FORMAT           ] = "o - podesite format ispisa brojeva.",
    [ T_CMDLN_PULLUPS_EN               ] = "P - omogućite pull-up otpornike na ploči.",
    [ T_CMDLN_PULLUPS_DIS              ] = "p - onemogućite pull-up otpornike na ploči.",
    [ T_CMDLN_PSU_DIS                  ] = "w - onemogućite napojnu jedinicu na ploči.",
    [ T_CMDLN_ADC_CONT                 ] = "V {IOx} - kontinualno mjerenje napona na pinu {IOx}. Unesite bez broja pina za mjerenje napona na svim pinovima.",
    [ T_CMDLN_ADC_ONE                  ] = "v {IOx} - jednokratno mjerenje napona na pinu {IOx}. Unesite bez broja pina za jednokratno mjerenje napona na svim pinovima.",
    [ T_CMDLN_SELFTEST                 ] = "~ - izvršite fabrički self-test. Odspojite sve priključene uređaje i pređite u HiZ mod prije pokretanja testa.",
    [ T_CMDLN_AUX_IN                   ] = "@ {IOx} - postavite pin {IOx} kao ulaz, pročitajte stanje.",
    [ T_CMDLN_AUX_LOW                  ] = "a {IOx} - postavite pin {IOx} kao izlaz i LOW.",
    [ T_CMDLN_AUX_HIGH                 ] = "A {IOx} - postavite pin {IOx} kao izlaz i HIGH.",
    [ T_CMDLN_DUMP                     ] = "dump {datoteka} {uređaj} - zapišite sadržaj flash {uređaj} u {datoteka}. Upozorenje: trenutno radi kao prototip samo sa 25LC020 u SPI modu.",
    [ T_CMDLN_LOAD                     ] = "load {datoteka} {uređaj} - učitajte saržaj {datoteka} na flash {uređaj}. Upozorenje: trenutno radi kao prototip sa 25LC020 u SPI modu.",
    [ T_CMDLN_DISPLAY                  ] = NULL,
    [ T_CMDLN_LOGIC                    ] = NULL,
    [ T_CMDLN_HEX                      ] = NULL,
    [ T_HELP_SECTION_IO                ] = NULL,
    [ T_HELP_SECTION_CAPTURE           ] = NULL,
    [ T_HELP_SECTION_CONFIGURE         ] = NULL,
    [ T_HELP_SECTION_SYSTEM            ] = NULL,
    [ T_HELP_SECTION_FILES             ] = NULL,
    [ T_HELP_SECTION_PROGRAMS          ] = NULL,
    [ T_HELP_SECTION_MODE              ] = NULL,
    [ T_HELP_SECTION_SYNTAX            ] = NULL,
    [ T_HELP_SECTION_HELP              ] = NULL,
    [ T_HELP_GREATER_THAN              ] = "Pokrenite Bus sintaksa (vidjeti: Bus sintaksa)",
    [ T_HELP_SYNTAX_ADC                ] = "Mjeri napon na IO.x\t",
    [ T_HELP_CMD_LS                    ] = "Izlistaj datoteke",
    [ T_HELP_CMD_CD                    ] = "Promjeni direktorij",
    [ T_HELP_CMD_MKDIR                 ] = "Napravi direktorij",
    [ T_HELP_CMD_RM                    ] = "Ukloni datoteku/Direktorij",
    [ T_HELP_CMD_PAUSE                 ] = NULL,
    [ T_HELP_CMD_FORMAT                ] = NULL,
    [ T_HELP_CMD_CAT                   ] = "Ispiši sadržaj datoteke",
    [ T_HELP_CMD_HEX                   ] = NULL,
    [ T_HELP_CAPTURE_SCOPE             ] = NULL,
    [ T_HELP_CAPTURE_LA                ] = NULL,
    [ T_HELP_CMD_FLASH                 ] = NULL,
    [ T_HELP_CMD_LABEL                 ] = NULL,
    [ T_HELP_CMD_IMAGE                 ] = NULL,
    [ T_HELP_CMD_DUMP                  ] = NULL,
    [ T_HELP_1_2                       ] = "Konvertuj x/obrni x\t",
    [ T_HELP_1_3                       ] = "Selftest\t\t",
    [ T_HELP_1_4                       ] = "Poništi postavke na Bus Pirate\t",
    [ T_HELP_1_5                       ] = "Prebaci na bootloader\t",
    [ T_HELP_1_6                       ] = "Odloži 1 us/MS (d:4 za ponavljanje)",
    [ T_HELP_1_7                       ] = "Postavi IO.x stanje (low/HI/READ)",
    [ T_HELP_COMMAND_AUX               ] = "Postavi IO x stanje (low/HI/READ)",
    [ T_HELP_COMMAND_DISPLAY           ] = NULL,
    [ T_HELP_1_9                       ] = "Konfiguracijski izbornik\t",
    [ T_HELP_1_22                      ] = "Prikaži napon na IOx (jednom/CONT)",
    [ T_HELP_1_10                      ] = "Prikaži napon na svim IO (jednom/CONT)",
    [ T_HELP_1_11                      ] = "Izmjeri frekvenciju na IOx (jednom/CONT)",
    [ T_HELP_1_23                      ] = "Prati frekvenciju (off/ON)\t",
    [ T_HELP_1_12                      ] = "Generiši frekvenciju (off/ON)",
    [ T_HELP_HELP_GENERAL              ] = NULL,
    [ T_HELP_HELP_DISPLAY              ] = NULL,
    [ T_HELP_HELP_COMMAND              ] = NULL,
    [ T_HELP_1_14                      ] = "Versioninfo/statusinfo\t",
    [ T_HELP_1_15                      ] = "Bitorder (msb/LSB)\t",
    [ T_HELP_1_16                      ] = "Promjeni mod\t\t",
    [ T_HELP_1_17                      ] = "Zadaj format prikaza brojeva",
    [ T_HELP_1_18                      ] = "Pull-up otpornik (off/ON)",
    [ T_HELP_1_19                      ] = "-\t\t\t",
    [ T_HELP_1_20                      ] = "Prikaži napon/stanja\t",
    [ T_HELP_1_21                      ] = "Napajanje (off/ON)\t",
    [ T_HELP_2_1                       ] = "Makro mod x/prikaži sve\t",
    [ T_HELP_2_3                       ] = "Start",
    [ T_HELP_2_4                       ] = "Stop",
    [ T_HELP_2_7                       ] = "Pošalji string",
    [ T_HELP_2_8                       ] = NULL,
    [ T_HELP_2_9                       ] = NULL,
    [ T_HELP_2_10                      ] = "Pošalji vrijednost",
    [ T_HELP_2_11                      ] = "Čitaj",
    [ T_HELP_SYN_CLOCK_HIGH            ] = NULL,
    [ T_HELP_SYN_CLOCK_LOW             ] = NULL,
    [ T_HELP_SYN_CLOCK_TICK            ] = NULL,
    [ T_HELP_SYN_DATA_HIGH             ] = NULL,
    [ T_HELP_SYN_DATA_LOW              ] = NULL,
    [ T_HELP_SYN_DATA_READ             ] = NULL,
    [ T_HELP_2_18                      ] = "Čitaj bit",
    [ T_HELP_2_19                      ] = "Ponovi npr. r:10",
    [ T_HELP_2_20                      ] = "Pročitaj/zapiši bita npr. 0x55.2",
    [ T_HELP_2_21                      ] = "Korisnički makro x/izlistaj sve",
    [ T_HELP_2_22                      ] = "Korisnički makro dodijeli x",
    [ T_HELP_HINT                      ] = "Uvežite više naredbi sa ; || &&.\r\n\r\nProbajte -h pomoć: ls -h",
    [ T_HELP_FLASH                     ] = NULL,
    [ T_HELP_FLASH_ERASE               ] = NULL,
    [ T_HELP_FLASH_WRITE               ] = NULL,
    [ T_HELP_FLASH_READ                ] = NULL,
    [ T_HELP_FLASH_VERIFY              ] = NULL,
    [ T_HELP_FLASH_TEST                ] = NULL,
    [ T_HELP_FLASH_PROBE               ] = NULL,
    [ T_HELP_FLASH_INIT                ] = NULL,
    [ T_HELP_FLASH_FILE_FLAG           ] = NULL,
    [ T_HELP_FLASH_ERASE_FLAG          ] = NULL,
    [ T_HELP_FLASH_VERIFY_FLAG         ] = NULL,
    [ T_INFO_FIRMWARE                  ] = NULL,
    [ T_INFO_BOOTLOADER                ] = NULL,
    [ T_INFO_WITH                      ] = "sa",
    [ T_INFO_RAM                       ] = NULL,
    [ T_INFO_FLASH                     ] = NULL,
    [ T_INFO_SN                        ] = NULL,
    [ T_INFO_WEBSITE                   ] = NULL,
    [ T_INFO_TF_CARD                   ] = NULL,
    [ T_INFO_FILE_SYSTEM               ] = NULL,
    [ T_NOT_DETECTED                   ] = NULL,
    [ T_INFO_AVAILABLE_MODES           ] = "Dostupni modovi",
    [ T_INFO_CURRENT_MODE              ] = "Aktivni mod",
    [ T_INFO_POWER_SUPPLY              ] = "Napajanje",
    [ T_INFO_CURRENT_LIMIT             ] = "Granica struje",
    [ T_INFO_PULLUP_RESISTORS          ] = "Pull-up otpornik",
    [ T_INFO_FREQUENCY_GENERATORS      ] = "Generatori frekvencija",
    [ T_INFO_DISPLAY_FORMAT            ] = "Format prikaza",
    [ T_INFO_DATA_FORMAT               ] = "Format podataka",
    [ T_INFO_BITS                      ] = "biti",
    [ T_INFO_BITORDER                  ] = NULL,
    [ T_CONFIG_FILE                    ] = "Konfiguracijska datoteka",
    [ T_CONFIG_CONFIGURATION_OPTIONS   ] = "Konfiguracijske opcije",
    [ T_CONFIG_LANGUAGE                ] = NULL,
    [ T_CONFIG_ANSI_COLOR_MODE         ] = NULL,
    [ T_CONFIG_ANSI_COLOR_FULLCOLOR    ] = NULL,
    [ T_CONFIG_ANSI_COLOR_256          ] = NULL,
    [ T_CONFIG_ANSI_TOOLBAR_MODE       ] = NULL,
    [ T_CONFIG_LANGUAGE_ENGLISH        ] = NULL,
    [ T_CONFIG_LANGUAGE_CHINESE        ] = NULL,
    [ T_CONFIG_LANGUAGE_POLISH         ] = NULL,
    [ T_CONFIG_LANGUAGE_BOSNIAN        ] = NULL,
    [ T_CONFIG_LANGUAGE_ITALIAN        ] = NULL,
    [ T_CONFIG_DISABLE                 ] = "Onemogući",
    [ T_CONFIG_ENABLE                  ] = "Omogući",
    [ T_CONFIG_SCREENSAVER             ] = NULL,
    [ T_CONFIG_SCREENSAVER_5           ] = "5 minuta",
    [ T_CONFIG_SCREENSAVER_10          ] = "10 minuta",
    [ T_CONFIG_SCREENSAVER_15          ] = "15 minuta",
    [ T_CONFIG_LEDS_EFFECT             ] = "LED efektri",
    [ T_CONFIG_LEDS_EFFECT_SOLID       ] = "Jednobojno",
    [ T_CONFIG_LEDS_EFFECT_ANGLEWIPE   ] = "Ugaono kruženje",
    [ T_CONFIG_LEDS_EFFECT_CENTERWIPE  ] = "Centrirano kruženje",
    [ T_CONFIG_LEDS_EFFECT_CLOCKWISEWIPE ] = "Kruženje u smijeru kazaljke",
    [ T_CONFIG_LEDS_EFFECT_TOPDOWNWIPE ] = "Prelaz odozgo",
    [ T_CONFIG_LEDS_EFFECT_SCANNER     ] = "Skener",
    [ T_CONFIG_LEDS_EFFECT_GENTLE_GLOW ] = NULL,
    [ T_CONFIG_LEDS_EFFECT_CYCLE       ] = "Ludnica mod",
    [ T_CONFIG_LEDS_COLOR              ] = "LED boja",
    [ T_CONFIG_LEDS_COLOR_RAINBOW      ] = "Duga",
    [ T_CONFIG_LEDS_COLOR_RED          ] = "Crvena",
    [ T_CONFIG_LEDS_COLOR_ORANGE       ] = "Narandžasta",
    [ T_CONFIG_LEDS_COLOR_YELLOW       ] = "Žuta",
    [ T_CONFIG_LEDS_COLOR_GREEN        ] = "Zelena",
    [ T_CONFIG_LEDS_COLOR_BLUE         ] = "Plava",
    [ T_CONFIG_LEDS_COLOR_PURPLE       ] = "Ljubičasta",
    [ T_CONFIG_LEDS_COLOR_PINK         ] = "Roza",
    [ T_CONFIG_LEDS_COLOR_WHITE        ] = NULL,
    [ T_CONFIG_LEDS_BRIGHTNESS         ] = "LED svjetlina",
    [ T_CONFIG_LEDS_BRIGHTNESS_10      ] = NULL,
    [ T_CONFIG_LEDS_BRIGHTNESS_20      ] = NULL,
    [ T_CONFIG_LEDS_BRIGHTNESS_30      ] = NULL,
    [ T_CONFIG_LEDS_BRIGHTNESS_40      ] = NULL,
    [ T_CONFIG_LEDS_BRIGHTNESS_50      ] = NULL,
    [ T_CONFIG_LEDS_BRIGHTNESS_100     ] = "100% ***UPOZORENJE: doći će do oštećenja bez vanjskog USB napajanja***",
    [ T_CONFIG_BINMODE_SELECT          ] = NULL,
    [ T_HELP_DUMMY_COMMANDS            ] = NULL,
    [ T_HELP_DUMMY_INIT                ] = NULL,
    [ T_HELP_DUMMY_TEST                ] = NULL,
    [ T_HELP_DUMMY_FLAGS               ] = NULL,
    [ T_HELP_DUMMY_B_FLAG              ] = NULL,
    [ T_HELP_DUMMY_I_FLAG              ] = NULL,
    [ T_HELP_DUMMY_FILE_FLAG           ] = NULL,
    [ T_HELP_SLE4442                   ] = NULL,
    [ T_HELP_SLE4442_INIT              ] = NULL,
    [ T_HELP_SLE4442_DUMP              ] = NULL,
    [ T_HELP_SLE4442_UNLOCK            ] = NULL,
    [ T_HELP_SLE4442_WRITE             ] = NULL,
    [ T_HELP_SLE4442_ERASE             ] = NULL,
    [ T_HELP_SLE4442_PSC               ] = NULL,
    [ T_HELP_SLE4442_ADDRESS_FLAG      ] = NULL,
    [ T_HELP_SLE4442_VALUE_FLAG        ] = NULL,
    [ T_HELP_SLE4442_CURRENT_PSC_FLAG  ] = NULL,
    [ T_HELP_SLE4442_NEW_PSC_FLAG      ] = NULL,
    [ T_HELP_SLE4442_FILE_FLAG         ] = NULL,
    [ T_HELP_GCMD_W                    ] = NULL,
    [ T_HELP_GCMD_W_DISABLE            ] = NULL,
    [ T_HELP_GCMD_W_ENABLE             ] = NULL,
    [ T_HELP_GCMD_W_VOLTS              ] = NULL,
    [ T_HELP_GCMD_W_CURRENT_LIMIT      ] = NULL,
    [ T_HELP_GCMD_P                    ] = NULL,
    [ T_HELP_HELP                      ] = NULL,
    [ T_HELP_SYS_COMMAND               ] = NULL,
    [ T_HELP_SYS_DISPLAY               ] = NULL,
    [ T_HELP_SYS_MODE                  ] = NULL,
    [ T_HELP_SYS_HELP                  ] = NULL,
    [ T_HELP_GCMD_SELFTEST             ] = NULL,
    [ T_HELP_GCMD_SELFTEST_CMD         ] = NULL,
    [ T_HELP_GCMD_SELFTEST_H_FLAG      ] = NULL,
    [ T_HELP_AUXIO                     ] = NULL,
    [ T_HELP_AUXIO_LOW                 ] = NULL,
    [ T_HELP_AUXIO_HIGH                ] = NULL,
    [ T_HELP_AUXIO_INPUT               ] = NULL,
    [ T_HELP_AUXIO_IO                  ] = NULL,
    [ T_HELP_DISK_HEX                  ] = NULL,
    [ T_HELP_DISK_HEX_FILE             ] = NULL,
    [ T_HELP_DISK_HEX_ADDR             ] = NULL,
    [ T_HELP_DISK_HEX_ASCII            ] = NULL,
    [ T_HELP_DISK_HEX_SIZE             ] = NULL,
    [ T_HELP_DISK_HEX_OFF              ] = NULL,
    [ T_HELP_DISK_HEX_PAGER_OFF        ] = NULL,
    [ T_HELP_DISK_CAT                  ] = NULL,
    [ T_HELP_DISK_CAT_FILE             ] = NULL,
    [ T_HELP_DISK_MKDIR                ] = NULL,
    [ T_HELP_DISK_MKDIR_DIR            ] = NULL,
    [ T_HELP_DISK_CD                   ] = NULL,
    [ T_HELP_DISK_CD_DIR               ] = NULL,
    [ T_HELP_DISK_RM                   ] = NULL,
    [ T_HELP_DISK_RM_FILE              ] = NULL,
    [ T_HELP_DISK_RM_DIR               ] = NULL,
    [ T_HELP_DISK_LS                   ] = NULL,
    [ T_HELP_DISK_LS_DIR               ] = NULL,
    [ T_HELP_DISK_FORMAT               ] = NULL,
    [ T_HELP_DISK_FORMAT_CMD           ] = NULL,
    [ T_HELP_DISK_LABEL                ] = NULL,
    [ T_HELP_DISK_LABEL_GET            ] = NULL,
    [ T_HELP_DISK_LABEL_SET            ] = NULL,
    [ T_HELP_VADC                      ] = NULL,
    [ T_HELP_VADC_SINGLE               ] = NULL,
    [ T_HELP_VADC_CONTINUOUS           ] = NULL,
    [ T_HELP_VADC_IO                   ] = NULL,
    [ T_HELP_I2C_SCAN                  ] = NULL,
    [ T_HELP_I2C_SCAN_VERBOSE          ] = NULL,
    [ T_HELP_FLAG                      ] = NULL,
    [ T_HELP_I2C_SI7021                ] = NULL,
    [ T_HELP_I2C_MS5611                ] = NULL,
    [ T_HELP_I2C_TSL2561               ] = NULL,
    [ T_HELP_1WIRE_SCAN                ] = NULL,
    [ T_HELP_1WIRE_DS18B20             ] = NULL,
    [ T_HELP_UART_BRIDGE               ] = NULL,
    [ T_HELP_UART_BRIDGE_EXIT          ] = NULL,
    [ T_HELP_UART_BRIDGE_TOOLBAR       ] = NULL,
    [ T_HELP_UART_BRIDGE_SUPPRESS_LOCAL_ECHO ] = NULL,
    [ T_HELP_UART_NMEA                 ] = NULL,
    [ T_HELP_UART_GLITCH_EXIT          ] = NULL,
    [ T_HELP_UART_SIDECHAN             ] = NULL,
    [ T_HELP_SECTION_SCRIPT            ] = NULL,
    [ T_HELP_CMD_SCRIPT                ] = NULL,
    [ T_HELP_CMD_BUTTON                ] = NULL,
    [ T_HELP_CMD_MACRO                 ] = NULL,
    [ T_HELP_CMD_TUTORIAL              ] = NULL,
    [ T_HELP_CMD_PAUSE_KEY             ] = NULL,
    [ T_HELP_CMD_PAUSE_BUTTON          ] = NULL,
    [ T_HELP_CMD_PAUSE_EXIT            ] = NULL,
    [ T_HELP_BUTTON                    ] = NULL,
    [ T_HELP_BUTTON_SHORT              ] = NULL,
    [ T_HELP_BUTTON_LONG               ] = NULL,
    [ T_HELP_BUTTON_FILE               ] = NULL,
    [ T_HELP_BUTTON_HIDE               ] = NULL,
    [ T_HELP_BUTTON_EXIT               ] = NULL,
    [ T_HELP_LOGIC                     ] = NULL,
    [ T_HELP_LOGIC_START               ] = NULL,
    [ T_HELP_LOGIC_STOP                ] = NULL,
    [ T_HELP_LOGIC_HIDE                ] = NULL,
    [ T_HELP_LOGIC_SHOW                ] = NULL,
    [ T_HELP_LOGIC_NAV                 ] = NULL,
    [ T_HELP_LOGIC_INFO                ] = NULL,
    [ T_HELP_LOGIC_FREQUENCY           ] = NULL,
    [ T_HELP_LOGIC_OVERSAMPLE          ] = NULL,
    [ T_HELP_LOGIC_DEBUG               ] = NULL,
    [ T_HELP_LOGIC_SAMPLES             ] = NULL,
    [ T_HELP_LOGIC_TRIGGER_PIN         ] = NULL,
    [ T_HELP_LOGIC_TRIGGER_LEVEL       ] = NULL,
    [ T_HELP_LOGIC_LOW_CHAR            ] = NULL,
    [ T_HELP_LOGIC_HIGH_CHAR           ] = NULL,
    [ T_HELP_CMD_CLS                   ] = NULL,
    [ T_HELP_SECTION_TOOLS             ] = NULL,
    [ T_HELP_CMD_LOGIC                 ] = NULL,
    [ T_HELP_CMD_SMPS                  ] = NULL,
    [ T_INFRARED_CMD_TEST              ] = NULL,
    [ T_UART_CMD_TEST                  ] = NULL,
    [ T_SPI_CMD_SNIFF                  ] = NULL,
    [ T_HELP_UART_GLITCH               ] = NULL,
    [ T_HELP_SIDECHAN_GLITCH           ] = NULL,
    [ T_HELP_UART_GLITCH_CONFIG        ] = NULL,

};
