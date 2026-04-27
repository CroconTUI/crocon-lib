#include <utils/colors.h>
#include <os/unix/crocclrs.h>

const char* _crocon_pickcolor(rgbi4_t bg_color, rgbi4_t fg_color) {

	const char* bg_result;
	const char* fg_result;
	char result[18];

	switch(bg_color) {

		case COLOR_RED:
			bg_result = "\x1B[41m";
			break;
		case COLOR_BRIGHT_RED:
			bg_result = "\x1B[101m";
			break;

		case COLOR_GREEN:
			bg_result = "\x1B[42m";
			break;
		case COLOR_BRIGHT_GREEN:
			bg_result = "\x1B[102m";
			break;

		case COLOR_BLUE:
			bg_result = "\x1B[44m";
			break;
		case COLOR_BRIGHT_BLUE:
			bg_result = "\x1B[104m";
			break;

		case COLOR_CYAN:
			bg_result = "\x1B[46m";
			break;
		case COLOR_BRIGHT_CYAN:
			bg_result = "\x1B[106m";
			break;

		case COLOR_MAGENTA:
			bg_result = "\x1B[45m";
			break;
		case COLOR_BRIGHT_MAGENTA:
			bg_result = "\x1B[105m";
			break;

		case COLOR_YELLOW:
			bg_result = "\x1B[43m";
			break;
		case COLOR_BRIGHT_YELLOW:
			bg_result = "\x1B[103m";
			break;

		case COLOR_BRIGHT:
			bg_result = "\x1B[100m";
			break;

		case COLOR_GRAY:
			bg_result = "\x1B[100m";
			break;

		case COLOR_WHITE:
			bg_result = "\x1B[107m";
			break;
		case COLOR_BLACK:
			bg_result = "\x1B[40m";
			break;
		default:
			bg_result = "\x1B[m";
	}

	switch(fg_color) {

		case COLOR_RED:
			fg_result = "\x1B[31m";
			break;
		case COLOR_BRIGHT_RED:
			fg_result = "\x1B[91m";
			break;

		case COLOR_GREEN:
			fg_result = "\x1B[32m";
			break;
		case COLOR_BRIGHT_GREEN:
			fg_result = "\x1B[92m";
			break;
				
		case COLOR_BLUE:
			fg_result = "\x1B[34m";
			break;
		case COLOR_BRIGHT_BLUE:
			fg_result = "\x1B[94m";
			break;

		case COLOR_CYAN:
			fg_result = "\x1B[36m";
			break;
		case COLOR_BRIGHT_CYAN:
			fg_result = "\x1B[96m";
			break;

		case COLOR_MAGENTA:
			fg_result = "\x1B[35m";
			break;
		case COLOR_BRIGHT_MAGENTA:
			fg_result = "\x1B[95m";
			break;

		case COLOR_YELLOW:
			fg_result = "\x1B[33m"
;
			break;
		case COLOR_BRIGHT_YELLOW:
			fg_result = "\x1B[93m";
			break;

		case COLOR_BRIGHT:
			fg_result = "\x1B[37m";
			break;
		case COLOR_WHITE:
			fg_result = "\x1B[97m";
			break;
		
		case COLOR_GRAY:
			fg_result = "\x1B[90m";
			break;

		default: 
			fg_result = "";
			break;
	}
	
	strcpy(result, bg_result);
	strcat(result, fg_result);
	
	return result;
}
