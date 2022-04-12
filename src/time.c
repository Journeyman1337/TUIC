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
#include <TUIC/time.h>
#include <GLFW/glfw3.h>
#include <TUIC/debug.h>
#include "glfw_error_check.h"
#include "objects.h"

TuiResult tuiGetTime(double* time)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	*time = glfwGetTime();
	return _GlfwErrorCheck();
}

TuiResult tuiSetTime(double time)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	if (time <= 0 || time >= 18446744073.0) //this is also enforced by GLFW, but better to enforce it explicitly ourselves
	{
		return TUI_RESULT_ERROR_INVALID_VALUE;
	}
	glfwSetTime(time);
	return _GlfwErrorCheck();
}