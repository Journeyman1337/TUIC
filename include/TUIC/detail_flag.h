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
/*! \file detail_flag.h
 */
#ifndef TUIC_DETAIL_FLAG_H //header guard
#define TUIC_DETAIL_FLAG_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*!
 * @brief Bitflag components that are combined into @ref TuiDetailMode enums.
 */
typedef enum TuiDetailFlag
{
	/*!
	 * @brief TUI detail mode glyph flag for 8 bit glyphs. This supports up to 256 unique glyphs. This size is optimal if you only want to use code page 437 for rendering.
	 */
	TUI_GLYPH_FLAG_G8 = (1 << 0),
	/*!
	 * @brief Detail mode glyph flag for 16 bit glyphs. This supports up to 65536 unique glyphs per @ref TuiAtlas.
	 */
	TUI_GLYPH_FLAG_G16 = (1 << 1),
	/*!
	 * @brief TUI detail mode flag for no colors. This shrinks the byte size per tile by not requiring any information about foreground and background colors.
	 */
	TUI_COLOR_FLAG_C0 = (1 << 2),
	/*!
	 * @brief TUI detail mode color flag for 4 bit colors. This enables use of a 16 color @ref TuiPalette for colors.
	 */
	TUI_COLOR_FLAG_C4 = (1 << 3),
	/*!
	 * @brief TUI detail mode color flag for 8 bit colors. This enables use of a 256 color @ref TuiPalette for colors.
	 */
	TUI_COLOR_FLAG_C8 = (1 << 4),
	/*!
	 * @brief TUI detail mode color flag for 8 bit colors with no foreground color. This enables use of a 256 color @ref TuiPalette for colors.
	 */
	TUI_COLOR_FLAG_C8NFG = (1 << 5),
	/*!
	 * @brief TUI detail mode color flag for 8 bit colors with no background color. This enables use of a 256 color @ref TuiPalette for colors.
	 */
	TUI_COLOR_FLAG_C8NBG = (1 << 6),
	/*!
	 * @brief TUI detail mode color flag for 24 bit colors. This enables use of 24 bit full colors with RGB components.
	 */
	TUI_COLOR_FLAG_C24 = (1 << 7),
	/*!
	 * @brief TUI detail mode color flag for a single 24 bit background color per tile. This enables use of 24 bit full colors with RGB components.
	 */
	TUI_COLOR_FLAG_C24NFG = (1 << 8),
	/*!
	 * @brief TUI detail mode color flag for a single 24 bit foreground color per tile. This enables use of 24 bit full colors with RGB components.
	 */
	TUI_COLOR_FLAG_C24NBG = (1 << 9),
	/*!
	 * @brief TUI detail mode color flag for 32 bit colors. This enables use of 32 bit full colors with RGBA components.
	 */
	TUI_COLOR_FLAG_C32 = (1 << 10),
	/*!
	 * @brief TUI detail mode color flag for a single 32 bit background color per tile. This enables use of 32 bit full colors with RGBA components.
	 */
	TUI_COLOR_FLAG_C32NFG = (1 << 11),
	/*!
	 * @brief TUI detail mode color flag for a single 32 bit foreground color per tile. This enables use of 32 bit full colors with RGBA components.
	 */
	TUI_COLOR_FLAG_C32NBG = (1 << 12),
	/*!
	 * @brief TUI detail mode color flag for full batches of tiles without increased batch size for coordinate information. This is most optimal for rendering in situations where almost all tiles are updated every frame.
	 */
	TUI_LAYOUT_FLAG_FULL = (1 << 13),
	/*!
	 * @brief TUI detail mode color flag for rendering tiles as needed instead of every tile every frame. This is most optimal for rendering in situations where few tiles are updated every frame.
	 */
	TUI_LAYOUT_FLAG_SPARSE = (1 << 14)
} TuiDetailFlag;


/*! @name Detail Mode Flag Names
 *
 * Constant string names of each detali flag.
 *  @{ */
/*!
 * @brief String name of @ref TUI_GLYPH_FLAG_G8.
 */
extern const char* kTui_Glyph_Flag_G8_Name;
/*!
 * @brief String name of @ref TUI_GLYPH_FLAG_G16.
 */
extern const char* kTui_Glyph_Flag_G16_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C0.
 */
extern const char* kTui_Color_Flag_C0_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C4.
 */
extern const char* kTui_Color_Flag_C4_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C8.
 */
extern const char* kTui_Color_Flag_C8_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C8NBG.
 */
extern const char* kTui_Color_Flag_C8NBG_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C8NFG.
 */
extern const char* kTui_Color_Flag_C8NFG_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C24.
 */
extern const char* kTui_Color_Flag_C24_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C24NBG.
 */
extern const char* kTui_Color_Flag_C24NBG_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C24NFG.
 */
extern const char* kTui_Color_Flag_C24NFG_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C32.
 */
extern const char* kTui_Color_Flag_C32_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C32NBG.
 */
extern const char* kTui_Color_Flag_C32NBG_Name;
/*!
 * @brief String name of @ref TUI_COLOR_FLAG_C32NFG.
 */
extern const char* kTui_Color_Flag_C32NFG_Name;
/*!
 * @brief String name of @ref TUI_LAYOUT_FLAG_FULL.
 */
extern const char* kTui_Layout_Flag_Full_Name;
/*!
 * @brief String name of @ref TUI_LAYOUT_FLAG_SPARSE.
 */
extern const char* kTui_Layout_Flag_Sparse_Name;
/*! @} */


/*! @name Detail Mode Flag Function
 *
 * Functions for dealing with @ref TuiDetailFlag enum values.
 *  @{ */
/*!
 * @brief Determine if a @ref TuiDetailFlag enum is valid.
 *
 * @param detail_flag The @ref TuiDetailFlag to check.
 *
 * @returns The @ref TuiBoolean result. If detail_flag is a valid @ref TuiDetailFlag, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiDetailFlagIsValid(TuiDetailFlag detail_flag);
/*!
 * @brief Retrieve the string name associated with a @ref TuiDetailFlag enum.
 *
 * @param detail_flag The @ref TuiDetailFlag to get the name of.
 *
 * @returns The string name. @ref TUI_NULL is returned if cursor_mode is an invalid @ref TuiDetailFlag.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiDetailFlagToString(TuiDetailFlag detail_flag);
/*!
 * @brief Determine the @ref TuiDetailFlag enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The TuiDetailFlag. @ref TUI_DETAIL_FLAG_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiDetailFlag tuiStringToDetailFlag(const char* string);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard