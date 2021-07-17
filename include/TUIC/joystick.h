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
/*! \file joystick.h
 */
#ifndef TUIC_JOYSTICK_H //header guard
#define TUIC_JOYSTICK_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>
#include <TUIC/joystick_id.h>
#include <TUIC/joystick_hat_state.h>
#include <TUIC/desktop_callback.h>

TuiBoolean tuiJoystickIsPresent(TuiJoystickId joystick_id);
const float* tuiJoystickGetAxes(TuiJoystickId joystick_id, int* count);
const unsigned char* tuiJoystickGetButtons(TuiJoystickId joystick_id, int* count);
const unsigned char* tuiJoystickGetHats(TuiJoystickId joystick_id, int* count);
const char* tuiJoystickGetName(TuiJoystickId joystick_id);
const char* tuiJoystickGetGUID(TuiJoystickId joystick_id);
void tuiJoystickSetUserPointer(TuiJoystickId joystick_id, void* pointer);
void* tuiJoystickGetUserPointer(TuiJoystickId joystick_id);
TuiBoolean tuiJoystickIsGamepad(TuiJoystickId joystick_id);
TuiBoolean tuiJoystickUpdateMappings(const char* string);
const char* tuiJoystickGetGamepadName(TuiJoystickId joystick_id);
tuiJoysticFunction tuiSetJoystickCallback(tuiJoysticFunction callback);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard