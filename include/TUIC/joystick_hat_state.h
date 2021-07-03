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
/*! \file joystick_hat_state.h
 */
#ifndef TUIC_JOYSTICK_HAT_STATE_H //header guard
#define TUIC_JOYSTICK_HAT_STATE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

enum TuiJoystickHatState
{
	TUI_HAT_CENTERED   = 0,
	TUI_HAT_UP         = 1,
	TUI_HAT_RIGHT      = 2,
	TUI_HAT_DOWN       = 4,
	TUI_HAT_LEFT       = 8,
	TUI_HAT_RIGHT_UP   = (TUI_HAT_RIGHT | TUI_HAT_UP),
	TUI_HAT_RIGHT_DOWN = (TUI_HAT_RIGHT | TUI_HAT_DOWN),
	TUI_HAT_LEFT_UP    = (TUI_HAT_LEFT  | TUI_HAT_UP),
	TUI_HAT_LEFT_DOWN  = (TUI_HAT_LEFT  | TUI_HAT_DOWN)
};

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard