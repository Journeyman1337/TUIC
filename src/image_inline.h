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
#ifndef TUIC_IMAGE_INLINE_H //header guard
#define TUIC_IMAGE_INLINE_H
#include <TUIC/types.h>
#include <string.h>
#include <GLFW/glfw3.h>
#include "objects.h"
#include <TUIC/debug.h>
#include <TUIC/boolean.h>

static inline TuiImage _CreateImage(int pixel_width, int pixel_height, int channel_count, uint8_t* pixel_data, TuiBoolean copy_data, const char* func_name)
{
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, func_name);
		return NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_IMAGE_DIMENSIONS, func_name);
		return NULL;
	}

	TuiImage image = tuiAllocate(sizeof(TuiImage_s));
	image->PixelWidth = pixel_width;
	image->PixelHeight = pixel_height;
	image->ChannelCount = channel_count;
	image->PixelDataSize = (size_t)pixel_width * (size_t)pixel_height * (size_t)channel_count;

	if (pixel_data != NULL)
	{
		if (copy_data == TUI_TRUE)
		{
			image->PixelData = tuiAllocate(image->PixelDataSize);
			memcpy(image->PixelData, pixel_data, image->PixelDataSize);
		}
		else
		{
			image->PixelData = pixel_data;
		}
	}
	else
	{
		image->PixelData = tuiAllocate(image->PixelDataSize);
		memset(image->PixelData, 0, image->PixelDataSize);
	}
	return image;
}

static inline uint8_t* _ResizeImageData(const uint8_t* pixels, int pixel_width, int pixel_height, int channel_count, int new_pixel_width, int new_pixel_height, const char* func_name)
{
	uint8_t* output_pixels = tuiAllocate((size_t)(new_pixel_width * new_pixel_height * channel_count));
	int stb_result = stbir_resize_uint8(pixels, pixel_width, pixel_height, 0,
		output_pixels, new_pixel_width, new_pixel_height, 0,
		channel_count);
	if (stb_result == 0)
	{
		tuiFree(output_pixels);
		tuiDebugError(TUI_ERROR_RESIZE_IMAGE_FAILURE, func_name);
		return NULL;
	}
	return output_pixels;
}

static inline GLFWimage _TuiImageToGlfwImage(TuiImage image, const char* func_name)
{
	GLFWimage glfw_image;
	glfw_image.width = 0;
	glfw_image.height = 0;
	glfw_image.pixels = NULL;
	if (image->ChannelCount != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, func_name);
		return glfw_image;
	}
	glfw_image.width = image->PixelWidth;
	glfw_image.height = image->PixelHeight;
	glfw_image.pixels = image->PixelData;
	return glfw_image;
}

static inline TuiImage _GlfwImageToTuiImage(GLFWimage image, const char* func_name)
{
	return create_image(image.width, image.height, 4, image.pixels, TUI_TRUE, func_name);
}
#endif //header guard