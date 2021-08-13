/* Test window state changes including: iconify, maximize, restore, hide, show, focus, fullscreen, and windowed. */

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState state, TuiKeyboardMod mods)
{
	if (key == TUIK_I && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean iconified = tuiWindowGetIconified(window);
		tuiWindowSetIconified(window, !iconified);
	}
	if (key == TUIK_M && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean maximized = tuiWindowGetMaximized(window);
		tuiWindowSetMaximized(window, !maximized);
	}
	if (key == TUIK_R && state == TUI_BUTTON_PRESS)
	{
		tuiWindowRestore(window);
	}
	if (key == TUIK_H && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean visible = tuiWindowGetVisible(window);
		if (visible == TUI_TRUE)
		{
			tuiWindowHide(window);
			printf("Window hidden.\n");
		}
		else
		{
			tuiWindowShow(window);
			printf("Window shown.\n");
		}
	}
	if (key == TUIK_F && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean fullscreen = tuiWindowGetFullscreen(window);
		if (fullscreen == TUI_TRUE)
		{
			tuiWindowSetFullscreenCurrentMonitor(window);
			printf("Window made fullscreen.\n");
		}
		else
		{
			tuiWindowSetWindowed(window);
			printf("Window made windowed.\n");
		}
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
	
	TuiWindow window = tuiWindowCreate(256, 256, "window_state", TUI_NULL);
	tuiWindowSetKeyboardKeyCallback(window, key_callback);
	tuiWindowSetIconifyCallback(window, iconify_callback);
	tuiWindowSetMaximizeCallback(window, maximize_callback);
	
	while (tuiWindowShouldClose(window) == TUI_FALSE)
	{
		tuiPollEvents();
		tuiWindowClearColor(window, 255, 0, 0, 255);
		tuiWindowFrame(window);
	}
	
	tuiWindowDestroy(window);
	window = TUI_NULL;
	
	tuiTerminate();
	
	return 0;
}