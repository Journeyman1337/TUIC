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

#include <stdio.h>
#include <string.h>

static int sAtlasCount = 0;

TuiAtlas tuiAtlasCreateCoordinateImagePixelBoundingBoxes(TuiImage image, int glyph_count, uint16_t* glyph_bounding_boxes, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}
	if (glyph_bounding_boxes == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES, __func__);
		return TUI_NULL;
	}
	if (glyph_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_COUNT, __func__);
		return TUI_NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return TUI_NULL;
	}

	TuiAtlas atlas = tuiAllocate(sizeof(TuiAtlas_s));
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_COORDS;
	atlas->ChannelCount = image->ChannelCount;
	atlas->PixelWidth = image->PixelWidth;
	atlas->PixelHeight = image->PixelHeight;
	atlas->TileWidth = 0;
	atlas->TileHeight = 0;
	atlas->PixelDataSize = image->PixelDataSize;
	atlas->ApiData = TUI_NULL;
	atlas->GlyphCount = (size_t)glyph_count;
	
	float* raw_glyph_uvs = tuiGenerateUVCoordinatesFromPixelCooordinates(glyph_count, glyph_bounding_boxes, image->PixelWidth, image->PixelHeight, TUI_NULL);
	TuiErrorCode error_code = tuiAtlasCreate_Opengl33(atlas, image->PixelData, raw_glyph_uvs);
	tuiFree(raw_glyph_uvs);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiAtlasDestroy_Opengl33(atlas);
		tuiFree(atlas);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sAtlasCount++;
	return atlas;
}

TuiAtlas tuiAtlasCreateCoordinateRawPixelsPixelBoundingBoxes(int pixel_width , int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, uint16_t* glyph_bounding_boxes, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (pixels == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return TUI_NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return TUI_NULL;
	}
	if (glyph_bounding_boxes == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES, __func__);
		return TUI_NULL;
	}
	if (glyph_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_COUNT, __func__);
		return TUI_NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return TUI_NULL;
	}

	TuiAtlas atlas = tuiAllocate(sizeof(TuiAtlas_s));
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_COORDS;
	atlas->ChannelCount = (size_t)channel_count;
	atlas->PixelWidth = (size_t)pixel_width;
	atlas->PixelHeight = (size_t)pixel_height;
	atlas->TileWidth = 0;
	atlas->TileHeight = 0;
	atlas->PixelDataSize = (size_t)pixel_width * (size_t)pixel_height * (size_t)channel_count;
	atlas->ApiData = TUI_NULL;
	atlas->GlyphCount = glyph_count;
	
	float* raw_glyph_uvs = tuiGenerateUVCoordinatesFromPixelCooordinates(glyph_count, glyph_bounding_boxes, pixel_width, pixel_height, TUI_NULL);
	TuiErrorCode error_code = tuiAtlasCreate_Opengl33(atlas, pixels, raw_glyph_uvs);
	tuiFree(raw_glyph_uvs);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiAtlasDestroy_Opengl33(atlas);
		tuiFree(atlas);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sAtlasCount++;
	return atlas;
}

TuiAtlas tuiAtlasCreateCoordinateImageRawUVs(TuiImage image, int glyph_count, float* raw_glyph_uvs, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}
	if (raw_glyph_uvs == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE_COORDINATES, __func__);
		return TUI_NULL;
	}
	if (glyph_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_COUNT, __func__);
		return TUI_NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return TUI_NULL;
	}

	TuiAtlas atlas = tuiAllocate(sizeof(TuiAtlas_s));
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_COORDS;
	atlas->ChannelCount = image->ChannelCount;
	atlas->PixelWidth = image->PixelWidth;
	atlas->PixelHeight = image->PixelHeight;
	atlas->TileWidth = 0;
	atlas->TileHeight = 0;
	atlas->PixelDataSize = image->PixelDataSize;
	atlas->ApiData = TUI_NULL;
	atlas->GlyphCount = (size_t)glyph_count;
	
	TuiErrorCode error_code = tuiAtlasCreate_Opengl33(atlas, image->PixelData, raw_glyph_uvs);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiAtlasDestroy_Opengl33(atlas);
		tuiFree(atlas);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sAtlasCount++;
	return atlas;
}

TuiAtlas tuiAtlasCreateCoordinateRawPixelsRawUVs(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, float* raw_glyph_uvs, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (pixels == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return TUI_NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return TUI_NULL;
	}
	if (raw_glyph_uvs == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE_COORDINATES, __func__);
		return TUI_NULL;
	}
	if (glyph_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_COUNT, __func__);
		return TUI_NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return TUI_NULL;
	}

	TuiAtlas atlas = tuiAllocate(sizeof(TuiAtlas_s));
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_COORDS;
	atlas->ChannelCount = (size_t)channel_count;
	atlas->PixelWidth = (size_t)pixel_width;
	atlas->PixelHeight = (size_t)pixel_height;
	atlas->TileWidth = 0;
	atlas->TileHeight = 0;
	atlas->PixelDataSize = (size_t)pixel_width * (size_t)pixel_height * (size_t)channel_count;
	atlas->ApiData = TUI_NULL;
	atlas->GlyphCount = (size_t)glyph_count;
	
	TuiErrorCode error_code = tuiAtlasCreate_Opengl33(atlas, pixels, raw_glyph_uvs);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiAtlasDestroy_Opengl33(atlas);
		tuiFree(atlas);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sAtlasCount++;
	return atlas;
}

TuiAtlas tuiAtlasCreateGridImage(TuiImage image, int tile_pixel_width, int tile_pixel_height, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}
	if (image->PixelWidth % tile_pixel_width != 0 && image->PixelHeight % tile_pixel_height != 0 || tile_pixel_width <= 0 || tile_pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return TUI_NULL;
	}

	TuiAtlas atlas = tuiAllocate(sizeof(TuiAtlas_s));
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_GRID;
	atlas->TileWidth = (size_t)tile_pixel_width;
	atlas->TileHeight = (size_t)tile_pixel_height;
	atlas->GridGlyphsWide = image->PixelWidth / tile_pixel_width;
	atlas->GridGlyphsTall = image->PixelHeight / tile_pixel_height;
	atlas->ChannelCount = image->ChannelCount;
	atlas->PixelWidth = image->PixelWidth;
	atlas->PixelHeight = image->PixelHeight;
	atlas->PixelDataSize = atlas->ChannelCount * atlas->PixelWidth * atlas->PixelHeight;
	TuiErrorCode error_code = tuiAtlasCreate_Opengl33(atlas, image->PixelData, TUI_NULL);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiAtlasDestroy_Opengl33(atlas);
		tuiFree(atlas);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sAtlasCount++;
	return atlas;
}

TuiAtlas tuiAtlasCreateGridRawPixels(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int tile_pixel_width, int tile_pixel_height, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (pixels == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return TUI_NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return TUI_NULL;
	}
	if (tile_pixel_width <= 0 || tile_pixel_height <= 0 || pixel_width % tile_pixel_width != 0 || pixel_height % tile_pixel_height != 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return TUI_NULL;
	}

	TuiAtlas atlas = tuiAllocate(sizeof(TuiAtlas_s));
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_GRID;
	atlas->TileWidth = (size_t)tile_pixel_width;
	atlas->TileHeight = (size_t)tile_pixel_height;
	atlas->GridGlyphsWide = (size_t)pixel_width / (size_t)tile_pixel_width;
	atlas->GridGlyphsTall = (size_t)pixel_height / (size_t)tile_pixel_height;
	atlas->ChannelCount = (size_t)channel_count;
	atlas->PixelWidth = (size_t)pixel_width;
	atlas->PixelHeight = (size_t)pixel_height;
	atlas->PixelDataSize = atlas->ChannelCount * atlas->PixelWidth * atlas->PixelHeight;
	TuiErrorCode error_code = tuiAtlasCreate_Opengl33(atlas, pixels, TUI_NULL);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiAtlasDestroy_Opengl33(atlas);
		tuiFree(atlas);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sAtlasCount++;
	return atlas;
}

const size_t kCodepageGlyphCount = 256;
const size_t kCodepageGlyphTileDimensions = 16;

TuiAtlas tuiAtlasCreateCodepageImage(TuiImage image, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}
	if (image->PixelWidth % kCodepageGlyphTileDimensions != 0 || image->PixelHeight % kCodepageGlyphTileDimensions != 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return TUI_NULL;
	}

	TuiAtlas atlas = tuiAllocate(sizeof(TuiAtlas_s));
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_GRID;
	atlas->TileWidth = image->PixelWidth / kCodepageGlyphTileDimensions;
	atlas->TileHeight = image->PixelHeight / kCodepageGlyphTileDimensions;
	atlas->GridGlyphsWide = kCodepageGlyphTileDimensions;
	atlas->GridGlyphsTall = kCodepageGlyphTileDimensions;
	atlas->ChannelCount = image->ChannelCount;
	atlas->PixelWidth = image->PixelWidth;
	atlas->PixelHeight = image->PixelHeight;
	atlas->PixelDataSize = atlas->ChannelCount * atlas->PixelWidth * atlas->PixelHeight;
	atlas->GlyphCount = kCodepageGlyphCount;
	TuiErrorCode error_code = tuiAtlasCreate_Opengl33(atlas, image->PixelData, TUI_NULL);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiAtlasDestroy_Opengl33(atlas);
		tuiFree(atlas);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sAtlasCount++;
	return atlas;
}

