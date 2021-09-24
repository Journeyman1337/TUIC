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
/*! \file rect.h
 */
#ifndef TUIC_RECT_H //header guard
#define TUIC_RECT_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/grid_shape_types.h>
#include <TUIC/boolean.h>


/*! @name 2D Rect Functions
 *
 * Functions for manipulating @ref TuiRect.
 *  @{ */
/*!
 * @brief Create a @ref TuiRect.
 *
 * @param x The x position of one of the rect corners.
 * @param y The y position of one of the rect corners.
 * @param width The width of the rect. If negative, the rect contents are flipped.
 * @param height The height of the rect. If negative, the rect contents are flipped.
 *
 * @returns The created @ref TuiRect.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiRect(const int x, const int y, const int width, const int height);
/*!
 * @brief Get the far x coordinate of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The far x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRectGetFarX(const TuiRect rect);
/*!
 * @brief Get the far y coordinate of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The far y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRectGetFarY(const TuiRect rect);
/*!
 * @brief Get the width of a @ref TuiRect in tiles, or the absolute value if its width.
 * 
 * @param rect The @ref TuiRect.
 *
 * @returns The physical width.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRectGetTileWidth(const TuiRect rect);
/*!
 * @brief Get the height of a @ref TuiRect in tiles, or the absolute value if its height.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The physical height.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiRectGetTileHeight(const TuiRect rect);
/*!
 * @brief Get if the contents of a @ref TuiRect is flipped wide, or if its width is negative.
 * 
 * @param rect The @ref TuiRect.
 *
 * @returns The @ref TuiBoolean result. If rect is a flipped wide @ref TuiRect, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectIsFlippedWide(const TuiRect rect);
/*!
 * @brief Get if the contents of a @ref TuiRect is flipped tall or if its height is negative.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The @ref TuiBoolean result. If rect is a flipped tall @ref TuiRect, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectIsFlippedTall(const TuiRect rect);
/*!
 * @brief Get if a @ref TuiRect is degenerate. A degenerate rect has a 0 valued width or height.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The @ref TuiBoolean result. If rect is a degenerate @ref TuiRect, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectIsDegenerate(const TuiRect rect);
/*!
 * @brief Get if a @ref TuiBox from a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 * @param depth The depth of the box border in tiles.
 *
 * @returns The @ref TuiBox.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBox tuiRectGetBox(const TuiRect rect, const int depth);
/*!
 * @brief Get the @ref TuiPoint2 at the top left corner of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRectGetTopLeftCornerPoint2(const TuiRect rect);
/*!
 * @brief Get the @ref TuiPoint2 at the top right corner of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRectGetTopRightCornerPoint2(const TuiRect rect);
/*!
 * @brief Get the @ref TuiPoint2 at the bottom left corner of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRectGetBottomLeftCornerPoint2(const TuiRect rect);
/*!
 * @brief Get the @ref TuiPoint2 at the bottom right corner of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRectGetBottomRightCornerPoint2(const TuiRect rect);
/*!
 * @brief Get the @ref TuiLine on the left border of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 * @param corners If the corners should be included in the border line.
 *
 * @returns The @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLine tuiRectGetLeftBorderLine(const TuiRect rect, const TuiBoolean corners);
/*!
 * @brief Get the @ref TuiLine on the right border of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 * @param corners If the corners should be included in the border line.
 *
 * @returns The @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLine tuiRectGetRightBorderLine(const TuiRect rect, const TuiBoolean corners);
/*!
 * @brief Get the @ref TuiLine on the top border of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 * @param corners If the corners should be included in the border line.
 *
 * @returns The @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLine tuiRectGetTopBorderLine(const TuiRect rect, const TuiBoolean corners);
/*!
 * @brief Get the @ref TuiLine on the bottom border of a @ref TuiRect.
 *
 * @param rect The @ref TuiRect.
 * @param corners If the corners should be included in the border line.
 *
 * @returns The @ref TuiLine.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLine tuiRectGetBottomBorderLine(const TuiRect rect, const TuiBoolean corners);
/*!
 * @brief Get the inner rect of a @ref TuiRect, not including its corners or borders.
 *
 * @param rect The @ref TuiRect.
 * @param depth How deep the inner rect should be in its rect.
 *
 * @returns The inner @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiRectGetInnerRect(const TuiRect rect, const int depth);
/*!
 * @brief Get a cropped @ref TuiRect.
 *
 * @param rect The @ref TuiRect to crop.
 * @param crop_rect The @ref TuiRect crop.
 *
 * @returns The cropped @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiRectCrop(const TuiRect rect, const TuiRect crop_rect);
/*!
 * @brief Get if a @ref TuiRect contains a @ref TuiPoint2,
 *
 * @param rect The @ref TuiRect.
 * @param point2 The @ref TuiPoint2
 *
 * @returns The @ref TuiBoolean result. If the point2 is in rect, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectContainsPoint2(const TuiRect rect, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiRect contains a @ref TuiLine,
 *
 * @param rect The @ref TuiRect.
 * @param line The @ref TuiLine
 *
 * @returns The @ref TuiBoolean result. If the line is in rect, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectContainsLine(const TuiRect rect, const TuiLine line);
/*!
 * @brief Get if a @ref TuiRect contains a @ref TuiRect,
 *
 * @param rect_1 The @ref TuiRect that contains rect_2.
 * @param rect_2 The @ref TuiRect that is contained by rect_1.
 *
 * @returns The @ref TuiBoolean result. If the rect_1 is in rect_2, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectContainsRect(const TuiRect rect_1, const TuiRect rect_2);
/*!
 * @brief Get if a @ref TuiRect intersects a @ref TuiLine.
 *
 * @param rect The @ref TuiRect.
 * @param line The @ref TuiLine
 *
 * @returns The @ref TuiBoolean result. If the rect intersects line, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectIntersectsLine(const TuiRect rect, const TuiLine line);
/*!
 * @brief Get if a @ref TuiRect intersect.
 *
 * @param rect_1 The first @ref TuiRect.
 * @param rect_2 The second @ref TuiRect
 *
 * @returns The @ref TuiBoolean result. If rect_1 intersects rect_2, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectIntersectsRect(const TuiRect rect_1, const TuiRect rect_2);
/*!
 * @brief Get if a @ref TuiRect intersects a @ref TuiCircle.
 *
 * @param rect The @ref TuiRect.
 * @param circle The @ref TuiCircle
 *
 * @returns The @ref TuiBoolean result. If the rect intersects circle, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectIntersectsCircle(const TuiRect rect, const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiRect intersects a @ref TuiRing.
 *
 * @param rect The @ref TuiRect.
 * @param ring The @ref TuiRing
 *
 * @returns The @ref TuiBoolean result. If the rect intersects ring, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectIntersectsRing(const TuiRect rect, const TuiRing ring);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard