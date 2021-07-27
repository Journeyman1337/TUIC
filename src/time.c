#include <TUIC/time.h>
#include <GLFW/glfw3.h>
#include <TUIC/debug.h>
#include "glfw_error_check.h"
#include "objects.h"

double tuiGetTime()
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0.0;
	}
	double time = glfwGetTime();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return 0.0;
	}
	return time;
}

void tuiSetTime(double time)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}
	if (time <= 0 || time >= 18446744073.0) //this is also enforced by GLFW, but better to enforce it explicitly ourselves
	{
		tuiDebugError(TUI_ERROR_INVALID_TIME, __func__);
		return;
	}
	glfwSetTime(time);
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return;
	}
}

uint64_t tuiGetTimerValue()
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}
	uint64_t timer_value = glfwGetTimerValue();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return 0;
	}
	return timer_value;
}

uint64_t tuiGetTimerFrequency()
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}
	uint64_t timer_frequency = glfwGetTimerFrequency();
	TuiErrorCode glfw_error = _GlfwErrorCheck();
	if (glfw_error != TUI_ERROR_NONE)
	{
		tuiDebugError(glfw_error, __func__);
		return 0;
	}
	return timer_frequency;
}
