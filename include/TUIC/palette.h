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
 * @brief The default Xterm color palette, with every three indices representing the RGB values of each of the 256 colors ordered by color index. 
 */
extern const uint8_t kTuiXtermPalette[768];
/*! @name TuiPalette functions
 *
 * These functions are used for manipulating @ref TuiPalette opaque objects.
 *
 *  @{ */
/*!
 * @brief Create a new @ref TuiPalette with custom colors.
 *
 * Use this function to create a @ref TuiPalette using an array of colors. The array must be in order of the color indices in the pallete, in order of their RGB components.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param channel_count The amount of color channels per color.
 * @param color_count The amount of colors.
 * @param color_data A pointer to an array that contains all of the colors.
 *
 * @returns The created @ref TuiPalette object. NULLL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_INVALID_PALETTE_COLOR_COUNT if color count is not greater than 0 and less than or equal to 256.
 * Throws @ref TUI_ERROR_INVALID_CHANNEL_COUNT if channel_count is not 3 or 4.
 * Throws @ref TUI_ERROR_NULL_COLORS if color_data is NULL. 
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiPalette tuiPaletteCreate(TuiInstance instance, int channel_count, int color_count, uint8_t* color_data);
/*!
 * @brief Create a new @ref TuiPalette using the Xterm standard color palette.
 *
 * Use this function to create a @ref TuiPalette using the Xterm standard color palette.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param tui_palette_size The amount of colors from the Xterm pallete to add to this @ref TuiPalette.
 *
 * @returns The created @ref TuiPalette object. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_INVALID_PALETTE_COLOR_COUNT if color count is not greater than 0 and less than or equal to 256.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiPalette tuiPaletteCreateXterm(TuiInstance instance, int tui_palette_size);
/*!
 * @brief Destroy @ref TuiPalette and correctly dispose of all of its resources.
 *
 * Call this function when you wish to destroy a @ref TuiPalette object. This is typically called before application exist, shortly before destroying the associated @ref TuiInstance.
 *
 * @param palette The @ref TuiPalette object to destroy.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PALETTE is palette is NULL.
 */
void tuiPaletteDestroy(TuiPalette palette);
/*!
 * @brief  Get the @ref TuiInstance of a  @ref TuiPalette.
 *
 * @param palette The @ref TuiPalette.
 *
 * @returns The @ref TuiInstance. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PALETTE if palette is NULL.
 */
TuiInstance tuiPaletteGetInstance(TuiPalette palette);
/*!
 * @brief Returns the amount of colors in a @ref TuiPalette object.
 *
 * @param palette The @ref TuiPalette object.
 *
 * @returns The amount of colors in the @ref TuiPalette.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PALETTE is palette is NULL.
 */
int tuiPaletteGetColorCount(TuiPalette palette);
/*!
 * @brief Returns the amount of color channels in a @ref TuiPalette object. 0 is returned on error.
 *
 * @param palette The @ref TuiPalette object.
 *
 * @returns The amount of color channels in the @ref TuiPalette. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PALETTE is palette is NULL.
 */
int tuiPaletteGetChannelCount(TuiPalette palette);
/*!
 * @brief Extract the foreground color palette id from two color byte.
 *
 * @param detail_mode The two color byte.
 *
 * @returns The forground color.
 */
uint8_t tuiClassicColorGetForeground(uint8_t fg_and_bg);
/*!
 * @brief Extract the background color palette id from two color byte.
 *
 * @param detail_mode The two color byte.
 *
 * @returns The background color.
 */
uint8_t tuiClassicColorGetBackground(uint8_t fg_and_bg);
/*!
 * @brief Combine two 4 bit foreground and background color palette ids into a two color byte.
 *
 * @param fg The foreground color.
 * @param bg The background color.
 *
 * @returns The two color byte.
 */
uint8_t tuiClassicColorCombine(uint8_t fg, uint8_t bg);
/*! @} */
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard