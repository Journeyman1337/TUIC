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
/*! \file desktop_callback.h
 */
#ifndef TUIC_DESKTOP_CALLBACK_H //header guard
#define TUIC_DESKTOP_CALLBACK_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>
#include <TUIC/mouse_button.h>
#include <TUIC/button_state.h>
#include <TUIC/keyboard_mod.h>
#include <TUIC/keyboard_key.h>
#include <TUIC/types.h>

typedef void (* tuiWindowMoveFunction)(TuiWindow window, int x_position, int y_position);

typedef void (* tuiWindowCloseFunction)(TuiWindow window);

typedef void (* tuiWindowFocusFunction)(TuiWindow window, TuiBoolean focused);

typedef void (* tuiWindowIconifyFunction)(TuiWindow window,TuiBoolean iconified);

typedef void (* tuiWindowMaximizeFunction)(TuiWindow window, TuiBoolean maximized);

typedef void (* tuiWindowResizeFunction)(TuiWindow window, int pixel_width, int pixel_height);

typedef void (* tuiWindowContentScaleFunction)(TuiWindow window, float scale_wide, float scale_tall);

typedef void (* tuiMouseButtonFunction)(TuiWindow window, TuiMouseButton mouse_button, TuiButtonState button_state, TuiKeyboardMod mod);

typedef void (* tuiCursorMoveFunction)(TuiWindow window, double x_position, double y_position);

typedef void (* tuiCursorEnterFunction)(TuiWindow window, TuiBoolean entered);

typedef void (* tuiMouseScrollFunction)(TuiWindow window, double x_translate, double y_translate);

typedef void (* tuiKeyboardKeyboardKeyFunction)(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState button_state, TuiKeyboardMod mod);

typedef void (* tuiCharFunction)(TuiWindow window, unsigned int codepoint);

typedef void (* tuiFileDropFunction)(TuiWindow window, int path_count, const char* paths[]);

typedef void (*tuiMonitorConnectedFunction)(TuiMonitor monitor, TuiBoolean connected);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard