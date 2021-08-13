/* Test raw mouse motion. */

#include <TUIC/tuic.h>

#include <stdio.h>

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState state, TuiKeyboardMod mods)
{
	if (key == TUIK_SPACE && state == TUI_BUTTON_PRESS)
	{
		TuiBoolean raw_mouse_motion_enabled = tuiWindowGetRawMouseMotionEnabled(window);
		tuiWindowSetRawMouseMotionEnabled(window, !raw_mouse_motion_enabled);
		if (raw_mouse_motion_enabled == TUI_TRUE)
		{
			printf("Raw mouse motion disabled.\n");
		}
		else //if (raw_mouse_motion_enabled == TUI_FALSE)
		{
			printf("Raw mouse motion enabled.\n");
		}
	}
	if (key == TUIK_ESCAPE && state == TUI_BUTTON_PRESS)
	{
		tuiWindowSetShouldClose(window, TUI_TRUE);
	}
}

void cursor_move(TuiWindow window, double x_position, double y_position)
{
	printf("Cursor move: ( x = %f, y = %f )\n", x_position, y_position);
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
	
	if (tuiRawMouseMotionSupported() == TUI_FALSE)
	{
		printf("Raw mouse motion is not supported.");
		return 0;
	}
	
	TuiWindow window = tuiWindowCreate(256, 256, "raw_mouse_motion", TUI_NULL);
	tuiWindowSetKeyboardKeyCallback(window, key_callback);
	tuiWindowSetCursorMoveCallback(window, cursor_move);

	tuiWindowSetCursorMode(window, TUI_CURSOR_MODE_DISABLED);
	
	printf("Press spacebar to enable or disable raw mouse motion. Press escape to close the window.\nRaw mouse motion disabled.\n");
	
	while (tuiWindowShouldClose(window) == TUI_FALSE)
	{
		tuiPollEvents();
		tuiWindowFrame(window);
	}
	
	tuiWindowDestroy(window);
	window = TUI_NULL;
	
	tuiTerminate();	
	
	return 0;
}