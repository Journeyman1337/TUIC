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
#include <TUIC/filter_mode.h>
#include <TUIC/debug.h>

#include <stddef.h>

#define TO_STRING(value) #value

const char* kTui_Filter_Point_Name = TO_STRING(TUI_FILTER_POINT);

const char* kTui_Filter_Bilinear_Name = TO_STRING(TUI_FILTER_BILINEAR);

TuiBoolean tuiFilterModeIsValid(TuiFilterMode filter_mode)
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

const char* tuiFilterModeToString(TuiFilterMode filter_mode)
{
	switch (filter_mode)
	{
	case TUI_FILTER_POINT:
		return kTui_Filter_Point_Name;
	case TUI_FILTER_BILINEAR:
		return kTui_Filter_Bilinear_Name;
	default:
		return NULL;
	}
}

TuiFilterMode tuiStringToFilterMode(const char* str)
{
	if (strcmp(str, kTui_Filter_Point_Name) == 0)
	{
		return TUI_FILTER_POINT;
	}
	else if (strcmp(str, kTui_Filter_Bilinear_Name) == 0)
	{
		return TUI_FILTER_BILINEAR;
	}
	return TUI_FILTER_INVALID;
}