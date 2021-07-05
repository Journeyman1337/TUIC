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
/*! \file system.h
 */
#ifndef TUIC_SYSTEM_H //header guard
#define TUIC_SYSTEM_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/desktop_callback.h>

int tuiInit();
int tuiIsActive();
void tuiTerminate();
void tuiPollEvents();
void tuiWaitEvents();
void tuiWaitEventsTimeout(double timeout);
void tuiPostEmptyEvent();
int tuiRawMouseMotionSupported(void);
const char* tuiGetKeyName(int key, int scancode);
int tuiGetKeyScancode(int key);
int tuiJoystickPresent(int jid);
const float* tuiGetJoystickAxes(int jid, int* count);
const unsigned char* tuiGetJoystickButtons(int jid, int* count);
const unsigned char* tuiGetJoystickHats(int jid, int* count);
const char* tuiGetJoystickName(int jid);
const char* tuiGetJoystickGUID(int jid);
void tuiSetJoystickUserPointer(int jid, void* pointer);
void* tuiGetJoystickUserPointer(int jid);
int tuiJoystickIsGamepad(int jid);
tuiJoysticFunction tuiSetJoystickCallback(tuiJoysticFunction callback);
int tuiUpdateGamepadMappings(const char* string);
const char* tuiGetGamepadName(int jid);
double tuiGetTime();
void tuiSetTime(double time);
uint64_t tuiGetTimerValue();
uint64_t tuiGetTimerFrequency();
int tuiVulkanSupported();

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard