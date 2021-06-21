#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <TUIC/tuic.h>
#include <TUIC/backends/opengl33.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const size_t kWindowWidth = 600;
const size_t kWindowHeight = 800;
const size_t kScreenWidth = 600 - 30;
const size_t kScreenHeight = 800 - 30;
const char* kWindowTitle = "Example 3: Panel Transformed Rendering";

const char* kSheetImageFile1 = "cp_8x8_rgba_bg_alpha.png";
const size_t kSheetTextureFormat1 = 4;
const size_t kSheetBlendMode1 = TUI_BLEND_BG_ALPHA;
const size_t kAtlasMode1 = TUI_ATLAS_GRID;
const size_t kSheetChannels1 = 4;
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

int main()
{

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
    GLFWwindow* window = glfwCreateWindow(kWindowWidth, kWindowHeight, kWindowTitle, NULL, NULL);
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
    TuiPanel panel1; //This will be a G8_C4 panel with random data, rendered to the screen object in lower left quarter.
    TuiPalette palette1;
    TuiBatch batch1;
    TuiGlyphAtlas atlas1;
    TuiPanel panel2; //This will be a G16_C8 panel with random data, rendered to the screen object in upper right quarter.
    TuiPalette palette2;
    TuiBatch batch2;
    TuiGlyphAtlas atlas2;
    TuiPanel panel3; //This panel will be rendered to the main screen (the window) with a margin of 5 pixels around it on all sides.

    //Set debug callback.
    tuiSetDebugErrorCallback(TuiMessageCallback);

    //Create the TUIC instance.
    instance = tuiOpengl33InstanceCreate(kWindowWidth, kWindowHeight, ((void*)glfwGetProcAddress)); //The instance should always be the first TUIC object created and the last destroyed.

    /* PANEL 1 SETUP */
    panel1 = tuiPanelCreate(instance, kScreenWidth/2, kScreenHeight/2);
    palette1 = tuiPaletteCreateXterm(instance, 16);
    batch1 = tuiBatchCreate(TUI_DETAIL_G8_C4_FULL, 15, 15);
    TuiImage image = tuiImageLoad("cp_8x8_rgba_bg_alpha.png", 4);
    if (image == NULL)
    {
        printf("Issue loading image file. Make sure that it was moved from the content folder to a location the executable can read. You need to do this manually.\n");
        glfwTerminate();
        return -1;
    }
    atlas1 = tuiGlyphAtlasCreateCodepageGrid(instance, image, TUI_BLEND_BG_ALPHA);
    tuiImageDestroy(image);
    for (int x = 0; x < 15; x++)
    {
        for (int y = 0; y < 15; y++)
        {
            tuiBatchSetTile_G8_C4_FULL(batch1, x, y, rand() % 256, rand() % 256);
        }
    }

    /* PANEL 2 SETUP */
    panel2 = tuiPanelCreate(instance, kScreenWidth/2, kScreenHeight/2);
    palette2 = tuiPaletteCreateXterm(instance, 256);
    batch2 = tuiBatchCreate(TUI_DETAIL_G16_C8_FULL, 15, 15);
    const uint16_t glyphs_tall = 31;
    const uint16_t glyphs_wide = 53;
    const uint16_t glyph_count = glyphs_tall * glyphs_wide;
    const uint16_t glyph_width = 16;
    const uint16_t glyph_height = 16;
    uint16_t* glyph_bounding_boxes = malloc(sizeof(size_t) * glyph_count * 4);
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
    image = tuiImageLoad("kenny_roguelikeSheet_transparent.png", 4);
    if (image == NULL)
    {
        printf("Issue loading image file. Make sure that it was moved from the content folder to a location the executable can read. You need to do this manually.\n");
        glfwTerminate();
        return -1;
    }
    atlas2 = tuiGlyphAtlasCreate(instance, image, glyph_count, glyph_bounding_boxes, TUI_BLEND_BG_ALPHA);
    tuiImageDestroy(image);
    for (int x = 0; x < 15; x++)
    {
        for (int y = 0; y < 15; y++)
        {
            tuiBatchSetTile_G16_C8_FULL(batch2, x, y, x + y, x % 256, 255 - (y % 256));
        }
    }


    /* SCREEN SETUP */
    panel3 = tuiPanelCreate(instance, kScreenWidth, kScreenHeight);

    /* DRAWING AND RENDERING */
    tuiPanelDrawBatch(panel1, atlas1, palette1, batch1);
    tuiPanelDrawBatch(panel2, atlas2, palette2, batch2);
    tuiPanelClearColor(panel3, 255, 255, 0, 255);
    tuiPanelRenderToPanelTransformed(panel1, panel3, kScreenWidth / 2, kScreenWidth, kScreenHeight / 2, kScreenHeight);
    tuiPanelRenderToPanelTransformed(panel2, panel3, 0, kScreenWidth / 2, 0, kScreenHeight / 2);
    //Render screen to a png image (TransformScreen.png) NOTE: this is just hte screen, not what is rendered to the window bellow!
    image = tuiPanelGetImage(panel3, NULL);
    tuiImageSave(image, "TransformScreen.png");
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

        tuiInstanceClearColor(instance, 255, 0, 255, 255); //Draw the instance screen (the window) magenta
        tuiPanelRenderTransformed(panel3, 30, kWindowWidth - 30, 30, kWindowHeight - 30); //Draw the screen with the panels already rendered to it with a 30 pixel margin around it.

        glfwSwapBuffers(window); //swap the window buffers
    }

    //Destroy all TUIC objects
    tuiPanelDestroy(panel1);
    tuiBatchDestroy(batch1);
    tuiPaletteDestroy(palette1);
    tuiGlyphAtlasDestroy(atlas1);
    tuiPanelDestroy(panel2);
    tuiBatchDestroy(batch2);
    tuiPaletteDestroy(palette2);
    tuiGlyphAtlasDestroy(atlas2);
    tuiPanelDestroy(panel3);
    tuiInstanceDestroy(instance); //TuiInstance must always be created first and destroyed last.

    //Terminate GLFW
    glfwTerminate();

    return 0;
}