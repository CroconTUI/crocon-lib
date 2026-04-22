#ifndef CROCON_LIB
#define CROCON_LIB

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

#endif
