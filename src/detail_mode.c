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
#include <TUIC/types.h>
#include <TUIC/detail_mode.h>
#include <TUIC/blend_mode.h>
#include <TUIC/debug.h>
#include <TUIC/boolean.h>

#define TO_STRING(value) #value

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

TuiBoolean tuiDetailIsValid(TuiDetailMode detail_mode)
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

TuiBoolean tuiDetailHasFlag(TuiDetailMode detail_mode, TuiDetailFlag detail_flag)
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

TuiDetailFlag tuiDetailGetGlyphFlag(TuiDetailMode detail_mode)
{
	return detail_mode & (
		TUI_DETAIL_FLAG_GLYPH_8 |
		TUI_DETAIL_FLAG_GLYPH_16);
}

TuiDetailFlag tuiDetailGetColorFlag(TuiDetailMode detail_mode)
{
	return detail_mode & (
		TUI_DETAIL_FLAG_COLOR_0 |
		TUI_DETAIL_FLAG_COLOR_4 |
		TUI_DETAIL_FLAG_COLOR_8 |
		TUI_DETAIL_FLAG_COLOR_8NBG |
		TUI_DETAIL_FLAG_COLOR_8NFG |
		TUI_DETAIL_FLAG_COLOR_24 |
		TUI_DETAIL_FLAG_COLOR_24NBG |
		TUI_DETAIL_FLAG_COLOR_24NFG |
		TUI_DETAIL_FLAG_COLOR_32 |
		TUI_DETAIL_FLAG_COLOR_32NBG |
		TUI_DETAIL_FLAG_COLOR_32NFG);
}

TuiDetailFlag tuiDetailGetLayoutFlag(TuiDetailMode detail_mode)
{
	return detail_mode & (
		TUI_DETAIL_FLAG_LAYOUT_FULL |
		TUI_DETAIL_FLAG_LAYOUT_SPARSE);
}

size_t tuiDetailGetTileByteSize(TuiDetailFlag glyph_flag, TuiDetailFlag color_flag)
{
	switch (glyph_flag)
	{
	case TUI_DETAIL_FLAG_GLYPH_8:
		switch (color_flag)
		{
		case TUI_DETAIL_FLAG_COLOR_0:
			return kTui_Detail_G8_C0_Size;
		case TUI_DETAIL_FLAG_COLOR_4:
			return kTui_Detail_G8_C4_Size;
		case TUI_DETAIL_FLAG_COLOR_8:
			return kTui_Detail_G8_C8_Size;
		case TUI_DETAIL_FLAG_COLOR_8NBG:
			return kTui_Detail_G8_C8NBG_Size;
		case TUI_DETAIL_FLAG_COLOR_8NFG:
			return kTui_Detail_G8_C8NFG_Size;
		case TUI_DETAIL_FLAG_COLOR_24:
			return kTui_Detail_G8_C24_Size;
		case TUI_DETAIL_FLAG_COLOR_24NBG:
			return kTui_Detail_G8_C24NBG_Size;
		case TUI_DETAIL_FLAG_COLOR_24NFG:
			return kTui_Detail_G8_C24NFG_Size;
		case TUI_DETAIL_FLAG_COLOR_32:
			return kTui_Detail_G8_C32_Size;
		case TUI_DETAIL_FLAG_COLOR_32NBG:
			return kTui_Detail_G8_C32NBG_Size;
		case TUI_DETAIL_FLAG_COLOR_32NFG:
			return kTui_Detail_G8_C32NFG_Size;
		}
		break;
	case TUI_DETAIL_FLAG_GLYPH_16:
		switch (color_flag)
		{
		case TUI_DETAIL_FLAG_COLOR_0:
			return kTui_Detail_G16_C0_Size;
		case TUI_DETAIL_FLAG_COLOR_4:
			return kTui_Detail_G16_C4_Size;
		case TUI_DETAIL_FLAG_COLOR_8:
			return kTui_Detail_G16_C8_Size;
		case TUI_DETAIL_FLAG_COLOR_8NBG:
			return kTui_Detail_G16_C8NBG_Size;
		case TUI_DETAIL_FLAG_COLOR_8NFG:
			return kTui_Detail_G16_C8NFG_Size;
		case TUI_DETAIL_FLAG_COLOR_24:
			return kTui_Detail_G16_C24_Size;
		case TUI_DETAIL_FLAG_COLOR_24NBG:
			return kTui_Detail_G16_C24NBG_Size;
		case TUI_DETAIL_FLAG_COLOR_24NFG:
			return kTui_Detail_G16_C24NFG_Size;
		case TUI_DETAIL_FLAG_COLOR_32:
			return kTui_Detail_G16_C32_Size;
		case TUI_DETAIL_FLAG_COLOR_32NBG:
			return kTui_Detail_G16_C32NBG_Size;
		case TUI_DETAIL_FLAG_COLOR_32NFG:
			return kTui_Detail_G16_C32NFG_Size;
		}
		break;
	}
	return 0;
}

TuiBoolean tuiModesAreCompatible(TuiDetailMode detail_mode, TuiBlendMode blend_mode)
{
	if (blend_mode == TUI_BLEND_NORMAL)
	{
		if (tuiDetailHasFlag(detail_mode, TUI_DETAIL_FLAG_COLOR_0) == TUI_TRUE)
		{
			return TUI_TRUE;
		}
		else
		{
			return TUI_FALSE;
		}
	}
	else if (tuiDetailHasFlag(detail_mode, TUI_DETAIL_FLAG_COLOR_0) == TUI_TRUE)
	{
		return TUI_FALSE;
	}
	return TUI_TRUE;
}

TuiBoolean tuiDetailHasPalette(TuiDetailMode detail_mode)
{
	if (tuiDetailHasFlag(detail_mode, TUI_DETAIL_FLAG_COLOR_24) == TUI_FALSE && tuiDetailHasFlag(detail_mode, TUI_DETAIL_FLAG_COLOR_0) == TUI_FALSE)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

const char* tuiDetailModeToString(TuiDetailMode detail_mode)
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
		return TUI_NULL;
	}
}

TuiDetailMode tuiStringToDetailMode(const char* string)
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
