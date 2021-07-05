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
/*! \file window_attribute.h
 */
#ifndef TUIC_WINDOW_ATTRIBUTE_H //header guard
#define TUIC_WINDOW_ATTRIBUTE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>

typedef enum TuiWindowAttribute
{
	TUI_WINDOW_FOCUSED                 = 0x00020001,
	TUI_WINDOW_ICONIFIED               = 0x00020002,
	TUI_WINDOW_RESIZABLE               = 0x00020003,
	TUI_WINDOW_VISIBLE                 = 0x00020004,
	TUI_WINDOW_DECORATED               = 0x00020005,
	TUI_WINDOW_AUTO_ICONIFY            = 0x00020006,
	TUI_WINDOW_FLOATING                = 0x00020007,
	TUI_WINDOW_MAXIMIZED               = 0x00020008,
	TUI_WINDOW_CENTER_CURSOR           = 0x00020009,
	TUI_WINDOW_TRANSPARENT_FRAMEBUFFER = 0x0002000A,
	TUI_WINDOW_HOVERED                 = 0x0002000B,
	TUI_WINDOW_FOCUS_ON_SHOW           = 0x0002000C,
	TUI_WINDOW_MOUSE_PASSTHROUGH       = 0x0002000D,
	TUI_WINDOW_INVALID                 = 0,
	TUI_WINDOW_FIRST                   = TUI_WINDOW_FOCUSED,
	TUI_WINDOW_LAST                    = TUI_WINDOW_MOUSE_PASSTHROUGH
} TuiWindowAttribute;

extern const char* kTui_Window_Focused_Name;
extern const char* kTui_Window_Iconified_Name;
extern const char* kTui_Window_Resizable_Name;
extern const char* kTui_Window_Visible_Name;
extern const char* kTui_Window_Decorated_Name;
extern const char* kTui_Window_Auto_Iconify_Name;
extern const char* kTui_Window_Floating_Name;
extern const char* kTui_Window_Maximized_Name;
extern const char* kTui_Window_Center_Cursor_Name;
extern const char* kTui_Window_Transparent_Framebuffer_Name;
extern const char* kTui_Window_Hovered_Name;
extern const char* kTui_Window_Focus_On_Show_Name;
extern const char* kTui_Window_Mouse_Passthrough_Name;

TuiBoolean tuiWindowAttributeIsValid(TuiWindowAttribute window_attribute);
const char* tuiWindowAttributeToString(TuiWindowAttribute window_attribute);
TuiWindowAttribute tuiStringToWindowAttribute(const char* str);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard