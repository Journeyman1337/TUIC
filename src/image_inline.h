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
#ifdef __cplusplus //extern C guard
#include <TUIC/types.h>
extern "C" {
#endif

inline TuiImage create_image(int pixel_width, int pixel_height, int channel_count, uint8_t* pixel_data, int copy_data, const char* func_name)
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
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard