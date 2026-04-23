#include <crocon.h>
#include <crocpriv.h>

int crocon_initscr() {

	_crocon_initscr();
	_crocon_clearscr();
	_crocon_move(0, 0);

	return 0;
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
	unsigned int x, unsigned int y,
	unsigned int width, unsigned int height,
	const char c 
) {
	return _crocon_fillchar(x, y, width, height, c);	
}

int crocon_fillcolor(
	unsigned int x,     unsigned int y,
	unsigned int width, unsigned int height,
	rgbi4_t bg_color, rgbi4_t fg_color
) {
	return _crocon_fillcolor(x, y, width, height, bg_color, fg_color);	
}

int crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color,
	const char c
) {
	return _crocon_fillscr(bg_color, fg_color, c);	
}

int crocon_cprintf(rgbi4_t fg_color, const char* str) {
	return _crocon_cprintf(fg_color, str);
}

int crocon_cprintf2(
	rgbi4_t fg_color, int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

	_crocon_cprintf2(fg_color, length, str, args);

	va_end(args);

	return 0;
}

int crocon_mvcprintf(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, const char* str
) {
	_crocon_move(x, y);
	return _crocon_cprintf(fg_color, str);
}

int crocon_mvcprintf2(
	unsigned int x, unsigned int y, 
	rgbi4_t fg_color, int length, const char* str, ...
) {
	va_list args;
	va_start(args, str);

 	_crocon_move(x, y);
	_crocon_cprintf2(fg_color, length, str, args);

	va_end(args);

	return 0;
}

int crocon_move(unsigned int x, unsigned int y) {
	return _crocon_move(x, y);
}

int crocon_getch() {
	return _crocon_getch();
}

