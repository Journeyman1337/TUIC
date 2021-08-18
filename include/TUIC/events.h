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
/*! \file events.h
 */
#ifndef TUIC_EVENTS_H //header guard
#define TUIC_EVENTS_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif


/*! @name Input Event Functions
 *
 * Functions for handling input events.
 *  @{ */
/*! 
 * @brief Poll all callbacks, input, and windowing events.
 * 
 * @errors This function can have the error @ref TUI_ERROR_NOT_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly return.
 * 
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiPollEvents();
/*!
* @brief Sleeps the current thread and waits until an input event occurs to Poll.
 *
 * @errors This function can have the error @ref TUI_ERROR_NOT_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiWaitEvents();
/*!
 * @brief Sleeps the current thread and waits until an input event occurs to Poll.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, @ref TUI_ERROR_INVALID_EVENT_TIMEOUT and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiWaitEventsTimeout(double timeout);
/*!
 * @brief Post an empty event, causing tuiWaitEvents and tuiWaitEventsTimeout to immediatly return.
 *
 * @errors This function can have the error @ref TUI_ERROR_NOT_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiPostEmptyEvent();
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard