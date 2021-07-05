#include <TUIC/button_state.h>
#include <stddef.h>

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
		return NULL;
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