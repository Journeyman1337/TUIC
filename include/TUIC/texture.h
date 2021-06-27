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
/*! @name TuiTexture functions
 *
 * These functions are used for manipulating @ref TuiTexture opaque objects.
 *
 * @{ */
/*!
 * @brief Create a @ref TuiTexture with a @ref TuiImage.
 *
 * @param instance The @ref TuiInstance.
 * @param image The @ref TuiImage.
 * @param filter_mode The @ref TuiFilterMode.
 * @param draw_mode The @ref TuiDrawMode.
 *
 * @returns The created @ref TuiTexture object. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_INVALID_FILTER_MODE if filter_mode is not a valid @ref TuiFilterMode.
 * Throws @ref TUI_ERROR_INVALID_DRAW_MODE if draw_mode is not a valid @ref TuiDrawMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiTexture tuiTextureCreate(TuiInstance instance, TuiImage image, int filter_mode, int draw_mode);
/*!
 * @brief Create a @ref TuiTexture with a raw pixel array.
 *
 * @param instance The @ref TuiInstance.
 * @param pixel_width The width of the pixel array in pixels.
 * @param pixel_height The height of the pixel array in pixels.
 * @param channel_count The amount of channels per pixel in the pixel array.
 * @param pixels A pointer to the pixel array.
 * @param filter_mode The @ref TuiFilterMode.
 * @param draw_mode The @ref TuiDrawMode.
 *
 * @returns The created @ref TuiTexture object. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_PIXELS if pixels is NULL.
 * Throws @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS if pixel_with or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT if channel_count is not 3 or 4.
 * Throws @ref TUI_ERROR_INVALID_FILTER_MODE if filter_mode is not a valid @ref TuiFilterMode.
 * Throws @ref TUI_ERROR_INVALID_DRAW_MODE if draw_mode is not a valid @ref TuiDrawMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiTexture tuiTextureCreateRawPixels(TuiInstance instance, int pixel_width, int pixel_height, int channel_count, const uint8_t* pixels, int filter_mode, int draw_mode);
/*!
 * @brief  Destroy @ref TuiTexture and correctly dispose of all of its resources.
 *
 * @param texture The @ref TuiTexture object to destroy.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiTextureDestroy(TuiTexture texture);
/*!
 * @brief Get width and height of the image of a @ref TuiTexture in pixels.
 *
 * @param texture The @ref TuiTexture.
 * @param out_pixel_width A pointer to where the width will be stored. If NULL or an error occurs, it is ignored.
 * @param out_pixel_height A pointer to where the height will be stored. If NULL or an error occurs, it is ignored.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if atlas is NULL.
 */
void tuiTextureGetPixelDimensions(TuiTexture texture, int* pixel_width, int* pixel_height);
/*!
 * @brief Get the pixel width of the texture of a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 *
 * @returns The pixel width of the texture. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 */
int tuiTextureGetPixelWidth(TuiTexture texture);
/*!
 * @brief Get the pixel heigith of the texture of a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 *
 * @returns The pixel heigith of the texture. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 */
int tuiTextureGetPixelHeight(TuiTexture texture);
/*!
 * @brief Get the amount of channels used by a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 *
 * @returns The amount of color channels. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 */
int tuiTextureGetChannelCount(TuiTexture texture);
/*!
 * @brief Get the @ref TuiFilterMode used by a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 *
 * @returns The @ref TuiFilterMode. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 */
int tuiTextureGetFilterMode(TuiTexture texture);
/*!
 * @brief Get the @ref TuiDrawMode used by a @ref TuiTexture.
 *
 * @param texture The @ref TuiTexture.
 *
 * @returns The @ref TuiDrawMode. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 */
int tuiTextureGetDrawMode(TuiTexture texture);
/*!
 * @brief Set the pixels of a @ref TuiTexture with a @ref TuiImage.
 *
 * @param texture The @ref TuiTexture.
 * @param image The @ref TuiImage.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the instance of texture is damaged.
 * Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiTextureSetImage(TuiTexture texture, TuiImage image);
/*!
 * @brief Set the pixels of a @ref TuiTexture with a raw pixel array.
 *
 * @param texture The @ref TuiTexture.
 * @param pixel_width The width of the pixel array in pixels.
 * @param pixel_height The height of the pixel array in pixels.
 * @param channel_count The amount of channels per pixel in the pixel array.
 * @param pixels A pointer to the pixel array.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the instance of texture is damaged.
 * Throws @ref TUI_ERROR_NULL_PIXELS if pixels is NULL.
 * Throws @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS if pixel_with or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT if channel_count is not 3 or 4.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiTextureSetPixels(TuiTexture texture, int pixel_width, int pixel_height, int channel_count, const uint8_t* pixels);
/*!
 * @brief Render a @ref TuiTexture to the main graphics context framebuffer if its @ref TuiInstance.
 *
 * @param texture The @ref TuiTexture.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the TuiInstance of texture is damaged.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiTextureRender(TuiTexture texture);
/*!
 * @brief Render a @ref TuiTexture to the main graphics context framebuffer of its @ref TuiInstance in a transformed position.
 *
 * @param texture The @ref TuiTexture.
 * @param left_x The framebuffer pixel x coordinate of the @ref TuiPanel left side.
 * @param right_x The framebuffer pixel x coordinate of the @ref TuiPanel right side.
 * @param top_y The framebuffer pixel y coordinate of the @ref TuiPanel top side.
 * @param bottom_y The framebuffer pixel y coordinat of the @ref TuiPanel bottom side.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of texture is damaged.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiTextureRenderTransformed(TuiTexture texture, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Render the framebuffer texture of a @ref TuiPanel to the framebuffer of a @ref TuiPanel.
 *
 * @param panel The @ref TuiTexture.
 * @param panel The @ref TuiPanel.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the TuiInstance of texture is damaged.
 * Throws @ref TUI_ERROR_NULL_TARGET_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_UNMATCHING_PANEL_INSTANCE if the @ref TuiInstacne of panel does not match the @ref TuiInstance of texture.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiTextureRenderToPanel(TuiTexture texture, TuiPanel panel);
/*!
 * @brief Render the framebuffer texture of a @ref TuiPanel to the framebuffer of a @ref TuiPanel.
 *
 * @param panel The @ref TuiTexture.
 * @param panel The @ref TuiPanel.
 * @param left_x The framebuffer pixel x coordinate of the @ref TuiPanel left side.
 * @param right_x The framebuffer pixel x coordinate of the @ref TuiPanel right side.
 * @param top_y The framebuffer pixel y coordinate of the @ref TuiPanel top side.
 * @param bottom_y The framebuffer pixel y coordinat of the @ref TuiPanel bottom side.
 *
 * @errors Throws @ref TUI_ERROR_NULL_TEXTURE if texture is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the TuiInstance of texture is damaged.
 * Throws @ref TUI_ERROR_NULL_TARGET_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_UNMATCHING_PANEL_INSTANCE if the @ref TuiInstacne of panel does not match the @ref TuiInstance of texture.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiTextureRenderToPanelTransformed(TuiTexture texture, TuiPanel panel, int left_x, int right_x, int top_y, int bottom_y);
/*! @} */
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard