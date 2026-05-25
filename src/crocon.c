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

#include <crocon.h>
#include <utils/colors.h>
#include <crocpriv.h>

#include <stdlib.h>

CROCSCREEN* stdscr;

extern cbool _crocon_initscr(CROCSCREEN* scr);
extern cbool _crocon_settitle();
extern cbool _crocon_clearscr();
extern cbool _crocon_freescr();

extern cbool _crocon_fillchar(
	uint_t x,     uint_t y,
	uint_t width, uint_t height,
	const char c
);

extern cbool _crocon_fillcolor(
	uint_t orig_x, uint_t orig_y,
	uint_t width,  uint_t height,
	rgbi4_t bg_color, rgbi4_t fg_color 
);

extern cbool _crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
);

extern cbool _crocon_cputchar(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
);

extern cbool _crocon_cprintf(
	rgbi4_t bg_color, rgbi4_t fg_color, const char* str
);

extern cbool _crocon_cprintf_va(
	rgbi4_t bg_color, rgbi4_t fg_color, int length, 
	const char* str, va_list args
);

extern cbool _crocon_move(uint_t x, uint_t y);
extern int   _crocon_getch();
extern cbool _crocon_kbhit();
extern cbool _crocon_hidecurs(cbool value);

int crocon_initscr() {

	stdscr = (CROCSCREEN*)malloc(sizeof(CROCSCREEN));

	_crocon_initscr(stdscr);
	_crocon_clearscr();
	_crocon_move(0, 0);

	return 0;
}

int crocon_settitle(const char* title) {
	return _crocon_settitle(title);
}

int crocon_getver(CROCVERSION* version) {
	version->major  = 0;
	version->minor  = 0;
	version->patch  = 1;

	#ifdef CROCON_VERSION_PREFIX
		version->suffix = CROCON_VERSION_PREFIX; 
	#else
		version->suffix = "-alpha1"; 
	#endif

	return ctrue;
}

int crocon_clearscr() {
	return _crocon_clearscr();
}	

int crocon_fillchar(
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height,
	const char c 
) {
	return _crocon_fillchar(x, y, width, height, c);
}

int crocon_fillcolor(
	unsigned int x,     unsigned int y,
	unsigned int width, unsigned int height,
	rgbi4_t bg_color, rgbi4_t fg_color
) {
	return _crocon_fillcolor(x, y, width, height, bg_color, fg_color);
}

int crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color,
	const char c
) {
	return _crocon_fillscr(bg_color, fg_color, c);	
}

int crocon_cputchar(rgbi4_t fg_color, const char c) {
	return _crocon_cputchar(COLOR_TRANSPARENT, fg_color, c);	
}

int crocon_cputchar2(rgbi4_t bg_color, rgbi4_t fg_color, const char c) {
	return _crocon_cputchar(bg_color, fg_color, c);	
}

int crocon_cprintf(rgbi4_t fg_color, const char* str) {
	return _crocon_cprintf(COLOR_TRANSPARENT, fg_color, str);
}

int crocon_cprintf2(rgbi4_t bg_color, rgbi4_t fg_color, const char* str) {
	return _crocon_cprintf(bg_color, fg_color, str);
}

int crocon_cprintf3(
	rgbi4_t fg_color, int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

	_crocon_cprintf_va(COLOR_TRANSPARENT, fg_color, length, str, args);

	va_end(args);

	return 0;
}

int crocon_cprintf4(
	rgbi4_t bg_color, rgbi4_t fg_color, int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

	_crocon_cprintf_va(bg_color, fg_color, length, str, args);

	va_end(args);

	return 0;
}

int crocon_mvcprintf(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, const char* str
) {
	_crocon_move(x, y);
	return _crocon_cprintf(COLOR_TRANSPARENT, fg_color, str);
}

int crocon_mvcprintf2(
	unsigned int x, unsigned int y, 
	rgbi4_t bg_color, rgbi4_t fg_color, 
	const char* str
) {
	_crocon_move(x, y);
	return _crocon_cprintf(bg_color, fg_color, str);
}

int crocon_mvcprintf3(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

 	_crocon_move(x, y);
	_crocon_cprintf_va(COLOR_TRANSPARENT, fg_color, length, str, args);

	va_end(args);

	return 0;
}

int crocon_mvcprintf4(
	unsigned int x, unsigned int y, 
	rgbi4_t bg_color, rgbi4_t fg_color, 
	int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

 	_crocon_move(x, y);
	_crocon_cprintf_va(COLOR_TRANSPARENT, fg_color, length, str, args);

	va_end(args);

	return 0;
}

int crocon_move(unsigned int x, unsigned int y) {
	return _crocon_move(x, y);
}

int crocon_getch() {
	return _crocon_getch();
}

int crocon_kbhit() {
	return _crocon_kbhit();
}

int crocon_hidecurs(cbool value) {
	return _crocon_hidecurs(value);
}

int crocon_freescr() {
	_crocon_clearscr();
	_crocon_move(0, 0);
	_crocon_freescr();
	free(stdscr);

	return ctrue;
}

