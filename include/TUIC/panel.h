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
/*! \file panel.h
 */
#ifndef TUIC_PANEL_H //header guard
#define TUIC_PANEL_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

typedef TuiAtlas_s* TuiAtlas;
typedef TuiTexture_s* TuiTexture;
typedef TuiConsole_s* TuiConsole;
typedef TuiWindow_s* TuiWindow;
typedef TuiPanel_s* TuiPanel;

TuiResult tuiPanelCreate(TuiPanel* panel, int pixel_width, int pixel_height);

void tuiPanelDestroy(TuiPanel panel);

TuiResult tuiPanelGetPixels(TuiPanel panel, uint8_t** pixels, int* pixel_width, int* pixel_height);

TuiResult tuiPanelClearColor(TuiPanel panel, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

TuiResult tuiPanelSetPixelDimensions(TuiPanel panel, int pixel_width, int pixel_height);

void tuiPanelGetPixelDimensions(TuiPanel panel, int* pixel_width, int* pixel_height);

TuiResult tuiPanelDrawConsole(TuiPanel panel, TuiAtlas atlas, TuiConsole console);

TuiResult tuiPanelDrawConsoleTransformed(TuiPanel panel, TuiAtlas atlas, TuiConsole console, int left_x, int right_x, int top_y, int bottom_y);

TuiResult tuiPanelDrawPanel(TuiPanel panel, TuiPanel subject_panel);

TuiResult tuiPanelDrawPanelTransformed(TuiPanel panel, TuiPanel subject_panel, int left_x, int right_x, int top_y, int bottom_y);

TuiResult tuiPanelDrawTexture(TuiPanel panel, TuiTexture texture);

TuiResult tuiPanelDrawTextureTransformed(TuiPanel panel, TuiTexture texture, int left_x, int right_x, int top_y, int bottom_y);

TuiResult tuiPanelDrawWindow(TuiPanel panel, TuiWindow window);

TuiResult tuiPanelDrawWindowTransformed(TuiPanel panel, TuiWindow window, int left_x, int right_x, int top_y, int bottom_y);

size_t tuiGetPanelCount();

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard