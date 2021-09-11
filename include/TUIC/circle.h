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
/*! \file circle.h
 */
#ifndef TUIC_CIRCLE_H //header guard
#define TUIC_CIRCLE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>


/*! @name 2D Circle Functions
 *
 * Functions for manipulating @ref TuiCircle.
 *  @{ */
/*!
 * @brief Create a @ref TuiCircle.
 * 
 * @param center_x The x position of one of the circle center point.
 * @param center_y The y position of one of the circle center point.
 * @param radius The radius of the circle.
 *
 * @returns The created @ref TuiCircle.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCircle tuiCircle(const int center_x, const int center_y, const float radius);
/*!
 * @brief Get the center @ref TuiPoint2 of a @ref TuiCircle.
 *
 * @param circle The @ref TuiCircle.
 *
 * @returns The center @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCircleGetCenterPoint2(const TuiCircle circle);
/*!
 * @brief Get the topmost @ref TuiPoint2 of a @ref TuiCircle.
 *
 * @param circle The @ref TuiCircle.
 *
 * @returns The topmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCircleGetTopPoint2(const TuiCircle circle);
/*!
 * @brief Get the leftmost @ref TuiPoint2 of a @ref TuiCircle.
 *
 * @param circle The @ref TuiCircle.
 *
 * @returns The leftmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCircleGetLeftPoint2(const TuiCircle circle);
/*!
 * @brief Get the bottomost @ref TuiPoint2 of a @ref TuiCircle.
 *
 * @param circle The @ref TuiCircle.
 *
 * @returns The bottomost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCircleGetBottomPoint2(const TuiCircle circle);
/*!
 * @brief Get the rightmost @ref TuiPoint2 of a @ref TuiCircle.
 *
 * @param circle The @ref TuiCircle.
 *
 * @returns The rightmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCircleGetRightPoint2(const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiCircle is degenerate. A degenerate @ref TuiCircle has a negative radius.
 *
 * @param circle The @ref TuiCircle.
 *
 * @returns if the @ref TuiCircle is degenerate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleIsDegenerate(const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiCircle contains a @ref TuiPoint2.
 *
 * @param circle The @ref TuiCircle.
 * @param point2 The @ref TuiPoint2
 *
 * @returns if the @ref TuiCircle contains the @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleContainsPoint2(const TuiCircle circle, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiCircle contains a @ref TuiLine.
 *
 * @param circle The @ref TuiCircle.
 * @param line The @ref TuiLine
 *
 * @returns if the @ref TuiCircle contains the @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleContainsLine(const TuiCircle circle, const TuiLine line);
/*!
 * @brief Get if a @ref TuiCircle contains a @ref TuiRect.
 *
 * @param circle The @ref TuiCircle.
 * @param rect The @ref TuiRect
 *
 * @returns if the @ref TuiCircle contains the @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleContainsRect(const TuiCircle circle, const TuiRect rect);
/*!
 * @brief Get if a @ref TuiCircle contains a @ref TuiCircle.
 *
 * @param circle_1 The first @ref TuiCircle.
 * @param circle_2 The second @ref TuiCircle
 *
 * @returns if the @ref TuiCircle contains the @ref TuiCircle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleContainsCircle(const TuiCircle circle_1, const TuiCircle circle_2);
/*!
 * @brief Get if a @ref TuiCircle intersects a @ref TuiLine.
 *
 * @param circle The @ref TuiCircle.
 * @param line The @ref TuiLine
 *
 * @returns if the @ref TuiCircle intersects the @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleIntersectsLine(const TuiCircle circle, const TuiLine line);
/*!
 * @brief Get if a @ref TuiCircle intersects a @ref TuiRect.
 *
 * @param circle The @ref TuiCircle.
 * @param rect The @ref TuiRect
 *
 * @returns if the @ref TuiCircle intersects the @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleIntersectsRect(const TuiCircle circle, const TuiRect rect);
/*!
 * @brief Get if a @ref TuiCircle intersects a @ref TuiCircle.
 *
 * @param circle_1 The first @ref TuiCircle.
 * @param circle_2 The second @ref TuiCircle
 *
 * @returns if the @ref TuiCircle intersects the @ref TuiCircles.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleIntersectsCircle(const TuiCircle circle_1, const TuiCircle circle_2);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard