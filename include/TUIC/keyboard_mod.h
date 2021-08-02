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
/*! \file keyboard_mod.h
 */
#ifndef TUIC_KEYBOARD_MOD_H //header guard
#define TUIC_KEYBOARD_MOD_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>

typedef enum TuiKeyboardMod
{
	TUI_MOD_INVALID	 	    = 0x0040,
	TUI_MOD_SHIFT           = 0x0001,
	TUI_MOD_CONTROL         = 0x0002,
	TUI_MOD_ALT             = 0x0004,
	TUI_MOD_SUPER           = 0x0008,
	TUI_MOD_CAPS_LOCK       = 0x0010,
	TUI_MOD_NUM_LOCK        = 0x0020,
	TUI_MOD_NONE			= 0,
} TuiKeyboardMod;


extern const char* kTui_Keyboard_Mod_Shift_Name;
extern const char* kTui_Keyboard_Mod_Control_Name;
extern const char* kTui_Keyboard_Mod_Alt_Name;
extern const char* kTui_Keyboard_Mod_Super_Name;
extern const char* kTui_Keyboard_Mod_Caps_Lock_Name;
extern const char* kTui_Keyboard_Mod_Num_Lock_Name;
extern const char* kTui_Keyboard_Mod_None_Name;

TuiBoolean tuiKeyboardModIsValid(TuiKeyboardMod keyboard_mod);
TuiKeyboardMod tuiStringToKeyboardMod(const char* str);
TuiBoolean tuiKeyboardModHasMod(TuiKeyboardMod keyboard_mod, TuiKeyboardMod contains_keyboard_mod);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard