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
/*! \file cursor_mode.h
 */
#ifndef TUIC_CURSOR_MODE_H //header guard
#define TUIC_CURSOR_MODE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*!
 * @brief The state of the mouse cursor.
 */
typedef enum TuiCursorMode
{ 
	/*!
	 * \brief The cursor mode is invalid.
	 *
	 * This cursor mode is returned when an error occurs, and is also used to specify that no cursor mode is
	 * defined.
	 */
	TUI_CURSOR_MODE_INVALID = 0,
	/*!
	 * \brief The cursor is visilble and behaves normally.
	 */
	TUI_CURSOR_MODE_NORMAL		= 0x00034001,
	/*!
	 * \brief The cursor is hidden while over the window and behaves normally outside the window.
	 */
	TUI_CURSOR_MODE_HIDDEN		= 0x00034002,
	/*!
	 * \brief The cursor is hidden and unable to be removed from the window.
	 */
	TUI_CURSOR_MODE_DISABLED	= 0x00034003,
	/*!
	 * \brief The first valid cursor mode.
	 */
	TUI_CURSOR_MODE_FIRST		= TUI_CURSOR_MODE_NORMAL,
	/*!
	 * \brief The last valid cursor mode.
	 */
	TUI_CURSOR_MODE_LAST		= TUI_CURSOR_MODE_DISABLED
} TuiCursorMode;


/*! @name Cursor Mode Names
 * 
 *  These are const string names of @ref TuiCursorMode enum values.
 *  @{ */
/*!
 * @brief String name of @ref TUI_CURSOR_MODE_NORMAL.
 */
extern const char* kTui_Cursor_Mode_Normal_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_MODE_HIDDEN.
 */
extern const char* kTui_Cursor_Mode_Hidden_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_MODE_DISABLED.
 */
extern const char* kTui_Cursor_Mode_Disabled_Name;
/*! @} */


/*! @name Cursor Mode Functions
 *
 * Functions for dealing with @ref TuiCursorMode enum values.
 *  @{ */
 /*!
  * @brief Determine if a @ref TuiCursorMode enum is valid.
  *
  * @param cursor_mode The @ref TuiCursorMode to check.
  *
  * @returns The @ref TuiBoolean result. If cursor_mode is a valid @ref TuiCursorMode, it
  * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
  *
  * @errors This function can have no errors.
  *
  * @requirements This function can be called freely, even if TUIC is not currently initialized.
  *
  * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
  */
TuiBoolean tuiCursorModeIsValid(TuiCursorMode cursor_mode);
/*!
 * @brief Retrieve the string name associated with a @ref TuiCursorMode enum.
 *
 * @param cursor_mode The @ref TuiCursorMode to get the name of.
 *
 * @returns The string name. @ref TUI_NULL is returned if cursor_mode is an invalid @ref TuiCursorMode.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiCursorModeToString(TuiCursorMode cursor_mode);
/*!
 * @brief Determine the @ref TuiCursorMode enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The TuiCursorMode. @ref TUI_CURSOR_MODE_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCursorMode tuiStringToCursorMode(const char* str);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard