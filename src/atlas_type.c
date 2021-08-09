/*
	Copyright (c) 2021 Daniel Valcour
	
	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <TUIC/debug.h>
#include <TUIC/atlas_type.h>
#include <TUIC/boolean.h>
#include <TUIC/types.h>

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
		return TUI_NULL;
	}
}

TuiAtlasType tuiStringToAtlasType(const char* str)
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

