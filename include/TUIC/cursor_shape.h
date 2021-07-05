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

typedef enum TuiCursorShape
{
	TUI_CURSOR_INVALID		  = 0,
	TUI_CURSOR_ARROW          = 0x00036001,
	TUI_CURSOR_IBEAM          = 0x00036002,
	TUI_CURSOR_CROSSHAIR      = 0x00036003,
	TUI_CURSOR_POINTING_HAND  = 0x00036004,
	TUI_CURSOR_RESIZE_EW      = 0x00036005,
	TUI_CURSOR_RESIZE_NS      = 0x00036006,
	TUI_CURSOR_RESIZE_NWSE    = 0x00036007,
	TUI_CURSOR_RESIZE_NESW    = 0x00036008,
	TUI_CURSOR_RESIZE_ALL     = 0x00036009,
	TUI_CURSOR_NOT_ALLOWED    = 0x0003600A,
	TUI_CURSOR_HRESIZE        = TUI_CURSOR_RESIZE_EW,
	TUI_CURSOR_VRESIZE        = TUI_CURSOR_RESIZE_NS,
	TUI_CURSOR_HAND           = TUI_CURSOR_POINTING_HAND,
	TUI_CURSOR_FIRST		  = TUI_CURSOR_ARROW,
	TUI_CURSOR_LAST			  = TUI_CURSOR_NOT_ALLOWED
}TuiCursorShape;

extern const char* kTui_Cursor_Arrow_Name;
extern const char* kTui_Cursor_Ibeam_Name;
extern const char* kTui_Cursor_Crosshair_Name;
extern const char* kTui_Cursor_Pointing_Hand_Name;
extern const char* kTui_Cursor_Resize_EW_Name;
extern const char* kTui_Cursor_Resize_NS_Name;
extern const char* kTui_Cursor_Resize_NWSE_Name;
extern const char* kTui_Cursor_Resize_NESW_Name;
extern const char* kTui_Cursor_Resize_All_Name;
extern const char* kTui_Cursor_Not_Allowed_Name;

TuiBoolean tuiCursorShapeIsValid(TuiCursorShape cursor_shape);
const char* tuiCursorShapeToString(TuiCursorShape cursor_shape);
TuiCursorShape tuiStringToCursorShape(const char* str);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard