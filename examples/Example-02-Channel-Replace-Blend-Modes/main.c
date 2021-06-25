#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <TUIC/tuic.h>
#include <TUIC/backends/opengl33.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t kTilesWide = 100;
const size_t kTilesTall = 80;
const size_t kTileSizeMultiplier = 1;
const size_t kTilePixelWidth = 8;
const size_t kTilePixelHeight = 8;
const char* kWindowTitle = "Example 2: Channel Replace Blend Modes";

const size_t kTuiDetail = TUI_DETAIL_G8_C4_FULL;
const size_t kAtlasType = TUI_ATLAS_GRID;

void TuiMessageCallback(int error_code, const char* msg)
{
    if (error_code == TUI_ERROR_BACKEND_SPECIFIC)
    {
        printf("%s : %s backend message: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
    }
    else
    {
        printf("%s : %s location: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
    }
}

void TestBlendMode(TuiInstance instance, TuiPalette palette, TuiBatch batch, size_t tui_blend_mode, size_t window_width, size_t window_height, const char* sheet_image_file, size_t tui_texture_format)
{
    TuiPanel panel = tuiPanelCreate(instance, window_width, window_height);
    TuiImage image = tuiImageLoad(sheet_image_file, tui_texture_format);
    if (image == NULL)
    {
        printf("Issue loading image file \"%s\". Make sure that it was moved from the content folder to a location the executable can read.\n", sheet_image_file);
        return;
    }
    TuiGlyphAtlas atlas = tuiGlyphAtlasCreateCodepageGrid(instance, image, tui_blend_mode);
    tuiImageDestroy(image);
    tuiPanelDrawBatch(panel, atlas, palette, batch);
    tuiPanelRender(panel);
    image = tuiPanelGetImage(panel, NULL);
    char out_path[128];
    strcpy(out_path, "blend_test_");
    strcat(out_path, sheet_image_file);
    tuiImageSave(image, out_path);
    printf("Saved \"%s\"\n", out_path);
    tuiImageDestroy(image);
    tuiPanelDestroy(panel);
    tuiGlyphAtlasDestroy(atlas);
}

int main()
{
    size_t window_width = kTilesWide * kTilePixelWidth * kTileSizeMultiplier;
    size_t window_height = kTilesTall * kTilePixelHeight * kTileSizeMultiplier;

    //Setup GLFW and GLEW
    if (!glfwInit()) //Even though we wont render to a window, GLFW is still necessary. Opengl wont work without a context, and this is the easiest way to get one.
    {
        printf("GLFW failed to initialize.\n");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    GLFWwindow* window = glfwCreateWindow(window_width, window_height, kWindowTitle, NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window.\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //Set debug callback.
    tuiSetDebugErrorCallback(TuiMessageCallback);

    //Create the TUIC instance.
    TuiInstance instance = tuiOpengl33InstanceCreate(window_width, window_height, ((void*)glfwGetProcAddress)); //The instance should always be the first TUIC object created and the last destroyed.

    //Create the TUIC palette.
    TuiPalette palette = tuiPaletteCreateXterm(instance, 16);

    //Create the batch and fill it with random tiles.
    TuiBatch batch = tuiBatchCreate(kTuiDetail, kTilesWide, kTilesTall);
    time_t t;
    srand((unsigned)time(&t));
    for (int x = 0; x < kTilesWide; x++)
    {
        for (int y = 0; y < kTilesTall; y++)
        {
            tuiBatchSetTile_G8_C4_FULL(batch, x, y, rand() % 256, rand() % 256);
        }
    }

    //set first tile to white fg and black bc with exclamation mark glyph (upper left corner)
    tuiBatchSetTile_G8_C4_FULL(batch, 0, 0, 1, tuiClassicColorCombine(0, 15));

    TestBlendMode(instance, palette, batch, TUI_BLEND_BG_ALPHA, window_width, window_height, "cp_8x8_rgba_bg_alpha.png", 4);
    glfwSwapBuffers(window);
    TestBlendMode(instance, palette, batch, TUI_BLEND_FG_ALPHA, window_width, window_height, "cp_8x8_rgba_fg_alpha.png", 4);
    glfwSwapBuffers(window);
    TestBlendMode(instance, palette, batch, TUI_BLEND_BG_RED, window_width, window_height, "cp_8x8_rgb_bg_red.png", 3);
    glfwSwapBuffers(window);
    TestBlendMode(instance, palette, batch, TUI_BLEND_FG_RED, window_width, window_height, "cp_8x8_rgb_fg_red.png", 3);
    glfwSwapBuffers(window);
    TestBlendMode(instance, palette, batch, TUI_BLEND_BG_GREEN, window_width, window_height, "cp_8x8_rgb_bg_green.png", 3);
    glfwSwapBuffers(window);
    TestBlendMode(instance, palette, batch, TUI_BLEND_FG_GREEN, window_width, window_height, "cp_8x8_rgb_fg_green.png", 3);
    glfwSwapBuffers(window);
    TestBlendMode(instance, palette, batch, TUI_BLEND_BG_BLUE, window_width, window_height, "cp_8x8_rgb_bg_blue.png", 3);
    glfwSwapBuffers(window);
    TestBlendMode(instance, palette, batch, TUI_BLEND_FG_BLUE, window_width, window_height, "cp_8x8_rgb_fg_blue.png", 3);
    glfwSwapBuffers(window);

    //Destroy all TUIC objects
    tuiBatchDestroy(batch);
    tuiPaletteDestroy(palette);
    tuiInstanceDestroy(instance);
    glfwTerminate();
    return 0;
}