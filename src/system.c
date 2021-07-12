#include <TUIC/tuic.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <TUIC/desktop_callback.h>
#include "glfw_error_check.h"

static int sActive = TUI_FALSE;

TuiBoolean tuiInit()
{
	if (sActive == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_ALREADY_INITIALIZED, __func__);
		return TUI_FALSE;
	}

	int initialized = glfwInit();
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)

	if (initialized == GLFW_TRUE)
	{
		sActive = TUI_TRUE;
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiIsActive()
{
	return sActive;
}

void tuiTerminate()
{
	if (tuiGetWindowCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_WINDOW, __func__);
		return;
	}
	if (tuiGetCursorCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_CURSOR, __func__);
		return;
	}

	sActive = TUI_FALSE;
	glfwTerminate();
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiRawMouseMotionSupported()
{
	int supported = glfwRawMouseMotionSupported();
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (supported == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiVulkanSupported()
{
	int supported = glfwVulkanSupported();
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (supported == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}