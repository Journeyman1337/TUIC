#include <TUIC/joystick.h>
#include <TUIC/system.h>
#include <GLFW/glfw3.h>
#include "glfw_error_check.h"

TuiBoolean tuiJoystickIsPresent(TuiJoystickId joystick_id)
{
	int present = glfwJoystickPresent(joystick_id);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (present == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const float* tuiJoystickGetAxes(TuiJoystickId joystick_id, int* count)
{
	int out_count = 0;
	const float* axes = glfwGetJoystickAxes(joystick_id, &out_count);
	GLFW_CHECK_ERROR_RETURN(NULL)
	if (count != NULL)
	{
		*count = out_count;
	}
	return axes;
}

const unsigned char* tuiJoystickGetButtons(TuiJoystickId joystick_id, int* count)
{
	int out_count = 0;
	const unsigned char* buttons = glfwGetJoystickButtons(joystick_id, count);
	GLFW_CHECK_ERROR_RETURN(NULL)
	if (count != NULL)
	{
		*count = out_count;
	}
	return buttons;
}

const unsigned char* tuiJoystickGetHats(TuiJoystickId joystick_id, int* count)
{
	int out_count = 0;
	const unsigned char* hats = glfwGetJoystickHats(joystick_id, count);
	GLFW_CHECK_ERROR_RETURN(NULL)
	if (count != NULL)
	{
		*count = out_count;
	}
	return hats;
}

const char* tuiJoystickGetName(TuiJoystickId joystick_id)
{
	const char* name = glfwGetJoystickName(joystick_id);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return name;
}

const char* tuiJoystickGetGUID(TuiJoystickId joystick_id)
{
	const char* guid = glfwGetJoystickGUID(joystick_id);
	GLFW_CHECK_ERROR(NULL)
	return guid;
}

void tuiJoystickSetUserPointer(TuiJoystickId joystick_id, void* pointer)
{
	glfwSetJoystickUserPointer(joystick_id, pointer);
	GLFW_CHECK_ERROR()
}

void* tuiJoystickGetUserPointer(TuiJoystickId joystick_id)
{
	void* ptr = glfwGetJoystickUserPointer(joystick_id);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return ptr;
}

TuiBoolean tuiJoystickIsGamepad(TuiJoystickId joystick_id)
{
	int is_gamepad = glfwJoystickIsGamepad(joystick_id);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (is_gamepad == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiJoystickUpdateMappings(const char* string)
{
	int updated = glfwUpdateGamepadMappings(string);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (updated == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiJoystickGetGamepadName(TuiJoystickId joystick_id)
{
	const char* name = glfwGetGamepadName(joystick_id);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return name;
}

tuiJoysticFunction tuiSetJoystickCallback(tuiJoysticFunction callback)
{
	tuiJoysticFunction joystick_function = glfwSetJoystickCallback(callback);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return joystick_function;
}
