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
/*! \file crop_circle.h
 */
#ifndef TUIC_CROP_CIRCLE_H //header guard
#define TUIC_CROP_CIRCLE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/grid_shape_types.h>
#include <TUIC/boolean.h>


/*! @name 2D Cropped Circle Functions
 *
 * Functions for manipulating @ref TuiCropCircle.
 *  @{ */
/*!
 * @brief Create a @ref TuiCropCircle.
 *
 * @param center_x The x position of one of the cropped crop_circle center point.
 * @param center_y The y position of one of the cropped crop_circle center point.
 * @param radius The radius of the cropped crop_circle.
 * @param crop_x The uppper left x position of the crop rect.
 * @param crop_y The upper left y position of the crop rect.
 * @param crop_width The width of the crop rect in tiles.
 * @param crop_height The height of the crop rect in tiles.
 *
 * @returns The created @ref TuiCropCircle.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCropCircle tuiCropCircle(const int center_x, const int center_y, const float radius, const int crop_x, const int crop_y, const int crop_width, const int crop_height);
/*!
 * @brief Get the center @ref TuiPoint2 of the circle of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The center @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropCircleGetCircleCenterPoint2(const TuiCropCircle crop_circle);
/*!
 * @brief Get the left x coordinate of the circle of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The left x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetCircleLeftX(const TuiCropCircle crop_circle);
/*!
 * @brief Get the right x coordinate of the circle of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The right x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetCircleRightX(const TuiCropCircle crop_circle);
/*!
 * @brief Get the top y coordinate of the circle of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The top y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetCircleTopY(const TuiCropCircle crop_circle);
/*!
 * @brief Get the bottom y coordinate of the circle of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The bottom y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetCircleBottomY(const TuiCropCircle crop_circle);
/*!
 * @brief Get the dimensions of the circle of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The dimensions.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetCircleDimensions(const TuiCropCircle crop_circle);
/*!
 * @brief Get the bounding @ref TuiRect of the circle of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropCircleGetCircleBoundingRect(const TuiCropCircle crop_circle);
/*!
 * @brief Get the far x coordinate of the crop rect of a @ref TuiRect.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The far x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetCropFarX(const TuiCropCircle crop_circle);
/*!
 * @brief Get the far y coordinate of the crop rect of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The far y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetCropFarY(const TuiCropCircle crop_circle);
/*!
 * @brief Get the left x coordinate of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The left x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetLeftX(const TuiCropCircle crop_circle);
/*!
 * @brief Get the right x coordinate of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The right x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetRightX(const TuiCropCircle crop_circle);
/*!
 * @brief Get the top y coordinate of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The top y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetTopY(const TuiCropCircle crop_circle);
/*!
 * @brief Get the bottom y coordinate of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The bottom y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropCircleGetBottomY(const TuiCropCircle crop_circle);
/*!
 * @brief Get the crop @ref TuiRect of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The crop @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropCircleGetCropRect(const TuiCropCircle crop_circle);
/*!
 * @brief Get the @ref TuiCircle of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The @ref TuiCircle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCircle tuiCropCircleGetCircle(const TuiCropCircle crop_circle);
/*!
 * @brief Get the bounding @ref TuiRect of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropCircleGetBoundingRect(const TuiCropCircle crop_circle);
/*!
 * @brief Get the leftmost @ref TuiPoint2 of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The leftmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropCircleGetLeftPoint2(const TuiCropCircle crop_circle);
/*!
 * @brief Get the rightmost @ref TuiPoint2 of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The rightmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropCircleGetRightPoint2(const TuiCropCircle crop_circle);
/*!
 * @brief Get the topmost @ref TuiPoint2 of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The topmost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropCircleGetTopPoint2(const TuiCropCircle crop_circle);
/*!
 * @brief Get the bottomost @ref TuiPoint2 of a @ref TuiCropCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns The bottomost @ref TuiPoint2
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropCircleGetBottomPoint2(const TuiCropCircle crop_circle);
/*!
 * @brief Get if a @ref TuiCropCircle is degenerate. A degenerate @ref TuiCropCircle has a radius greater than -0.5f and less than 0.5f.
 *
 * @param crop_circle The @ref TuiCropCircle.
 *
 * @returns if the @ref TuiCropCircle is degenerate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleIsDegenerate(const TuiCropCircle crop_circle);
/*!
 * @brief Get if a @ref TuiCropCircle contains a @ref TuiPoint2.
 *
 * @param crop_circle The @ref TuiCropCircle.
 * @param point2 The @ref TuiPoint2
 *
 * @returns if the @ref TuiCropCircle contains the @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleContainsPoint2(const TuiCropCircle crop_circle, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiCropCircle contains a @ref TuiLine.
 *
 * @param crop_circle The @ref TuiCropCircle.
 * @param line The @ref TuiLine
 *
 * @returns if the @ref TuiCropCircle contains the @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleContainsLine(const TuiCropCircle crop_circle, const TuiLine line);
/*!
 * @brief Get if a @ref TuiCropCircle contains a @ref TuiRect.
 *
 * @param crop_circle The @ref TuiCropCircle.
 * @param rect The @ref TuiRect
 *
 * @returns if the @ref TuiCropCircle contains the @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleContainsRect(const TuiCropCircle crop_circle, const TuiRect rect);
/*!
 * @brief Get if a @ref TuiCropCircle contains a @ref TuiCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 * @param circle The @ref TuiCircle
 *
 * @returns if the @ref TuiCropCircle contains the @ref TuiCircle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleContainsCircle(const TuiCropCircle crop_circle, const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiCropCircle contains a @ref TuiCropCircle.
 *
 * @param crop_circle_1 The first @ref TuiCropCircle.
 * @param crop_circle_2 The second @ref TuiCropCircle
 *
 * @returns if the @ref TuiCropCircle contains the @ref TuiCropCircle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleContainsCropCircle(const TuiCropCircle crop_circle_1, const TuiCropCircle crop_circle_2);
/*!
 * @brief Get if a @ref TuiCropCircle intersects a @ref TuiLine.
 *
 * @param crop_circle The @ref TuiCropCircle.
 * @param line The @ref TuiLine
 *
 * @returns if the @ref TuiCropCircle intersects the @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleIntersectsLine(const TuiCropCircle crop_circle, const TuiLine line);
/*!
 * @brief Get if a @ref TuiCropCircle intersects a @ref TuiRect.
 *
 * @param crop_circle The @ref TuiCropCircle.
 * @param rect The @ref TuiRect
 *
 * @returns if the @ref TuiCropCircle intersects the @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleIntersectsRect(const TuiCropCircle crop_circle, const TuiRect rect);
/*!
 * @brief Get if a @ref TuiCropCircle intersects a @ref TuiCircle.
 *
 * @param crop_circle The @ref TuiCropCircle.
 * @param circle The @ref TuiCircle
 *
 * @returns if the @ref TuiCropCircle intersects the @ref TuiCircle.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleIntersectsCircle(const TuiCropCircle crop_circle, const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiCropCircle intersects a @ref TuiCropCircle.
 *
 * @param crop_circle_1 The first @ref TuiCropCircle.
 * @param crop_circle_2 The second @ref TuiCropCircle
 *
 * @returns if the @ref TuiCropCircle intersects the @ref TuiCropCircles.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleIntersectsCropCircle(const TuiCropCircle crop_circle_1, const TuiCropCircle crop_circle_2);
/*!
 * @brief Get if a @ref TuiCropCircle intersects a @ref TuiRing.
 *
 * @param ring The @ref TuiRing.
 * @param rect The @ref TuiRect
 *
 * @returns if the @ref TuiCropCircle intersects the @ref TuiRing.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropCircleIntersectsRing(const TuiCropCircle crop_circle, const TuiRing ring);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard
