/* Test creating TuiTexture objects with each creation function. */

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

    printf("Create TuiTexture with each creation function and draw them to a window.\n");
    
    TuiImage sushi = tuiImageCreatePNG("sushi.png");
    TuiTexture texture_1 = tuiTextureCreateImage(sushi, TUI_FILTER_POINT);
    TuiTexture texture_2 = tuiTextureCreateRawPixels(tuiImageGetPixelWidth(sushi), tuiImageGetPixelHeight(sushi), tuiImageGetChannelCount(sushi), tuiImageGetPixels(sushi), TUI_FILTER_POINT);
    tuiImageDestroy(sushi);
    sushi = TUI_NULL;

    TuiWindow window = tuiWindowCreate(512, 512, "panel_resizing", TUI_NULL);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);

    tuiWindowClearColor(window, 255, 255, 255, 255); // white clear color
    tuiWindowDrawTexture(window, texture_1);
    printf("tuiTextureCreateImage\n");
    frame(window);

    tuiWindowClearColor(window, 255, 255, 255, 255); // white clear color
    tuiWindowDrawTexture(window, texture_2);
    printf("tuiTextureCreateRawPixels\n");
    frame(window);

    tuiTextureDestroy(texture_1);
    texture_1 = TUI_NULL;
    tuiTextureDestroy(texture_2);
    texture_2 = TUI_NULL;
    tuiWindowDestroy(window);
    window = TUI_NULL;

    tuiTerminate();
    return 0;
}