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
#ifndef TUIC_GLFW_ERROR_CHECK_H //header guard
#define TUIC_GLFW_ERROR_CHECK_H
#include <TUIC/debug.h>
#include <GLFW/glfw3.h>
#include <TUIC/boolean.h>

static inline void _GlfwClearErrors()
{
	while (glfwGetError(NULL) != GLFW_NO_ERROR);
}

static inline TuiErrorCode _GlfwErrorCheck()
{
	int error = glfwGetError(NULL);
	if (error != GLFW_NO_ERROR)
	{
		_GlfwClearErrors();
		switch (error)
		{
		case GLFW_FORMAT_UNAVAILABLE:
			return TUI_ERROR_GLFW_FORMAT_UNAVAILABLE;
		case GLFW_VERSION_UNAVAILABLE:
			return TUI_ERROR_GLFW_INVALID_VERSION;
		case GLFW_NO_WINDOW_CONTEXT:
			return TUI_ERROR_GLFW_NO_GRAPHICS_CONTEXT;
		case GLFW_NOT_INITIALIZED:
			return TUI_ERROR_GLFW_NOT_INITIALIZED;
		case GLFW_OUT_OF_MEMORY:
			return TUI_ERROR_GLFW_OUT_OF_MEMORY;
		case GLFW_PLATFORM_ERROR:
			return TUI_ERROR_GLFW_PLATFORM;
		case GLFW_INVALID_VALUE:
			return TUI_ERROR_GLFW_VALUE;
		case GLFW_INVALID_ENUM:
			return TUI_ERROR_GLFW_ENUM;
		default:
			return TUI_ERROR_UNKNOWN;
		}
	}
	return TUI_ERROR_NONE;
}

#endif //header guard