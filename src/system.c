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
	if (tuiGetInstanceCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_INSTANCE, __func__);
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

void tuiPollEvents()
{
	glfwPollEvents();
	GLFW_CHECK_ERROR()
}

void tuiWaitEvents()
{
	glfwWaitEvents();
	GLFW_CHECK_ERROR()
}

void tuiWaitEventsTimeout(double timeout)
{
	glfwWaitEventsTimeout(timeout);
	GLFW_CHECK_ERROR()
}

void tuiPostEmptyEvent()
{
	glfwPostEmptyEvent();
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

double tuiGetTime()
{
	double time = glfwGetTime();
	GLFW_CHECK_ERROR_RETURN(time, 0.0)
	return time;
}

void tuiSetTime(double time)
{
	if (time <= 0 || time >= 18446744073.0)
	{
		tuiDebugError(TUI_ERROR_INVALID_TIME, __func__);
		return;
	}
	glfwSetTime(time);
	GLFW_CHECK_ERROR()
}

uint64_t tuiGetTimerValue()
{
	uint64_t timer_value = glfwGetTimerValue();
	GLFW_CHECK_ERROR_RETURN(0)
	return timer_value;
}

uint64_t tuiGetTimerFrequency()
{
	uint64_t timer_frequency = glfwGetTimerFrequency();
	GLFW_CHECK_ERROR_RETURN(0)
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