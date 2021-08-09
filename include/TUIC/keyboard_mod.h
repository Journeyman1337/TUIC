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



/*! @name Keyboard Mods
 *  @{ */
/*!
 * @brief Keyboard modifier keys.
 */
typedef enum TuiKeyboardMod
{
	/*!
	 * \brief The keyboard mod is invalid.
	 *
	 * This keyboard mod is returned when an error occurs, and is also used to specify that no keyboard mod is
	 * defined.
	 */
	TUI_MOD_INVALID	 	    = 0x0040,
	/*!
	 * \brief A shift key is pressed.
	 */
	TUI_MOD_SHIFT           = 0x0001,
	/*!
	 * \brief A control key is pressed.
	 */
	TUI_MOD_CONTROL         = 0x0002,
	/*!
	 * \brief An alt key is pressed.
	 */
	TUI_MOD_ALT             = 0x0004,
	/*!
	 * \brief A super key is pressed.
	 */
	TUI_MOD_SUPER           = 0x0008,
	/*!
	 * \brief A caps lock key is pressed.
	 */
	TUI_MOD_CAPS_LOCK       = 0x0010,
	/*!
	 * \brief A num lock key is pressed.
	 */
	TUI_MOD_NUM_LOCK        = 0x0020,
	/*!
	 * \brief Now mod keys are pressed.
	 */
	TUI_MOD_NONE			= 0,
	/*!
	 * \brief All mod keys  pressed.
	 */
	TUI_MOD_ALL				= (TUI_MOD_SHIFT | TUI_MOD_CONTROL | TUI_MOD_ALT | TUI_MOD_SUPER | TUI_MOD_CAPS_LOCK | TUI_MOD_NUM_LOCK)
} TuiKeyboardMod;
/*! @} */


/*! @name Keyboard Mod Names
 *  @{ */
/*!
 * @brief String name of @ref TUI_MOD_SHIFT.
 */
extern const char* kTui_Keyboard_Mod_Shift_Name;
/*!
 * @brief String name of @ref TUI_MOD_CONTROL.
 */
extern const char* kTui_Keyboard_Mod_Control_Name;
/*!
 * @brief String name of @ref TUI_MOD_ALT.
 */
extern const char* kTui_Keyboard_Mod_Alt_Name;
/*!
 * @brief String name of @ref TUI_MOD_SUPER.
 */
extern const char* kTui_Keyboard_Mod_Super_Name;
/*!
 * @brief String name of @ref TUI_MOD_CAPS_LOCK.
 */
extern const char* kTui_Keyboard_Mod_Caps_Lock_Name;
/*!
 * @brief String name of @ref TUI_MOD_NUM_LOCK.
 */
extern const char* kTui_Keyboard_Mod_Num_Lock_Name;
/*!
 * @brief String name of @ref TUI_MOD_NONE.
 */
extern const char* kTui_Keyboard_Mod_None_Name;
/*!
 * @brief String name of @ref TUI_MOD_ALL.
 */
extern const char* kTui_Keyboard_Mod_All_Name;
/*! @} */


/*! @name Keyboard Mod Functions
 *
 * Functions for dealing with @ref TuiKeyboardMod enum values.
 *  @{ */
 /*!
  * @brief Determine if a @ref TuiKeyboardMod enum is valid.
  *
  * @param keyboard_mod The @ref TuiKeyboardMod to check.
  *
  * @returns The @ref TuiBoolean result. If keyboard_mod is a valid @ref TuiKeyboardMod, it
  * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
  *
  * @errors This function can have no errors.
  *
  * @requirements This function can be called freely, even if TUIC is not currently initialized.
  *
  * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
  */
TuiBoolean tuiKeyboardModIsValid(TuiKeyboardMod keyboard_mod);
/*!
 * @brief Retrieve the string name associated with a @ref TuiKeyboardMod enum.
 *
 * @param keyboard_mod The @ref TuiKeyboardMod to get the name of.
 *
 * @returns The string name. @ref TUI_NULL is returned if cursor_shape is an invalid @ref TuiKeyboardMod.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiKeyboardModToString(TuiKeyboardMod keyboard_mod);
/*!
 * @brief Determine the @ref TuiKeyboardMod enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The TuiKeyboardMod. @ref TUI_MOD_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiKeyboardMod tuiStringToKeyboardMod(const char* str);
/*!
 * @brief Determine if a @ref TuiKeyboardMod enum contains a @ref TuiKeyboardMod.
 *
 * @param keyboard_mod The @ref TuiKeyboardMod to check for the flag.
 * @param contains_keyboard_mod The @ref TuiKeyboardMod to check for within the other mod.
 *
 * @returns The @ref TuiBoolean result. If keyboard_mod contains the contains_keyboard_mod, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiKeyboardModHasMod(TuiKeyboardMod keyboard_mod, TuiKeyboardMod contains_keyboard_mod);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard