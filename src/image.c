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
#include "image_inline.h"

#include <stb_image.h>
#include <stb_image_write.h>
#include <stb_image_resize.h>

TuiImage tuiImageCreate(int pixel_width, int pixel_height, int channel_count, uint8_t* pixel_data, TuiBoolean copy_data)
{
	return _CreateImage(pixel_width, pixel_height, channel_count, pixel_data, copy_data, __func__);
}

void tuiImageDestroy(TuiImage image)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return;
	}

	tuiFree(image->PixelData);
	tuiFree(image);
}

TuiImage tuiImageLoad(const char* path)
{;
	if (path == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PATH, __func__);
		return TUI_NULL;
	}

	int i_width, i_height, i_channels;
	uint8_t* pixels = stbi_load(path, &i_width, &i_height, &i_channels, 0);
	if (pixels == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_LOAD_IMAGE_FAILURE, __func__);
		return TUI_NULL;
	}
	TuiImage ret = _CreateImage(i_width, i_height, i_channels, pixels, TUI_FALSE, __func__);
	return ret;
}

void tuiImageSave(TuiImage image, const char* path)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return;
	}
	if (path == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PATH, __func__);
		return;
	}

	stbi_write_png(path, image->PixelWidth, image->PixelHeight, image->ChannelCount, image->PixelData, image->PixelWidth * image->ChannelCount);
}

TuiImage tuiImageClone(TuiImage image)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}

	return _CreateImage(image->ChannelCount, image->PixelWidth, image->PixelHeight, image->PixelData, TUI_TRUE, __func__);
}

void tuiImageGetPixelDimensions(TuiImage image, int* width, int* height, int* channel_count)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return;
	}

	if (width != TUI_NULL)
	{
		*width = (int)image->PixelWidth;
	}
	if (height != TUI_NULL)
	{
		*height = (int)image->PixelHeight;
	}
	if (channel_count != TUI_NULL)
	{
		*channel_count = (int)image->ChannelCount;
	}
}

int tuiImageGetPixelWidth(TuiImage image)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return 0;
	}

	return (int)image->PixelWidth;
}

int tuiImageGetPixelHeight(TuiImage image)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return 0;
	}

	return (int)image->PixelHeight;
}

int tuiImageGetChannelCount(TuiImage image)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return 0;
	}

	return (int)image->ChannelCount;
}

uint8_t* tuiImageGetPixels(TuiImage image)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}

	return image->PixelData;
}

size_t tuiImageGetPixelDataSize(TuiImage image)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return 0;
	}

	return image->PixelDataSize;
}

void tuiImageResize(TuiImage image, int new_width, int new_height)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return;
	}
	if (new_width <= 0 || new_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_IMAGE_DIMENSIONS, __func__);
		return;
	}

	size_t new_size = (size_t)new_width * (size_t)new_height * image->ChannelCount;
	uint8_t* new_pixels = _ResizeImageData(image->PixelData, image->PixelWidth, image->PixelHeight, image->ChannelCount, new_width, new_height, TUI_NULL, __func__);
	if (new_pixels == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_RESIZE_IMAGE_FAILURE, __func__);
		return;
	}
	tuiFree(image->PixelData);
	image->PixelWidth = new_width;
	image->PixelHeight = new_height;
	image->PixelData = new_pixels;
}

TuiImage tuiImageCloneResize(TuiImage image, int new_width, int new_height)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}
	if (new_width <= 0 || new_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_IMAGE_DIMENSIONS, __func__);
		return TUI_NULL;
	}

	size_t new_size = (size_t)new_width * (size_t)new_height * image->ChannelCount;
	uint8_t* new_pixels = _ResizeImageData(image->PixelData, image->PixelWidth, image->PixelHeight, image->ChannelCount, new_width, new_height, TUI_NULL, __func__);
	if (new_pixels == TUI_NULL)
	{
		return TUI_NULL;
	}
	return _CreateImage(image->ChannelCount, new_width, new_height, new_pixels, TUI_TRUE, __func__);
}

void tuiImageEmplace(TuiImage image, TuiImage target_image, int start_x, int start_y)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return;
	}
	if (target_image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TARGET_IMAGE, __func__);
		return;
	}
	if (image->ChannelCount != target_image->ChannelCount)
	{
		tuiDebugError(TUI_ERROR_INCOMPATIBLE_IMAGES, __func__);
		return;
	}

	size_t sx = 0; // obviously, this is subject to testing...
	size_t sy = 0;
	if (start_x > 0) //clip start x
	{
		sx = (size_t)start_x;
	}
	if (start_y > 0) //clip start y
	{
		sy = (size_t)start_y;
	}
	size_t ex = (size_t)(start_x + image->PixelWidth);
	size_t ey = (size_t)(start_y + image->PixelHeight);
	if (ex > target_image->PixelWidth) //clip end x
	{
		ex = target_image->PixelWidth;
	}
	if (ey > target_image->PixelHeight) //clip end y
	{
		ey = target_image->PixelHeight;
	}
	for (size_t t_x = sx, x = 0; t_x < ex; t_x++, x++)
	{
		for (size_t t_y = sy, y = 0; t_y < ey; t_y++, y++)
		{
			for (int c = 0; c < image->ChannelCount; c++)
			{
				target_image->PixelData[((target_image->PixelWidth * t_y + t_x) * target_image->ChannelCount) + c] =
					image->PixelData[((image->PixelWidth * y + x) * image->ChannelCount) + c];
			}
		}
	}
}