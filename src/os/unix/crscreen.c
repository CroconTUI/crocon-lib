#ifdef UNIX

#include <os/unix/crscreen.h>
#include <stdio.h>
#include <stdlib.h>

FILE*   _crocon_stdout;
cbool   _crocon_conio_emu;
struct  termios _crocon_old_attrs, _crocon_new_attrs;
int     _crocon_block_mode;

cbool _crocon_initscr(CROCSCREEN* scr) {
	
	struct winsize w;
	_crocon_stdout = stdout;
	
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	scr->metrics.width  = w.ws_col;
	scr->metrics.height = w.ws_row;
	
	_crocon_coniomode(ctrue);

	return ctrue;
}

cbool _crocon_freescr() {

	_crocon_hidecurs(cfalse);
	_crocon_coniomode(cfalse);

	return ctrue;
}

cbool _crocon_settitle(const char* title) {
	printf("\033]0;%s\007", title);
	return ctrue;
}

cbool _crocon_clearscr() {
	_crocon_fillscr(COLOR_BLACK, COLOR_GRAY, ' ');
	return ctrue;
}

cbool _crocon_coniomode(cbool value) {
	
	// from: https://github.com/Flawww/linux_conio/blob/main/linux_conio.cpp
	
	// allow kbhit and getch on UNIX/Linux
	if (value == _crocon_conio_emu) {
		return cfalse;
	}
	_crocon_conio_emu = value;
	
	tcgetattr(STDIN_FILENO, &_crocon_old_attrs);
	_crocon_new_attrs = _crocon_old_attrs;
	
	if(value == ctrue)
		_crocon_new_attrs.c_lflag &= ~(ICANON | ECHO);
	else
		_crocon_new_attrs.c_lflag |= (ICANON | ECHO);
	
	tcsetattr(STDIN_FILENO, TCSANOW, &_crocon_new_attrs);

	return ctrue;
}

cbool _crocon_noblock(cbool value) {
	
	// from: https://github.com/Flawww/linux_conio/blob/main/linux_conio.cpp
	
	if(value == ctrue) {
		_crocon_block_mode = fcntl(STDIN_FILENO, F_GETFL, 0);
		fcntl(STDIN_FILENO, F_SETFL, _crocon_block_mode | O_NONBLOCK);
	} else {
		fcntl(STDIN_FILENO, F_SETFL, _crocon_block_mode);
	}

	return ctrue;
}

cbool _crocon_fillchar(
	uint_t orig_x, uint_t orig_y,
	uint_t width, uint_t height,
	const char c 
) {
	unsigned int x = width;
	unsigned int y = height;

	for(y; y > 0; y--) {
		printf("\033[%d;%dH", orig_y + y, (orig_x - width) + x);
		for(x; x > 0; x--) {
			putchar(c);
		}
		fflush(stdout);
		x = width;
	}

	return ctrue;
}

cbool _crocon_fillcolor(
	uint_t orig_x, uint_t orig_y,
	uint_t width, uint_t height,
	rgbi4_t bg_color, rgbi4_t fg_color
) {
	const char* color;
	const char* def_color;

	uint_t x = width;
	uint_t y = height;

	color     = _crocon_pickcolor(bg_color, fg_color);
	def_color = "\033[m";

	
	for(y; y > 0; y--) {
		printf("\033[%d;%dH", orig_y + y, (orig_x - width) + x);
		printf(color);
		for(x; x > 0; x--) {
			putchar(' ');
		}
		printf(def_color);
		fflush(stdout);
		x = width;
	}
	
	free(color);
	
	return ctrue;
}

cbool _crocon_fillscr(
	rgbi4_t bg_color, rgbi4_t fg_color, const char c 
) {
	printf("\033[H\033[J");
	return ctrue;
}

cbool _crocon_cprintf(rgbi4_t bg_color, rgbi4_t fg_color, const char* str) {
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
	
	fflush(stdout);
	
	return ctrue;
}

cbool _crocon_cprintf_va(
	rgbi4_t bg_color, rgbi4_t fg_color, int length, 
	const char* fmt_str, va_list args
) {
	
	char* str = malloc(length * sizeof(length));
	
	vsnprintf(str, length, fmt_str, args);
	
	_crocon_cprintf(bg_color, fg_color, str);

	free(str);

	return ctrue;
}

cbool _crocon_cputchar(rgbi4_t bg_color, rgbi4_t fg_color, const char c) {
	return _crocon_cprintf(bg_color, fg_color, &c);
}

cbool _crocon_move(unsigned int x, unsigned int y) {
	printf("\033[%d;%dH", y + 1, x);
	return ctrue;
}

int _crocon_getch() {
	return getchar();
}

cbool _crocon_kbhit() {
	
	int c;
	
	// from: https://github.com/Flawww/linux_conio/blob/main/linux_conio.cpp
	
	 if (!_crocon_conio_emu) {
		return cfalse;
	}
	
 	_crocon_noblock(ctrue);
	c = getchar();
	_crocon_noblock(cfalse);
    
    // if the char returned from non-blocking getchar is not EOF, a character exists in stdin.
    if (c != EOF) {
        // put the character we read back onto the stdin stream
        ungetc(c, stdin);
        return ctrue;
    }
    
    return cfalse;
}

cbool _crocon_hidecurs(cbool value) {
	
	int result = 0;
	
	if(value == ctrue)
		printf("\033[?25l");
	else
		printf("\033[?25h");

	return ctrue;
}

#endif
