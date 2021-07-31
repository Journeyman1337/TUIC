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
/*! \file filter_mode.h
 */
#ifndef TUIC_FILTER_MODE_H //header guard
#define TUIC_FILTER_MODE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*! @name Filter modes
 *  @{ */
/*!
 * @brief The filter mode used for rendering a texture or framebuffer.
 */
typedef enum TuiFilterMode
{
	/*!
	 * \brief The filter mode is invalid.
	 *
	 * This filter mode is returned when an error occurs, and is also used to specify that no filter mode is
	 * defined.
	 */
	TUI_FILTER_INVALID = 0,
	/*!
	 * @brief Filter mode with no filtering.
	 */
	TUI_FILTER_POINT = 1,
	/*!
	 * @brief Filter mode with bilinear color interpolation.
	 */
	TUI_FILTER_BILINEAR = 2
} TuiFilterMode;
/*! @} */


/*! @name Filter Mode Names
 *  These are const string names of @ref TuiFilterMode enum values.
 *  @{ */
/*!
 * @brief String name of @ref TUI_FILTER_POINT.
 */
extern const char* kTui_Filter_Point_Name;
/*!
 * @brief String name of @ref TUI_FILTER_BILINEAR.
 */
extern const char* kTui_Filter_Bilinear_Name;
/* @) */


/*! @name TuiFilterMode functions
 *
 * Functions for dealing with @ref TuiFilterMode enum values.
 *  @{ */
/*!
 * @brief Determine if a @ref TuiFilterMode enum is valid.
 *
 * @param filter_mode The @ref TuiFilterMode to check.
 *
 * @returns The @ref TuiBoolean result. If filter_mode is a valid @ref TuiFilterMode, it
 * returns @ref TuiTrue. Otherwise, it returns @ref TuiFalse.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiFilterModeIsValid(TuiFilterMode filter_mode);
/*!
 * @brief Retrieve the string name associated with a @ref TuiFilterMode enum.
 *
 * @param filter_mode The @ref TuiFilterMode to get the name of.
 *
 * @returns The string name. NULL is returned if filter_mode is an invalid @ref TuiFilterMode.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiFilterModeToString(TuiFilterMode filter_mode);
/*!
 * @brief Determine the @ref TuiFilterMode enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The @ref TuiFilterMode. @ref TUI_FILTER_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiFilterMode tuiStringToFilterMode(const char* str);
/*! @} */

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard