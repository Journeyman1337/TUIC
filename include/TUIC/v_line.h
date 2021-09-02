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
/*! \file v_line.h
 */
#ifndef TUIC_V_LINE_H //header guard
#define TUIC_V_LINE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>


/*! @name VLine Functions
 *
 * Functions for manipulating @ref TUiVLine.
 *  @{ */
/*!
 * @brief Create a @ref TuiVLine.
 *
 * @param x The x intercept of the line.
 * @param start_y The y position of the start point.
 * @param end_y The y position of the end point.
 *
 * @returns The created @ref TuiVLine.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiVLine tuiVLine(const int x, const int start_y, const int end_y);
/*!
 * @brief Get the starting point of a @ref TuiVLine.
 *
 * @param v_line THe @ref TuiVLine.
 *
 * @returns The starting @ref TuiPoint2.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiVLineGetStartPoint2(const TuiVLine v_line);
/*!
 * @brief Get the starting point of a @ref TuiVLine.
 *
 * @param v_line THe @ref TuiVLine.
 *
 * @returns The starting @ref TuiPoint2.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiVLineGetEndPoint2(const TuiVLine v_line);
/*!
 * @brief Get the @ref TuiLine of a @ref TuiVLine.
 *
 * @param v_line THe @ref TuiVLine.
 *
 * @returns The @ref TuiLine.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLine tuiVLineGetLine(const TuiVLine v_line);
/*!
 * @brief Get the length of a @ref TuiVLine.
 *
 * @param v_line The @ref TuiVLine.
 *
 * @returns The length of the line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiVLineGetLength(const TuiVLine v_line);
/*!
 * @brief Get if two @ref TuiVLine contains a @ref TuiPoint2.
 *
 * @param v_line The @ref TuiLine.
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
TuiBoolean tuiVLineContainsPoint(const TuiVLine v_line, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiVLine contains a @ref TuiLine.
 *
 * @param v_line The @ref TuiVLine.
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
TuiBoolean tuiVLineContainsLine(const TuiLine line, const TuiVLine v_line);
/*!
 * @brief Get if a @ref TuiVLine intersects a @ref TuiLine.
 *
 * @param v_line The @ref TuiVLine.
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
TuiBoolean tuiVLineIntersectsLine(const TuiVLine v_line, const TuiLine line);
/*!
 * @brief Get if a @ref TuiVLine intersects a @ref TuiHLine.
 *
 * @param v_line The @ref TuiVLine.
 * @param h_line The @ref TuiHLine.
 *
 * @returns If the lines intersect.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiVLineIntersectsHLine(const TuiVLine v_line, const TuiHLine h_line);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard