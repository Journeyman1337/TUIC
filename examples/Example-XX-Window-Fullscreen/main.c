
#include <TUIC/tuic.h>

#include <stdio.h>

const int windowed_window_width = 500;
const int windowed_window_height = 500;

void TuiMessageCallback(TuiErrorCode error_code, const char* msg)
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

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState button_state, TuiKeyboardKeyMod key_mod)
{
    if (key == TUIK_F && button_state == TUI_BUTTON_PRESS)
    {
        if (tuiWindowIsFullscreen(window))
        {
            tuiWindowSetWindowedResize(window, windowed_window_width, windowed_window_height, windowed_window_width, windowed_window_height);
            printf("Window is now windowed!\n");
        }
        else
        {
            TuiMonitor window_monitor = tuiWindowGetMonitor(window);
            tuiWindowSetFullscreenResize(window, window_monitor, 0, 0, 0);
            printf("Window is now fullscreen in monitor: \"%s\"!\n", tuiMonitorGetName(window_monitor));
        }
    }
}

int main()
{
    /* Initialize TUIC. */
    TuiBoolean multi_window = TUI_FALSE;
    TuiBoolean initialization_successful = tuiInit(multi_window);
    if (initialization_successful == TUI_FALSE)
    {
        printf("Failed to initialize TUIC.");
        return -1;
    }

    /* Tell TUIC to send all debug messages to our message callback (the function we implemented above main). */
    tuiSetDebugErrorCallback(TuiMessageCallback);

    /* Load the custom window icon image. */
    int expected_channel_count = 4;
    TuiImage window_icon_image = tuiImageLoad("sushi.png", expected_channel_count);

    /* Create the window. */
    const char* window_title = "Example XX";
    TuiWindow window = tuiWindowCreate(windowed_window_width, windowed_window_height, window_title, NULL);

    /* Set the key callback. */
    tuiWindowSetKeyboardKeyCallback(window, key_callback);

    /* Print prompt to console. */
    printf("Press F to swap between windowed and fullscreen mode.\n");

    //Render loop
    while (tuiWindowShouldClose(window) == TUI_FALSE)
    {
        tuiPollEvents(); //handle input events and call callback functions
       
        if (tuiWindowIsFullscreen(window))
        {
            tuiWindowClearColor(window, 255, 0, 0, 255); //red clear color
        }
        else
        {
            tuiWindowClearColor(window, 0, 0, 255, 255); //blue clear color
        }

        tuiWindowSwapBuffers(window); //swap the window buffers
    }

    /* Destroy all remaining TUIC objects */
    tuiWindowDestroy(window); //The instance must always be created first and destroyed last.
    window = NULL;

    tuiTerminate();
    return 0;
}
