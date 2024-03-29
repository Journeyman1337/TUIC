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
/*! \file button_state.h
 */
#ifndef TUIC_BUTTON_STATE_H //header guard
#define TUIC_BUTTON_STATE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>

/*!
 * @brief The position of a button or key.
 */
typedef enum TuiButtonState_e
{
	/*!
	 * \brief The button state is invalid.
	 *
	 * This button state is returned when an error occurs, and is also used to specify that no button state is
	 * defined.
	 */
	TUI_BUTTON_INVALID = 3,
	/*!
	 * \brief The button is released.
	 */
	TUI_BUTTON_RELEASE = 0,
	/*!
	 * \brief The button is pressed.
	 */
	TUI_BUTTON_PRESS = 1,
	/*!
	 * \brief The button is pressed and is repeating.
	 */
	TUI_BUTTON_REPEAT = 2,
	/*!
	 * \brief The first valid button state.
	 */
	TUI_BUTTON_FIRST = TUI_BUTTON_RELEASE,
	/*!
	 * \brief The last valid button state.
	 */
	TUI_BUTTON_LAST = TUI_BUTTON_REPEAT
}TuiButtonState;

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard