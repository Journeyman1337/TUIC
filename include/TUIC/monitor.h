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
/*! \file monitor.h
 */
#ifndef TUIC_MONITOR_H //header guard
#define TUIC_MONITOR_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/desktop_callback.h>


/*! @name Monitor Functions
 *
 * Functions for manipulating @ref TuiMonitor opaque objects.
 *  @{ */
/*!
 * @brief Get pointer to all @ref TuiMonitor on the system. 
 * 
 * @param count A pointer to where the monitor count will be stored. If it is @ref TUI_NULL or an error occurs, it is ignored.
 * 
 * @return A pointer to an array of all present @ref TuiMonitor.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly return.
 * 
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The monitor list pointed to will be changed and possible move to a different address when monitors are connected or disconnected.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
TuiMonitor* tuiGetMonitors(int* count);
/*!
 * @brief Get pointer to the primary @ref TuiMonitor.
 *
 * @return The primary monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly return.
 * 
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The lifetime of @ref TuiMonitor objects is handled internally by the library. They are automatically destroyed after the @ref tuiMonitorConnectedFunction callback is called after the monitor is destroyed.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
TuiMonitor tuiGetPrimaryMonitor();
/*!
 * @brief Get the pixel width and height of a @ref TuiMonitor.
 * 
 * @param out_pixel_width A pointer to where the pixel width of the monitor screen will be stored. If @ref TUI_NULL, it is ignored.
 * @param out_pixel_height A pointer to where the pixel height of the monitor screen will be stored. If @ref TUI_NULL, it is ignored.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiMonitorGetPixelDimensions(TuiMonitor monitor, int* out_pixel_width, int* out_pixel_height);
/*!
 * @brief Get the pixel width of a @ref TuiMonitor.
 *
 * @param monitor The @ref TuiMonitor.
 * 
 * @returns The pixel width of the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 * 
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiMonitorGetPixelWidth(TuiMonitor monitor);
/*!
 * @brief Get the pixel height of a @ref TuiMonitor.
 *
 * @param monitor The @ref TuiMonitor.
 *
 * @returns The pixel height of the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiMonitorGetPixelHeight(TuiMonitor monitor);
/*!
 * @brief Get the physical width and height of a @ref TuiMonitor in milimeters.
 *
 * @param out_physical_width A pointer to where the physical width of the monitor screen will be stored. If @ref TUI_NULL, it is ignored.
 * @param out_physical_height A pointer to where the physical height of the monitor screen will be stored. If @ref TUI_NULL, it is ignored.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors.The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiMonitorGetPhysicalSize(TuiMonitor monitor, int* out_physical_width, int* out_physical_height);
/*!
 * @brief Get the physical width of a @ref TuiMonitor in milimeters.
 *
 * @param monitor The @ref TuiMonitor.
 *
 * @returns The physical width of the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiMonitorGetPhysicalWidth(TuiMonitor monitor);
/*!
 * @brief Get the physical height of a @ref TuiMonitor in milimeters.
 *
 * @param monitor The @ref TuiMonitor.
 *
 * @returns The physical height of the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiMonitorGetPhysicalHeight(TuiMonitor monitor);
/*!
 * @brief Get the ratio between the @ref TuiMonitor DPI and the platform's default DPI width and height.
 *
 * @param out_scale_wide A pointer to where the scale wide will be stored. If @ref TUI_NULL, it is ignored.
 * @param out_scale_tall A pointer to where the scale tall will be stored. If @ref TUI_NULL, it is ignored.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiMonitorGetContentScale(TuiMonitor monitor, float* out_scale_wide, float* out_scale_tall);
/*!
 * @brief Get the content scale wide of a @ref TuiMonitor.
 *
 * @param monitor The @ref TuiMonitor.
 *
 * @returns The content scale wide of the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
float tuiMonitorGetContentScaleWide(TuiMonitor monitor);
/*!
 * @brief Get the content scale tall of a @ref TuiMonitor.
 *
 * @param monitor The @ref TuiMonitor.
 *
 * @returns The content scale tall of the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
float tuiMonitorGetContentScaleTall(TuiMonitor monitor);
/*!
 * @brief Get the refresh rate of a @ref TuiMonitor.
 *
 * @param monitor The @ref TuiMonitor.
 *
 * @returns The refresh rate of the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiMonitorGetRefreshRate(TuiMonitor monitor);
/*!
 * @brief Get the name of a @ref TuiMonitor.
 *
 * @param monitor The @ref TuiMonitor.
 *
 * @returns The name the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The name is freed from memory after the monitor is disconnected.
 * 
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
const char* tuiMonitorGetName(TuiMonitor monitor);
/*!
 * @brief Set the user pointer of a @ref TuiMonitor.
 *
 * @param monitor The @ref TuiMonitor.
 * @param user_pointer The user pointer.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void tuiMonitorSetUserPointer(TuiMonitor monitor, void* user_pointer);
/*!
 * @brief Get the user pointer of a @ref TuiMonitor.
 *
 * @param monitor The @ref TuiMonitor.
 *
 * @returns The user pointer of the monitor.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_MONITOR and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
void* tuiMonitorGetUserPointer(TuiMonitor monitor);
/*!
 * @brief Set the monitor connected callback.
 *
 * @param monitor The callback.
 *
 * @returns The previously set callback.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and GLFW errors. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
tuiMonitorConnectedFunction tuiSetMonitorConnectedCallback(tuiMonitorConnectedFunction callback);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard