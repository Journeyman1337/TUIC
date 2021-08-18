/* Test a TuiWindow created with a custom TuiWindowCreateInfo struct. */

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
    while (sNextFrame == TUI_FALSE)
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

void resize_callback(TuiWindow window, int pixel_width, int pixel_height)
{
    printf("Window resize: Viewport( x = %d, y = %d ) Framebuffer( x = %d, y = %d) \n", pixel_width, pixel_height, tuiWindowGetFramebufferPixelWidth(window), tuiWindowGetFramebufferPixelHeight(window));
}


int main()
{
    tuiSetDebugErrorCallback(message_callback);

    if (tuiInit() == TUI_FALSE)
    {
        printf("Failed to initialize TUIC.");
        return 1;
    }

    TuiWindowCreateInfo create_info = tuiWindowCreateInfo();
    create_info.center_cursor = TUI_TRUE;
    TuiWindow window = tuiWindowCreate(256, 256, "center cursor", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    frame(window);
    tuiWindowDestroy(window);
    window = TUI_NULL;

    create_info = tuiWindowCreateInfo();
    create_info.decorated = TUI_FALSE;
    window = tuiWindowCreate(256, 256, "not decorated", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    frame(window);
    tuiWindowDestroy(window);
    window = TUI_NULL;

    create_info = tuiWindowCreateInfo();
    create_info.focused = TUI_FALSE;
    window = tuiWindowCreate(256, 256, "not focused", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    frame(window);
    tuiWindowDestroy(window);
    window = TUI_NULL;

    create_info = tuiWindowCreateInfo();
    create_info.focus_on_show = TUI_FALSE;
    window = tuiWindowCreate(256, 256, "not focus on show", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    tuiWindowHide(window);
    tuiWindowShow(window);
    frame(window);
    tuiWindowDestroy(window);
    window = TUI_NULL;

    create_info = tuiWindowCreateInfo();
    create_info.framebuffer_match_viewport_size = TUI_FALSE;
    create_info.resizable = TUI_TRUE;
    create_info.unmatching_framebuffer_pixel_width = 512;
    create_info.unmatching_framebuffer_pixel_height = 512;
    window = tuiWindowCreate(256, 256, "resizable unmatching framebuffer size", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    tuiWindowSetViewportResizeCallback(window, resize_callback);
    frame(window);
    tuiWindowDestroy(window);
    window = TUI_NULL;

    create_info = tuiWindowCreateInfo();
    create_info.fullscreen = TUI_TRUE;
    window = tuiWindowCreate(256, 256, "fullscreen", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    frame(window);
    tuiWindowDestroy(window);
    window = TUI_NULL;

    create_info = tuiWindowCreateInfo();
    create_info.maximized = TUI_TRUE;
    window = tuiWindowCreate(256, 256, "maximized", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    frame(window);
    tuiWindowDestroy(window);
    window = TUI_NULL;

    create_info = tuiWindowCreateInfo();
    create_info.topmost = TUI_TRUE;
    window = tuiWindowCreate(256, 256, "topmost", &create_info);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    frame(window);
    tuiWindowDestroy(window);
    window = TUI_NULL;

    tuiTerminate();
    return 0;
}