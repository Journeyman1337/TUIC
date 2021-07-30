#include <TUIC/events.h>
#include <GLFW/glfw3.h>
#include <TUIC/debug.h>
#include "glfw_error_check.h"
#include "objects.h"

void tuiPollEvents()
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}

	glfwPollEvents();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
	}
}

void tuiWaitEvents()
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}

	glfwWaitEvents();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
	}
}

void tuiWaitEventsTimeout(double timeout)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}
	if (timeout < 0.0 || 
		timeout == 0x7ff0000000000000ULL ||// INFINITY
		 timeout == 0x7ff0000000000001ULL // NaN
		)
	{
		tuiDebugError(TUI_ERROR_INVALID_EVENT_TIMEOUT, __func__);
		return;
	}

	glfwWaitEventsTimeout(timeout);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
	}
}

void tuiPostEmptyEvent()
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}

	glfwPostEmptyEvent();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
	}
}