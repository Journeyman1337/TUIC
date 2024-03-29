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
/*! \file cursor_shape.h
 */
 #ifndef TUIC_CURSOR_SHAPE_H //header guard
#define TUIC_CURSOR_SHAPE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>

typedef enum TuiCursorShape_e
{
	TUI_CURSOR_SHAPE_INVALID		  = 0,
	TUI_CURSOR_SHAPE_ARROW,
	TUI_CURSOR_SHAPE_IBEAM ,
	TUI_CURSOR_SHAPE_CROSSHAIR,
	TUI_CURSOR_SHAPE_POINTING_HAND,
	TUI_CURSOR_SHAPE_RESIZE_EW,
	TUI_CURSOR_SHAPE_RESIZE_NS,
	TUI_CURSOR_SHAPE_RESIZE_NWSE,
	TUI_CURSOR_SHAPE_RESIZE_NESW,
	TUI_CURSOR_SHAPE_RESIZE_ALL,
	TUI_CURSOR_SHAPE_NOT_ALLOWED,
	TUI_CURSOR_SHAPE_HRESIZE        = TUI_CURSOR_SHAPE_RESIZE_EW,
	TUI_CURSOR_SHAPE_VRESIZE        = TUI_CURSOR_SHAPE_RESIZE_NS,
	TUI_CURSOR_SHAPE_FIRST		    = TUI_CURSOR_SHAPE_ARROW,
	TUI_CURSOR_SHAPE_LAST			= TUI_CURSOR_SHAPE_NOT_ALLOWED
}TuiCursorShape;

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard