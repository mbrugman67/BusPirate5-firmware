/*
 * nuvo51icp, an ICP flasher for the Nuvoton NuMicro 8051 line of chips
 * https://github.com/steve-m/N76E003-playground
 *
 * Copyright (c) 2021 Steve Markgraf <steve@steve-m.de>
 * Copyright (c) 2023-2024 Nikita Lita
 * Copyright (c) 2025 Matt Brugman <mattb@linux.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "pico/stdlib.h"

#include "pirate.h"
#include "pirate/bio.h"
#include "system_config.h"

#define M_NUV_RESET BIO0
#define M_NUV_CLOCK BIO1
#define M_NUV_DATA BIO2
#define M_NUV_TRIGGER BIO3

static const char pin_labels[][5] = {"RST", "CLK", "DAT", "TRG"};

static uint8_t pgm_init_done = false;
/*
static int8_t dat_dir = -1;
static int8_t dat = -1;
static int8_t rst = -1;
static int8_t clk = -1;
*/
uint8_t N51PGM_is_init()
{
	return (pgm_init_done);
}

int N51PGM_init(void)
{
	// allocate the 3 I/O points
    system_bio_update_purpose_and_label(true, M_NUV_RESET, BP_PIN_IO, pin_labels[0]);
    system_bio_update_purpose_and_label(true, M_NUV_CLOCK, BP_PIN_IO, pin_labels[1]);
    system_bio_update_purpose_and_label(true, M_NUV_DATA, BP_PIN_IO, pin_labels[2]);
    system_bio_update_purpose_and_label(true, M_NUV_TRIGGER, BP_PIN_IO, pin_labels[3]);

	// reset, clock, and trigger are outputs.  Set data to be an input to start with
    bio_output(M_NUV_RESET);
    bio_output(M_NUV_CLOCK);
    bio_output(M_NUV_TRIGGER);
    bio_input(M_NUV_DATA);

    // set initial output states
    bio_put(M_NUV_RESET, 0);
    bio_put(M_NUV_CLOCK, 0);
    bio_put(M_NUV_TRIGGER, 0);

	pgm_init_done = true;

	return (0);
}

void N51PGM_set_dat(uint8_t val)
{
	bio_put(M_NUV_DATA, (bool)val);
}

uint8_t N51PGM_get_dat(void)
{
	return (bio_get(M_NUV_DATA));
}

void N51PGM_set_rst(uint8_t val)
{
	bio_put(M_NUV_RESET, val);
	bio_put(M_NUV_TRIGGER, val);
}

void N51PGM_set_clk(uint8_t val)
{
	bio_put(M_NUV_CLOCK, val);
}

void N51PGM_dat_dir(uint8_t state)
{
	if (state == true) {
		bio_output(M_NUV_DATA);
	} else {
		bio_input(M_NUV_DATA);
	}
}

void N51PGM_release_non_rst_pins(void)
{
    system_bio_update_purpose_and_label(false, M_NUV_RESET, BP_PIN_IO, pin_labels[0]);
    system_bio_update_purpose_and_label(false, M_NUV_CLOCK, BP_PIN_IO, pin_labels[1]);
    system_bio_update_purpose_and_label(false, M_NUV_DATA, BP_PIN_IO, pin_labels[2]);
    system_bio_update_purpose_and_label(false, M_NUV_TRIGGER, BP_PIN_IO, pin_labels[3]);
}

void N51PGM_release_rst(void)
{
    system_bio_update_purpose_and_label(false, M_NUV_RESET, BP_PIN_IO, pin_labels[0]);
}

void N51PGM_deinit(uint8_t leave_reset_high)
{
	if (leave_reset_high)
		N51PGM_set_rst(true);
	else{
		N51PGM_release_rst();
	}

	N51PGM_release_non_rst_pins();

	pgm_init_done = false;
}

void N51PGM_set_trigger(uint8_t val)
{
	bio_put(M_NUV_TRIGGER, (bool)val);
}

uint32_t N51PGM_usleep(uint32_t usec)
{
	busy_wait_us(usec);
	return (usec);
}

void N51PGM_print(const char *msg)
{
	printf("%s", msg);
}
