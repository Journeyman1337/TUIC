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
/*! \file atlas.h
 */
#ifndef TUIC_ATLAS_H //header guard
#define TUIC_ATLAS_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>


/*! @name Atlas Functions
 *
 * Functions for manipulating @ref TuiAtlas opaque objects.
 *  @{ */

TuiAtlas tuiAtlasCreateCoordinateImagePixelBoundingBoxes(TuiImage image, int glyph_count, uint16_t* glyph_bounding_boxes);

TuiAtlas tuiAtlasCreateCoordinateRawPixelsPixelBoundingBoxes(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, uint16_t* glyph_bounding_boxes);

TuiAtlas tuiAtlasCreateCoordinateImageRawUVs(TuiImage image, int glyph_count, float* raw_glyph_uvs);

TuiAtlas tuiAtlasCreateCoordinateRawPixelsRawUVs(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int glyph_count, float* raw_glyph_uvs);

TuiAtlas tuiAtlasCreateGridImage(TuiImage image, int tile_pixel_width, int tile_pixel_height);

TuiAtlas tuiAtlasCreateGridRawPixels(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels, int tile_pixel_width, int tile_pixel_height);

TuiAtlas tuiAtlasCreateCodepageImage(TuiImage image);

TuiAtlas tuiAtlasCreateCodepageRawPixels(int pixel_width, int pixel_height, int channel_count, uint8_t* pixels);
/*!
 * @brief Free a @ref TuiAtlas and correctly dispose of of its internally managed resources.
 *
 * @param atlas The @ref TuiAtlas to destroy.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_ATLAS. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
void tuiAtlasDestroy(TuiAtlas atlas);
/*!
 * @brief Get the amount of @ref TuiAtlas that currently exist.
 *
 * @returns The amount of atlases that currently exist.
 * 
 * @errors This function does not have errors.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiGetAtlasCount();
/*!
 * @brief Get the amount of color channels in the texutre of a @ref TuiAtlas.
 * 
 * @param atlas The @ref TuiAtlas to retrieve the channel count from.
 * 
 * @returns The amount of color channels. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_ATLAS. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiAtlasGetChannelCount(TuiAtlas atlas);
/*!
 * @brief Get the pixel width in the texutre of a @ref TuiAtlas.
 * 
 * @param atlas The @ref TuiAtlas to retrieve the pixel width from.
 * 
 * @returns The pixel width. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_ATLAS. The first error that occurs will cause the function to immediatly return.
 *
  * @requirements This function must be called only while TUIC is initialized.
  *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiAtlasGetPixelWidth(TuiAtlas atlas);
/*!
 * @brief Get the pixel height in the texutre of a @ref TuiAtlas.
 * 
 * @param atlas The @ref TuiAtlas to retrieve the pixel height from.
 * 
 * @returns The pixel height. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_ATLAS. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called at any time. However, this function is only useful for accessing information from a @ref TuiAtlas, which can only exist while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiAtlasGetPixelHeight(TuiAtlas atlas);
/*!
 * @brief Get the pixel height in the texutre of a @ref TuiAtlas.
 * 
 * @param atlas The @ref TuiAtlas to retrieve the pixel dimensions from.
 * @param out_pixel_width A pointer to where the pixel width of the atlas texture will be stored. If @ref TUI_NULL, it is ignored.
 * @param out_pixel_height A pointer to where the pixel height of the atlas texture will be stored. If @ref TUI_NULL, it is ignored.
 * @param out_channel_count A pointer to where the channel count of the atlas texture will be stored. If @ref TUI_NULL, it is ignored.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_ATLAS. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety For each @ref TuiAtlas, this function must only be called on one thread at a time to ensure safe memory access.
 */ 
void tuiAtlasGetPixelDimensions(TuiAtlas atlas, int* out_pixel_width, int* out_pixel_height, int* out_channel_count);
/*!
 * @brief Get the amount of glyphs present in a @ref TuiAtlas.
 *
 * @param atlas The @ref TuiAtlas.
 *
 * @returns The glyph count. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_ATLAS. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiAtlasGetGlyphCount(TuiAtlas atlas);
/*!
 * @brief Get a raw UV texture coordinate STPQ array from a raw pixel coordinate STPQ array.
 *
 * @param glyph_count The amount of glyphs.
 * @param pixel_coordinates The pixel coordinate array.
 * @param texture_width The width of the texture in pixels.
 * @param texture_height The height of the texture in pixels.
 * @param out_ptr A pointer to a correctly sized array where the output will be stored. If @ref TUI_NULL, a new array is allocated on the heap instead.
 *
 * @returns The UV texture coordinate array.
 *
 * @errors This function can have no errors. However, a malformed pixel coordinate array or a misized out_ptr array may cause undefined behaviour or a fatal crash without an error.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @pointer_lifetime The returned UV texture coordinate array must be freed with @ref tuiFree() when it is no longer needed to avoid memory leaks.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
float* tuiGenerateUVCoordinatesFromPixelCooordinates(int glyph_count, uint16_t* pixel_coordinates, int texture_width, int texture_height, float* out_ptr);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard