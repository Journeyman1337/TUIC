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
/*! \file grid_shape_types.h
 */
#ifndef TUIC_GRID_SHAPE_TYPES_H // header guard
#define TUIC_GRID_SHAPE_TYPES_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/box_part.h>


/*! @name Grid Shape Struct Types
 * These structs represent shapes made of tiles on a roguelike grid.
 *  @{ */
/*!
 * \brief A 2D tile coordinate position.
 */
typedef struct TuiPoint2
{
	/*!
	 * \brief The x coordinate of the point.
	 */
	int x;
	/*!
	 * \brief The y coordinate of the point.
	 */
	int y;
} TuiPoint2;
/*!
 * \brief A 2D tile line segment with a start and an end.
 */
typedef struct TuiLine
{
	/*!
	 * \brief The x coordinate of the line start point.
	 */
	int start_x;
	/*!
	 * \brief The y coordinate of the line start point.
	 */
	int start_y;
	/*!
	 * \brief The x coordinate of the line end point.
	 */
	int end_x;
	/*!
	 * \brief The y coordinate of the line end point.
	 */
	int end_y;
} TuiLine;
/*!
 * \brief An iterator that goes over every point in a @ref TuiLine.
 */
typedef struct TuiLineIt
{
	/*!
	 * \brief The x coordinate of the line start point.
	 */
	const int start_x;
	/*!
	 * \brief The y coordinate of the line start point.
	 */
	const int start_y;
	/*!
	 * \brief The x coordinate of the line end point.
	 */
	const int end_x;
	/*!
	 * \brief The y coordinate of the line end point.
	 */
	const int end_y;
	/*!
	 * \brief The diagonal length of the line.
	 */
	const int diagonal_length;
	/*!
	 * \brief The Bresenham index of the line iterator algorithm.
	 */
	int position;
} TuiLineIt;
/*!
 * \brief A 2D tile rect.
 */
typedef struct TuiRect
{
	/*!
	 * \brief The x position of one of the rect corners.
	 */
	int x;
	/*!
	 * \brief The y position of one of the rect corners.
	 */
	int y;
	/*!
	 * \brief The width of the rect in tiles.
	 */
	int width;
	/*!
	 * \brief The height of the rect in tiles.
	 */
	int height;
} TuiRect;
/*!
 * \brief A 2D rect iterator.
 */
typedef struct TuiRectIt
{
	/*!
	 * \brief The x position of the left border of the rect.
	 */
	const int left_x;
	/*!
	 * \brief The x position of the right border of the rect.
	 */
	const int right_x;
	/*!
	 * \brief The x position of the top border of the rect.
	 */
	const int top_y;
	/*!
	 * \brief The x position of the bottom border of the rect.
	 */
	const int bottom_y;
	/*!
	 * \brief The current x position of the iterator.
	 */
	int cur_x_position;
	/*!
	 * \brief The current y position of the iterator.
	 */
	int cur_y_position;
} TuiRectIt;
/*!
 * \brief A 2D tile rect outline.
 */
typedef struct TuiBox
{
	/*!
	 * \brief The x position of one of the box corners.
	 */
	int x;
	/*!
	 * \brief The y position of one of the box corners.
	 */
	int y;
	/*!
	 * \brief The width of the box in tiles.
	 */
	int width;
	/*!
	 * \brief The height of the box in tiles.
	 */
	int height;
	/*!
	 * \brief The depth/thickness of the box borders in tiles.
	 */
	int depth;
} TuiBox;
/*!
 * \brief A 2D rect outline iterator.
 */
typedef struct TuiBoxIt
{
	/*!
	 * \brief The x position of the left border of the rect.
	 */
	const int left_x;
	/*!
	 * \brief The x position of the right border of the rect.
	 */
	const int right_x;
	/*!
	 * \brief The x position of the top border of the rect.
	 */
	const int top_y;
	/*!
	 * \brief The x position of the bottom border of the rect.
	 */
	const int bottom_y;
	/*!
	 * \brief The depth/thickness of the box borders in tiles.
	 */
	int depth;
	/*!
	 * \brief The current box part being iterated over.
	 */
	TuiBoxPart cur_box_part;
	/*!
	 * \brief The current x position of the iterator.
	 */
	int cur_x_position;
	/*!
	 * \brief The current y position of the iterator.
	 */
	int cur_y_position;
} TuiBoxIt;

/*!
 * \brief A 2D tile rect outline.
 */
typedef struct TuiCropBox
{
	/*!
	 * \brief The x position of one of the box corners.
	 */
	int x;
	/*!
	 * \brief The y position of one of the box corners.
	 */
	int y;
	/*!
	 * \brief The width of the box in tiles.
	 */
	int width;
	/*!
	 * \brief The height of the box in tiles.
	 */
	int height;
	/*!
	 * \brief The depth/thickness of the box borders in tiles.
	 */
	int depth;
	/*!
	 * \brief The x position of the left border of the crop rect.
	 */
	int crop_x;
	/*!
	 * \brief The y position of the top border of the crop rect.
	 */
	int crop_y;
	/*!
	 * \brief The width of the crop rect in tiles.
	 */
	int crop_width;
	/*!
	 * \brief The height of the crop rect in tiles.
	 */
	int crop_height;
} TuiCroppedBox;
/*!
 * \brief A 2D rect outline iterator.
 */
