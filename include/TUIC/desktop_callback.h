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
/*! \file desktop_callback.h
 */
#ifndef TUIC_DESKTOP_CALLBACK_H //header guard
#define TUIC_DESKTOP_CALLBACK_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>
#include <TUIC/mouse_button.h>
#include <TUIC/button_state.h>
#include <TUIC/keyboard_mod.h>
#include <TUIC/keyboard_key.h>
#include <TUIC/types.h>


/*! @name Desktop Callbacks
 *
 * These callback function types are used for events related to desktop platforms.
 *
 *  @{ */
/*!
 * @brief Callback type used for @ref TuiWindow move events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param x_position The new x monitor pixel position of the window.
 * @param y_position The new y monitor pixel position of the window.
 */
typedef void (* tuiWindowMoveFunction)(TuiWindow window, int x_position, int y_position);
/*!
 * @brief Callback type used for TuiWindow close events.
 *
 * @params window The @ref TuiWindow that caused the event.
 */
typedef void (* tuiWindowCloseFunction)(TuiWindow window);
/*!
 * @brief Callback type used for  @ref TuiWindow focus events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param focused If the window gained or lost focus.
 */
typedef void (* tuiWindowFocusFunction)(TuiWindow window, TuiBoolean focused);
/*!
 * @brief Callback type used for TuiWindow iconify events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param iconified If the window iconified or restored from an iconify.
 */
typedef void (* tuiWindowIconifyFunction)(TuiWindow window,TuiBoolean iconified);
/*!
 * @brief Callback type used for  @ref TuiWindow maximize events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param maximized If the window maximized or restored from a maximize.
 */
typedef void (* tuiWindowMaximizeFunction)(TuiWindow window, TuiBoolean maximized);
/*!
 * @brief Callback type used for  @ref TuiWindow viewport resize events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param pixel_width The new pixel width of the window's viewport.
 * @param pixel_height The new pixel height of the window's viewport.
 */
typedef void (* tuiWindowViewportResizeFunction)(TuiWindow window, int pixel_width, int pixel_height);
/*!
 * @brief Callback type used for TuiWindow content scale.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param scale_wide The new scale wide of the window.
 * @param scale_tall The new scale tall of the window.
 */
typedef void (* tuiWindowContentScaleFunction)(TuiWindow window, float scale_wide, float scale_tall);
/*!
 * @brief Callback type used for  @ref TuiWindow mouse button events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param mouse_button The @ref TuiMouseButton that caused the event.
 * @param button_state The @ref TuiButtonState of the mouse button.
 * @param mod The @ref TuiKeyboardMod keys that are currently pressed.
 */
typedef void (* tuiMouseButtonFunction)(TuiWindow window, TuiMouseButton mouse_button, TuiButtonState button_state, TuiKeyboardMod mod);
/*!
 * @brief Callback type used for  @ref TuiWindow mouse move events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param x_position The new x pixel position of the cursor.
 * @param y_position The new y pixel position of the cursor.
 */
typedef void (* tuiCursorMoveFunction)(TuiWindow window, double x_position, double y_position);
/*!
 * @brief Callback type used for @ref TuiWindow mouse enter events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param entered If the mouse entered or exited the window.
 */
typedef void (* tuiCursorEnterFunction)(TuiWindow window, TuiBoolean entered);
/*!
 * @brief Callback type used for  @ref TuiWindow mouse scroll events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param x_translate The horizontal mouse scroll distance.
 * @parma y_translate The vertical mouse scroll distance.
 */
typedef void (* tuiMouseScrollFunction)(TuiWindow window, double x_translate, double y_translate);
/*!
 * @brief Callback type used for @ref TuiWindow keyboard key events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param key The @ref TuiKeyboardKey that caused the event.
 * @param scancode The keyboard scancode of the keyboard key.
 * @param button_state The @ref TuiButtonState of the keyboard key.
 * @param mod The @ref TuiKeyboardMod keys currently pressed.
 */
typedef void (* tuiKeyboardKeyboardKeyFunction)(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState button_state, TuiKeyboardMod mod);
/*!
 * @brief Callback type used for @ref TuiWindow character typed events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param codepoint THe unicode value of the character that was typed.
 */
typedef void (* tuiCharFunction)(TuiWindow window, unsigned int codepoint);
/*!
 * @brief Callback type used for @ref TuiWindow file drop events.
 *
 * @param window The @ref TuiWindow that captured the event.
 * @param path_count The amount of files/folders that were dropped in the window.
 * @param paths An array of the full paths of the dropped files.
 * 
 * @pointer_lifetime paths is only safe to access until a file drop callback is called again, at which point it will be overwritten.
 */
typedef void (* tuiFileDropFunction)(TuiWindow window, int path_count, const char* paths[]);
/*!
 * @brief Callback type used for @ref TuiMonitor connected events.
 *
 * @param monitor The @ref TuiMonitor that captured the event.
 * @param connected If the monitor was connected or disconnected
 *
 * @pointer_lifetime After this callback is called when a monitor is disconnected, the monitor struct will automatically be deleted by the library.
 */
typedef void (*tuiMonitorConnectedFunction)(TuiMonitor monitor, TuiBoolean connected);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard