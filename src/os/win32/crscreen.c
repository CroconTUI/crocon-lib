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

#ifdef WIN32

#include <os/win32/crscreen.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

HANDLE _crocon_stdout = INVALID_HANDLE_VALUE;

int _crocon_initscr(CROCSCREEN* scr) {
	
	HANDLE hStdOut = INVALID_HANDLE_VALUE;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int result;
	COORD szMaxBuf;

	#ifndef MSVC_GE_800
		// Workaround for FPI support loading
		double fpiWa = sqrt(4);
	#endif
	
	_crocon_stdout = GetStdHandle(STD_OUTPUT_HANDLE);

	hStdOut = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
	
	if(hStdOut == INVALID_HANDLE_VALUE)
		hStdOut = _crocon_stdout;

	result = GetConsoleScreenBufferInfo(_crocon_stdout, &csbi);
	
	szMaxBuf.X = csbi.dwSize.X > 1024 ?
			1024 : csbi.dwSize.X;

	szMaxBuf.Y = csbi.dwSize.Y > 1024 ?
			1024 : csbi.dwSize.Y;

	SetConsoleScreenBufferSize(_crocon_stdout, szMaxBuf);
	
	scr->alive = ctrue;
	scr->metrics.width  = szMaxBuf.X;
	scr->metrics.height = szMaxBuf.Y;

	return ctrue;
}

int _crocon_settitle(const char* title) {
	int result = SetConsoleTitle(title);
	return result;
}

int _crocon_clearscr() {

	_crocon_fillscr(COLOR_BLACK, COLOR_GRAY, ' ');
	
	return ctrue;
}

int _crocon_fillchar(
	unsigned int orig_x, unsigned int orig_y,
	unsigned int width, unsigned int height,
	const char c 
) {

	COORD cursor;
	DWORD written;
	unsigned int x = orig_x;
	unsigned int y = orig_y;
	cursor.X = x;

	for(y; y < (orig_y + height); y++)	{
		cursor.Y = y;
		FillConsoleOutputCharacter(_crocon_stdout, c, width, cursor, &written);
	}

	return ctrue;
}

int _crocon_fillcolor(
	unsigned int orig_x, unsigned int orig_y,
	unsigned int width, unsigned int height,
	rgbi4_t bg_color, rgbi4_t fg_color
) {
	COORD cursor;
	DWORD written;
	WORD color;
	unsigned int x = orig_x;
	unsigned int y = orig_y;

	cursor.X = x;

	color = (WORD)_crocon_pickcolor(bg_color, fg_color);

	for(y; y < (orig_y + height); y++)	{
		cursor.Y = y;
		FillConsoleOutputAttribute(_crocon_stdout, color, width, cursor, &written);
	}

	return ctrue;
}

int _crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
) {
	COORD cursor;
	DWORD written;
	int width;
	WORD color;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

   	GetConsoleScreenBufferInfo(_crocon_stdout, &csbi);

	width = csbi.dwSize.X * csbi.dwSize.Y;
	
	cursor.X = 0;
	cursor.Y = 0;

	color = (WORD)_crocon_pickcolor(bg_color, fg_color);

	SetConsoleTextAttribute(_crocon_stdout, color);

	FillConsoleOutputCharacter(
		_crocon_stdout, c, width, cursor, &written
	);

	return ctrue;
}

int _crocon_cprintf(rgbi4_t fg_color, const char* str) {

	DWORD result;
	DWORD written;
	WORD color;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD cursor;

	GetConsoleScreenBufferInfo(_crocon_stdout, &csbi);
	cursor = csbi.dwCursorPosition;

	if(fg_color != COLOR_GRAY) {
		color = (WORD)_crocon_pickcolor(COLOR_BLACK, fg_color);
	
		SetConsoleTextAttribute(_crocon_stdout, color);
	} else {
		SetConsoleTextAttribute(_crocon_stdout, 0);
	}

	WriteConsole(_crocon_stdout, str, strlen(str), &result, NULL);

	return ctrue;
}

int _crocon_cprintf2(rgbi4_t bg_color, rgbi4_t fg_color, const char* str) {

	DWORD result;
	DWORD written;
	WORD color;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD cursor;

	GetConsoleScreenBufferInfo(_crocon_stdout, &csbi);
	cursor = csbi.dwCursorPosition;

	color = (WORD)_crocon_pickcolor(bg_color, fg_color);
	
	SetConsoleTextAttribute(_crocon_stdout, color);

	WriteConsole(_crocon_stdout, str, strlen(str), &result, NULL);

	SetConsoleTextAttribute(_crocon_stdout, 0);

	return ctrue;
}

int _crocon_cprintf3(rgbi4_t fg_color, int length, const char* fmt_str, va_list args) {
	
	char* str = malloc((length + 1) * sizeof(char));

	#ifdef MSVC_GE_800
		_vsnprintf_s(str, length, length, fmt_str, args);
	#else
		_vsnprintf(str, length, fmt_str, args);
	#endif
	
	_crocon_cprintf(fg_color, str);

	free(str);

	return ctrue;
}

int _crocon_cprintf4(rgbi4_t bg_color, rgbi4_t fg_color, int length, const char* fmt_str, va_list args) {
	
	char* str = malloc((length + 1) * sizeof(char));

	#ifdef MSVC_GE_800
		_vsnprintf_s(str, length, length, fmt_str, args);
	#else
		_vsnprintf(str, length, fmt_str, args);
	#endif
	
	_crocon_cprintf2(bg_color, fg_color, str);

	free(str);

	return ctrue;
}

int _crocon_move(unsigned int x, unsigned int y) {
	
	COORD cursor;
	
	cursor.X = x;
	cursor.Y = y;
	
	SetConsoleCursorPosition(_crocon_stdout, cursor);
	
	return ctrue;
}

int _crocon_getch() {
	return _getch();
}

int _crocon_kbhit() {
	return _kbhit();
}

int _crocon_hidecurs() {
	
	int result = 0;
	CONSOLE_CURSOR_INFO curs_info;

	GetConsoleCursorInfo(_crocon_stdout, &curs_info);
	curs_info.bVisible = FALSE;
	SetConsoleCursorInfo(_crocon_stdout, &curs_info);

	return result;
}

#endif
