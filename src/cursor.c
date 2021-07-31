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
#include <TUIC/cursor.h>
#include "image_inline.h"
#include <GLFW/glfw3.h>
#include "glfw_error_check.h"
#include <TUIC/debug.h>
#include <TUIC/system.h>
#include <TUIC/boolean.h>

static int sCursorCount;

TuiCursor tuiCursorCreateImage(TuiImage image, int hotspot_x, int hotspot_y)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return NULL;
	}
	if (image == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return NULL;
	}
	if (image->ChannelCount != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return NULL;
	}

	GLFWimage glfw_image = _TuiImageToGlfwImage(image, __func__);
	if (glfw_image.width == 0)
	{
		return NULL;
	}
	TuiCursor cursor = glfwCreateCursor(&glfw_image, hotspot_x, hotspot_y);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return NULL;
	}
	sCursorCount++;
	return cursor;
}

TuiCursor tuiCursorCreateRawPixels(int pixel_width, int pixel_height, uint8_t* pixels, int hotspot_x, int hotspot_y)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return NULL;
	}
	if (pixels == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return NULL;
	}
	
	GLFWimage glfw_image;
	glfw_image.width = pixel_width;
	glfw_image.height = pixel_height;
	glfw_image.pixels = pixels;
	if (glfw_image.width == 0)
	{
		return NULL;
	}
	TuiCursor cursor = glfwCreateCursor(&glfw_image, hotspot_x, hotspot_y);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return NULL;
	}
	sCursorCount++;
	return cursor;
}

TuiCursor tuiCursorCreateShape(TuiCursorShape shape)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return NULL;
	}
	if (tuiCursorShapeIsValid(shape) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_CURSOR_SHAPE, __func__);
		return NULL;
	}

	TuiCursor cursor = glfwCreateStandardCursor(shape);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return NULL;
	}
	if (cursor == NULL)
	{
		tuiDebugError(TUI_ERROR_UNSUPPORTED_CURSOR_SHAPE, __func__);
		return NULL;
	}
	sCursorCount++;
	return cursor;
}

void tuiCursorDestroy(TuiCursor cursor)
{
	if (cursor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_CURSOR, __func__);
		return;
	}
	glfwDestroyCursor(cursor);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return;
	}
	sCursorCount--;
}

int tuiGetCursorCount()
{
	return sCursorCount;
}
