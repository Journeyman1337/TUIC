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
#include <TUIC/mouse_button.h>
#include <stddef.h>
#include <string.h>

const char* kTui_Mouse_Button_1_Name = "MOUSE_BUTTON_1";

const char* kTui_Mouse_Button_2_Name = "MOUSE_BUTTON_2";

const char* kTui_Mouse_Button_3_Name = "MOUSE_BUTTON_3";

const char* kTui_Mouse_Button_4_Name = "MOUSE_BUTTON_4";

const char* kTui_Mouse_Button_5_Name = "MOUSE_BUTTON_5";

const char* kTui_Mouse_Button_6_Name = "MOUSE_BUTTON_6";

const char* kTui_Mouse_Button_7_Name = "MOUSE_BUTTON_7";

const char* kTui_Mouse_Button_8_Name = "MOUSE_BUTTON_8";

TuiBoolean tuiMouseButtonIsValid(TuiMouseButton mouse_button)
{
	if (
			(mouse_button >= TUI_MOUSE_BUTTON_FIRST) &&
			(mouse_button <= TUI_MOUSE_BUTTON_LAST)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiMouseButtonToString(TuiMouseButton mouse_button)
{
	switch (mouse_button)
	{
	case TUI_MOUSE_BUTTON_1:
		return kTui_Mouse_Button_1_Name;
	case TUI_MOUSE_BUTTON_2:
		return kTui_Mouse_Button_2_Name;
	case TUI_MOUSE_BUTTON_3:
		return kTui_Mouse_Button_3_Name;
	case TUI_MOUSE_BUTTON_4:
		return kTui_Mouse_Button_4_Name;
	case TUI_MOUSE_BUTTON_5:
		return kTui_Mouse_Button_5_Name;
	case TUI_MOUSE_BUTTON_6:
		return kTui_Mouse_Button_6_Name;
	case TUI_MOUSE_BUTTON_7:
		return kTui_Mouse_Button_7_Name;
	case TUI_MOUSE_BUTTON_8:
		return kTui_Mouse_Button_8_Name;
	default:
		return NULL;
	}
}

TuiMouseButton tuiStringToMouseButton(const char* str)
{
	if (strcmp(str, kTui_Mouse_Button_1_Name) == 0)
	{
		return TUI_MOUSE_BUTTON_1;
	}
	else if (strcmp(str, kTui_Mouse_Button_2_Name) == 0)
	{
		return TUI_MOUSE_BUTTON_2;
	}
	else if (strcmp(str, kTui_Mouse_Button_3_Name) == 0)
	{
		return TUI_MOUSE_BUTTON_3;
	}
	else if (strcmp(str, kTui_Mouse_Button_4_Name) == 0)
	{
		return TUI_MOUSE_BUTTON_4;
	}
	else if (strcmp(str, kTui_Mouse_Button_5_Name) == 0)
	{
		return TUI_MOUSE_BUTTON_5;
	}
	else if (strcmp(str, kTui_Mouse_Button_6_Name) == 0)
	{
		return TUI_MOUSE_BUTTON_6;
	}
	else if (strcmp(str, kTui_Mouse_Button_7_Name) == 0)
	{
		return TUI_MOUSE_BUTTON_7;
	}
	else if (strcmp(str, kTui_Mouse_Button_8_Name) == 0)
	{
		return TUI_MOUSE_BUTTON_8;
	}
	return TUI_MOUSE_BUTTON_INVALID;

}