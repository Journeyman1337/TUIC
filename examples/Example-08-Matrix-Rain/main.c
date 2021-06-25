/*  */

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <TUIC/tuic.h>
#include <TUIC/backends/opengl33.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t kTilesWide = 256;
const size_t kTilesTall = 180;
const size_t kTileSizeMultiplier = 1;
const size_t kTilePixelWidth = 8;
const size_t kTilePixelHeight = 8;
const char* kWindowTitle = "Example 8: Matrix Rain";
const char* kSheetImageFile = "cp_8x8_rgb_fg_green.png";
const size_t kSheetTextureFormat = 3;
const size_t kSheetBlendMode = TUI_BLEND_FG_GREEN;
const size_t kAtlasMode = TUI_ATLAS_GRID;
const size_t kTuiDetail = TUI_DETAIL_G8_C4_SPARSE;

const uint8_t kTrailHeadColor[3] = { 0, 255, 0 };
const uint8_t kBackColor[3] = { 0, 10, 0 };
const size_t kTrailLength = 15;
const size_t kTrailLenghtMultiplierMax = 1;
const size_t kTrailCreateChance = 20;
const double kUpdateDelta = 0.01;

typedef struct MatrixTrail
{
    size_t active;
    size_t head_y;
    size_t length;
} MatrixTrail;

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

    /* GLFW and GLEW Initialization */
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
    glfwSwapInterval(0); // Change to 1 to cap framerate with your monitor's vsync.

    /* TUI Object Declaration */
    TuiInstance instance;
    TuiGlyphAtlas atlas;
    TuiPalette palette;
    TuiPanel panel;
    TuiBatch batch;

    /* Tell TUIC to send all debug messages to our message callback (the function we implemented above main). */
    tuiSetDebugErrorCallback(TuiMessageCallback);

    /* Create the TUIC instance. */
    instance = tuiOpengl33InstanceCreate(window_width, window_height, ((void*)glfwGetProcAddress));

    /* Load the atlas image */
    TuiImage image = tuiImageLoad(kSheetImageFile, kSheetTextureFormat);
    if (image == NULL)
    {
        printf("Issue loading image file. Make sure that it was moved from the content folder to a location the executable can read. You need to do this manually.\n");
        glfwTerminate();
        return -1;
    }

    /* Create the Glyph Atlas */
    atlas = tuiGlyphAtlasCreateCodepageGrid(instance, image, kSheetBlendMode);
    tuiImageDestroy(image);

    /* Create the palette */
    uint8_t palette_colors[16 * 3];
    palette_colors[0] = kBackColor[0];
    palette_colors[1] = kBackColor[1];
    palette_colors[2] = kBackColor[2];
    for (size_t color_i = 1; color_i <= kTrailLength; color_i++)
    {
        for (size_t channel_i = 0; channel_i < 3; channel_i++)
        {
            float channel_color_max = ((float)kTrailHeadColor[channel_i]);
            float channel_color_min = ((float)kBackColor[channel_i]);
            float interpolation_percent = ((float)color_i) / ((float)kTrailLength);
            float interpolated_channel_color = channel_color_min + (interpolation_percent * (channel_color_max - channel_color_min));
            palette_colors[(color_i * 3) + channel_i] = ((uint8_t)(interpolated_channel_color));
        }
    }
    palette = tuiPaletteCreate(instance, 3, 16, palette_colors);

    /* Create the panel */
    panel = tuiPanelCreate(instance, window_width, window_height);

    /* Create the batch */
    batch = tuiBatchCreate(kTuiDetail, kTilesWide, kTilesTall);

    //fps tracking setup
    double last_time = 0;
    int nbFrame = 0;

    //init data
    double last_frame = 0.0;
    double total_time = 0.0f;
    uint8_t* glyphs = malloc(kTilesWide * kTilesTall);
    memset(glyphs, 0, kTilesWide * kTilesTall);
    MatrixTrail* trails = malloc(kTilesWide * sizeof(MatrixTrail));
    memset(trails, 0, kTilesWide * sizeof(MatrixTrail));
    size_t active_trails = 0;

    //init rand
    time_t t;
    srand((unsigned)time(&t));

    //Render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents(); //handle input events and call callback functions

        /* Print fps to console */
        double current_time = glfwGetTime();
        double second_delta = current_time - last_time;
        nbFrame++;
        if (second_delta >= 1.0) { // If last fps print was more than 1 sec ago

            double fps = nbFrame / second_delta;
            printf("%f FPS\n", fps);
            nbFrame = 0;
            last_time = current_time;
        }

        double delta = current_time - last_frame;
        last_frame = current_time;
        total_time += delta;
        if (total_time > kUpdateDelta)
        {
            total_time = 0.0;

            //If not max trails active, try to create new trail.
            if (active_trails < kTilesWide)
            {
                if (rand() % 100 <= kTrailCreateChance)
                {
                    size_t new_trail_i = 0;
                    for (size_t trail_i = rand() % kTilesWide; trail_i < kTilesWide; trail_i++)
                    {
                        if (trails[trail_i].active == 0)
                        {
                            new_trail_i = trail_i;
                            break;
                        }
                    }
                    trails[new_trail_i].active = 1;
                    trails[new_trail_i].head_y = 0;
                    trails[new_trail_i].length = ((rand() % kTrailLenghtMultiplierMax) + 1) * kTrailLength;
                    active_trails++;
                }
            }

            //loop through trails and move active ones down. create random glyph at new head, then render all tiles of trail at colors and deactivate trails that go offscreen.
            for (size_t trail_i = 0; trail_i < kTilesWide; trail_i++)
            {
                if (trails[trail_i].active == 1)
                {
                    trails[trail_i].head_y++;
                    size_t length = kTrailLength * trails[trail_i].length;
                    if (trails[trail_i].head_y >= kTilesTall + length)
                    {
                        trails[trail_i].active = 0;
                        active_trails--;
                        continue;
                    }
                    if (trails[trail_i].head_y < kTilesTall)
                    {
                        glyphs[trail_i + trails[trail_i].head_y * kTilesWide] = rand() % 256;
                    }
                    
                    for (size_t part_i = 0; part_i < length; part_i++)
                    {
                        size_t part_y = trails[trail_i].head_y - part_i;
                        if (part_y < kTilesTall)
                        {

                            uint8_t color = tuiClassicColorCombine(15 - (part_i/kTrailLength), 0);
                            tuiBatchSetTile_G8_C4_SPARSE(batch, trail_i, part_y, glyphs[trail_i + part_y * kTilesWide], color);
                        }
                    }
                }
            }


            tuiPanelDrawBatch(panel, atlas, palette, batch);
            tuiBatchClear(batch); //since using a sparse batch, this is required.
        }


        tuiPanelRender(panel);
        
        glfwSwapBuffers(window); //swap the window buffers
    }

    /* Destroy all TUIC objects */
    tuiPanelDestroy(panel);
    tuiBatchDestroy(batch);
    tuiPaletteDestroy(palette);
    tuiGlyphAtlasDestroy(atlas);
    tuiInstanceDestroy(instance); //The instance must always be created first and destroyed last.
    free(glyphs);
	free(trails);

    glfwTerminate();
    return 0;
}