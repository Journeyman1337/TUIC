#include <TUIC/joystick.h>
#include <TUIC/system.h>
#include <GLFW/glfw3.h>

TuiBoolean tuiJoystickIsPresent(TuiJoystickId joystick_id)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return TUI_FALSE;
	}

	if (glfwJoystickPresent(joystick_id) == TUI_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const float* tuiGetJoystickAxes(TuiJoystickId joystick_id, int* count)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickAxes(joystick_id, count);
}

const unsigned char* tuiGetJoystickButtons(TuiJoystickId joystick_id, int* count)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickButtons(joystick_id, count);
}

const unsigned char* tuiGetJoystickHats(TuiJoystickId joystick_id, int* count)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}


	return tuiGetJoystickHats(joystick_id, count);
}

const char* tuiGetJoystickName(TuiJoystickId joystick_id)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickName(joystick_id);
}

const char* tuiGetJoystickGUID(TuiJoystickId joystick_id)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickGUID(joystick_id);
}

void tuiSetJoystickUserPointer(TuiJoystickId joystick_id, void* pointer)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}

	glfwSetJoystickUserPointer(joystick_id, pointer);
}

void* tuiGetJoystickUserPointer(TuiJoystickId joystick_id)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetJoystickUserPointer(joystick_id);
}

TuiBoolean tuiJoystickIsGamepad(TuiJoystickId joystick_id)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0;
	}

	if (glfwJoystickIsGamepad(joystick_id) == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiUpdateGamepadMappings(const char* string)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return 0;
	}

	if (glfwUpdateGamepadMappings(string) == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiGetGamepadName(TuiJoystickId joystick_id)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwGetGamepadName(joystick_id);
}

tuiJoysticFunction tuiSetJoystickCallback(tuiJoysticFunction callback)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	return glfwSetJoystickCallback(callback);
}
