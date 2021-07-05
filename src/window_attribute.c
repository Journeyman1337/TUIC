#include <TUIC/window_attribute.h>
#include <stddef.h>
#include <string.h>

const char* kTui_Window_Focused_Name = "WINDOW_FOCUESED";

const char* kTui_Window_Iconified_Name = "WINDOW_ICONIFIED";

const char* kTui_Window_Resizable_Name = "WINDOW_RESIZABLE";

const char* kTui_Window_Visible_Name = "WINDOW_VISIBLE";

const char* kTui_Window_Decorated_Name = "WINDOW_DECORATED";

const char* kTui_Window_Auto_Iconify_Name = "WINDOW_AUTO_ICONIFY";

const char* kTui_Window_Floating_Name = "WINDOW_FLOATING";

const char* kTui_Window_Maximized_Name = "WINDOW_MAXIMIZED";

const char* kTui_Window_Center_Cursor_Name = "WINDOW_CENTER_CURSOR";

const char* kTui_Window_Transparent_Framebuffer_Name = "WINDOW_TRANSPARENT_FRAMEBUFFER";

const char* kTui_Window_Hovered_Name = "WINDOW_HOVERED";

const char* kTui_Window_Focus_On_Show_Name = "WINDOW_FOCUS_ON_SHOW";

const char* kTui_Window_Mouse_Passthrough_Name = "WINDOW_MOUSE_PASSTHROUGH";


TuiBoolean tuiWindowAttributeIsValid(TuiWindowAttribute window_attribute)
{
	if (
			(window_attribute >= TUI_WINDOW_FIRST) &&
			(window_attribute <= TUI_WINDOW_LAST)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiWindowAttributeToString(TuiWindowAttribute window_attribute)
{
	switch (window_attribute)
	{
	case TUI_WINDOW_FOCUSED:
		return kTui_Window_Focused_Name;
	case TUI_WINDOW_ICONIFIED:
		return kTui_Window_Iconified_Name;
	case TUI_WINDOW_RESIZABLE:
		return kTui_Window_Resizable_Name;
	case TUI_WINDOW_VISIBLE:
		return kTui_Window_Visible_Name;
	case TUI_WINDOW_DECORATED:
		return kTui_Window_Decorated_Name;
	case TUI_WINDOW_AUTO_ICONIFY:
		return kTui_Window_Auto_Iconify_Name;
	case TUI_WINDOW_FLOATING:
		return kTui_Window_Floating_Name;
	case TUI_WINDOW_MAXIMIZED:
		return kTui_Window_Maximized_Name;
	case TUI_WINDOW_CENTER_CURSOR:
		return kTui_Window_Center_Cursor_Name;
	case TUI_WINDOW_TRANSPARENT_FRAMEBUFFER:
		return kTui_Window_Transparent_Framebuffer_Name;
	case TUI_WINDOW_HOVERED:
		return kTui_Window_Hovered_Name;
	case TUI_WINDOW_FOCUS_ON_SHOW:
		return kTui_Window_Focus_On_Show_Name;
	case TUI_WINDOW_MOUSE_PASSTHROUGH:
		return kTui_Window_Mouse_Passthrough_Name;
	default:
		return NULL;
	}
}

TuiWindowAttribute tuiStringToWindowAttribute(const char* str)
{
	if (strcmp(str, kTui_Window_Focused_Name) == 0)
	{
		return TUI_WINDOW_FOCUSED;
	}
	else if (strcmp(str, kTui_Window_Iconified_Name) == 0)
	{
		return TUI_WINDOW_ICONIFIED;
	}
	else if (strcmp(str, kTui_Window_Resizable_Name) == 0)
	{
		return TUI_WINDOW_RESIZABLE;
	}
	else if (strcmp(str, kTui_Window_Visible_Name) == 0)
	{
		return TUI_WINDOW_VISIBLE;
	}
	else if (strcmp(str, kTui_Window_Decorated_Name) == 0)
	{
		return TUI_WINDOW_DECORATED;
	}
	else if (strcmp(str, kTui_Window_Auto_Iconify_Name) == 0)
	{
		return TUI_WINDOW_AUTO_ICONIFY;
	}
	else if (strcmp(str, kTui_Window_Floating_Name) == 0)
	{
		return TUI_WINDOW_FLOATING;
	}
	else if (strcmp(str, kTui_Window_Maximized_Name) == 0)
	{
		return TUI_WINDOW_MAXIMIZED;
	}
	else if (strcmp(str, kTui_Window_Center_Cursor_Name) == 0)
	{
		return TUI_WINDOW_CENTER_CURSOR;
	}
	else if (strcmp(str, kTui_Window_Transparent_Framebuffer_Name) == 0)
	{
		return TUI_WINDOW_TRANSPARENT_FRAMEBUFFER;
	}
	else if (strcmp(str, kTui_Window_Hovered_Name) == 0)
	{
		return TUI_WINDOW_HOVERED;
	}
	else if (strcmp(str, kTui_Window_Focus_On_Show_Name) == 0)
	{
		return TUI_WINDOW_FOCUS_ON_SHOW;
	}
	else if (strcmp(str, kTui_Window_Mouse_Passthrough_Name) == 0)
	{
		return TUI_WINDOW_MOUSE_PASSTHROUGH;
	}
	return TUI_WINDOW_INVALID;
}