#include <TUIC/keyboard_mod.h>
#include <stddef.h>

const char* kTui_Keyboard_Mod_Shift_Name = "MOD_SHIFT";

const char* kTui_Keyboard_Mod_Control_Name = "MOD_CONTROL";

const char* kTui_Keyboard_Mod_Alt_Name = "MOD_ALT";

const char* kTui_Keyboard_Mod_Super_Name = "MOD_SUPER";

const char* kTui_Keyboard_Mod_Caps_Lock_Name = "MOD_CAPS_LOCK";

const char* kTui_Keyboard_Mod_Num_Lock_Name = "MOD_NUM_LOCK";

const char* kTui_Keyboard_Mod_None_Name = "MOD_NONE";

const char* kTui_Keyboard_Mod_All_Name = "MOD_ALL";

TuiBoolean tuiKeyboardModIsValid(TuiKeyboardMod mod)
{
	if (
			(mod >= TUI_MOD_NONE) &&
			(mod <= TUI_MOD_ALL)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiKeyboardModToString(TuiKeyboardMod mod)
{
	switch (mod)
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
	case TUI_MOD_ALL:
		return kTui_Keyboard_Mod_All_Name;
	default:
		return NULL;
	}
}

TuiKeyboardMod tuiStringToMod(const char* str)
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
	else if (strcmp(str, kTui_Keyboard_Mod_All_Name) == 0)
	{
		return TUI_MOD_ALL;
	}
	return TUI_MOD_INVALID;
}

TuiBoolean tuiKeyboardModContainsMod(TuiKeyboardMod mod, TuiKeyboardMod contains_mod)
{
	if ((mod & contains_mod) == contains_mod)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}