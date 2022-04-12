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
#include <TUIC/system.h>

#include <assert.h>
#include <stddef.h>
#include <string.h>

static int sAtlasCount = 0;

TuiResult tuiAtlasCreateFromImage(TuiAtlas* atlas, int width, int height, int pages, const uint8_t* pixel_data, const float* const stpqp_coordinates, const int glyph_count)
{
	assert(atlas != NULL);
	assert(pixel_data != NULL);
	assert(stpqp_coordinates != NULL);
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	if (glyph_count <= 0 || width <= 0 || height <= 0 || pages <= 0)
	{
		return TUI_RESULT_ERROR_INVALID_VALUE;
	}
	*atlas = (TuiAtlas)tuiAllocate(sizeof(TuiAtlas_s));
	if (*atlas == NULL)
	{
		return TUI_RESULT_ERROR_OUT_OF_MEMORY;
	}
	memset(atlas, 0, sizeof(TuiAtlas_s));
	(*atlas)->ChannelCount = image->ChannelCount;
	(*atlas)->Width = width;
	(*atlas)->Height = height;
	(*atlas)->Pages = pages;
	(*atlas)->GlyphCount = glyph_count;
	TuiResult result = tuiAtlasCreate_Opengl33((*atlas), pixel_data, stpqp_coordinates);	
	if (result != TUI_RESULT_OK)
	{
		tuiFree(*atlas)
		*atlas = NULL;
		return result;
	}
	sAtlasCount++;
	return TUI_RESULT_OK;
}

void tuiAtlasDestroy(TuiAtlas atlas)
{
	assert(atlas != NULL);
	tuiAtlasDestroy_Opengl33(atlas);
	tuiFree(atlas);
	sAtlasCount--;
}

TuiResult tuiAtlasSetData(TuiAtlas atlas, int width, int height, int pages, const uint8_t* pixel_data, const float* const stpqp_coordinates, const int glyph_count)
{
	assert(atlas != NULL);
	assert(pixel_data != NULL);
	assert(stpqp_coordinates != NULL);
	tuiAtlasDestroy_Opengl33(atlas);
	atlas->ChannelCount = image->ChannelCount;
	atlas->Width = width;
	atlas->Height = height;
	atlas->Pages = pages;
	atlas->GlyphCount = glyph_count;
	TuiResult result = tuiAtlasCreate_Opengl33(atlas, pixel_data, stpqp_coordinates);	
	if (result != TUI_RESULT_OK)
	{
		tuiFree(atlas);
		sAtlasCount--;
		return result;
	}
	return TUI_RESULT_OK;
}

void tuiAtlasGetDimensions(TuiAtlas atlas, int* const width, int* const height, int* const pages)
{
	assert(atlas != NULL);
	if (width != NULL)
	{
		*width = atlas->Width;
	}
	if (height != NULL)
	{
		*height = atlas->Height;
	}
	if (pages != NULL)
	{
		*pages = atlas->Pages;
	}
}

int tuiAtlasGetGlyphCount(TuiAtlas atlas)
{
	assert(atlas != NULL);
	return atlas->GlyphCount;
}

size_t tuiGetAtlasCount()
{
	return sAtlasCount;
}