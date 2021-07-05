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