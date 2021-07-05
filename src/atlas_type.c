#include <TUIC/debug.h>
#include <TUIC/atlas_type.h>
#include <TUIC/boolean.h>
#include <stddef.h>

#define TO_STRING(value) #value

const char* kTui_Atlas_Coords_Name = TO_STRING(TUI_ATLAS_COORDS);

const char* kTui_Atlas_Grid_Name = TO_STRING(TUI_ATLAS_GRID);

TuiBoolean tuiAtlasTypeIsValid(TuiAtlasType atlas_type)
{
	if (
			(atlas_type >= TUI_ATLAS_FIRST) &&
			(atlas_type <= TUI_ATLAS_LAST) 
		)
	{
		return TUI_TRUE;
	}
	else 
	{
		return TUI_FALSE;
	}
}

const char* tuiAtlasTypeToString(TuiAtlasType atlas_type)
{
	switch (atlas_type)
	{
	case TUI_ATLAS_COORDS:
		return kTui_Atlas_Coords_Name;
	case TUI_ATLAS_GRID:
		return kTui_Atlas_Grid_Name;
	default:
		return NULL;
	}
}

int tuiStringToAtlasType(const char* str)
{
	if (strcmp(str, kTui_Atlas_Coords_Name) == 0)
	{
		return TUI_ATLAS_COORDS;
	}
	else if (strcmp(str, kTui_Atlas_Grid_Name) == 0)
	{
		return TUI_ATLAS_GRID;
	}
	return TUI_ATLAS_INVALID;
}

