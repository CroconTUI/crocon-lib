#ifndef _CROCON_OS_WIN32_CROCSCRN_H
#define _CROCON_OS_WIN32_CROCSCRN_H

#include <os/win32/crocw32.h>
#include <os/win32/crocclrs.h>

extern int _crocon_initscr();
extern int _crocon_settitle();
extern int _crocon_clearscr();

extern int _crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
);

#endif
