#include <TUIC/monitor.h>
#include <TUIC/system.h>
#include <GLFW/glfw3.h>
#include <TUIC/boolean.h>

TuiMonitor* tuiGetMonitors(int* count)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	return glfwGetMonitors(count);
}

TuiMonitor tuiGetPrimaryMonitor()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	return glfwGetPrimaryMonitor();
}

void tuiGetMonitorPos(TuiMonitor monitor, int* xpos, int* ypos)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	glfwGetMonitorPos(monitor, xpos, ypos);
}

void tuiGetMonitorWorkarea(TuiMonitor monitor, int* xpos, int* ypos, int* width, int* height)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	glfwGetMonitorWorkarea(monitor, xpos, ypos, width, height);
}

void tuiGetMonitorPhysicalSize(TuiMonitor monitor, int* widthMM, int* heightMM)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	glfwGetMonitorPhysicalSize(monitor, widthMM, heightMM);
}

void tuiGetMonitorContentScale(TuiMonitor monitor, float* xscale, float* yscale)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	glfwGetMonitorContentScale(monitor, xscale, yscale);
}

const char* tuiGetMonitorName(TuiMonitor monitor)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}
	return glfwGetMonitorName(monitor);
}

void tuiSetMonitorUserPointer(TuiMonitor monitor, void* pointer)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	glfwSetMonitorUserPointer(monitor, pointer);
}

void* tuiGetMonitorUserPointer(TuiMonitor monitor)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetMonitorUserPointer(monitor);
}

tuiMonitorFunction tuiSetMonitorCallback(tuiMonitorFunction callback)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return (tuiMonitorFunction)glfwSetMonitorCallback(callback);
}
