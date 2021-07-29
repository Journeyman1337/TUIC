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
/*! \file debug.h
 */
#ifndef TUIC_DEBUG_H //header guard
#define TUIC_DEBUG_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/error_code.h>


/*! @name Debug Output
 *
 * These functions and callbacks are used for controling how TUIC handles debug output.
 *
 *  @{ */ 
/*!
 * @brief Callback type used to set the debug callback handler.
 * 
 * @params error_code The @ref TuiErrorCode.
 * @param msg For errors with @ref TuiErrorCode @ref TUI_ERROR_BACKEND_SPECIFIC, this is a string description of the error. For all other error codes, this is the name of the function where the error occured.
 */
typedef void(*tuiDebugErrorCallback) (TuiErrorCode error_code, const char* msg);
/*!
 * @brief Set the callback function to handle debug output from TUI. After passing a callback function, TUIC will call that function and pass in debug output. Setting the callback to NULL will disable the callback.
 *
 * @param callack A function pointer to the callback.
 * 
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 */
void tuiSetDebugErrorCallback(tuiDebugErrorCallback callback);
/*!
 * @brief Send a debug message to the debug callback function. This function sends a message to the currently set debug callback function. If none was set or it was set to NULL, nothing will happen.
 *
 * @param error_code The @ref TuiErrorCode.
 * @param msg For errors with @ref TuiErrorCode @ref TUI_ERROR_BACKEND_SPECIFIC, this is a string description of the error. For all other error codes, this is the name of the function where the error occured.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 */
void tuiDebugError(TuiErrorCode error_code, const char* msg);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard