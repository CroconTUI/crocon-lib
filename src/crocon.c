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
#include <crocpriv.h>

#include <stdlib.h>

CROCSCREEN* stdscr;

extern int _crocon_initscr(CROCSCREEN* scr);
extern int _crocon_settitle();
extern int _crocon_clearscr();

extern int _crocon_fillchar(
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height,
	const char c
);

extern int _crocon_fillcolor(
	unsigned int orig_x, unsigned int orig_y,
	unsigned int width, unsigned int height,
	rgbi4_t bg_color, rgbi4_t fg_color 
);

extern int _crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
);

extern int _crocon_cprintf(
	rgbi4_t fg_color, const char* str
);

extern int _crocon_cprintf2(
	rgbi4_t bg_color, rgbi4_t fg_color, const char* str
);

extern int _crocon_cprintf3(
	rgbi4_t fg_color, int length, const char* str, va_list args
);

extern int _crocon_cprintf4(
	rgbi4_t bg_color, rgbi4_t fg_color, int length, const char* str, va_list args
);

extern int _crocon_move(unsigned int x, unsigned int y);
extern int _crocon_getch();
extern int _crocon_kbhit();
extern int _crocon_hidecurs();

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
	version->major = 26;
	version->minor = 4;
	version->patch = 21;
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

int crocon_cprintf(rgbi4_t fg_color, const char* str) {
	return _crocon_cprintf(fg_color, str);
}

int crocon_cprintf2(rgbi4_t bg_color, rgbi4_t fg_color, const char* str) {
	return _crocon_cprintf2(bg_color, fg_color, str);
}

int crocon_cprintf3(
	rgbi4_t fg_color, int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

	_crocon_cprintf3(fg_color, length, str, args);

	va_end(args);

	return 0;
}

int crocon_cprintf4(
	rgbi4_t bg_color, rgbi4_t fg_color, int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

	_crocon_cprintf4(bg_color, fg_color, length, str, args);

	va_end(args);

	return 0;
}

int crocon_mvcprintf(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, const char* str
) {
	_crocon_move(x, y);
	return _crocon_cprintf(fg_color, str);
}

int crocon_mvcprintf2(
	unsigned int x, unsigned int y, 
	rgbi4_t bg_color, rgbi4_t fg_color, 
	const char* str
) {
	_crocon_move(x, y);
	return _crocon_cprintf2(bg_color, fg_color, str);
}

int crocon_mvcprintf3(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

 	_crocon_move(x, y);
	_crocon_cprintf3(fg_color, length, str, args);

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
	_crocon_cprintf4(bg_color, fg_color, length, str, args);

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

int crocon_hidecurs() {
	return _crocon_hidecurs();
}

int crocon_freescr() {
	_crocon_clearscr();
	_crocon_move(0, 0);
	free(stdscr);
}

