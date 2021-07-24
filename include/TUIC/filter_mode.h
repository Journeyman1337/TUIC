/*
	Copyright (c) 2021 Daniel Valcour
	
	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/*! \file filter_mode.h
 */
#ifndef TUIC_FILTER_MODE_H //header guard
#define TUIC_FILTER_MODE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>

typedef enum TuiFilterMode
{
	TUI_FILTER_INVALID = 0,
	TUI_FILTER_POINT = 1,
	TUI_FILTER_BILINEAR = 2
} TuiFilterMode;

extern const char* kTui_Filter_Point_Name;
extern const char* kTui_Filter_Bilinear_Name;

TuiBoolean tuiFilterModeIsValid(TuiFilterMode filter_mode);
const char* tuiFilterModeToString(TuiFilterMode filter_mode);
TuiFilterMode tuiStringToFilterMode(const char* string);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard