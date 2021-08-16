/* Test updating a texture after it was created. */

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

    printf("Testing updating a TuiTexture after it is created.");

    TuiImage sushi = tuiImageCreatePNG("sushi.png");
    TuiTexture texture = tuiTextureCreateImage(sushi, TUI_FILTER_POINT);
    tuiImageDestroy(sushi);
    sushi = TUI_NULL;

    TuiWindow window = tuiWindowCreate(256, 256, "texture_updating", TUI_NULL);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);

    tuiWindowClearColor(window, 255, 255, 255, 255); // white clear color
    tuiWindowDrawTexture(window, texture);
    printf("Texture loaded from png.\n");
    frame(window);

    TuiImage fill_red = tuiImageCreateColor(256, 256, 3, 255, 0, 0, 255); // red filled image
    tuiTextureSetImage(texture, fill_red);
    tuiImageDestroy(fill_red);
    fill_red = TUI_NULL;

    tuiWindowClearColor(window, 255, 255, 255, 255); // white clear color
    tuiWindowDrawTexture(window, texture);
    printf("Texture updated to red fill color with size change.\n");
    frame(window);

    TuiImage fill_green = tuiImageCreateColor(256, 256, 3, 0, 255, 0, 255); // green filled image
    tuiTextureSetImage(texture, fill_green);
    tuiImageDestroy(fill_green);
    fill_green = TUI_NULL;

    tuiWindowClearColor(window, 255, 255, 255, 255); // white clear color
    tuiWindowDrawTexture(window, texture);
    printf("Texture updated to green fill color with no size change.\n");
    frame(window);

    tuiTextureDestroy(texture);
    texture = TUI_NULL;
    tuiWindowDestroy(window);
    window = TUI_NULL;

    tuiTerminate();
    return 0;
}