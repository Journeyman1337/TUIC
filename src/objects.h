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
/*! \file objects.h
 */
#ifndef TUIC_OPAQUE_OBJECTS_H // header guard
#define TUIC_OPAQUE_OBJECTS_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <stdint.h>
#include <TUIC/types.h>
#include <GLFW/glfw3.h>
#include <TUIC/desktop_callback.h>

typedef struct TuiSystem_s
{
	TuiBoolean WindowIconsSupported;

	GLFWwindow* BaseWindow;

	tuiMonitorConnectedFunction MonitorConnectedCallback;

	void* ApiData;
} TuiSystem_s;

typedef TuiSystem_s* TuiSystem;

TuiSystem tui_get_system();

typedef struct TuiWindow_s
{
	void* UserPointer;

	char* Title;

	tuiWindowMoveFunction WindowMoveCallback;

	tuiWindowCloseFunction WindowCloseCallback;

	tuiWindowFocusFunction WindowFocusCallback;

	tuiWindowIconifyFunction WindowIconifyCallback;

	tuiWindowMaximizeFunction WindowMaximizeCallback;

	tuiWindowViewportResizeFunction WindowViewportResizeCallback;

	tuiWindowContentScaleFunction WindowContentScaleCallback;

	tuiMouseButtonFunction MouseButtonCallback;

	tuiCursorMoveFunction CursorMoveCallback;

	tuiCursorEnterFunction CursorEnterCallback;

	tuiMouseScrollFunction MouseScrollCallback;

	tuiKeyboardKeyboardKeyFunction KeyboardKeyCallback;

	tuiCharFunction CharCallback;

	tuiFileDropFunction FileDropCallback;

	GLFWwindow* GlfwWindow;

	size_t ViewportPixelWidth;

	size_t ViewportPixelHeight;

	size_t FramebufferPixelWidth;

	size_t FramebufferPixelHeight;

	TuiBoolean IsFullscreen;

	TuiBoolean FramebufferMatchViewportSize;

	int FullscreenLastWindowedPositionX;

	int FullscreenLastWindowedPositionY;

	TuiBoolean IsFixedAspectRatio;

	int MinWidth;

	int MinHeight;

	int MaxWidth;

	int MaxHeight;

	void* ApiData;
} TuiWindow_s;

typedef struct TuiAtlas_s
{
	size_t Width;

	size_t Height;
	
	size_t Pages;
	
	size_t Channels;
	
	size_t BitDepth;

	size_t GlyphCount;

	void* ApiData;
} TuiAtlas_s;

typedef struct TuiTexture_s
{

	size_t PixelWidth;

	size_t PixelHeight;

	size_t ChannelCount;

	void* ApiData;
} TuiTexture_s;

typedef struct TuiPanel_s
{

	size_t PixelWidth;

	size_t PixelHeight;

	void* ApiData;
} TuiPanel_s;

typedef struct TuiConsole_s
{
	size_t PixelWidth;
	
    size_t PixelHeight;
	
    size_t TilesWide;
	
    size_t TilesTall;
	
    float PixelScale;
	
    size_t TileWidth;
	
    size_t TileHeight;
	
    size_t TileDataCapacity;
	
    size_t TileDataCount;
	
    uint8_t* TileData;
} TuiConsole_s;

#ifdef __cplusplus // extern C guard
}
#endif
#endif // header guard