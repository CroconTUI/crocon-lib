#ifndef _CROCON_OS_UNIX_CROCSCRN_H
#define _CROCON_OS_UNIX_CROCSCRN_H

#include <os/unix/crocw32.h>
#include <os/unix/crocclrs.h>

extern int _crocon_initscr();
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
	rgbi4_t fg_color, int length, const char* str, va_list args
);

extern int _crocon_move(unsigned int x, unsigned int y);
extern int _crocon_getch();

#endif
