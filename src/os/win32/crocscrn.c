#ifdef WIN32

#include <os/win32/crocscrn.h>
#include <stdio.h>
#include <stdlib.h>

HANDLE _crocon_stdout = INVALID_HANDLE_VALUE;

int _crocon_initscr() {
	
	HANDLE hStdOut = INVALID_HANDLE_VALUE;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int result;

	_crocon_stdout = GetStdHandle(STD_OUTPUT_HANDLE);

	hStdOut = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
	
	if(hStdOut == INVALID_HANDLE_VALUE)
		hStdOut = _crocon_stdout;

	return true;	
}

int _crocon_settitle(const char* title) {	
	int result = SetConsoleTitle(title);
	return result;
}

int _crocon_clearscr() {

	_crocon_fillscr(COLOR_BLACK, COLOR_GRAY, ' ');
	
	return 0;	
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

	return 0;
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

	return 0;
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

	FillConsoleOutputAttribute(
		_crocon_stdout, color, width, cursor, &written
	);

	FillConsoleOutputCharacter(
		_crocon_stdout, c, width, cursor, &written
	);

	return 0;
}

int _crocon_cprintf(rgbi4_t fg_color, const char* str) {

	DWORD result;
	DWORD written;
	WORD color;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(_crocon_stdout, &csbi);

	WriteConsole(_crocon_stdout, str, strlen(str), &result, NULL);

	if(fg_color == COLOR_GRAY)
		return 0;

	color = (WORD)_crocon_pickcolor(COLOR_BLACK, fg_color);
	
	FillConsoleOutputAttribute(
		_crocon_stdout, color, strlen(str), csbi.dwCursorPosition, &written
	);

	return 0;
}

int _crocon_cprintf2(rgbi4_t fg_color, int length, const char* fmt_str, va_list args) {
	
	char* str = malloc(length * sizeof(length));
	
	#ifdef _MSC_VER >= 800
		_vsnprintf_s(str, length, length, fmt_str, args);
	#else
		_vsnprintf(str, length, fmt_str, args);
	#endif
	
	_crocon_cprintf(fg_color, str);

	free(str);

	return 0;
}

int _crocon_move(unsigned int x, unsigned int y) {
	
	COORD cursor;
	
	cursor.X = x;
	cursor.Y = y;
	
	SetConsoleCursorPosition(_crocon_stdout, cursor);
	
	return 0;	
}

int _crocon_getch() {
	return getchar();
}

#endif
