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
	system->MonitorConnectedCallback(monitor, (TuiBoolean)connected);
}

TuiMonitor* tuiGetMonitors(int* count)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return NULL;
	}

	int out_count = 0;
	TuiMonitor* monitors = glfwGetMonitors(&out_count);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return NULL;
	}
	if (count != NULL)
	{
		*count = out_count;
	}
	
	return monitors;
}

TuiMonitor tuiGetPrimaryMonitor()
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return NULL;
	}

	TuiMonitor monitor = glfwGetPrimaryMonitor();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return NULL;
	}
	return monitor;
}

void tuiMonitorGetPixelDimensions(TuiMonitor monitor, int* out_pixel_width, int* out_pixel_height)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return;
	}

	const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return;
	}
	if (out_pixel_width != NULL)
	{
		*out_pixel_width = vidmode->width;
	}
	if (out_pixel_height != NULL)
	{
		*out_pixel_height = vidmode->height;
	}
}

int tuiMonitorGetPixelWidth(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return 0;
	}
	return vidmode->width;
}

int tuiMonitorGetPixelHeight(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return 0;
	}
	return vidmode->height;
}

void tuiMonitorGetPhysicalSize(TuiMonitor monitor, int* out_physical_width, int* out_physical_height)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return;
	}

	glfwGetMonitorPhysicalSize(monitor, out_physical_width, out_physical_height);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return;
	}
}

int tuiMonitorGetPhysicalWidth(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	int physical_width = 0;
	glfwGetMonitorPhysicalSize(monitor, &physical_width, NULL);
	return physical_width;
}

int tuiMonitorGetPhysicalHeight(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	int physical_height = 0;
	glfwGetMonitorPhysicalSize(monitor, NULL, &physical_height);
	return physical_height;
}

void tuiMonitorGetContentScale(TuiMonitor monitor, float* out_scale_wide, float* out_scale_tall)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return;
	}

	glfwGetMonitorContentScale(monitor, out_scale_wide, out_scale_tall);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return;
	}
}

float tuiMonitorGetContentScaleWide(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0.0f;
	}

	float scale_wide = 0;
	glfwGetMonitorContentScale(monitor, &scale_wide, NULL);
	return scale_wide;
}

float tuiMonitorGetContentScaleTall(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0.0f;
	}

	float scale_tall = 0;
	glfwGetMonitorContentScale(monitor, NULL, &scale_tall);
	return scale_tall;
}

int tuiMonitorGetRefreshRate(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	return mode->refreshRate;
}

const char* tuiMonitorGetName(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return NULL;
	}

	const char* name = glfwGetMonitorName(monitor);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return NULL;
	}
	return name;
}

void tuiMonitorSetUserPointer(TuiMonitor monitor, void* user_pointer)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return;
	}

	glfwSetMonitorUserPointer(monitor, user_pointer);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return;
	}
}

void* tuiMonitorGetUserPointer(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return NULL;
	}

	void* ptr = glfwGetMonitorUserPointer(monitor);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return NULL;
	}
	return ptr;
}

tuiMonitorConnectedFunction tuiSetMonitorConnectedCallback(tuiMonitorConnectedFunction callback)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return NULL;
	}
	tuiMonitorConnectedFunction monitor_function = system->MonitorConnectedCallback;
	system->MonitorConnectedCallback = callback;
	if (callback != NULL)
	{
		glfwSetMonitorCallback(glfwMonitorCallback);
	}
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return NULL;
	}
	return monitor_function;
}
