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

static inline int _TuiErrorCodeToGlfwError(TuiErrorCode error_code)
{
	switch (error_code)
	{
	case TUI_ERROR_GLFW_API_UNAVAILABLE:
		return GLFW_API_UNAVAILABLE;
	case TUI_ERROR_GLFW_FORMAT_UNAVAILABLE:
		return GLFW_FORMAT_UNAVAILABLE;
	case TUI_ERROR_GLFW_INVALID_ENUM:
		return GLFW_INVALID_ENUM;
	case TUI_ERROR_GLFW_INVALID_VALUE:
		return GLFW_INVALID_VALUE;
	case TUI_ERROR_GLFW_NOT_INITIALIZED:
		return GLFW_NOT_INITIALIZED;
	case TUI_ERROR_GLFW_NO_CURRENT_CONTEXT:
		return GLFW_NO_CURRENT_CONTEXT;
	case TUI_ERROR_GLFW_NO_WINDOW_CONTEXT:
		return GLFW_NO_WINDOW_CONTEXT;
	case TUI_ERROR_GLFW_OUT_OF_MEMORY:
		return GLFW_OUT_OF_MEMORY;
	case TUI_ERROR_GLFW_PLATFORM_ERROR:
		return GLFW_PLATFORM_ERROR;
	case TUI_ERROR_GLFW_VERSION_UNAVAILABLE:
		return GLFW_VERSION_UNAVAILABLE;
	default:
		return GLFW_NO_ERROR;
	}
}

static inline TuiErrorCode _GlfwErrorToErrorCode(int glfw_error)
{
	switch (glfw_error)
	{
	case GLFW_API_UNAVAILABLE:
		return TUI_ERROR_GLFW_API_UNAVAILABLE;
	case GLFW_FORMAT_UNAVAILABLE:
		return TUI_ERROR_GLFW_FORMAT_UNAVAILABLE;
	case GLFW_INVALID_ENUM:
		return TUI_ERROR_GLFW_INVALID_ENUM;
	case GLFW_INVALID_VALUE:
		return TUI_ERROR_GLFW_INVALID_VALUE;
	case GLFW_NOT_INITIALIZED:
		return TUI_ERROR_GLFW_NOT_INITIALIZED;
	case GLFW_NO_CURRENT_CONTEXT:
		return TUI_ERROR_GLFW_NO_CURRENT_CONTEXT;
	case GLFW_NO_WINDOW_CONTEXT:
		return TUI_ERROR_GLFW_NO_WINDOW_CONTEXT;
	case GLFW_OUT_OF_MEMORY:
		return TUI_ERROR_GLFW_OUT_OF_MEMORY;
	case GLFW_PLATFORM_ERROR:
		return TUI_ERROR_GLFW_PLATFORM_ERROR;
	case GLFW_VERSION_UNAVAILABLE:
		return TUI_ERROR_GLFW_VERSION_UNAVAILABLE;
	default:
		return TUI_ERROR_UNKNOWN;
	}
}

static inline TuiErrorCode _GlfwErrorCheck()
{
	int glfw_error = glfwGetError(NULL);
	if (glfw_error != GLFW_NO_ERROR)
	{
		_GlfwClearErrors();
		return _GlfwErrorToErrorCode(glfw_error);
	}
	return TUI_ERROR_NONE;
}


#endif //header guard