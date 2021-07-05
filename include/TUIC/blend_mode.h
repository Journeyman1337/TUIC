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
/*! \file blend_mode.h
 */
#ifndef TUIC_BLEND_MODE_H //header guard
#define TUIC_BLEND_MODE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

enum TuiBlendMode
{
	TUI_BLEND_INVALID = 0,
	TUI_BLEND_NORMAL = 1,
	TUI_BLEND_FG_RED = 2,
	TUI_BLEND_FG_GREEN = 3,
	TUI_BLEND_FG_BLUE = 4,
	TUI_BLEND_FG_ALPHA = 5,
	TUI_BLEND_BG_RED = 6,
	TUI_BLEND_BG_GREEN = 7,
	TUI_BLEND_BG_BLUE = 8,
	TUI_BLEND_BG_ALPHA = 9,
	TUI_BLEND_LAST = TUI_BLEND_BG_ALPHA
};

extern const char* kTui_Blend_NORMAL_Name;
extern const char* kTui_Blend_FG_RED_Name;
extern const char* kTui_Blend_FG_GREEN_Name;
extern const char* kTui_Blend_FG_BLUE_Name;
extern const char* kTui_Blend_FG_ALPHA_Name;
extern const char* kTui_Blend_BG_RED_Name;
extern const char* kTui_Blend_BG_GREEN_Name;
extern const char* kTui_Blend_BG_BLUE_Name;
extern const char* kTui_Blend_BG_ALPHA_Name;

int tuiBlendIsValid(int blend_mode);
const char* tuiBlendModeToString(int blend_mode);
int tuiStringToBlendMode(const char* string);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard