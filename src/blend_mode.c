#include <TUIC/blend_mode.h>
#include <TUIC/debug.h>
#include <TUIC/boolean.h>
#include <stddef.h>

#define TO_STRING(value) #value

const char* kTui_Blend_NORMAL_Name = TO_STRING(TUI_BLEND_NORMAL);

const char* kTui_Blend_FG_RED_Name = TO_STRING(TUI_BLEND_FG_RED);

const char* kTui_Blend_FG_GREEN_Name = TO_STRING(TUI_BLEND_FG_GREEN);

const char* kTui_Blend_FG_BLUE_Name = TO_STRING(TUI_BLEND_FG_BLUE);

const char* kTui_Blend_FG_ALPHA_Name = TO_STRING(TUI_BLEND_FG_ALPHA);

const char* kTui_Blend_BG_RED_Name = TO_STRING(TUI_BLEND_BG_RED);

const char* kTui_Blend_BG_GREEN_Name = TO_STRING(TUI_BLEND_BG_GREEN);

const char* kTui_Blend_BG_BLUE_Name = TO_STRING(TUI_BLEND_BG_BLUE);

const char* kTui_Blend_BG_ALPHA_Name = TO_STRING(TUI_BLEND_BG_ALPHA);

int tuiBlendIsValid(int blend_mode)
{
	if (
		(blend_mode == TUI_BLEND_NORMAL) ||
		(blend_mode == TUI_BLEND_BG_RED) ||
		(blend_mode == TUI_BLEND_BG_GREEN) ||
		(blend_mode == TUI_BLEND_BG_BLUE) ||
		(blend_mode == TUI_BLEND_BG_ALPHA) ||
		(blend_mode == TUI_BLEND_FG_RED) ||
		(blend_mode == TUI_BLEND_FG_GREEN) ||
		(blend_mode == TUI_BLEND_FG_BLUE) ||
		(blend_mode == TUI_BLEND_FG_ALPHA)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiBlendModeToString(int blend_mode)
{
	switch (blend_mode)
	{
	case TUI_BLEND_NORMAL:
		return kTui_Blend_NORMAL_Name;
	case TUI_BLEND_FG_RED:
		return kTui_Blend_FG_RED_Name;
	case TUI_BLEND_FG_GREEN:
		return kTui_Blend_FG_GREEN_Name;
	case TUI_BLEND_FG_BLUE:
		return kTui_Blend_FG_BLUE_Name;
	case TUI_BLEND_FG_ALPHA:
		return kTui_Blend_FG_ALPHA_Name;
	case TUI_BLEND_BG_RED:
		return kTui_Blend_BG_RED_Name;
	case TUI_BLEND_BG_GREEN:
		return kTui_Blend_BG_GREEN_Name;
	case TUI_BLEND_BG_BLUE:
		return kTui_Blend_BG_BLUE_Name;
	case TUI_BLEND_BG_ALPHA:
		return kTui_Blend_BG_ALPHA_Name;
	default:
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}
}


int tuiStringToBlendMode(const char* string)
{
	if (strcmp(string, kTui_Blend_NORMAL_Name) == 0)
	{
		return TUI_BLEND_NORMAL;
	}
	else if (strcmp(string, kTui_Blend_FG_RED_Name) == 0)
	{
		return TUI_BLEND_FG_RED;
	}
	else if (strcmp(string, kTui_Blend_FG_GREEN_Name) == 0)
	{
		return TUI_BLEND_FG_GREEN;
	}
	else if (strcmp(string, kTui_Blend_FG_BLUE_Name) == 0)
	{
		return TUI_BLEND_FG_BLUE;
	}
	else if (strcmp(string, kTui_Blend_FG_ALPHA_Name) == 0)
	{
		return TUI_BLEND_FG_ALPHA;
	}
	else if (strcmp(string, kTui_Blend_BG_RED_Name) == 0)
	{
		return TUI_BLEND_BG_RED;
	}
	else if (strcmp(string, kTui_Blend_BG_GREEN_Name) == 0)
	{
		return TUI_BLEND_BG_GREEN;
	}
	else if (strcmp(string, kTui_Blend_BG_BLUE_Name) == 0)
	{
		return TUI_BLEND_BG_BLUE;
	}
	else if (strcmp(string, kTui_Blend_BG_ALPHA_Name) == 0)
	{
		return TUI_BLEND_BG_ALPHA;
	}
	return 0;
}