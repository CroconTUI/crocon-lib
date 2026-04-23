#ifndef _CROCON_OS_WIN32_CROCSCRN_H
#define _CROCON_OS_WIN32_CROCSCRN_H

#include <os/win32/crocw32.h>
#include <os/win32/crocclrs.h>

extern int _crocon_initscr();
extern int _crocon_settitle();
extern int _crocon_clearscr();

extern int _crocon_fillchar(
	const char c, 
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height
);

extern int _crocon_fillcolor(
	unsigned int orig_x, unsigned orig_y,
	unsigned int width, unsigned int height,
	rgbi4_t bg_color, rgbi4_t fg_color 
);

extern int _crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
);

extern int _crocon_cprintf(rgbi4_t fg_color, const char* str);

extern int _crocon_move(unsigned int x, unsigned int y);
extern int _crocon_getch();

#endif
