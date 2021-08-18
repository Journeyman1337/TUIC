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
#include <TUIC/button_state.h>
#include <TUIC/types.h>
#include <string.h>

#define TO_STRING(value) #value

const char* kTui_Button_Release_Name = "BUTTON_RELEASE";

const char* kTui_Button_Press_Name = "BUTTON_PRESS";

const char* kTui_Button_Repeat_Name = "BUTTON_REPEAT";

TuiBoolean tuiButtonStateIsValid(TuiButtonState button_state)
{
	if (
		(button_state >= TUI_BUTTON_FIRST) &&
		(button_state <= TUI_BUTTON_LAST)
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

const char* tuiButtonStateToString(TuiButtonState button_state)
{
	switch (button_state)
	{
	case TUI_BUTTON_RELEASE:
		return kTui_Button_Release_Name;
	case TUI_BUTTON_PRESS:
		return kTui_Button_Press_Name;
	case TUI_BUTTON_REPEAT:
		return kTui_Button_Repeat_Name;
	default:
		// tuiDebugError(TUI_ERROR_INVALID_BUTTON_STATE, __func__);
		return TUI_NULL;
	}
}

TuiButtonState tuiStringToButtonState(const char* str)
{
	if (strcmp(str, kTui_Button_Release_Name) == 0)
	{
		return TUI_BUTTON_RELEASE;
	}
	else if (strcmp(str, kTui_Button_Press_Name) == 0)
	{
		return TUI_BUTTON_PRESS;
	}
	else if (strcmp(str, kTui_Button_Repeat_Name) == 0)
	{
		return TUI_BUTTON_REPEAT;
	}
	return TUI_BUTTON_INVALID;
}