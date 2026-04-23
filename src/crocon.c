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

int crocon_clearscr() {
	return _crocon_clearscr();
}	

int crocon_fillchar(
	const char c, 
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height
) {
	return _crocon_fillchar(c, x, y, width, height);	
}

int crocon_cprintf(rgbi4_t fg_color, const char* str) {
	return _crocon_cprintf(fg_color, str);
}

int crocon_mvcprintf(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, const char* str
) {
	return _crocon_mvcprintf(x, y, fg_color, str);
}

int crocon_getch() {
	return _crocon_getch();
}

