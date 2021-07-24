#include "common_test.hpp"

#include <string.h>
#include <stdio.h>

const char* kOutDirectoryPath = "test_out/";

TuiAtlas test_CreateCodepageAtlas(TuiBlendMode blend_mode)
{
	TuiImage image = nullptr;
	switch (blend_mode)
	{
		case TUI_BLEND_BG_ALPHA:
			image = tuiImageLoad("cp_8x8_rgba_bg_alpha.png");
			break;
		case TUI_BLEND_FG_ALPHA:
			image = tuiImageLoad("cp_8x8_rgba_fg_alpha.png");
			break;
		case TUI_BLEND_BG_RED:
			image = tuiImageLoad("cp_8x8_rgb_bg_red.png");
			break;
		case TUI_BLEND_FG_RED:
			image = tuiImageLoad("cp_8x8_rgb_fg_red.png");
			break;
		case TUI_BLEND_BG_GREEN:
			image = tuiImageLoad("cp_8x8_rgb_bg_green.png");
			break;
		case TUI_BLEND_FG_GREEN:
			image = tuiImageLoad("cp_8x8_rgb_fg_green.png");
			break;
		case TUI_BLEND_BG_BLUE:
			image = tuiImageLoad("cp_8x8_rgb_bg_blue.png");
			break;
		case TUI_BLEND_FG_BLUE:
			image = tuiImageLoad("cp_8x8_rgb_fg_blue.png");
			break;
		case TUI_BLEND_NORMAL:
			image = tuiImageLoad("cp_8x8_rgba_bg_alpha.png");
			break;
	}
	TuiAtlas atlas = tuiAtlasCreateCodepageGrid(image, blend_mode);
	tuiImageDestroy(image);
	return atlas;
}

