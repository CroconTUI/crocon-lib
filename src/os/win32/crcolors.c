/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2026, CroconTUI Project
 * Copyright (c) 2026, Dmitry Tretyakov
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <utils/colors.h>
#include <os/win32/crcolors.h>

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
