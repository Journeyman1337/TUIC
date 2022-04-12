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
#include <TUIC/monitor.h>
#include <TUIC/system.h>
#include <GLFW/glfw3.h>
#include "glfw_error_check.h"
#include <TUIC/boolean.h>
#include <TUIC/debug.h>
#include "objects.h"

static void glfwMonitorCallback(GLFWmonitor* monitor, int connected)
{
	TuiSystem system = tui_get_system();
	if (system != NULL && system->MonitorConnectedCallback != NULL)
	{
		system->MonitorConnectedCallback(monitor, (TuiBoolean)connected);
	}	
}

TuiResult tuiGetMonitors(TuiMonitor** monitors, int* count)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	monitors = glfwGetMonitors(count);
	return _GlfwErrorCheck();
}

TuiResult tuiGetPrimaryMonitor(TuiMonitor* monitor)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	monitor = glfwGetPrimaryMonitor();
	return _GlfwErrorCheck();
}

TuiResult tuiMonitorGetPixelDimensions(TuiMonitor monitor, int* out_pixel_width, int* out_pixel_height)
{
	assert(monitor != NULL);
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
}

TuiResult tuiMonitorGetPixelDimensions(TuiMonitor monitor, int* pixel_width, int* pixel_height)
{
	assert(monitor != NULL);
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	TuiResult result = _GlfwErrorCheck();
	if (result != TUI_RESULT_OK)
	{
		return result;
	}
	if (pixel_width != NULL)
	{
		*pixel_width = vidmode->width;
	}
	if (pixel_height != NULL)
	{
		*pixel_width = vidmode->height;
	}
	return TUI_RESULT_OK;
}

TuiResult tuiMonitorGetPhysicalSize(TuiMonitor monitor, int* physical_width, int* physical_height)
{
	assert(monitor != NULL);
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	glfwGetMonitorPhysicalSize(monitor, physical_width, physical_height);
	return _GlfwErrorCheck();
}

TuiResult tuiMonitorGetContentScale(TuiMonitor monitor, float* scale_wide, float* scale_tall)
{
	assert(monitor != NULL);
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	glfwGetMonitorContentScale(monitor, scale_wide, out_scale_tall);
	return _GlfwErrorCheck();
}

TuiResult tuiMonitorGetRefreshRate(TuiMonitor monitor, int* refresh_rate)
{
	assert(monitor != NULL);
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	TuiResult result = _GlfwErrorCheck();
	if (result != TUI_RESULT_OK)
	{
		return result;
	}
	if (refresh_rate != NULL)
	{
		*refresh_rate = vidmode->refreshRate;
	}
	return TUI_RESULT_OK;
}

TuiResult tuiMonitorGetName(TuiMonitor monitor, const char** name)
{
	assert(monitor != NULL);
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	*name = glfwGetMonitorName(monitor);
	return _GlfwErrorCheck();
}

TuiResult tuiMonitorSetUserPointer(TuiMonitor monitor, void* user_pointer)
{
	assert(monitor != NULL);
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	glfwSetMonitorUserPointer(monitor, user_pointer);
	return _GlfwErrorCheck();
}

TuiResult tuiMonitorGetUserPointer(TuiMonitor monitor, void** user_ptr)
{
	assert(monitor != NULL);
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	*user_ptr = glfwGetMonitorUserPointer(monitor);
	return _GlfwErrorCheck();
}

TuiResult tuiSetMonitorConnectedCallback(tuiMonitorConnectedFunction callback, tuiMonitorConnectedFunction* previous_callback)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	previous_callback = system->MonitorConnectedCallback;
	system->MonitorConnectedCallback = callback;
	if (callback != NULL)
	{
		glfwSetMonitorCallback(glfwMonitorCallback);
	}
	return _GlfwErrorCheck();
}
