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
extern int _crocon_cprintf(rgbi4_t fg_color, const char* str);
extern int _crocon_mvcprintf(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, const char* str
);

#endif
