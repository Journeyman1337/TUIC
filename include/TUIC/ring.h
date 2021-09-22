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
/*! \file ring.h
 */
#ifndef TUIC_RING_H //header guard
#define TUIC_RING_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/grid_shape_types.h>
#include <TUIC/boolean.h>


/*! @name 2D Ring Functions
 *
 * Functions for manipulating @ref TuiRing.
 *  @{ */
/*!
 * @brief Create a @ref TuiRing.
 *
 * @param center_x The x position of one of the ring center point.
 * @param center_y The y position of one of the ring center point.
 * @param radius The radius of the ring.
 * @param depth The depth of the ring.
 *
 * @returns The created @ref TuiRing.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRing tuiRing(const int center_x, const int center_y, const float radius, const float depth);
/*!
 * @brief Get the center @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The center @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetCenterPoint2(const TuiRing ring);
/*!
 * @brief Get the left x coordinate of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The left x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetLeftX(const TuiRing ring);
/*!
 * @brief Get the right x coordinate of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The right x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetRightX(const TuiRing ring);
/*!
 * @brief Get the top y coordinate of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The top y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetTopY(const TuiRing ring);
/*!
 * @brief Get the bottom y coordinate of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The bottom y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetBottomY(const TuiRing ring);
/*!
 * @brief Get the radius of the inner circle of a  @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The inner radius.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
float tuiRingGetInnerRadius(const TuiRing ring);
/*!
 * @brief Get the left x coordinate of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The left x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetInnerLeftX(const TuiRing ring);
/*!
 * @brief Get the right x coordinate of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The right x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetInnerRightX(const TuiRing ring);
/*!
 * @brief Get the top y coordinate of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The top y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetInnerTopY(const TuiRing ring);
/*!
 * @brief Get the bottom y coordinate of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The bottom y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetInnerBottomY(const TuiRing ring);
/*!
 * @brief Get the dimensions of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The dimensions.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetDimensions(const TuiRing ring);
/*!
 * @brief Get the dimensions of the inner circle of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The dimensions.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRingGetInnerDimensions(const TuiRing ring);
/*!
 * @brief Get the circle of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The circle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCircle tuiRingGetCircle(const TuiRing ring);
/*!
 * @brief Get the inner circle of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The inner circle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCircle tuiRingGetInnerCircle(const TuiRing ring);
/*!
 * @brief Get the bounding @ref TuiRect of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiRingGetBoundingRect(const TuiRing ring);
/*!
 * @brief Get the bounding @ref TuiRect of a the inner circle of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiRingGetInnerBoundingRect(const TuiRing ring);
/*!
 * @brief Get the leftmost @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The leftmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetLeftPoint2(const TuiRing ring);
/*!
 * @brief Get the rightmost @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The rightmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetRightPoint2(const TuiRing ring);
/*!
 * @brief Get the topmost @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The topmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetTopPoint2(const TuiRing ring);
/*!
 * @brief Get the bottomost @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The bottomost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetBottomPoint2(const TuiRing ring);
/*!
 * @brief Get the leftmost @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The leftmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetInnerLeftPoint2(const TuiRing ring);
/*!
 * @brief Get the rightmost @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The rightmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetInnerRightPoint2(const TuiRing ring);
/*!
 * @brief Get the topmost @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The topmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetInnerTopPoint2(const TuiRing ring);
/*!
 * @brief Get the bottomost @ref TuiPoint2 of a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns The bottomost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRingGetInnerBottomPoint2(const TuiRing ring);
/*!
 * @brief Get if a @ref TuiRing is degenerate. A degenerate @ref TuiCircle has a radius and/or depth greater than -0.5f and less than 0.5f.
 *
 * @param ring The @ref TuiRing.
 *
 * @returns if the @ref TuiRing is degenerate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRingIsDegenerate(const TuiRing ring);
/*!
 * @brief Get if a @ref TuiRing contains a @ref TuiPoint2.
 *
 * @param ring The @ref TuiRing.
 * @param point2 The @ref TuiPoint2
 *
 * @returns if the @ref TuiRing contains the @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRingContainsPoint2(const TuiRing ring, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiRing intersects a @ref TuiLine.
 *
 * @param ring The @ref TuiCircle.
 * @param line The @ref TuiLine
 *
 * @returns if the @ref TuiRing intersects the @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRingIntersetsLine(const TuiRing ring, const TuiLine line);
/*!
 * @brief Get if a @ref TuiRing intersects a @ref TuiRect.
 *
 * @param ring The @ref TuiRing.
 * @param rect The @ref TuiRect
 *
 * @returns if the @ref TuiRing intersects the @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRingIntersectsRect(const TuiRing ring, const TuiRect rect);
/*!
 * @brief Get if a @ref TuiRing intersects a @ref TuiRect.
 *
 * @param ring The @ref TuiRing.
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
TuiBoolean tuiRingIntersectsCircle(const TuiRing ring, const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiRing intersects a @ref TuiRing.
 *
 * @param ring_1 The first @ref TuiRing.
 * @param ring_2 The second @ref TuiRing
 *
 * @returns if the @ref TuiRing intersects the @ref TuiRing.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRingIntersectsRing(const TuiRing ring_1, const TuiRing ring_2);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard