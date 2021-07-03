#include <TUIC/debug.h>
#include <TUIC/atlas_type.h>
#include <TUIC/boolean.h>
#include <stddef.h>

#define TO_STRING(value) #value

const char* kTui_Atlas_COORDS_Name = TO_STRING(TUI_ATLAS_COORDS);

const char* kTui_Atlas_GRID_Name = TO_STRING(TUI_ATLAS_GRID);

int tuiAtlasTypeIsValid(int atlas_type)
{
	if (
		(atlas_type == TUI_ATLAS_COORDS) ||
		(atlas_type == TUI_ATLAS_GRID)
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

const char* tuiAtlasTypeToString(int atlas_type)
{
	switch (atlas_type)
	{
	case TUI_ATLAS_COORDS:
		return kTui_Atlas_COORDS_Name;
	case TUI_ATLAS_GRID:
		return kTui_Atlas_GRID_Name;
	default:
		tuiDebugError(TUI_ERROR_INVALID_ATLAS_TYPE, __func__);
		return NULL;
	}
}

int tuiStringToAtlasType(const char* string)
{
	if (strcmp(string, kTui_Atlas_COORDS_Name) == 0)
	{
		return TUI_ATLAS_COORDS;
	}
	else if (strcmp(string, kTui_Atlas_GRID_Name) == 0)
	{
		return TUI_ATLAS_GRID;
	}
	return 0;
}

