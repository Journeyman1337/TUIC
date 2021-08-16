/* Test resizing a TuiPanel. */

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

    printf("Test resizing a TuiPanel.\n");

    TuiImage sushi = tuiImageCreatePNG("sushi.png");
    TuiTexture texture = tuiTextureCreateImage(sushi, TUI_FILTER_BILINEAR);
    tuiImageDestroy(sushi);
    sushi = TUI_NULL;

    TuiWindow window = tuiWindowCreate(512, 512, "panel_resizing", TUI_NULL);
    tuiWindowSetKeyboardKeyCallback(window, key_callback);
    
    TuiPanel panel = tuiPanelCreate(256, 256);
    tuiPanelClearColor(panel, 255, 255, 255, 255); // white clear color
    tuiPanelDrawTexture(panel, texture);
    tuiWindowDrawPanel(window, panel);
    printf("256x256\n");
    frame(window);

    tuiPanelSetPixelDimensions(panel, 128, 128);
    tuiPanelClearColor(panel, 255, 255, 255, 255); // white clear color
    tuiPanelDrawTexture(panel, texture);
    tuiWindowDrawPanel(window, panel);
    printf("128x128\n");
    frame(window);

    tuiPanelSetPixelDimensions(panel, 32, 32);
    tuiPanelClearColor(panel, 255, 255, 255, 255); // white clear color
    tuiPanelDrawTexture(panel, texture);
    tuiWindowDrawPanel(window, panel);
    printf("32x32\n");
    frame(window);

    tuiPanelSetPixelDimensions(panel, 16, 16);
    tuiPanelClearColor(panel, 255, 255, 255, 255); // white clear color
    tuiPanelDrawTexture(panel, texture);
    tuiWindowDrawPanel(window, panel);
    printf("16x16\n");
    frame(window);

    tuiPanelSetPixelDimensions(panel, 8, 8);
    tuiPanelClearColor(panel, 255, 255, 255, 255); // white clear color
    tuiPanelDrawTexture(panel, texture);
    tuiWindowDrawPanel(window, panel);
    printf("8x8\n");
    frame(window);

    tuiPanelSetPixelDimensions(panel, 4, 4);
    tuiPanelClearColor(panel, 255, 255, 255, 255); // white clear color
    tuiPanelDrawTexture(panel, texture);
    tuiWindowDrawPanel(window, panel);
    printf("4x4\n");
    frame(window);

    tuiPanelSetPixelDimensions(panel, 2, 2);
    tuiPanelClearColor(panel, 255, 255, 255, 255); // white clear color
    tuiPanelDrawTexture(panel, texture);
    tuiWindowDrawPanel(window, panel);
    printf("2z2\n");
    frame(window);

    tuiTextureDestroy(texture);
    texture = TUI_NULL;
    tuiPanelDestroy(panel);
    panel = TUI_NULL;
    tuiWindowDestroy(window);
    window = TUI_NULL;

    tuiTerminate();
    return 0;
}