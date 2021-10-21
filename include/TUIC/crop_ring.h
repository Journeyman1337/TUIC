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
/*! \file crop_ring.h
 */
#ifndef TUIC_CROP_RING_H //header guard
#define TUIC_CROP_RING_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/grid_shape_types.h>
#include <TUIC/boolean.h>


/*! @name 2D Cropped Ring Functions
 *
 * Functions for manipulating @ref TuiCropRing.
 *  @{ */
/*!
 * @brief Create a @ref TuiCropRing.
 *
 * @param center_x The x position of one of the crop_ring center point.
 * @param center_y The y position of one of the crop_ring center point.
 * @param radius The radius of the crop_ring.
 * @param depth The depth of the crop_ring.
 * @param crop_x The uppper left x position of the crop rect.
 * @param crop_y The upper left y position of the crop rect.
 * @param crop_width The width of the crop rect in tiles.
 * @param crop_height The height of the crop rect in tiles.
 *
 * @returns The created @ref TuiCropRing.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCropRing tuiCropRing(const int center_x, const int center_y, const float radius, const float depth, const int crop_x, const int crop_y, const int crop_width, const int crop_height);
/*!
 * @brief Get the center @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The center @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingCenterPoint2(const TuiCropRing crop_ring);
/*!
 * @brief Get the left x coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The left x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetRingLeftX(const TuiCropRing crop_ring);
/*!
 * @brief Get the right x coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The right x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetRingRightX(const TuiCropRing crop_ring);
/*!
 * @brief Get the top y coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The top y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetRingTopY(const TuiCropRing crop_ring);
/*!
 * @brief Get the bottom y coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The bottom y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetRingBottomY(const TuiCropRing crop_ring);
/*!
 * @brief Get the radius of the inner circle of a  @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The inner radius.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
float tuiCropRingGetInnerRingRadius(const TuiCropRing crop_ring);
/*!
 * @brief Get the left x coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The left x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetInnerRingLeftX(const TuiCropRing crop_ring);
/*!
 * @brief Get the right x coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The right x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetInnerRingRightX(const TuiCropRing crop_ring);
/*!
 * @brief Get the top y coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The top y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetInnerRingTopY(const TuiCropRing crop_ring);
/*!
 * @brief Get the bottom y coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The bottom y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetInnerRingBottomY(const TuiCropRing crop_ring);
/*!
 * @brief Get the dimensions of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The dimensions.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetRingDimensions(const TuiCropRing crop_ring);
/*!
 * @brief Get the dimensions of the inner circle of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The dimensions.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetRingInnerDimensions(const TuiCropRing crop_ring);
/*!
 * @brief Get the far x coordinate of the crop rect of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The far x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetCropFarX(const TuiCropRing crop_ring);
/*!
 * @brief Get the far y coordinate of the crop rect of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The far y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetCropFarY(const TuiCropRing crop_ring);
/*!
 * @brief Get the left x coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The left x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetLeftX(const TuiCropRing crop_ring);
/*!
 * @brief Get the right x coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The right x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetRightX(const TuiCropRing crop_ring);
/*!
 * @brief Get the top y coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The top y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetTopY(const TuiCropRing crop_ring);
/*!
 * @brief Get the bottom y coordinate of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The bottom y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropRingGetBottomY(const TuiCropRing crop_ring);
/*!
 * @brief Get the @ref TuiRing of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The inner ring.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRing tuiCropRingGetRing(const TuiCropRing crop_ring);
/*!
 * @brief Get the circle of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The circle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCircle tuiCropRingGetRingCircle(const TuiCropRing crop_ring);
/*!
 * @brief Get the inner circle of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The inner circle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCircle tuiCropRingGetRingInnerCircle(const TuiCropRing crop_ring);
/*!
 * @brief Get the bounding @ref TuiRect of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropRingGetRingBoundingRect(const TuiCropRing crop_ring);
/*!
 * @brief Get the bounding @ref TuiRect of a the inner circle of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropRingGetRingInnerBoundingRect(const TuiCropRing crop_ring);
/*!
 * @brief Get the bounding @ref TuiRect of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropRingGetBoundingRect(const TuiCropRing crop_ring);
/*!
 * @brief Get the crop @ref TuiRect of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The crop @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropRingGetCropRect(const TuiCropRing crop_ring);
/*!
 * @brief Get the leftmost @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The leftmost @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingLeftPoint2(const TuiCropRing crop_ring);
/*!
 * @brief Get the rightmost @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The rightmost @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingRightPoint2(const TuiCropRing crop_ring);
/*!
 * @brief Get the topmost @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The topmost @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingTopPoint2(const TuiCropRing crop_ring);
/*!
 * @brief Get the bottomost @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The bottomost @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingBottomPoint2(const TuiCropRing crop_ring);
/*!
 * @brief Get the leftmost @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The leftmost @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingInnerLeftPoint2(const TuiCropRing crop_ring);
/*!
 * @brief Get the rightmost @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The rightmost @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingInnerRightPoint2(const TuiCropRing crop_ring);
/*!
 * @brief Get the topmost @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The topmost @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingInnerTopPoint2(const TuiCropRing crop_ring);
/*!
 * @brief Get the bottomost @ref TuiPoint2 of a @ref TuiCropRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 *
 * @returns The bottomost @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropRingGetRingInnerBottomPoint2(const TuiCropRing crop_ring);
/*!
* @brief Get if a @ref TuiCropRing is degenerate. A degenerate @ref TuiCircle has a radius and/or depth greater than -0.5f and less than 0.5f or if the unsigned depth is greater than the unsigned radius.
*
* @param crop_ring The @ref TuiCropRing.
*
* @returns if the @ref TuiCropRing is degenerate.
*
* @errors This function can have no error codes.
*
* @requirements This function can be called freely, even if TUIC is not currently initialized.
*
* @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
*/
TuiBoolean tuiCropRingIsDegenerate(const TuiCropRing crop_ring);
/*!
 * @brief Get if a @ref TuiCropRing contains a @ref TuiPoint2.
 *
 * @param crop_ring The @ref TuiCropRing.
 * @param point2 The @ref TuiPoint2
 *
 * @returns if the @ref TuiCropRing contains the @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropRingContainsPoint2(const TuiCropRing crop_ring, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiCropRing intersects a @ref TuiLine.
 *
 * @param crop_ring The @ref TuiCircle.
 * @param line The @ref TuiLine
 *
 * @returns if the @ref TuiCropRing intersects the @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropRingIntersetsLine(const TuiCropRing crop_ring, const TuiLine line);
/*!
 * @brief Get if a @ref TuiCropRing intersects a @ref TuiRect.
 *
 * @param crop_ring The @ref TuiCropRing.
 * @param rect The @ref TuiRect
 *
 * @returns if the @ref TuiCropRing intersects the @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropRingIntersectsRect(const TuiCropRing crop_ring, const TuiRect rect);
/*!
 * @brief Get if a @ref TuiCropRing intersects a @ref TuiRect.
 *
 * @param crop_ring The @ref TuiCropRing.
 * @param rect The @ref TuiRect
 *
 * @returns if the @ref TuiCropRing intersects the @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropRingIntersectsCircle(const TuiCropRing crop_ring, const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiCropRing intersects a @ref TuiRing.
 *
 * @param crop_ring The @ref TuiCropRing.
 * @param ring The @ref TuiRing
 *
 * @returns if the @ref TuiCropRing intersects the @ref TuiRing.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropRingIntersectsRing(const TuiCropRing crop_ring, const TuiRing ring);
/*!
 * @brief Get if a @ref TuiCropRing intersects a @ref TuiCropRing.
 *
 * @param crop_ring_1 The first @ref TuiCropRing.
 * @param crop_ring_2 The second @ref TuiCropRing
 *
 * @returns if the @ref TuiCropRing intersects the @ref TuiCropRing.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropRingIntersectsCropRing(const TuiCropRing crop_ring_1, const TuiCropRing crop_ring_2);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard