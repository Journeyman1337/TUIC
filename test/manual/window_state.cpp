/* Test window state changes including: iconify, maximize, restore, hide, show, focus, fullscreen, and windowed. */

#include <TUIC/tuic.h>

#include <stdio.h>

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState state, TuiKeyboardMod mods)
{
	TuiWindow state_window = (TuiWindow)tuiWindowGetUserPointer(window);
	if (key == TUIK_I && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean iconified = tuiWindowGetIconified(state_window);
		if (iconified == TUI_FALSE)
		{
			tuiWindowIconify(state_window);
		}
		else //if (iconified == TUI_TRUE)
		{
			tuiWindowRestore(state_window);
		}
		tuiWindowFocus(window);
	}
	if (key == TUIK_M && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean maximized = tuiWindowGetMaximized(state_window);
		if (maximized == TUI_TRUE)
		{
			tuiWindowRestore(state_window);
		}
		else //if (maximized == TUI_FALSE)
		{
			tuiWindowMaximize(state_window);
		}
		tuiWindowFocus(window);
	}
	if (key == TUIK_H && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean visible = tuiWindowGetVisible(state_window);
		if (visible == TUI_TRUE)
		{
			tuiWindowHide(state_window);
			printf("Window hidden.\n");
		}
		else
		{
			tuiWindowShow(state_window);
			printf("Window shown.\n");
		}
		tuiWindowFocus(window);
	}
	if (key == TUIK_F && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean fullscreen = tuiWindowGetIsFullscreen(state_window);
		if (fullscreen == TUI_FALSE)
		{
			tuiWindowSetFullscreenCurrentMonitor(state_window);
			printf("Window made fullscreen. %d %d\n", tuiWindowGetViewportPixelWidth(state_window), tuiWindowGetFramebufferPixelWidth(state_window));
		}
		else //if (fullscreen == TUI_TRUE)
		{
			tuiWindowSetWindowedViewportSize(state_window, 256, 256);
			printf("Window made windowed.\n");
		}
		tuiWindowFocus(window);
	}
}

void iconify_callback(TuiWindow window, TuiBoolean iconified)
{
	if (iconified == TUI_TRUE)
	{
		printf("Window iconified.\n");
	}
	else //if (iconified == TUI_FALSE)
	{
		printf("Window uniconified.\n");
	}
}

void maximize_callback(TuiWindow window, TuiBoolean maximized)
{
	if (maximized == TUI_TRUE)
	{
		printf("Window maximized.\n");
	}
	else //if (maximized == TUI_FALSE)
	{
		printf("Window unmaximized.\n");
	}
}

void message_callback(TuiErrorCode error_code, const char* msg)
{
	if (error_code == TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC)
	{
		printf("%s : %s backend message: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
	}
	else
	{
		printf("%s : %s location: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
	}
}

int main()
{
	tuiSetDebugErrorCallback(message_callback);
	
	if (tuiInit() == TUI_FALSE)
	{
		printf("Failed to initialize TUIC.");
		return 1;
	}
	
	TuiWindow window = tuiWindowCreate(256, 256, "State Changing Window", TUI_NULL);
	
	tuiWindowSetIconifyCallback(window, iconify_callback);
	tuiWindowSetMaximizeCallback(window, maximize_callback);

	TuiWindow input_focus_window = tuiWindowCreate(256, 256, "Input Focus Window", TUI_NULL);
	tuiWindowSetUserPointer(input_focus_window, window);
	tuiWindowSetKeyboardKeyCallback(input_focus_window, key_callback);
	tuiWindowSetTopmost(input_focus_window, TUI_TRUE);

	printf("Give the input focus window input focus to change the state of the other window. Press M to maximize and restore the window. Press I to iconify the window. Press F to toggle between fullscreen and windowed. Press H to hide the window.\n");
	
	while (tuiWindowShouldClose(window) == TUI_FALSE && tuiWindowShouldClose(input_focus_window) == TUI_FALSE)
	{
		tuiPollEvents();
		tuiWindowClearColor(window, 255, 0, 0, 255);
		tuiWindowFrame(window);
		tuiWindowFrame(input_focus_window);
	}
	
	tuiWindowDestroy(window);
	window = TUI_NULL;
	tuiWindowDestroy(input_focus_window);
	input_focus_window = TUI_NULL;
	
	tuiTerminate();
	
	return 0;
}