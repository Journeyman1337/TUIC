#include <TUIC/tuic.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <TUIC/desktop_callback.h>
#include "glfw_error_check.h"
#include "objects.h"
#include "opengl33.h"

static TuiSystem sSystem;

TuiSystem tui_get_system()
{
	return sSystem;
}

TuiBoolean tuiInit(TuiBoolean multi_window)
{
	if (sSystem != NULL)
	{
		tuiDebugError(TUI_ERROR_ALREADY_INITIALIZED, __func__);
		return TUI_FALSE;
	}

	int initialized = glfwInit();

	if (initialized != GLFW_TRUE)
	{
		return TUI_FALSE;
	}

	sSystem = tuiAllocate(sizeof(TuiSystem_s));
	sSystem->MultiWindow = multi_window;
	sSystem->BaseWindow = NULL;
	sSystem->BaseWindowClaimed = TUI_FALSE;
	sSystem->ApiData = NULL;

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
	sSystem->BaseWindow = glfwCreateWindow(1, 1, "", NULL, NULL);
	if (sSystem->BaseWindow == NULL)
	{
		tuiFree(sSystem);
		sSystem = NULL;
		glfwTerminate();
		GLFW_CLEAR_ERRORS()
			return TUI_FALSE;
	}
	tuiSystemCreate_Opengl33();

	GLFW_CLEAR_ERRORS()
	return TUI_TRUE;
}

TuiBoolean tuiIsActive()
{
	return sSystem != NULL;
}

void tuiTerminate()
{
	if (sSystem == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_FALSE;
	}
	TuiBoolean failed = TUI_FALSE;
	if (tuiGetWindowCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_WINDOW, __func__);
		failed = TUI_TRUE;
	}
	if (tuiGetCursorCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_CURSOR, __func__);
		failed = TUI_TRUE;
	}
	if (tuiGetAtlasCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_ATLAS, __func__);
		failed = TUI_TRUE;
	}
	if (tuiGetPanelCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_PANEL, __func__);
		failed = TUI_TRUE;
	}
	if (tuiGetPaletteCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_PALETTE, __func__);
		failed = TUI_TRUE;
	}
	if (tuiGetTextureCount() != 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_TEXTURE, __func__);
		failed = TUI_TRUE;
	}
	if (sSystem == NULL)
	{
		tuiDebugError(TUI_ERROR_DESKTOP_NOT_INITIALIZED, __func__);
		failed = TUI_TRUE;
	}
	if (failed == TUI_TRUE)
	{
		return;
	}


	tuiSystemDestroy_Opengl33();
	glfwDestroyWindow(sSystem->BaseWindow);
	tuiFree(sSystem);
	
	glfwTerminate();
	GLFW_CLEAR_ERRORS()
}

TuiBoolean tuiMultiWindowDesktop()
{
	if (sSystem == NULL)
	{
		return TUI_FALSE;
	}
	return sSystem->MultiWindow;
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