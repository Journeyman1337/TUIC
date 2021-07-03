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
/*! \file key.h
 */
#ifndef TUIC_KEY_H //header guard
#define TUIC_KEY_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

enum TuiKey
{
	TUI_KEY_SPACE             = 32,
	TUI_KEY_APOSTROPHE        = 39, /* ' */
	TUI_KEY_COMMA             = 44, /* , */
	TUI_KEY_MINUS             = 45, /* - */
	TUI_KEY_PERIOD            = 46, /* . */
	TUI_KEY_SLASH             = 47, /* / */
	TUI_KEY_0                 = 48,
	TUI_KEY_1                 = 49,
	TUI_KEY_2                 = 50,
	TUI_KEY_3                 = 51,
	TUI_KEY_4                 = 52,
	TUI_KEY_5                 = 53,
	TUI_KEY_6                 = 54,
	TUI_KEY_7                 = 55,
	TUI_KEY_8                 = 56,
	TUI_KEY_9                 = 57,
	TUI_KEY_SEMICOLON         = 59, /* ; */
	TUI_KEY_EQUAL             = 61, /* = */
	TUI_KEY_A                 = 65,
	TUI_KEY_B                 = 66,
	TUI_KEY_C                 = 67,
	TUI_KEY_D                 = 68,
	TUI_KEY_E                 = 69,
	TUI_KEY_F                 = 70,
	TUI_KEY_G                 = 71,
	TUI_KEY_H                 = 72,
	TUI_KEY_I                 = 73,
	TUI_KEY_J                 = 74,
	TUI_KEY_K                 = 75,
	TUI_KEY_L                 = 76,
	TUI_KEY_M                 = 77,
	TUI_KEY_N                 = 78,
	TUI_KEY_O                 = 79,
	TUI_KEY_P                 = 80,
	TUI_KEY_Q                 = 81,
	TUI_KEY_R                 = 82,
	TUI_KEY_S                 = 83,
	TUI_KEY_T                 = 84,
	TUI_KEY_U                 = 85,
	TUI_KEY_V                 = 86,
	TUI_KEY_W                 = 87,
	TUI_KEY_X                 = 88,
	TUI_KEY_Y                 = 89,
	TUI_KEY_Z                 = 90,
	TUI_KEY_LEFT_BRACKET      = 91, /* [ */
	TUI_KEY_BACKSLASH         = 92, /* \ */
	TUI_KEY_RIGHT_BRACKET     = 93, /* ] */
	TUI_KEY_GRAVE_ACCENT      = 96, /* ` */
	TUI_KEY_WORLD_1           = 16, /* non-US #1 */
	TUI_KEY_WORLD_2           = 16, /* non-US #2 */

/* Function keys */
	TUI_KEY_ESCAPE            = 256,
	TUI_KEY_ENTER             = 257,
	TUI_KEY_TAB               = 258,
	TUI_KEY_BACKSPACE         = 259,
	TUI_KEY_INSERT            = 260,
	TUI_KEY_DELETE            = 261,
	TUI_KEY_RIGHT             = 262,
	TUI_KEY_LEFT              = 263,
	TUI_KEY_DOWN              = 264,
	TUI_KEY_UP                = 265,
	TUI_KEY_PAGE_UP           = 266,
	TUI_KEY_PAGE_DOWN         = 267,
	TUI_KEY_HOME              = 268,
	TUI_KEY_END               = 269,
	TUI_KEY_CAPS_LOCK         = 280,
	TUI_KEY_SCROLL_LOCK       = 281,
	TUI_KEY_NUM_LOCK          = 282,
	TUI_KEY_PRINT_SCREEN      = 283,
	TUI_KEY_PAUSE             = 284,
	TUI_KEY_F1                = 290,
	TUI_KEY_F2                = 291,
	TUI_KEY_F3                = 292,
	TUI_KEY_F4                = 293,
	TUI_KEY_F5                = 294,
	TUI_KEY_F6                = 295,
	TUI_KEY_F7                = 296,
	TUI_KEY_F8                = 297,
	TUI_KEY_F9                = 298,
	TUI_KEY_F10               = 299,
	TUI_KEY_F11               = 300,
	TUI_KEY_F12               = 301,
	TUI_KEY_F13               = 302,
	TUI_KEY_F14               = 303,
	TUI_KEY_F15               = 304,
	TUI_KEY_F16               = 305,
	TUI_KEY_F17               = 306,
	TUI_KEY_F18               = 307,
	TUI_KEY_F19               = 308,
	TUI_KEY_F20               = 309,
	TUI_KEY_F21               = 310,
	TUI_KEY_F22               = 311,
	TUI_KEY_F23               = 312,
	TUI_KEY_F24               = 313,
	TUI_KEY_F25               = 314,
	TUI_KEY_KP_0              = 320,
	TUI_KEY_KP_1              = 321,
	TUI_KEY_KP_2              = 322,
	TUI_KEY_KP_3              = 323,
	TUI_KEY_KP_4              = 324,
	TUI_KEY_KP_5              = 325,
	TUI_KEY_KP_6              = 326,
	TUI_KEY_KP_7              = 327,
	TUI_KEY_KP_8              = 328,
	TUI_KEY_KP_9              = 329,
	TUI_KEY_KP_DECIMAL        = 330,
	TUI_KEY_KP_DIVIDE         = 331,
	TUI_KEY_KP_MULTIPLY       = 332,
	TUI_KEY_KP_SUBTRACT       = 333,
	TUI_KEY_KP_ADD            = 334,
	TUI_KEY_KP_ENTER          = 335,
	TUI_KEY_KP_EQUAL          = 336,
	TUI_KEY_LEFT_SHIFT        = 340,
	TUI_KEY_LEFT_CONTROL      = 341,
	TUI_KEY_LEFT_ALT          = 342,
	TUI_KEY_LEFT_SUPER        = 343,
	TUI_KEY_RIGHT_SHIFT       = 344,
	TUI_KEY_RIGHT_CONTROL     = 345,
	TUI_KEY_RIGHT_ALT         = 346,
	TUI_KEY_RIGHT_SUPER       = 347,
	TUI_KEY_MENU              = 348,

	TUI_KEY_LAST              = TUI_KEY_MENU
};

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard