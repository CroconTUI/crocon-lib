#ifdef WIN32

#include <os/win32/crocw32.h>

HANDLE _crocon_stdout = INVALID_HANDLE_VALUE;

int _crocon_initscr() {
	
	HANDLE hStdOut = INVALID_HANDLE_VALUE;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	_crocon_stdout = GetStdHandle(STD_OUTPUT_HANDLE);

	hStdOut = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
	
	if(hStdOut == INVALID_HANDLE_VALUE)
		hStdOut = _crocon_stdout;

	return 0;	
}

#endif
