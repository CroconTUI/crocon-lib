#include <utils/colors.h>
#include <os/win32/crocclrs.h>

unsigned short _crocon_pickcolor(rgbi4_t bg_color, rgbi4_t fg_color) {

	unsigned short result;

	switch(bg_color) {

		case COLOR_RED:
			result = BACKGROUND_RED;
			break;
		case COLOR_BRIGHT_RED:
			result = BACKGROUND_RED   | BACKGROUND_INTENSITY;
			break;

		case COLOR_GREEN:
			result = BACKGROUND_GREEN;
			break;
		case COLOR_BRIGHT_GREEN:
			result = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
			break;

		case COLOR_BLUE:
			result = BACKGROUND_BLUE;
			break;
		case COLOR_BRIGHT_BLUE:
			result = BACKGROUND_BLUE  | BACKGROUND_INTENSITY;
			break;

		case COLOR_CYAN:
			result = BACKGROUND_BLUE  | BACKGROUND_GREEN;
			break;
		case COLOR_BRIGHT_CYAN:
			result = BACKGROUND_BLUE  | BACKGROUND_GREEN |
					 BACKGROUND_INTENSITY;
			break;

		case COLOR_MAGENTA:
			result = BACKGROUND_RED   | BACKGROUND_BLUE;
			break;
		case COLOR_BRIGHT_MAGENTA:
			result = BACKGROUND_RED   | BACKGROUND_BLUE	 |
					 BACKGROUND_INTENSITY;
			break;

		case COLOR_YELLOW:
			result = BACKGROUND_RED   | BACKGROUND_GREEN;
			break;
		case COLOR_BRIGHT_YELLOW:
			result = BACKGROUND_RED   | BACKGROUND_GREEN |
					 BACKGROUND_INTENSITY;
			break;

		case COLOR_BRIGHT:
			result = BACKGROUND_INTENSITY;
			break;

		case COLOR_GRAY:
			result = BACKGROUND_RED   | BACKGROUND_GREEN     | 
				     BACKGROUND_BLUE;
			break;

		case COLOR_WHITE:
			result = BACKGROUND_RED   | BACKGROUND_GREEN     | 
				     BACKGROUND_BLUE  | BACKGROUND_INTENSITY;
			break;
		default:
			result = 0;
			break;  
	}

	switch(fg_color) {

		case COLOR_RED:
			result |= FOREGROUND_RED;
			break;
		case COLOR_BRIGHT_RED:
			result |= FOREGROUND_RED | FOREGROUND_INTENSITY;
			break;

		case COLOR_GREEN:
			result |= FOREGROUND_GREEN;
			break;
		case COLOR_BRIGHT_GREEN:
			result |= FOREGROUND_GREEN | FOREGROUND_INTENSITY;
			break;
				
		case COLOR_BLUE:
			result |= FOREGROUND_BLUE;
			break;
		case COLOR_BRIGHT_BLUE:
			result |= FOREGROUND_BLUE | FOREGROUND_INTENSITY;
			break;

		case COLOR_CYAN:
			result |= FOREGROUND_BLUE | BACKGROUND_GREEN;
			break;
		case COLOR_BRIGHT_CYAN:
			result |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
			break;

		case COLOR_MAGENTA:
			result |= FOREGROUND_RED  | BACKGROUND_BLUE;
			break;
		case COLOR_BRIGHT_MAGENTA:
			result |= FOREGROUND_RED  | FOREGROUND_BLUE  | FOREGROUND_INTENSITY;
			break;

		case COLOR_YELLOW:
			result |= FOREGROUND_RED  | BACKGROUND_GREEN;
			break;
		case COLOR_BRIGHT_YELLOW:
			result |= FOREGROUND_RED  | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
			break;

		case COLOR_BRIGHT:
			result |= FOREGROUND_INTENSITY;
			break;
		case COLOR_WHITE:
			result |= FOREGROUND_RED  | FOREGROUND_GREEN     | 
			          FOREGROUND_BLUE | FOREGROUND_INTENSITY;
			break;
		
		default: 
			result |= FOREGROUND_RED  | FOREGROUND_GREEN     | 
			          FOREGROUND_BLUE; 
			break;
	}
	
	return result;	
}
