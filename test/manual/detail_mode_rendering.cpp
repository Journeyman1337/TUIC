/* Render test batches for every detail mode to a TuiWindow and save screenshots. */

#include <TUIC/tuic.h>

#include <stdio.h>
#include <string.h>

#define TILE_DIMENSIONS 128
#define TILE_PIXEL_DIMENSIONS 8
#define WINDOW_DIMENSIONS TILE_DIMENSIONS * TILE_PIXEL_DIMENSIONS

TuiBatch GetTestPatternBatch(TuiDetailMode detail_mode)
{
	TuiBatch batch = TUI_NULL;
	TuiDetailFlag detail_flag = tuiDetailGetLayoutFlag(detail_mode);
	switch (detail_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
		batch = tuiBatchCreateFull(detail_mode, TILE_DIMENSIONS, TILE_DIMENSIONS, 0);
		break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
		batch = tuiBatchCreateSparse(detail_mode, TILE_DIMENSIONS, TILE_DIMENSIONS, TUI_TRUE, 0);
		break;
	case TUI_DETAIL_FLAG_LAYOUT_FREE:
		batch = tuiBatchCreateFree(detail_mode, TILE_PIXEL_DIMENSIONS, TILE_PIXEL_DIMENSIONS, WINDOW_DIMENSIONS, WINDOW_DIMENSIONS, (TILE_DIMENSIONS) * (TILE_DIMENSIONS), 0);
		break;
	default:
		break;
	}
	
	for (int x = 0; x < TILE_DIMENSIONS; x++)
	{
		for (int y = 0; y < TILE_DIMENSIONS; y++)
		{
			if (!tuiDetailHasFlag(detail_mode, TUI_DETAIL_FLAG_LAYOUT_SPARSE) == TUI_TRUE || (x % 2 == 0 && y % 2 == 0))
			{
				switch (detail_mode)
				{
				case TUI_DETAIL_MODE_G0_C8NBG_FULL:
					tuiBatchSetTile_G0_C8NBG_FULL(batch, x, y, x % 256);
					break;
				case TUI_DETAIL_MODE_G0_C24NBG_FULL:
					tuiBatchSetTile_G0_C24NBG_FULL(batch, x, y, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G0_C32NBG_FULL:
					tuiBatchSetTile_G0_C32NBG_FULL(batch, x, y, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G8_C0_FULL:
					tuiBatchSetTile_G8_C0_FULL(batch, x, y, x);
					break;
				case TUI_DETAIL_MODE_G8_C4_FULL:
					tuiBatchSetTile_G8_C4_FULL(batch, x, y, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_MODE_G8_C8NBG_FULL:
					tuiBatchSetTile_G8_C8NBG_FULL(batch, x, y, x, x % 256);
					break;
				case TUI_DETAIL_MODE_G8_C8_FULL:
					tuiBatchSetTile_G8_C8_FULL(batch, x, y, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C8NFG_FULL:
					tuiBatchSetTile_G8_C8NFG_FULL(batch, x, y, x, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24_FULL:
					tuiBatchSetTile_G8_C24_FULL(batch, x, y, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24NBG_FULL:
					tuiBatchSetTile_G8_C24NBG_FULL(batch, x, y, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24NFG_FULL:
					tuiBatchSetTile_G8_C24NFG_FULL(batch, x, y, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C32_FULL:
					tuiBatchSetTile_G8_C32_FULL(batch, x, y, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G8_C32NBG_FULL:
					tuiBatchSetTile_G8_C32NBG_FULL(batch, x, y, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G8_C32NFG_FULL:
					tuiBatchSetTile_G8_C32NFG_FULL(batch, x, y, x, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G16_C0_FULL:
					tuiBatchSetTile_G16_C0_FULL(batch, x, y, x);
					break;
				case TUI_DETAIL_MODE_G16_C4_FULL:
					tuiBatchSetTile_G16_C4_FULL(batch, x, y, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_MODE_G16_C8NBG_FULL:
					tuiBatchSetTile_G16_C8NBG_FULL(batch, x, y, x, x % 256);
					break;
				case TUI_DETAIL_MODE_G16_C8_FULL:
					tuiBatchSetTile_G16_C8_FULL(batch, x, y, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C8NFG_FULL:
					tuiBatchSetTile_G16_C8NFG_FULL(batch, x, y, x, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24_FULL:
					tuiBatchSetTile_G16_C24_FULL(batch, x, y, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24NBG_FULL:
					tuiBatchSetTile_G16_C24NBG_FULL(batch, x, y, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24NFG_FULL:
					tuiBatchSetTile_G16_C24NFG_FULL(batch, x, y, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C32_FULL:
					tuiBatchSetTile_G16_C32_FULL(batch, x, y, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G16_C32NBG_FULL:
					tuiBatchSetTile_G16_C32NBG_FULL(batch, x, y, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G16_C32NFG_FULL:
					tuiBatchSetTile_G16_C32NFG_FULL(batch, x, y, x, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G0_C8NBG_SPARSE:
					tuiBatchSetTile_G0_C8NBG_SPARSE(batch, x, y, x % 256);
					break;
				case TUI_DETAIL_MODE_G0_C24NBG_SPARSE:
					tuiBatchSetTile_G0_C24NBG_SPARSE(batch, x, y, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G0_C32NBG_SPARSE:
					tuiBatchSetTile_G0_C32NBG_SPARSE(batch, x, y, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G8_C0_SPARSE:
					tuiBatchSetTile_G8_C0_SPARSE(batch, x, y, x);
					break;
				case TUI_DETAIL_MODE_G8_C4_SPARSE:
					tuiBatchSetTile_G8_C4_SPARSE(batch, x, y, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_MODE_G8_C8NBG_SPARSE:
					tuiBatchSetTile_G8_C8NBG_SPARSE(batch, x, y, x, x % 256);
					break;
				case TUI_DETAIL_MODE_G8_C8_SPARSE:
					tuiBatchSetTile_G8_C8_SPARSE(batch, x, y, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C8NFG_SPARSE:
					tuiBatchSetTile_G8_C8NFG_SPARSE(batch, x, y, x, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24_SPARSE:
					tuiBatchSetTile_G8_C24_SPARSE(batch, x, y, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24NBG_SPARSE:
					tuiBatchSetTile_G8_C24NBG_SPARSE(batch, x, y, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24NFG_SPARSE:
					tuiBatchSetTile_G8_C24NFG_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C32_SPARSE:
					tuiBatchSetTile_G8_C32_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G8_C32NBG_SPARSE:
					tuiBatchSetTile_G8_C32NBG_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G8_C32NFG_SPARSE:
					tuiBatchSetTile_G8_C32NFG_SPARSE(batch, x, y, x, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G16_C0_SPARSE:
					tuiBatchSetTile_G16_C0_SPARSE(batch, x, y, x);
					break;
				case TUI_DETAIL_MODE_G16_C4_SPARSE:
					tuiBatchSetTile_G16_C4_SPARSE(batch, x, y, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_MODE_G16_C8NBG_SPARSE:
					tuiBatchSetTile_G16_C8NBG_SPARSE(batch, x, y, x, x % 256);
					break;
				case TUI_DETAIL_MODE_G16_C8_SPARSE:
					tuiBatchSetTile_G16_C8_SPARSE(batch, x, y, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C8NFG_SPARSE:
					tuiBatchSetTile_G16_C8NFG_SPARSE(batch, x, y, x, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24_SPARSE:
					tuiBatchSetTile_G16_C24_SPARSE(batch, x, y, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24NBG_SPARSE:
					tuiBatchSetTile_G16_C24NBG_SPARSE(batch, x, y, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24NFG_SPARSE:
					tuiBatchSetTile_G16_C24NFG_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C32_SPARSE:
					tuiBatchSetTile_G16_C32_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G16_C32NBG_SPARSE:
					tuiBatchSetTile_G16_C32NBG_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G16_C32NFG_SPARSE:
					tuiBatchSetTile_G16_C32NFG_SPARSE(batch, x, y, x, x % 256, y % 128, x % 256, x);
					break; 
				case TUI_DETAIL_MODE_G0_C8NBG_FREE:
					tuiBatchSetTile_G0_C8NBG_FREE(batch, x * 8, y * 8, x % 256);
					break;
				case TUI_DETAIL_MODE_G0_C24NBG_FREE:
					tuiBatchSetTile_G0_C24NBG_FREE(batch, x * 8, y * 8, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G0_C32NBG_FREE:
					tuiBatchSetTile_G0_C32NBG_FREE(batch, x * 8, y * 8, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G8_C0_FREE:
					tuiBatchSetTile_G8_C0_FREE(batch, x * 8, y * 8, x);
					break;
				case TUI_DETAIL_MODE_G8_C4_FREE:
					tuiBatchSetTile_G8_C4_FREE(batch, x * 8, y * 8, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_MODE_G8_C8NBG_FREE:
					tuiBatchSetTile_G8_C8NBG_FREE(batch, x * 8, y * 8, x, x % 256);
					break;
				case TUI_DETAIL_MODE_G8_C8_FREE:
					tuiBatchSetTile_G8_C8_FREE(batch, x * 8, y * 8, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C8NFG_FREE:
					tuiBatchSetTile_G8_C8NFG_FREE(batch, x * 8, y * 8, x, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24_FREE:
					tuiBatchSetTile_G8_C24_FREE(batch, x * 8, y * 8, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24NBG_FREE:
					tuiBatchSetTile_G8_C24NBG_FREE(batch, x * 8, y * 8, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G8_C24NFG_FREE:
					tuiBatchSetTile_G8_C24NFG_FREE(batch, x * 8, y * 8, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G8_C32_FREE:
					tuiBatchSetTile_G8_C32_FREE(batch, x * 8, y * 8, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G8_C32NBG_FREE:
					tuiBatchSetTile_G8_C32NBG_FREE(batch, x * 8, y * 8, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G8_C32NFG_FREE:
					tuiBatchSetTile_G8_C32NFG_FREE(batch, x * 8, y * 8, x, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G16_C0_FREE:
					tuiBatchSetTile_G16_C0_FREE(batch, x * 8, y * 8, x);
					break;
				case TUI_DETAIL_MODE_G16_C4_FREE:
					tuiBatchSetTile_G16_C4_FREE(batch, x * 8, y * 8, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_MODE_G16_C8NBG_FREE:
					tuiBatchSetTile_G16_C8NBG_FREE(batch, x * 8, y * 8, x, x % 256);
					break;
				case TUI_DETAIL_MODE_G16_C8_FREE:
					tuiBatchSetTile_G16_C8_FREE(batch, x * 8, y * 8, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C8NFG_FREE:
					tuiBatchSetTile_G16_C8NFG_FREE(batch, x * 8, y * 8, x, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24_FREE:
					tuiBatchSetTile_G16_C24_FREE(batch, x * 8, y * 8, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24NBG_FREE:
					tuiBatchSetTile_G16_C24NBG_FREE(batch, x * 8, y * 8, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_MODE_G16_C24NFG_FREE:
					tuiBatchSetTile_G16_C24NFG_FREE(batch, x * 8, y * 8, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_MODE_G16_C32_FREE:
					tuiBatchSetTile_G16_C32_FREE(batch, x * 8, y * 8, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_MODE_G16_C32NBG_FREE:
					tuiBatchSetTile_G16_C32NBG_FREE(batch, x * 8, y * 8, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_MODE_G16_C32NFG_FREE:
					tuiBatchSetTile_G16_C32NFG_FREE(batch, x * 8, y * 8, x, x % 256, y % 128, x % 256, x);
					break;
				}
			}
		}
	}
	return batch;
}

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

static int sNextFrame = TUI_FALSE;

void frame(TuiWindow window)
{
	tuiWindowFrame(window);
	tuiPollEvents();
	sNextFrame = TUI_FALSE;
	while (sNextFrame == TUI_FALSE && tuiWindowShouldClose(window) == TUI_FALSE)
	{
		tuiWindowFrame(window);
		tuiPollEvents();
	}
}

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState state, TuiKeyboardMod mods)
{
	if (key == TUIK_SPACE && (  state == TUI_BUTTON_PRESS || state == TUI_BUTTON_REPEAT))
	{
		sNextFrame = TUI_TRUE;
	}
}

const TuiDetailMode kDetailModes[69] =
{
	TUI_DETAIL_MODE_G0_C8NBG_FULL,
	TUI_DETAIL_MODE_G0_C24NBG_FULL,
	TUI_DETAIL_MODE_G0_C32NBG_FULL,
	TUI_DETAIL_MODE_G8_C4_FULL,
	TUI_DETAIL_MODE_G8_C8_FULL,
	TUI_DETAIL_MODE_G8_C8NBG_FULL,
	TUI_DETAIL_MODE_G8_C8NFG_FULL,
	TUI_DETAIL_MODE_G8_C24_FULL,
	TUI_DETAIL_MODE_G8_C24NBG_FULL,
	TUI_DETAIL_MODE_G8_C24NFG_FULL,
	TUI_DETAIL_MODE_G8_C32_FULL,
	TUI_DETAIL_MODE_G8_C32NBG_FULL,
	TUI_DETAIL_MODE_G8_C32NFG_FULL,
	TUI_DETAIL_MODE_G16_C4_FULL,
	TUI_DETAIL_MODE_G16_C8_FULL,
	TUI_DETAIL_MODE_G16_C8NBG_FULL,
	TUI_DETAIL_MODE_G16_C8NFG_FULL,
	TUI_DETAIL_MODE_G16_C24_FULL,
	TUI_DETAIL_MODE_G16_C24NBG_FULL,
	TUI_DETAIL_MODE_G16_C24NFG_FULL,
	TUI_DETAIL_MODE_G16_C32_FULL,
	TUI_DETAIL_MODE_G16_C32NBG_FULL,
	TUI_DETAIL_MODE_G16_C32NFG_FULL,
	TUI_DETAIL_MODE_G0_C8NBG_SPARSE,
	TUI_DETAIL_MODE_G0_C24NBG_SPARSE,
	TUI_DETAIL_MODE_G0_C32NBG_SPARSE,
	TUI_DETAIL_MODE_G8_C4_SPARSE,
	TUI_DETAIL_MODE_G8_C8_SPARSE,
	TUI_DETAIL_MODE_G8_C8NBG_SPARSE,
	TUI_DETAIL_MODE_G8_C8NFG_SPARSE,
	TUI_DETAIL_MODE_G8_C24_SPARSE,
	TUI_DETAIL_MODE_G8_C24NBG_SPARSE,
	TUI_DETAIL_MODE_G8_C24NFG_SPARSE,
	TUI_DETAIL_MODE_G8_C32_SPARSE,
	TUI_DETAIL_MODE_G8_C32NBG_SPARSE,
	TUI_DETAIL_MODE_G8_C32NFG_SPARSE,
	TUI_DETAIL_MODE_G16_C4_SPARSE,
	TUI_DETAIL_MODE_G16_C8_SPARSE,
	TUI_DETAIL_MODE_G16_C8NBG_SPARSE,
	TUI_DETAIL_MODE_G16_C8NFG_SPARSE,
	TUI_DETAIL_MODE_G16_C24_SPARSE,
	TUI_DETAIL_MODE_G16_C24NBG_SPARSE,
	TUI_DETAIL_MODE_G16_C24NFG_SPARSE,
	TUI_DETAIL_MODE_G16_C32_SPARSE,
	TUI_DETAIL_MODE_G16_C32NBG_SPARSE,
	TUI_DETAIL_MODE_G16_C32NFG_SPARSE,
	TUI_DETAIL_MODE_G0_C8NBG_FREE,
	TUI_DETAIL_MODE_G0_C24NBG_FREE,
	TUI_DETAIL_MODE_G0_C32NBG_FREE,
	TUI_DETAIL_MODE_G8_C4_FREE,
	TUI_DETAIL_MODE_G8_C8_FREE,
	TUI_DETAIL_MODE_G8_C8NBG_FREE,
	TUI_DETAIL_MODE_G8_C8NFG_FREE,
	TUI_DETAIL_MODE_G8_C24_FREE,
	TUI_DETAIL_MODE_G8_C24NBG_FREE,
	TUI_DETAIL_MODE_G8_C24NFG_FREE,
	TUI_DETAIL_MODE_G8_C32_FREE,
	TUI_DETAIL_MODE_G8_C32NBG_FREE,
	TUI_DETAIL_MODE_G8_C32NFG_FREE,
	TUI_DETAIL_MODE_G16_C4_FREE,
	TUI_DETAIL_MODE_G16_C8_FREE,
	TUI_DETAIL_MODE_G16_C8NBG_FREE,
	TUI_DETAIL_MODE_G16_C8NFG_FREE,
	TUI_DETAIL_MODE_G16_C24_FREE,
	TUI_DETAIL_MODE_G16_C24NBG_FREE,
	TUI_DETAIL_MODE_G16_C24NFG_FREE,
	TUI_DETAIL_MODE_G16_C32_FREE,
	TUI_DETAIL_MODE_G16_C32NBG_FREE,
	TUI_DETAIL_MODE_G16_C32NFG_FREE
};

int main()
{
	tuiSetDebugErrorCallback(message_callback);

	if (tuiInit() == TUI_FALSE)
	{
		printf("Failed to initialize TUIC.");
		return 1;
	}

	printf("Testing all detail modes by rendering test pattern batches. Press spacebar to render the next batch.\n");

	TuiImage image = tuiImageCreatePNG("cp_8x8_rgba_bg_alpha.png");
	TuiAtlas atlas = tuiAtlasCreateCodepageImage(image, TUI_BLEND_BG_ALPHA);
	tuiImageDestroy(image);
	image = TUI_NULL;

	TuiPalette palette = tuiPaletteCreateXterm(256);

	TuiWindow window = tuiWindowCreate(WINDOW_DIMENSIONS, WINDOW_DIMENSIONS, "detail_mode_rendering", TUI_NULL);
	tuiWindowSetKeyboardKeyCallback(window, key_callback);

	for (size_t detail_mode_i = 0; detail_mode_i < 69; detail_mode_i++)
	{
		TuiDetailMode cur_detail_mode = kDetailModes[detail_mode_i];
		TuiBatch batch = GetTestPatternBatch(cur_detail_mode);
		tuiWindowClearColor(window, 0, 0, 0, 255);
		tuiWindowDrawBatch(window, atlas, palette, batch);
		const char* cur_detail_mode_name = tuiDetailModeToString(cur_detail_mode);
		printf("%s\n", cur_detail_mode_name);
		frame(window);
		tuiBatchDestroy(batch);
		batch = TUI_NULL;
		if (tuiWindowShouldClose(window) == TUI_TRUE)
		{
			break;
		}
	}
		
	tuiAtlasDestroy(atlas);
	atlas = TUI_NULL;
	tuiPaletteDestroy(palette);
	palette = TUI_NULL;
	tuiWindowDestroy(window);
	window = TUI_NULL;

	tuiTerminate();

	return 0;
}