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

#ifndef _CROCON_UTILS_COLORS_H
#define _CROCON_UTILS_COLORS_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

// Background and foreground colors (by RGBI HEX system)

typedef enum {

	COLOR_TRANSPARENT        = 0x00000000,
	COLOR_BLACK              = 0x00000080,

	COLOR_RED                = 0xFF000080,
	COLOR_BRIGHT_RED         = 0xFF0000FF,

	COLOR_GREEN              = 0x00FF0080,
	COLOR_BRIGHT_GREEN       = 0x00FF00FF,
	
	COLOR_BLUE               = 0x0000FF80,
	COLOR_BRIGHT_BLUE        = 0x0000FFFF,

	COLOR_CYAN               = 0x00FFFF80,
	COLOR_BRIGHT_CYAN        = 0x00FFFFFF,

	COLOR_MAGENTA            = 0xFF00FF80,
	COLOR_BRIGHT_MAGENTA     = 0xFF00FFFF,

	COLOR_YELLOW             = 0xFFFF0080,
	COLOR_BRIGHT_YELLOW      = 0xFFFF00FF,

	COLOR_BRIGHT             = 0x000000FF,

	COLOR_GRAY               = 0xFFFFFF80,
	COLOR_WHITE              = 0xFFFFFFFF

	// Total: 16 colors

} rgbi4_t;

#ifdef __cplusplus
}
#endif

#endif
