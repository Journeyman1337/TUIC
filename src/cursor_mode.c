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
#include <TUIC/cursor_mode.h>
#include <stddef.h>

const char* kTui_Cursor_Mode_Normal_Name = "CURSOR_MODE_NORMAL";

const char* kTui_Cursor_Mode_Hidden_Name = "CURSOR_MODE_HIDDEN";

const char* kTui_Cursor_Mode_Disabled_Name = "CURSOR_MODE_DISABLED";

TuiBoolean tuiCursorModeIsValid(TuiCursorMode cursor_mode)
{
	if (
			(cursor_mode >= TUI_CURSOR_MODE_FIRST) &&
			(cursor_mode <= TUI_CURSOR_MODE_LAST)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiCursorModeToString(TuiCursorMode cursor_mode)
{
	switch (cursor_mode)
	{
	case TUI_CURSOR_MODE_NORMAL:
		return kTui_Cursor_Mode_Normal_Name;
	case TUI_CURSOR_MODE_HIDDEN:
		return kTui_Cursor_Mode_Hidden_Name;
	case TUI_CURSOR_MODE_DISABLED:
		return kTui_Cursor_Mode_Disabled_Name;
	default:
		return NULL;
	}
}

TuiCursorMode tuiStringToCursorMode(const char* str)
{
	if (strcmp(str, kTui_Cursor_Mode_Normal_Name) == 0)
	{
		return TUI_CURSOR_MODE_NORMAL;
	}
	else if (strcmp(str, kTui_Cursor_Mode_Hidden_Name) == 0)
	{
		return TUI_CURSOR_MODE_HIDDEN;
	}
	else if (strcmp(str, kTui_Cursor_Mode_Disabled_Name) == 0)
	{
		return TUI_CURSOR_MODE_DISABLED;
	}
	return TUI_CURSOR_MODE_INVALID;
}