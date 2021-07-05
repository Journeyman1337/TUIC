#include <TUIC/joystick_hat_state.h>
#include <stddef.h>

const char* kTui_Hat_Centered_Name = "HAT_CENTERED";

const char* kTui_Hat_Up_Name = "HAT_UP";

const char* kTui_Hat_Right_Name = "HAT_RIGHT";

const char* kTui_Hat_Down_Name = "HAT_DOWN";

const char* kTui_Hat_Left_Name = "HAT_LEFT";

const char* kTui_Hat_Right_Up_Name = "HAT_RIGHT_UP";

const char* kTui_Hat_Right_Down_Name = "HAT_RIGHT_DOWN";

const char* kTui_Hat_Left_Up_Name = "HAT_LEFT_UP";

const char* kTui_Hat_Left_Down_Name = "HAT_LEFT_DOWN";

TuiBoolean tuiJoystickHatStateIsValid(TuiJoystickHatState joystick_hat_state)
{
	if (
		(joystick_hat_state == TUI_HAT_UP) ||
		(joystick_hat_state == TUI_HAT_RIGHT) ||
		(joystick_hat_state == TUI_HAT_DOWN) ||
		(joystick_hat_state == TUI_HAT_LEFT) ||
		(joystick_hat_state == TUI_HAT_RIGHT_UP) ||
		(joystick_hat_state == TUI_HAT_RIGHT_DOWN) ||
		(joystick_hat_state == TUI_HAT_LEFT_UP) ||
		(joystick_hat_state == TUI_HAT_LEFT_DOWN)
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

const char* tuiJoystickHatStateToString(TuiJoystickHatState joystick_hat_state)
{
	switch (joystick_hat_state)
	{
	case TUI_HAT_UP:
		return kTui_Hat_Up_Name;
	case TUI_HAT_RIGHT:
		return kTui_Hat_Right_Name;
	case TUI_HAT_DOWN:
		return kTui_Hat_Down_Name;
	case TUI_HAT_LEFT:
		return kTui_Hat_Left_Name;
	case TUI_HAT_RIGHT_UP:
		return kTui_Hat_Right_Up_Name;
	case TUI_HAT_RIGHT_DOWN:
		return kTui_Hat_Right_Down_Name;
	case TUI_HAT_LEFT_UP:
		return kTui_Hat_Left_Up_Name;
	case TUI_HAT_LEFT_DOWN:
		return kTui_Hat_Left_Down_Name;
	default:
		return NULL;
	}
}

TuiJoystickHatState tuiStringToJoystickHatState(const char* str)
{
	if (strcmp(str, kTui_Hat_Up_Name) == 0)
	{
		return TUI_HAT_UP;
	}
	else if (strcmp(str, kTui_Hat_Right_Name) == 0)
	{
		return TUI_HAT_RIGHT;
	}
	else if (strcmp(str, kTui_Hat_Down_Name) == 0)
	{
		return TUI_HAT_DOWN;
	}
	else if (strcmp(str, kTui_Hat_Left_Name) == 0)
	{
		return TUI_HAT_LEFT;
	}
	else if (strcmp(str, kTui_Hat_Right_Up_Name) == 0)
	{
		return TUI_HAT_RIGHT_UP;
	}
	else if (strcmp(str, kTui_Hat_Right_Down_Name) == 0)
	{
		return TUI_HAT_RIGHT_DOWN;
	}
	else if (strcmp(str, kTui_Hat_Left_Up_Name) == 0)
	{
		return TUI_HAT_LEFT_UP;
	}
	else if (strcmp(str, kTui_Hat_Left_Down_Name) == 0)
	{
		return TUI_HAT_LEFT_DOWN;
	}
	return TUI_HAT_INVALID;
}