#include <TUIC/tuic.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <TUIC/desktop_callback.h>

static int sActive = TUI_FALSE;

int tuiInit()
{
	sActive = TUI_TRUE;
	return glfwInit();
}

int tuiIsActive()
{
	return sActive;
}

void tuiTerminate()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	if (tuiGetInstanceCount() != 0)
	{
		// TODO tuiDebugError(TUI_ERROR_DANGLING_INSTANCE, __func__);
		return;
	}
	if (tuiGetCursorCount() != 0)
	{
		// TODO tuiDebugError(TUI_ERROR_DANGLING_CURSOR, __func__);
		return;
	}

	sActive = TUI_FALSE;
	glfwTerminate();
}

void tuiPollEvents()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	glfwPollEvents();
}

void tuiWaitEvents()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	glfwWaitEvents();
}

void tuiWaitEventsTimeout(double timeout)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	glfwWaitEventsTimeout(timeout);
}

void tuiPostEmptyEvent()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	glfwPostEmptyEvent();
}

int tuiRawMouseMotionSupported()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return TUI_FALSE;
	}

	return glfwRawMouseMotionSupported();
}

double tuiGetTime()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0.0;
	}

	return glfwGetTime();
}

void tuiSetTime(double time)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	glfwSetTime(time);
}

uint64_t tuiGetTimerValue()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0;
	}

	return glfwGetTimerValue();
}

uint64_t tuiGetTimerFrequency()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0;
	}

	return glfwGetTimerFrequency();
}

int tuiVulkanSupported()
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0;
	}

	return glfwVulkanSupported();
}