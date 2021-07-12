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
#include <TUIC/types.h>

TuiPanel tuiPanelCreate(TuiWindow window, int pixel_width, int pixel_height);

void tuiPanelDestroy(TuiPanel panel);

TuiWindow tuiPanelGetWindow(TuiPanel panel);

TuiImage tuiPanelGetImage(TuiPanel panel, TuiImage fill_image);

uint8_t* tuiPanelGetPixels(TuiPanel panel, int* pixel_width, int* pixel_height, uint8_t* fill_pixels);

void tuiPanelClearColor(TuiPanel panel, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

void tuiPanelSetPixelDimensions(TuiPanel panel, int pixel_width, int pixel_height);

void tuiPanelGetPixelDimensions(TuiPanel panel, int* pixel_width, int* pixel_height);

int tuiPanelGetPixelWidth(TuiPanel panel);

int tuiPanelGetPixelHeight(TuiPanel panel);

void tuiPanelDrawBatch(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiBatch batch);

void tuiPanelDrawBatchData(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data);

void tuiPanelDrawBatchTransformed(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y);

void tuiPanelDrawBatchDataTransformed(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y);

void tuiPanelRender(TuiPanel panel);

void tuiPanelRenderTransformed(TuiPanel panel, int left_x, int right_x, int top_y, int bottom_y);

void tuiPanelRenderToPanel(TuiPanel panel, TuiPanel target_panel);

void tuiPanelRenderToPanelTransformed(TuiPanel panel, TuiPanel target_panel, int left_x, int right_x, int top_y, int bottom_y);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard