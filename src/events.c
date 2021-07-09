#include <TUIC/events.h>
#include <GLFW/glfw3.h>
#include <TUIC/debug.h>
#include "glfw_error_check.h"

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