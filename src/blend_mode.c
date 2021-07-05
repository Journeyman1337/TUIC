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

TuiBoolean tuiBlendIsValid(TuiBlendMode blend_mode)
{
	if (
		(blend_mode > TUI_BLEND_INVALID) &&
		(blend_mode <= TUI_BLEND_LAST)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiBlendModeToString(TuiBlendMode blend_mode)
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
		return NULL;
	}
}

TuiBlendMode tuiStringToBlendMode(const char* str)
{
	if (strcmp(str, kTui_Blend_NORMAL_Name) == 0)
	{
		return TUI_BLEND_NORMAL;
	}
	else if (strcmp(str, kTui_Blend_FG_RED_Name) == 0)
	{
		return TUI_BLEND_FG_RED;
	}
	else if (strcmp(str, kTui_Blend_FG_GREEN_Name) == 0)
	{
		return TUI_BLEND_FG_GREEN;
	}
	else if (strcmp(str, kTui_Blend_FG_BLUE_Name) == 0)
	{
		return TUI_BLEND_FG_BLUE;
	}
	else if (strcmp(str, kTui_Blend_FG_ALPHA_Name) == 0)
	{
		return TUI_BLEND_FG_ALPHA;
	}
	else if (strcmp(str, kTui_Blend_BG_RED_Name) == 0)
	{
		return TUI_BLEND_BG_RED;
	}
	else if (strcmp(str, kTui_Blend_BG_GREEN_Name) == 0)
	{
		return TUI_BLEND_BG_GREEN;
	}
	else if (strcmp(str, kTui_Blend_BG_BLUE_Name) == 0)
	{
		return TUI_BLEND_BG_BLUE;
	}
	else if (strcmp(str, kTui_Blend_BG_ALPHA_Name) == 0)
	{
		return TUI_BLEND_BG_ALPHA;
	}
	return TUI_BLEND_INVALID;
}