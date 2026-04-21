#include <crocon.h>
#include <crocpriv.h>

int crocon_initscr() {
	return _crocon_initscr();
}

int crocon_settitle(const char* title) {
	return _crocon_settitle(title);
}

int crocon_getver(CROCVERSION* version) {
	version->major = 26;
	version->minor = 4;
	version->patch = 21;
	return true;
}


