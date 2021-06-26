#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <TUIC/tuic.h>
#include <TUIC/backends/opengl33.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


const size_t kTileSizeMultiplier = 4;
const size_t kTilePixelWidth = 8;
const size_t kTilePixelHeight = 8;
const char* kWindowTitle = "Example 4: Dynamic Resizing";
const char* kSheetImageFile = "cp_8x8_rgba_bg_alpha.png";
const size_t kSheetTextureFormat = 4;
const size_t kSheetBlendMode = TUI_BLEND_BG_ALPHA;
const size_t kAtlasMode = TUI_ATLAS_GRID;
const size_t kSheetChannels = 4;
const size_t kTuiDetail = TUI_DETAIL_G8_C4_FULL;

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

typedef struct WindowUserPointer
{
    size_t window_width;
    size_t window_height;
    size_t tiles_wide;
    size_t tiles_tall;
    size_t extra_pixels_wide;
    size_t extra_pixels_tall;
    TuiInstance instance;
    TuiBatch batch;
    TuiPanel panel;
    TuiGlyphAtlas atlas;
    TuiPalette palette;
} WindowUserPointer;

void WindowResizeCallback(GLFWwindow* window, int width, int height)
{
    WindowUserPointer* usr_ptr = glfwGetWindowUserPointer(window);

    tuiInstanceResizeScreen(usr_ptr->instance, width, height);

    usr_ptr->window_width = width;
    usr_ptr->window_height = height;
    size_t new_tiles_wide = usr_ptr->window_width / (kTilePixelWidth * kTileSizeMultiplier);
    size_t new_tiles_tall = usr_ptr->window_height / (kTilePixelHeight * kTileSizeMultiplier);
    usr_ptr->extra_pixels_wide = usr_ptr->window_width % (kTilePixelWidth * kTileSizeMultiplier);
    usr_ptr->extra_pixels_tall = usr_ptr->window_height % (kTilePixelHeight * kTileSizeMultiplier);
    if (new_tiles_wide != usr_ptr->tiles_wide || new_tiles_tall != usr_ptr->tiles_tall)
    {
        usr_ptr->tiles_wide = new_tiles_wide;
        usr_ptr->tiles_tall = new_tiles_tall;

        // If you look in a debugger, you will see upon shrinking the batch memory usage doesn't decrease. If you change the third argument to TUI_FALSE, it will decrease.
        // Reserving extra space on batch resize shrinking can allow for increased performance in some situations.
        tuiBatchResize(usr_ptr->batch, usr_ptr->tiles_wide, usr_ptr->tiles_tall, TUI_TRUE);
        tuiPanelSetSize(usr_ptr->panel, new_tiles_wide * kTilePixelWidth, new_tiles_tall * kTilePixelHeight);
        for (int x = 0; x < usr_ptr->tiles_wide; x++)
        {
            for (int y = 0; y < usr_ptr->tiles_tall; y++)
            {
                int color = tuiClassicColorCombine(x % 256, y % 256);
                tuiBatchSetTile_G8_C4_FULL(usr_ptr->batch, x, y, (x + y) % 256, color);
            }
        }
        tuiPanelClearColor(usr_ptr->panel, 0, 0, 0, 0);
        tuiPanelDrawBatch(usr_ptr->panel, usr_ptr->atlas, usr_ptr->palette, usr_ptr->batch);
    }
}

int main()
{
    WindowUserPointer usr_ptr;
    usr_ptr.window_width = 400;
    usr_ptr.window_height = 600;
    usr_ptr.tiles_wide = usr_ptr.window_width  / (kTilePixelWidth * kTileSizeMultiplier);
    usr_ptr.tiles_tall = usr_ptr.window_height / (kTilePixelHeight * kTileSizeMultiplier);
    usr_ptr.extra_pixels_wide = usr_ptr.window_width % (kTilePixelWidth * kTileSizeMultiplier);
    usr_ptr.extra_pixels_tall = usr_ptr.window_height % (kTilePixelHeight * kTileSizeMultiplier);

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
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    GLFWwindow* window = glfwCreateWindow(usr_ptr.window_width, usr_ptr.window_height, kWindowTitle, NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window.\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); //Change to 1 to cap framerate with vsync.
    glfwSetWindowUserPointer(window, &usr_ptr);

    //Declare TUIC objects
    TuiInstance instance;
    TuiGlyphAtlas atlas;
    TuiPalette palette;
    TuiPanel panel;
    TuiBatch batch;

    //Set debug callback.
    tuiSetDebugErrorCallback(TuiMessageCallback);

    //Create the TUIC instance.
    instance = tuiOpengl33InstanceCreate(usr_ptr.window_width, usr_ptr.window_height, ((void*)glfwGetProcAddress)); //The instance should always be the first TUIC object created and the last destroyed.
    usr_ptr.instance = instance;

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
    usr_ptr.atlas = atlas;
    tuiImageDestroy(image);

    //Create the palette
    palette = tuiPaletteCreateXterm(instance, 16);
    usr_ptr.palette = palette;

    //Create the panel
    panel = tuiPanelCreate(instance, usr_ptr.window_width, usr_ptr.window_height);
    usr_ptr.panel = panel;

    //Create the batch
    batch = tuiBatchCreate(kTuiDetail, usr_ptr.tiles_wide, usr_ptr.tiles_tall);
    usr_ptr.batch = batch;
    for (int x = 0; x < usr_ptr.tiles_wide; x++)
    {
        for (int y = 0; y < usr_ptr.tiles_tall; y++)
        {
            int color = tuiClassicColorCombine(x % 256, y % 256);
            tuiBatchSetTile_G8_C4_FULL(batch, x, y, (x + y) % 256, color);
        }
    }

    //Render the batch to the panel
    tuiPanelDrawBatch(panel, atlas, palette, batch);

    glfwSetFramebufferSizeCallback(window, WindowResizeCallback);

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

        tuiInstanceClearColor(instance, 0, 0, 128, 255);
        tuiPanelDrawBatch(panel, atlas, palette, batch);
        tuiPanelRenderTransformed(panel, 0, usr_ptr.window_width - usr_ptr.extra_pixels_wide, 0, usr_ptr.window_height - usr_ptr.extra_pixels_tall);

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
