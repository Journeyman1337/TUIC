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

typedef void (* tuiWindowPosFunction)(TuiInstance,int,int);

typedef void (* tuiWindowSizeFunction)(TuiInstance,int,int);

typedef void (* tuiWindowCloseFunction)(TuiInstance);

typedef void (* tuiWindowRefreshFunction)(TuiInstance);

typedef void (* tuiWindowFocusFunction)(TuiInstance,TuiBoolean);

typedef void (* tuiWindowIconifyFunction)(TuiInstance,TuiBoolean);

typedef void (* tuiWindowMaximizeFunction)(TuiInstance,TuiBoolean);

typedef void (* tuiFramebufferSizeFunction)(TuiInstance,int,int);

typedef void (* tuiWindowContentScaleFunction)(TuiInstance,float,float);

typedef void (* tuiMouseButtonFunction)(TuiInstance,TuiMouseButton,TuiButtonState,TuiKeyMod);

typedef void (* tuiCursorPosFunction)(TuiInstance,double,double);

typedef void (* tuiCursorEnterFunction)(TuiInstance,TuiBoolean);

typedef void (* tuiScrollFunction)(TuiInstance,double,double);

typedef void (* tuiKeyFunction)(TuiInstance,TuiKey,int,TuiButtonState,TuiKeyMod);

typedef void (* tuiCharFunction)(TuiInstance,unsigned int);

typedef void (* tuiDropFunction)(TuiInstance,int,const char*[]);

typedef void (* tuiMonitorFunction)(TuiMonitor,TuiBoolean);

typedef void (* tuiJoysticFunction)(TuiJoystickId, TuiBoolean);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard