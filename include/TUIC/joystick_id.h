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
/*! \file joystick_id.h
 */
#ifndef TUIC_JOYSTICK_ID_H //header guard
#define TUIC_JOYSTICK_ID_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

enum TuiJoystickId
{
	TUI_JOYSTICK_1            = 0,
	TUI_JOYSTICK_2            = 1,
	TUI_JOYSTICK_3            = 2,
	TUI_JOYSTICK_4            = 3,
	TUI_JOYSTICK_5            = 4,
	TUI_JOYSTICK_6            = 5,
	TUI_JOYSTICK_7            = 6,
	TUI_JOYSTICK_8            = 7,
	TUI_JOYSTICK_9            = 8,
	TUI_JOYSTICK_10           = 9,
	TUI_JOYSTICK_11           = 10,
	TUI_JOYSTICK_12           = 11,
	TUI_JOYSTICK_13           = 12,
	TUI_JOYSTICK_14           = 13,
	TUI_JOYSTICK_15           = 14,
	TUI_JOYSTICK_16           = 15,
	TUI_JOYSTICK_LAST         = TUI_JOYSTICK_16
};

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard