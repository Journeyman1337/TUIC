#include <TUIC/mouse_button.h>
#include <stddef.h>
#include <string.h>

const char* kTui_Mouse_1_Name = "MOUSE_1";

const char* kTui_Mouse_2_Name = "MOUSE_2";

const char* kTui_Mouse_3_Name = "MOUSE_3";

const char* kTui_Mouse_4_Name = "MOUSE_4";

const char* kTui_Mouse_5_Name = "MOUSE_5";

const char* kTui_Mouse_6_Name = "MOUSE_6";

const char* kTui_Mouse_7_Name = "MOUSE_7";

const char* kTui_Mouse_8_Name = "MOUSE_8";

TuiBoolean tuiMouseButtonIsValid(TuiMouseButton mouse_button)
{
	if (
			(mouse_button >= TUI_MOUSE_FIRST) &&
			(mouse_button <= TUI_MOUSE_LAST)
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
	case TUI_MOUSE_1:
		return kTui_Mouse_1_Name;
	case TUI_MOUSE_2:
		return kTui_Mouse_2_Name;
	case TUI_MOUSE_3:
		return kTui_Mouse_3_Name;
	case TUI_MOUSE_4:
		return kTui_Mouse_4_Name;
	case TUI_MOUSE_5:
		return kTui_Mouse_5_Name;
	case TUI_MOUSE_6:
		return kTui_Mouse_6_Name;
	case TUI_MOUSE_7:
		return kTui_Mouse_7_Name;
	case TUI_MOUSE_8:
		return kTui_Mouse_8_Name;
	default:
		return NULL;
	}
}

TuiMouseButton tuiStringToMouseButton(const char* str)
{
	if (strcmp(str, kTui_Mouse_1_Name) == 0)
	{
		return TUI_MOUSE_1;
	}
	else if (strcmp(str, kTui_Mouse_2_Name) == 0)
	{
		return TUI_MOUSE_2;
	}
	else if (strcmp(str, kTui_Mouse_3_Name) == 0)
	{
		return TUI_MOUSE_3;
	}
	else if (strcmp(str, kTui_Mouse_4_Name) == 0)
	{
		return TUI_MOUSE_4;
	}
	else if (strcmp(str, kTui_Mouse_5_Name) == 0)
	{
		return TUI_MOUSE_5;
	}
	else if (strcmp(str, kTui_Mouse_6_Name) == 0)
	{
		return TUI_MOUSE_6;
	}
	else if (strcmp(str, kTui_Mouse_7_Name) == 0)
	{
		return TUI_MOUSE_7;
	}
	else if (strcmp(str, kTui_Mouse_8_Name) == 0)
	{
		return TUI_MOUSE_8;
	}
	return TUI_MOUSE_INVALID;

}