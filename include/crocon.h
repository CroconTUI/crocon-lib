#ifndef _CROCON_CROCON_H
#define _CROCON_CROCON_H

#include <widgets/screen.h>
#include <utils/colors.h>

#ifdef WIN32
	#include <os/win32/crocscrn.h>
#endif

typedef struct _crocon_version {
	int major;
	int minor;
	int patch;
} CROCVERSION;

#ifdef CROCON_LIB
	extern CROCSCREEN* stdscr;
#else
	#ifdef UNIX
		CROCSCREEN* stdscr;
	#elif WIN32
		__declspec(dllimport) CROCSCREEN* stdscr;
	#endif
#endif

int crocon_initscr();
int crocon_settitle(const char* title);
int crocon_getver(CROCVERSION* version);
int crocon_clearscr();

int crocon_fillchar(
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height,
	const char c
);

int crocon_fillcolor(
	unsigned int orig_x, unsigned orig_y,
	unsigned int width, unsigned int height,
	rgbi4_t bg_color, rgbi4_t fg_color
);

int crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
);

int crocon_cprintf(rgbi4_t fg_color, const char* str);
int crocon_cprintf2(
	rgbi4_t fg_color, int length, const char* str, ...
);

int crocon_mvcprintf(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, const char* str
);

int crocon_mvcprintf2(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, int length, const char* str, ...
);

int crocon_move(unsigned int x, unsigned int y);

int crocon_getch();

int crocon_freescr();

#endif
