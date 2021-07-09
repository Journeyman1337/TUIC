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

void tuiGetMonitorPos(TuiMonitor monitor, int* xpos, int* ypos)
{
	glfwGetMonitorPos(monitor, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiGetMonitorWorkarea(TuiMonitor monitor, int* xpos, int* ypos, int* width, int* height)
{
	glfwGetMonitorWorkarea(monitor, xpos, ypos, width, height);
	GLFW_CHECK_ERROR()
}

void tuiGetMonitorPhysicalSize(TuiMonitor monitor, int* widthMM, int* heightMM)
{
	glfwGetMonitorPhysicalSize(monitor, widthMM, heightMM);
	GLFW_CHECK_ERROR()
}

void tuiGetMonitorContentScale(TuiMonitor monitor, float* xscale, float* yscale)
{
	glfwGetMonitorContentScale(monitor, xscale, yscale);
	GLFW_CHECK_ERROR()
}

const char* tuiGetMonitorName(TuiMonitor monitor)
{
	const char* name = glfwGetMonitorName(monitor);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return name;
}

void tuiSetMonitorUserPointer(TuiMonitor monitor, void* pointer)
{
	glfwSetMonitorUserPointer(monitor, pointer);
	GLFW_CHECK_ERROR()
}

void* tuiGetMonitorUserPointer(TuiMonitor monitor)
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
