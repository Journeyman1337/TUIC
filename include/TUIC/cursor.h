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
/*! \file cursor.h
 */
 #ifndef TUIC_CURSOR_H //header guard
#define TUIC_CURSOR_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/cursor_shape.h>

/*! @name @ref TuiCursor functions
 *
 * Functions for manipulating @ref TuiCursor opaque objects.
 *  @{ */
/*!
 * @brief Create a new @ref TuiCursor from a 4 channel @ref TuiImage.
 *
 * @param image The @ref TuiImage to use to create the cursor image.
 * @param hotspot_x The x pixel coordinate of the cursor hotspot.
 * @param hotspot_y The y pixel coordinate of the cursor hotspot.
 *
 * @returns The created @ref TuiCursor. NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED ,@ref TUI_ERROR_NULL_IMAGE, and @ref TUI_ERROR_INVALID_CHANNEL_COUNT. The first error that occurs will cause the function to immediatly return. One or more GLFW errors may also occur.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned @ref TuiCursor must be destroyed before TUIC is terminated, using the function @ref tuiCursorDestroy().
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
TuiCursor tuiCursorCreateImage(TuiImage image, int hotspot_x, int hotspot_y);
/*!
 * @brief Create a new @ref TuiCursor from a 4 channel raw pixel array.
 *
 * @param pixel_width The width of the pixel array in pixels.
 * @param pixel_height The height of the pixel array in pixels.
 * @param raw_pixels A pointer to the start of the pixel array. The pixel array must be ordered from left to right, top to bottom. Each pixel must be in the order RGBA.
 * @param hotspot_x The x pixel coordinate of the cursor hotspot.
 * @param hotspot_y The y pixel coordinate of the cursor hotspot.
 *
 * @returns The created @ref TuiCursor. NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED,  @ref TUI_ERROR_NULL_PIXELS, and @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS. The first error that occurs will cause the function to immediatly return. One or more GLFW errors may also occur.  Also, an inccorectly sized or allocated pixel array may cause undefined behaviour or a fatal crash without an error.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned @ref TuiCursor must be destroyed before TUIC is terminated, using the function @ref tuiCursorDestroy().
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
TuiCursor tuiCursorCreateRawPixels(int pixel_width, int pixel_height, uint8_t* pixels, int hotspot_x, int hotspot_y);
/*!
 *@brief Create a new @ref TuiCursor from a @ref TUiCursorShape.
 *
 * @param shape The @ref TuiCursorShape to use to create the cursor image.
 *
 * @returns The created @ref TuiCursor. NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, @ref TUI_ERROR_INVALID_CURSOR_SHAPE, and @ref TUI_ERROR_UNSUPPORTED_CURSOR_SHAPE.The first error that occurs will cause the function to immediatly return. One or more GLFW errors may also occur.
 *
 *@requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned @ref TuiCursor must be destroyed before TUIC is terminated, using the function @ref tuiCursorDestroy().
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
TuiCursor tuiCursorCreateShape(TuiCursorShape shape);
/*!
 * @brief Free a @ref TuiCursor and correctly dispose of of its internally managed resources.
 *
 * @param atlas The @ref TuiCursor to destroy.
 *
 * @errors This function can possible have the error @ref TUI_ERROR_NULL_CURSOR and immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
void tuiCursorDestroy(TuiCursor cursor);
/*!
 * @brief Get the amount of @ref TuiCursor that currently exist.
 *
 * @returns The amount of cursors that currently exist.
 *
 * @errors This function does not have errors.
 *
 * @requirements This function can be called at any time.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiGetCursorCount();
/*! @} */

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard