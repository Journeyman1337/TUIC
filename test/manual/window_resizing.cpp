/* Test resizing a TuiWindow and test all resize control functions (size limits, aspect ratio fixing, etc). */

#include <TUIC/tuic.h>

#include <stdio.h>

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

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState button_state, TuiKeyboardMod mod)
{
    if (key == TUIK_A && button_state == TUI_BUTTON_PRESS)
    {
        if (tuiWindowGetAspectRatioIsFixed(window) == TUI_FALSE)
        {
            tuiWindowFixCurrentAspectRatio(window);
            int aspect_numerator = 0;
            int aspect_denominator = 0;
            tuiWindowGetAspectRatio(window, &aspect_numerator, &aspect_denominator);
            printf("Aspect ratio fixed at ( %d/%d ).\n", aspect_numerator, aspect_denominator);
        }
        else
        {
            tuiWindowUnfixAspectRatio(window);
            printf("Aspect ratio is unfixed.\n");
        }
    }
    if (key == TUIK_S && button_state == TUI_BUTTON_PRESS)
    {
        if (tuiWindowHasMinSizeLimits(window))
        {
            tuiWindowSetMinSizeLimits(window, 0, 0);
            printf("Min size limits removed.\n");
        }
        else
        {
            int width = tuiWindowGetFramebufferPixelWidth(window);
            int height = tuiWindowGetFramebufferPixelHeight(window);
            tuiWindowSetMinSizeLimits(window, width, height);
            printf("Min size limits set to ( %d, %d ).\n", width, height);
        }
    }
    if (key == TUIK_D && button_state == TUI_BUTTON_PRESS)
    {
        if (tuiWindowHasMaxSizeLimits(window))
        {
            tuiWindowSetMaxSizeLimits(window, 0, 0);
            printf("Max size limits removed.\n");
        }
        else
        {
            int width = tuiWindowGetFramebufferPixelWidth(window);
            int height = tuiWindowGetFramebufferPixelHeight(window);
            tuiWindowSetMaxSizeLimits(window, width, height);
            printf("Max size limits set to ( %d, %d ).\n", width, height);
        }
    }
}

void window_resize_callback(TuiWindow window, int pixel_width, int pixel_height)
{
    printf("Window resize: ( x = %d, y = %d )\n", pixel_width, pixel_height);
}

int main()
{
    tuiSetDebugErrorCallback(message_callback);

    if (tuiInit() == TUI_FALSE)
    {
        printf("Failed to initialize TUIC.");
        return 1;
    }

    printf("Test resizing a TuiWindow. Press A to fix or unfix the aspect ratio. Press S to set the minimum size limits to the current size or remove the minimum size limits. Press D to set the maximum size limits as the current size or remove the maximum size limits. Resize the window by dragging the edges. The rendered tile dimensions will update dynamically based on the window size. Extra space will be left as white pixels. \n");

    TuiWindowCreateInfo create_info = tuiWindowCreateInfo();
    create_info.resizable = TUI_TRUE;
    TuiWindow window = tuiWindowCreate(256, 256, "window_resizing", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    tuiWindowSetViewportResizeCallback(window, window_resize_callback);

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