TuiBatch test_GetTestPatternBatch(TuiDetailMode detail_mode)
{
	TuiBatch batch = tuiBatchCreate(detail_mode, TEST_DIMENSIONS, TEST_DIMENSIONS);
	for (int x = 0; x < TEST_DIMENSIONS; x++)
	{
		for (int y = 0; y < TEST_DIMENSIONS; y++)
		{
			if (!tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE || (x % 2 == 0 && y % 2 == 0))
			{
				switch(detail_mode)
				{
				case TUI_DETAIL_G8_C0_FULL:
					tuiBatchSetTile_G8_C0_FULL(batch, x, y, x);
					break;
				case TUI_DETAIL_G8_C4_FULL:
					tuiBatchSetTile_G8_C4_FULL(batch, x, y, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_G8_C8NBG_FULL:
					tuiBatchSetTile_G8_C8NBG_FULL(batch, x, y, x, x % 256);
					break;
				case TUI_DETAIL_G8_C8_FULL:
					tuiBatchSetTile_G8_C8_FULL(batch, x, y, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_G8_C8NFG_FULL:
					tuiBatchSetTile_G8_C8NFG_FULL(batch, x, y, x, y % 256);
					break;
				case TUI_DETAIL_G8_C24_FULL:
					tuiBatchSetTile_G8_C24_FULL(batch, x, y, x, x % 256, y % 256, x % 256, y % 256, x % 128,  y % 256);
					break;
				case TUI_DETAIL_G8_C24NBG_FULL:
					tuiBatchSetTile_G8_C24NBG_FULL(batch, x, y, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_G8_C24NFG_FULL:
					tuiBatchSetTile_G8_C24NFG_FULL(batch, x, y, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_G8_C32_FULL:
					tuiBatchSetTile_G8_C32_FULL(batch, x, y, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_G8_C32NBG_FULL:
					tuiBatchSetTile_G8_C32NBG_FULL(batch, x, y, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_G8_C32NFG_FULL:
					tuiBatchSetTile_G8_C32NFG_FULL(batch, x, y, x, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_G16_C0_FULL:
					tuiBatchSetTile_G16_C0_FULL(batch, x, y, x);
					break;
				case TUI_DETAIL_G16_C4_FULL:
					tuiBatchSetTile_G16_C4_FULL(batch, x, y, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_G16_C8NBG_FULL:
					tuiBatchSetTile_G16_C8NBG_FULL(batch, x, y, x, x % 256);
					break;
				case TUI_DETAIL_G16_C8_FULL:
					tuiBatchSetTile_G16_C8_FULL(batch, x, y, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_G16_C8NFG_FULL:
					tuiBatchSetTile_G16_C8NFG_FULL(batch, x, y, x, y % 256);
					break;
				case TUI_DETAIL_G16_C24_FULL:
					tuiBatchSetTile_G16_C24_FULL(batch, x, y, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_G16_C24NBG_FULL:
					tuiBatchSetTile_G16_C24NBG_FULL(batch, x, y, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_G16_C24NFG_FULL:
					tuiBatchSetTile_G16_C24NFG_FULL(batch, x, y, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_G16_C32_FULL:
					tuiBatchSetTile_G16_C32_FULL(batch, x, y, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_G16_C32NBG_FULL:
					tuiBatchSetTile_G16_C32NBG_FULL(batch, x, y, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_G16_C32NFG_FULL:
					tuiBatchSetTile_G16_C32NFG_FULL(batch, x, y, x, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_G8_C0_SPARSE:
					tuiBatchSetTile_G8_C0_SPARSE(batch, x, y, x);
					break;
				case TUI_DETAIL_G8_C4_SPARSE:
					tuiBatchSetTile_G8_C4_SPARSE(batch, x, y, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_G8_C8NBG_SPARSE:
					tuiBatchSetTile_G8_C8NBG_SPARSE(batch, x, y, x, x % 256);
					break;
				case TUI_DETAIL_G8_C8_SPARSE:
					tuiBatchSetTile_G8_C8_SPARSE(batch, x, y, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_G8_C8NFG_SPARSE:
					tuiBatchSetTile_G8_C8NFG_SPARSE(batch, x, y, x, y % 256);
					break;
				case TUI_DETAIL_G8_C24_SPARSE:
					tuiBatchSetTile_G8_C24_SPARSE(batch, x, y, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_G8_C24NBG_SPARSE:
					tuiBatchSetTile_G8_C24NBG_SPARSE(batch, x, y, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_G8_C24NFG_SPARSE:
					tuiBatchSetTile_G8_C24NFG_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_G8_C32_SPARSE:
					tuiBatchSetTile_G8_C32_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_G8_C32NBG_SPARSE:
					tuiBatchSetTile_G8_C32NBG_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_G8_C32NFG_SPARSE:
					tuiBatchSetTile_G8_C32NFG_SPARSE(batch, x, y, x, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_G16_C0_SPARSE:
					tuiBatchSetTile_G16_C0_SPARSE(batch, x, y, x);
					break;
				case TUI_DETAIL_G16_C4_SPARSE:
					tuiBatchSetTile_G16_C4_SPARSE(batch, x, y, x, tuiClassicColorCombine(x % 16, y % 16));
					break;
				case TUI_DETAIL_G16_C8NBG_SPARSE:
					tuiBatchSetTile_G16_C8NBG_SPARSE(batch, x, y, x, x % 256);
					break;
				case TUI_DETAIL_G16_C8_SPARSE:
					tuiBatchSetTile_G16_C8_SPARSE(batch, x, y, x, x % 256, y % 256);
					break;
				case TUI_DETAIL_G16_C8NFG_SPARSE:
					tuiBatchSetTile_G16_C8NFG_SPARSE(batch, x, y, x, y % 256);
					break;
				case TUI_DETAIL_G16_C24_SPARSE:
					tuiBatchSetTile_G16_C24_SPARSE(batch, x, y, x, x % 256, y % 256, x % 256, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_G16_C24NBG_SPARSE:
					tuiBatchSetTile_G16_C24NBG_SPARSE(batch, x, y, x, x % 256, y % 256, x % 256);
					break;
				case TUI_DETAIL_G16_C24NFG_SPARSE:
					tuiBatchSetTile_G16_C24NFG_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256);
					break;
				case TUI_DETAIL_G16_C32_SPARSE:
					tuiBatchSetTile_G16_C32_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256, y, x % 256, y % 128, x % 256, x);
					break;
				case TUI_DETAIL_G16_C32NBG_SPARSE:
					tuiBatchSetTile_G16_C32NBG_SPARSE(batch, x, y, x, y % 256, x % 128, y % 256, y);
					break;
				case TUI_DETAIL_G16_C32NFG_SPARSE:
					tuiBatchSetTile_G16_C32NFG_SPARSE(batch, x, y, x, x % 256, y % 128, x % 256, x);
					break;
				}
			}
		}
	}
	return batch;
}

void test_BlendMode(TuiBlendMode blend_mode, TuiPanel panel)
{
	tuiPanelClearColor(panel, 0, 0, 0, 255);
	const char* blend_name = tuiBlendModeToString(blend_mode);
	TuiBatch batch = test_GetTestPatternBatch(TUI_DETAIL_G8_C4_FULL);
	TuiPalette palette = tuiPaletteCreateXterm(16);  
	TuiAtlas atlas = test_CreateCodepageAtlas(blend_mode);
	tuiPanelClearColor(panel, 0, 0, 0, 255);
	tuiPanelDrawBatch(panel, atlas, palette, batch);
	TuiImage out_image = tuiPanelGetImage(panel);
	char out_path[128];
	strcpy(out_path, kOutDirectoryPath);
	strcpy(out_path, blend_name);
	strcat(out_path, ".png");
	tuiImageSave(out_image, out_path);
	tuiBatchDestroy(batch);
	tuiPaletteDestroy(palette);
	tuiAtlasDestroy(atlas);
	tuiImageDestroy(out_image);	
	printf("%s\n", blend_name);
}

void test_DetailMode(TuiDetailMode detail_mode, TuiPanel panel)
{
	tuiPanelClearColor(panel, 0, 0, 0, 255);
	const char* detail_name = tuiDetailModeToString(detail_mode);
	TuiBatch batch = test_GetTestPatternBatch(detail_mode);
	TuiPalette palette = NULL;
	if (tuiDetailHasPalette(detail_mode) == TUI_TRUE)
	{
		 palette = tuiPaletteCreateXterm(256);
	}
	TuiBlendMode blend_mode = TUI_BLEND_FG_GREEN;
	if (tuiModesAreCompatible(detail_mode, TUI_BLEND_FG_GREEN) == TUI_FALSE)
	{
		 blend_mode = TUI_BLEND_NORMAL;
	}
	TuiAtlas atlas = test_CreateCodepageAtlas(blend_mode);
	tuiPanelClearColor(panel, 0, 0, 0, 255);
	tuiPanelDrawBatch(panel, atlas, palette, batch);
	TuiImage out_image = tuiPanelGetImage(panel);
	char out_path[128];
	strcpy(out_path, kOutDirectoryPath);
	strcpy(out_path, detail_name);
	strcat(out_path, ".png");
	tuiImageSave(out_image, out_path);
	tuiBatchDestroy(batch);
	if (tuiDetailHasPalette(detail_mode) == TUI_TRUE)
	{
		tuiPaletteDestroy(palette);
	}
	tuiAtlasDestroy(atlas);
	tuiImageDestroy(out_image);	
	printf("%s\n",detail_name);
}

void test_Palette(int palette_channel_count, TuiPanel panel)
{
	tuiPanelClearColor(panel, 0, 0, 0, 255);
	char palette_type_name[16];
	snprintf(palette_type_name, 16, "PALETTE_%d", palette_channel_count);
	TuiBatch batch = test_GetTestPatternBatch(TUI_DETAIL_G8_C4_FULL);
	uint8_t* palette_colors = new uint8_t[static_cast<size_t>(palette_channel_count) * 16]();
	for (size_t color_i = 0; color_i < 16; color_i++)
	{
		size_t channel_i = color_i * palette_channel_count;
		palette_colors[channel_i++] = 15 * (16 % (color_i + 1));
		palette_colors[channel_i++] = 15 * (15 - (16 % (color_i + 1)));
		palette_colors[channel_i] = 0;
		if (palette_channel_count == 4)
		{
			palette_colors[++channel_i] = 15 * (256 % (color_i + 1));
		}
	}
	TuiPalette palette = tuiPaletteCreate(palette_channel_count, 16, palette_colors);
	delete[] palette_colors;
	TuiAtlas atlas = test_CreateCodepageAtlas(TUI_BLEND_BG_ALPHA);
	tuiPanelClearColor(panel, 0, 0, 255, 255);
	tuiPanelDrawBatch(panel, atlas, palette, batch);
	TuiImage out_image = tuiPanelGetImage(panel);
	char out_path[128];
	strcpy(out_path, kOutDirectoryPath);
	strcpy(out_path, palette_type_name);
	strcat(out_path, ".png");
	tuiImageSave(out_image, out_path);
	tuiBatchDestroy(batch);
	tuiPaletteDestroy(palette );
	tuiAtlasDestroy(atlas);
	tuiImageDestroy(out_image);
	printf("%s\n",palette_type_name);
}