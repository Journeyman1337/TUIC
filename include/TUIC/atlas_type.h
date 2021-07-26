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
/*! \file atlas_type.h
 */
#ifndef TUIC_ATLAS_TYPE_H //header guard
#define TUIC_ATLAS_TYPE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*! @name Atlas types
 *  @{ */
/*!
* @brief How the glyph locations within a @ref TuiAtlas are stored. 
*/
typedef enum TuiAtlasType
{
	/*!
	 * \brief The atlas type is invalid.
	 *
	 * This atlas type is returned when an error occurs, and is also used to specify that no atlas type is
	 * defined.
	 */
	TUI_ATLAS_INVALID = 0,
	/*!
	 * \brief The atlas uses an STPQ texture coordinate array to store the locations of each glyph.
	 * 
	 * The STPQ coordinates for each glyph are in order of glyph index, with the first four
	 * elemeents in the array being the STPQ coordinates of the glyph of index 0.
	 */
	TUI_ATLAS_COORDS = 1,
	/*!
	 * \brief The glyphs are layed out in a grid pattern where each glyph has the same pixel width
	 * and pixel height.
	 * 
	 * Glyphs are indexed from left to right, top to bottom, with the index of 0 being the glyph in
	 * the upper right corner of the texture.
	 */
	TUI_ATLAS_GRID = 2,
	/*!
	 * \brief The first atlas type value.
	 */
	TUI_ATLAS_FIRST = TUI_ATLAS_COORDS,
	/*!
	 * \brief The last valid atlas type value.
	 */
	TUI_ATLAS_LAST = TUI_ATLAS_GRID
} TuiAtlasType;
/*! @} */


/*! @name @ref TuiAtlasType names
 *
 * Constant string names of each atlas type.
 *  @{ */
/*!
 * @brief String name of TUI_ATLAS_COORDS.
 */
extern const char* kTui_Atlas_Coords_Name;
/*!
 * @brief String name of TUI_ATLAS_GRID.
 */
extern const char* kTui_Atlas_Grid_Name;
/*! @} */


/*! @name TuiAtlasType functions
 *
 * Functions for dealing with @ref TuiAtlasType enum values.
 *  @{ */
/*!
 * @brief Determine if a @ref TuiAtlasType enum is valid.
 * 
 * @param atlas_type The @ref TuiAtlasType to check.
 * 
 * @returns The @ref TuiBoolean result. If it atlas_type is a valid @ref TuiAtlasType, it
 * returns @ref TuiTrue. Otherwise, it returns @ref TuiFalse.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiAtlasTypeIsValid(TuiAtlasType atlas_type);
/*!
 * @brief Retrieve the string name associated with a @ref TuiAtlasType enum.
 *
 * @param atlas_type The TuiAtlasType to get the name of.
 *
 * @returns The string name. NULL is returned if atlas_types is an invalid @ref TuiAtlasType.
 * 
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiAtlasTypeToString(TuiAtlasType atlas_type);
/*!
 * @brief Determine the TuiAtlasType enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The TuiAtlasType. @ref TUI_ATLAS_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiAtlasType tuiStringToAtlasType(const char* str);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard