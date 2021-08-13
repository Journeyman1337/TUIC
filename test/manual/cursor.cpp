/* Test mouse custom and standard TuiCursor objects and use all cursor functions. */

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

int main()
{
    tuiSetDebugErrorCallback(message_callback);

    if (tuiInit() == TUI_FALSE)
    {
        printf("Failed to initialize TUIC.");
        return 1;
    }

    printf("Test all cursor creation functions and test all cursor shapes that are supported on the current platform. Press spacebar to test the next cursor.\n");

    TuiWindow window = tuiWindowCreate(256, 256, "cursor", TUI_NULL);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);

    TuiImage custom_cursor_image = tuiImageCreatePNG("custom_cursor.png");

    TuiCursor cur_cursor = tuiCursorCreateImage(custom_cursor_image, 8, 8);
    tuiWindowSetCursor(window, cur_cursor);
    printf("tuiImageCreatePNG\n");
    frame(window);
    tuiCursorDestroy(cur_cursor);
    cur_cursor = TUI_NULL;

    cur_cursor = tuiCursorCreateRawPixels(tuiImageGetPixelWidth(custom_cursor_image), tuiImageGetPixelHeight(custom_cursor_image), tuiImageGetPixels(custom_cursor_image), 8, 8);
    tuiWindowSetCursor(window, cur_cursor);
    printf("tuiCursorCreateRawPixels\n");
    frame(window);
    tuiCursorDestroy(cur_cursor);
    cur_cursor = TUI_NULL;

    tuiImageDestroy(custom_cursor_image);
    custom_cursor_image = TUI_NULL;

    for (size_t cursor_shape_i = TUI_CURSOR_SHAPE_FIRST; cursor_shape_i <= TUI_CURSOR_SHAPE_LAST; cursor_shape_i++)
    {
        TuiCursorShape cursor_shape = (TuiCursorShape)cursor_shape_i;
        const char* cursor_shape_name = tuiCursorShapeToString(cursor_shape);
        printf("%s: ", cursor_shape_name);
        if (tuiCursorShapeSupported(cursor_shape) == TUI_TRUE)
        {
            printf("Shape is supported!\n");
            cur_cursor = tuiCursorCreateShape(cursor_shape);
            tuiWindowSetCursor(window, cur_cursor);
            frame(window);
            tuiCursorDestroy(cur_cursor);
            cur_cursor = TUI_NULL;
        }
        else
        {
            printf("Shape is not supported! skipping...\n");
        }
    }

    tuiWindowDestroy(window);
    window = TUI_NULL;

    tuiTerminate();

    return 0;
}