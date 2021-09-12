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
/*! \file batch_full.h
 */
#ifndef TUIC_BATCH_FULL_H //header guard
#define TUIC_BATCH_FULL_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif


/*! @name Full Batch Data Functions
 *
 * These functions are used for settin data of @ref TuiBatch that use @ref TUI_DETAIL_FLAG_LAYOUT_FULL.
 *  @{ */
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G0_C8NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param fg The 8 bit value that contains the foreground color palette id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G0_C8NBG_FULL(TuiBatch batch, int x, int y, uint8_t fg);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G0_C24NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G0_C24NBG_FULL(TuiBatch batch, int x, int y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G0_C32NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 * @param fg_a The 8 bit value that contains the foreground color alpha color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G0_C32NBG_FULL(TuiBatch batch, int x, int y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C0_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C0_FULL(TuiBatch batch, int x, int y, uint8_t glyph);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C4_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param fg_and_bg The 8 bit value that contains both the foreground and background color palette ids.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C4_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t colors);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C8_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param fg The 8 bit value that contains the foreground color palette id.
 * @param bg The 8 bit value that contains the background color palette id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C8_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg, uint8_t bg);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C8NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param fg The 8 bit value that contains the foreground color palette id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C8NBG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C8NFG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param bg The 8 bit value that contains the background color palette id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C8NFG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C24_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 * @param bg_r The 8 bit value that contains the background color red color value.
 * @param bg_g The 8 bit value that contains the background color green color value.
 * @param bg_b The 8 bit value that contains the background color blue color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C24_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C24NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C24NBG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C24NFG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param bg_r The 8 bit value that contains the background color red color value.
 * @param bg_g The 8 bit value that contains the background color green color value.
 * @param bg_b The 8 bit value that contains the background color blue color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C24NFG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C32_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 * @param fg_a The 8 bit value that contains the foreground color alpha color value.
 * @param bg_r The 8 bit value that contains the background color red color value.
 * @param bg_g The 8 bit value that contains the background color green color value.
 * @param bg_b The 8 bit value that contains the background color blue color value.
 * @param bg_a The 8 bit value that contains the background color alpha color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C32_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C32NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 * @param fg_a The 8 bit value that contains the foreground color alpha color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C32NBG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G8_C32NFG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 8 bit glyph id.
 * @param bg_r The 8 bit value that contains the background color red color value.
 * @param bg_g The 8 bit value that contains the background color green color value.
 * @param bg_b The 8 bit value that contains the background color blue color value.
 * @param bg_a The 8 bit value that contains the background color alpha color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G8_C32NFG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C0_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C0_FULL(TuiBatch batch, int x, int y, uint16_t glyph);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C4_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param fg_and_bg The 8 bit value that contains both the foreground and background color palette ids.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C4_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t colors);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C8_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param fg The 8 bit value that contains the foreground color palette id.
 * @param bg The 8 bit value that contains the background color palette id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C8_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg, uint8_t bg);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C8NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param fg The 8 bit value that contains the foreground color palette id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C8NBG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C8NFG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param bg The 8 bit value that contains the background color palette id.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C8NFG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C24_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 * @param bg_r The 8 bit value that contains the background color red color value.
 * @param bg_g The 8 bit value that contains the background color green color value.
 * @param bg_b The 8 bit value that contains the background color blue color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C24_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C24NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C24NBG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C24NFG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param bg_r The 8 bit value that contains the background color red color value.
 * @param bg_g The 8 bit value that contains the background color green color value.
 * @param bg_b The 8 bit value that contains the background color blue color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C24NFG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C32_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 * @param fg_a The 8 bit value that contains the foreground color alpha color value.
 * @param bg_r The 8 bit value that contains the background color red color value.
 * @param bg_g The 8 bit value that contains the background color green color value.
 * @param bg_b The 8 bit value that contains the background color blue color value.
 * @param bg_a The 8 bit value that contains the background color alpha color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C32_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C32NBG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param fg_r The 8 bit value that contains the foreground color red color value.
 * @param fg_g The 8 bit value that contains the foreground color green color value.
 * @param fg_b The 8 bit value that contains the foreground color blue color value.
 * @param fg_a The 8 bit value that contains the foreground color alpha color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C32NBG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a);
/*!
 * @brief Set a tile of a @ref TuiBatch that uses @ref TUI_DETAIL_MODE_G16_C32NFG_FULL detail mode.
 *
 * @param batch The @ref TuiBatch.
 * @param x The x coordinate of the tile.
 * @param y The y coordinate of the tile.
 * @param glyph The 16 bit glyph id.
 * @param bg_r The 8 bit value that contains the background color red color value.
 * @param bg_g The 8 bit value that contains the background color green color value.
 * @param bg_b The 8 bit value that contains the background color blue color value.
 * @param bg_a The 8 bit value that contains the background color alpha color value.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NULL_BATCH and @ref TUI_ERROR_INVALID_BATCH_FUNCTION. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function can be called safely on any thread at any time.
 */
void tuiBatchSetTile_G16_C32NFG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard