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
/*! \file enums.h
 */
#ifndef TUIC_CONSTANTS_H //header guard
#define TUIC_CONSTANTS_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
/*! @brief These constants are meant to be used for boolean values when using TUIC.
 */
enum TuiBoolean
{
	/*!
	* \brief Equivalent to the boolean value of true.
	*/
	TUI_TRUE = 1,
	/*!
	* \brief Equivalent to the boolean value of false.
	*/
	TUI_FALSE = 0,
};
/*! @brief These flags are combined to create the various detail rendering modes supported by the TUIC library. There are three categories of flags: glyph flags, color flags, and layout flags. Combining one of each results in a detail mode.
 */
enum TuiDetailFlag
{
	/*!
	 * @brief TUI detail mode glyph flag for 8 bit glyphs.
	 *
	 * This supports up to 256 unique glyphs. This size is optimal if you only want to use code page 437 for rendering.
	 */
	TUI_GLYPH_FLAG_G8 =			(1 << 0),
	/*!
	 * @brief Detail mode glyph flag for 16 bit glyphs.
	 *
	 * This supports up to 65536 unique glyphs.
	 */
	TUI_GLYPH_FLAG_G16 =		(1 << 1),
	/*!
	 * @brief TUI detail mode flag for no colors.
	 *
	 * This shrinks the byte size per tile by not requiring any information about foreground and background colors.
	 */
	TUI_COLOR_FLAG_C0 =			(1 << 2),
	/*!
	 * @brief TUI detail mode color flag for 4 bit colors.
	 *
	 * This enables use of a 16 color palette for colors.
	 */
	TUI_COLOR_FLAG_C4 =			(1 << 3),
	/*!
	 * @brief TUI detail mode color flag for 8 bit colors.
	 *
	 * This enables use of a 256 color palette for colors.
	 */
	TUI_COLOR_FLAG_C8 =			(1 << 4),
	/*!
	 * @brief TUI detail mode color flag for 8 bit colors with no foreground color.
	 *
	 * This enables use of a 256 color palette for colors.
	 */
	TUI_COLOR_FLAG_C8NFG =		(1 << 5),
	/*!
	 * @brief TUI detail mode color flag for 8 bit colors with no background color.
	 *
	 * This enables use of a 256 color palette for colors.
	 */
	TUI_COLOR_FLAG_C8NBG =		(1 << 6),
	/*!
	 * @brief TUI detail mode color flag for 24 bit colors.
	 *
	 * This enables use of 24 bit full colors with RGB components.
	 */
	TUI_COLOR_FLAG_C24 =		(1 << 7),
	/*!
	 * @brief TUI detail mode color flag for a single 24 bit background color per tile.
	 *
	 * This enables use of 24 bit full colors with RGB components.
	 */
	TUI_COLOR_FLAG_C24NFG =		(1 << 8),
	/*!
	 * @brief TUI detail mode color flag for a single 24 bit foreground color per tile.
	 *
	 * This enables use of 24 bit full colors with RGB components.
	 */
	TUI_COLOR_FLAG_C24NBG =		(1 << 9),
	/*!
	 * @brief TUI detail mode color flag for 32 bit colors.
	 *
	 * This enables use of 32 bit full colors with RGBA components.
	 */
	TUI_COLOR_FLAG_C32 =		(1 << 10),
	/*!
	 * @brief TUI detail mode color flag for a single 32 bit background color per tile.
	 *
	 * This enables use of 32 bit full colors with RGBA components.
	 */
	TUI_COLOR_FLAG_C32NFG =		(1 << 11),
	/*!
	 * @brief TUI detail mode color flag for a single 32 bit foreground color per tile.
	 *
	 * This enables use of 32 bit full colors with RGBA components.
	 */
	TUI_COLOR_FLAG_C32NBG =		(1 << 12),
	/*!
	 * @brief TUI detail mode color flag for full batches of tiles for entire panels of certain dimensions.
	 *
	 * Since data latency is the largest performance factor in TUI rendering, full batches are wasteful when updating only a few tiles per frame. Full batches are only worth using if you require a huge amount of tile changes at a frequent rate, so that the extra bytes per tile that sparse batches require would make them slower.
	 */
	TUI_LAYOUT_FLAG_FULL =		(1 << 13),
	/*!
	 * @brief TUI detail mode color flag for rendering tiles as needed instead of every tile every frame.
	 *
	 * This enables sparse batching of tile data. This means that instead of rendering one glyph per tile, only the requested tiles at given coordinates are rendered. Sparse layout batches require at 2  extra bytes per tile compared to full layout batches, plus one more byte for each x or y batch tile dimension larger than 256 tiles. Sparse batches are more performant than full batches in most situations, and work well along with a TuiPanel to store the pixels of unchanged tiles from previous draws.
	 */
	TUI_LAYOUT_FLAG_SPARSE =	(1 << 14)
};
/*! @name Detail Mode Flag Names
 * These are the const string names of @ref TuiDetailFlag enum values.
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
/*! @brief Detail modes are the different methods of rendering TUI panels that TUIC supports. These macros are made up of combined detail flag macros. Each detail mode is made up of the combination of exactly one glyph flag, one color flag, and one layout flag.
 */
enum TuiDetailMode
{
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with no colors.
	 */
	TUI_DETAIL_G8_C0_FULL =				(TUI_GLYPH_FLAG_G8 		| TUI_COLOR_FLAG_C0			| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with 4 bit colors (16 color palette).
	 */
	TUI_DETAIL_G8_C4_FULL =				(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C4			| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with 8 bit colors (256 color palette).
	 */
	TUI_DETAIL_G8_C8_FULL =				(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8			| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with an 8 bit foreground color (256 color palette).
	 */
	TUI_DETAIL_G8_C8NBG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8NBG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with an 8 bit background color (256 color palette).
	 */
	TUI_DETAIL_G8_C8NFG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8NFG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with an 24 bit colors (RGB full color).
	 */
	TUI_DETAIL_G8_C24_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with a 24 bit foreground color (RGB full color).
	 */
	TUI_DETAIL_G8_C24NBG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24NBG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with a 24 bit background color (RGB full color).
	 */
	TUI_DETAIL_G8_C24NFG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24NFG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with an 32 bit colors (RGBA full color).
	 */
	TUI_DETAIL_G8_C32_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with a 32 bit foreground color (RGBA full color).
	 */
	TUI_DETAIL_G8_C32NBG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32NBG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 8 bit glyph batches with a 32 bit background color (RGBA full color).
	 */
	TUI_DETAIL_G8_C32NFG_FULL =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C32NFG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with no colors.
	 */
	TUI_DETAIL_G16_C0_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C0			| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with 4 bit colors (16 color palette).
	 */
	TUI_DETAIL_G16_C4_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C4			| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with 8 bit colors (256 color palette).
	 */
	TUI_DETAIL_G16_C8_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8			| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with an 8 bit foreground color (256 color palette).
	 */
	TUI_DETAIL_G16_C8NBG_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8NBG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with an 8 bit background color (256 color palette).
	 */
	TUI_DETAIL_G16_C8NFG_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8NFG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with an 24 bit colors (RGB full color).
	 */
	TUI_DETAIL_G16_C24_FULL =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with a 24 bit foreground color (RGB full color).
	 */
	TUI_DETAIL_G16_C24NBG_FULL =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24NBG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with a 24 bit background color (RGB full color).
	 */
	TUI_DETAIL_G16_C24NFG_FULL =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24NFG		| TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with a 32 bit foreground color (RGBA full color).
	 */
	TUI_DETAIL_G16_C32_FULL =			(TUI_GLYPH_FLAG_G16| TUI_COLOR_FLAG_C32 | TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with a 32 bit foreground color (RGBA full color).
	 */
	TUI_DETAIL_G16_C32NBG_FULL =		(TUI_GLYPH_FLAG_G16 | TUI_COLOR_FLAG_C32NBG | TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for full 16 bit glyph batches with a 32 bit background color (RGBA full color).
	 */
	TUI_DETAIL_G16_C32NFG_FULL =		(TUI_GLYPH_FLAG_G16 | TUI_COLOR_FLAG_C32NFG | TUI_LAYOUT_FLAG_FULL),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with no colors.
	 */
	TUI_DETAIL_G8_C0_SPARSE =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C0			| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with 4 bit colors (16 color palette).
	 */
	TUI_DETAIL_G8_C4_SPARSE =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C4			| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with 8 bit colors (256 color palette).
	 */
	TUI_DETAIL_G8_C8_SPARSE =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8			| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with an 8 bit foreground color (256 color palette).
	 */
	TUI_DETAIL_G8_C8NBG_SPARSE =		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8NBG		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with an 8 bit background color (256 color palette).
	 */
	TUI_DETAIL_G8_C8NFG_SPARSE =		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C8NFG		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with an 24 bit colors (RGB full color).
	 */
	TUI_DETAIL_G8_C24_SPARSE =			(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with a 24 bit foreground color (RGB full color).
	 */
	TUI_DETAIL_G8_C24NBG_SPARSE =		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24NBG		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with a 24 bit background color (RGB full color).
	 */
	TUI_DETAIL_G8_C24NFG_SPARSE =		(TUI_GLYPH_FLAG_G8		| TUI_COLOR_FLAG_C24NFG		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with an 32 bit colors (RGBA full color).
	 */
	TUI_DETAIL_G8_C32_SPARSE = 			(TUI_GLYPH_FLAG_G8 | TUI_COLOR_FLAG_C32 | TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with a 32 bit foreground color (RGBA full color).
	 */
	TUI_DETAIL_G8_C32NBG_SPARSE = 		(TUI_GLYPH_FLAG_G8 | TUI_COLOR_FLAG_C32NBG | TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 8 bit glyph batches with a 32 bit background color (RGBA full color).
	 */
	TUI_DETAIL_G8_C32NFG_SPARSE = 		(TUI_GLYPH_FLAG_G8 | TUI_COLOR_FLAG_C32NFG | TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with no colors.
	 */
	TUI_DETAIL_G16_C0_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C0			| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with 4 bit colors (16 color palette).
	 */
	TUI_DETAIL_G16_C4_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C4			| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with 8 bit colors (256 color palette).
	 */
	TUI_DETAIL_G16_C8_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8			| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with an 8 bit foreground color (256 color palette).
	 */
	TUI_DETAIL_G16_C8NBG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8NBG		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with an 8 bit background color (256 color palette).
	 */
	TUI_DETAIL_G16_C8NFG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C8NFG		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with an 24 bit colors (RGB full color).
	 */
	TUI_DETAIL_G16_C24_SPARSE =			(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with a 24 bit foreground color (RGB full color).
	 */
	TUI_DETAIL_G16_C24NBG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24NBG		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with a 24 bit background color (RGB full color).
	 */
	TUI_DETAIL_G16_C24NFG_SPARSE =		(TUI_GLYPH_FLAG_G16		| TUI_COLOR_FLAG_C24NFG		| TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with an 24 bit colors (RGBA full color).
	 */
	TUI_DETAIL_G16_C32_SPARSE =			(TUI_GLYPH_FLAG_G16 | TUI_COLOR_FLAG_C32 | TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with a 32 bit foreground color (RGBA full color).
	 */
	TUI_DETAIL_G16_C32NBG_SPARSE =		(TUI_GLYPH_FLAG_G16 | TUI_COLOR_FLAG_C32NBG | TUI_LAYOUT_FLAG_SPARSE),
	/*!
	 * @brief TUI detail mode for sparse 16 bit glyph batches with a 32 bit background color (RGBA full color).
	 */
	TUI_DETAIL_G16_C32NFG_SPARSE =		(TUI_GLYPH_FLAG_G16 | TUI_COLOR_FLAG_C32NFG | TUI_LAYOUT_FLAG_SPARSE),
};
/*! @name Detail Mode Constant Tile Byte Sizes
 * These constants act as constants containing the size of a single tile in bytes for each supported detail mode.
 *  @{ */
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C0.
 */
extern const size_t kTui_Detail_G8_C0_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C4.
 */
extern const size_t kTui_Detail_G8_C4_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C8.
 */
extern const size_t kTui_Detail_G8_C8_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C8NBG.
 */
extern const size_t kTui_Detail_G8_C8NBG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C8NFG.
 */
extern const size_t kTui_Detail_G8_C8NFG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C24.
 */
extern const size_t kTui_Detail_G8_C24_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C24NBG.
 */
extern const size_t kTui_Detail_G8_C24NBG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C24NFG.
 */
extern const size_t kTui_Detail_G8_C24NFG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C32.
 */
extern const size_t kTui_Detail_G8_C32_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C32NBG.
 */
extern const size_t kTui_Detail_G8_C32NBG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G8 and color flag @ref TUI_COLOR_FLAG_C32NFG.
 */
extern const size_t kTui_Detail_G8_C32NFG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C0.
 */
extern const size_t kTui_Detail_G16_C0_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C4.
 */
extern const size_t kTui_Detail_G16_C4_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C8.
 */
extern const size_t kTui_Detail_G16_C8_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C8NBG.
 */
extern const size_t kTui_Detail_G16_C8NBG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C8NFG.
 */
extern const size_t kTui_Detail_G16_C8NFG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C24.
 */
extern const size_t kTui_Detail_G16_C24_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C24NBG.
 */
extern const size_t kTui_Detail_G16_C24NBG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C24NFG.
 */
extern const size_t kTui_Detail_G16_C24NFG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C32.
 */
extern const size_t kTui_Detail_G16_C32_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C32NBG.
 */
extern const size_t kTui_Detail_G16_C32NBG_Size;
/*!
 * @brief Tile byte size of detail modes with glyph flag @ref TUI_GLYPH_FLAG_G16 and color flag @ref TUI_COLOR_FLAG_C32NFG.
 */
extern const size_t kTui_Detail_G16_C32NFG_Size;
/*! @} */
/*! @name Detail Mode Names
 * These are const string names of @ref TuiDetailMode enum values.
 *  @{ */
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C0_FULL.
 */
extern const char* kTui_Detail_G8_C0_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C4_FULL.
 */
extern const char* kTui_Detail_G8_C4_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C8_FULL.
 */
extern const char* kTui_Detail_G8_C8_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C8NBG_FULL.
 */
extern const char* kTui_Detail_G8_C8NBG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C8NFG_FULL.
 */
extern const char* kTui_Detail_G8_C8NFG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C24_FULL.
 */
extern const char* kTui_Detail_G8_C24_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C24NBG_FULL.
 */
extern const char* kTui_Detail_G8_C24NBG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C24NFG_FULL.
 */
extern const char* kTui_Detail_G8_C24NFG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C32_FULL.
 */
extern const char* kTui_Detail_G8_C32_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C32NBG_FULL.
 */
extern const char* kTui_Detail_G8_C32NBG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C32NFG_FULL.
 */
extern const char* kTui_Detail_G8_C32NFG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C0_FULL.
 */
extern const char* kTui_Detail_G16_C0_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C4_FULL.
 */
extern const char* kTui_Detail_G16_C4_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C8_FULL.
 */
extern const char* kTui_Detail_G16_C8_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C8NBG_FULL.
 */
extern const char* kTui_Detail_G16_C8NBG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C8NFG_FULL.
 */
extern const char* kTui_Detail_G16_C8NFG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C24_FULL.
 */
extern const char* kTui_Detail_G16_C24_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C24NBG_FULL.
 */
extern const char* kTui_Detail_G16_C24NBG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C24NFG_FULL.
 */
extern const char* kTui_Detail_G16_C24NFG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C32_FULL.
 */
extern const char* kTui_Detail_G16_C32_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C32NBG_FULL.
 */
extern const char* kTui_Detail_G16_C32NBG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C32NFG_FULL.
 */
extern const char* kTui_Detail_G16_C32NFG_Full_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C0_SPARSE.
 */
extern const char* kTui_Detail_G8_C0_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C4_SPARSE.
 */
extern const char* kTui_Detail_G8_C4_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C8_SPARSE.
 */
extern const char* kTui_Detail_G8_C8_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C8NBG_SPARSE.
 */
extern const char* kTui_Detail_G8_C8NBG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C8NFG_SPARSE.
 */
extern const char* kTui_Detail_G8_C8NFG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C24_SPARSE.
 */
extern const char* kTui_Detail_G8_C24_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C24NBG_SPARSE.
 */
extern const char* kTui_Detail_G8_C24NBG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C24NFG_SPARSE.
 */
extern const char* kTui_Detail_G8_C24NFG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C32_SPARSE.
 */
extern const char* kTui_Detail_G8_C32_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C32NBG_SPARSE.
 */
extern const char* kTui_Detail_G8_C32NBG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G8_C32NFG_SPARSE.
 */
extern const char* kTui_Detail_G8_C32NFG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C0_SPARSE.
 */
extern const char* kTui_Detail_G16_C0_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C4_SPARSE.
 */
extern const char* kTui_Detail_G16_C4_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C8_SPARSE.
 */
extern const char* kTui_Detail_G16_C8_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C8NBG_SPARSE.
 */
extern const char* kTui_Detail_G16_C8NBG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C8NFG_SPARSE.
 */
extern const char* kTui_Detail_G16_C8NFG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C24_SPARSE.
 */
extern const char* kTui_Detail_G16_C24_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C24NBG_SPARSE.
 */
extern const char* kTui_Detail_G16_C24NBG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C24NFG_SPARSE.
 */
extern const char* kTui_Detail_G16_C24NFG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C32_SPARSE.
 */
extern const char* kTui_Detail_G16_C32_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C32NBG_SPARSE.
 */
extern const char* kTui_Detail_G16_C32NBG_Sparse_Name;
/*!
 * @brief String name of @ref TUI_DETAIL_G16_C32NFG_SPARSE.
 */
extern const char* kTui_Detail_G16_C32NFG_Sparse_Name;
/* @) */
/*! @brief Atlas Type
 * An atlas type describes the way a @ref TuiGlyphAtlas organizes its sub-images.
 */
enum TuiAtlasType
{
	/*!
	 * \brief Glyph atlas mode which uses STPQ pixel coordinates (left, right, up, down) surrounding each glyph to define their bounds.
	 */
	TUI_ATLAS_COORDS = 0,
	 /*!
	  * \brief Glyph atlas mode which uses a fixed grid of glyphs.
	  */
	TUI_ATLAS_GRID = 1,
};
/*! @name Atlas Type Names
 * These are const string names of @ref TuiAtlasType enum values.
 *  @{ */
/*!
 * @brief String name of @ref TUI_ATLAS_COORDS.
 */
extern const char* kTui_Atlas_COORDS_Name;
/*!
 * @brief String name of @ref TUI_ATLAS_GRID.
 */
extern const char* kTui_Atlas_GRID_Name;
/*! @} */

/*! @brief Blend Mode Enums
 */
enum TuiBlendMode
{
/*!
 * \brief Blend mode that uses no foreground and background colors.
 * 
 * This blend mode only works for panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_NORMAL = 0,
/*!
 * \brief Blend mode that blends the glyph foreground color with the red color component of the glyph texture.
 *
 * This blend mode does not work with panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_FG_RED = 1,
/*!
 * \brief Blend mode that blends the glyph foreground color with the green color component of the glyph texture.
 *
 * This blend mode does not work with panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_FG_GREEN = 2,
/*!
 * \brief Blend mode that blends the glyph foreground color with the blue color component of the glyph texture.
 *
 * This blend mode does not work with panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_FG_BLUE = 3,
/*!
 * \brief Blend mode that blends the glyph foreground color with the alpha color component of the glyph texture.
 *
 * This blend mode does not work with panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_FG_ALPHA = 4,
/*!
 * \brief Blend mode that blends the glyph background color with the red color component of the glyph texture.
 *
 * This blend mode does not work with panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_BG_RED = 5,
/*!
 * \brief Blend mode that blends the glyph background color with the green color component of the glyph texture.
 *
 * This blend mode does not work with panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_BG_GREEN = 6,
/*!
 * \brief Blend mode that blends the glyph background color with the blue color component of the glyph texture.
 * 
 * This blend mode does not work with panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_BG_BLUE = 7,
/*!
 * \brief Blend mode that blends the glyph background color with the alpha color component of the glyph texture.
 *
 * This blend mode does not work with panels using detail modes with @ref TUI_COLOR_FLAG_C0.
 */
	TUI_BLEND_BG_ALPHA = 8,
};
/*! @name Blend Mode Names
 *  @{ */
/*!
 * @brief String name of @ref TUI_BLEND_NORMAL.
 */
extern const char* kTui_Blend_NORMAL_Name;
/*!
 * @brief String name of @ref TUI_BLEND_FG_RED.
 */
extern const char* kTui_Blend_FG_RED_Name;
/*!
 * @brief String name of @ref TUI_BLEND_FG_GREEN.
 */
extern const char* kTui_Blend_FG_GREEN_Name;
/*!
 * @brief String name of @ref TUI_BLEND_FG_BLUE.
 */
extern const char* kTui_Blend_FG_BLUE_Name;
/*!
 * @brief String name of @ref TUI_BLEND_FG_ALPHA.
 */
extern const char* kTui_Blend_FG_ALPHA_Name;
/*!
 * @brief String name of @ref TUI_BLEND_BG_RED.
 */
extern const char* kTui_Blend_BG_RED_Name;
/*!
 * @brief String name of @ref TUI_BLEND_BG_GREEN.
 */
extern const char* kTui_Blend_BG_GREEN_Name;
/*!
 * @brief String name of @ref TUI_BLEND_BG_BLUE.
 */
extern const char* kTui_Blend_BG_BLUE_Name;
/*!
 * @brief String name of @ref TUI_BLEND_BG_ALPHA.
 */
extern const char* kTui_Blend_BG_ALPHA_Name;

enum TuiFilterMode
{

	TUI_FILTER_POINT = 1,

	TUI_FILTER_BILINEAR = 2
};

extern const char* kTui_Filter_Point_Name;

extern const char* kTui_Filter_Bilinear_Name;
/*! @} */
/*! @name Enum Manipulation Functions
 *  @{ */
 /*!
  * @brief Get the glyph @ref TuiDetailFlag of a @ref TuiDetailMode.
  *
  * @param detail_mode The detail mode.
  *
  * @returns The glyph flag.
  */
int tuiDetailGetGlyphFlag(int detail_mode);
/*!
 * @brief Get the color flag of a @ref TuiDetailMode.
 *
 * @param detail_mode The detail mode.
 *
 * @returns The color flag.
 */
int tuiDetailGetColorFlag(int detail_mode);
/*!
 * @brief Get the layout @ref TuiDetailFlag of a @ref TuiDetailMode.
 *
 * @param detail_mode The detail mode.
 *
 * @returns The layout flag.
 */
int tuiDetailGetLayoutFlag(int detail_mode);
/*!
 * @brief Get the base byte size of @ref TuiDetailMode with the given glyph @ref TuiDetailFlag and color @ref TuiDetailFlag.
 *
 * @param glyph_flag The glyph flag.
 * @param color_flag The color flag.
 *
 * @returns The base byte size.
 */
size_t tuiDetailGetTileByteSize(int glyph_flag, int color_flag);
/*!
 * @brief Get if a @ref TuiDetailMode requires a color palette.
 *
 * @param detail_mode The detail mode.
 *
 * @returns If it requires a color palette.
 */
int tuiDetailHasPalette(int detail_mode);
/*!
 * @brief Get if a @ref TuiDetailMode is valid.
 *
 * @param detail_mode The detail mode.
 *
 * @returns If it is valid.
 */
int tuiDetailIsValid(int detail_mode);
/*!
 * @brief Get if a @ref TuiDetailMode contains the given @ref TuiDetailFlag.
 *
 * @param detail_mode The TuiDetalMode.
 * @param flag The @ref TuiDetailFlag.
 *
 * @returns If it contains the flag.
 */
int tuiDetailHasFlag(int detail_mode, int detail_flag);
/*!
 * @brief Get if a @ref TuiBlendMode is valid.
 *
 * @param detail_mode The @ref TuiDetailMode.
 *
 * @returns If it is valid.
 */
int tuiBlendIsValid(int blend_mode);
/*!
 * @brief Get if a @ref TuiAtlasType is valid.
 *
 * @param texture_format The @ref TuiAtlasType.
 *
 * @returns If it is valid.
 */
int tuiAtlasTypeIsValid(int atlas_type);
/*!
 * @brief Get if a @ref TuiDetailFlag is valid.
 *
 * @param detail_mode The @ref TuiDetailFlag.
 *
 * @returns If it is valid.
 */
int tuiDetailFlagIsValid(int detail_flag);

int tuiFilterModeIsValid(int filter_mode);
/*!
 * @brief Get if a @ref TuiBlendMode is compatible with a @ref TuiDetailMode.
 *
 * @param detail_mode The @ref TuiDetailMode.
 * @param blend_mode The @ref TuiBlendMode.
 *
 * @returns If they are compatible.
 */
int tuiModesAreCompatible(int detail_mode, int blend_mode);
/*!
 * @brief Get string name of a @ref TuiDetailFlag.
 *
 * @param detail_mode The @ref TuiDetailFlag.
 *
 * @returns The string name.
 */
const char* tuiDetailFlagToString(int detail_flag);
/*!
 * @brief Get a @ref TuiDetailFlag from a string name.
 *
 * @param string The string name.
 *
 * @returns The @ref TuiDetailFlag.
 */
int tuiStringToDetailFlag(const char* string);
/*!
 * @brief Get string name of a @ref TuiDetailMode.
 *
 * @param detail_mode The @ref TuiDetailMode.
 *
 * @returns The string name.
 */
const char* tuiDetailModeToString(int detail_mode);
/*!
 * @brief Get a @ref TuiDetailMode from a string name.
 *
 * @param string The string name.
 *
 * @returns The @ref TuiDetailMode.
 */
int tuiStringToDetailMode(const char* string);
/*!
 * @brief Get string name of a @ref TuiBlendMode.
 *
 * @param detail_mode The @ref TuiBlendMode.
 *
 * @returns The string name.
 */
const char* tuiBlendModeToString(int blend_mode);
/*!
 * @brief Get a @ref TuiBlendMode from a string name.
 *
 * @param string The string name.
 *
 * @returns The @ref TuiBlendMode.
 */
int tuiStringToBlendMode(const char* string);
/*!
 * @brief Get string name of an @ref TuiAtlasType.
 *
 * @param detail_mode The @ref TuiAtlasType.
 *
 * @returns The string name.
 */
const char* tuiAtlasTypeToString(int atlas_type);
/*!
 * @brief Get a @ref TuiAtlasType from a string name.
 *
 * @param string The string name.
 *
 * @returns The atlas type.
 */
int tuiStringToAtlasType(const char* string);

const char* tuiFilterModeToString(int filter_mode);

int tuiStringToFilterMode(const char* string);
/*! @} */
#ifdef __cplusplus //extern C guard
 }
#endif
#endif //header guard