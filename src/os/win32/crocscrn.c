#ifdef WIN32

#include <os/win32/crocscrn.h>

HANDLE _crocon_stdout = INVALID_HANDLE_VALUE;

int _crocon_initscr() {
	
	HANDLE hStdOut = INVALID_HANDLE_VALUE;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int result;

	if(!(result = FreeConsole()))
		return false;

	if(!(result = AllocConsole()))
		return false;

	_crocon_stdout = GetStdHandle(STD_OUTPUT_HANDLE);

	hStdOut = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
	
	if(hStdOut == INVALID_HANDLE_VALUE)
		hStdOut = _crocon_stdout;

	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	_crocon_fillchar(' ', 0, 0, csbi.dwSize.X, csbi.dwSize.Y);

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

	cursor.X = 0;
	cursor.Y = 0;

	GetConsoleScreenBufferInfo(_crocon_stdout, &csbi);
	FillConsoleOutputCharacter(
		_crocon_stdout, ' ', 
		(DWORD)(csbi.dwSize.X * csbi.dwSize.Y), cursor, &written
	);
	
	return 0;	
}

int _crocon_fillchar(
	const char c, 
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height
) {
	COORD cursor;
	DWORD written;

	cursor.X = x;
	cursor.Y = y;

	for(y; y < y + height; y++)	{
		FillConsoleOutputCharacter(_crocon_stdout, c, (DWORD)width, cursor, &written);
	}

	return 0;
}

#endif
