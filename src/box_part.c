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
#include <TUIC/box_part.h>
#include <TUIC/boolean.h>
#include <TUIC/types.h>
#include <string.h>

#define TO_STRING(value) #value

extern const char* kTui_Box_Part_Left_Side_Name = TO_STRING(TUI_BOX_PART_LEFT_SIDE);

extern const char* kTui_Box_Part_Top_Left_Corner_Name = TO_STRING(TUI_BOX_PART_TOP_LEFT_CORNER);

extern const char* kTui_Box_Part_Top_Side_Name = TO_STRING(TUI_BOX_PART_TOP_SIDE);

extern const char* kTui_Box_Part_Top_Right_Corner_Name = TO_STRING(TUI_BOX_PART_TOP_RIGHT_CORNER);

extern const char* kTui_Box_Part_Right_Side_Name = TO_STRING(TUI_BOX_PART_RIGHT_SIDE);

extern const char* kTui_Box_Part_Bottom_Right_Corner_Name = TO_STRING(TUI_BOX_PART_BOTTOM_RIGHT_CORNER);

extern const char* kTui_Box_Part_Bottom_Side_Name = TO_STRING(TUI_BOX_PART_BOTTOM_SIDE);

extern const char* kTui_Box_Part_Bottom_Left_Corner_Name = TO_STRING(TUI_BOX_PART_BOTTOM_LEFT_CORNER);

TuiBoolean tuiBoxPartIsValid(TuiBoxPart box_part)
{
	return
		(box_part >= TUI_BOX_PART_FIRST) && 
		(box_part <= TUI_BOX_PART_LAST);
}

const char* tuiBoxPartToString(TuiBoxPart box_part)
{
	switch (box_part)
	{
	case TUI_BOX_PART_LEFT_SIDE:
		return kTui_Box_Part_Left_Side_Name;
	case TUI_BOX_PART_TOP_LEFT_CORNER:
		return kTui_Box_Part_Top_Left_Corner_Name;
	case TUI_BOX_PART_TOP_SIDE:
		return kTui_Box_Part_Top_Side_Name;
	case TUI_BOX_PART_TOP_RIGHT_CORNER:
		return kTui_Box_Part_Top_Right_Corner_Name;
	case TUI_BOX_PART_RIGHT_SIDE:
		return kTui_Box_Part_Right_Side_Name;
	case TUI_BOX_PART_BOTTOM_RIGHT_CORNER:
		return kTui_Box_Part_Bottom_Right_Corner_Name;
	case TUI_BOX_PART_BOTTOM_SIDE:
		return kTui_Box_Part_Bottom_Side_Name;
	case TUI_BOX_PART_BOTTOM_LEFT_CORNER:
		return kTui_Box_Part_Bottom_Left_Corner_Name; 
	default:
		return TUI_NULL;
	}
}

TuiBoxPart tuiStringToBoxPart(const char* str)
{
	if (strcmp(str, kTui_Box_Part_Left_Side_Name) == 0)
	{
		return TUI_BOX_PART_LEFT_SIDE;
	}
	else if (strcmp(str, kTui_Box_Part_Top_Left_Corner_Name) == 0)
	{
		return TUI_BOX_PART_TOP_LEFT_CORNER;
	}
	else if (strcmp(str, kTui_Box_Part_Top_Side_Name) == 0)
	{
		return TUI_BOX_PART_TOP_SIDE;
	}
	else if (strcmp(str, kTui_Box_Part_Top_Right_Corner_Name) == 0)
	{
		return TUI_BOX_PART_TOP_RIGHT_CORNER;
	}
	else if (strcmp(str, kTui_Box_Part_Right_Side_Name) == 0)
	{
		return TUI_BOX_PART_RIGHT_SIDE;
	}
	else if (strcmp(str, kTui_Box_Part_Bottom_Right_Corner_Name) == 0)
	{
		return TUI_BOX_PART_BOTTOM_RIGHT_CORNER;
	}
	else if (strcmp(str, kTui_Box_Part_Bottom_Side_Name) == 0)
	{
		return TUI_BOX_PART_BOTTOM_SIDE;
	}
	else if (strcmp(str, kTui_Box_Part_Bottom_Left_Corner_Name) == 0)
	{
		return TUI_BOX_PART_BOTTOM_LEFT_CORNER;
	}
	return TUI_BOX_PART_INVALID;
}