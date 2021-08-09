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
/*! \file mouse_button.h
 */
#ifndef TUIC_MOUSE_BUTTON_H //header guard
#define TUIC_MOUSE_BUTTON_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*! @name Mouse Buttons
 *  @{ */
/*!
 * @brief Mouse buttons.
 */
typedef enum TuiMouseButton
{
	/*!
	 * \brief The filter mode is invalid.
	 *
	 * This filter mode is returned when an error occurs, and is also used to specify that no mouse button is
	 * defined.
	 */
	TUI_MOUSE_BUTTON_INVALID  = 8,
	/*!
	 * @brief Mouse button 1 (left mouse button).
	 */
	TUI_MOUSE_BUTTON_1        = 0,
	/*!
	 * @brief Mouse button 2 (right mouse button).
	 */
	TUI_MOUSE_BUTTON_2        = 1,
	/*!
	 * @brief Mouse button 3 (middle mouse button).
	 */
	TUI_MOUSE_BUTTON_3        = 2,
	/*!
	 * @brief Mouse button 4 (extra button 1).
	 */
	TUI_MOUSE_BUTTON_4        = 3,
	/*!
	 * @brief Mouse button 5 (extra button 2).
	 */
	TUI_MOUSE_BUTTON_5        = 4,
	/*!
	 * @brief Mouse button 6 (extra button 3).
	 */
	TUI_MOUSE_BUTTON_6        = 5,
	/*!
	 * @brief Mouse button 7 (extra button 4).
	 */
	TUI_MOUSE_BUTTON_7        = 6,
	/*!
	 * @brief Mouse button 8 (extra button 5).
	 */
	TUI_MOUSE_BUTTON_8        = 7,
	/*!
	 * @brief The first valid mouse button.
	 */
	TUI_MOUSE_BUTTON_FIRST    = TUI_MOUSE_BUTTON_1,
	/*!
	 * @brief The last valid mouse button.
	 */
	TUI_MOUSE_BUTTON_LAST     = TUI_MOUSE_BUTTON_8,
	/*!
	 * @brief Alternanate value for mouse button 1 (left mouse button).
	 */
	TUI_MOUSE_BUTTON_LEFT     = TUI_MOUSE_BUTTON_1,
	/*!
	 * @brief Alternate value for mouse button 2 (right mouse button).
	 */
	TUI_MOUSE_BUTTON_RIGHT    = TUI_MOUSE_BUTTON_2,
	/*!
	 * @brief Alternate value for mouse button 3 (middle mouse button).
	 */
	TUI_MOUSE_BUTTON_MIDDLE   = TUI_MOUSE_BUTTON_3,
	/*!
	 * @brief Alternate value for mouse button 4 (extra button 1).
	 */
	TUI_MOUSE_BUTTON_X1       = TUI_MOUSE_BUTTON_4,
	/*!
	 * @brief Alternate value for mouse button 5 (extra button 2).
	 */
	TUI_MOUSE_BUTTON_X2       = TUI_MOUSE_BUTTON_5,
	/*!
	 * @brief Alternate value for mouse button 6 (extra button 3).
	 */
	TUI_MOUSE_BUTTON_X3		  = TUI_MOUSE_BUTTON_6,
	/*!
	 * @brief Alternate value for mouse button 7 (extra button 4).
	 */
	TUI_MOUSE_BUTTON_X4		  = TUI_MOUSE_BUTTON_7,
	/*!
	 * @brief Alternate value for mouse button 8 (extra button 5).
	 */
	TUI_MOUSE_BUTTON_X5		  = TUI_MOUSE_BUTTON_8
} TuiMouseButton;
/*! @} */


/*! @name Mouse Button Names
 *
 *  These are const string names of @ref TuiMouseButton enum values.
 *  @{ */
/*!
 * @brief String name of @ref TUI_MOUSE_BUTTON_1 and @ref TUI_MOUSE_BUTTON_LEFT.
 */
extern const char* kTui_Mouse_Button_1_Name;
/*!
 * @brief String name of @ref TUI_MOUSE_BUTTON_2 and @ref TUI_MOUSE_BUTTON_RIGHT.
 */
extern const char* kTui_Mouse_Button_2_Name;
/*!
 * @brief String name of @ref TUI_MOUSE_BUTTON_3 and @ref TUI_MOUSE_BUTTON_MIDDLE.
 */
extern const char* kTui_Mouse_Button_3_Name;
/*!
 * @brief String name of @ref TUI_MOUSE_BUTTON_4 and @ref TUI_MOUSE_BUTTON_X1.
 */
extern const char* kTui_Mouse_Button_4_Name;
/*!
 * @brief String name of @ref TUI_MOUSE_BUTTON_5 and @ref TUI_MOUSE_BUTTON_X2.
 */
extern const char* kTui_Mouse_Button_5_Name;
/*!
 * @brief String name of @ref TUI_MOUSE_BUTTON_6 and @ref TUI_MOUSE_BUTTON_X3.
 */
extern const char* kTui_Mouse_Button_6_Name;
/*!
 * @brief String name of @ref TUI_MOUSE_BUTTON_7 and @ref TUI_MOUSE_BUTTON_X4.
 */
extern const char* kTui_Mouse_Button_7_Name;
/*!
 * @brief String name of @ref TUI_MOUSE_BUTTON_8 and @ref TUI_MOUSE_BUTTON_X5.
 */
extern const char* kTui_Mouse_Button_8_Name;
/* @) */


/*! @name Mouse Button Functions
 *
 * Functions for dealing with @ref TuiMouseButton enum values.
 *  @{ */
/*!
 * @brief Determine if a @ref TuiMouseButton enum is valid.
 *
 * @param mouse_button The @ref TuiMouseButton to check.
 *
 * @returns The @ref TuiBoolean result. If mouse_button is a valid @ref TuiMouseButton, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiMouseButtonIsValid(TuiMouseButton mouse_button);
/*!
 * @brief Retrieve the string name associated with a @ref TuiMouseButton enum.
 *
 * @param mouse_button The @ref TuiMouseButton to get the name of.
 *
 * @returns The string name. @ref TUI_NULL is returned if mouse_button is an invalid @ref TuiMouseButton.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiMouseButtonToString(TuiMouseButton mouse_button);
/*!
 * @brief Determine the @ref TuiMouseButton enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The @ref TuiMouseButton. @ref TUI_MOUSE_BUTTON_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiMouseButton tuiStringToMouseButton(const char* str);
/* @) */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard