#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <TUIC/tuic.h>
#include <TUIC/backends/opengl33.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



const size_t kTilesWide = 50;
const size_t kTilesTall = 40;
const size_t kTileSizeMultiplier = 3;
const size_t kTilePixelWidth = 8;
const size_t kTilePixelHeight = 8;
const char* kWindowTitle = "Example 7: Mouse Input";

const char* kSheetImageFile = "cp_8x8_rgba_bg_alpha.png";
const size_t kSheetTextureFormat = 4;
const size_t kSheetBlendMode = TUI_BLEND_BG_ALPHA;
const size_t kAtlasMode = TUI_ATLAS_GRID;
const size_t kSheetChannels = 4;

const size_t kTuiDetail = TUI_DETAIL_G8_C4_SPARSE;

struct MousePosData
{
    int mouse_tile_x;
    int mouse_tile_y;
} typedef MousePosData;

void MousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
    MousePosData* dat = glfwGetWindowUserPointer(window);

    double tile_x = xpos / (kTilePixelWidth * kTileSizeMultiplier);
    double tile_y = ypos / (kTilePixelHeight * kTileSizeMultiplier);
    dat->mouse_tile_x = tile_x;
    dat->mouse_tile_y = tile_y;
}

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
int main()
{
    size_t window_width = kTilesWide * kTilePixelWidth * kTileSizeMultiplier;
    size_t window_height = kTilesTall * kTilePixelHeight * kTileSizeMultiplier;

    //Setup GLFW and GLEW
    if (!glfwInit())
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
    glfwSwapInterval(0); //Change to 1 to cap framerate with vsync.

    //Declare TUIC objects
    TuiInstance instance;
    TuiGlyphAtlas atlas;
    TuiPalette palette;
    TuiPanel panel;
    TuiBatch batch;

    //Set debug callback.
    tuiSetDebugErrorCallback(TuiMessageCallback);

    //Create the TUIC instance.
    instance = tuiOpengl33InstanceCreate(window_width, window_height, ((void*)glfwGetProcAddress)); //The instance should always be the first TUIC object created and the last destroyed.

    /* Load the atlas image */
    TuiImage image = tuiImageLoad(kSheetImageFile, kSheetChannels);
    if (image == NULL)
    {
        printf("Issue loading image file. Make sure that it was moved from the content folder to a location the executable can read. You need to do this manually.\n");
        glfwTerminate();
        return -1;
    }

    /* Create the Glyph Atlas */
    atlas = tuiGlyphAtlasCreateCodepageGrid(instance, image, kSheetBlendMode);
    tuiImageDestroy(image);

    //Create the palette
    palette = tuiPaletteCreateXterm(instance, 16);

    //Create the panel
    panel = tuiPanelCreate(instance, window_width, window_height);

    //Create the batch
    batch = tuiBatchCreate(kTuiDetail, kTilesWide, kTilesTall);

    MousePosData mouse_pos_dat;
    mouse_pos_dat.mouse_tile_x = 0;
    mouse_pos_dat.mouse_tile_y = 0;
    glfwSetWindowUserPointer(window, &mouse_pos_dat);
    glfwSetCursorPosCallback(window, MousePosCallback);

    //fps tracking setup
    double last_time = 0;
    int nbFrame = 0;

    int color = tuiClassicColorCombine(14, 0);

    //Render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents(); //handle input events and call callback functions

        //Print fps to console
        double currentTime = glfwGetTime();
        double delta = currentTime - last_time;
        nbFrame++;
        if (delta >= 1.0) { // If last fps print was more than 1 sec ago

            double fps = nbFrame / delta;
            printf("%f FPS\n", fps);
            nbFrame = 0;
            last_time = currentTime;
        }

        tuiBatchClear(batch);
        if (mouse_pos_dat.mouse_tile_x >= 0 && mouse_pos_dat.mouse_tile_x < kTilesWide && mouse_pos_dat.mouse_tile_y >= 0 && mouse_pos_dat.mouse_tile_y < kTilesTall)
        {
            tuiBatchSetTile_G8_C4_SPARSE(batch, mouse_pos_dat.mouse_tile_x, mouse_pos_dat.mouse_tile_y, 255, color);
        }

        tuiPanelDrawBatch(panel, atlas, palette, batch);
        tuiPanelRender(panel);
        
        glfwSwapBuffers(window); //swap the window buffers
    }

    //Destroy all TUIC objects
    tuiPanelDestroy(panel);
    tuiBatchDestroy(batch);
    tuiPaletteDestroy(palette);
    tuiGlyphAtlasDestroy(atlas);
    tuiInstanceDestroy(instance); //TuiInstance must always be created first and destroyed last.
    glfwTerminate();
    return 0;
}