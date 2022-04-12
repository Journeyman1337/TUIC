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
/*! \file mouse_button.h
 */
#ifndef TUIC_MOUSE_BUTTON_H //header guard
#define TUIC_MOUSE_BUTTON_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


typedef enum TuiMouseButton
{
	TUI_MOUSE_BUTTON_INVALID  = 0,
	TUI_MOUSE_BUTTON_1,
	TUI_MOUSE_BUTTON_2,
	TUI_MOUSE_BUTTON_3,
	TUI_MOUSE_BUTTON_4,
	TUI_MOUSE_BUTTON_5,
	TUI_MOUSE_BUTTON_6,
	TUI_MOUSE_BUTTON_7,
	TUI_MOUSE_BUTTON_8,
	TUI_MOUSE_BUTTON_FIRST    = TUI_MOUSE_BUTTON_1,
	TUI_MOUSE_BUTTON_LAST     = TUI_MOUSE_BUTTON_8,
	TUI_MOUSE_BUTTON_LEFT     = TUI_MOUSE_BUTTON_1,
	TUI_MOUSE_BUTTON_RIGHT    = TUI_MOUSE_BUTTON_2,
	TUI_MOUSE_BUTTON_MIDDLE   = TUI_MOUSE_BUTTON_3,
	TUI_MOUSE_BUTTON_X1       = TUI_MOUSE_BUTTON_4,
	TUI_MOUSE_BUTTON_X2       = TUI_MOUSE_BUTTON_5,
	TUI_MOUSE_BUTTON_X3		  = TUI_MOUSE_BUTTON_6,
	TUI_MOUSE_BUTTON_X4		  = TUI_MOUSE_BUTTON_7,
	TUI_MOUSE_BUTTON_X5		  = TUI_MOUSE_BUTTON_8
} TuiMouseButton;


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard