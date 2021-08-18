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

#include <stb_image_resize.h>

TuiImage tuiImageCreatePixels(int pixel_width, int pixel_height, int channel_count, uint8_t* pixel_data, TuiBoolean copy_data)
{
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return TUI_NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_IMAGE_DIMENSIONS, __func__);
		return TUI_NULL;
	}

	return _CreateImage(pixel_width, pixel_height, channel_count, pixel_data, copy_data);
}

TuiImage tuiImageCreatePNG(const char* path)
{
	if (path == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PATH, __func__);
		return TUI_NULL;
	}

	int width = 0, height = 0, channels = 0;
	uint8_t* pixels = TUI_NULL;
	_LoadPixelsPNG(path, &width, &height, &channels, &pixels);
	TuiImage ret = _CreateImage(width, height, channels, pixels, TUI_FALSE);
	return ret;
}

TuiImage tuiImageCreateColor(int pixel_width, int pixel_height, int channel_count, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return TUI_NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_IMAGE_DIMENSIONS, __func__);
		return TUI_NULL;
	}

	uint8_t* pixels = (uint8_t*)tuiAllocate((size_t)pixel_width * (size_t)pixel_height * (size_t)channel_count);

	for (size_t pixel_y = 0; pixel_y < (size_t)pixel_height; pixel_y++)
	{
		for (size_t pixel_x = 0; pixel_x < (size_t)pixel_width; pixel_x++)
		{
			size_t pixel_i = (pixel_y * (size_t)pixel_width + pixel_x) * (size_t)channel_count;
			pixels[pixel_i++] = r;
			pixels[pixel_i++] = g;
			pixels[pixel_i] = b;
			if (channel_count == 4)
			{
				pixels[++pixel_i] = a;
			}
		}
	}

	TuiImage ret = _CreateImage(pixel_width, pixel_height, channel_count, pixels, TUI_FALSE);
	return ret;
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

void tuiImageSavePNG(TuiImage image, const char* path)
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

	FILE* fp = fopen(path, "wb");
	if (!fp)
	{
		// tuiDebugError(TUI_ERROR_INVALID_FILE_PATH, __func__);
		return TUI_NULL;
	}
	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		// tuiDebugError(TUI_ERROR_INVALID_PNG_FILE, __func__);
		return TUI_NULL;
	}
	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		// tuiDebugError(TUI_ERROR_INVALID_PNG_FILE, __func__);
		return TUI_NULL;
	}
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		// tuiDebugError(TUI_ERROR_INVALID_PNG_FILE, __func__);
		return TUI_NULL;
	}
	png_init_io(png_ptr, fp);
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		// tuiDebugError(TUI_ERROR_INVALID_PNG_FILE, __func__);
		return TUI_NULL;
	}
	png_byte color_type = (image->ChannelCount == 3) ? 2 : 6;
	png_set_IHDR(png_ptr, info_ptr, image->PixelWidth, image->PixelHeight, 8, color_type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
	png_write_info(png_ptr, info_ptr);
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		// tuiDebugError(TUI_ERROR_INVALID_PNG_FILE, __func__);
		return TUI_NULL;
	}
	png_bytep* row_pointers = (png_bytep*)tuiAllocate(sizeof(png_bytep) * image->PixelHeight);
	for (size_t y = 0; y < image->PixelHeight; y++)
		row_pointers[y] = &image->PixelData[y * image->PixelWidth * image->ChannelCount];
	png_write_image(png_ptr, row_pointers);
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		// tuiDebugError(TUI_ERROR_INVALID_PNG_FILE, __func__);
		return TUI_NULL;
	}
	png_write_end(png_ptr, NULL);
	tuiFree(row_pointers);
	fclose(fp);
}

TuiImage tuiImageClone(TuiImage image)
{
	if (image == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return TUI_NULL;
	}

	return _CreateImage(image->ChannelCount, image->PixelWidth, image->PixelHeight, image->PixelData, TUI_TRUE);
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
	return _CreateImage(image->ChannelCount, new_width, new_height, new_pixels, TUI_TRUE);
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