TuiAtlas tuiAtlasCreateCodepageRawPixels(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (pixels == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return TUI_NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return TUI_NULL;
	}
	if (pixel_width % kCodepageGlyphTileDimensions != 0 || pixel_height % kCodepageGlyphTileDimensions != 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return TUI_NULL;
	}

	TuiAtlas atlas = tuiAllocate(sizeof(TuiAtlas_s));
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_GRID;
	atlas->TileWidth = (size_t)pixel_width / kCodepageGlyphTileDimensions;
	atlas->TileHeight = (size_t)pixel_height / kCodepageGlyphTileDimensions;
	atlas->GridGlyphsWide = kCodepageGlyphTileDimensions;
	atlas->GridGlyphsTall = kCodepageGlyphTileDimensions;
	atlas->ChannelCount = (size_t)channel_count;
	atlas->PixelWidth = (size_t)pixel_width;
	atlas->PixelHeight = (size_t)pixel_height;
	atlas->PixelDataSize = atlas->ChannelCount * atlas->PixelWidth * atlas->PixelHeight;
	atlas->GlyphCount = kCodepageGlyphCount;
	TuiErrorCode error_code = tuiAtlasCreate_Opengl33(atlas, pixels, TUI_NULL);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiAtlasDestroy_Opengl33(atlas);
		tuiFree(atlas);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sAtlasCount++;
	return atlas;
}

void tuiAtlasDestroy(TuiAtlas atlas)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}
	if (atlas == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return;
	}

	TuiErrorCode error_code = tuiAtlasDestroy_Opengl33(atlas);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiDebugError(error_code, __func__);
		return;
	}
	sAtlasCount--;
	tuiFree(atlas);
}

int tuiGetAtlasCount()
{
	return sAtlasCount;
}

int tuiAtlasGetChannelCount(TuiAtlas atlas)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}
	if (atlas == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return 0;
	}

	return (int)atlas->ChannelCount;
}

int tuiAtlasGetPixelWidth(TuiAtlas atlas)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}
	if (atlas == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return 0;
	}

	return atlas->PixelWidth;
}

int tuiAtlasGetPixelHeight(TuiAtlas atlas)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}
	if (atlas == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return 0;
	}

	return atlas->PixelHeight;
}

void tuiAtlasGetPixelDimensions(TuiAtlas atlas, int* out_pixel_width, int* out_pixel_height, int* out_channel_count)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}
	if (atlas == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return;
	}

	if (out_pixel_width != TUI_NULL)
	{
		*out_pixel_width = (int)atlas->PixelWidth;
	}
	if (out_pixel_height != TUI_NULL)
	{
		*out_pixel_height = (int)atlas->PixelHeight;
	}
	if (out_channel_count != TUI_NULL)
	{
		*out_channel_count = (int)atlas->ChannelCount;
	}
}

TuiBlendMode tuiAtlasGetBlendMode(TuiAtlas atlas)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_BLEND_INVALID;
	}
	if (atlas == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return TUI_BLEND_INVALID;
	}

	return atlas->BlendMode;
}

void tuiAtlasSetBlendMode(TuiAtlas atlas, TuiBlendMode blend_mode)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}
	if (atlas == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return;
	}
	if (tuiBlendIsValid(blend_mode) != TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return;
	}

	atlas->BlendMode = blend_mode;
}

int tuiAtlasGetGlyphCount(TuiAtlas atlas)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}
	if (atlas == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return 0;
	}
	return atlas->GlyphCount;
}

float* tuiGenerateUVCoordinatesFromPixelCooordinates(int glyph_count, uint16_t* pixel_coordinates, int texture_width, int texture_height, float* out_ptr)
{
	size_t glyphBoundingBoxesParameterCount = (size_t)glyph_count * 4; // amount of glyphs times 4 for STPQ coordinates
	float* glyphBoundingBoxesUVCoordinates = out_ptr;
	if (out_ptr == TUI_NULL) //If out_ptr is TUI_NULL, allocate memory that fits the data
	{
		glyphBoundingBoxesUVCoordinates = (float*)tuiAllocate(sizeof(float) * glyphBoundingBoxesParameterCount); 
	}
	for (size_t coord = 0; coord < glyphBoundingBoxesParameterCount; coord++)
	{
		if (coord % 4 < 2) // for coordinates ST (U coordinates of right and left edges)
		{
			glyphBoundingBoxesUVCoordinates[coord] = (float)((float)pixel_coordinates[coord] / (float)texture_width);
		}
		else // for coordinates PQ (V coordinates of top and bottom edges)
		{
			glyphBoundingBoxesUVCoordinates[coord] = (float)((float)pixel_coordinates[coord] / (float)texture_height);
		}
	}
	return glyphBoundingBoxesUVCoordinates;
}