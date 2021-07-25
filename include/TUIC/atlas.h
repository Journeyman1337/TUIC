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
/*! \file atlas.h
 */
#ifndef TUIC_ATLAS_H //header guard
#define TUIC_ATLAS_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/blend_mode.h>
TuiAtlas tuiAtlasCreateCoordinateImagePixelBoundingBoxes(TuiImage image, int glyph_count, uint16_t* glyph_bounding_boxes, TuiBlendMode blend_mode);
TuiAtlas tuiAtlasCreateCoordinateRawPixelsPixelBoundingBoxes(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, uint16_t* glyph_bounding_boxes, TuiBlendMode blend_mode);
TuiAtlas tuiAtlasCreateCoordinateRawPixelsRawUVs(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, float* raw_glyph_uvs, TuiBlendMode blend_mode);
TuiAtlas tuiAtlasCreateGridImage(TuiImage image, int tile_pixel_width, int tile_pixel_height, TuiBlendMode blend_mode);
TuiAtlas tuiAtlasCreateGridRawPixels(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int tile_pixel_width, int tile_pixel_height, TuiBlendMode blend_mode);
TuiAtlas tuiAtlasCreateCodepageImage(TuiImage image, TuiBlendMode blend_mode);
TuiAtlas tuiAtlasCreateCodepageRawPixels(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, TuiBlendMode blend_mode);
void tuiAtlasDestroy(TuiAtlas atlas);

int tuiGetAtlasCount();

int tuiAtlasGetChannelCount(TuiAtlas atlas);

int tuiAtlasGetPixelWidth(TuiAtlas atlas);

int tuiAtlasGetPixelHeight(TuiAtlas atlas);

void tuiAtlasGetPixelDimensions(TuiAtlas atlas, int* out_pixel_width, int* out_pixel_height, int* out_channel_count);

TuiBlendMode tuiAtlasGetBlendMode(TuiAtlas atlas);

void tuiAtlasSetBlendMode(TuiAtlas atlas, TuiBlendMode blend_mode);

int tuiAtlasGetGlyphCount(TuiAtlas atlas);

float* tuiGenerateUVCoordinatesFromPixelCooordinates(int glyph_count, uint16_t* pixel_coordinates, int texture_width, int texture_height, float* out_ptr);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard