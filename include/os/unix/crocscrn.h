#ifndef _CROCON_OS_UNIX_CROCSCRN_H
#define _CROCON_OS_UNIX_CROCSCRN_H

#include <os/unix/crocunix.h>
#include <os/unix/crocclrs.h>

#include <stdlib.h>

extern int _crocon_initscr(CROCSCREEN* scr);
extern int _crocon_settitle();
extern int _crocon_clearscr();

extern int _crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
);

#endif
