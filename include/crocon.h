#ifndef CROCON_LIB
#define CROCON_LIB

#include <widgets/screen.h>

#ifdef WIN32
	#include <os/win32/crocscrn.h>
#endif

typedef struct _crocon_version {
	int major;
	int minor;
	int patch;
} CROCVERSION;

int crocon_initscr();
int crocon_settitle(const char* title);
int crocon_getver(CROCVERSION* version);
int crocon_clearscr();

int crocon_fillchar(
	const char c, 
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height
);

int crocon_cprintf(rgbi4_t fg_color, const char* str);
int crocon_mvcprintf(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, const char* str
);

#endif
