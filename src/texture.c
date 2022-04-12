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
#include <TUIC/tuic.h>
#include "objects.h"
#include "opengl33.h"

#include <string.h>
#include <assert.h>

static int sTextureCount = 0;

TuiResult tuiTextureCreate(TuiTexture* texture, uint8_t* pixel_data, int pixel_width, int pixel_height)
{
	assert(texture != NULL);
	assert(pixel_data != NULL);
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		return TUI_RESULT_ERROR_INVALID_VALUE;
	}
	*texture = (TuiTexture)tuiAllocate(sizeof(TuiTexture_s));
	memset(*texture, 0, sizeof(TuiTexture_s));
	(*texture)->PixelWidth = pixel_width;
	(*texture)->PixelHeight = pixel_height;
	TuiResult result = tuiTextureCreate_Opengl33((*texture), pixel_data, pixel_width, pixel_height);
	if (result != TUI_RESULT_OK)
	{
		tuiFree(*texture);
		*texture = NULL;
		return result;
	}
	sTextureCount++;
	return TUI_RESULT_OK;
}

void tuiTextureDestroy(TuiTexture texture)
{
	assert(texture != NULL);
	tuiTextureDestroy_Opengl33(texture);
	tuiFree(texture);
	sTextureCount--;
}

void tuiTextureGetPixelDimensions(TuiTexture texture, int* pixel_width, int* pixel_height)
{
	assert(texture != NULL);
	if (pixel_width != NULL)
	{
		*pixel_width = texture->PixelWidth;
	}
	if (pixel_height != NULL)
	{
		*pixel_height = texture->PixelHeight;
	}
}

size_t tuiGetTextureCount()
{
	return sTextureCount;
}