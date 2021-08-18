/* Test saving screenshots from a TuiWindow. */

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

int main()
{
    tuiSetDebugErrorCallback(message_callback);

    if (tuiInit() == TUI_FALSE)
    {
        printf("Failed to initialize TUIC.");
        return 1;
    }

    printf("Saving a screenshot image from a TuiWindow to test_window.png\n");

    TuiImage sushi = tuiImageCreatePNG("sushi.png");
    TuiTexture texture = tuiTextureCreateImage(sushi, TUI_FILTER_BILINEAR);
    tuiImageDestroy(sushi);
    sushi = TUI_NULL;
    TuiWindow window = tuiWindowCreate(256, 256, "window_screenshots", TUI_NULL);
    tuiWindowClearColor(window, 255, 255, 255, 255); // white clear color
    tuiWindowDrawTexture(window, texture);
    TuiImage out_sushi = tuiWindowGetImage(window);
    tuiImageSavePNG(out_sushi, "test_window.png");
    tuiImageDestroy(out_sushi);
    out_sushi = TUI_NULL;
    tuiTextureDestroy(texture);
    texture = TUI_NULL;
    tuiWindowDestroy(window);
    window = TUI_NULL;

    tuiTerminate();
    return 0;
}
