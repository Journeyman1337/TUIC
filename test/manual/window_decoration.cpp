/* Test window icon setting, title setting, and decroation control functions. */

#include <TUIC/tuic.h>

#include <stdio.h>
#include <string.h>

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

static int sNextFrame = TUI_FALSE;

void frame(TuiWindow window)
{
    tuiWindowFrame(window);
    tuiPollEvents();
    sNextFrame = TUI_FALSE;
    while (sNextFrame == TUI_FALSE && tuiWindowShouldClose(window) == TUI_FALSE)
    {
        tuiWindowFrame(window);
        tuiPollEvents();
    }
}

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState state, TuiKeyboardMod mods)
{
    if (key == TUIK_SPACE && state == TUI_BUTTON_PRESS)
    {
        sNextFrame = TUI_TRUE;
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

    printf("Press spacebar to toggle window decoration.\n");

    TuiWindow window = tuiWindowCreate(256, 256, "window_decoration", TUI_NULL);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);

    while (tuiWindowShouldClose(window) == TUI_FALSE)
    {
        tuiWindowSetDecorated(window, TUI_FALSE);
        frame(window);
        tuiWindowSetDecorated(window, TUI_TRUE);
        frame(window);
    }

    tuiWindowDestroy(window);
    window = TUI_NULL;

    tuiTerminate();
    return 0;
}