/*! \file texture.h
 */
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
/*! \file image.h
 */
#ifndef TUIC_TEXTURE_H //header guard
#define TUIC_TEXTURE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

typedef TuiTexture_s* TuiTexture;
typedef enum TuiResult_e TuiResult; 

TuiResult tuiTextureCreate(TuiTexture* texture, uint8_t* pixel_data, int pixel_width, int pixel_height);

void tuiTextureDestroy(TuiTexture texture);

void tuiTextureGetPixelDimensions(TuiTexture texture, int* pixel_width, int* pixel_height);

size_t tuiGetTextureCount();

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard