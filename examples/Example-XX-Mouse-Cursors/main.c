
#include <TUIC/tuic.h>

#include <stdio.h>

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

static TuiImage custom_cursor_image = NULL;
static TuiCursorShape current_cursor_shape = TUI_CURSOR_SHAPE_FIRST;
static TuiCursor current_cursor = NULL;

TuiCursorShape increment_cursor_shape(TuiCursorShape current_shape)
{
    if (current_shape != 0 && current_shape < TUI_CURSOR_SHAPE_LAST)
    {
        current_shape = current_shape +  1;
    }
    else if (current_shape == TUI_CURSOR_SHAPE_LAST)
    {
        return 0;
    }
    else if (current_shape == 0)
    {
        current_shape = TUI_CURSOR_SHAPE_FIRST;
    }
    if (tuiCursorShapeIsSupported(current_shape) == TUI_FALSE)
    {
        return increment_cursor_shape(current_shape);
    }
    else
    {
        return current_shape;
    }
}

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState button_state, TuiKeyboardKeyMod key_mod)
{
    if (key == TUIK_C && button_state == TUI_BUTTON_PRESS)
    {
        current_cursor_shape = increment_cursor_shape(current_cursor_shape);
        if (current_cursor_shape == 0)
        {
            TuiCursor next_cursor = tuiCursorCreate(custom_cursor_image, 8, 8);
            tuiWindowSetCursor(window, next_cursor);
            tuiCursorDestroy(current_cursor);
            current_cursor = next_cursor;
        }
        else
        {
            TuiCursor next_cursor = tuiCursorCreateStandard(current_cursor_shape);
            tuiWindowSetCursor(window, next_cursor);
            tuiCursorDestroy(current_cursor);
            current_cursor = next_cursor;
        }
        printf("Cursor changed to %s!\n", (current_cursor_shape == 0) ? "custom" : tuiCursorShapeToString(current_cursor_shape));
    }
}

int main()
{
    int window_width = 500;
    int window_height = 500;

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

    /* Load the custom cursor image. */
    int expected_channel_count = 4;
    custom_cursor_image  = tuiImageLoad("custom_cursor.png", expected_channel_count);

    /* Initialize the current cursor. */
    current_cursor = tuiCursorCreateStandard(current_cursor_shape);

    /* Create the window. */
    const char* window_title = "Example XX";
    TuiWindow window = tuiWindowCreate(window_width, window_height, window_title, NULL);

    /* Set the window key callback. */
    tuiWindowSetKeyboardKeyCallback(window, key_callback);

    /* Print prompt to console. */
    printf("Press C to change mouse cursors.\n");

    //Render loop
    while (tuiWindowShouldClose(window) == TUI_FALSE)
    {
        tuiPollEvents(); //handle input events and call callback function.

        tuiWindowSwapBuffers(window); //swap the window buffers
    }

    /* Destroy all remaining TUIC objects */
    tuiWindowDestroy(window);
    window = NULL;
    tuiCursorDestroy(current_cursor);
    current_cursor = NULL;

    tuiTerminate();
    return 0;
}
