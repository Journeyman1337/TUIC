#include <TUIC/cursor_shape.h>
#include <stddef.h>

const char* kTui_Cursor_Arrow_Name = "CURSOR_ARROW";

const char* kTui_Cursor_Ibeam_Name = "CURSOR_IBEAM";

const char* kTui_Cursor_Crosshair_Name = "CURSOR_CROSSHAIR";

const char* kTui_Cursor_Pointing_Hand_Name = "CURSOR_POINTING_HAND";

const char* kTui_Cursor_Resize_EW_Name ="CURSOR_RESIZE_EW";

const char* kTui_Cursor_Resize_NS_Name = "CURSOR_RESIZE_NS";

const char* kTui_Cursor_Resize_NWSE_Name = "CURSOR_RESIZE_NWSE";

const char* kTui_Cursor_Resize_NESW_Name = "CURSOR_RESIZE_NESW";

const char* kTui_Cursor_Resize_All_Name = "CURSOR_RESIZE_ALL";

const char* kTui_Cursor_Not_Allowed_Name = "CURSOR_NOT_ALLOWED";

TuiBoolean tuiCursorShapeIsValid(TuiCursorShape cursor_shape)
{
	if (
			(cursor_shape >= TUI_CURSOR_FIRST) &&
			(cursor_shape <= TUI_CURSOR_LAST)
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

const char* tuiCursorShapeToString(TuiCursorShape cursor_shape)
{
	switch (cursor_shape)
	{
	case TUI_CURSOR_ARROW:
		return kTui_Cursor_Arrow_Name;
	case TUI_CURSOR_IBEAM:
		return kTui_Cursor_Ibeam_Name;
	case TUI_CURSOR_CROSSHAIR:
		return kTui_Cursor_Crosshair_Name;
	case TUI_CURSOR_POINTING_HAND:
		return kTui_Cursor_Pointing_Hand_Name;
	case TUI_CURSOR_RESIZE_EW:
		return kTui_Cursor_Resize_EW_Name;
	case TUI_CURSOR_RESIZE_NS:
		return kTui_Cursor_Resize_NS_Name;
	case TUI_CURSOR_RESIZE_NWSE:
		return kTui_Cursor_Resize_NWSE_Name;
	case TUI_CURSOR_RESIZE_NESW:
		return kTui_Cursor_Resize_NESW_Name;
	case TUI_CURSOR_RESIZE_ALL:
		return kTui_Cursor_Resize_All_Name;
	case TUI_CURSOR_NOT_ALLOWED:
		return kTui_Cursor_Not_Allowed_Name;
	default:
		return NULL;
	}
}

TuiCursorShape tuiStringToCursorShape(const char* str)
{
	if (strcmp(str, kTui_Cursor_Arrow_Name) == 0)
	{
		return TUI_CURSOR_ARROW;
	}
	else if (strcmp(str, kTui_Cursor_Ibeam_Name) == 0)
	{
		return TUI_CURSOR_IBEAM;
	}
	else if (strcmp(str, kTui_Cursor_Crosshair_Name) == 0)
	{
		return TUI_CURSOR_CROSSHAIR;
	}
	else if (strcmp(str, kTui_Cursor_Pointing_Hand_Name) == 0)
	{
		return TUI_CURSOR_POINTING_HAND;
	}
	else if (strcmp(str, kTui_Cursor_Resize_EW_Name) == 0)
	{
		return TUI_CURSOR_RESIZE_EW;
	}
	else if (strcmp(str, kTui_Cursor_Resize_NS_Name) == 0)
	{
		return TUI_CURSOR_RESIZE_NS;
	}
	else if (strcmp(str, kTui_Cursor_Resize_NWSE_Name) == 0)
	{
		return TUI_CURSOR_RESIZE_NWSE;
	}
	else if (strcmp(str, kTui_Cursor_Resize_NESW_Name) == 0)
	{
		return TUI_CURSOR_RESIZE_NESW;
	}
	else if (strcmp(str, kTui_Cursor_Resize_All_Name) == 0)
	{
		return TUI_CURSOR_RESIZE_ALL;
	}
	else if (strcmp(str, kTui_Cursor_Not_Allowed_Name) == 0)
	{
		return TUI_CURSOR_NOT_ALLOWED;
	}
	return TUI_CURSOR_INVALID;
}
