#ifndef _CROCON_UTILS_METRICS_H
#define _CROCON_UTILS_METRICS_H

#include <utils/c_exts.h>

typedef struct _crocon_metrics {
	
	// Screen coordinates (up to 16383 x 16383 chars)
	unsigned short 	x_pos 		: 14;
	unsigned short 	y_pos 		: 14;

	// Active width area size (up to 16383 x 16383 chars)
	unsigned short 	width		: 14;
	unsigned short 	height 		: 14;

	// Full area size (up to 262143 x 262143 chars)
	unsigned int   	full_width   : 18; 
	unsigned int   	full_height  : 18;

	// Scrollable and sizeable widgets support
	bool 			scrollable;
	bool 			sizeable;
	unsigned int	x_scroll_pos : 18;
	unsigned int    y_scroll_pos : 18;
	 
} CROCMETRICS;

#endif
