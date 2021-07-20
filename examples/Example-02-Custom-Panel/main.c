
#include <TUIC/tuic.h>

#include <stdio.h>
#include <string.h>

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

const size_t kTilesWide = 50;
const size_t kTilesTall = 50;
const size_t kTilePixelWidth = 16;
const size_t kTilePixelHeight = 16;

int main()
{
    int window_width = kTilesWide * kTilePixelWidth;
    int window_height = kTilesTall * kTilePixelHeight;

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

    /* Load the atlas image */
    const char* atlas_image_name = "kenny_roguelikeSheet_transparent.png";
    int atlas_image_expected_channel_count = 4;
    TuiImage atlas_image = tuiImageLoad(atlas_image_name, atlas_image_expected_channel_count);
    if (atlas_image == NULL)
    {
        printf("Issue loading image file. Make sure that it was moved from the content folder to a location the executable can read. You need to do this manually.\n");
        tuiTerminate();
        return -1;
    }

    /* Create the atlas */
    const uint16_t glyphs_tall = 31;
    const uint16_t glyphs_wide = 53;
    const uint16_t glyph_count = glyphs_tall * glyphs_wide;
    const uint16_t glyph_width = 16;
    const uint16_t glyph_height = 16;
    uint16_t* glyph_bounding_boxes = tuiAllocate(sizeof(size_t) * glyph_count * 4);
    {
        size_t i = 0;
        for (uint16_t y = 0; y < glyphs_tall; y++)
        {
            for (uint16_t x = 0; x < glyphs_wide; x++)
            {
                glyph_bounding_boxes[i++] = (x * glyph_width) + x;                      //left x pixel
                glyph_bounding_boxes[i++] = (x * glyph_width) + (x + glyph_width);      //right x pixel
                glyph_bounding_boxes[i++] = (y * glyph_height) + (y + glyph_height);    //top y pixel
                glyph_bounding_boxes[i++] = (y * glyph_height) + y;                     //bottom y pixel
            }
        }
    }
    TuiBlendMode blend_mode = TUI_BLEND_BG_ALPHA;
    TuiAtlas atlas = tuiAtlasCreate(atlas_image, glyph_count, glyph_bounding_boxes, blend_mode);
    tuiImageDestroy(atlas_image);
    atlas_image = NULL;
    tuiFree(glyph_bounding_boxes);
    glyph_bounding_boxes = NULL;

    /* Create the batch */
    TuiDetailMode detail_mode = TUI_DETAIL_G16_C24_FULL;
    TuiBatch batch = tuiBatchCreate(detail_mode, kTilesTall, kTilesWide);

    /* Fill the batch with data */
    for (int tile_x = 0; tile_x < kTilesWide; tile_x++)
    {
        for (int tile_y = 0; tile_y < kTilesTall; tile_y++)
        {
            int glyph = (tile_x * tile_y) % glyph_count;
            uint8_t fg_r = (tile_x * 4) % 255;
            uint8_t fg_g = (tile_y * 2) % 255;
            uint8_t fg_b = (tile_x * tile_y) % 255;
            uint8_t bg_r = 0;
            uint8_t bg_g = 0;
            uint8_t bg_b = 0;
            tuiBatchSetTile_G16_C24_FULL(batch, tile_x, tile_y, glyph, fg_r, fg_g, fg_b, bg_r, bg_g, bg_b);
        }
    }

    /* Create the window. */
    const char* window_title = "Example XX";
    TuiWindow window = tuiWindowCreate(window_width, window_height, window_title, NULL);

    /* Render initial clear color to window. */
    tuiWindowClearColor(window, 0, 0, 0, 255); //black

    /* Draw batch to window */
    TuiPalette palette = NULL; //no palette for this detail mode
    tuiWindowDrawBatch(window, atlas, palette, batch);

    /* Print prompt to console */
    printf("TUI rendered using a cutom glyph atlas and 24 bit fullcolor.");

    //Render loop
    while (tuiWindowShouldClose(window) == TUI_FALSE)
    {
        tuiPollEvents(); //handle input events and call callback function.

        tuiWindowFrame(window); //swap the window buffers
    }


    /* Destroy all remaining TUIC objects */
    tuiWindowDestroy(window);
    window = NULL;
    tuiAtlasDestroy(atlas);
    atlas = NULL;
    tuiBatchDestroy(batch);
    batch = NULL;

    tuiTerminate();
    return 0;
}
