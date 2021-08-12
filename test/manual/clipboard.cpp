/* Test the clipboard getter and setter functions. */

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

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState state, TuiKeyboardMod mods)
{
    if (key == TUIK_ENTER && state == TUI_BUTTON_PRESS)
    {
        printf("%s\n", tuiGetClipboardString());
    }
    if (key == TUIK_Z && state == TUI_BUTTON_PRESS)
    {
        tuiSetClipboardString("abcdefghijlmnopqrstuvwxyz1234567890");
    }
    if (key == TUIK_X && state == TUI_BUTTON_PRESS)
    {
        tuiSetClipboardString("qwertyuiopasdfghjklzxcvbnm");
    }
}

int main()
{
    if (tuiInit() == TUI_FALSE)
    {
        printf("Failed to initialize TUIC.");
        return 1;
    }

    tuiSetDebugErrorCallback(message_callback);

    TuiWindow window = tuiWindowCreate(256, 256, "clipboard", TUI_NULL);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);

    printf("Press enter to print the clipboard text. Press z to add all letters and numbers to the clipboard. Press x to copy all qwerty characters in order to the clipboard. Window must have input focus (click window to gain focus).\n");

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