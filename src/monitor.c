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

void tuiMonitorGetPhysicalSize(TuiMonitor monitor, int* widthMM, int* heightMM)
{
	glfwGetMonitorPhysicalSize(monitor, widthMM, heightMM);
	GLFW_CHECK_ERROR()
}

void tuiMonitorGetContentScale(TuiMonitor monitor, float* xscale, float* yscale)
{
	glfwGetMonitorContentScale(monitor, xscale, yscale);
	GLFW_CHECK_ERROR()
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
