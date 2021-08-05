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
/*! \file time.h
 */
#ifndef TUIC_TIME_H //header guard
#define TUIC_TIME_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <stdint.h>
 

/*! @name @ref TUIC time functions
 *
 * Functions for manipulating the TUIC internal timimg system.
 *  @{ */
/*
 * @brief Get the amount of time that has passed since TUIC was initialized (in seconds).
 *
 * @returns The amount of time that has passed in seconds.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly occur.
 *
 * @requirements This function must only be called when TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
double tuiGetTime();
/*
 * @brief Set the global TUIC time to a custom value.
 *
 * @param The value to set the global time.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, @ref TUI_ERROR_INVALID_TIME, and GLFW errors. The first error that occurs will cause the function to immediatly occur.
 *
 * @requirements This function must only be called when TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiSetTime(double time);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard