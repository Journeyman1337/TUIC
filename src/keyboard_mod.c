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
#include <TUIC/keyboard_mod.h>
#include <TUIC/types.h>
#include <string.h>

const char* kTui_Keyboard_Mod_Shift_Name = "MOD_SHIFT";

const char* kTui_Keyboard_Mod_Control_Name = "MOD_CONTROL";

const char* kTui_Keyboard_Mod_Alt_Name = "MOD_ALT";

const char* kTui_Keyboard_Mod_Super_Name = "MOD_SUPER";

const char* kTui_Keyboard_Mod_Caps_Lock_Name = "MOD_CAPS_LOCK";

const char* kTui_Keyboard_Mod_Num_Lock_Name = "MOD_NUM_LOCK";

const char* kTui_Keyboard_Mod_None_Name = "MOD_NONE";

TuiBoolean tuiKeyboardModIsValid(TuiKeyboardMod keyboard_mod)
{
	if (
			((keyboard_mod | TUI_MOD_ALL) == TUI_MOD_ALL)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiKeyboardModToString(TuiKeyboardMod keyboard_mod)
{
	switch (keyboard_mod)
	{
	case TUI_MOD_SHIFT:
		return kTui_Keyboard_Mod_Shift_Name;
	case TUI_MOD_CONTROL:
		return kTui_Keyboard_Mod_Control_Name;
	case TUI_MOD_ALT:
		return kTui_Keyboard_Mod_Alt_Name;
	case TUI_MOD_SUPER:
		return kTui_Keyboard_Mod_Super_Name;
	case TUI_MOD_CAPS_LOCK:
		return kTui_Keyboard_Mod_Caps_Lock_Name;
	case TUI_MOD_NUM_LOCK:
		return kTui_Keyboard_Mod_Num_Lock_Name;
	case TUI_MOD_NONE:
		return kTui_Keyboard_Mod_None_Name;
	default:
		return TUI_NULL;
	}
}

TuiKeyboardMod tuiStringToKeyboardMod(const char* str)
{
	if (strcmp(str, kTui_Keyboard_Mod_Shift_Name) == 0)
	{
		return TUI_MOD_SHIFT;
	}
	else if (strcmp(str, kTui_Keyboard_Mod_Control_Name) == 0)
	{
		return TUI_MOD_CONTROL;
	}
	else if (strcmp(str, kTui_Keyboard_Mod_Alt_Name) == 0)
	{
		return TUI_MOD_ALT;
	}
	else if (strcmp(str, kTui_Keyboard_Mod_Super_Name) == 0)
	{
		return TUI_MOD_SUPER;
	}
	else if (strcmp(str, kTui_Keyboard_Mod_Caps_Lock_Name) == 0)
	{
		return TUI_MOD_CAPS_LOCK;
	}
	else if (strcmp(str, kTui_Keyboard_Mod_Num_Lock_Name) == 0)
	{
		return TUI_MOD_NUM_LOCK;
	}
	else if (strcmp(str, kTui_Keyboard_Mod_None_Name) == 0)
	{
		return TUI_MOD_NONE;
	}
	return TUI_MOD_INVALID;
}

TuiBoolean tuiKeyboardModHasMod(TuiKeyboardMod keyboard_mod, TuiKeyboardMod contains_keyboard_mod)
{
	if ((keyboard_mod & contains_keyboard_mod) == contains_keyboard_mod)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}