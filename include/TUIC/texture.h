/*! \file texture.h
 */
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
#ifndef TUIC_TEXTURE_H //header guard
#define TUIC_TEXTURE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>


/*! @name Texture Functions
 *
 * Functions for manipulating @ref TuiTexture opaque objects.
 *  @{ */
/*!
 * @brief Create a @ref TuiTexture from a @TuiImage.
 *
 * @param image The @ref TuiImage to use ffor the texture.
 * @param filter_mode The @ref TuiFilterMode to use when rendering the texture.
 * 
 * @returns The created @ref TuiTexture. @ref TUI_NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, @ref TUI_ERROR_NULL_PIXELS, @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS, @ref TUI_ERROR_INVALID_CHANNEL_COUNT, and @ref TUI_ERROR_INVALID_FILTER_MODE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned @ref TuiTexture must be destroyed before TUIC is terminated, using the function @ref tuiTextureDestroy().
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
TuiTexture tuiTextureCreateImage(TuiImage image, TuiFilterMode filter_mode);
/*!
 * @brief Create a @ref TuiTexture from a pixel array.
 *
 * @param pixel_width The pixel width of the pixel array.
 * @param pixel_height The pixel height of the pixel array.
 * @param channel_count The channel count of the pixel array.
 * @param A pointer to the pixel array.
 * @param filter_mode The @ref TuiFilterMode to use when rendering the texture.
 * 
 * @returns The created @ref TuiTexture. @ref TUI_NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, @ref TUI_ERROR_NULL_PIXELS, @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS, @ref TUI_ERROR_INVALID_CHANNEL_COUNT, and @ref TUI_ERROR_INVALID_FILTER_MODE. The first error that occurs will cause the function to immediatly return. Also, an inccorectly sized or pixels array may cause undefined behaviour or a fatal crash without an error.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned @ref TuiTexture must be destroyed before TUIC is terminated, using the function @ref tuiTextureDestroy().
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
TuiTexture tuiTextureCreateRawPixels(int pixel_width, int pixel_height, int channel_count, const uint8_t* pixels, int filter_mode);
/*!
 * @brief Free a @ref TuiTexture and correctly dispose of of its internally managed resources.
 *
 * @param texture The @ref TuiTexture to destroy.
 * 
 * @returns The created @ref TuiTexture. @ref TUI_NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_TEXTURE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
void tuiTextureDestroy(TuiTexture texture);
/*!
 * @brief Get the amount of @ref TuiTexture that currently exist.
 *
 * @returns The amount of textures that currently exist.
 *
 * @errors This function does not have errors.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiGetTextureCount();
/*!
 * @brief Get the pixel dimensions of a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 * @param pixel_width A pointer to where the pixel width of the texture will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 * @param pixel_height A pointer to where the pixel height of the texture will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_TEXTURE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
void tuiTextureGetPixelDimensions(TuiTexture texture, int* pixel_width, int* pixel_height);
/*!
 * @brief Get the pixel width of a @ref TuiTexture.
 * 
 * @param texture The @ref TuiTexture.
 *
 * @return The pixel width of the texture.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_TEXTURE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiTextureGetPixelWidth(TuiTexture texture);
/*!
 * @brief Get the pixel height of a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 *
 * @return The pixel height of the texture.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_TEXTURE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiTextureGetPixelHeight(TuiTexture texture);
/*!
 * @brief Get the channel count of a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_TEXTURE. The first error that occurs will cause the function to immediatly return.
 *
 * @return The pixel height of the texture.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiTextureGetChannelCount(TuiTexture texture);
/*!
 * @brief Get the @ref TuiFilterMode of a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_TEXTURE. The first error that occurs will cause the function to immediatly return.
 *
 * @return The @ref TuiFilterMode of the texture.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
TuiFilterMode tuiTextureGetFilterMode(TuiTexture texture);
/*!
 * @brief Fill a @ref TuiTexture with the data of a @ref TuiImage.
 * 
 * @param texture The texture to fill.
 * @param image The image to fill with.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIZLIED, @ref TUI_ERROR_NULL_TEXTURE and @ref TUI_ERROR_NULL_IMAGE. The first error that occurs will cause the function to immediatly return.
 * 
 * @requirements This function must be called only while TUIC is initialized.
 * 
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
void tuiTextureSetImage(TuiTexture texture, TuiImage image);
/*!
 * @brief Fill a @ref TuiTexture with a pixel array.
 *
 * @param texture The texture to fill.
 * @param pixel_width The width of the pixel array.
 * @param pixel_height The height of the pixel array.
 * @param channel_count The amount of channels in the pixel array.
 * @param pixels The pixel array.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, @ref TUI_ERROR_NULL_TEXTURE, @ref TUI_ERROR_NULL_PIXELS, @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS, and @ref TUI_ERROR_INVALID_CHANNEL_COUNT. The first error that occurs will cause the function to immediatly return. Also, an inccorectly sized or pixels array may cause undefined behaviour or a fatal crash without an error.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
void tuiTextureSetPixels(TuiTexture texture, int pixel_width, int pixel_height, int channel_count, const uint8_t* pixels);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard