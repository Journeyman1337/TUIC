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
#include <string.h>

#define TO_STRING(value) #value

const char* kTui_Glyph_Flag_G8_Name = TO_STRING(TUI_GLYPH_FLAG_G8);

const char* kTui_Glyph_Flag_G16_Name = TO_STRING(TUI_GLYPH_FLAG_G16);

const char* kTui_Color_Flag_C0_Name = TO_STRING(TUI_COLOR_FLAG_C0);

const char* kTui_Color_Flag_C4_Name = TO_STRING(TUI_COLOR_FLAG_C4);

const char* kTui_Color_Flag_C8_Name = TO_STRING(TUI_COLOR_FLAG_C8);

const char* kTui_Color_Flag_C8NBG_Name = TO_STRING(TUI_COLOR_FLAG_C8NBG);

const char* kTui_Color_Flag_C8NFG_Name = TO_STRING(TUI_COLOR_FLAG_C8NFG);

const char* kTui_Color_Flag_C24_Name = TO_STRING(TUI_COLOR_FLAG_C24);

const char* kTui_Color_Flag_C24NBG_Name = TO_STRING(TUI_COLOR_FLAG_C24NBG);

const char* kTui_Color_Flag_C24NFG_Name = TO_STRING(TUI_COLOR_FLAG_C24NFG);

const char* kTui_Color_Flag_C32_Name = TO_STRING(TUI_COLOR_FLAG_C32);

const char* kTui_Color_Flag_C32NBG_Name = TO_STRING(TUI_COLOR_FLAG_C32NBG);

const char* kTui_Color_Flag_C32NFG_Name = TO_STRING(TUI_COLOR_FLAG_C32NFG);

const char* kTui_Layout_Flag_Full_Name = TO_STRING(TUI_LAYOUT_FLAG_FULL);

const char* kTui_Layout_Flag_Sparse_Name = TO_STRING(TUI_LAYOUT_FLAG_SPARSE);
 
const size_t kTui_Detail_G8_C0_Size = 1;

const size_t kTui_Detail_G8_C4_Size = 2;

const size_t kTui_Detail_G8_C8_Size = 3;

const size_t kTui_Detail_G8_C8NBG_Size = 2;

const size_t kTui_Detail_G8_C8NFG_Size = 2;

const size_t kTui_Detail_G8_C24_Size = 7;

const size_t kTui_Detail_G8_C24NBG_Size = 4;

const size_t kTui_Detail_G8_C24NFG_Size = 4;

const size_t kTui_Detail_G8_C32_Size = 9;

const size_t kTui_Detail_G8_C32NBG_Size = 5;

const size_t kTui_Detail_G8_C32NFG_Size = 5;

const size_t kTui_Detail_G16_C0_Size = 2;

const size_t kTui_Detail_G16_C4_Size = 3;

const size_t kTui_Detail_G16_C8_Size = 4;

const size_t kTui_Detail_G16_C8NBG_Size = 3;

const size_t kTui_Detail_G16_C8NFG_Size = 3;

const size_t kTui_Detail_G16_C24_Size = 8;

const size_t kTui_Detail_G16_C24NBG_Size = 5;

const size_t kTui_Detail_G16_C24NFG_Size = 5;

const size_t kTui_Detail_G16_C32_Size = 10;

const size_t kTui_Detail_G16_C32NBG_Size = 6;

const size_t kTui_Detail_G16_C32NFG_Size = 6;

const char* kTui_Detail_G8_C0_Full_Name = TO_STRING(TUI_DETAIL_G8_C0_FULL);

const char* kTui_Detail_G8_C4_Full_Name = TO_STRING(TUI_DETAIL_G8_C4_FULL);

const char* kTui_Detail_G8_C8_Full_Name = TO_STRING(TUI_DETAIL_G8_C8_FULL);

const char* kTui_Detail_G8_C8NBG_Full_Name = TO_STRING(TUI_DETAIL_G8_C8NBG_FULL);

const char* kTui_Detail_G8_C8NFG_Full_Name = TO_STRING(TUI_DETAIL_G8_C8NFG_FULL);

const char* kTui_Detail_G8_C24_Full_Name = TO_STRING(TUI_DETAIL_G8_C24_FULL);

const char* kTui_Detail_G8_C24NBG_Full_Name = TO_STRING(TUI_DETAIL_G8_C24NBG_FULL);

const char* kTui_Detail_G8_C24NFG_Full_Name = TO_STRING(TUI_DETAIL_G8_C24NFG_FULL);

const char* kTui_Detail_G8_C32_Full_Name = TO_STRING(TUI_DETAIL_G8_C32_FULL);

const char* kTui_Detail_G8_C32NBG_Full_Name = TO_STRING(TUI_DETAIL_G8_C32NBG_FULL);

const char* kTui_Detail_G8_C32NFG_Full_Name = TO_STRING(TUI_DETAIL_G8_C32NFG_FULL);

const char* kTui_Detail_G16_C0_Full_Name = TO_STRING(TUI_DETAIL_G16_C0_FULL);

const char* kTui_Detail_G16_C4_Full_Name = TO_STRING(TUI_DETAIL_G16_C4_FULL);

const char* kTui_Detail_G16_C8_Full_Name = TO_STRING(TUI_DETAIL_G16_C8_FULL);

const char* kTui_Detail_G16_C8NBG_Full_Name = TO_STRING(TUI_DETAIL_G16_C8NBG_FULL);

const char* kTui_Detail_G16_C8NFG_Full_Name = TO_STRING(TUI_DETAIL_G16_C8NFG_FULL);

const char* kTui_Detail_G16_C24_Full_Name = TO_STRING(TUI_DETAIL_G16_C24_FULL);

const char* kTui_Detail_G16_C24NBG_Full_Name = TO_STRING(TUI_DETAIL_G16_C24NBG_FULL);

const char* kTui_Detail_G16_C24NFG_Full_Name = TO_STRING(TUI_DETAIL_G16_C24NFG_FULL);

const char* kTui_Detail_G16_C32_Full_Name = TO_STRING(TUI_DETAIL_G16_C32_FULL);

const char* kTui_Detail_G16_C32NBG_Full_Name = TO_STRING(TUI_DETAIL_G16_C32NBG_FULL);

const char* kTui_Detail_G16_C32NFG_Full_Name = TO_STRING(TUI_DETAIL_G16_C32NFG_FULL);

const char* kTui_Detail_G8_C0_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C0_SPARSE);

const char* kTui_Detail_G8_C4_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C4_SPARSE);

const char* kTui_Detail_G8_C8_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C8_SPARSE);

const char* kTui_Detail_G8_C8NBG_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C8NBG_SPARSE);

const char* kTui_Detail_G8_C8NFG_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C8NFG_SPARSE);

const char* kTui_Detail_G8_C24_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C24_SPARSE);

const char* kTui_Detail_G8_C24NBG_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C24NBG_SPARSE);

const char* kTui_Detail_G8_C24NFG_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C24NFG_SPARSE);

const char* kTui_Detail_G8_C32_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C32_SPARSE);

const char* kTui_Detail_G8_C32NBG_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C32NBG_SPARSE);

const char* kTui_Detail_G8_C32NFG_Sparse_Name = TO_STRING(TUI_DETAIL_G8_C32NFG_SPARSE);

const char* kTui_Detail_G16_C0_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C0_SPARSE);

const char* kTui_Detail_G16_C4_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C4_SPARSE);

const char* kTui_Detail_G16_C8_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C8_SPARSE);

const char* kTui_Detail_G16_C8NBG_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C8NBG_SPARSE);

const char* kTui_Detail_G16_C8NFG_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C8NFG_SPARSE);

const char* kTui_Detail_G16_C24_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C24_SPARSE);

const char* kTui_Detail_G16_C24NBG_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C24NBG_SPARSE);

const char* kTui_Detail_G16_C24NFG_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C24NFG_SPARSE);

const char* kTui_Detail_G16_C32_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C32_SPARSE);

const char* kTui_Detail_G16_C32NBG_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C32NBG_SPARSE);

const char* kTui_Detail_G16_C32NFG_Sparse_Name = TO_STRING(TUI_DETAIL_G16_C32NFG_SPARSE);

const char* KTui_Texture_RGB_Name = TO_STRING(TUI_TEXTURE_RGB);

const char* kTui_Texture_RGBA_Name = TO_STRING(TUI_TEXTURE_RGBA);

const char* kTui_Atlas_COORDS_Name = TO_STRING(TUI_ATLAS_COORDS);

const char* kTui_Atlas_GRID_Name = TO_STRING(TUI_ATLAS_GRID);

const char* kTui_Palette_RGB_Name = TO_STRING(TUI_PALETTE_RGB);

const char* kTui_Palette_RGBA_Name = TO_STRING(TUI_PALETTE_RGBA);

const char* kTui_Blend_NORMAL_Name = TO_STRING(TUI_BLEND_NORMAL);

const char* kTui_Blend_FG_RED_Name = TO_STRING(TUI_BLEND_FG_RED);

const char* kTui_Blend_FG_GREEN_Name = TO_STRING(TUI_BLEND_FG_GREEN);

const char* kTui_Blend_FG_BLUE_Name = TO_STRING(TUI_BLEND_FG_BLUE);

const char* kTui_Blend_FG_ALPHA_Name = TO_STRING(TUI_BLEND_FG_ALPHA);

const char* kTui_Blend_BG_RED_Name = TO_STRING(TUI_BLEND_BG_RED);

const char* kTui_Blend_BG_GREEN_Name = TO_STRING(TUI_BLEND_BG_GREEN);

const char* kTui_Blend_BG_BLUE_Name = TO_STRING(TUI_BLEND_BG_BLUE);

const char* kTui_Blend_BG_ALPHA_Name = TO_STRING(TUI_BLEND_BG_ALPHA);

const char* kTui_Filter_Point_Name = TO_STRING(TUI_FILTER_POINT);

const char* kTui_Filter_Bilinear_Name = TO_STRING(TUI_FILTER_BILINEAR);

const char* kTui_Draw_Static_Name = TO_STRING(TUI_DRAW_STATIC);

const char* kTui_Draw_Dynamic_Name = TO_STRING(TUI_DRAW_DYNAMIC);

const char* kTui_Draw_Stream_Name = TO_STRING(TUI_DRAW_STREAM);

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

int tuiDetailHasFlag(int detail_mode, int detail_flag)
{
	if ((detail_mode & detail_flag) == detail_flag)
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

int tuiAtlasTypeIsValid(int atlas_type)
{
	if (
		(atlas_type == TUI_ATLAS_COORDS) ||
		(atlas_type == TUI_ATLAS_GRID)
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

int tuiDetailFlagIsValid(int detail_flag)
{
	return detail_flag & (
		TUI_GLYPH_FLAG_G8 |
		TUI_GLYPH_FLAG_G16 |
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
		TUI_COLOR_FLAG_C32NFG |
		TUI_LAYOUT_FLAG_FULL |
		TUI_LAYOUT_FLAG_SPARSE);
}

int tuiFilterModeIsValid(int filter_mode)
{
	if (
		filter_mode == TUI_FILTER_POINT ||
		filter_mode == TUI_FILTER_BILINEAR
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

int tuiDrawModeIsValid(int draw_mode)
{
	if (
		draw_mode == TUI_DRAW_STATIC ||
		draw_mode == TUI_DRAW_DYNAMIC ||
		draw_mode == TUI_DRAW_STREAM
		)
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

const char* tuiDetailFlagToString(int detail_flag)
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
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_FLAG, __func__);
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
	else if (strcmp(string, kTui_Color_Flag_C32NFG_Name) == 0)
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

const char* tuiDetailModeToString(int detail_mode)
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
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
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

const char* tuiBlendModeToString(int blend_mode)
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
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
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

const char* tuiAtlasTypeToString(int atlas_type)
{
	switch (atlas_type)
	{
	case TUI_ATLAS_COORDS:
		return kTui_Atlas_COORDS_Name;
	case TUI_ATLAS_GRID:
		return kTui_Atlas_GRID_Name;
	default:
		tuiDebugError(TUI_ERROR_INVALID_ATLAS_TYPE, __func__);
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

const char* tuiFilterModeToString(int filter_mode)
{
	switch (filter_mode)
	{
	case TUI_FILTER_POINT:
		return kTui_Filter_Point_Name;
	case TUI_FILTER_BILINEAR:
		return kTui_Filter_Bilinear_Name;
	default:
		//TODO tuiDebugError(TUI_ERROR_INVALID_FILTER_MODE, __func__);
		return NULL;
	}
}

int tuiStringToFilterMode(const char* string)
{
	if (strcmp(string, kTui_Filter_Point_Name) == 0)
	{
		return TUI_FILTER_POINT;
	}
	else if (strcmp(string, kTui_Filter_Bilinear_Name) == 0)
	{
		return TUI_FILTER_BILINEAR;
	}
	return 0;
}

const char* tuiDrawModeToString(int draw_mode)
{
	switch (draw_mode)
	{
	case TUI_DRAW_STATIC:
		return kTui_Draw_Static_Name;
	case TUI_DRAW_DYNAMIC:
		return kTui_Draw_Dynamic_Name;
	case TUI_DRAW_STREAM:
		return kTui_Draw_Stream_Name;
	default:
		//TODO tuiDebugError(TUI_ERROR_INVALID_DRAW_MODE, __func__);
		return NULL;
	}
}

int tuiStringToDrawMode(const char* string)
{
	if (strcmp(string, kTui_Draw_Static_Name) == 0)
	{
		return TUI_DRAW_STATIC;
	}
	else if (strcmp(string, kTui_Draw_Dynamic_Name) == 0)
	{
		return TUI_DRAW_DYNAMIC;
	}
	else if (strcmp(string, kTui_Draw_Stream_Name) == 0)
	{
		return TUI_DRAW_STREAM;
	}
	return 0;
}


