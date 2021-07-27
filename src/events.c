#include <TUIC/events.h>
#include <GLFW/glfw3.h>
#include <TUIC/debug.h>
#include "glfw_error_check.h"

void tuiPollEvents()
{
	glfwPollEvents();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
	}
}

void tuiWaitEvents()
{
	glfwWaitEvents();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
	}
}

void tuiWaitEventsTimeout(double timeout)
{
	glfwWaitEventsTimeout(timeout);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
	}
}

void tuiPostEmptyEvent()
{
	glfwPostEmptyEvent();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
	}
}