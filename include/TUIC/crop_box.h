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
/*! \file crop_box.h
 */
#ifndef TUIC_CROP_BOX_H //header guard
#define TUIC_CROP_BOX_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/grid_shape_types.h>
#include <TUIC/boolean.h>


/*! @name 2D Cropped Box Functions
 *
 * Functions for manipulating @ref TuiCropBox.
 *  @{ */
/*!
 * @brief Create a @ref TuiCropBox.
 *
 * @param x The x position of one of the crop_box corners.
 * @param y The y position of one of the crop_box corners.
 * @param width The width of the crop_box. If negative, the crop_box contents are flipped.
 * @param height The height of the crop_box. If negative, the crop_box contents are flipped.
 * @param depth The depth of the crop_box border in tiles.
 * @param crop_x The uppper left x position of the crop rect.
 * @param crop_y The upper left y position of the crop rect.
 * @param crop_width The width of the crop rect in tiles.
 * @param crop_height The height of the crop rect in tiles.
 *
 * @returns The created @ref TuiRect.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCropBox tuiCropBox(const int x, const int y, const int width, const int height, const int depth, const int crop_x, const int crop_y, const int crop_width, const int crop_height);
/*!
 * @brief Get the far x coordinate of a @ref TuiCropBox.
 *
 * @param rect The @ref TuiCropBox.
 *
 * @returns The far x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetBoxFarX(const TuiCropBox crop_box);
/*!
 * @brief Get the far y coordinate of a @ref TuiCropBox.
 *
 * @param rect The @ref TuiCropBox.
 *
 * @returns The far y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetBoxFarY(const TuiCropBox crop_box);
/*!
 * @brief Get the width of a @ref TuiCropBox in tiles, or the absolute value if its width.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The tile width.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetBoxTileWidth(const TuiCropBox crop_box);
/*!
 * @brief Get the height of a @ref TuiCropBox in tiles, or the absolute value if its height.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The tile height.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetBoxTileHeight(const TuiCropBox crop_box);
/*!
 * @brief Get the left x coordinate of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The left x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetLeftX(const TuiCropBox crop_box);
/*!
 * @brief Get the right x coordinate of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The right x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetRightX(const TuiCropBox crop_box);
/*!
 * @brief Get the top y coordinate of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The top y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetTopY(const TuiCropBox crop_box);
/*!
 * @brief Get the bottom y coordinate of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The bottom y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetBottomY(const TuiCropBox crop_box);
/*!
 * @brief Get if the contents of a @ref TuiCropBox is flipped wide, or if its width is negative.
 *
 * @param rect The @ref TuiCropBox.
 *
 * @returns The @ref TuiBoolean result. If crop_box is a flipped wide @ref TuiCropBox, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIsFlippedWide(const TuiCropBox crop_box);
/*!
 * @brief Get if the contents of a @ref TuiCropBox is flipped tall or if its height is negative.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The @ref TuiBoolean result. If crop_box is a flipped tall @ref TuiCropBox, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIsFlippedTall(const TuiCropBox crop_box);
/*!
 * @brief Get if a @ref TuiCropBox is degenerate. A degenerate crop_box has a 0 valued width, height, or depth.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The @ref TuiBoolean result. If crop_box is a degenerate @ref TuiCropBox, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIsDegenerate(const TuiCropBox crop_box);
/*!
 * @brief Get the bounding @ref TuiRect from a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropBoxGetBoundingRect(const TuiCropBox crop_box);
/*!
 * @brief Get the crop @ref TuiRect from a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The bounding @ref TuiRect.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiCropBoxGetCropRect(const TuiCropBox crop_box);
/*!
 * @brief Get the far x coordinate of the crop rect of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The far x coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetCropFarX(const TuiCropBox crop_box);
/*!
 * @brief Get the far y coordinate of the crop rect of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The far y coordinate.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
int tuiCropBoxGetCropFarY(const TuiCropBox crop_box);
/*!
 * @brief Get the @ref TuiBox from a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The @ref TuiBox.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBox tuiCropBoxGetBox(const TuiCropBox crop_box);
/*!
 * @brief Get the @ref TuiPoint2 at the top left corner of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropBoxGetBoxTopLeftCornerPoint2(const TuiCropBox crop_box);
/*!
 * @brief Get the @ref TuiPoint2 at the top right corner of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropBoxGetBoxTopRightCornerPoint2(const TuiCropBox crop_box);
/*!
 * @brief Get the @ref TuiPoint2 at the bottom left corner of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropBoxGetBoxBottomLeftCornerPoint2(const TuiCropBox crop_box);
/*!
 * @brief Get the @ref TuiPoint2 at the bottom right corner of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
 *
 * @returns The @ref TuiPoint2.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCropBoxGetBoxBottomRightCornerPoint2(const TuiCropBox crop_box);
/*!
 * @brief Get the @ref TuiLine on the left border of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
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
TuiLine tuiCropBoxGetBoxLeftBorderLine(const TuiCropBox crop_box, const TuiBoolean corners);
/*!
 * @brief Get the @ref TuiLine on the right border of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
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
TuiLine tuiCropBoxGetBoxRightBorderLine(const TuiCropBox crop_box, const TuiBoolean corners);
/*!
 * @brief Get the @ref TuiLine on the top border of a @ref TuiCropBox.
 *
 * @param crop_box The @ref TuiCropBox.
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
TuiLine tuiCropBoxGetBoxTopBorderLine(const TuiCropBox crop_box, const TuiBoolean corners);
/*!
* @brief Get the @ref TuiLine on the bottom border of a @ref TuiCropBox.
*
* @param crop_box The @ref TuiCropBox.
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
TuiLine tuiCropBoxGetBoxBottomBorderLine(const TuiCropBox crop_box, const TuiBoolean corners);
/*!
 * @brief Get if a @ref TuiCropBox contains a @ref TuiPoint2,
 *
 * @param crop_box The @ref TuiCropBox.
 * @param point2 The @ref TuiPoint2
 *
 * @returns The @ref TuiBoolean result. If the point2 is in crop_box, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxContainsPoint2(const TuiCropBox crop_box, const TuiPoint2 point2);
/*!
 * @brief Get if a @ref TuiCropBox intersects a @ref TuiLine.
 *
 * @param crop_box The @ref TuiCropBox.
 * @param line The @ref TuiLine
 *
 * @returns The @ref TuiBoolean result. If the crop_box intersects line, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIntersectsLine(const TuiCropBox crop_box, const TuiLine line);
/*!
 * @brief Get if a @ref TuiCropBox intersects a @ref TuiRect.
 *
 * @param crop_box The @ref TuiCropBox.
 * @param rect The @ref TuiRect
 *
 * @returns The @ref TuiBoolean result. If the crop_box intersects rect, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIntersectsRect(const TuiCropBox crop_box, const TuiRect rect);
/*!
 * @brief Get if a @ref TuiCropBox intersects a @ref TuiBox.
 *
 * @param crop_box The @ref TuiCropBox.
 * @param box The @ref TuiBox
 *
 * @returns The @ref TuiBoolean result. If the crop_box intersects box, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIntersectsBox(const TuiCropBox crop_box, const TuiBox box);
/*!
 * @brief Get if a @ref TuiCropBox intersect.
 *
 * @param crop_box_1 The first @ref TuiCropBox.
 * @param crop_box_2 The second @ref TuiCropBox
 *
 * @returns The @ref TuiBoolean result. If crop_box_1 intersects crop_box_2, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIntersectsCropBox(const TuiCropBox crop_box_1, const TuiCropBox crop_box_2);
/*!
 * @brief Get if a @ref TuiCropBox intersects a @ref TuiCircle.
 *
 * @param crop_box The @ref TuiCropBox.
 * @param circle The @ref TuiCircle
 *
 * @returns The @ref TuiBoolean result. If the crop_box intersects circle, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIntersectsCircle(const TuiCropBox crop_box, const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiCropBox intersects a @ref TuiRing.
 *
 * @param crop_box The @ref TuiCropBox.
 * @param ring The @ref TuiRing
 *
 * @returns The @ref TuiBoolean result. If the crop_box intersects ring, it
 * returns @ref TUI_TRUE. Otherwise, it returns @ref TUI_FALSE.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCropBoxIntersectsRing(const TuiCropBox crop_box, const TuiRing ring);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard