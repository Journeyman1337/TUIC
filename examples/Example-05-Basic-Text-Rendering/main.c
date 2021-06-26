#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <TUIC/tuic.h>
#include <TUIC/backends/opengl33.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const size_t kTilesWide = 100;
const size_t kTilesTall = 80;
const size_t kTileSizeMultiplier = 1;
const size_t kTilePixelWidth = 8;
const size_t kTilePixelHeight = 8;
const char* kWindowTitle = "Example 5: Basic Text Rendering";
const char* kSheetImageFile = "cp_8x8_rgba_bg_alpha.png";
const size_t kSheetTextureFormat = 4;
const size_t kSheetBlendMode = TUI_BLEND_BG_ALPHA;
const size_t kAtlasMode = TUI_ATLAS_GRID;
const size_t kSheetChannels = 4;
const size_t kTuiDetail = TUI_DETAIL_G8_C4_FULL;

const char* kString1 = "This is an example of rendered text.";
const char* kString2 = "This rendering method crude but it works.";
size_t kXStart = 20;
size_t kYStart1 = 20;
size_t kYStart2 = 22;

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

    uint8_t color = tuiClassicColorCombine(15, 0);
    for (int x = 0; kString1[x] != '\0'; x++)
    {
        tuiBatchSetTile_G8_C4_FULL(batch, kXStart + x, kYStart1, kString1[x], color);
    }

    for (int x = 0; kString2[x] != '\0'; x++)
    {
        tuiBatchSetTile_G8_C4_FULL(batch, kXStart + x, kYStart2, kString2[x], color);
    }


    //Render the batch to the panel
    tuiPanelDrawBatch(panel, atlas, palette, batch);

    //Render panel to a png image (BasicTextRendering.png)
    image = tuiPanelGetImage(panel, NULL);
    tuiImageSave(image, "BasicTextRendering.png");
    tuiImageDestroy(image);

    //fps tracking setup
    double last_time = 0;
    int nbFrame = 0;

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