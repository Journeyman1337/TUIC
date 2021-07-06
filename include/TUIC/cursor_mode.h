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
/*! \file cursor_mode.h
 */
#ifndef TUIC_CURSOR_MODE_H //header guard
#define TUIC_CURSOR_MODE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>

typedef enum TuiCursorMode
{
	TUI_CURSOR_MODE_INVALID = 0,
	TUI_CURSOR_MODE_NORMAL		= 0x00034001,
	TUI_CURSOR_MODE_HIDDEN		= 0x00034002,
	TUI_CURSOR_MODE_DISABLED	= 0x00034003,
	TUI_CURSOR_MODE_FIRST		= TUI_CURSOR_MODE_NORMAL,
	TUI_CURSOR_MODE_LAST		= TUI_CURSOR_MODE_DISABLED
} TuiCursorMode;

extern const char* kTui_Cursor_Mode_Normal_Name;
extern const char* kTui_Cursor_Mode_Hidden_Name;
extern const char* kTui_Cursor_Mode_Disabled_Name;

TuiBoolean tuiCursorModeIsValid(TuiCursorMode cursor_mode);
const char* tuiCursorModeToString(TuiCursorMode cursor_mode);
TuiCursorMode tuiStringToCursorMode(const char* str);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard