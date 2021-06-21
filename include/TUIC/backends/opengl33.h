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
/*! \file opengl33.h
 * This file includes all function prototypes for the opengl33 backend. To use this backend, it needs to be implemented in a c or cpp file somewhere  in your project using opengl33_implementation.h like so:
 * 
 *     #include <gl/glew.h> //You need to include opengl bindings before implementing the opengl33 backend. You can use any Opengl loading library that you prefeer.
 *     #define TUIC_OPENGL33_LOAD_GLEW //specify that glew is the library being used.
 *     //#define TUIC_OPENGL33_LOAD_GLAD //specify this instead of previous macro to use GLAD instead of GLEW.
 *     //#define TUIC_OPENGL33_LOAD_NONE //specify this to use no loading library. This will cause tuiOpengl33InstanceCreateNewContext to return NULL.
 *     #define TUIC_OPENGL33_IMPLEMENTATION // Including this before the header tells the compiler to implement the opengl33 backend.
 *     //#define GLD_ACTIVE 0 //disable glDebug debugging library (increases performance in debug configuration builds for opengl33 backend)
 *     #include <TUIC/backends/opengl33_implementation.h> //This header is for the implementation. Use tuic/backends/opengl33.h for includes everywhere else.
 */
#ifndef TUIC_OPENGL33_H //header guard
#define TUIC_OPENGL33_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include "tuic/types.h"
/*!
 * @brief Create a new @ref TuiInstance using the Opengl33 backend.
 * 
 * For this to work, there needs to be a graphics context made current that uses bindings for Opengl 3.3.
 *
 * @param pixel_width The width of the graphics context screen.
 * @param pixel_height The height of the graphics context screen.
 * 
 * @returns The @ref TuiInstance. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_INVALID_INSTANCE_DIMENSIONS if pixel_width or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiInstance tuiOpengl33InstanceCreateExistingContext(int pixel_width, int pixel_height);
/*!
 * @brief Create a new @ref TuiInstance using the Opengl33 backend in a new graphics context.
 *
 * @param pixel_width The width of the graphics context screen.
 * @param pixel_height The height of the graphics context screen.
 * @param window_proc_address A function pointer to the window create procedure.
 *
 * @returns The @ref TuiInstance. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_INVALID_INSTANCE_DIMENSIONS if pixel_width or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiInstance tuiOpengl33InstanceCreate(int pixel_width, int pixel_height, void* window_proc_address);
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard