#include <TUIC/monitor.h>
#include <TUIC/system.h>
#include <GLFW/glfw3.h>
#include "glfw_error_check.h"
#include <TUIC/boolean.h>
#include <TUIC/debug.h>


TuiMonitor* tuiGetMonitors(int* count)
{
	int out_count;
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
	glfwGetMonitorWorkarea(monitor, NULL, NULL, width, height);
}

int tuiMonitorGetPixelWidth(TuiMonitor monitor)
{
	int width = 0;
	glfwGetMonitorWorkarea(monitor, NULL, NULL, &width, NULL);
	return width;
}

int tuiMonitorGetPixelHeight(TuiMonitor monitor)
{
	int height = 0;
	glfwGetMonitorWorkarea(monitor, NULL, NULL, NULL, &height);
	return height;
}

void tuiMonitorGetPhysicalSize(TuiMonitor monitor, int* physical_width, int* physical_height)
{
	glfwGetMonitorPhysicalSize(monitor, physical_width, physical_height);
	GLFW_CHECK_ERROR()
}

int tuiMonitorGetPhysicalWidth(TuiMonitor monitor)
{
	int physical_width = 0;
	glfwGetMonitorPhysicalSize(monitor, &physical_width, NULL);
	return physical_width;
}

int tuiMonitorGetPhysicalHeight(TuiMonitor monitor)
{
	int physical_height = 0;
	glfwGetMonitorPhysicalSize(monitor, NULL, &physical_height);
	return physical_height;
}

void tuiMonitorGetContentScale(TuiMonitor monitor, float* content_width, float* content_height)
{
	glfwGetMonitorContentScale(monitor, content_width, content_height);
	GLFW_CHECK_ERROR()
}

int tuiMonitorGetContentWidth(TuiMonitor monitor)
{
	int content_width = 0;
	glfwGetMonitorContentScale(monitor, &content_width, NULL);
	return content_width;
}

int tuiMonitorGetContentHeight(TuiMonitor monitor)
{
	int content_height = 0;
	glfwGetMonitorContentScale(monitor, NULL, &content_height);
	return content_height;
}

int tuiMonitorGetRefreshRate(TuiMonitor monitor)
{
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	return mode->refreshRate;
}

const char* tuiMonitorGetName(TuiMonitor monitor)
{
	const char* name = glfwGetMonitorName(monitor);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return name;
}

void tuiMonitorSetUserPointer(TuiMonitor monitor, void* pointer)
{
	glfwSetMonitorUserPointer(monitor, pointer);
	GLFW_CHECK_ERROR()
}

void* tuiMonitorGetUserPointer(TuiMonitor monitor)
{
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
