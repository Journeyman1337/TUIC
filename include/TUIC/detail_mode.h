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
/*! \file detail_mode.h
 */
#ifndef TUIC_DETAIL_MODE_H //header guard
#define TUIC_DETAIL_MODE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/detail_flag.h>

enum TuiDetailMode
{
	TUI_DETAIL_G8_C0_FULL =				(TUI_GLYPH_FLAG_G8 		| TUI_COLOR_FLAG_C0			| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C4_FULL =				(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C4			| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C8_FULL =				(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8			| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C8NBG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8NBG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C8NFG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8NFG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C24_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C24NBG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24NBG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C24NFG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24NFG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C32_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C32NBG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32NBG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C32NFG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32NFG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C0_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C0			| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C4_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C4			| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C8_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8			| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C8NBG_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8NBG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C8NFG_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8NFG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C24_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C24NBG_FULL =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24NBG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C24NFG_FULL =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24NFG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C32_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C32		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C32NBG_FULL =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C32NBG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G16_C32NFG_FULL =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C32NFG		| TUI_LAYOUT_FLAG_FULL),
	TUI_DETAIL_G8_C0_SPARSE =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C0			| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C4_SPARSE =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C4			| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C8_SPARSE =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8			| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C8NBG_SPARSE =		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8NBG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C8NFG_SPARSE =		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8NFG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C24_SPARSE =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C24NBG_SPARSE =		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24NBG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C24NFG_SPARSE =		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24NFG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C32_SPARSE = 			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C32NBG_SPARSE = 		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32NBG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G8_C32NFG_SPARSE = 		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32NFG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C0_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C0			| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C4_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C4			| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C8_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8			| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C8NBG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8NBG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C8NFG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8NFG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C24_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C24NBG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24NBG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C24NFG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24NFG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C32_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C32		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C32NBG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C32NBG		| TUI_LAYOUT_FLAG_SPARSE),
	TUI_DETAIL_G16_C32NFG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C32NFG		| TUI_LAYOUT_FLAG_SPARSE)
};

extern const size_t kTui_Detail_G8_C0_Size;
extern const size_t kTui_Detail_G8_C4_Size;
extern const size_t kTui_Detail_G8_C8_Size;
extern const size_t kTui_Detail_G8_C8NBG_Size;
extern const size_t kTui_Detail_G8_C8NFG_Size;
extern const size_t kTui_Detail_G8_C24_Size;
extern const size_t kTui_Detail_G8_C24NBG_Size;
extern const size_t kTui_Detail_G8_C24NFG_Size;
extern const size_t kTui_Detail_G8_C32_Size;
extern const size_t kTui_Detail_G8_C32NBG_Size;
extern const size_t kTui_Detail_G8_C32NFG_Size;
extern const size_t kTui_Detail_G16_C0_Size;
extern const size_t kTui_Detail_G16_C4_Size;
extern const size_t kTui_Detail_G16_C8_Size;
extern const size_t kTui_Detail_G16_C8NBG_Size;
extern const size_t kTui_Detail_G16_C8NFG_Size;
extern const size_t kTui_Detail_G16_C24_Size;
extern const size_t kTui_Detail_G16_C24NBG_Size;
extern const size_t kTui_Detail_G16_C24NFG_Size;
extern const size_t kTui_Detail_G16_C32_Size;
extern const size_t kTui_Detail_G16_C32NBG_Size;
extern const size_t kTui_Detail_G16_C32NFG_Size;

extern const char* kTui_Detail_G8_C0_Full_Name;
extern const char* kTui_Detail_G8_C4_Full_Name;
extern const char* kTui_Detail_G8_C8_Full_Name;
extern const char* kTui_Detail_G8_C8NBG_Full_Name;
extern const char* kTui_Detail_G8_C8NFG_Full_Name;
extern const char* kTui_Detail_G8_C24_Full_Name;
extern const char* kTui_Detail_G8_C24NBG_Full_Name;
extern const char* kTui_Detail_G8_C24NFG_Full_Name;
extern const char* kTui_Detail_G8_C32_Full_Name;
extern const char* kTui_Detail_G8_C32NBG_Full_Name;
extern const char* kTui_Detail_G8_C32NFG_Full_Name;
extern const char* kTui_Detail_G16_C0_Full_Name;
extern const char* kTui_Detail_G16_C4_Full_Name;
extern const char* kTui_Detail_G16_C8_Full_Name;
extern const char* kTui_Detail_G16_C8NBG_Full_Name;
extern const char* kTui_Detail_G16_C8NFG_Full_Name;
extern const char* kTui_Detail_G16_C24_Full_Name;
extern const char* kTui_Detail_G16_C24NBG_Full_Name;
extern const char* kTui_Detail_G16_C24NFG_Full_Name;
extern const char* kTui_Detail_G16_C32_Full_Name;
extern const char* kTui_Detail_G16_C32NBG_Full_Name;
extern const char* kTui_Detail_G16_C32NFG_Full_Name;
extern const char* kTui_Detail_G8_C0_Sparse_Name;
extern const char* kTui_Detail_G8_C4_Sparse_Name;
extern const char* kTui_Detail_G8_C8_Sparse_Name;
extern const char* kTui_Detail_G8_C8NBG_Sparse_Name;
extern const char* kTui_Detail_G8_C8NFG_Sparse_Name;
extern const char* kTui_Detail_G8_C24_Sparse_Name;
extern const char* kTui_Detail_G8_C24NBG_Sparse_Name;
extern const char* kTui_Detail_G8_C24NFG_Sparse_Name;
extern const char* kTui_Detail_G8_C32_Sparse_Name;
extern const char* kTui_Detail_G8_C32NBG_Sparse_Name;
extern const char* kTui_Detail_G8_C32NFG_Sparse_Name;
extern const char* kTui_Detail_G16_C0_Sparse_Name;
extern const char* kTui_Detail_G16_C4_Sparse_Name;
extern const char* kTui_Detail_G16_C8_Sparse_Name;
extern const char* kTui_Detail_G16_C8NBG_Sparse_Name;
extern const char* kTui_Detail_G16_C8NFG_Sparse_Name;
extern const char* kTui_Detail_G16_C24_Sparse_Name;
extern const char* kTui_Detail_G16_C24NBG_Sparse_Name;
extern const char* kTui_Detail_G16_C24NFG_Sparse_Name;
extern const char* kTui_Detail_G16_C32_Sparse_Name;
extern const char* kTui_Detail_G16_C32NBG_Sparse_Name;
extern const char* kTui_Detail_G16_C32NFG_Sparse_Name;

int tuiDetailGetGlyphFlag(int detail_mode);
int tuiDetailGetColorFlag(int detail_mode);
int tuiDetailGetLayoutFlag(int detail_mode);
size_t tuiDetailGetTileByteSize(int glyph_flag, int color_flag);
int tuiDetailHasPalette(int detail_mode);
int tuiDetailIsValid(int detail_mode);
int tuiDetailHasFlag(int detail_mode, int detail_flag);
int tuiModesAreCompatible(int detail_mode, int blend_mode);
const char* tuiDetailModeToString(int detail_mode);
int tuiStringToDetailMode(const char* string);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard