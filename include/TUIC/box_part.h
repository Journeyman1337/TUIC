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
/*! \file box_part.h
 */
#ifndef TUIC_BOX_PART_H // header guard
#define TUIC_BOX_PART_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*!
 * @brief Parts of a @ref TuiBox.
 */
typedef enum TuiBoxPart
{
	/*!
	 * \brief The box part is invalid.
	 *
	 * This box part is returned when an error occurs, and is also used to specify that no box part is
	 * defined.
	 */
	TUI_BOX_PART_INVALID = 0,
	/*!
	 * \brief The left side of the @ref TuiBox.
	 */
	TUI_BOX_PART_LEFT_SIDE = 1,
	/*!
	 * \brief The top left corner of the @ref TuiBox.
	 */
	TUI_BOX_PART_TOP_LEFT_CORNER = 2,
	/*!
	 * \brief The top side of the @ref TuiBox.
	 */
	TUI_BOX_PART_TOP_SIDE = 3,
	/*!
	 * \brief The top right corner of the @ref TuiBox.
	 */
	TUI_BOX_PART_TOP_RIGHT_CORNER = 4,
	/*!
	 * \brief The top right side of the @ref TuiBox.
	 */
	TUI_BOX_PART_RIGHT_SIDE = 5,
	/*!
	 * \brief The bottom right corner of the @ref TuiBox.
	 */
	TUI_BOX_PART_BOTTOM_RIGHT_CORNER = 6,
	/*!
	 * \brief The bottom side of the @ref TuiBox.
	 */
	TUI_BOX_PART_BOTTOM_SIDE = 7,
	/*!
	 * \brief The bottom left corner of the @ref TuiBox.
	 */
	TUI_BOX_PART_BOTTOM_LEFT_CORNER = 8,
	/*!
	 * \brief The first valid box part value.
	 */
	TUI_BOX_PART_FIRST = TUI_BOX_PART_LEFT_SIDE,
	/*!
	 * \brief The last valid box part value.
	 */
	TUI_BOX_PART_LAST = TUI_BOX_PART_BOTTOM_LEFT_CORNER
} TuiBoxPart;

/*! @name Box Part Names
 *
 * Constant string names of each box part.
 *  @{ */
/*!
 * @brief String name of @ref TUI_BOX_PART_LEFT_SIDE.
 */
extern const char* kTui_Box_Part_Left_Side_Name;
/*!
 * @brief String name of @ref TUI_BOX_PART_TOP_LEFT_CORNER.
 */
extern const char* kTui_Box_Part_Top_Left_Corner_Name;
/*!
 * @brief String name of @ref TUI_BOX_PART_TOP_SIDE.
 */
extern const char* kTui_Box_Part_Top_Side_Name;
/*!
 * @brief String name of @ref TUI_BOX_PART_TOP_RIGHT_CORNER.
 */
extern const char* kTui_Box_Part_Top_Right_Corner_Name;
/*!
 * @brief String name of @ref TUI_BOX_PART_RIGHT_SIDE.
 */
extern const char* kTui_Box_Part_Right_Side_Name;
/*!
 * @brief String name of @ref TUI_BOX_PART_BOTTOM_RIGHT_CORNER.
 */
extern const char* kTui_Box_Part_Bottom_Right_Corner_Name;
/*!
 * @brief String name of @ref TUI_BOX_PART_BOTTOM_SIDE.
 */
extern const char* kTui_Box_Part_Bottom_Side_Name;
/*!
 * @brief String name of @ref TUI_BOX_PART_BOTTOM_LEFT_CORNER.
 */
extern const char* kTui_Box_Part_Bottom_Left_Corner_Name;
/*! @} */


/*! @name Box Part Functions
 *
 * Functions for dealing with @ref TuiBoxPart enum values.
 *  @{ */
 /*!
  * @brief Determine if a @ref TuiBoxPart enum is valid.
  *
  * @param box_part The @ref TuiBoxPart to check.
  *
  * @returns The @ref TuiBoolean result. If box_part is a valid @ref TuiBoxPart, it
  * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
  *
  * @errors This function can have no errors.
  *
  * @requirements This function can be called freely, even if TUIC is not currently initialized.
  *
  * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
  */
TuiBoolean tuiBoxPartIsValid(TuiBoxPart box_part);
/*!
 * @brief Retrieve the string name associated with a @ref TuiBoxPart enum.
 *
 * @param box_part The @ref TuiBoxPart to get the name of.
 *
 * @returns The string name. @ref TUI_NULL is returned if box_part is an invalid @ref TuiBoxPart.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiBoxPartToString(TuiBoxPart box_part);
/*!
 * @brief Determine the @ref TuiBoxPart enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The @ref TuiBoxPart. @ref TUI_BOX_PART_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoxPart tuiStringToBoxPart(const char* str);
/*! @} */


#ifdef __cplusplus // extern C guard
}
#endif
#endif // header guard