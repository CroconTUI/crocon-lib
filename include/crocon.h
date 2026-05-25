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

#ifndef _CROCON_CROCON_H
#define _CROCON_CROCON_H

#include "widgets/screen.h"
#include "widgets/window.h"
#include "utils/colors.h"

#ifdef WIN32
	#include "os/win32/crscreen.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _crocon_version {
	int major;
	int minor;
	int patch;
	const char* suffix;
} CROCVERSION;

#ifdef CROCON_LIB
	extern CROCSCREEN* stdscr;
#else
	#ifdef UNIX
		CROCSCREEN* stdscr;
	#elif WIN32
		__declspec(dllimport) CROCSCREEN* stdscr;
	#endif
#endif

// Low-level Crocon API

int crocon_settitle(const char* title);
int crocon_getver(CROCVERSION* version);

int crocon_fillchar(
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height,
	const char c
);

int crocon_fillcolor(
	unsigned int orig_x, unsigned orig_y,
	unsigned int width, unsigned int height,
	rgbi4_t bg_color, rgbi4_t fg_color
);

int crocon_cprintf(rgbi4_t fg_color, const char* str);
int crocon_cprintf2(rgbi4_t bg_color, rgbi4_t fg_color, const char* str);

int crocon_cprintf3(
	rgbi4_t fg_color, int length, const char* str, ...
);
int crocon_cprintf4(
	rgbi4_t bg_color, rgbi4_t fg_color, int length, const char* str, ...
);

int crocon_mvcprintf(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, const char* str
);

int crocon_mvcprintf2(
	unsigned int x, unsigned int y, 
	rgbi4_t bg_color, rgbi4_t fg_color, 
	const char* str
);

int crocon_mvcprintf3(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, int length, const char* str, ...
);

int crocon_mvcprintf4(
	unsigned int x, unsigned int y, 
	rgbi4_t bg_color, rgbi4_t fg_color, 
	int length, const char* str, ...
);

int crocon_move(unsigned int x, unsigned int y);
int crocon_kbhit();
int crocon_getch();
int crocon_hidecurs(int value);

// Screen (console buffer)

int crocon_initscr();
int crocon_clearscr();

int crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
);

int crocon_freescr();

// Widgets (window, button, progressbar and etc.)

int crocon_createwin(CROCWINDOW* wnd);

#ifdef __cplusplus
}
#endif

#endif
