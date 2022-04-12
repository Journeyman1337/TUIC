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

#include <stddef.h>
#include <assert.h>

static size_t sCursorCount;

TuiResult tuiCursorCreateFromImage(TuiCursor* cursor, TuiImage image, int hotspot_x, int hotspot_y)
{
	assert(cursor != NULL);
	assert(image != NULL);
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}
	if (image->ChannelCount != 4)
	{
		return TUI_RESULT_ERROR_INVALID_VALUE;
	}
	GLFWimage glfw_image = _TuiImageToGlfwImage(image, __func__);
	if (glfw_image.width == 0)
	{
		return TUI_RESULTERROR_INVALID_VALUE;
	}
	TuiCursor cursor = glfwCreateCursor(&glfw_image, hotspot_x, hotspot_y);
	TuiResult glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_RESULT_OK)
	{
		return glfw_error;
	}
	sCursorCount++;
	return cursor;
}

void tuiCursorDestroy(TuiCursor cursor)
{
	assert(cursor != NULL);
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	glfwDestroyCursor(cursor);
	_glfwClearErrors();
	sCursorCount--;
}

size_t tuiGetCursorCount()
{
	return sCursorCount;
}
