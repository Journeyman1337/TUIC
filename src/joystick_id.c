#include <TUIC/joystick_id.h>
#include <stddef.h>

const char* kTui_Joystick_1_Name = "JOYSTICK_1";

const char* kTui_Joystick_2_Name = "JOYSTICK_2";

const char* kTui_Joystick_3_Name = "JOYSTICK_3";

const char* kTui_Joystick_4_Name = "JOYSTICK_4";

const char* kTui_Joystick_5_Name = "JOYSTICK_5";

const char* kTui_Joystick_6_Name = "JOYSTICK_6";

const char* kTui_Joystick_7_Name = "JOYSTICK_7";

const char* kTui_Joystick_8_Name = "JOYSTICK_8";

const char* kTui_Joystick_9_Name = "JOYSTICK_9";

const char* kTui_Joystick_10_Name = "JOYSTICK_10";

const char* kTui_Joystick_11_Name = "JOYSTICK_11";

const char* kTui_Joystick_12_Name = "JOYSTICK_12";

const char* kTui_Joystick_13_Name = "JOYSTICK_13";

const char* kTui_Joystick_14_Name = "JOYSTICK_14";

const char* kTui_Joystick_15_Name = "JOYSTICK_15";

const char* kTui_Joystick_16_Name = "JOYSTICK_16";

TuiBoolean tuiJoystickIdIsValid(TuiJoystickId joystick_id)
{
	if (
			(joystick_id >= TUI_JOYSTICK_FIRST) &&
			(joystick_id <= TUI_JOYSTICK_LAST)
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}
const char* tuiJoystickIdToString(TuiJoystickId joystick_id)
{
	switch (joystick_id)
	{
	case TUI_JOYSTICK_1:
		return kTui_Joystick_1_Name;
	case TUI_JOYSTICK_2:
		return kTui_Joystick_2_Name;
	case TUI_JOYSTICK_3:
		return kTui_Joystick_3_Name;
	case TUI_JOYSTICK_4:
		return kTui_Joystick_4_Name;
	case TUI_JOYSTICK_5:
		return kTui_Joystick_5_Name;
	case TUI_JOYSTICK_6:
		return kTui_Joystick_6_Name;
	case TUI_JOYSTICK_7:
		return kTui_Joystick_7_Name;
	case TUI_JOYSTICK_8:
		return kTui_Joystick_8_Name;
	case TUI_JOYSTICK_9:
		return kTui_Joystick_8_Name;
	case TUI_JOYSTICK_10:
		return kTui_Joystick_10_Name;
	case TUI_JOYSTICK_11:
		return kTui_Joystick_11_Name;
	case TUI_JOYSTICK_12:
		return kTui_Joystick_12_Name;
	case TUI_JOYSTICK_13:
		return kTui_Joystick_13_Name;
	case TUI_JOYSTICK_14:
		return kTui_Joystick_14_Name;
	case TUI_JOYSTICK_15:
		return kTui_Joystick_15_Name;
	case TUI_JOYSTICK_16:
		return kTui_Joystick_16_Name;
	default:
		return NULL;
	}
}

TuiJoystickId tuiStringToJoystickId(const char* str)
{
	if (strcmp(str, kTui_Joystick_1_Name) == 0)
	{
		return TUI_JOYSTICK_1;
	}
	else if (strcmp(str, kTui_Joystick_2_Name) == 0)
	{
		return TUI_JOYSTICK_2;
	}
	else if (strcmp(str, kTui_Joystick_3_Name) == 0)
	{
		return TUI_JOYSTICK_3;
	}
	else if (strcmp(str, kTui_Joystick_4_Name) == 0)
	{
		return TUI_JOYSTICK_4;
	}
	else if (strcmp(str, kTui_Joystick_5_Name) == 0)
	{
		return TUI_JOYSTICK_5;
	}
	else if (strcmp(str, kTui_Joystick_6_Name) == 0)
	{
		return TUI_JOYSTICK_6;
	}
	else if (strcmp(str, kTui_Joystick_7_Name) == 0)
	{
		return TUI_JOYSTICK_7;
	}
	else if (strcmp(str, kTui_Joystick_8_Name) == 0)
	{
		return TUI_JOYSTICK_8;
	}
	else if (strcmp(str, kTui_Joystick_9_Name) == 0)
	{
		return TUI_JOYSTICK_9;
	}
	else if (strcmp(str, kTui_Joystick_10_Name) == 0)
	{
		return TUI_JOYSTICK_10;
	}
	else if (strcmp(str, kTui_Joystick_11_Name) == 0)
	{
		return TUI_JOYSTICK_11;
	}
	else if (strcmp(str, kTui_Joystick_12_Name) == 0)
	{
		return TUI_JOYSTICK_12;
	}
	else if (strcmp(str, kTui_Joystick_13_Name) == 0)
	{
		return TUI_JOYSTICK_13;
	}
	else if (strcmp(str, kTui_Joystick_14_Name) == 0)
	{
		return TUI_JOYSTICK_14;
	}
	else if (strcmp(str, kTui_Joystick_15_Name) == 0)
	{
		return TUI_JOYSTICK_15;
	}
	else if (strcmp(str, kTui_Joystick_16_Name) == 0)
	{
		return TUI_JOYSTICK_16;
	}
	return TUI_JOYSTICK_INVALID;
}