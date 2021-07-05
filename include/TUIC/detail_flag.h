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
/*! \file detail_flag.h
 */
#ifndef TUIC_DETAIL_FLAG_H //header guard
#define TUIC_DETAIL_FLAG_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

typedef enum TuiDetailFlag
{
	TUI_GLYPH_FLAG_G8 = (1 << 0),
	TUI_GLYPH_FLAG_G16 = (1 << 1),
	TUI_COLOR_FLAG_C0 = (1 << 2),
	TUI_COLOR_FLAG_C4 = (1 << 3),
	TUI_COLOR_FLAG_C8 = (1 << 4),
	TUI_COLOR_FLAG_C8NFG = (1 << 5),
	TUI_COLOR_FLAG_C8NBG = (1 << 6),
	TUI_COLOR_FLAG_C24 = (1 << 7),
	TUI_COLOR_FLAG_C24NFG = (1 << 8),
	TUI_COLOR_FLAG_C24NBG = (1 << 9),
	TUI_COLOR_FLAG_C32 = (1 << 10),
	TUI_COLOR_FLAG_C32NFG = (1 << 11),
	TUI_COLOR_FLAG_C32NBG = (1 << 12),
	TUI_LAYOUT_FLAG_FULL = (1 << 13),
	TUI_LAYOUT_FLAG_SPARSE = (1 << 14)
} TuiDetailFlag;

extern const char* kTui_Glyph_Flag_G8_Name;
extern const char* kTui_Glyph_Flag_G16_Name;
extern const char* kTui_Color_Flag_C0_Name;
extern const char* kTui_Color_Flag_C4_Name;
extern const char* kTui_Color_Flag_C8_Name;
extern const char* kTui_Color_Flag_C8NBG_Name;
extern const char* kTui_Color_Flag_C8NFG_Name;
extern const char* kTui_Color_Flag_C24_Name;
extern const char* kTui_Color_Flag_C24NBG_Name;
extern const char* kTui_Color_Flag_C24NFG_Name;
extern const char* kTui_Color_Flag_C32_Name;
extern const char* kTui_Color_Flag_C32NBG_Name;
extern const char* kTui_Color_Flag_C32NFG_Name;
extern const char* kTui_Layout_Flag_Full_Name;
extern const char* kTui_Layout_Flag_Sparse_Name;

int tuiDetailFlagIsValid(int detail_flag);
const char* tuiDetailFlagToString(int detail_flag);
int tuiStringToDetailFlag(const char* string);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard