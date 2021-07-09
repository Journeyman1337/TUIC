#include <TUIC/time.h>
#include <GLFW/glfw3.h>
#include <TUIC/debug.h>
#include "glfw_error_check.h"

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