typedef struct TuiCropBoxIt
{
	/*!
	 * \brief The x position of the left border of the rect.
	 */
	const int left_x;
	/*!
	 * \brief The x position of the right border of the rect.
	 */
	const int right_x;
	/*!
	 * \brief The x position of the top border of the rect.
	 */
	const int top_y;
	/*!
	 * \brief The x position of the bottom border of the rect.
	 */
	const int bottom_y;
	/*!
	 * \brief The depth/thickness of the box borders in tiles.
	 */
	int depth;
	/*!
	 * \brief The current box part being iterated over.
	 */
	TuiBoxPart cur_box_part;
	/*!
	 * \brief The current x position of the iterator.
	 */
	int cur_x_position;
	/*!
	 * \brief The current y position of the iterator.
	 */
	int cur_y_position;
	/*!
	 * \brief The x position of the left border of the crop rect.
	 */
	int crop_x;
	/*!
	 * \brief The y position of the top border of the crop rect.
	 */
	int crop_y;
	/*!
	 * \brief The width of the crop rect in tiles.
	 */
	int crop_width;
	/*!
	 * \brief The height of the crop rect in tiles.
	 */
	int crop_height;
} TuiBoxIt;
/*!
 * \brief A 2D circle.
 */
typedef struct TuiCircle
{
	/*!
	 * \brief The x position of the center of the circle.
	 */
	int center_x;
	/*!
	 * \brief The y position of the center of the circle.
	 */
	int center_y;
	/*!
	 * \brief The radius of the circle.
	 */
	float radius;
} TuiCircle;
/*!
 * \brief A 2D circle iterator.
 */
typedef struct TuiCircleIt
{
	/*!
	 * \brief The radius of the circle.
	 */
	const float radius;
	/*!
	 * \brief The x position of the center of the circle.
	 */
	const int center_x;
	/*!
	 * \brief The y position of the center of the circle.
	 */
	const int center_y;
	/*!
	 * \brief The top y position of the center of the circle.
	 */
	const int top_y;
	/*!
	 * \brief The bottom y position of the center of the circle.
	 */
	const int bottom_y;
	/*!
	 * \brief The left x position of the current row of the circle.
	 */
	int row_left_x;
	/*!
	 * \brief The right x position of the current row of the circle.
	 */
	int row_right_x;
	/*!
	 * \brief The current x position of the iterator.
	 */
	int cur_x_position;
	/*!
	 * \brief The current y position of the iterator.
	 */
	int cur_y_position;
} TuiCircleIt;
/*!
 * \brief A 2D cropped circle.
 */
typedef struct TuiCropCircle
{
	/*!
	 * \brief The x position of the center of the circle.
	 */
	int center_x;
	/*!
	 * \brief The y position of the center of the circle.
	 */
	int center_y;
	/*!
	 * \brief The radius of the circle.
	 */
	float radius;
	/*!
	 * \brief The x position of the left border of the crop rect.
	 */
	int crop_x;
	/*!
	 * \brief The y position of the top border of the crop rect.
	 */
	int crop_y;
	/*!
	 * \brief The width of the crop rect in tiles.
	 */
	int crop_width;
	/*!
	 * \brief The height of the crop rect in tiles.
	 */
	int crop_height;
} TuiCropCircle;
/*!
 * \brief A 2D cropped circle iterator.
 */
typedef struct TuiCropCircleIt
{
	/*!
	 * \brief The radius of the circle.
	 */
	const float radius;
	/*!
	 * \brief The x position of the center of the circle.
	 */
	const int center_x;
	/*!
	 * \brief The y position of the center of the circle.
	 */
	const int center_y;
	/*!
	 * \brief The top y position of the center of the circle.
	 */
	const int top_y;
	/*!
	 * \brief The bottom y position of the center of the circle.
	 */
	const int bottom_y;
	/*!
	 * \brief The left x position of the current row of the circle.
	 */
	int row_left_x;
	/*!
	 * \brief The right x position of the current row of the circle.
	 */
	int row_right_x;
	/*!
	 * \brief The current x position of the iterator.
	 */
	int cur_x_position;
	/*!
	 * \brief The current y position of the iterator.
	 */
	int cur_y_position;
	/*!
	 * \brief The x position of the left border of the crop rect.
	 */
	int crop_x;
	/*!
	 * \brief The y position of the top border of the crop rect.
	 */
	int crop_y;
	/*!
	 * \brief The width of the crop rect in tiles.
	 */
	int crop_width;
	/*!
	 * \brief The height of the crop rect in tiles.
	 */
	int crop_height;
} TuiCropCircleIt;
/*! @} */


#ifdef __cplusplus // extern C guard
}
#endif
#endif // header guard