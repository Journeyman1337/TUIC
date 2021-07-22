#include <TUIC/cursor_shape.h>
#include <stddef.h>
#include <GLFW/glfw3.h>
#include "glfw_error_check.h"
#include "objects.h"

const char* kTui_Cursor_Shape_Arrow_Name = "CURSOR_SHAPE_ARROW";

const char* kTui_Cursor_Shape_Ibeam_Name = "CURSOR_SHAPE_IBEAM";

const char* kTui_Cursor_Shape_Crosshair_Name = "CURSOR_SHAPE_CROSSHAIR";

const char* kTui_Cursor_Shape_Pointing_Hand_Name = "CURSOR_SHAPE_POINTING_HAND";

const char* kTui_Cursor_Shape_Resize_EW_Name ="CURSOR_SHAPE_RESIZE_EW";

const char* kTui_Cursor_Shape_Resize_NS_Name = "CURSOR_SHAPE_RESIZE_NS";

const char* kTui_Cursor_Shape_Resize_NWSE_Name = "CURSOR_SHAPE_RESIZE_NWSE";

const char* kTui_Cursor_Shape_Resize_NESW_Name = "CURSOR_SHAPE_RESIZE_NESW";

const char* kTui_Cursor_Shape_Resize_All_Name = "CURSOR_SHAPE_RESIZE_ALL";

const char* kTui_Cursor_Shape_Not_Allowed_Name = "CURSOR_SHAPE_NOT_ALLOWED";

TuiBoolean tuiCursorShapeIsValid(TuiCursorShape cursor_shape)
{
	if (
			(cursor_shape >= TUI_CURSOR_SHAPE_FIRST) &&
			(cursor_shape <= TUI_CURSOR_SHAPE_LAST)
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

TuiBoolean tuiCursorShapeIsSupported(TuiCursorShape cursor_shape) // glfw has no function for this purpose, so we need to improvise
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_FALSE;
	}
	GLFWcursor* cursor = glfwCreateStandardCursor((int)cursor_shape); // try creating a standard cursor iwth the shape
	if (cursor != NULL) // if the created cursor is not NULL...
	{
		glfwDestroyCursor(cursor); // destroy it because we dont actually want to use it
		GLFW_CLEAR_ERRORS()
		return TUI_TRUE; // return true
	}
	GLFW_CLEAR_ERRORS()
	return TUI_FALSE; //if the created curser was NULL return false
}

const char* tuiCursorShapeToString(TuiCursorShape cursor_shape)
{
	switch (cursor_shape)
	{
	case TUI_CURSOR_SHAPE_ARROW:
		return kTui_Cursor_Shape_Arrow_Name;
	case TUI_CURSOR_SHAPE_IBEAM:
		return kTui_Cursor_Shape_Ibeam_Name;
	case TUI_CURSOR_SHAPE_CROSSHAIR:
		return kTui_Cursor_Shape_Crosshair_Name;
	case TUI_CURSOR_SHAPE_POINTING_HAND:
		return kTui_Cursor_Shape_Pointing_Hand_Name;
	case TUI_CURSOR_SHAPE_RESIZE_EW:
		return kTui_Cursor_Shape_Resize_EW_Name;
	case TUI_CURSOR_SHAPE_RESIZE_NS:
		return kTui_Cursor_Shape_Resize_NS_Name;
	case TUI_CURSOR_SHAPE_RESIZE_NWSE:
		return kTui_Cursor_Shape_Resize_NWSE_Name;
	case TUI_CURSOR_SHAPE_RESIZE_NESW:
		return kTui_Cursor_Shape_Resize_NESW_Name;
	case TUI_CURSOR_SHAPE_RESIZE_ALL:
		return kTui_Cursor_Shape_Resize_All_Name;
	case TUI_CURSOR_SHAPE_NOT_ALLOWED:
		return kTui_Cursor_Shape_Not_Allowed_Name;
	default:
		return NULL;
	}
}

TuiCursorShape tuiStringToCursorShape(const char* str)
{
	if (strcmp(str, kTui_Cursor_Shape_Arrow_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_ARROW;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Ibeam_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_IBEAM;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Crosshair_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_CROSSHAIR;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Pointing_Hand_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_POINTING_HAND;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Resize_EW_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_RESIZE_EW;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Resize_NS_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_RESIZE_NS;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Resize_NWSE_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_RESIZE_NWSE;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Resize_NESW_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_RESIZE_NESW;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Resize_All_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_RESIZE_ALL;
	}
	else if (strcmp(str, kTui_Cursor_Shape_Not_Allowed_Name) == 0)
	{
		return TUI_CURSOR_SHAPE_NOT_ALLOWED;
	}
	return TUI_CURSOR_SHAPE_INVALID;
}
