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
#include <TUIC/blend_mode.h>
#include <TUIC/debug.h>
#include <TUIC/boolean.h>
#include <stddef.h>

#define TO_STRING(value) #value

const char* kTui_Blend_NORMAL_Name = TO_STRING(TUI_BLEND_NORMAL);

const char* kTui_Blend_FG_RED_Name = TO_STRING(TUI_BLEND_FG_RED);

const char* kTui_Blend_FG_GREEN_Name = TO_STRING(TUI_BLEND_FG_GREEN);

const char* kTui_Blend_FG_BLUE_Name = TO_STRING(TUI_BLEND_FG_BLUE);

const char* kTui_Blend_FG_ALPHA_Name = TO_STRING(TUI_BLEND_FG_ALPHA);

const char* kTui_Blend_BG_RED_Name = TO_STRING(TUI_BLEND_BG_RED);

const char* kTui_Blend_BG_GREEN_Name = TO_STRING(TUI_BLEND_BG_GREEN);

const char* kTui_Blend_BG_BLUE_Name = TO_STRING(TUI_BLEND_BG_BLUE);

const char* kTui_Blend_BG_ALPHA_Name = TO_STRING(TUI_BLEND_BG_ALPHA);

TuiBoolean tuiBlendIsValid(TuiBlendMode blend_mode)
{
	if (
		(blend_mode > TUI_BLEND_INVALID) &&
		(blend_mode <= TUI_BLEND_LAST)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiBlendModeToString(TuiBlendMode blend_mode)
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
		return TUI_NULL;
	}
}

TuiBlendMode tuiStringToBlendMode(const char* str)
{
	if (strcmp(str, kTui_Blend_NORMAL_Name) == 0)
	{
		return TUI_BLEND_NORMAL;
	}
	else if (strcmp(str, kTui_Blend_FG_RED_Name) == 0)
	{
		return TUI_BLEND_FG_RED;
	}
	else if (strcmp(str, kTui_Blend_FG_GREEN_Name) == 0)
	{
		return TUI_BLEND_FG_GREEN;
	}
	else if (strcmp(str, kTui_Blend_FG_BLUE_Name) == 0)
	{
		return TUI_BLEND_FG_BLUE;
	}
	else if (strcmp(str, kTui_Blend_FG_ALPHA_Name) == 0)
	{
		return TUI_BLEND_FG_ALPHA;
	}
	else if (strcmp(str, kTui_Blend_BG_RED_Name) == 0)
	{
		return TUI_BLEND_BG_RED;
	}
	else if (strcmp(str, kTui_Blend_BG_GREEN_Name) == 0)
	{
		return TUI_BLEND_BG_GREEN;
	}
	else if (strcmp(str, kTui_Blend_BG_BLUE_Name) == 0)
	{
		return TUI_BLEND_BG_BLUE;
	}
	else if (strcmp(str, kTui_Blend_BG_ALPHA_Name) == 0)
	{
		return TUI_BLEND_BG_ALPHA;
	}
	return TUI_BLEND_INVALID;
}