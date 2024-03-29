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
/*! \file system.h
 */
#ifndef TUIC_SYSTEM_H //header guard
#define TUIC_SYSTEM_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*! @name TUIC System Functions
 *
 * Functions for controling the TUIC library's state machine.
 *  @{ */
/*!
 * @brief Initialize the TUIC library.
 * 
 * @returns The @ref TuiBoolean result. If the library initialized successfully, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_ALREADY_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly return @ref TUI_FALSE.
 * 
 * @requirements This function must only be called when TUIC is not initialized.
 * 
 * @thread_safety The thread on which this function is called on is the only thread that many other TUIC functions must be called on.
 */
TuiBoolean tuiInit();
/*!
 * @brief Get if the TUIC system is currently initialized.
 * 
 * @returns The @ref TuiBoolean result. If the library is currently initialized, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 * 
 * @errors This function can have no errors.
 * 
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiIsActive();
/*!
 * @brief Terminate the TUIC library.
 *
 * @returns The @ref TuiBoolean result. If the library initialized successfully, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED,  @ref TUI_ERROR_DANGLING_WINDOW, @ref TUI_ERROR_DANGLING_CURSOR, @ref TUI_ERROR_DANGLING_ATLAS, @ref TUI_ERROR_DANGLING_PANEL, @ref TUI_ERROR_DANGLING_PALETTE and @ref TUI_ERROR_DANGLING_TEXTURE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must only be called when TUIC is initialized. All @ref TuiWindow, @ref TuiCursor, @ref TuiAtlas, @ref TuiPanel, @ref TuiPalette, and @ref TuiTexture must be destroyed before this function is called.
 *
 * @thread_safety The thread on which this function is called on is the only thread that many other TUIC functions must be called on.
 */
void tuiTerminate();
/*!
 * @brief Get if raw mouse motion is suported on the current platform.
 *
 * @returns The @ref TuiBoolean result. If raw mouse motion is supported, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function must only be called when TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
TuiBoolean tuiRawMouseMotionSupported();
/*!
 * @brief Get if window icons are suported on the current platform.
 *
 * @returns The @ref TuiBoolean result. If window icon are supported, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function must only be called when TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
TuiBoolean tuiWindowIconsSupported();
/*!
 * @brief Get the clipboard text.
 *
 * @returns The clipboard string.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned clipboard string is overwritten the next time this function is calledd.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
const char* tuiGetClipboardString();
/*!
 * @brief Set the clipboard text.
 * @param string The string to set.
 *
 * @returns The clipboard string.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, @ref TUI_ERROR_NULL_STRING, and and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned clipboard string is overwritten the next time this function is called.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiSetClipboardString(const char* string);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard