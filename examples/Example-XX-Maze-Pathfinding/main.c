
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

int main()
{
    int tiles_wide = 50;
    int tiles_tall = 50;
    int glyph_pixel_dimensions = 8;
    int size_multiplier = 2;
    int window_width = tiles_wide * glyph_pixel_dimensions * size_multiplier;
    int window_height = tiles_tall * glyph_pixel_dimensions * size_multiplier;

    if (tuiInit(TUI_FALSE) == TUI_FALSE)
    {
        printf("Failed to initialize TUIC.");
        return -1;
    }

    /* Tell TUIC to send all debug messages to our message callback (the function we implemented above main). */
    tuiSetDebugErrorCallback(TuiMessageCallback);

    /* Create the window create info */
    TuiWindowCreateInfo window_create_info = tuiWindowCreateInfo();
    window_create_info.center_cursor = TUI_TRUE;

    /* Create the TUIC instance. */
    const char* window_title = "Example 1";
    TuiWindow window = tuiWindowCreate(window_width, window_height, window_title, &window_create_info);

    /* Load the atlas image */
    const char* atlas_image_name = "cp_8x8_rgb_fg_green.png";
    int atlas_image_expected_channel_count = 3;
    TuiImage atlas_image = tuiImageLoad(atlas_image_name, atlas_image_expected_channel_count);
    if (atlas_image == NULL)
    {
        printf("Issue loading image file. Make sure that it was moved from the content folder to a location the executable can read. You need to do this manually.\n");
        tuiWindowDestroy(window);
        window = NULL;
        tuiTerminate();
        return -1;
    }

    /* Create the Glyph Atlas */
    TuiBlendMode blend_mode = TUI_BLEND_FG_GREEN;
    TuiAtlas atlas = tuiAtlasCreateCodepageGrid(atlas_image, blend_mode);
    tuiImageDestroy(atlas_image);
    atlas_image = NULL;

    /* Create the palette */
    int palette_color_count = 16;
    TuiPalette palette = tuiPaletteCreateXterm(palette_color_count);

    /* Create the panel (graphics framebuffer) */
    TuiPanel panel = tuiPanelCreate(window_width, window_height);

    /* Create the batch (tile rendering data container) */
    TuiDetailMode detail_mode = TUI_DETAIL_G8_C4_FULL; // same as (TUI_GLYPH_FLAG_G8 | TUI_COLOR_FLAG_C4 | TUI_LAYOUT_FLAG_FULL)
    TuiBatch batch = tuiBatchCreate(detail_mode, tiles_wide, tiles_tall);

    //Fill the batch with tile data.
    for (int x = 0; x < tiles_wide; x++)
    {
        for (int y = 0; y < tiles_tall; y++)
        {
            uint8_t foreground_color_palette_id = x % 16;
            uint8_t background_color_palette_id = 16 - (y % 16);
            uint8_t two_color_byte = tuiClassicColorCombine(foreground_color_palette_id, background_color_palette_id);
            uint8_t glyph_id = (x + y) % 256;
            tuiBatchSetTile_G8_C4_FULL(batch, x, y, glyph_id, two_color_byte);
        }
    }

    //Render the batch to the panel
    tuiPanelDrawBatch(panel, atlas, palette, batch);

    //Destroy the batch. We rendered it to the panel so we can render the panel instead of re-rendering the batch every frame.
    tuiBatchDestroy(batch);
    batch = NULL;

    //Render panel to a png image file
    TuiImage out_image = tuiPanelGetImage(panel, NULL);
    const char* out_image_name = "example-1-screenshot.png";
    tuiImageSave(out_image, out_image_name);
    tuiImageDestroy(out_image);
    out_image = NULL;

    //fps tracking setup
    double last_time = 0;
    int nbFrame = 0;

    //Render loop
    while (tuiWindowShouldClose(window) == TUI_FALSE)
    {
        tuiPollEvents(); //handle input events and call callback functions

        /* Print fps to console */
        double currentTime = tuiGetTime();
        double delta = currentTime - last_time;
        nbFrame++;
        if (delta >= 1.0) { // If last fps print was more than 1 sec ago

            double fps = nbFrame / delta;
            printf("%f FPS\n", fps);
            nbFrame = 0;
            last_time = currentTime;
        }

        tuiWindowDrawPanel(window, panel);
        //tuiPanelRenderTransformed(panel, window_width/2, window_width, window_height/2, window_height); //Use this function instead to render the panel within the given rect sides.

        tuiWindowFrame(window); //swap the window buffers
    }

    /* Destroy all remaining TUIC objects */
    tuiPanelDestroy(panel);
    panel = NULL;
    tuiPaletteDestroy(palette);
    palette = NULL;
    tuiAtlasDestroy(atlas);
    atlas = NULL;
    tuiWindowDestroy(window); //The instance must always be created first and destroyed last.
    window = NULL;

    tuiTerminate();
    return 0;
}