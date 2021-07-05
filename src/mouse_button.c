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