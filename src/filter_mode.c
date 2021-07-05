#include <TUIC/filter_mode.h>
#include <TUIC/debug.h>

#include <stddef.h>

#define TO_STRING(value) #value

const char* kTui_Filter_Point_Name = TO_STRING(TUI_FILTER_POINT);

const char* kTui_Filter_Bilinear_Name = TO_STRING(TUI_FILTER_BILINEAR);

TuiBoolean tuiFilterModeIsValid(TuiFilterMode filter_mode)
{
	if (
		filter_mode == TUI_FILTER_POINT ||
		filter_mode == TUI_FILTER_BILINEAR
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

const char* tuiFilterModeToString(TuiFilterMode filter_mode)
{
	switch (filter_mode)
	{
	case TUI_FILTER_POINT:
		return kTui_Filter_Point_Name;
	case TUI_FILTER_BILINEAR:
		return kTui_Filter_Bilinear_Name;
	default:
		return NULL;
	}
}

TuiFilterMode tuiStringToFilterMode(const char* string)
{
	if (strcmp(string, kTui_Filter_Point_Name) == 0)
	{
		return TUI_FILTER_POINT;
	}
	else if (strcmp(string, kTui_Filter_Bilinear_Name) == 0)
	{
		return TUI_FILTER_BILINEAR;
	}
	return 0;
}