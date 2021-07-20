#include <TUIC/monitor.h>
#include <TUIC/system.h>
#include <GLFW/glfw3.h>
#include "glfw_error_check.h"
#include <TUIC/boolean.h>
#include <TUIC/debug.h>


TuiMonitor* tuiGetMonitors(int* count)
{
	int out_count = 0;
	TuiMonitor* monitors = glfwGetMonitors(&out_count);
	GLFW_CHECK_ERROR_RETURN(NULL)
	if (count != NULL)
	{
		*count = out_count;
	}
	
	return monitors;
}

TuiMonitor tuiGetPrimaryMonitor()
{
	TuiMonitor monitor = glfwGetPrimaryMonitor();
	GLFW_CHECK_ERROR_RETURN(NULL)
	return monitor;
}

void tuiMonitorGetPixelDimensions(TuiMonitor monitor, int* width, int* height)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return;
	}

	GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	GLFW_CHECK_ERROR()
	if (width != NULL)
	{
		*width = vidmode->width;
	}
	if (height != NULL)
	{
		*height = vidmode->height;
	}
}

int tuiMonitorGetPixelWidth(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return vidmode->width;
}

int tuiMonitorGetPixelHeight(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return vidmode->height;
}

void tuiMonitorGetPhysicalSize(TuiMonitor monitor, int* physical_width, int* physical_height)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return;
	}

	glfwGetMonitorPhysicalSize(monitor, physical_width, physical_height);
	GLFW_CHECK_ERROR()
}

int tuiMonitorGetPhysicalWidth(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
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
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	int physical_height = 0;
	glfwGetMonitorPhysicalSize(monitor, NULL, &physical_height);
	return physical_height;
}

void tuiMonitorGetContentScale(TuiMonitor monitor, float* scale_wide, float* scale_tall)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return;
	}

	glfwGetMonitorContentScale(monitor, scale_wide, scale_tall);
	GLFW_CHECK_ERROR()
}

float tuiMonitorGetContentScaleWide(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
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
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
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
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return 0;
	}

	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	return mode->refreshRate;
}

const char* tuiMonitorGetName(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return NULL;
	}

	const char* name = glfwGetMonitorName(monitor);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return name;
}

void tuiMonitorSetUserPointer(TuiMonitor monitor, void* pointer)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return;
	}

	glfwSetMonitorUserPointer(monitor, pointer);
	GLFW_CHECK_ERROR()
}

void* tuiMonitorGetUserPointer(TuiMonitor monitor)
{
	if (monitor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_MONITOR, __func__);
		return NULL;
	}

	void* ptr = glfwGetMonitorUserPointer(monitor);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return ptr;
}

tuiMonitorFunction tuiSetMonitorCallback(tuiMonitorFunction callback)
{
	tuiMonitorFunction monitor_function = (tuiMonitorFunction)glfwSetMonitorCallback(callback);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return monitor_function;
}
