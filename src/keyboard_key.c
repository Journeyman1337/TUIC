#include <TUIC/keyboard_key.h>
#include <GLFW/glfw3.h>
#include <stddef.h>
#include <TUIC/system.h>
#include <TUIC/debug.h>
#include "glfw_error_check.h"
#include "objects.h"

const char* kTuik_Space_Name = "KEY_SPACE";

const char* kTuik_Apostrophe_Name = "KEY_POSTROPHE";

const char* kTuik_Comma_Name = "KEY_COMMA";

const char* kTuik_Minus_Name = "KEY_MINUS";

const char* kTuik_Period_Name = "KEY_PERIOD";

const char* kTuik_Slash_Name = "KEY_SLASH";

const char* kTuik_0_Name = "KEY_0";

const char* kTuik_1_Name = "KEY_1";

const char* kTuik_2_Name = "KEY_2";

const char* kTuik_3_Name = "KEY_3";

const char* kTuik_4_Name = "KEY_4";

const char* kTuik_5_Name = "KEY_5";

const char* kTuik_6_Name = "KEY_6";

const char* kTuik_7_Name = "KEY_7";

const char* kTuik_8_Name = "KEY_8";

const char* kTuik_9_Name = "KEY_9";

const char* kTuik_Semicolon_Name = "KEY_SEMICOLON";

const char* kTuik_Equal_Name = "KEY_EQUAL";

const char* kTuik_A_Name = "KEY_A";

const char* kTuik_B_Name = "KEY_B";

const char* kTuik_C_Name = "KEY_C";

const char* kTuik_D_Name = "KEY_D";

const char* kTuik_E_Name = "KEY_E";

const char* kTuik_F_Name = "KEY_F";

const char* kTuik_G_Name = "KEY_G";

const char* kTuik_H_Name = "KEY_H";

const char* kTuik_I_Name = "KEY_I";

const char* kTuik_J_Name = "KEY_J";

const char* kTuik_K_Name = "KEY_K";

const char* kTuik_L_Name = "KEY_L";

const char* kTuik_M_Name = "KEY_M";

const char* kTuik_N_Name = "KEY_N";

const char* kTuik_O_Name = "KEY_O";

const char* kTuik_P_Name = "KEY_P";

const char* kTuik_Q_Name = "KEY_Q";

const char* kTuik_R_Name = "KEY_R";

const char* kTuik_S_Name = "KEY_S";

const char* kTuik_T_Name = "KEY_T";

const char* kTuik_U_Name = "KEY_U";

const char* kTuik_V_Name = "KEY_V";

const char* kTuik_W_Name = "KEY_W";

const char* kTuik_X_Name = "KEY_X";

const char* kTuik_Y_Name = "KEY_Y";

const char* kTuik_Z_Name = "KEY_Z";

const char* kTuik_Left_Bracket_Name = "KEY_LEFT_BRACKET";

const char* kTuik_Backslash_Name = "KEY_BAKCSLASH";

const char* kTuik_Right_Bracket_Name = "KEY_RIGHT_BRACKET";

const char* kTuik_Grave_Accent_Name = "KEY_GRAVE_ACCENT";

const char* kTuik_World_1_Name = "KEY_WORLD_1";

const char* kTuik_World_2_Name = "KEY_WORLD_2";

const char* kTuik_Escape_Name = "KEY_ESCAPE";

const char* kTuik_Enter_Name = "KEY_ENTER";

const char* kTuik_Tab_Name = "KEY_TAB";

const char* kTuik_Backspace_Name = "KEY_BACKSPACE";

const char* kTuik_Insert_Name = "KEY_INSERT";

const char* kTuik_Delete_Name = "KEY_DELETE";

const char* kTuik_Right_Name = "KEY_RIGHT";

const char* kTuik_Left_Name = "KEY_LEFT";

const char* kTuik_Down_Name = "KEY_DOWN";

const char* kTuik_Up_Name = "KEY_UP";

const char* kTuik_Page_Up_Name = "KEY_PAGE_UP";

const char* kTuik_Page_Down_Name = "KEY_PAGE_DOWN";

const char* kTuik_Home_Name = "KEY_HOME";

const char* kTuik_End_Name = "KEY_END";

const char* kTuik_Caps_Lock_Name = "KEY_CAPS_LOCK";

const char* kTuik_Scroll_Lock_Name = "KEY_SCROLL_LOCK";

const char* kTuik_Num_Lock_Name = "KEY_NUM_LOCK";

const char* kTuik_Print_Screen_Name = "KEY_PRINT_SCREEN";

const char* kTuik_Pause_Name = "KEY_PAUSE";

const char* kTuik_F1_Name = "KEY_F1";

const char* kTuik_F2_Name = "KEY_F2";

const char* kTuik_F3_Name = "KEY_F3";

const char* kTuik_F4_Name = "KEY_F4";

const char* kTuik_F5_Name = "KEY_F5";

const char* kTuik_F6_Name = "KEY_F6";

const char* kTuik_F7_Name = "KEY_F7";

const char* kTuik_F8_Name = "KEY_F8";

const char* kTuik_F9_Name = "KEY_F9";

const char* kTuik_F10_Name = "KEY_F10";

const char* kTuik_F11_Name = "KEY_F11";

const char* kTuik_F12_Name = "KEY_F12";

const char* kTuik_F13_Name = "KEY_F13";

const char* kTuik_F14_Name = "KEY_F14";

const char* kTuik_F15_Name = "KEY_F15";

const char* kTuik_F16_Name = "KEY_F16";

const char* kTuik_F17_Name = "KEY_F16";

const char* kTuik_F18_Name = "KEY_F18";

const char* kTuik_F19_Name = "KEY_F19";

const char* kTuik_F20_Name = "KEY_F20";

const char* kTuik_F21_Name = "KEY_F21";

const char* kTuik_F22_Name = "KEY_F22";

const char* kTuik_F23_Name = "KEY_F23";

const char* kTuik_F24_Name = "KEY_F24";

const char* kTuik_F25_Name = "KEY_F25";

const char* kTuik_KP_0_Name = "KEY_F26";

const char* kTuik_KP_1_Name = "KEY_KP_1";

const char* kTuik_KP_2_Name = "KEY_KP_2";

const char* kTuik_KP_3_Name = "KEY_KP_3";

const char* kTuik_KP_4_Name = "KEY_KP_4";

const char* kTuik_KP_5_Name = "KEY_KP_5";

const char* kTuik_KP_6_Name = "KEY_KP_6";

const char* kTuik_KP_7_Name = "KEY_KP_7";

const char* kTuik_KP_8_Name = "KEY_KP_8";

const char* kTuik_KP_9_Name = "KEY_KP_9";

const char* kTuik_KP_Decimal_Name = "KEY_KP_DECIMAL";

const char* kTuik_KP_Divide_Name = "KEY_KP_DIVIDE";

const char* kTuik_KP_Multiply_Name = "KEY_KP_MULTIPLY";

const char* kTuik_KP_Subtract_Name = "KEY_KP_SUBTRACT";

const char* kTuik_KP_Add_Name = "KEY_KP_ADD";

const char* kTuik_KP_Enter_Name = "KEY_KP_ENTER";

const char* kTuik_KP_Equal_Name = "KEY_KP_EQUAL";

const char* kTuik_Left_Shift_Name = "KEY_LEFT_SHIFT";

const char* kTuik_Left_Control_Name = "KEY_LEFT_CONTROL";

const char* kTuik_Left_Alt_Name = "KEY_LEFT_ALT";

const char* kTuik_Left_Super_Name = "KEY_LEFT_SUPER";

const char* kTuik_Right_Shift_Name = "KEY_RIGHT_SHIFT";

const char* kTuik_Right_Control_Name = "KEY_RIGHT_CONTROL";

const char* kTuik_Right_Alt_Name = "KEY_RIGHT_ALT";

const char* kTuik_Right_Super_Name = "KEY_RIGHT_SUPER";

const char* kTuik_Menu_Name = "KEY_MENU";

TuiBoolean tuiKeyboardKeyIsValid(TuiKeyboardKey key)
{
	if (
			(key == TUIK_SPACE) ||
			(key == TUIK_APOSTROPHE) ||
			(key >= TUIK_COMMA && key <= TUIK_GRAVE_ACCENT) ||
			(key == TUIK_WORLD_1) ||
			(key == TUIK_WORLD_2) ||
			(key >= TUIK_ESCAPE && key <= TUIK_MENU)
		)
	{
		return TUI_TRUE;
	}
	else
	{
		return TUI_FALSE;
	}
}

const char* tuiKeyboardKeyToString(TuiKeyboardKey key)
{
	// keys are seperated into groups to encourage compiler to generate lookup tables and speed up debug builds
	if (key >= TUIK_COMMA && key <= TUIK_GRAVE_ACCENT)
	{
		switch (key)
		{
		case TUIK_COMMA:
			return kTuik_Comma_Name;
		case TUIK_MINUS:
			return kTuik_Minus_Name;
		case TUIK_PERIOD:
			return kTuik_Period_Name;
		case TUIK_SLASH:
			return kTuik_Slash_Name;
		case TUIK_0:
			return kTuik_0_Name;
		case TUIK_1:
			return kTuik_1_Name;
		case TUIK_2:
			return kTuik_2_Name;
		case TUIK_3:
			return kTuik_3_Name;
		case TUIK_4:
			return kTuik_4_Name;
		case TUIK_5:
			return kTuik_5_Name;
		case TUIK_6:
			return kTuik_6_Name;
		case TUIK_7:
			return kTuik_7_Name;
		case TUIK_8:
			return kTuik_8_Name;
		case TUIK_9:
			return kTuik_9_Name;
		case TUIK_SEMICOLON:
			return kTuik_Semicolon_Name;
		case TUIK_EQUAL:
			return kTuik_Equal_Name;
		case TUIK_A:
			return kTuik_A_Name;
		case TUIK_B:
			return kTuik_B_Name;
		case TUIK_C:
			return kTuik_C_Name;
		case TUIK_D:
			return kTuik_D_Name;
		case TUIK_E:
			return kTuik_E_Name;
		case TUIK_F:
			return kTuik_F_Name;
		case TUIK_G:
			return kTuik_G_Name;
		case TUIK_H:
			return kTuik_H_Name;
		case TUIK_I:
			return kTuik_I_Name;
		case TUIK_J:
			return kTuik_J_Name;
		case TUIK_K:
			return kTuik_K_Name;
		case TUIK_L:
			return kTuik_L_Name;
		case TUIK_M:
			return kTuik_M_Name;
		case TUIK_N:
			return kTuik_N_Name;
		case TUIK_O:
			return kTuik_0_Name;
		case TUIK_P:
			return kTuik_P_Name;
		case TUIK_Q:
			return kTuik_Q_Name;
		case TUIK_R:
			return kTuik_R_Name;
		case TUIK_S:
			return kTuik_S_Name;
		case TUIK_T:
			return kTuik_T_Name;
		case TUIK_U:
			return kTuik_U_Name;
		case TUIK_V:
			return kTuik_V_Name;
		case TUIK_W:
			return kTuik_W_Name;
		case TUIK_X:
			return kTuik_X_Name;
		case TUIK_Y:
			return kTuik_Y_Name;
		case TUIK_Z:
			return kTuik_Z_Name;
		case TUIK_LEFT_BRACKET:
			return kTuik_Left_Bracket_Name;
		case TUIK_BACKSLASH:
			return kTuik_Backslash_Name;
		case TUIK_RIGHT_BRACKET:
			return kTuik_Right_Bracket_Name;
		case TUIK_GRAVE_ACCENT:
			return kTuik_Grave_Accent_Name;
		}
	}
	else if (key >= TUIK_ESCAPE && key <= TUIK_MENU)
	{
		switch (key)
		{
		case TUIK_ESCAPE:
			return kTuik_Escape_Name;
		case TUIK_ENTER:
			return kTuik_Enter_Name;
		case TUIK_TAB:
			return kTuik_Tab_Name;
		case TUIK_BACKSPACE:
			return kTuik_Backspace_Name;
		case TUIK_INSERT:
			return kTuik_Insert_Name;
		case TUIK_DELETE:
			return kTuik_Delete_Name;
		case TUIK_RIGHT:
			return kTuik_Right_Name;
		case TUIK_LEFT:
			return kTuik_Left_Name;
		case TUIK_DOWN:
			return kTuik_Down_Name;
		case TUIK_UP:
			return kTuik_Up_Name;
		case TUIK_PAGE_UP:
			return kTuik_Page_Up_Name;
		case TUIK_PAGE_DOWN:
			return kTuik_Page_Down_Name;
		case TUIK_HOME:
			return kTuik_Home_Name;
		case TUIK_END:
			return kTuik_End_Name;
		case TUIK_CAPS_LOCK:
			return kTuik_Caps_Lock_Name;
		case TUIK_SCROLL_LOCK:
			return kTuik_Scroll_Lock_Name;
		case TUIK_NUM_LOCK:
			return kTuik_Num_Lock_Name;
		case TUIK_PRINT_SCREEN:
			return kTuik_Pause_Name;
		case TUIK_F1:
			return kTuik_F1_Name;
		case TUIK_F2:
			return kTuik_F2_Name;
		case TUIK_F3:
			return kTuik_F3_Name;
		case TUIK_F4:
			return kTuik_F4_Name;
		case TUIK_F5:
			return kTuik_F5_Name;
		case TUIK_F6:
			return kTuik_F6_Name;
		case TUIK_F7:
			return kTuik_F7_Name;
		case TUIK_F8:
			return kTuik_F8_Name;
		case TUIK_F9:
			return kTuik_F9_Name;
		case TUIK_F10:
			return kTuik_F10_Name;
		case TUIK_F11:
			return kTuik_F11_Name;
		case TUIK_F12:
			return kTuik_F12_Name;
		case TUIK_F13:
			return kTuik_F13_Name;
		case TUIK_F14:
			return kTuik_F14_Name;
		case TUIK_F15:
			return kTuik_F15_Name;
		case TUIK_F16:
			return kTuik_F16_Name;
		case TUIK_F17:
			return kTuik_F17_Name;
		case TUIK_F18:
			return kTuik_F18_Name;
		case TUIK_F19:
			return kTuik_F19_Name;
		case TUIK_F20:
			return kTuik_F20_Name;
		case TUIK_F21:
			return kTuik_F21_Name;
		case TUIK_F22:
			return kTuik_F22_Name;
		case TUIK_F23:
			return kTuik_F23_Name;
		case TUIK_F24:
			return kTuik_F24_Name;
		case TUIK_F25:
			return kTuik_F25_Name;
		case TUIK_KP_0:
			return kTuik_KP_0_Name;
		case TUIK_KP_1:
			return kTuik_KP_1_Name;
		case TUIK_KP_2:
			return kTuik_KP_2_Name;
		case TUIK_KP_3:
			return kTuik_KP_3_Name;
		case TUIK_KP_4:
			return kTuik_KP_4_Name;
		case TUIK_KP_5:
			return kTuik_KP_5_Name;
		case TUIK_KP_6:
			return kTuik_KP_6_Name;
		case TUIK_KP_7:
			return kTuik_KP_7_Name;
		case TUIK_KP_8:
			return kTuik_KP_8_Name;
		case TUIK_KP_9:
			return kTuik_KP_9_Name;
		case TUIK_KP_DECIMAL:
			return kTuik_KP_Decimal_Name;
		case TUIK_KP_DIVIDE:
			return kTuik_KP_Divide_Name;
		case TUIK_KP_MULTIPLY:
			return kTuik_KP_Multiply_Name;
		case TUIK_KP_SUBTRACT:
			return kTuik_KP_Subtract_Name;
		case TUIK_KP_ADD:
			return kTuik_KP_Add_Name;
		case TUIK_KP_ENTER:
			return kTuik_KP_Enter_Name;
		case TUIK_KP_EQUAL:
			return kTuik_KP_Equal_Name;
		case TUIK_LEFT_SHIFT:
			return kTuik_Left_Shift_Name;
		case TUIK_LEFT_CONTROL:
			return kTuik_Left_Control_Name;
		case TUIK_LEFT_ALT:
			return kTuik_Left_Alt_Name;
		case TUIK_LEFT_SUPER:
			return kTuik_Left_Super_Name;
		case TUIK_RIGHT_SHIFT:
			return kTuik_Right_Shift_Name;
		case TUIK_RIGHT_CONTROL:
			return kTuik_Right_Control_Name;
		case TUIK_RIGHT_ALT:
			return kTuik_Right_Alt_Name;
		case TUIK_RIGHT_SUPER:
			return kTuik_Right_Super_Name;
		case TUIK_MENU:
			return kTuik_Menu_Name;
		}
	}
	switch (key)
	{
	case TUIK_SPACE:
		return kTuik_Space_Name;
	case TUIK_APOSTROPHE:
		return kTuik_Apostrophe_Name;
	case TUIK_WORLD_1:
		return kTuik_World_1_Name;
	case TUIK_WORLD_2:
		return kTuik_World_2_Name;
	default:
		return NULL;
	}
}

TuiKeyboardKey tuiStringToKey(const char* str)
{
	if (strcmp(str, kTuik_Space_Name) == 0)
	{
		return TUIK_SPACE;
	}
	else if (strcmp(str, kTuik_Apostrophe_Name) == 0)
	{
		return TUIK_APOSTROPHE;
	}
	else if (strcmp(str, kTuik_Comma_Name) == 0)
	{
		return TUIK_COMMA;
	}
	else if (strcmp(str, kTuik_Minus_Name) == 0)
	{
		return TUIK_MINUS;
	}
	else if (strcmp(str, kTuik_Period_Name) == 0)
	{
		return TUIK_PERIOD;
	}
	else if (strcmp(str, kTuik_Slash_Name) == 0)
	{
		return TUIK_SLASH;
	}
	else if (strcmp(str, kTuik_0_Name) == 0)
	{
		return TUIK_0;
	}
	else if (strcmp(str, kTuik_1_Name) == 0)
	{
		return TUIK_1;
	}
	else if (strcmp(str, kTuik_2_Name) == 0)
	{
		return TUIK_2;
	}
	else if (strcmp(str, kTuik_3_Name) == 0)
	{
		return TUIK_3;
	}
	else if (strcmp(str, kTuik_4_Name) == 0)
	{
		return TUIK_4;
	}
	else if (strcmp(str, kTuik_5_Name) == 0)
	{
		return TUIK_5;
	}
	else if (strcmp(str, kTuik_6_Name) == 0)
	{
		return TUIK_6;
	}
	else if (strcmp(str, kTuik_7_Name) == 0)
	{
		return TUIK_7;
	}
	else if (strcmp(str, kTuik_8_Name) == 0)
	{
		return TUIK_8;
	}
	else if (strcmp(str, kTuik_9_Name) == 0)
	{
		return TUIK_9;
	}
	else if (strcmp(str, kTuik_Semicolon_Name) == 0)
	{
		return TUIK_SEMICOLON;
	}
	else if (strcmp(str, kTuik_Equal_Name) == 0)
	{
		return TUIK_EQUAL;
	}
	else if (strcmp(str, kTuik_A_Name) == 0)
	{
		return TUIK_A;
	}
	else if (strcmp(str, kTuik_B_Name) == 0)
	{
		return TUIK_B;
	}
	else if (strcmp(str, kTuik_C_Name) == 0)
	{
		return TUIK_C;
	}
	else if (strcmp(str, kTuik_D_Name) == 0)
	{
		return TUIK_D;
	}
	else if (strcmp(str, kTuik_E_Name) == 0)
	{
		return TUIK_E;
	}
	else if (strcmp(str, kTuik_F_Name) == 0)
	{
		return TUIK_F;
	}
	else if (strcmp(str, kTuik_G_Name) == 0)
	{
		return TUIK_G;
	}
	else if (strcmp(str, kTuik_H_Name) == 0)
	{
		return TUIK_H;
	}
	else if (strcmp(str, kTuik_I_Name) == 0)
	{
		return TUIK_I;
	}
	else if (strcmp(str, kTuik_J_Name) == 0)
	{
		return TUIK_J;
	}
	else if (strcmp(str, kTuik_K_Name) == 0)
	{
		return TUIK_K;
	}
	else if (strcmp(str, kTuik_L_Name) == 0)
	{
		return TUIK_L;
	}
	else if (strcmp(str, kTuik_M_Name) == 0)
	{
		return TUIK_M;
	}
	else if (strcmp(str, kTuik_N_Name) == 0)
	{
		return TUIK_N;
	}
	else if (strcmp(str, kTuik_O_Name) == 0)
	{
		return TUIK_O;
	}
	else if (strcmp(str, kTuik_P_Name) == 0)
	{
		return TUIK_P;
	}
	else if (strcmp(str, kTuik_Q_Name) == 0)
	{
		return TUIK_Q;
	}
	else if (strcmp(str, kTuik_R_Name) == 0)
	{
		return TUIK_R;
	}
	else if (strcmp(str, kTuik_S_Name) == 0)
	{
		return TUIK_S;
	}
	else if (strcmp(str, kTuik_T_Name) == 0)
	{
		return TUIK_T;
	}
	else if (strcmp(str, kTuik_U_Name) == 0)
	{
		return TUIK_U;
	}
	else if (strcmp(str, kTuik_V_Name) == 0)
	{
		return TUIK_V;
	}
	else if (strcmp(str, kTuik_W_Name) == 0)
	{
		return TUIK_W;
	}
	else if (strcmp(str, kTuik_X_Name) == 0)
	{
		return TUIK_X;
	}
	else if (strcmp(str, kTuik_Y_Name) == 0)
	{
		return TUIK_Y;
	}
	else if (strcmp(str, kTuik_Z_Name) == 0)
	{
		return TUIK_Z;
	}
	else if (strcmp(str, kTuik_Left_Bracket_Name) == 0)
	{
		return TUIK_LEFT_BRACKET;
	}
	else if (strcmp(str, kTuik_Backslash_Name) == 0)
	{
		return TUIK_BACKSLASH;
	}
	else if (strcmp(str, kTuik_Right_Bracket_Name) == 0)
	{
		return TUIK_RIGHT_BRACKET;
	}
	else if (strcmp(str, kTuik_Grave_Accent_Name) == 0)
	{
		return TUIK_GRAVE_ACCENT;
	}
	else if (strcmp(str, kTuik_World_1_Name) == 0)
	{
		return TUIK_WORLD_1;
	}
	else if (strcmp(str, kTuik_World_2_Name) == 0)
	{
		return TUIK_WORLD_2;
	}
	else if (strcmp(str, kTuik_Escape_Name) == 0)
	{
		return TUIK_ESCAPE;
	}
	else if (strcmp(str, kTuik_Enter_Name) == 0)
	{
		return TUIK_ENTER;
	}
	else if (strcmp(str, kTuik_Tab_Name) == 0)
	{
		return TUIK_TAB;
	}
	else if (strcmp(str, kTuik_Backspace_Name) == 0)
	{
		return TUIK_BACKSPACE;
	}
	else if (strcmp(str, kTuik_Insert_Name) == 0)
	{
		return TUIK_INSERT;
	}
	else if (strcmp(str, kTuik_Delete_Name) == 0)
	{
		return TUIK_DELETE;
	}
	else if (strcmp(str, kTuik_Right_Name) == 0)
	{
		return TUIK_RIGHT;
	}
	else if (strcmp(str, kTuik_Left_Name) == 0)
	{
		return TUIK_LEFT;
	}
	else if (strcmp(str, kTuik_Down_Name) == 0)
	{
		return TUIK_DOWN;
	}
	else if (strcmp(str, kTuik_Up_Name) == 0)
	{
		return TUIK_UP;
	}
	else if (strcmp(str, kTuik_Page_Up_Name) == 0)
	{
		return TUIK_PAGE_UP;
	}
	else if (strcmp(str, kTuik_Page_Down_Name) == 0)
	{
		return TUIK_PAGE_DOWN;
	}
	else if (strcmp(str, kTuik_Home_Name) == 0)
	{
		return TUIK_HOME;
	}
	else if (strcmp(str, kTuik_End_Name) == 0)
	{
		return TUIK_END;
	}
	else if (strcmp(str, kTuik_Caps_Lock_Name) == 0)
	{
		return TUIK_CAPS_LOCK;
	}
	else if (strcmp(str, kTuik_Scroll_Lock_Name) == 0)
	{
		return TUIK_SCROLL_LOCK;
	}
	else if (strcmp(str, kTuik_Num_Lock_Name) == 0)
	{
		return TUIK_NUM_LOCK;
	}
	else if (strcmp(str, kTuik_Print_Screen_Name) == 0)
	{
		return TUIK_PRINT_SCREEN;
	}
	else if (strcmp(str, kTuik_Pause_Name) == 0)
	{
		return TUIK_PAUSE;
	}
	else if (strcmp(str, kTuik_F1_Name) == 0)
	{
		return TUIK_F1;
	}
	else if (strcmp(str, kTuik_F2_Name) == 0)
	{
		return TUIK_F2;
	}
	else if (strcmp(str, kTuik_F3_Name) == 0)
	{
		return TUIK_F3;
	}
	else if (strcmp(str, kTuik_F4_Name) == 0)
	{
		return TUIK_F4;
	}
	else if (strcmp(str, kTuik_F5_Name) == 0)
	{
		return TUIK_F5;
	}
	else if (strcmp(str, kTuik_F6_Name) == 0)
	{
		return TUIK_F6;
	}
	else if (strcmp(str, kTuik_F7_Name) == 0)
	{
		return TUIK_F7;
	}
	else if (strcmp(str, kTuik_F8_Name) == 0)
	{
		return TUIK_F8;
	}
	else if (strcmp(str, kTuik_F9_Name) == 0)
	{
		return TUIK_F9;
	}
	else if (strcmp(str, kTuik_F10_Name) == 0)
	{
		return TUIK_F10;
	}
	else if (strcmp(str, kTuik_F11_Name) == 0)
	{
		return TUIK_F11;
	}
	else if (strcmp(str, kTuik_F12_Name) == 0)
	{
		return TUIK_F12;
	}
	else if (strcmp(str, kTuik_F13_Name) == 0)
	{
		return TUIK_F13;
	}
	else if (strcmp(str, kTuik_F14_Name) == 0)
	{
		return TUIK_F14;
	}
	else if (strcmp(str, kTuik_F15_Name) == 0)
	{
		return TUIK_F15;
	}
	else if (strcmp(str, kTuik_F16_Name) == 0)
	{
		return TUIK_F16;
	}
	else if (strcmp(str, kTuik_F17_Name) == 0)
	{
		return TUIK_F17;
	}
	else if (strcmp(str, kTuik_F18_Name) == 0)
	{
		return TUIK_F18;
	}
	else if (strcmp(str, kTuik_F18_Name) == 0)
	{
		return TUIK_F19;
	}
	else if (strcmp(str, kTuik_F20_Name) == 0)
	{
		return TUIK_F20;
	}
	else if (strcmp(str, kTuik_F21_Name) == 0)
	{
		return TUIK_F21;
	}
	else if (strcmp(str, kTuik_F22_Name) == 0)
	{
		return TUIK_F22;
	}
	else if (strcmp(str, kTuik_F23_Name) == 0)
	{
		return TUIK_F23;
	}
	else if (strcmp(str, kTuik_F24_Name) == 0)
	{
		return TUIK_F24;
	}
	else if (strcmp(str, kTuik_F25_Name) == 0)
	{
		return TUIK_F25;
	}
	else if (strcmp(str, kTuik_KP_0_Name) == 0)
	{
		return TUIK_KP_0;
	}
	else if (strcmp(str, kTuik_KP_1_Name) == 0)
	{
		return TUIK_KP_1;
	}
	else if (strcmp(str, kTuik_KP_2_Name) == 0)
	{
		return TUIK_KP_2;
	}
	else if (strcmp(str, kTuik_KP_3_Name) == 0)
	{
		return TUIK_KP_3;
	}
	else if (strcmp(str, kTuik_KP_4_Name) == 0)
	{
		return TUIK_KP_4;
	}
	else if (strcmp(str, kTuik_KP_5_Name) == 0)
	{
		return TUIK_KP_5;
	}
	else if (strcmp(str, kTuik_KP_6_Name) == 0)
	{
		return TUIK_KP_6;
	}
	else if (strcmp(str, kTuik_KP_7_Name) == 0)
	{
		return TUIK_KP_7;
	}
	else if (strcmp(str, kTuik_KP_8_Name) == 0)
	{
		return TUIK_KP_9;
	}
	else if (strcmp(str, kTuik_KP_9_Name) == 0)
	{
		return TUIK_KP_9;
	}
	else if (strcmp(str, kTuik_KP_Decimal_Name) == 0)
	{
		return TUIK_KP_DECIMAL;
	}
	else if (strcmp(str, kTuik_KP_Divide_Name) == 0)
	{
		return TUIK_KP_DIVIDE;
	}
	else if (strcmp(str, kTuik_KP_Multiply_Name) == 0)
	{
		return TUIK_KP_MULTIPLY;
	}
	else if (strcmp(str, kTuik_KP_Subtract_Name) == 0)
	{
		return TUIK_KP_SUBTRACT;
	}
	else if (strcmp(str, kTuik_KP_Add_Name) == 0)
	{
		return TUIK_KP_ADD;
	}
	else if (strcmp(str, kTuik_KP_Enter_Name) == 0)
	{
		return TUIK_KP_ENTER;
	}
	else if (strcmp(str, kTuik_KP_Equal_Name) == 0)
	{
		return TUIK_KP_EQUAL;
	}
	else if (strcmp(str, kTuik_Left_Shift_Name) == 0)
	{
		return TUIK_LEFT_SHIFT;
	}
	else if (strcmp(str, kTuik_Left_Control_Name) == 0)
	{
		return TUIK_LEFT_CONTROL;
	}
	else if (strcmp(str, kTuik_Left_Alt_Name) == 0)
	{
		return TUIK_LEFT_ALT;
	}
	else if (strcmp(str, kTuik_Left_Super_Name) == 0)
	{
		return TUIK_LEFT_SUPER;
	}
	else if (strcmp(str, kTuik_Right_Shift_Name) == 0)
	{
		return TUIK_RIGHT_SHIFT;
	}
	else if (strcmp(str, kTuik_Right_Control_Name) == 0)
	{
		return TUIK_RIGHT_CONTROL;
	}
	else if (strcmp(str, kTuik_Right_Alt_Name) == 0)
	{
		return TUIK_RIGHT_ALT;
	}
	else if (strcmp(str, kTuik_Right_Super_Name) == 0)
	{
		return TUIK_RIGHT_SUPER;
	}
	else if (strcmp(str, kTuik_Menu_Name) == 0)
	{
		return TUIK_MENU;
	}
	return TUIK_INVALID;
}

int tuiKeyboardKeyGetScancode(TuiKeyboardKey key)
{
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}

	int scancode = glfwGetKeyScancode(key);

	int glfw_error = glfwGetError(NULL);
	GLFW_CHECK_ERROR_RETURN(0)

	return scancode;
}