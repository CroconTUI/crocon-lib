#ifdef UNIX

#include <os/unix/crocscrn.h>
#include <stdio.h>
#include <stdlib.h>

FILE* _crocon_stdout;

int _crocon_initscr(CROCSCREEN* scr) {
	
	struct winsize w;
	_crocon_stdout = stdout;
	
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	scr->metrics.width  = w.ws_col;
	scr->metrics.height = w.ws_row;

	return true;
}

int _crocon_settitle(const char* title) {	
	printf("\033]0;%s\007", title);
	return 0;
}

int _crocon_clearscr() {
	_crocon_fillscr(COLOR_BLACK, COLOR_GRAY, ' ');
	return 0;
}

int _crocon_fillchar(
	unsigned int orig_x, unsigned int orig_y,
	unsigned int width, unsigned int height,
	const char c 
) {
	unsigned int x = width;
	unsigned int y = height;

	for(y; y > 0; y--) {
		printf("\033[%d;%dH", orig_y + y, orig_x + x);
		for(x; x > 0; x--) {
			putchar(c);
		}
		fflush(stdout);
		x = width;
	}

	return 0;
}

int _crocon_fillcolor(
	unsigned int orig_x, unsigned int orig_y,
	unsigned int width, unsigned int height,
	rgbi4_t bg_color, rgbi4_t fg_color
) {
	const char* color;
	const char* def_color;

	unsigned int x = width;
	unsigned int y = height;

	color     = _crocon_pickcolor(bg_color, fg_color);
	def_color = "\033[m";

	
	for(y; y > 0; y--) {
		printf("\033[%d;%dH", orig_y + y, orig_x + x);
		printf(color);
		for(x; x > 0; x--) {
			putchar(' ');
		}
		printf(def_color);
		fflush(stdout);
		x = width;
	}

	
	return 0;
}

int _crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
) {
	printf("\033[H\033[J");
	return 0;
}

int _crocon_cprintf(rgbi4_t fg_color, const char* str) {
	const char* color;
	const char* def_color;
	char* cstr;
	
	cstr = malloc((strlen(str) + 22) * sizeof(char));

	color     = _crocon_pickcolor(COLOR_TRANSPARENT, fg_color);
	def_color = "\033[m";

	strcpy(cstr, color);
	strcat(cstr, str);
	strcat(cstr, def_color);
	
	printf("%s", cstr);
	
	free(color);
	free(cstr);
	
	return 0;
}

int _crocon_cprintf2(rgbi4_t bg_color, rgbi4_t fg_color, const char* str) {
	const char* color;
	const char* def_color;
	char* cstr;
	
	cstr = malloc((strlen(str) + 22) * sizeof(char));

	color     = _crocon_pickcolor(bg_color, fg_color);
	def_color = "\033[m";

	strcpy(cstr, color);
	strcat(cstr, str);
	strcat(cstr, def_color);
	
	printf("%s", cstr);
	
	free(color);
	free(cstr);
	
	return 0;
}

int _crocon_cprintf3(rgbi4_t fg_color, int length, const char* fmt_str, va_list args) {
	
	char* str = malloc(length * sizeof(length));
	
	vsnprintf(str, length, fmt_str, args);
	
	_crocon_cprintf(fg_color, str);

	free(str);

	return 0;
}

int _crocon_cprintf4(rgbi4_t bg_color, rgbi4_t fg_color, int length, const char* fmt_str, va_list args) {
	
	char* str = malloc(length * sizeof(length));
	
	vsnprintf(str, length, fmt_str, args);
	
	_crocon_cprintf2(bg_color, fg_color, str);

	free(str);

	return 0;
}

int _crocon_move(unsigned int x, unsigned int y) {
	printf("\033[%d;%dH", y + 1, x);
	return 0;
}

int _crocon_getch() {
	return getchar();
}

#endif
