#include <os/win32/crocw32.h>

extern int _crocon_initscr();
extern int _crocon_settitle();
extern int _crocon_clearscr();
extern int _crocon_fillchar(
	const char c, 
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height
);
