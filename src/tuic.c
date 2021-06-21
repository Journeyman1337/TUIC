/*
	Copyright (c) 2021 Daniel Valcour
	
	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <TUIC/tuic.h>
#include <TUIC/backends/objects.h>

#include <stdio.h>
#include <string.h>

void tui_default_debug_message(const char* message) {}

static tuiDebugCallback sDebugCallback = tui_default_debug_message;

void tuiSetDebugCallback(tuiDebugCallback callback)
{
	if (callback == NULL)
	{
		sDebugCallback = tui_default_debug_message;
	}
	else
	{
		sDebugCallback = callback;
	}
}

void tuiDebugMessage(const char* message)
{
	if (sDebugCallback != NULL)
	{
		sDebugCallback(message);
	}
}

void tuiInstanceDestroy(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	if (instance->PanelCount > 0)
	{
		tuiDebugMessage("TuiInstance destroyed with one or more TuiPanel still attached.");
	}
	if (instance->GlyphAtlasCount > 0)
	{
		tuiDebugMessage("TuiInstance destroyed with one or more TuiGlyphAtlas still attached.");
	}
	if (instance->PaletteCount > 0)
	{
		tuiDebugMessage("TuiInstance destroyed with one or more TuiPalette still attached.");
	}
	instance->InstanceDestroy(instance);
	tuiFree(instance);
}

void tuiInstanceClearColor(TuiInstance instance, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	instance->InstanceClearColor(instance, r, g, b, a);
}

void tuiInstanceSetDamaged(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	instance->IsDamaged = TUI_TRUE;
}

void tuiInstanceResizeScreen(TuiInstance instance, int screen_width, int screen_height)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	if (screen_width <= 0 || screen_height <= 0)
	{
		tuiDebugMessage("Can not resize instance main screen with dimensions less than or equal to 0.");
	}
	instance->PixelWidth = (int)screen_width;
	instance->PixelHeight = (int)screen_height;
	instance->InstanceResizeScreen(instance, screen_width, screen_height);
}

int tuiInstanceGetScreenPixelWidth(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return 0;
	}
	return (size_t)instance->PixelWidth;
}

int tuiInstanceGetScreenPixelHeight(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return 0;
	}
	return (size_t)instance->PixelHeight;
}

void tuiInstanceGetScreenPixelDimensons(TuiInstance instance, int* width, int* height)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	if (width != NULL)
	{
		*width = instance->PixelWidth;
	}
	if (height != NULL)
	{
		*height = instance->PixelHeight;
	}
}

void tuiInstanceDrawBatch(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch, int blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugMessage("atlas is NULL.");
		return;
	}
	if (batch == NULL)
	{
		tuiDebugMessage("batch is NULL.");
		return;
	}
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}
	if (tuiDetailHasPalette(batch->DetailMode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugMessage("batch detail mode requires palette but it is NULL.");
		return;
	}

	instance->InstanceDrawBatchData(instance, atlas, palette, batch->DetailMode, blend_mode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, 0, instance->PixelWidth, 0, instance->PixelHeight);
}

void tuiInstanceDrawBatchData(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, int detail_mode, int blend_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}
	if (batch_data == NULL)
	{
		tuiDebugMessage("batch data is NULL.");
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugMessage("Can not render batch data with tile width or tile height less than or equal to 0.");
		return;
	}

	instance->InstanceDrawBatchData(instance, atlas, palette, (size_t)detail_mode, (size_t)blend_mode, (size_t)tiles_wide, (size_t)tiles_tall, (size_t)sparse_index, batch_data, 0, instance->PixelWidth, 0, instance->PixelHeight);

}

void tuiInstanceDrawBatchTransformed(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch, int blend_mode, int left_x, int right_x, int top_y, int bottom_y)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugMessage("atlas is NULL.");
		return;
	}
	if (batch == NULL)
	{
		tuiDebugMessage("batch is NULL.");
		return;
	}
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}
	if (tuiDetailHasPalette(batch->DetailMode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugMessage("batch detail mode requires palette but it is NULL.");
		return;
	}

	instance->InstanceDrawBatchData(instance, atlas, palette, batch->DetailMode, (size_t)blend_mode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, left_x, right_x, top_y, bottom_y);
}

void tuiInstanceDrawBatchDataTransformed(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, int detail_mode, int blend_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y)
{
	if (instance == NULL)
	{
		tuiDebugMessage("instance is NULL.");
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}
	if (batch_data == NULL)
	{
		tuiDebugMessage("batch data is NULL.");
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugMessage("Can not render batch data with tile width or tile height less than or equal to 0.");
		return;
	}

	instance->InstanceDrawBatchData(instance, atlas, palette, (size_t)detail_mode, (size_t)blend_mode, (size_t)tiles_wide, (size_t)tiles_tall, sparse_index, batch_data, left_x, right_x, top_y, bottom_y);
}

int tuiDetailHasPalette(int detail_mode)
{
	if (tuiDetailHasFlag(detail_mode, TUI_COLOR_FLAG_C24) == TUI_FALSE && tuiDetailHasFlag(detail_mode, TUI_COLOR_FLAG_C0) == TUI_FALSE)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

int tuiDetailIsValid(int detail_mode)
{
	if (
			(detail_mode == TUI_DETAIL_G8_C0_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C4_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C8_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C8NBG_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C8NFG_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C24_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C24NBG_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C24NFG_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C32_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C32NBG_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C32NFG_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C0_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C4_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C8_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C8NBG_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C8NFG_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C24_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C24NBG_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C24NFG_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C32_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C32NBG_FULL) ||
			(detail_mode == TUI_DETAIL_G16_C32NFG_FULL) ||
			(detail_mode == TUI_DETAIL_G8_C0_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C4_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C8_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C8NBG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C8NFG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C24_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C24NBG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C24NFG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C32_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C32NBG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G8_C32NFG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C0_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C4_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C8_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C8NBG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C8NFG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C24_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C24NBG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C24NFG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C32_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C32NBG_SPARSE) ||
			(detail_mode == TUI_DETAIL_G16_C32NFG_SPARSE)
	)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

int tuiDetailHasFlag(int detail_mode, int flag)
{
	if ((detail_mode & flag) == flag)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

int tuiBlendIsValid(int blend_mode)
{
	if (
		(blend_mode == TUI_BLEND_NORMAL) ||
		(blend_mode == TUI_BLEND_BG_RED) ||
		(blend_mode == TUI_BLEND_BG_GREEN) ||
		(blend_mode == TUI_BLEND_BG_BLUE) ||
		(blend_mode == TUI_BLEND_BG_ALPHA) ||
		(blend_mode == TUI_BLEND_FG_RED) ||
		(blend_mode == TUI_BLEND_FG_GREEN) ||
		(blend_mode == TUI_BLEND_FG_BLUE) ||
		(blend_mode == TUI_BLEND_FG_ALPHA)
	)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

uint8_t tuiClassicColorGetForeground(uint8_t fg_and_bg)
{
	return fg_and_bg % 16;
}

uint8_t tuiClassicColorGetBackground(uint8_t fg_and_bg)
{
	return fg_and_bg / 16;
}

uint8_t tuiClassicColorCombine(uint8_t fg, uint8_t bg)
{
	return fg + (bg * 16);
}

int tuiTextureFormatIsValid(int tui_texture_format)
{
	if (tui_texture_format == TUI_TEXTURE_RGB || tui_texture_format == TUI_TEXTURE_RGBA)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

int tuiDetailGetGlyphFlag(int detail_mode)
{
	return detail_mode & (
		TUI_GLYPH_FLAG_G8 | 
		TUI_GLYPH_FLAG_G16);
}
 
int tuiDetailGetColorFlag(int detail_mode)
{
	return detail_mode & (
		TUI_COLOR_FLAG_C0 |
		TUI_COLOR_FLAG_C4 |
		TUI_COLOR_FLAG_C8 | 
		TUI_COLOR_FLAG_C8NBG |
		TUI_COLOR_FLAG_C8NFG |
		TUI_COLOR_FLAG_C24 | 
		TUI_COLOR_FLAG_C24NBG | 
		TUI_COLOR_FLAG_C24NFG |
		TUI_COLOR_FLAG_C32 |
		TUI_COLOR_FLAG_C32NBG |
		TUI_COLOR_FLAG_C32NFG);
}
 
int tuiDetailGetLayoutFlag(int detail_mode)
{
	return detail_mode & (
		TUI_LAYOUT_FLAG_FULL |
		TUI_LAYOUT_FLAG_SPARSE);
}
 
size_t tuiDetailGetTileByteSize(int glyph_flag, int color_flag)
{
	switch (glyph_flag)
	{
	case TUI_GLYPH_FLAG_G8:
		switch (color_flag)
		{
			case TUI_COLOR_FLAG_C0:
				return kTui_Detail_G8_C0_Size;
			case TUI_COLOR_FLAG_C4:
				return kTui_Detail_G8_C4_Size;
			case TUI_COLOR_FLAG_C8:
				return kTui_Detail_G8_C8_Size;
			case TUI_COLOR_FLAG_C8NBG:
				return kTui_Detail_G8_C8NBG_Size;
			case TUI_COLOR_FLAG_C8NFG:
				return kTui_Detail_G8_C8NFG_Size;
			case TUI_COLOR_FLAG_C24:
				return kTui_Detail_G8_C24_Size;
			case TUI_COLOR_FLAG_C24NBG:
				return kTui_Detail_G8_C24NBG_Size;
			case TUI_COLOR_FLAG_C24NFG:
				return kTui_Detail_G8_C24NFG_Size;
			case TUI_COLOR_FLAG_C32:
				return kTui_Detail_G8_C32_Size;
			case TUI_COLOR_FLAG_C32NBG:
				return kTui_Detail_G8_C32NBG_Size;
			case TUI_COLOR_FLAG_C32NFG:
				return kTui_Detail_G8_C32NFG_Size;
		}
		break;
	case TUI_GLYPH_FLAG_G16:
		switch (color_flag)
		{
		case TUI_COLOR_FLAG_C0:
			return kTui_Detail_G16_C0_Size;
		case TUI_COLOR_FLAG_C4:
			return kTui_Detail_G16_C4_Size;
		case TUI_COLOR_FLAG_C8:
			return kTui_Detail_G16_C8_Size;
		case TUI_COLOR_FLAG_C8NBG:
			return kTui_Detail_G16_C8NBG_Size;
		case TUI_COLOR_FLAG_C8NFG:
			return kTui_Detail_G16_C8NFG_Size;
		case TUI_COLOR_FLAG_C24:
			return kTui_Detail_G16_C24_Size;
		case TUI_COLOR_FLAG_C24NBG:
			return kTui_Detail_G16_C24NBG_Size;
		case TUI_COLOR_FLAG_C24NFG:
			return kTui_Detail_G16_C24NFG_Size;
		case TUI_COLOR_FLAG_C32:
			return kTui_Detail_G16_C32_Size;
		case TUI_COLOR_FLAG_C32NBG:
			return kTui_Detail_G16_C32NBG_Size;
		case TUI_COLOR_FLAG_C32NFG:
			return kTui_Detail_G16_C32NFG_Size;
		}
		break;
	}
	return 0;
}

int tuiModesAreCompatible(int detail_mode, int blend_mode)
{
	if (blend_mode == TUI_BLEND_NORMAL)
	{
		if (tuiDetailHasFlag(detail_mode, TUI_COLOR_FLAG_C0) == TUI_TRUE)
		{
			return TUI_TRUE;
		}
		else
		{
			return TUI_FALSE;
		}
	}
	else if (tuiDetailHasFlag(detail_mode, TUI_COLOR_FLAG_C0) == TUI_TRUE)
	{
		return TUI_FALSE;
	}
	return TUI_TRUE;
}

const char* tuiDetailFlagAsString(int detail_flag)
{
	switch (detail_flag)
	{
	case TUI_GLYPH_FLAG_G8:
		return kTui_Glyph_Flag_G8_Name;
	case TUI_GLYPH_FLAG_G16:
		return kTui_Glyph_Flag_G16_Name;
	case TUI_COLOR_FLAG_C0:
		return kTui_Color_Flag_C0_Name;
	case TUI_COLOR_FLAG_C4:
		return kTui_Color_Flag_C4_Name;
	case TUI_COLOR_FLAG_C8:
		return kTui_Color_Flag_C8_Name;
	case TUI_COLOR_FLAG_C8NBG:
		return kTui_Color_Flag_C8NBG_Name;
	case TUI_COLOR_FLAG_C8NFG:
		return kTui_Color_Flag_C8NFG_Name;
	case TUI_COLOR_FLAG_C24:
		return kTui_Color_Flag_C24_Name;
	case TUI_COLOR_FLAG_C24NBG:
		return kTui_Color_Flag_C24NBG_Name;
	case TUI_COLOR_FLAG_C24NFG:
		return kTui_Color_Flag_C24NFG_Name;
	case TUI_COLOR_FLAG_C32:
		return kTui_Color_Flag_C32_Name;
	case TUI_COLOR_FLAG_C32NBG:
		return kTui_Color_Flag_C32NBG_Name;
	case TUI_COLOR_FLAG_C32NFG:
		return kTui_Color_Flag_C32NFG_Name;
	case TUI_LAYOUT_FLAG_FULL:
		return kTui_Layout_Flag_Full_Name;
	case TUI_LAYOUT_FLAG_SPARSE:
		return kTui_Layout_Flag_Sparse_Name;
	default:
		tuiDebugMessage("Can not get name of invalid detail flag.");
		return NULL;
	}
}

int tuiStringToDetailFlag(const char* string)
{
	if (strcmp(string, kTui_Glyph_Flag_G8_Name) == 0)
	{
		return TUI_GLYPH_FLAG_G8;
	}
	else if (strcmp(string, kTui_Glyph_Flag_G16_Name) == 0)
	{
		return TUI_GLYPH_FLAG_G16;
	}
	else if (strcmp(string, kTui_Color_Flag_C0_Name) == 0)
	{
		return TUI_COLOR_FLAG_C0;
	}
	else if (strcmp(string, kTui_Color_Flag_C4_Name) == 0)
	{
		return TUI_COLOR_FLAG_C4;
	}
	else if (strcmp(string, kTui_Color_Flag_C8_Name) == 0)
	{
		return TUI_COLOR_FLAG_C8;
	}
	else if (strcmp(string, kTui_Color_Flag_C8NBG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C8NBG;
	}
	else if (strcmp(string, kTui_Color_Flag_C8NFG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C8NFG;
	}
	else if (strcmp(string, kTui_Color_Flag_C24_Name) == 0)
	{
		return TUI_COLOR_FLAG_C24;
	}
	else if (strcmp(string, kTui_Color_Flag_C24NBG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C24NBG;
	}
	else if (strcmp(string, kTui_Color_Flag_C24NFG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C24NFG;
	}
	else if (strcmp(string, kTui_Color_Flag_C32_Name) == 0)
	{
		return TUI_COLOR_FLAG_C32;
	}
	else if (strcmp(string, kTui_Color_Flag_C32NBG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C32NBG;
	}
	else if (strcmp(string, kTui_Color_Flag_C32NFG_Name))
	{
		return TUI_COLOR_FLAG_C32NFG;
	}
	else if (strcmp(string, kTui_Layout_Flag_Full_Name) == 0)
	{
		return TUI_LAYOUT_FLAG_FULL;
	}
	else if (strcmp(string, kTui_Layout_Flag_Sparse_Name) == 0)
	{
		return TUI_LAYOUT_FLAG_SPARSE;
	}
	return 0;
}

const char* tuiDetailModeAsString(int detail_mode)
{
	switch (detail_mode)
	{
	case TUI_DETAIL_G8_C0_FULL:
		return kTui_Detail_G8_C0_Full_Name;
	case TUI_DETAIL_G8_C4_FULL:
		return kTui_Detail_G8_C4_Full_Name;
	case TUI_DETAIL_G8_C8_FULL:
		return kTui_Detail_G8_C8_Full_Name;
	case TUI_DETAIL_G8_C8NBG_FULL:
		return kTui_Detail_G8_C8NBG_Full_Name;
	case TUI_DETAIL_G8_C8NFG_FULL:
		return kTui_Detail_G8_C8NFG_Full_Name;
	case TUI_DETAIL_G8_C24_FULL:
		return kTui_Detail_G8_C24_Full_Name;
	case TUI_DETAIL_G8_C24NBG_FULL:
		return kTui_Detail_G8_C24NBG_Full_Name;
	case TUI_DETAIL_G8_C24NFG_FULL:
		return kTui_Detail_G8_C24NFG_Full_Name;
	case TUI_DETAIL_G8_C32_FULL:
		return kTui_Detail_G8_C32_Full_Name;
	case TUI_DETAIL_G8_C32NBG_FULL:
		return kTui_Detail_G8_C32NBG_Full_Name;
	case TUI_DETAIL_G8_C32NFG_FULL:
		return kTui_Detail_G8_C32NFG_Full_Name;
	case TUI_DETAIL_G16_C0_FULL:
		return kTui_Detail_G16_C0_Full_Name;
	case TUI_DETAIL_G16_C4_FULL:
		return kTui_Detail_G16_C4_Full_Name;
	case TUI_DETAIL_G16_C8_FULL:
		return kTui_Detail_G16_C8_Full_Name;
	case TUI_DETAIL_G16_C8NBG_FULL:
		return kTui_Detail_G16_C8NBG_Full_Name;
	case TUI_DETAIL_G16_C8NFG_FULL:
		return kTui_Detail_G16_C8NFG_Full_Name;
	case TUI_DETAIL_G16_C24_FULL:
		return kTui_Detail_G16_C24_Full_Name;
	case TUI_DETAIL_G16_C24NBG_FULL:
		return kTui_Detail_G16_C24NBG_Full_Name;
	case TUI_DETAIL_G16_C24NFG_FULL:
		return kTui_Detail_G16_C24NFG_Full_Name;
	case TUI_DETAIL_G16_C32_FULL:
		return kTui_Detail_G16_C32_Full_Name;
	case TUI_DETAIL_G16_C32NBG_FULL:
		return kTui_Detail_G16_C32NBG_Full_Name;
	case TUI_DETAIL_G16_C32NFG_FULL:
		return kTui_Detail_G16_C32NFG_Full_Name;
	case TUI_DETAIL_G8_C0_SPARSE:
		return kTui_Detail_G8_C0_Sparse_Name;
	case TUI_DETAIL_G8_C4_SPARSE:
		return kTui_Detail_G8_C4_Sparse_Name;
	case TUI_DETAIL_G8_C8_SPARSE:
		return kTui_Detail_G8_C8_Sparse_Name;
	case TUI_DETAIL_G8_C8NBG_SPARSE:
		return kTui_Detail_G8_C8NBG_Sparse_Name;
	case TUI_DETAIL_G8_C8NFG_SPARSE:
		return kTui_Detail_G8_C8NFG_Sparse_Name;
	case TUI_DETAIL_G8_C24_SPARSE:
		return kTui_Detail_G8_C24_Sparse_Name;
	case TUI_DETAIL_G8_C24NBG_SPARSE:
		return kTui_Detail_G8_C24NBG_Sparse_Name;
	case TUI_DETAIL_G8_C24NFG_SPARSE:
		return kTui_Detail_G8_C24NFG_Sparse_Name;
	case TUI_DETAIL_G8_C32_SPARSE:
		return kTui_Detail_G8_C32_Sparse_Name;
	case TUI_DETAIL_G8_C32NBG_SPARSE:
		return kTui_Detail_G8_C32NBG_Sparse_Name;
	case TUI_DETAIL_G8_C32NFG_SPARSE:
		return kTui_Detail_G8_C32NFG_Sparse_Name;
	case TUI_DETAIL_G16_C0_SPARSE:
		return kTui_Detail_G16_C0_Sparse_Name;
	case TUI_DETAIL_G16_C4_SPARSE:
		return kTui_Detail_G16_C4_Sparse_Name;
	case TUI_DETAIL_G16_C8_SPARSE:
		return kTui_Detail_G16_C8_Sparse_Name;
	case TUI_DETAIL_G16_C8NBG_SPARSE:
		return kTui_Detail_G16_C8NBG_Sparse_Name;
	case TUI_DETAIL_G16_C8NFG_SPARSE:
		return kTui_Detail_G16_C8NFG_Sparse_Name;
	case TUI_DETAIL_G16_C24_SPARSE:
		return kTui_Detail_G16_C24_Sparse_Name;
	case TUI_DETAIL_G16_C24NBG_SPARSE:
		return kTui_Detail_G16_C24NBG_Sparse_Name;
	case TUI_DETAIL_G16_C24NFG_SPARSE:
		return kTui_Detail_G16_C24NFG_Sparse_Name;
	case TUI_DETAIL_G16_C32_SPARSE:
		return kTui_Detail_G16_C32_Sparse_Name;
	case TUI_DETAIL_G16_C32NBG_SPARSE:
		return kTui_Detail_G16_C32NBG_Sparse_Name;
	case TUI_DETAIL_G16_C32NFG_SPARSE:
		return kTui_Detail_G16_C32NFG_Sparse_Name;
	default:
		tuiDebugMessage("Can not get name of invalid detail mode.");
		return NULL;
	}
}

int tuiStringToDetailMode(const char* string)
{
	if (strcmp(string, kTui_Detail_G8_C0_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C0_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C4_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C4_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C8_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C8_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C8NBG_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C8NBG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C8NFG_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C8NFG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C24_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C24_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C24NBG_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C24NBG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C24NFG_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C24NFG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C32_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C32_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C32NBG_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C32NBG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C32NFG_Full_Name) == 0)
	{
		return TUI_DETAIL_G8_C32NFG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C0_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C0_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C4_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C4_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C8_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C8_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C8NBG_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C8NBG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C8NFG_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C8NFG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C24_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C24_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C24NBG_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C24NBG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C24NFG_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C24NFG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C32_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C32_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C32NBG_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C32NBG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G16_C32NFG_Full_Name) == 0)
	{
		return TUI_DETAIL_G16_C32NFG_FULL;
	}
	else if (strcmp(string, kTui_Detail_G8_C0_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C0_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C4_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C4_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C8_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C8_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C8NBG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C8NBG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C8NFG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C8NFG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C24_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C24_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C24NBG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C24NBG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C24NFG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C24NFG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C32_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C32_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C32NBG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C32NBG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G8_C32NFG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G8_C32NFG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C0_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C0_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C4_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C4_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C8_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C8_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C8NBG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C8NBG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C8NFG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C8NFG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C24_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C24_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C24NBG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C24NBG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C24NFG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C24NFG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C32_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C32_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C32NBG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C32NBG_SPARSE;
	}
	else if (strcmp(string, kTui_Detail_G16_C32NFG_Sparse_Name) == 0)
	{
		return TUI_DETAIL_G16_C32NFG_SPARSE;
	}
	return 0;
}

const char* tuiBlendModeAsString(int blend_mode)
{
	switch (blend_mode)
	{
	case TUI_BLEND_NORMAL:
		return kTui_Blend_NORMAL_Name;
	case TUI_BLEND_FG_RED:
		return kTui_Blend_FG_RED_Name;
	case TUI_BLEND_FG_GREEN:
		return kTui_Blend_FG_GREEN_Name;
	case TUI_BLEND_FG_BLUE:
		return kTui_Blend_FG_BLUE_Name;
	case TUI_BLEND_FG_ALPHA:
		return kTui_Blend_FG_ALPHA_Name;
	case TUI_BLEND_BG_RED:
		return kTui_Blend_BG_RED_Name;
	case TUI_BLEND_BG_GREEN:
		return kTui_Blend_BG_GREEN_Name;
	case TUI_BLEND_BG_BLUE:
		return kTui_Blend_BG_BLUE_Name;
	case TUI_BLEND_BG_ALPHA:
		return kTui_Blend_BG_ALPHA_Name;
	default:
		tuiDebugMessage("Can not get name of invalid blend mode.");
		return NULL;
	}
}


int tuiStringToBlendMode(const char* string)
{
	if (strcmp(string, kTui_Blend_NORMAL_Name) == 0)
	{
		return TUI_BLEND_NORMAL;
	}
	else if (strcmp(string, kTui_Blend_FG_RED_Name) == 0)
	{
		return TUI_BLEND_FG_RED;
	}
	else if (strcmp(string, kTui_Blend_FG_GREEN_Name) == 0)
	{
		return TUI_BLEND_FG_GREEN;
	}
	else if (strcmp(string, kTui_Blend_FG_BLUE_Name) == 0)
	{
		return TUI_BLEND_FG_BLUE;
	}
	else if (strcmp(string, kTui_Blend_FG_ALPHA_Name) == 0)
	{
		return TUI_BLEND_FG_ALPHA;
	}
	else if (strcmp(string, kTui_Blend_BG_RED_Name) == 0)
	{
		return TUI_BLEND_BG_RED;
	}
	else if (strcmp(string, kTui_Blend_BG_GREEN_Name) == 0)
	{
		return TUI_BLEND_BG_GREEN;
	}
	else if (strcmp(string, kTui_Blend_BG_BLUE_Name) == 0)
	{
		return TUI_BLEND_BG_BLUE;
	}
	else if (strcmp(string, kTui_Blend_BG_ALPHA_Name) == 0)
	{
		return TUI_BLEND_BG_ALPHA;
	}
	return 0;
}

const char* tuiTextureFormatAsString(int texture_format)
{
	switch (texture_format)
	{
	case TUI_TEXTURE_RGB:
		return KTui_Texture_RGB_Name;
	case TUI_TEXTURE_RGBA:
		return kTui_Texture_RGBA_Name;
	default:
		tuiDebugMessage("Can not get name of invalid texture format.");
		return NULL;
	}
}

int tuiStringToTextureFormat(const char* string)
{
	if (strcmp(string, KTui_Texture_RGB_Name) == 0)
	{
		return TUI_TEXTURE_RGB;
	}
	else if (strcmp(string, kTui_Texture_RGBA_Name) == 0)
	{
		return TUI_TEXTURE_RGBA;
	}
	return 0;
}

const char* tuiAtlasTypeAsString(int atlas_type)
{
	switch (atlas_type)
	{
	case TUI_ATLAS_COORDS:
		return kTui_Atlas_COORDS_Name;
	case TUI_ATLAS_GRID:
		return kTui_Atlas_GRID_Name;
	default:
		tuiDebugMessage("Can not get name of invalid atlas type.");
		return NULL;
	}
}

int tuiStringToAtlasType(const char* string)
{
	if (strcmp(string, kTui_Atlas_COORDS_Name) == 0)
	{
		return TUI_ATLAS_COORDS;
	}
	else if (strcmp(string, kTui_Atlas_GRID_Name) == 0)
	{
		return TUI_ATLAS_GRID;
	}
	return 0;
}

const char* tuiPaletteTypeAsString(int palette_type)
{
	switch (palette_type)
	{
	case TUI_PALETTE_RGB:
		return kTui_Palette_RGB_Name;
	case TUI_PALETTE_RGBA:
		return kTui_Palette_RGBA_Name;
	default:
		tuiDebugMessage("Can not get name of invalid palette type.");
		return NULL;
	}
}

int tuiStringToPaletteType(const char* string)
{
	if (strcmp(string, kTui_Palette_RGB_Name) == 0)
	{
		return TUI_PALETTE_RGB;
	}
	else if (strcmp(string, kTui_Palette_RGBA_Name) == 0)
	{
		return TUI_PALETTE_RGBA;
	}
	return 0;
}
