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
/*! \file batch.h
 */
#ifndef TUIC_BATCH_H //header guard
#define TUIC_BATCH_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/detail_mode.h>
#include <TUIC/boolean.h>
#include <TUIC/batch_full.h>
#include <TUIC/batch_sparse.h>
#include <TUIC/batch_free.h>


/*! @name Batch Functions
 *
 * These functions are used for manipulating @ref TuiBatch opaque objects.
 *  @{ */
/*!
 * @brief Create a new @ref TuiBatch with detail flag @ref TUI_DETAIL_FLAG_LAYOUT_FULL.
 *
 * @param tui_detail_mode The @ref TuiDetailMode that the @ref TuiBatch will use to organize its tile data.
 * @param tiles_wide The amount of tiles wide of the @ref TuiBatch data.
 * @param tiles_tall The amount of tiles tall of the @ref TuiBatch data.
 * @param minimum_reserved_data_size The miniumum amount of bytes to reserve for the data array. More will be allocated if needed for a full batch of tiles.
 *
 * @returns The created @ref TuiBatch. @ref TUI_NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_INVALID_BATCH_TILE_DIMENSIONS, @ref TUI_ERROR_INVALID_DETAIL_MODE, and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return. 
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 * 
 * @pointer_lifetime The returned @ref TuiBatch must be destroyed using the function @ref tuiBatchDestroy().
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
TuiBatch tuiBatchCreateFull(TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t minimum_reserved_data_size);
/*!
 * @brief Create a new @ref TuiBatch with detail flag @ref TUI_DETAIL_FLAG_LAYOUT_SPARSE.
 *
 * @param tui_detail_mode The @ref TuiDetailMode that the @ref TuiBatch will use to organize its tile data.
 * @param tiles_wide The amount of tiles wide of the @ref TuiBatch data.
 * @param tiles_tall The amount of tiles tall of the @ref TuiBatch data.
 * @param use_stencil If tiles set since the last clear should be tracked using a stencil buffer to prevent drawing more than one tile in the same position location.
 * @param minimum_reserved_data_size The miniumum amount of bytes to reserve for the data array. More will be allocated if needed for a full batch of tiles.
 *
 * @returns The created @ref TuiBatch. @ref TUI_NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_INVALID_BATCH_TILE_DIMENSIONS, @ref TUI_ERROR_INVALID_DETAIL_MODE, and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @pointer_lifetime The returned @ref TuiBatch must be destroyed using the function @ref tuiBatchDestroy().
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
TuiBatch tuiBatchCreateSparse(TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, TuiBoolean use_stencil, size_t minimum_reserved_data_size);
/*!
 * @brief Create a new @ref TuiBatch with detail flag @ref TUI_DETAIL_FLAG_LAYOUT_FREE.
 *
 * @param tui_detail_mode The @ref TuiDetailMode that the @ref TuiBatch will use to organize its tile data.
 * @param tile_pixel_width The width of a single tile in pixels.
 * @param tile_pixel_height The height of a single tile in pixels.
 * @param maximum_tile_count The maximum amount of tiles to allow for pushing into this batch.
 * @param minimum_reserved_data_size The miniumum amount of bytes to reserve for the data array. More will be allocated if needed for reserved_tile_count amount of tiles.
 *
 * @returns The created @ref TuiBatch. @ref TUI_NULL is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_INVALID_BATCH_VIEWPORT_PIXEL_DIMENSIONS, @ref TUI_ERROR_INVALID_BATCH_GLYPH_PIXEL_DIMENSIONS, @ref TUI_ERROR_INVALID_BATCH_MAX_TILE_COUNT, @ref TUI_ERROR_INVALID_DETAIL_MODE, and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @pointer_lifetime The returned @ref TuiBatch must be destroyed using the function @ref tuiBatchDestroy().
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
TuiBatch tuiBatchCreateFree(TuiDetailMode detail_mode, int tile_pixel_width, int tile_pixel_height, int draw_viewport_width, int draw_viewport_height, int maximum_tile_count, size_t minimum_reserved_data_size);
/*!
 * @brief  Destroy @ref TuiBatch and correctly dispose of of its internally managed resources.
 *
 * @param batch The @ref TuiBatch to destroy.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_BATCH and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchDestroy(TuiBatch batch);
/*!
 * @brief  Get the @ref TuiDetailMode used by a @ref TuiBatch.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The @ref TuiDetailMode of the batch. 0 is returned if an error occurs.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_BATCH and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
TuiDetailMode tuiBatchGetDetail(TuiBatch batch);
/*!
 * @brief Set new tile dimensions of a @ref TuiBatch and clear its data.
 *
 * @param batch The @ref TuiBatch to resize.
 * @param tiles_wide The new batch tiles wide.
 * @param tiles_height The new batch tiles tall.
 * @param reserve_extra A @ref TuiBoolean enum that specifies if extra space in the data array should be rserved for future resizes instead of deallocated.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH, @ref TUI_ERROR_INVALID_BATCH_TILE_DIMENSIONS, and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchSetTileDimensions(TuiBatch batch, int tiles_wide, int tiles_tall, TuiBoolean reserve_extra);
/*!
 * @brief Get the tile dimensions of a @ref TuiBatch.
 *
 * @param batch The @ref TuiBatch to get the tile dimensions of.
 * @param tiles_wide A pointer to where the tile width of the @ref TuiBatch will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 * @param tiles_height A pointer to where the tile height of the @ref TuiBatch will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchGetTileDimensions(TuiBatch batch, int* tiles_wide, int* tiles_tall);
/*!
 * @brief Get the width of a @ref TuiBatch in tiles.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The tiles wide. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetTilesWide(TuiBatch batch);
/*!
 * @brief Get the height of a @ref TuiBatch in tiles.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The tiles tall. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetTilesTall(TuiBatch batch);
/*!
 * @brief Set new viewport pixel dimensions of a @ref TuiBatch and clear its data.
 *
 * @param batch The @ref TuiBatch to resize.
 * @param pixel_width The new pixel width of the draw viewport.
 * @param pixel_height The new pixel height of the draw viewport.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH, @ref TUI_ERROR_INVALID_BATCH_VIEWPORT_PIXEL_DIMENSIONS, and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchSetViewportPixelDimensions(TuiBatch batch, int pixel_width, int pixel_height);
/*!
 * @brief Get the viewport pixel dimensions of a @ref TuiBatch.
 *
 * @param batch The @ref TuiBatch to get the tile dimensions of.
 * @param pixel_width A pointer to where the pixel width of the draw viewport will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 * @param pixel_height A pointer to where the pixel height of the draw viewport will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchGetViewportPixelDimensions(TuiBatch batch, int* pixel_width, int* pixel_height);
/*!
 * @brief Get the width of a @ref TuiBatch in pixels.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The pixel width. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetViewportPixelWidth(TuiBatch batch);
/*!
 * @brief Get the height of a @ref TuiBatch in pixels.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The pixel height. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetViewportPixelHeight(TuiBatch batch);
/*!
 * @brief Set new glyph pixel dimensions of a @ref TuiBatch and clear its data.
 *
 * @param batch The @ref TuiBatch to resize.
 * @param pixel_width The new pixel width of each glyph.
 * @param pixel_height The new pixel height of each glyph.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH, @ref TUI_ERROR_INVALID_BATCH_GLYPH_PIXEL_DIMENSISONS, and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchSetGlyphPixelDimensions(TuiBatch batch, int pixel_width, int pixel_height);
/*!
 * @brief Get the viewport pixel dimensions of a @ref TuiBatch.
 *
 * @param batch The @ref TuiBatch to get the tile dimensions of.
 * @param pixel_width A pointer to where the pixel width of each glyph will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 * @param pixel_height A pointer to where the pixel height of each glyph will be stored. If @ref TUI_NULL or an error occurs, it is ignored.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchGetGlyphPixelDimensions(TuiBatch batch, int* pixel_width, int* pixel_height);
/*!
 * @brief Get the width of each glyph of a @ref TuiBatch in pixels.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The pixel width. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetGlyphPixelWidth(TuiBatch batch);
/*!
 * @brief Get the height of each glyph of a @ref TuiBatch in pixels.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The pixel height. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetGlyphPixelHeight(TuiBatch batch);
/*!
 * @brief Set the maximum tile count of a @ref TuiBatch and clear its data.
 *
 * @param batch The @ref TuiBatch.
 * @param max_tile_count The maximum tile count.
 * @param reserve_extra A @ref TuiBoolean enum that specifies if extra space in the data array should be rserved for future resizes instead of deallocated.
 *
 * @returns The maximum tile count. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH, @ref TUI_ERROR_INVALID_BATCH_MAX_TILE_COUNT, and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchSetMaxTileCount(TuiBatch batch, int max_tile_count, TuiBoolean reserve_extra);
/*!
 * @brief Get the maximum tile count of a @ref TuiBatch.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The maximum tile count. 0 is returned if an error occurs.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_BATCH and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetMaxTileCount(TuiBatch batch);
/*!
 * @brief Get the size of the data array of a @ref TuiBatch in bytes.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The size of the data array in bytes. 0 is returned if an error occurs.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_BATCH and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetDataSize(TuiBatch batch);
/*!
 * @brief Get the size of the data array of a @ref TuiBatch in bytes including reserved space.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The size of the data array in bytes, including reserved space. 0 is returned if an error occurs.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_BATCH and immediatly return. 
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
int tuiBatchGetReservedSize(TuiBatch batch);
/*!
 * @brief Get the amount of tiles currently set in a @ref TuiBatch.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns The amount of tiles that are currently set. 0 is returned if an error occurs.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_BATCH and immediatly return. 
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access. 
 */
int tuiBatchGetTileCount(TuiBatch batch);
/*!
 * @brief Get a pointer to the data array of a @ref TuiBatch.
 *
 * @param batch The @ref TuiBatch.
 *
 * @returns A pointer to the data array. TUI_NULL is returned if an error occurs.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_BATCH and immediatly return.
 * 
 * @pointer_lifetime The returned pointer shares its lifetime with the @ref TuiBatch it was taken from, and must not be manually freed.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
const uint8_t* tuiBatchGetData(TuiBatch batch);
/*!
 * @brief Clear the data of a @ref TuiBatch to 0.
 *
 * @param batch The @ref TuiBatch to clear.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_BATCH and immediatly return. 
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread. However, it is important to manipulate and use each @ref TuiBatch on only one thread at a time to ensure safe memory access.
 */
void tuiBatchClear(TuiBatch batch);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard