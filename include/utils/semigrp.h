/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2026, CroconTUI Project
 * Copyright (c) 2026, Dmitry Tretyakov
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _CROCON_UTILS_SEMIGRP_H
#define _CROCON_UTILS_SEMIGRP_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

// Background and foreground colors (by RGBI HEX system)

typedef enum {

	// Single lines

	SG_LINES_1H      = 0x2500,
	SG_LINES_1V      = 0x2502,
	
	// Up/Down and Left/Right
	
	SG_LINES_1D_1R   = 0x250C,
	SG_LINES_1D_1L   = 0x2510,
	SG_LINES_1U_1R   = 0x2514,
	SG_LINES_1U_1L   = 0x2518,

	// Vertical/Horizontal and Left/Right

	SG_LINES_1V_1R   = 0x251C,
	SG_LINES_1V_1L   = 0x2524,
	SG_LINES_1H_1R   = 0x252C,
	SG_LINES_1H_1L   = 0x2534,
	
	// Cross single lines
	
	SG_LINES_1V_1H   = 0x253C,

	// Double lines

	SG_LINES_2H      = 0x2550,
	SG_LINES_2V      = 0x2551,
	
	// Double Up/Down and Double Left/Right

    SG_LINES_2D_2R   = 0x2554,
	SG_LINES_2D_2L   = 0x2557,
	SG_LINES_2U_2R   = 0x255A,
	SG_LINES_2U_2L   = 0x255D,

	// Double Vertical/Horizontal and Left/Right

	SG_LINES_2V_2R   = 0x2560,
	SG_LINES_2V_2L   = 0x2563,
	SG_LINES_2H_2R   = 0x2566,
	SG_LINES_2H_2L   = 0x2569,

	// Cross double lines
	
	SG_LINES_2V_2H   = 0x256C
	
} sgint_t;


#ifdef __cplusplus
}
#endif

#endif
