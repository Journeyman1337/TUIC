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
/*! \file window.h
 */
#ifndef TUIC_WINDOW_H //header guard
#define TUIC_WINDOW_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>
#include <TUIC/detail_mode.h>
#include <TUIC/mouse_button.h>
#include <TUIC/keyboard_key.h>
#include <TUIC/button_state.h>
#include <TUIC/cursor_mode.h>

typedef struct TuiWindowCreateInfo
{
	TuiBoolean resizable;
	TuiBoolean visible;
	TuiBoolean decorated;
	TuiBoolean focused;
	TuiBoolean auto_iconify;
	TuiBoolean topmost;
	TuiBoolean maximized;
	TuiBoolean center_cursor;
	TuiBoolean focus_on_show;
	TuiBoolean fullscreen;
	TuiMonitor monitor;
	TuiBoolean custom_window_position;
	int windowed_x_position;
	int windowed_y_position;
	TuiBoolean framebuffer_match_viewport_pixel_dimensions;
	int unmatching_viewport_pixel_width;
	int umnatching_viewport_pixel_height;
} TuiWindowCreateInfo;

TuiWindowCreateInfo tuiWindowCreateInfo();

TuiWindow tuiWindowCreate(int framebuffer_pixel_width, int framebuffer_pixel_height, const char* title, TuiWindowCreateInfo* create_info);

void tuiWindowDestroy(TuiWindow window);

int tuiGetWindowCount();

void tuiWindowClearColor(TuiWindow window, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

void tuiWindowSetFramebufferPixelDimensions(TuiWindow window, int pixel_width, int pixel_height);

int tuiWindowGetFramebufferPixelWidth(TuiWindow window);

int tuiWindowGetFramebufferPixelHeight(TuiWindow window);

void tuiWindowGetFramebufferPixelDimensons(TuiWindow window, int* width, int* height);

TuiImage tuiWindowGetImage(TuiWindow window);

void tuiWindowWriteImage(TuiWindow window, TuiImage image);

uint8_t* tuiWindowGetPixels(TuiWindow window, int* pixel_width, int* pixel_height, uint8_t* fill_pixels);

void tuiWindowDrawBatch(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiBatch batch);

void tuiWindowDrawBatchData(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data);

void tuiWindowDrawBatchTransformed(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y);

void tuiWindowDrawBatchDataTransformed(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y);

void tuiWindowDrawPanel(TuiWindow window, TuiPanel panel);

void tuiWindowDrawPanelTransformed(TuiWindow window, TuiPanel panel, int left_x, int right_x, int top_y, int bottom_y);

void tuiWindowDrawTexture(TuiWindow window, TuiTexture texture);

void tuiWindowDrawTextureTransformed(TuiWindow window, TuiTexture texture, int left_x, int right_x, int top_y, int bottom_y);

void tuiWindowDrawAtlas(TuiWindow window, TuiAtlas atlas);

void tuiWindowDrawAtlasTransformed(TuiWindow window, TuiAtlas atlas, int left_x, int right_x, int top_y, int bottom_y);

void tuiWindowDrawWindow(TuiWindow window, TuiWindow subject_window);

void tuiWindowDrawWindowTransformed(TuiWindow window, TuiWindow subject_window, int left_x, int right_x, int top_y, int bottom_y);

void tuiWindowFrame(TuiWindow window);

void tuiWindowFrameInterval(TuiWindow window, int interval);

const char* tuiWindowGetClipboardString(TuiWindow window);

void tuiWindowSetClipboardString(TuiWindow window, const char* string);

TuiCursorMode tuiWindowGetCursorMode(TuiWindow window);

void tuiWindowSetCursorMode(TuiWindow window, TuiCursorMode cursor_mode);

TuiBoolean tuiWindowGetStickyKeys(TuiWindow window);

void tuiWindowSetStickyKeys(TuiWindow window, TuiBoolean sticky_keys_mode);

TuiBoolean tuiWindowGetStickyMouseButtons(TuiWindow window);

void tuiWindowSetStickyMouseButtons(TuiWindow window, TuiBoolean sticky_mouse_buttons);

TuiBoolean tuiWindowGetLockKeyMods(TuiWindow window);

void tuiWindowSetLockKeyMods(TuiWindow window, TuiBoolean lock_mods);

TuiBoolean tuiWindowGetRawMouseMotion(TuiWindow window);

void tuiWindowSetRawMouseMotion(TuiWindow window, TuiBoolean raw_mouse_motion);

TuiButtonState tuiWindowGetKeyboardKey(TuiWindow window, TuiKeyboardKey key);

TuiButtonState tuiWindowGetMouseButton(TuiWindow window, TuiMouseButton mouse_button);

void tuiWindowGetCursorPosition(TuiWindow window, double *x_position, double *y_position);

double tuiWindowGetCursorXPosition(TuiWindow window);

double tuiWindowGetCursorYPosition(TuiWindow window);

void tuiWindowSetCursorPosition(TuiWindow window, double x_position, double y_position);

TuiBoolean tuiWindowShouldClose(TuiWindow window);

void tuiWindowSetShouldClose(TuiWindow window, TuiBoolean should_close);

void tuiWindowSetTitle(TuiWindow window, const char* title);

const char* tuiWindowGetTitle(TuiWindow window);

void tuiWindowSetDefaultIcon(TuiWindow window);

void tuiWindowSetIcon(TuiWindow window, TuiImage image);

TuiBoolean tuiWindowIconsSupported();

void tuiWindowGetPosition(TuiWindow window, int* x_position, int* y_position);

int tuiWindowGetXPosition(TuiWindow window);

int tuiWindowGetYPosition(TuiWindow window);

void tuiWindowSetPosition(TuiWindow window, int x_position, int y_position);

void tuiWindowSetSizeLimits(TuiWindow window, int min_width, int min_height, int max_width, int max_height);

void tuiWindowSetMinSizeLimits(TuiWindow window, int min_width, int min_height);

void tuiWindowSetMaxSizeLimits(TuiWindow window, int max_width, int max_height);

void tuiWindowSetMinWidth(TuiWindow window, int min_width);

void tuiWindowSetMinHeight(TuiWindow window, int min_height);

void tuiWindowSetMaxWidth(TuiWindow window, int max_width);

void tuiWindowSetMaxHeight(TuiWindow window, int max_height);

void tuiWindowGetSizeLimits(TuiWindow window, int* min_width, int* min_height, int* max_width, int* max_height);

int tuiWindowGetMinWidth(TuiWindow window);

int tuiWindowGetMinHeight(TuiWindow window);

int tuiWindowGetMaxWidth(TuiWindow window);

int tuiWindowGetMaxHeight(TuiWindow window);

TuiBoolean tuiWindowHasSizeLimits(TuiWindow window);

TuiBoolean tuiWindowHasMinSizeLimits(TuiWindow window);

TuiBoolean tuiWindowHasMaxSizeLimits(TuiWindow window);

void tuiWindowSetFixedAspectRatio(TuiWindow window, int numerator, int denominator);

void tuiWindowFixCurrentAspectRatio(TuiWindow window);

void tuiWindowUnfixAspectRatio(TuiWindow window);

TuiBoolean tuiWindowGetAspectRatioIsFixed(TuiWindow window);

void tuiWindowGetAspectRatio(TuiWindow, int* numerator, int* denominator);

void tuiWindowGetContentScale(TuiWindow window, float* scale_wide, float* scale_tall);

float tuiWindowGetContentScaleWide(TuiWindow window);

float tuiWindowGetContentScaleTall(TuiWindow window);

float tuiWindowGetOpacity(TuiWindow window);

void tuiWindowSetOpacity(TuiWindow window, float opacity);

void tuiWindowIconify(TuiWindow window);

void tuiWindowRestore(TuiWindow window);

void tuiWindowMaximize(TuiWindow window);

void tuiWindowShow(TuiWindow window);

void tuiWindowHide(TuiWindow window);

void tuiWindowFocus(TuiWindow window);

void tuiWindowRequestAttention(TuiWindow window);

TuiMonitor tuiWindowGetMonitor(TuiWindow window);

void tuiWindowSetFullscreenCurrentMonitor(TuiWindow window);

void tuiWindowSetFullscreen(TuiWindow window, TuiMonitor monitor);

void tuiWindowSetWindowed(TuiWindow window);

void tuiWindowSetWindowedViewportSize(TuiWindow window, int viewport_pixel_width, int viewport_pixel_height);

int tuiWindowGetViewportPixelWidth(TuiWindow window);

int tuiWindowGetViewportPixelHeight(TuiWindow window);

void tuiWindowGetViewportPixelDimensons(TuiWindow window, int* width, int* height);

void tuiWindowSetFramebufferMatchesViewportSize(TuiWindow window, TuiBoolean framebuffer_matches_viewport_size);

TuiBoolean tuiWindowGetFramebufferMatchesViewportSize(TuiWindow window);

TuiBoolean tuiWindowGetIsFullscreen(TuiWindow window);

TuiBoolean tuiWindowGetFocused(TuiWindow window);

TuiBoolean tuiWindowGetIconified(TuiWindow window);

TuiBoolean tuiWindowGetMaximized(TuiWindow window);

TuiBoolean tuiWindowGetMouseEntered(TuiWindow window);

TuiBoolean tuiWindowGetVisible(TuiWindow window);

TuiBoolean tuiWindowGetResizable(TuiWindow window);

void tuiWindowSetResizable(TuiWindow window, TuiBoolean resizable);

TuiBoolean tuiWindowGetDecorated(TuiWindow window);

void tuiWindowSetDecorated(TuiWindow window, TuiBoolean decorated);

TuiBoolean tuiWindowGetAutoIconify(TuiWindow window);

void tuiWindowSetAutoIconify(TuiWindow window, TuiBoolean auto_iconify);

TuiBoolean tuiWindowGetTopmost(TuiWindow window);

void tuiWindowSetTopmost(TuiWindow window, TuiBoolean topmost);

TuiBoolean tuiWindowGetFocusOnShow(TuiWindow window);

void tuiWindowSetFocusOnShow(TuiWindow window, TuiBoolean focus_on_show);

void tuiWindowSetUserPointer(TuiWindow window, void* ptr);

void* tuiWindowGetUserPointer(TuiWindow window);

void tuiWindowSetCursor(TuiWindow window, TuiCursor cursor);

tuiWindowMoveFunction tuiWindowSetMoveCallback(TuiWindow window, tuiWindowMoveFunction callback);

tuiWindowCloseFunction tuiWindowSetCloseCallback(TuiWindow window, tuiWindowCloseFunction callback);

tuiWindowRefreshFunction tuiWindowSetRefreshCallback(TuiWindow window, tuiWindowRefreshFunction callback);

tuiWindowFocusFunction tuiWindowSetFocusCallback(TuiWindow window, tuiWindowFocusFunction callback);

tuiWindowIconifyFunction tuiWindowSetIconifyCallback(TuiWindow window, tuiWindowIconifyFunction callback);

tuiWindowMaximizeFunction tuiWindowSetMaximizeCallback(TuiWindow window, tuiWindowMaximizeFunction callback);

tuiWindowResizeFunction tuiWindowSetResizeCallback(TuiWindow window, tuiWindowResizeFunction callback);

tuiWindowContentScaleFunction tuiWindowSetContentScaleCallback(TuiWindow window, tuiWindowContentScaleFunction callback);

tuiKeyboardKeyboardKeyFunction tuiWindowSetKeyboardKeyCallback(TuiWindow window, tuiKeyboardKeyboardKeyFunction callback);

tuiCharFunction tuiWindowSetCharCallback(TuiWindow window, tuiCharFunction callback);

tuiMouseButtonFunction tuiWindowSetMouseButtonCallback(TuiWindow window, tuiMouseButtonFunction callback);

tuiCursorMoveFunction tuiWindowSetCursorMoveCallback(TuiWindow window, tuiCursorMoveFunction callback);

tuiCursorEnterFunction tuiWindowSetCursorEnterCallback(TuiWindow window, tuiCursorEnterFunction callback);

tuiMouseScrollFunction tuiWindowSetMouseScrollCallback(TuiWindow window, tuiMouseScrollFunction callback);

tuiFileDropFunction tuiWindowSetFileDropCallback(TuiWindow window, tuiFileDropFunction callback);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard