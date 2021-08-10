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
/*! \file opengl33.h
 */
#ifndef TUIC_OPENGL33_H //header guard
#define TUIC_OPENGL33_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
void tuiSystemCreate_Opengl33();
void tuiSystemDestroy_Opengl33();
void tuiWindowCreate_Opengl33(TuiWindow window);
void tuiWindowDestroy_Opengl33(TuiWindow window);
void tuiWindowSetSize_Opengl33(TuiWindow window, size_t new_width, size_t new_height);
uint8_t* tuiWindowGetPixels_Opengl33(TuiWindow window, size_t* pixel_width, size_t* pixel_height, uint8_t* pixel_ptr);
void tuiWindowClearColor_Opengl33(TuiWindow window, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void tuiWindowDrawBatchData_Opengl33(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, size_t tiles_wide, size_t tiles_tall, size_t sparse_index, const uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y);
void tuiWindowDrawPanel_Opengl33(TuiWindow window, TuiPanel panel, int left_x, int right_x, int top_y, int bottom_y);
void tuiWindowDrawTexture_Opengl33(TuiWindow window, TuiTexture texture, int left_x, int right_x, int top_y, int bottom_y);
void tuiWindowDrawAtlas_Opengl33(TuiWindow window, TuiAtlas atlas, int left_x, int right_x, int top_y, int bottom_y);
void tuiWindowDrawWindow_Opengl33(TuiWindow window, TuiWindow subject_window, int left_x, int right_x, int top_y, int bottom_y);
void tuiWindowRender_Opengl33(TuiWindow window);
void tuiAtlasCreate_Opengl33(TuiAtlas atlas, const uint8_t* pixel_data, const float* raw_glyph_uvs);
void tuiAtlasDestroy_Opengl33(TuiAtlas atlas);
void tuiTextureCreate_Opengl33(TuiTexture texture, const uint8_t* pixels);
void tuiTextureDestroy_Opengl33(TuiTexture texture);
void tuiTextureSetPixels_Opengl33(TuiTexture texture, const uint8_t* pixels);
void tuiPaletteCreate_Opengl33(TuiPalette palette, const uint8_t* color_data);
void tuiPaletteDestroy_Opengl33(TuiPalette palette);
void tuiPanelCreate_Opengl33(TuiPanel panel);
void tuiPanelDestroy_Opengl33(TuiPanel panel);
uint8_t* tuiPanelGetPixels_Opengl33(TuiPanel panel, size_t* pixel_width, size_t* pixel_height, uint8_t* pixel_ptr);
void tuiPanelClearColor_Opengl33(TuiPanel panel, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void tuiPanelDrawBatchData_Opengl33(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, size_t tiles_wide, size_t tiles_tall, size_t sparse_index, const uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y);
void tuiPanelDrawPanel_Opengl33(TuiPanel panel, TuiPanel subject_panel, int left_x, int right_x, int top_y, int bottom_y);
void tuiPanelDrawTexture_Opengl33(TuiPanel panel, TuiTexture texture, int left_x, int right_x, int top_y, int bottom_y);
void tuiPanelDrawAtlas_Opengl33(TuiPanel panel, TuiAtlas atlas, int left_x, int right_x, int top_y, int bottom_y);
void tuiPanelDrawWindow_Opengl33(TuiPanel panel, TuiWindow window, int left_x, int right_x, int top_y, int bottom_y);
void tuiPanelSetSize_Opengl33(TuiPanel panel, size_t new_width, size_t new_height);
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard
