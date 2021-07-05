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

int tuiGetKeyScancode(int key)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0;
	}

	return glfwGetKeyScancode(key);
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

int tuiJoystickPresent(int jid)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0;
	}

	return glfwJoystickPresent(jid);
}

const float* tuiGetJoystickAxes(int jid, int* count)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickAxes(jid, count);
}

const unsigned char* tuiGetJoystickButtons(int jid, int* count)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickButtons(jid, count);
}

const unsigned char* tuiGetJoystickHats(int jid, int* count)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickHats(jid, count);
}

const char* tuiGetJoystickName(int jid)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickName(jid);
}

const char* tuiGetJoystickGUID(int jid)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickGUID(jid);
}

void tuiSetJoystickUserPointer(int jid, void* pointer)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	return glfwSetJoystickUserPointer(jid, pointer);
}

void* tuiGetJoystickUserPointer(int jid)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	return glfwGetJoystickUserPointer(jid);
}

int tuiJoystickIsGamepad(int jid)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	return glfwJoystickIsGamepad(jid);
}

tuiJoysticFunction tuiSetJoystickCallback(tuiJoysticFunction callback)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	glfwSetJoystickCallback(callback);
}

int tuiUpdateGamepadMappings(const char* string)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0;
	}

	return glfwUpdateGamepadMappings(string);
}

const char* tuiGetGamepadName(int jid)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetGamepadName(jid);
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