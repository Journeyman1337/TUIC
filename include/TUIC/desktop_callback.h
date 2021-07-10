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
#include <TUIC/key_mod.h>
#include <TUIC/key.h>
#include <TUIC/joystick_id.h>
#include <TUIC/types.h>

typedef void (* tuiWindowMoveFunction)(TuiInstance instance, int xpos, int ypos);

typedef void (* tuiWindowCloseFunction)(TuiInstance instance);

typedef void (* tuiWindowRefreshFunction)(TuiInstance instance);

typedef void (* tuiWindowFocusFunction)(TuiInstance instance, TuiBoolean focused);

typedef void (* tuiWindowIconifyFunction)(TuiInstance instance,TuiBoolean iconified);

typedef void (* tuiWindowMaximizeFunction)(TuiInstance instance, TuiBoolean maximized);

typedef void (* tuiWindowResizeFunction)(TuiInstance instance, int pixel_width, int pixel_height);

typedef void (* tuiWindowContentScaleFunction)(TuiInstance instance, float xscale, float yscale);

typedef void (* tuiMouseButtonFunction)(TuiInstance instance, TuiMouseButton mouse_button, TuiButtonState button_state, TuiKeyMod key_mod);

typedef void (* tuiCursorMoveFunction)(TuiInstance instance, double xpos, double ypos);

typedef void (* tuiCursorEnterFunction)(TuiInstance instance, TuiBoolean entered);

typedef void (* tuiMouseScrollFunction)(TuiInstance instance, double xscroll, double yscroll);

typedef void (* tuiKeyboardKeyFunction)(TuiInstance instance, TuiKey key, int scancode, TuiButtonState button_state, TuiKeyMod key_mod);

typedef void (* tuiCharFunction)(TuiInstance instance, unsigned int codepoint);

typedef void (* tuiFileDropFunction)(TuiInstance instance, int path_count, const char* paths[]);

typedef void (* tuiMonitorFunction)(TuiMonitor monitor, TuiBoolean connected);

typedef void (* tuiJoysticFunction)(TuiJoystickId joystic_id, TuiBoolean connected);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard