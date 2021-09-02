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
/*! \file h_line.h
 */
#ifndef TUIC_H_LINE_H //header guard
#define TUIC_H_LINE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>


/*! @name HLine Functions
 *
 * Functions for manipulating @ref TUiHLine.
 *  @{ */
/*!
 * @brief Create a @ref TuiHLine.
 *
 * @param start_x The x position of the start point.
 * @param end_x The x position of the end point.
 * @param y The y intercept of the line.
 *
 * @returns The created @ref TuiHLine.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiHLine tuiHLine(const int start_x, const int end_x, const int y);
/*!
 * @brief Get the starting point of a @ref TuiHLine.
 *
 * @param h_line THe @ref TuiHLine.
 *
 * @returns The starting @ref TuiPoint2.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiHLineGetStartPoint2(const TuiHLine h_line);
/*!
 * @brief Get the starting point of a @ref TuiHLine.
 *
 * @param h_line THe @ref TuiHLine.
 *
 * @returns The starting @ref TuiPoint2.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiHLineGetEndPoint2(const TuiHLine h_line);
/*!
 * @brief Get the @ref TuiLine of a @ref TuiHLine.
 *
 * @param h_line THe @ref TuiHLine.
 *
 * @returns The @ref TuiLine.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLine tuiHLineGetLine(const TuiHLine h_line);
/*!
 * @brief Get the length of a @ref TuiHLine.
 *
 * @param h_line The @ref TuiHLine.
 *
 * @returns The length of the line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiHLineGetLength(const TuiHLine h_line);
/*!
 * @brief Get if two @ref TuiHLine contains a @ref TuiPoint2.
 *
 * @param h_line The @ref TuiLine.
 * @param point2 The @ref TuiPoint2.
 *
 * @returns If the line contains the point.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiHLineContainsPoint(const TuiHLine h_line, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiHLine contains a @ref TuiLine.
 *
 * @param h_line The @ref TuiHLine.
 * @param line The @ref TuiLine to check for.
 *
 * @returns If the line contains the line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiHLineContainsLine(const TuiLine line, const TuiHLine h_line);
/*!
 * @brief Get if a @ref TuiHLine intersects a @ref TuiLine.
 *
 * @param h_line The @ref TuiHLine.
 * @param line The @ref TuiLine.
 *
 * @returns If the lines intersect.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiHLineIntersectsLine(const TuiHLine h_line, const TuiLine line);
/*!
 * @brief Get if a @ref TuiHLine intersects a @ref TuiVLine.
 *
 * @param h_line The @ref TuiHLine.
 * @param v_line The @ref TuiVLine.
 *
 * @returns If the lines intersect.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiHLineIntersectsVLine(const TuiHLine h_line, const TuiVLine v_line);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard