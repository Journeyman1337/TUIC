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
/*! \file glyph_atlas.h
 */
#ifndef TUIC_GLYPH_ATLAS_H //header guard
#define TUIC_GLYPH_ATLAS_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
/*! @name TuiGlyphAtlas functions
 *
 * These functions are used for manipulating @ref TuiGlyphAtlas opaque objects.
 *
 *  @{ */
/*!
 * @brief Create a new @ref TuiGlyphAtlas from a @ref TuiImage using @ref ATLAS_TYPE_COORDS.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param image The @ref TuiImage of for the texture.
 * @param glyph_count The amount of glyphs.
 * @param glyph_bounding_boxes The STPQ pixel coordinate bounding boxes surrounding each consequitive glyph ordered by ID.
 * @param blend_mode The @ref TuiBlendMode.
 *
 * @returns The created @ref TuiBatch object. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_INVALID_GLYPH_COUNT if glyph_count is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if blend_mode is an invalid @ref TuiBlendMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiGlyphAtlas tuiGlyphAtlasCreate(TuiInstance instance, TuiImage image, int glyph_count, uint16_t* glyph_bounding_boxes, TuiBlendMode blend_mode);
/*!
 * @brief Create a new @ref TuiGlyphAtlas from a raw pixel array using @ref ATLAS_TYPE_COORDS.
 *
 * @param instance The @ref TuiInstance object from raw pixel data that contains the graphics context.
 * @param pixel_width The width of the pixel array.
 * @param pixel_height The height of the pixel array.
 * @param channel_count The channel count of the pixel array.
 * @param raw_pixels The raw pixel array.
 * @param glyph_count The amount of glyphs in this atlas.
 * @param glyph_bounding_boxes The STPQ pixel coordinate bounding boxes surrounding each consequitive glyph ordered by ID.
 * @param blend_mode The @ref TuiBlendMode.
 *
 * @returns The created @ref TuiBatch object. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_PIXELS if pixels is NULL.
 * Throws @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS if pixel_with or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES if glyph_bounding_boxes is NULL.
 * Throws @ref TUI_ERROR_INVALID_GLYPH_COUNT if glyph_count is NULL.
 * Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT if channel_count is not 3 or 4.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if blend_mode is an invalid @ref TuiBlendMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiGlyphAtlas tuiGlyphAtlasCreateRawPixels(TuiInstance instance, int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, uint16_t* glyph_bounding_boxes, TuiBlendMode blend_mode);
/*!
 * @brief Create a new @ref TuiGlyphAtlas from a @ref TuiImage using @ref ATLAS_TYPE_COORDS and raw uvs.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param image The @ref TuiImage of for the texture.
 * @param glyph_count The amount of glyphs.
 * @param raw_glyph_uvs The raw UV bounding box array.
 * @param blend_mode The @ref TuiBlendMode.
 *
 * @returns The created @ref TuiBatch object. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_NULL_TEXTURE_COORDINATES if raw_glyph_uvs is NULL.
 * Throws @ref TUI_ERROR_INVALID_GLYPH_COUNT if glyph_count is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if blend_mode is an invalid @ref TuiBlendMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiGlyphAtlas tuiGlyphAtlasCreateRawUVs(TuiInstance instance, TuiImage image, int glyph_count, float* raw_glyph_uvs, TuiBlendMode blend_mode);
/*!
 * @brief Create a new @ref TuiGlyphAtlas from a @ref TuiImage using raw texture coordinates and @ref ATLAS_TYPE_COORDS.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param pixel_width The width of the pixel array.
 * @param pixel_height The height of the pixel array.
 * @param channel_count The channel count of the pixel array.
 * @param pixels The raw pixels of the image.
 * @param glyph_count The amount of glyphs in this atlas.
 * @param raw_glyph_uvs The STPQ floating point UV texture coordinate bounding boxes surrounding each consequitive glyph ordered by ID.
 * @param blend_mode The @ref TuiBlendMode.
 *
 * @returns The created @ref TuiBatch object. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_PIXELS if pixels is NULL.
 * Throws @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS if pixel_with or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_NULL_TEXTURE_COORDINATES if raw_glyph_uvs is NULL.
 * Throws @ref TUI_ERROR_INVALID_GLYPH_COUNT if glyph_count is NULL.
 * Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT if channel_count is not 3 or 4.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if blend_mode is an invalid @ref TuiBlendMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiGlyphAtlas tuiGlyphAtlasCreateRawPixelsRawUVs(TuiInstance instance, int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, float* raw_glyph_uvs, TuiBlendMode blend_mode);
/*!
 * @brief Create a new @ref TuiGlyphAtlas from a @ref TuiImage using @ref ATLAS_TYPE_GRID.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param image The @ref TuiImage object for the atlas image.
 * @param tile_pixel_width The width of a single tile in pixels when rendered to a panel.
 * @param tile_pixel_height The height of a single tile in pixels when rendered to a panel.
 * @param blend_mode The @ref TuiBlendMode.
 *
 * @returns The created @ref TuiBatch object. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_INVALID_GLYPH_DIMENSIONS if the tile pixel dimensions are invalid.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if blend_mode is an invalid @ref TuiBlendMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiGlyphAtlas tuiGlyphAtlasCreateGrid(TuiInstance instance, TuiImage image, int tile_pixel_width, int tile_pixel_height, TuiBlendMode blend_mode);
/*!
 * @brief Create a new @ref TuiGlyphAtlas using @ref ATLAS_TYPE_GRID.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param pixel_width The width of the pixel array.
 * @param pixel_height The height of the pixel array.
 * @param channel_count The channel count of the pixel array.
 * @param pixels The raw pixels of the image.
 * @param tile_pixel_width The width of a single tile in pixels when rendered to a panel.
 * @param tile_pixel_height The height of a single tile in pixels when rendered to a panel.
 *
 * @returns The created @ref TuiBatch object. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_PIXELS if pixels is NULL.
 * Throws @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS if pixel_with or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT if channel_count is not 3 or 4.
 * Throws @ref TUI_ERROR_INVALID_GLYPH_DIMENSIONS if the tile pixel dimensions are invalid.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if blend_mode is an invalid @ref TuiBlendMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiGlyphAtlas tuiGlyphAtlasCreateGridRawPixels(TuiInstance instance, int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int tile_pixel_width, int tile_pixel_height, TuiBlendMode blend_mode);
/*!
 * @brief Create a new @ref TuiGlyphAtlas from a @ref TuiImage for a codepage spritesheet using @ref ATLAS_TYPE_GRID.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param image The @ref TuiImage object for the atlas image.
 *
 * @returns The created @ref TuiBatch object. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_IMAGE if image is NULL.
 * Throws @ref TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS if the pixel dimensions are invalid for a codepage atlas.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if blend_mode is an invalid @ref TuiBlendMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiGlyphAtlas tuiGlyphAtlasCreateCodepageGrid(TuiInstance instance, TuiImage image, TuiBlendMode blend_mode);
/*!
 * @brief Create a new @ref TuiGlyphAtlas for a codepage spritesheet using @ref ATLAS_TYPE_GRID.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param image_width The width of the image in pixels.
 * @param image_height The height of the image in pixels.
 * @param image_channels The image channel count / texture format.
 * @param image_pixels The raw pixels of the image.
 *
 * @returns The created @ref TuiBatch object. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_PIXELS if pixels is NULL.
 * Throws @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS if pixel_with or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT if channel_count is not 3 or 4.
 * Throws @ref TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS if the pixel dimensions are invalid for a codepage atlas.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if blend_mode is an invalid @ref TuiBlendMode.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiGlyphAtlas tuiGlyphAtlasCreateCodepageGridRawPixels(TuiInstance instance, int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, TuiBlendMode blend_mode);
/*!
 * @brief  Destroy @ref TuiGlyphAtlas and correctly dispose of all of its resources.
 *
 * @param atlas The @ref TuiGlyphAtlas object to destroy.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiGlyphAtlasDestroy(TuiGlyphAtlas atlas);
/*!
 * @brief  Get the @ref TuiInstance of a  @ref TuiGlyphAtlas.
 *
 * @param atlas The @ref TuiGlyphAtlas.
 * 
 * @returns The @ref TuiInstance. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 */
TuiInstance tuiGlyphAtlasGetInstance(TuiGlyphAtlas atlas);
/*!
 * @brief Get the amount of channels used by a @ref TuiGlyphAtlas.
 * 
 * @param atlas The @ref TuiGlyphAtlas.
 * 
 * @returns The amount of color channels. 0 is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 */
int tuiGlyphAtlasGetChannelCount(TuiGlyphAtlas atlas);
/*!
 * @brief Get the pixel width of the texture of a @ref TuiGlyphAtlas.
 *
 * @param atlas The @ref TuiGlyphAtlas.
 *
 * @returns The pixel width of the texture. 0 is returned on error.
 *
 *  @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 */
int tuiGlyphAtlasGetPixelWidth(TuiGlyphAtlas atlas);
/*!
 * @brief Get the pixel height of the texture of a @ref TuiGlyphAtlas.
 *
 * @param atlas The @ref TuiGlyphAtlas.
 *
 * @returns The pixel height of the texture. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 */
int tuiGlyphAtlasGetPixelHeight(TuiGlyphAtlas atlas);
/*!
 * @brief Get width and height of the image of a @ref TuiGlyphAtlas in pixels.
 *
 * @param atlas The @ref TuiGlyphAtlas.
 * @param out_pixel_width A pointer to where the width will be stored. If NULL or an error occurs, it is ignored.
 * @param out_pixel_height A pointer to where the height will be stored. If NULL or an error occurs, it is ignored.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 */
void tuiGlyphAtlasGetPixelDimensions(TuiGlyphAtlas atlas, int* out_pixel_width, int* out_pixel_height);
/*!
 * @brief Get the @ref TuiBlendMode of a @ref TuiGlyphAtlas.
 *
 * @param atlas The @ref TuiGlyphAtlas.
 *
 * @returns The @ref TuiBlendMode. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 */
TuiBlendMode tuiGlyphAtlasGetBlendMode(TuiGlyphAtlas atlas);
/*!
 * @brief Set the @ref TuiBlendMode of a @ref TuiGlyphAtlas.
 *
 * @param atlas The @ref TuiGlyphAtlas.
 * @param blend_mode The blend mode.
 *
 * @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of atlas is damaged.
 * Throws @ref TUI_ERROR_INVALID_BLEND_MODE if atlas is NULL.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiGlyphAtlasSetBlendMode(TuiGlyphAtlas atlas, TuiBlendMode blend_mode);
/*!
 * @brief Get the glyph count of a @ref TuiGlyphAtlas.
 *
 * @param atlas The @ref TuiGlyphAtlas.
 *
 * @returns The glyuph count. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 */
int tuiGlyphAtlasGetGlyphCount(TuiGlyphAtlas atlas);
/*!
 * @brief Get a raw UV texture coordinate STPQ array from a raw pixel coordinate STPQ array.
 *
 * @param glyph_count The amount of glyphs.
 * @param pixel_coordinates The pixel coordinate array.
 * @param texture_width The width of the texture in pixels.
 * @param texture_height The height of the texture in pixels.
 * @param out_ptr A pointer to a correctly sized array where the output will be stored. If NULL, a new array is allocated on the heap instead.
 *
 * @returns The UV texture coordinate array.
 */
float* tuiGenerateUVCoordinatesFromPixelCooordinates(int glyph_count, uint16_t* pixel_coordinates, int texture_width, int texture_height, float* out_ptr);
/*! @} */
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard