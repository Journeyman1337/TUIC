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
/*! \file keyboard_key.h
 */
#ifndef TUIC_KEYBOARD_KEY //header guard
#define TUIC_KEYBOARD_KEY
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>

typedef enum TuiKeyboardKey
{
	TUIK_INVALID		   = 0,
	TUIK_SPACE             = 32,
	TUIK_APOSTROPHE        = 39, /* ' */
	TUIK_COMMA             = 44, /* , */
	TUIK_MINUS             = 45, /* - */
	TUIK_PERIOD            = 46, /* . */
	TUIK_SLASH             = 47, /* / */
	TUIK_0                 = 48,
	TUIK_1                 = 49,
	TUIK_2                 = 50,
	TUIK_3                 = 51,
	TUIK_4                 = 52,
	TUIK_5                 = 53,
	TUIK_6                 = 54,
	TUIK_7                 = 55,
	TUIK_8                 = 56,
	TUIK_9                 = 57,
	TUIK_SEMICOLON         = 59, /* ; */
	TUIK_EQUAL             = 61, /* = */
	TUIK_A                 = 65,
	TUIK_B                 = 66,
	TUIK_C                 = 67,
	TUIK_D                 = 68,
	TUIK_E                 = 69,
	TUIK_F                 = 70,
	TUIK_G                 = 71,
	TUIK_H                 = 72,
	TUIK_I                 = 73,
	TUIK_J                 = 74,
	TUIK_K                 = 75,
	TUIK_L                 = 76,
	TUIK_M                 = 77,
	TUIK_N                 = 78,
	TUIK_O                 = 79,
	TUIK_P                 = 80,
	TUIK_Q                 = 81,
	TUIK_R                 = 82,
	TUIK_S                 = 83,
	TUIK_T                 = 84,
	TUIK_U                 = 85,
	TUIK_V                 = 86,
	TUIK_W                 = 87,
	TUIK_X                 = 88,
	TUIK_Y                 = 89,
	TUIK_Z                 = 90,
	TUIK_LEFT_BRACKET      = 91, /* [ */
	TUIK_BACKSLASH         = 92, /* \ */
	TUIK_RIGHT_BRACKET     = 93, /* ] */
	TUIK_GRAVE_ACCENT      = 96, /* ` */
	TUIK_WORLD_1           = 161, /* non-US #1 */
	TUIK_WORLD_2           = 162, /* non-US #2 */

/* Function keys */
	TUIK_ESCAPE            = 256,
	TUIK_ENTER             = 257,
	TUIK_TAB               = 258,
	TUIK_BACKSPACE         = 259,
	TUIK_INSERT            = 260,
	TUIK_DELETE            = 261,
	TUIK_RIGHT             = 262,
	TUIK_LEFT              = 263,
	TUIK_DOWN              = 264,
	TUIK_UP                = 265,
	TUIK_PAGE_UP           = 266,
	TUIK_PAGE_DOWN         = 267,
	TUIK_HOME              = 268,
	TUIK_END               = 269,
	TUIK_CAPS_LOCK         = 280,
	TUIK_SCROLL_LOCK       = 281,
	TUIK_NUM_LOCK          = 282,
	TUIK_PRINT_SCREEN      = 283,
	TUIK_PAUSE             = 284,
	TUIK_F1                = 290,
	TUIK_F2                = 291,
	TUIK_F3                = 292,
	TUIK_F4                = 293,
	TUIK_F5                = 294,
	TUIK_F6                = 295,
	TUIK_F7                = 296,
	TUIK_F8                = 297,
	TUIK_F9                = 298,
	TUIK_F10               = 299,
	TUIK_F11               = 300,
	TUIK_F12               = 301,
	TUIK_F13               = 302,
	TUIK_F14               = 303,
	TUIK_F15               = 304,
	TUIK_F16               = 305,
	TUIK_F17               = 306,
	TUIK_F18               = 307,
	TUIK_F19               = 308,
	TUIK_F20               = 309,
	TUIK_F21               = 310,
	TUIK_F22               = 311,
	TUIK_F23               = 312,
	TUIK_F24               = 313,
	TUIK_F25               = 314,
	TUIK_KP_0              = 320,
	TUIK_KP_1              = 321,
	TUIK_KP_2              = 322,
	TUIK_KP_3              = 323,
	TUIK_KP_4              = 324,
	TUIK_KP_5              = 325,
	TUIK_KP_6              = 326,
	TUIK_KP_7              = 327,
	TUIK_KP_8              = 328,
	TUIK_KP_9              = 329,
	TUIK_KP_DECIMAL        = 330,
	TUIK_KP_DIVIDE         = 331,
	TUIK_KP_MULTIPLY       = 332,
	TUIK_KP_SUBTRACT       = 333,
	TUIK_KP_ADD            = 334,
	TUIK_KP_ENTER          = 335,
	TUIK_KP_EQUAL          = 336,
	TUIK_LEFT_SHIFT        = 340,
	TUIK_LEFT_CONTROL      = 341,
	TUIK_LEFT_ALT          = 342,
	TUIK_LEFT_SUPER        = 343,
	TUIK_RIGHT_SHIFT       = 344,
	TUIK_RIGHT_CONTROL     = 345,
	TUIK_RIGHT_ALT         = 346,
	TUIK_RIGHT_SUPER       = 347,
	TUIK_MENU              = 348,

	TUIK_LAST              = TUIK_MENU
} TuiKeyboardKey;

extern const char* kTuik_Space_Name;
extern const char* kTuik_Apostrophe_Name;
extern const char* kTuik_Comma_Name;
extern const char* kTuik_Minus_Name;
extern const char* kTuik_Period_Name;
extern const char* kTuik_Slash_Name;
extern const char* kTuik_0_Name;
extern const char* kTuik_1_Name;
extern const char* kTuik_2_Name;
extern const char* kTuik_3_Name;
extern const char* kTuik_4_Name;
extern const char* kTuik_5_Name;
extern const char* kTuik_6_Name;
extern const char* kTuik_7_Name;
extern const char* kTuik_8_Name;
extern const char* kTuik_9_Name;
extern const char* kTuik_Semicolon_Name;
extern const char* kTuik_Equal_Name;
extern const char* kTuik_A_Name;
extern const char* kTuik_B_Name;
extern const char* kTuik_C_Name;
extern const char* kTuik_D_Name;
extern const char* kTuik_E_Name;
extern const char* kTuik_F_Name;
extern const char* kTuik_G_Name;
extern const char* kTuik_H_Name;
extern const char* kTuik_I_Name;
extern const char* kTuik_J_Name;
extern const char* kTuik_K_Name;
extern const char* kTuik_L_Name;
extern const char* kTuik_M_Name;
extern const char* kTuik_N_Name;
extern const char* kTuik_O_Name;
extern const char* kTuik_P_Name;
extern const char* kTuik_Q_Name;
extern const char* kTuik_R_Name;
extern const char* kTuik_S_Name;
extern const char* kTuik_T_Name;
extern const char* kTuik_U_Name;
extern const char* kTuik_V_Name;
extern const char* kTuik_W_Name;
extern const char* kTuik_X_Name;
extern const char* kTuik_Y_Name;
extern const char* kTuik_Z_Name;
extern const char* kTuik_Left_Bracket_Name;
extern const char* kTuik_Backslash_Name;
extern const char* kTuik_Right_Bracket_Name;
extern const char* kTuik_Grave_Accent_Name;
extern const char* kTuik_World_1_Name;
extern const char* kTuik_World_2_Name;
extern const char* kTuik_Escape_Name;
extern const char* kTuik_Enter_Name;
extern const char* kTuik_Tab_Name;
extern const char* kTuik_Backspace_Name;
extern const char* kTuik_Insert_Name;
extern const char* kTuik_Delete_Name;
extern const char* kTuik_Right_Name;
extern const char* kTuik_Left_Name;
extern const char* kTuik_Down_Name;
extern const char* kTuik_Up_Name;
extern const char* kTuik_Page_Up_Name;
extern const char* kTuik_Page_Down_Name;
extern const char* kTuik_Home_Name;
extern const char* kTuik_End_Name;
extern const char* kTuik_Caps_Lock_Name;
extern const char* kTuik_Scroll_Lock_Name;
extern const char* kTuik_Num_Lock_Name;
extern const char* kTuik_Print_Screen_Name;
extern const char* kTuik_Pause_Name;
extern const char* kTuik_F1_Name;
extern const char* kTuik_F2_Name;
extern const char* kTuik_F3_Name;
extern const char* kTuik_F4_Name;
extern const char* kTuik_F5_Name;
extern const char* kTuik_F6_Name;
extern const char* kTuik_F7_Name;
extern const char* kTuik_F8_Name;
extern const char* kTuik_F9_Name;
extern const char* kTuik_F10_Name;
extern const char* kTuik_F11_Name;
extern const char* kTuik_F12_Name;
extern const char* kTuik_F13_Name;
extern const char* kTuik_F14_Name;
extern const char* kTuik_F15_Name;
extern const char* kTuik_F16_Name;
extern const char* kTuik_F17_Name;
extern const char* kTuik_F18_Name;
extern const char* kTuik_F19_Name;
extern const char* kTuik_F20_Name;
extern const char* kTuik_F21_Name;
extern const char* kTuik_F22_Name;
extern const char* kTuik_F23_Name;
extern const char* kTuik_F24_Name;
extern const char* kTuik_F25_Name;
extern const char* kTuik_KP_0_Name;
extern const char* kTuik_KP_1_Name;
extern const char* kTuik_KP_2_Name;
extern const char* kTuik_KP_3_Name;
extern const char* kTuik_KP_4_Name;
extern const char* kTuik_KP_5_Name;
extern const char* kTuik_KP_6_Name;
extern const char* kTuik_KP_7_Name;
extern const char* kTuik_KP_8_Name;
extern const char* kTuik_KP_9_Name;
extern const char* kTuik_KP_Decimal_Name;
extern const char* kTuik_KP_Divide_Name;
extern const char* kTuik_KP_Multiply_Name;
extern const char* kTuik_KP_Subtract_Name;
extern const char* kTuik_KP_Add_Name;
extern const char* kTuik_KP_Enter_Name;
extern const char* kTuik_KP_Equal_Name;
extern const char* kTuik_Left_Shift_Name;
extern const char* kTuik_Left_Control_Name;
extern const char* kTuik_Left_Alt_Name;
extern const char* kTuik_Left_Super_Name;
extern const char* kTuik_Right_Shift_Name;
extern const char* kTuik_Right_Control_Name;
extern const char* kTuik_Right_Alt_Name;
extern const char* kTuik_Right_Super_Name;
extern const char* kTuik_Menu_Name;

TuiBoolean tuiKeyboardKeyIsValid(TuiKeyboardKey keyboard_key);
const char* tuiKeyboardKeyToString(TuiKeyboardKey keyboard_key);
TuiKeyboardKey tuiStringToKeyboardKey(const char* str);
int tuiKeyboardKeyGetScancode(TuiKeyboardKey keyboard_key);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard