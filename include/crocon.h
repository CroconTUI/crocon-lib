#ifndef CROCON_LIB
#define CROCON_LIB

typedef struct {
	int major;
	int minor;
	int patch;
} CROCVERSION;

int crocon_initscr();
int crocon_settitle(const char* title);
int crocon_getver(CROCVERSION* version);

#endif
