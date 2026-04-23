#ifndef _CROCON_UTILS_COLORS_H
#define _CROCON_UTILS_COLORS_H

#include <stdio.h>

// Background and foreground colors (by RGBI HEX system)

typedef enum {
	COLOR_BLACK 	= 0x00000000,
	COLOR_RED		= 0xFF000000,
	COLOR_GREEN 	= 0x00FF0000,
	COLOR_BLUE  	= 0x0000FF00,
	COLOR_CYAN  	= 0x00FFFF00,
	COLOR_MAGENTA 	= 0xFF00FF00,
	COLOR_YELLOW	= 0xFFFF0000,
	COLOR_BRIGHT	= 0x000000FF,
} rgbi4_t;

#endif
