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
typedef enum TuiButtonState
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


/*! @name Button State Names
 *  These are const string names of @ref TuiButtonState enum values.
 *  @{ */
/*!
 * @brief String name of @ref TUI_BUTTON_RELEASE.
 */
extern const char* kTui_Button_Release_Name;
/*!
 * @brief String name of @ref TUI_BUTTON_PRESS.
 */
extern const char* kTui_Button_Press_Name;
/*!
 * @brief String name of @ref TUI_BUTTON_REPEAT.
 */
extern const char* kTui_Button_Repeat_Name;
/*! @} */


/*! @name Button State Functions
 *
 * Functions for dealing with @ref TuiButtonState enum values.
 *  @{ */
/*!
 * @brief Determine if a @ref TuiButtonState enum is valid.
 *
 * @param button_state The @ref TuiButtonState to check.
 *
 * @returns The @ref TuiBoolean result. If button_state is a valid @ref TuiButtonState, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiButtonStateIsValid(TuiButtonState button_state);
/*!
 * @brief Retrieve the string name associated with a @ref TuiButtonState enum.
 *
 * @param button_state The @ref TuiButtonState to get the name of.
 *
 * @returns The string name. @ref TUI_NULL is returned if button_state is an invalid @ref TuiButtonState.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiButtonStateToString(TuiButtonState button_state);
/*!
 * @brief Determine the @ref TuiButtonState enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The TuiBlendMode. @ref TUI_BUTTON_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiButtonState tuiStringToButtonState(const char* str);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard