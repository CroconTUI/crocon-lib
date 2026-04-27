#ifndef _CROCON_WIDGETS_SCREEN_H
#define _CROCON_WIDGETS_SCREEN_H

#include <utils/metrics.h>
#include <utils/colors.h>

typedef struct _crocon_screen {
	bool alive;
	bool echo;
	bool monochrome;
	bool cursor_vis;

	// Screen metrics (X, Y, width, height, scrollable or not and etc)
	CROCMETRICS* metrics;

	// Background and foreground colors
	rgbi4_t fg_color;
	rgbi4_t bg_color;
} CROCSCREEN;

#endif
