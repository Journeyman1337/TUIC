
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

void key_callback(TuiWindow window, TuiKey key, int scancode, TuiButtonState button_state, TuiKeyMod key_mod)
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
    }
}

int main()
{
    int tiles_wide = 50;
    int tiles_tall = 50;
    int glyph_pixel_dimensions = 8;
    int size_multiplier = 2;
    int window_width = tiles_wide * glyph_pixel_dimensions * size_multiplier;
    int window_height = tiles_tall * glyph_pixel_dimensions * size_multiplier;

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
    custom_cursor_image  = tuiImageLoad("custom_cursor.png", 0);

    /* Initialize the current cursor. */
    current_cursor = tuiCursorCreateStandard(current_cursor_shape);

    /* Create the window. */
    const char* window_title = "Example XX";
    TuiWindow window = tuiWindowCreate(window_width, window_height, window_title, NULL);

    /* Set the window key callback. */
    tuiWindowSetKeyboardKeyCallback(window, key_callback);

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
