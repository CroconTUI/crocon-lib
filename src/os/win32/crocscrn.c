#ifdef WIN32

#include <os/win32/crocscrn.h>
#include <stdio.h>

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
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD written;
	COORD cursor;

	_crocon_stdout = GetStdHandle(STD_OUTPUT_HANDLE);

	cursor.X = 0;
	cursor.Y = 0;

	SetConsoleTextAttribute(_crocon_stdout, 0);

	GetConsoleScreenBufferInfo(_crocon_stdout, &csbi);

	FillConsoleOutputCharacter(
		_crocon_stdout, ' ', 
		csbi.dwSize.X * csbi.dwSize.Y, cursor, &written
	);
	
	return 0;	
}

int _crocon_fillchar(
	const char c, 
	unsigned int orig_x, unsigned int orig_y,
	unsigned int width, unsigned int height
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

int _crocon_cprintf(rgbi4_t fg_color, const char* str) {

	DWORD result;
	WORD color;

	color = (WORD)_crocon_pickcolor(COLOR_BLACK, fg_color);
	SetConsoleTextAttribute(_crocon_stdout, color);
	WriteConsole(_crocon_stdout, str, strlen(str), &result, NULL);
	SetConsoleTextAttribute(_crocon_stdout, 0);

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
