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

static int sTextureCount = 0;

TuiTexture tuiTextureCreateImage(TuiImage image, TuiFilterMode filter_mode)
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
	if (tuiFilterModeIsValid(filter_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_FILTER_MODE, __func__);
		return TUI_NULL;
	}

	TuiTexture texture = tuiAllocate(sizeof(TuiTexture_s));
	texture->FilterMode = filter_mode;
	texture->PixelWidth = image->PixelWidth;
	texture->PixelHeight = image->PixelHeight;
	texture->ChannelCount = image->ChannelCount;
	tuiTextureCreate_Opengl33(texture, image->PixelData);
	sTextureCount++;
	return texture;
}

TuiTexture tuiTextureCreateRawPixels(int pixel_width, int pixel_height, int channel_count, const uint8_t* pixels, int filter_mode)
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
	if (tuiFilterModeIsValid(filter_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_FILTER_MODE, __func__);
		return TUI_NULL;
	}

	TuiTexture texture = tuiAllocate(sizeof(TuiTexture_s));
	texture->FilterMode = filter_mode;
	texture->PixelWidth = pixel_width;
	texture->PixelHeight = pixel_height;
	texture->ChannelCount = channel_count;
	tuiTextureCreate_Opengl33(texture, pixels);
	sTextureCount++;
	return texture;
}

void tuiTextureDestroy(TuiTexture texture)
{
	if (texture == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}

	tuiTextureDestroy_Opengl33(texture);
	tuiFree(texture);
	sTextureCount--;
}

int tuiGetTextureCount()
{
	return sTextureCount;
}

void tuiTextureGetPixelDimensions(TuiTexture texture, int* pixel_width, int* pixel_height)
{
	if (texture == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}

	if (pixel_width != TUI_NULL)
	{
		*pixel_width = (int)texture->PixelWidth;
	}
	if (pixel_height != TUI_NULL)
	{
		*pixel_height = (int)texture->PixelHeight;
	}
}

int tuiTextureGetPixelWidth(TuiTexture texture)
{
	if (texture == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return 0;
	}

	return texture->PixelWidth;
}

int tuiTextureGetPixelHeight(TuiTexture texture)
{
	if (texture == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return 0;
	}

	return texture->PixelHeight;
}

int tuiTextureGetChannelCount(TuiTexture texture)
{
	if (texture == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return 0;
	}

	return texture->ChannelCount;
}

TuiFilterMode tuiTextureGetFilterMode(TuiTexture texture)
{
	if (texture == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return 0;
	}

	return texture->FilterMode;
}

void tuiTextureSetImage(TuiTexture texture, TuiImage image)
{
	if (texture == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return;
	}

	texture->PixelWidth = image->PixelWidth;
	texture->PixelHeight = image->PixelHeight;
	texture->ChannelCount = image->ChannelCount;
	tuiTextureSetPixels_Opengl33(texture, image->PixelData);
}

void tuiTextureSetPixels(TuiTexture texture, int pixel_width, int pixel_height, int channel_count, const uint8_t* pixels)
{
	if (texture == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}
	if (pixels == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PIXELS, __func__);
		return;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PIXEL_DIMENSIONS, __func__);
		return;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return;
	}

	texture->PixelWidth = pixel_width;
	texture->PixelHeight = pixel_height;
	texture->ChannelCount = channel_count;
	tuiTextureSetPixels_Opengl33(texture, pixels);
}
