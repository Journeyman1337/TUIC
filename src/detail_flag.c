#include <TUIC/detail_flag.h>
#include <TUIC/debug.h>
#include <stddef.h>

#define TO_STRING(value) #value

const char* kTui_Glyph_Flag_G8_Name = TO_STRING(TUI_GLYPH_FLAG_G8);

const char* kTui_Glyph_Flag_G16_Name = TO_STRING(TUI_GLYPH_FLAG_G16);

const char* kTui_Color_Flag_C0_Name = TO_STRING(TUI_COLOR_FLAG_C0);

const char* kTui_Color_Flag_C4_Name = TO_STRING(TUI_COLOR_FLAG_C4);

const char* kTui_Color_Flag_C8_Name = TO_STRING(TUI_COLOR_FLAG_C8);

const char* kTui_Color_Flag_C8NBG_Name = TO_STRING(TUI_COLOR_FLAG_C8NBG);

const char* kTui_Color_Flag_C8NFG_Name = TO_STRING(TUI_COLOR_FLAG_C8NFG);

const char* kTui_Color_Flag_C24_Name = TO_STRING(TUI_COLOR_FLAG_C24);

const char* kTui_Color_Flag_C24NBG_Name = TO_STRING(TUI_COLOR_FLAG_C24NBG);

const char* kTui_Color_Flag_C24NFG_Name = TO_STRING(TUI_COLOR_FLAG_C24NFG);

const char* kTui_Color_Flag_C32_Name = TO_STRING(TUI_COLOR_FLAG_C32);

const char* kTui_Color_Flag_C32NBG_Name = TO_STRING(TUI_COLOR_FLAG_C32NBG);

const char* kTui_Color_Flag_C32NFG_Name = TO_STRING(TUI_COLOR_FLAG_C32NFG);

const char* kTui_Layout_Flag_Full_Name = TO_STRING(TUI_LAYOUT_FLAG_FULL);

const char* kTui_Layout_Flag_Sparse_Name = TO_STRING(TUI_LAYOUT_FLAG_SPARSE);

TuiBoolean tuiDetailFlagIsValid(TuiDetailFlag detail_flag)
{
	return detail_flag & (
		TUI_GLYPH_FLAG_G8 |
		TUI_GLYPH_FLAG_G16 |
		TUI_COLOR_FLAG_C0 |
		TUI_COLOR_FLAG_C4 |
		TUI_COLOR_FLAG_C8 |
		TUI_COLOR_FLAG_C8NBG |
		TUI_COLOR_FLAG_C8NFG |
		TUI_COLOR_FLAG_C24 |
		TUI_COLOR_FLAG_C24NBG |
		TUI_COLOR_FLAG_C24NFG |
		TUI_COLOR_FLAG_C32 |
		TUI_COLOR_FLAG_C32NBG |
		TUI_COLOR_FLAG_C32NFG |
		TUI_LAYOUT_FLAG_FULL |
		TUI_LAYOUT_FLAG_SPARSE);
}

const char* tuiDetailFlagToString(TuiDetailFlag detail_flag)
{
	switch (detail_flag)
	{
	case TUI_GLYPH_FLAG_G8:
		return kTui_Glyph_Flag_G8_Name;
	case TUI_GLYPH_FLAG_G16:
		return kTui_Glyph_Flag_G16_Name;
	case TUI_COLOR_FLAG_C0:
		return kTui_Color_Flag_C0_Name;
	case TUI_COLOR_FLAG_C4:
		return kTui_Color_Flag_C4_Name;
	case TUI_COLOR_FLAG_C8:
		return kTui_Color_Flag_C8_Name;
	case TUI_COLOR_FLAG_C8NBG:
		return kTui_Color_Flag_C8NBG_Name;
	case TUI_COLOR_FLAG_C8NFG:
		return kTui_Color_Flag_C8NFG_Name;
	case TUI_COLOR_FLAG_C24:
		return kTui_Color_Flag_C24_Name;
	case TUI_COLOR_FLAG_C24NBG:
		return kTui_Color_Flag_C24NBG_Name;
	case TUI_COLOR_FLAG_C24NFG:
		return kTui_Color_Flag_C24NFG_Name;
	case TUI_COLOR_FLAG_C32:
		return kTui_Color_Flag_C32_Name;
	case TUI_COLOR_FLAG_C32NBG:
		return kTui_Color_Flag_C32NBG_Name;
	case TUI_COLOR_FLAG_C32NFG:
		return kTui_Color_Flag_C32NFG_Name;
	case TUI_LAYOUT_FLAG_FULL:
		return kTui_Layout_Flag_Full_Name;
	case TUI_LAYOUT_FLAG_SPARSE:
		return kTui_Layout_Flag_Sparse_Name;
	default:
		return NULL;
	}
}

TuiDetailFlag tuiStringToDetailFlag(const char* string)
{
	if (strcmp(string, kTui_Glyph_Flag_G8_Name) == 0)
	{
		return TUI_GLYPH_FLAG_G8;
	}
	else if (strcmp(string, kTui_Glyph_Flag_G16_Name) == 0)
	{
		return TUI_GLYPH_FLAG_G16;
	}
	else if (strcmp(string, kTui_Color_Flag_C0_Name) == 0)
	{
		return TUI_COLOR_FLAG_C0;
	}
	else if (strcmp(string, kTui_Color_Flag_C4_Name) == 0)
	{
		return TUI_COLOR_FLAG_C4;
	}
	else if (strcmp(string, kTui_Color_Flag_C8_Name) == 0)
	{
		return TUI_COLOR_FLAG_C8;
	}
	else if (strcmp(string, kTui_Color_Flag_C8NBG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C8NBG;
	}
	else if (strcmp(string, kTui_Color_Flag_C8NFG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C8NFG;
	}
	else if (strcmp(string, kTui_Color_Flag_C24_Name) == 0)
	{
		return TUI_COLOR_FLAG_C24;
	}
	else if (strcmp(string, kTui_Color_Flag_C24NBG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C24NBG;
	}
	else if (strcmp(string, kTui_Color_Flag_C24NFG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C24NFG;
	}
	else if (strcmp(string, kTui_Color_Flag_C32_Name) == 0)
	{
		return TUI_COLOR_FLAG_C32;
	}
	else if (strcmp(string, kTui_Color_Flag_C32NBG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C32NBG;
	}
	else if (strcmp(string, kTui_Color_Flag_C32NFG_Name) == 0)
	{
		return TUI_COLOR_FLAG_C32NFG;
	}
	else if (strcmp(string, kTui_Layout_Flag_Full_Name) == 0)
	{
		return TUI_LAYOUT_FLAG_FULL;
	}
	else if (strcmp(string, kTui_Layout_Flag_Sparse_Name) == 0)
	{
		return TUI_LAYOUT_FLAG_SPARSE;
	}
	return 0;
}