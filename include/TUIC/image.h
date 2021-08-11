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


/*! @name Image Functions
 *
 * These functions are used for manipulating @ref TuiImage opaque objects.
 *
 *  @{ */
/*!
 * @brief Create a @ref TuiImage with a raw pixel array.
 *
 * @param texture_format The format of the image (its channel count).
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param pixel_data The pixel data array.
 * @param copy_data If the pixel data should be deeply copied instead of shallow coppied.
 * 
 * @returns The created @ref TuiImage. @ref TUI_NULL is returned if an error occurs.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_INVALID_CHANNEL_COUNT and @ref TUI_ERROR_INVALID_IMAGE_DIMENSIONS. The first error that occurs will cause the function to immediatly return. Also, an inccorectly sized or allocated pixels array may cause undefined behaviour or a fatal crash without an error.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 * 
 * @pointer_lifetime The returned @ref TuiImage must be destroyed using the function @ref tuiImageDestroy().
 * 
 * @thread_safety This function can be called safely on any thread at any time.
 */
TuiImage tuiImageCreatePixels(int pixel_width, int pixel_height, int channel_count, uint8_t* pixel_data, TuiBoolean copy_data);
/*!
 * @brief Load a @ref TuiImage from a png image file in secondary storage.
 *
 * @param path The local or full path to the image file.
 *
 * @returns The loaded @ref TuiImage. @ref TUI_NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_PATH and @ref TUI_ERROR_LOAD_IMAGE_FAILURE.  The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
TuiImage tuiImageCreatePixelsPNG(const char* path);
/*!
 * @brief Create a @ref TuiImage filled with pixels of a solid color.
 *
 * @param pixel_width The width of the image in pixels.
 * @param pixel_height The height of the image in pixels.
 * @param channel_count The amount of channels in the image.
 * @param r The red color channel of the solid fill color.
 * @param g The green color channel of the solid fill color.
 * @paran b The blue color channel of the solid fill color.
 * @param a The alpha color channel of the solid fill color. If the image has only 3 channels, this is ignored.
 *
 * @returns The loaded @ref TuiImage. @ref TUI_NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_INVALID_CHANNEL_COUNT and @ref TUI_ERROR_INVALID_IMAGE_DIMENSIONS. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
TuiImage tuiImageCreatePixelsColor(int pixel_width, int pixel_height, int channel_count, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
/*!
 * @brief  Destroy @ref TuiImage and correctly dispose of all of its resources.
 *
 * @param image The @ref TuiImage object to destroy.
 * 
 * @errors Can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return. 
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
void tuiImageDestroy(TuiImage image);
/*!
 * @brief Save a @ref TuiImage as a png image file.
 *
 * @param image The @ref TuiImage.
 * @param path The local or full path where the file will be saved, including the file name and extension.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_IMAGE and @ref TUI_ERROR_NULL_PATH.  The first error that occurs will cause the function to immediatly return. 
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
void tuiImageSave(TuiImage image, const char* path);
/*!
 * @brief Create a deep copy of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 * 
 * @returns The cloned @ref TuiImage. @ref TUI_NULL is returned if an error occurs.
 * 
 * @errors This function can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return. 
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
TuiImage tuiImageClone(TuiImage image);
/*!
 * @brief Get the pixel dimensions of a @ref TuiImage.
 * 
 * @param image The @ref TuiImage to get the pixel dimensions of.
 * @param pixel_width A pointer to where the pixel width of the @ref TuiImage will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 * @param pixel_height A pointer to where the pixel height of the @ref TuiImage will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 * @param channel_count A pointer to where the channel count of the @ref TuiImage will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 * 
 * @errors This function can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
void tuiImageGetPixelDimensions(TuiImage image, int* pixel_width, int* pixel_height, int* channel_count);
/*!
 * @brief Get the pixel width of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 * 
 * @returns The pixel width. 0 is returned if an error occurs
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
int tuiImageGetPixelWidth(TuiImage image);
/*!
 * @brief Get the pixel height of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns The pixel height. 0 is returned if an error occurs.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
int tuiImageGetPixelHeight(TuiImage image);
/*!
 * @brief Get the channel count of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns The channel count. 0 is returned if an error occurs.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
int tuiImageGetChannelCount(TuiImage image);
/*!
 * @brief Get a pointer to the raw pixels of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns A pointer to the pixel array of the image.
 * 
 * @errors This function can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 * 
 * @pointer_lifetime The returned pixel array should never be freed, and will be destroyed when the image it was taken from is destroyed. Modifying the contents of the array will affect the image, and is not thread safe with other @ref TuiImage functions on the same object.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
uint8_t* tuiImageGetPixels(TuiImage image);
/*!
 * @brief  Get the size of the pixel data array of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 *
 * @returns The size of the pixel array of the image in bytes. @ref TUI_NULL is returned on error.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
size_t tuiImageGetPixelDataSize(TuiImage image);
/*!
 * @brief Resize a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 * @param new_width The new width to set for the @ref TuiImage.
 * @param new_height The new height ot set for the @ref TuiImage.
 * 
 * @errors This function can have the error @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
void tuiImageResize(TuiImage image, int new_pixel_width, int new_pixel_height);
/*!
 * @brief Create a resized deep copy of a @ref TuiImage.
 *
 * @param image The @ref TuiImage.
 * @param new_width The new width to set for the @ref TuiImage clone.
 * @param new_height The new height ot set for the @ref TuiImage clone.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_IMAGE, @ref TUI_ERROR_INVALID_IMAGE_DIMENSIONS, and @ref TUI_ERROR_RESIZE_IMAGE_FAILURE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
TuiImage tuiImageCloneResize(TuiImage image, int new_pixel_width, int new_pixel_height);
/*!
 * @brief Emplace a @ref TuiImage inside of another image, starting from a specific pixel position. Pixels that go out of bounds are clipped.
 *
 * @param image The @ref TuiImage to emplace.
 * @param target_image The @ref TuiImage to emplace into.
 * @param start_x The left most x pixel coordinate from where the image will be emplaced.
 * @param start_y The top most y pixel coordinate from where the image will be emplaced.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_IMAGE, @ref TUI_ERROR_NULL_TARGET_IMAGE, and @ref TUI_ERROR_INCOMPATIBLE_IMAGES. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiImage on only one thread at a time to ensure safe memory access.
 */
void tuiImageEmplace(TuiImage image, TuiImage target_image, int start_x, int start_y);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard