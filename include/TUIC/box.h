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
/*! \file box.h
 */
#ifndef TUIC_BOX_H //header guard
#define TUIC_BOX_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/grid_shape_types.h>
#include <TUIC/boolean.h>


/*! @name 2D Box Functions
 *
 * Functions for manipulating @ref TuiBox.
 *  @{ */
/*!
 * @brief Create a @ref TuiBox.
 *
 * @param x The x position of one of the box corners.
 * @param y The y position of one of the box corners.
 * @param width The width of the box. If negative, the box contents are flipped.
 * @param height The height of the box. If negative, the box contents are flipped.
 * @param depth The depth of the box border in tiles.
 *
 * @returns The created @ref TuiRect.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBox tuiBox(const int x, const int y, const int width, const int height, const int depth);
/*!
 * @brief Get the far x coordinate of a @ref TuiBox.
 *
 * @param rect The @ref TuiBox.
 *
 * @returns The far x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiBoxGetFarX(const TuiBox box);
/*!
 * @brief Get the far y coordinate of a @ref TuiBox.
 *
 * @param rect The @ref TuiBox.
 *
 * @returns The far y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiBoxGetFarY(const TuiBox box);
/*!
 * @brief Get the width of a @ref TuiBox in tiles, or the absolute value if its width.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The tile width.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiBoxGetTileWidth(const TuiBox box);
/*!
 * @brief Get the height of a @ref TuiBox in tiles, or the absolute value if its height.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The tile height.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiBoxGetTileHeight(const TuiBox box);
/*!
 * @brief Get if the contents of a @ref TuiBox is flipped wide, or if its width is negative.
 *
 * @param rect The @ref TuiBox.
 *
 * @returns The @ref TuiBoolean result. If box is a flipped wide @ref TuiBox, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxIsFlippedWide(const TuiBox box);
/*!
 * @brief Get if the contents of a @ref TuiBox is flipped tall or if its height is negative.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The @ref TuiBoolean result. If box is a flipped tall @ref TuiBox, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxIsFlippedTall(const TuiBox box);
/*!
 * @brief Get if a @ref TuiBox is degenerate. A degenerate box has a 0 valued width, height, or depth.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The @ref TuiBoolean result. If box is a degenerate @ref TuiBox, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxIsDegenerate(const TuiBox box);
/*!
 * @brief Get the @ref TuiRect from a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiBoxGetRect(const TuiBox box);
/*!
 * @brief Get the @ref TuiRect within a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiBoxGetInnerRect(const TuiBox box);
/*!
 * @brief Get the @ref TuiPoint2 at the top left corner of a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiBoxGetTopLeftCornerPoint2(const TuiBox box);
/*!
 * @brief Get the @ref TuiPoint2 at the top right corner of a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiBoxGetTopRightCornerPoint2(const TuiBox box);
/*!
 * @brief Get the @ref TuiPoint2 at the bottom left corner of a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiBoxGetBottomLeftCornerPoint2(const TuiBox box);
/*!
 * @brief Get the @ref TuiPoint2 at the bottom right corner of a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiBoxGetBottomRightCornerPoint2(const TuiBox box);
/*!
 * @brief Get the @ref TuiLine on the left border of a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
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
TuiLine tuiBoxGetLeftBorderLine(const TuiBox box, const TuiBoolean corners);
/*!
 * @brief Get the @ref TuiLine on the right border of a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
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
TuiLine tuiBoxGetRightBorderLine(const TuiBox box, const TuiBoolean corners);
/*!
 * @brief Get the @ref TuiLine on the top border of a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
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
TuiLine tuiBoxGetTopBorderLine(const TuiBox box, const TuiBoolean corners);
/*!
 * @brief Get the @ref TuiLine on the bottom border of a @ref TuiBox.
 *
 * @param box The @ref TuiBox.
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
TuiLine tuiBoxGetBottomBorderLine(const TuiBox box, const TuiBoolean corners);
/*!
 * @brief Get if a @ref TuiBox contains a @ref TuiPoint2,
 *
 * @param box The @ref TuiBox.
 * @param point2 The @ref TuiPoint2
 *
 * @returns The @ref TuiBoolean result. If the point2 is in box, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxContainsPoint2(const TuiBox box, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiBox intersects a @ref TuiLine.
 *
 * @param box The @ref TuiBox.
 * @param line The @ref TuiLine
 *
 * @returns The @ref TuiBoolean result. If the box intersects line, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxIntersectsLine(const TuiBox box, const TuiLine line);
/*!
 * @brief Get if a @ref TuiBox intersects a @ref TuiRect.
 *
 * @param box The @ref TuiBox.
 * @param rect The @ref TuiRect
 *
 * @returns The @ref TuiBoolean result. If the box intersects rect, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxIntersectsRect(const TuiBox box, const TuiRect rect);
/*!
 * @brief Get if a @ref TuiBox intersect.
 *
 * @param box_1 The first @ref TuiBox.
 * @param box_2 The second @ref TuiBox
 *
 * @returns The @ref TuiBoolean result. If box_1 intersects box_2, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxIntersectsBox(const TuiBox box_1, const TuiBox box_2);
/*!
 * @brief Get if a @ref TuiBox intersects a @ref TuiCircle.
 *
 * @param box The @ref TuiBox.
 * @param circle The @ref TuiCircle
 *
 * @returns The @ref TuiBoolean result. If the box intersects circle, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxIntersectsCircle(const TuiBox box, const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiBox intersects a @ref TuiRing.
 *
 * @param box The @ref TuiBox.
 * @param ring The @ref TuiRing
 *
 * @returns The @ref TuiBoolean result. If the box intersects ring, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBoxIntersectsRing(const TuiBox box, const TuiRing ring);
 /*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard