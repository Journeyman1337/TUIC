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

TuiMonitor* tuiGetMonitors(int* count);
TuiMonitor tuiGetPrimaryMonitor();
void tuiMonitorGetPixelDimensions(TuiMonitor monitor, int* pixel_width, int* pixel_height);
int tuiMonitorGetPixelWidth(TuiMonitor monitor);
int tuiMonitorGetPixelHeight(TuiMonitor monitor);
void tuiMonitorGetPhysicalSize(TuiMonitor monitor, int* physical_width, int* physical_height);
void tuiMonitorGetContentScale(TuiMonitor monitor, float* content_width, float* content_height);
int tuiMonitorGetRefreshRate(TuiMonitor monitor);
const char* tuiMonitorGetName(TuiMonitor monitor);
void tuiMonitorSetUserPointer(TuiMonitor monitor, void* pointer);
void* tuiMonitorGetUserPointer(TuiMonitor monitor);
tuiMonitorFunction tuiSetMonitorCallback(tuiMonitorFunction callback);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard