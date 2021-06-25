#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <TUIC/tuic.h>
#include <TUIC/backends/opengl33.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const size_t kTilesWide = 100;
const size_t kTilesTall = 80;
const size_t kTileSizeMultiplier = 1;
const size_t kTilePixelWidth = 8;
const size_t kTilePixelHeight = 8;
const char* kWindowTitle = "Example 6: Simple Topdown Character";

const char* kSheetImageFile = "cp_8x8_rgba_bg_alpha.png";
const size_t kSheetTextureFormat = 4;
const size_t kSheetBlendMode = TUI_BLEND_BG_ALPHA;
const size_t kAtlasMode = TUI_ATLAS_GRID;
const size_t kSheetChannels = 4;

const size_t kTuiDetail1 = TUI_DETAIL_G8_C4_FULL;
const size_t kTuiDetail2 = TUI_DETAIL_G8_C4_SPARSE;

typedef struct PlayerInfo
{
    int player_x;
    int player_y;
} PlayerInfo;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    PlayerInfo* info = glfwGetWindowUserPointer(window);

    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_UP)
        {
            info->player_y--;
        }
        else if (key == GLFW_KEY_DOWN)
        {
            info->player_y++;
        }
        else if (key == GLFW_KEY_LEFT)
        {
            info->player_x--;
        }
        else if (key == GLFW_KEY_RIGHT)
        {
            info->player_x++;
        }
    }
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
    TuiPanel panel1;
    TuiPanel panel2;
    TuiBatch batch1;
    TuiBatch batch2;

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
    uint8_t ground_color = tuiClassicColorCombine(15, 0);
    uint8_t player_color = tuiClassicColorCombine(13, 8);

    //Create the panel 1
    panel1 = tuiPanelCreate(instance, window_width, window_height);

    //Create the batch 1
    batch1 = tuiBatchCreate(kTuiDetail1, kTilesWide, kTilesTall);

    //Fill the batch 1 with data.
    time_t t;
    srand((unsigned)time(&t));
    for (int x = 0; x < kTilesWide; x++)
    {
        for (int y = 0; y < kTilesTall; y++)
        {
            tuiBatchSetTile_G8_C4_FULL(batch1, x, y, rand() % 256, ground_color);
        }
    }

    //Render the batch 1 to the panel 1
    tuiPanelDrawBatch(panel1, atlas, palette, batch1);

    //Create the panel 2
    panel2 = tuiPanelCreate(instance, window_width, window_height);

    //Create the batch 2
    batch2 = tuiBatchCreate(kTuiDetail2, kTilesWide, kTilesTall);

    //Render the batch 1 to the panel 1
    tuiPanelDrawBatch(panel2, atlas, palette, batch2);

    PlayerInfo info;
    info.player_x = 5;
    info.player_y = 5;

    glfwSetWindowUserPointer(window, &info);
    glfwSetKeyCallback(window, KeyCallback);

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

        tuiBatchClear(batch2);
        tuiBatchSetTile_G8_C4_SPARSE(batch2, info.player_x, info.player_y, 2, player_color);

        tuiPanelClearColor(panel2, 0, 0, 0, 0);
        tuiPanelDrawBatch(panel2, atlas, palette, batch2);
        tuiPanelRender(panel1);
        tuiPanelRender(panel2);

        glfwSwapBuffers(window); //swap the window buffers
    }

    //Destroy all TUIC objects
    tuiPanelDestroy(panel1);
    tuiBatchDestroy(batch1);
    tuiPanelDestroy(panel2);
    tuiBatchDestroy(batch2);
    tuiPaletteDestroy(palette);
    tuiGlyphAtlasDestroy(atlas);
    tuiInstanceDestroy(instance); //TuiInstance must always be created first and destroyed last.
    glfwTerminate();
    return 0;
}
