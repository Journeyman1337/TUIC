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
#ifndef TUIC_IMAGE_H //header guard
#define TUIC_IMAGE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>

/*! @name TuiImage functions
 *
 * These functions are used for manipulating @ref TuiImage opaque objects.
 *
 *  @{ */
/*!
 * @brief  Destroy @ref TuiImage and correctly dispose of all of its resources.
 *
 * @param texture_format The format of the image (its channel count).
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param pixel_data The pixel data array.
 * @param copy_data If the pixel data should be copied.
 * 
 * @returns The created @ref TuiImage object. Null is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT when channel_count is not 3 or 4.
 * Throws @ref TUI_ERROR_INVALID_IMAGE_DIMENSIONS when pixel_width or pixel_height is less than or equal to 0.
 */
TuiImage tuiImageCreate(int pixel_width, int pixel_height, int channel_count, uint8_t* pixel_data, TuiBoolean copy_data);
/*!
 * @brief  Destroy @ref TuiImage and correctly dispose of all of its resources.
 *
 * @param image The @ref TuiImage object to destroy.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 */
void tuiImageDestroy(TuiImage image);
/*!
 * @brief Load a @ref TuiImage from an image file.
 *
 * @param path The path to the file.
 * @param expected_channel_count The expected image channel count. If 0, none is expected.
 * 
 * @return The @ref TuiImage. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PATH if path is NULL.
 * Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT if expected_channel_count is not 0, 3, or 4.
 * Throws @ref TUI_ERROR_LOAD_IMAGE_FAILURE if image fails to load from the file.
 * Throws @ref TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS if expected_channel_count is not 0 and does not match the loaded image channel count.
 */
TuiImage tuiImageLoad(const char* path, int expected_channel_count);
/*!
 * @brief  Save a @ref TuiImage to an image file.
 *
 * @param image The @ref TuiImage.
 * @param path The path to the file.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_NULL_PATH if path is NULL.
 */
void tuiImageSave(TuiImage image, const char* path);
/*!
 * @brief  Create a deep copy of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns The cloned @ref TuiImage object. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 */
TuiImage tuiImageClone(TuiImage image);

void tuiImageGetPixelDimensions(TuiImage image, int* pixel_width, int* pixel_height, int* channel_count);
/*!
 * @brief  Get the pixel width of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 * 
 * @returns The pixel width. 0 is returned on error.
 *
 * @errors Throws @TUI_ERROR_NULL_IMAGE if image is NULL.
 */
int tuiImageGetPixelWidth(TuiImage image);
/*!
 * @brief  Get the pixel height of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns The pixel height. 0 is returned on error.
 *
 * @errors Throws @TUI_ERROR_NULL_IMAGE if image is NULL.
 */
int tuiImageGetPixelHeight(TuiImage image);
/*!
 * @brief  Get the channel count of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns The channel count. 0 is returned on error.
 *
 * @errors Throws @TUI_ERROR_NULL_IMAGE if image is NULL.
 */
int tuiImageGetChannelCount(TuiImage image);
/*!
 * @brief  Get a pointer to the raw pixels of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns The raw pixel pointer.
 */
uint8_t* tuiImageGetPixels(TuiImage image);
/*!
 * @brief  Get the size of the pixel data array of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns The size. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 */
size_t tuiImageGetPixelDataSize(TuiImage image);
/*!
 * @brief  Resized a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 * @param new_width The new width to set for the @ref TuiImage.
 * @param new_height The new height ot set for the @ref TuiImage.
 */
void tuiImageResize(TuiImage image, int new_pixel_width, int new_pixel_height);
/*!
 * @brief  Create a resized deep copy of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 * @param new_width The new width to set for the @ref TuiImage clone.
 * @param new_height The new height ot set for the @ref TuiImage clone.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_INVALID_IMAGE_DIMENSIONS if new_width or new_height is less than or equal to 0.
 */
TuiImage tuiImageCloneResize(TuiImage image, int new_pixel_width, int new_pixel_height);
/*!
 * @brief  Emplace a image inside of another image.
 *
 * @param image The @ref TuiImage to emplace.
 * @param target_image The @ref TuiImage to emplace into.
 * @param start_x The left most x pixel coordinate from where the image will be emplaced.
 * @param start_y The top most y pixel coordinate from where the image will be emplaced.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_NULL_TARGET_IMAGE if target_image is null.
 * Throws @ref TUI_ERROR_INCOMPATIBLE_IMAGES of image and target_image have unmatching channel counts.
 */
void tuiImageEmplace(TuiImage image, TuiImage target_image, int start_x, int start_y);
/*! @} */
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard