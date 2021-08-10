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
/*! \file palette.h
 */
#ifndef TUIC_PALETTE_H //header guard
#define TUIC_PALETTE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <stdint.h>


/*!
 * @brief An array of all 256 24 bit colors in the XTerm standard color palette.
 */
extern const uint8_t kTuiXtermPalette[768];


/*! @name Palette Functions
 *
 * Functions for manipulating @ref TuiPalette opaque objects.
 *  @{ */
/*!
 * @brief Create a custon @ref TuiPalette.
 * 
 * @param channel_count The amount of channels per color.
 * @param color_count The amount of colors in the palette.
 * @param color_data A pointer to the color data array.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, @ref TUI_ERROR_INVALID_PALETTE_COLOR_COUNT, @ref TUI_ERROR_INVALID_CHANNEL_COUNT, and @ref TUI_ERROR_NULL_COLORS. The first error that occurs will cause the function to immediatly return. Also, an inccorectly sized or colors array may cause undefined behaviour or a fatal crash without an error.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned @ref TuiPalette must be destroyed before TUIC is terminated, using the function @ref tuiPaletteDestroy().
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
TuiPalette tuiPaletteCreate(int channel_count, int color_count, const uint8_t* color_data);
/*!
 * @brief Create a @ref TuiPalette that uses the XTerm standard color palette.
 * 
 * @param color_count The amount of XTerm colors to add to the palette.
 * 
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED, and @ref TUI_ERROR_INVALID_PALETTE_COLOR_COUNT. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @pointer_lifetime The returned @ref TuiPalette must be destroyed before TUIC is terminated, using the function @ref tuiPaletteDestroy().
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
TuiPalette tuiPaletteCreateXterm(int color_count);
/*!
 * @brief Free a @ref TuiPalette and correctly dispose of of its internally managed resources.
 *
 * @param palette The @ref TuiPalette to destroy.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_PALETTE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access and to prevent graphics context errors.
 */
void tuiPaletteDestroy(TuiPalette palette);
/*!
 * @brief Get the amount of @ref TuiPalette that currently exist.
 *
 * @returns The amount of palettes that currently exist.
 *
 * @errors This function does not have errors.
 *
 * @requirements This function can be called at any time.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiGetPaletteCount();
/*!
 * @brief Get the amount of colors in a @ref TuiPalette.
 *
 * @param palette The @ref TuiPalette to retrieve the color count from.
 *
 * @returns The amount of colors. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_PALETTE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiPaletteGetColorCount(TuiPalette palette);
/*!
 * @brief Get the amount of color channels in a @ref TuiPalette.
 *
 * @param palette The @ref TuiPalette to retrieve the color channel count from.
 *
 * @returns The amount of color channels. 0 is returned if an error occurs.
 *
 * @errors Possible errors in order are @ref TUI_ERROR_NOT_INITIALIZED and @ref TUI_ERROR_NULL_PALETTE. The first error that occurs will cause the function to immediatly return.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function must only be called on the same thread on which TUIC was initialized to ensure safe memory access.
 */
int tuiPaletteGetChannelCount(TuiPalette palette);
/*!
 * @brief tet the foreground color palette id from a two color byte.
 *
 * @param fg_and_bg The two color byte.
 *
 * @returns The foreground color palette id.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
uint8_t tuiClassicColorGetForeground(uint8_t fg_and_bg);
/*!
 * @brief tet the background color palette id from a two color byte.
 *
 * @param fg_and_bg The two color byte.
 *
 * @returns The background color palette id.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
uint8_t tuiClassicColorGetBackground(uint8_t fg_and_bg);
/*!
 * @brief Combine a foreground and background palette color id pair into a two color byte.
 *
 * @param fg The foreground color palette id.
 * @param bg The background color palette id.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
uint8_t tuiClassicColorCombine(uint8_t fg, uint8_t bg);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard