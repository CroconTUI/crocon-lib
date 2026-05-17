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

#ifndef _CROCON_WIDGETS_WIDGET_H
#define _CROCON_WIDGETS_WIDGET_H

#include "../utils/metrics.h"
#include "../utils/colors.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	WIDGET_EMPTY    = 0,
	WIDGET_LABEL    = 1,
	WIDGET_BUTTON   = 2,
	WIDGET_CHECKBOX = 3,
	WIDGET_RADIOBTN = 4,
	WIDGET_PROGRESS = 5,
	WIDGET_EDITBOX  = 6,
	WIDGET_LISTBOX  = 7,
	WIDGET_COMBOBOX = 8
} widget_t;

typedef union _crocon_widget {
	widget_t type;
	
	// Button, radiobutton, checkbox text
	char* title;

	// Widget metrics (X, Y, width, height, scrollable or not and etc)
	CROCMETRICS metrics;
	
	// Background and foreground colors
	rgbi4_t fg_color;
	rgbi4_t bg_color;
	
	// 'Focused', 'checked', 'enabled' flags for controls
	cbool focused;
	cbool checked;
	cbool enabled;
	cbool visible;
	
	int selected_id;
	int total_items;
	
	int min_value;
	int progress1;
	int progress2;
	int max_value;

	int style_attr;
} CROCWIDGET;

#ifdef __cplusplus
}
#endif

#endif
