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

TuiGlyphAtlas tuiGlyphAtlasCreate(TuiInstance instance, TuiImage image, int glyph_count, uint16_t* glyph_bounding_boxes, TuiBlendMode blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	if (image == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}
	if (glyph_bounding_boxes == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES, __func__);
		return NULL;
	}
	if (glyph_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_COUNT, __func__);
		return NULL;
	}

	TuiGlyphAtlas atlas = tuiAllocate(sizeof(TuiGlyphAtlas_s));
	atlas->Instance = instance;
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_COORDS;
	atlas->ChannelCount = image->ChannelCount;
	atlas->PixelWidth = image->PixelWidth;
	atlas->PixelHeight = image->PixelHeight;
	atlas->TileWidth = 0;
	atlas->TileHeight = 0;
	atlas->PixelDataSize = image->PixelDataSize;
	atlas->ApiData = NULL;
	atlas->GlyphCount = (size_t)glyph_count;
	
	float* raw_glyph_uvs = tuiGenerateUVCoordinatesFromPixelCooordinates(glyph_count, glyph_bounding_boxes, image->PixelWidth, image->PixelHeight, NULL);
	tuiGlyphAtlasCreate_Opengl33(atlas, image->PixelData, raw_glyph_uvs);
	atlas->Instance->GlyphAtlasCount++;
	tuiFree(raw_glyph_uvs);
	return atlas;
}

TuiGlyphAtlas tuiGlyphAtlasCreateRawPixels(TuiInstance instance, int pixel_width , int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, uint16_t* glyph_bounding_boxes, TuiBlendMode blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	if (pixels == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return NULL;
	}
	if (glyph_bounding_boxes == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES, __func__);
		return NULL;
	}
	if (glyph_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_COUNT, __func__);
		return NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}

	TuiGlyphAtlas atlas = tuiAllocate(sizeof(TuiGlyphAtlas_s));
	atlas->Instance = instance;
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_COORDS;
	atlas->ChannelCount = (size_t)channel_count;
	atlas->PixelWidth = (size_t)pixel_width;
	atlas->PixelHeight = (size_t)pixel_height;
	atlas->TileWidth = 0;
	atlas->TileHeight = 0;
	atlas->PixelDataSize = (size_t)pixel_width * (size_t)pixel_height * (size_t)channel_count;
	atlas->ApiData = NULL;
	atlas->GlyphCount = glyph_count;
	
	float* raw_glyph_uvs = tuiGenerateUVCoordinatesFromPixelCooordinates(glyph_count, glyph_bounding_boxes, pixel_width, pixel_height, NULL);
	tuiGlyphAtlasCreate_Opengl33(atlas, pixels, raw_glyph_uvs);
	atlas->Instance->GlyphAtlasCount++;
	tuiFree(raw_glyph_uvs);
	return atlas;
}

TuiGlyphAtlas tuiGlyphAtlasCreateRawUVs(TuiInstance instance, TuiImage image, int glyph_count, float* raw_glyph_uvs, TuiBlendMode blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	if (image == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return NULL;
	}
	if (raw_glyph_uvs == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE_COORDINATES, __func__);
		return NULL;
	}
	if (glyph_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_COUNT, __func__);
		return NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}

	TuiGlyphAtlas atlas = tuiAllocate(sizeof(TuiGlyphAtlas_s));
	atlas->Instance = instance;
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_COORDS;
	atlas->ChannelCount = image->ChannelCount;
	atlas->PixelWidth = image->PixelWidth;
	atlas->PixelHeight = image->PixelHeight;
	atlas->TileWidth = 0;
	atlas->TileHeight = 0;
	atlas->PixelDataSize = image->PixelDataSize;
	atlas->ApiData = NULL;
	atlas->GlyphCount = (size_t)glyph_count;
	
	tuiGlyphAtlasCreate_Opengl33(atlas, image->PixelData, raw_glyph_uvs);
	atlas->Instance->GlyphAtlasCount++;
	return atlas;
}

TuiGlyphAtlas tuiGlyphAtlasCreateRawPixelsRawUVs(TuiInstance instance, int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, float* raw_glyph_uvs, TuiBlendMode blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	if (pixels == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return NULL;
	}
	if (raw_glyph_uvs == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE_COORDINATES, __func__);
		return NULL;
	}
	if (glyph_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_COUNT, __func__);
		return NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}

	TuiGlyphAtlas atlas = tuiAllocate(sizeof(TuiGlyphAtlas_s));
	atlas->Instance = instance;
	atlas->BlendMode = blend_mode;
	atlas->AtlasType = TUI_ATLAS_COORDS;
	atlas->ChannelCount = (size_t)channel_count;
	atlas->PixelWidth = (size_t)pixel_width;
	atlas->PixelHeight = (size_t)pixel_height;
	atlas->TileWidth = 0;
	atlas->TileHeight = 0;
	atlas->PixelDataSize = (size_t)pixel_width * (size_t)pixel_height * (size_t)channel_count;
	atlas->ApiData = NULL;
	atlas->GlyphCount = (size_t)glyph_count;
	
	tuiGlyphAtlasCreate_Opengl33(atlas, pixels, raw_glyph_uvs);
	atlas->Instance->GlyphAtlasCount++;
	return atlas;
}

TuiGlyphAtlas tuiGlyphAtlasCreateGrid(TuiInstance instance, TuiImage image, int tile_pixel_width, int tile_pixel_height, TuiBlendMode blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	if (image == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return NULL;
	}
	if (image->PixelWidth % tile_pixel_width != 0 && image->PixelHeight % tile_pixel_height != 0 || tile_pixel_width <= 0 || tile_pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_DIMENSIONS, __func__);
		return NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}

	TuiGlyphAtlas atlas = tuiAllocate(sizeof(TuiGlyphAtlas_s));
	atlas->Instance = instance;
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
	tuiGlyphAtlasCreate_Opengl33(atlas, image->PixelData, NULL);
	atlas->Instance->GlyphAtlasCount++;
	return atlas;
}

TuiGlyphAtlas tuiGlyphAtlasCreateGridRawPixels(TuiInstance instance, int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int tile_pixel_width, int tile_pixel_height, TuiBlendMode blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	if (pixels == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return NULL;
	}
	if (tile_pixel_width <= 0 || tile_pixel_height <= 0 || pixel_width % tile_pixel_width != 0 || pixel_height % tile_pixel_height != 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_GLYPH_DIMENSIONS, __func__);
		return NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}

	TuiGlyphAtlas atlas = tuiAllocate(sizeof(TuiGlyphAtlas_s));
	atlas->Instance = instance;
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
	tuiGlyphAtlasCreate_Opengl33(atlas, pixels, NULL);
	atlas->Instance->GlyphAtlasCount++;
	return atlas;
}

const size_t kCodepageGlyphCount = 256;
const size_t kCodepageGlyphTileDimensions = 16;

TuiGlyphAtlas tuiGlyphAtlasCreateCodepageGrid(TuiInstance instance, TuiImage image, TuiBlendMode blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	if (image == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return NULL;
	}
	if (image->PixelWidth % kCodepageGlyphTileDimensions != 0 || image->PixelHeight % kCodepageGlyphTileDimensions != 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS, __func__);
		return NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}

	TuiGlyphAtlas atlas = tuiAllocate(sizeof(TuiGlyphAtlas_s));
	atlas->Instance = instance;
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
	tuiGlyphAtlasCreate_Opengl33(atlas, image->PixelData, NULL);
	atlas->Instance->GlyphAtlasCount++;
	return atlas;
}

TuiGlyphAtlas tuiGlyphAtlasCreateCodepageGridRawPixels(TuiInstance instance, int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, TuiBlendMode blend_mode)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	if (pixels == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return NULL;
	}
	if (pixel_width % kCodepageGlyphTileDimensions != 0 || pixel_height % kCodepageGlyphTileDimensions != 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS, __func__);
		return NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return NULL;
	}
	if (tuiBlendIsValid(blend_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return NULL;
	}

	TuiGlyphAtlas atlas = tuiAllocate(sizeof(TuiGlyphAtlas_s));
	atlas->Instance = instance;
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
	tuiGlyphAtlasCreate_Opengl33(atlas, pixels, NULL);
	atlas->Instance->GlyphAtlasCount++;
	return atlas;
}

void tuiGlyphAtlasDestroy(TuiGlyphAtlas atlas)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return;
	}

	tuiGlyphAtlasDestroy_Opengl33(atlas);
	atlas->Instance->GlyphAtlasCount--;
	tuiFree(atlas);
}

TuiInstance tuiGlyphAtlasGetInstance(TuiGlyphAtlas atlas)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return NULL;
	}

	return atlas->Instance;
}

int tuiGlyphAtlasGetChannelCount(TuiGlyphAtlas atlas)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return 0;
	}

	return (int)atlas->ChannelCount;
}

int tuiGlyphAtlasGetPixelWidth(TuiGlyphAtlas atlas)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return 0;
	}

	return atlas->PixelWidth;
}

int tuiGlyphAtlasGetPixelHeight(TuiGlyphAtlas atlas)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return 0;
	}

	return atlas->PixelHeight;
}

void tuiGlyphAtlasGetPixelDimensions(TuiGlyphAtlas atlas, int* out_pixel_width, int* out_pixel_height)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return;
	}
	if (out_pixel_width != NULL)
	{
		*out_pixel_width = (int)atlas->PixelWidth;
	}
	
	if (out_pixel_height != NULL)
	{
		*out_pixel_height = (int)atlas->PixelHeight;
	}
}

TuiBlendMode tuiGlyphAtlasGetBlendMode(TuiGlyphAtlas atlas)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return 0;
	}
	return atlas->BlendMode;
}

void tuiGlyphAtlasSetBlendMode(TuiGlyphAtlas atlas, TuiBlendMode blend_mode)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return;
	}
	if (atlas->Instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (tuiBlendIsValid(blend_mode) != TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BLEND_MODE, __func__);
		return;
	}
	atlas->BlendMode = blend_mode;
}

int tuiGlyphAtlasGetGlyphCount(TuiGlyphAtlas atlas)
{
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return 0;
	}
	return atlas->GlyphCount;
}

float* tuiGenerateUVCoordinatesFromPixelCooordinates(int glyph_count, uint16_t* pixel_coordinates, int texture_width, int texture_height, float* out_ptr)
{
	size_t glyphBoundingBoxesParameterCount = (size_t)glyph_count * 4;
	float* glyphBoundingBoxesUVCoordinates = out_ptr;
	if (out_ptr == NULL)
	{
		glyphBoundingBoxesUVCoordinates = (float*)tuiAllocate(sizeof(float) * glyphBoundingBoxesParameterCount);
	}
	for (size_t coord = 0; coord < glyphBoundingBoxesParameterCount; coord++)
	{
		if (coord % 4 < 2)
		{
			glyphBoundingBoxesUVCoordinates[coord] = (float)((float)pixel_coordinates[coord] / (float)texture_width);
		}
		else
		{
			glyphBoundingBoxesUVCoordinates[coord] = (float)((float)pixel_coordinates[coord] / (float)texture_height);
		}
	}
	return glyphBoundingBoxesUVCoordinates;
}