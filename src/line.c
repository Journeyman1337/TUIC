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
#include <TUIC/line.h>
#include <TUIC/point2.h>
#include <TUIC/rect.h>
#include <TUIC/circle.h>
#include "grid_shapes_inline.h"
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>


TuiLine tuiLine(const int start_x, const int start_y, const int end_x, const int end_y)
{
	TuiLine ret = { start_x, start_y, end_x, end_y };
	return ret;
}

int tuiLineGetLeftX(const TuiLine line)
{
	const int left_x = MIN(line.start_x, line.end_x);
	return left_x;
}

int tuiLineGetTopY(const TuiLine line)
{
	const int top_y = MIN(line.start_y, line.end_y);
	return top_y;
}

int tuiLineGetRightX(const TuiLine line)
{
	const int right_x = MAX(line.start_x, line.end_x);
	return right_x;
}

int tuiLineGetBottomY(const TuiLine line)
{
	const int bottom_y = MAX(line.start_y, line.end_y);
	return bottom_y;
}

TuiRect tuiLineGetBoundingRect(const TuiLine line)
{
	const int left_x = tuiLineGetLeftX(line);
	const int top_y = tuiLineGetTopY(line);
	const int right_x = tuiLineGetRightX(line);
	const int bottom_y = tuiLineGetBottomY(line);
	const int width = right_x - left_x;
	const int height = bottom_y - top_y;
	TuiRect ret = tuiRect(left_x, top_y, width, height);
	return ret;
}

TuiPoint2 tuiLineGetStartPoint2(const TuiLine line)
{
	TuiPoint2 ret = { line.start_x, line.start_y };
	return ret;
}

TuiPoint2 tuiLineGetEndPoint2(const TuiLine line)
{
	TuiPoint2 ret = { line.end_x, line.end_y };
	return ret;
}

TuiPoint2 tuiLineGetTranslationPoint2(const TuiLine line)
{
	TuiPoint2 ret = { line.end_x - line.start_x, line.end_y - line.start_y };
	return ret;
}

float tuiLineGetLength(const TuiLine line)
{
	const int x_difference = line.end_x - line.start_x; // calculate difference of x coordinates
	const int y_difference = line.end_y - line.start_y; // calculate difference of y coordinates
	const float length = sqrtf((float)abs((x_difference * x_difference) + (y_difference * y_difference))); // use pythagorean theorem
	return length;
}

int tuiLineGetDiagonalWidth(const TuiLine line)
{
	const int diagonal_width = abs(line.start_x - line.end_x) + 1;
	return diagonal_width;
}

int tuiLineGetDiagonalHeight(const TuiLine line)
{
	const int diagonal_height = abs(line.start_y - line.end_y) + 1;
	return diagonal_height;
}

int tuiLineGetDiagonalLength(const TuiLine line)
{
	const int diagonal_width = tuiLineGetDiagonalWidth(line);
	const int diagonal_height = tuiLineGetDiagonalHeight(line);
	const int diagonal_length = MAX(diagonal_width, diagonal_height);
	return diagonal_length;
}

int tuiLinesGetCrossProductZ(const TuiLine line_1, const TuiLine line_2)
{
	const TuiPoint2 line_1_translation = tuiLineGetTranslationPoint2(line_1);
	const TuiPoint2 line_2_translation = tuiLineGetTranslationPoint2(line_2);
	return (line_1_translation.x * line_2_translation.y) - (line_2_translation.x * line_1_translation.y);
}

int tuiLinesGetDotProduct(const TuiLine line_1, const TuiLine line_2)
{
	const TuiPoint2 line_1_translation = tuiLineGetTranslationPoint2(line_1);
	const TuiPoint2 line_2_translation = tuiLineGetTranslationPoint2(line_2);
	return (line_1_translation.x * line_2_translation.x) + (line_1_translation.y * line_2_translation.y);
}

TuiBoolean tuiLinesParallel(const TuiLine line_1, const TuiLine line_2)
{
	const int cross_product = tuiLinesGetCrossProductZ(line_1, line_2);
	return (cross_product == 0);
}

TuiBoolean tuiLinesCollinear(const TuiLine line_1, const TuiLine line_2)
{
	// Use triangle area formula without division by two.
	const int triangle_1_double_area = (line_1.start_x * (line_1.end_y - line_2.start_y)) + (line_1.end_x * (line_2.start_y - line_1.start_y)) + (line_2.start_x * (line_1.start_y - line_1.end_x)); // between line_1 points and line_2 start point
	const int triangle_2_double_area = (line_1.end_x * (line_1.end_y - line_2.end_y)) + (line_1.end_x * (line_2.end_y - line_1.start_y)) + (line_2.end_x * (line_1.start_y - line_1.end_y)); // between line_1 points and line_2 end point
	const TuiBoolean lines_collinear = (triangle_1_double_area == 0 && triangle_2_double_area == 0); // lines are collinear if both are 0
	return lines_collinear;
}

TuiBoolean tuiLinesPerpendicular(const TuiLine line_1, const TuiLine line_2)
{
	const int dot_product = tuiLinesGetDotProduct(line_1, line_2);
	return (dot_product == 0);
}

TuiBoolean tuiLineContainsPoint2(const TuiLine line, const TuiPoint2 point2)
{
	// if AC is vertical
	if (line.start_x == line.end_x) return line.start_x == point2.x;
	// if AC is horizontal
	if (line.start_y == line.end_y) return line.start_y == point2.y;
	// match the gradients
	return (line.start_x - point2.x) * (line.start_y - point2.y) == (point2.x - line.end_x) * (point2.y - line.end_y);
}

TuiBoolean tuiLineContainsLine(const TuiLine line_1, const TuiLine line_2)
{
	const TuiBoolean lines_are_collinear = tuiLinesCollinear(line_1, line_2); // determine if lines are collinear.
	const int max_line_x = MAX(line_1.start_x, line_1.end_x);
	const int min_line_x = MIN(line_1.start_x, line_1.end_x);
	const int max_line_y = MAX(line_1.start_y, line_1.end_y);
	const int min_line_y = MIN(line_1.start_y, line_1.end_y);
	const TuiBoolean line_contains_line = (
		lines_are_collinear &&
		(max_line_x >= line_2.start_x && max_line_x >= line_2.end_x) &&
		(min_line_x <= line_2.start_x && min_line_x <= line_2.end_x) &&
		(max_line_y >= line_2.start_y && max_line_y >= line_2.end_y) &&
		(min_line_y <= line_2.start_y && min_line_y <= line_2.end_y)
		);
	return line_contains_line;
}

TuiBoolean tuiLineIntersectsLine(const TuiLine line_1, const TuiLine line_2)
{
	const TuiPoint2 line_1_start = tuiLineGetStartPoint2(line_1);
	const TuiPoint2 line_1_end = tuiLineGetEndPoint2(line_1);
	const TuiPoint2 line_2_start = tuiLineGetStartPoint2(line_2);
	const TuiPoint2 line_2_end = tuiLineGetEndPoint2(line_2);
	const TuiPointOrientation orientation_1 = _tuiGetPoint2Orientation(line_1_start, line_1_end, line_2_start);
	const TuiPointOrientation orientation_2 = _tuiGetPoint2Orientation(line_1_start, line_1_end, line_2_end);
	const TuiPointOrientation orientation_3 = _tuiGetPoint2Orientation(line_2_start, line_2_end, line_1_start);
	const TuiPointOrientation orientation_4 = _tuiGetPoint2Orientation(line_2_start, line_2_end, line_1_end);
	return
		(orientation_1 != orientation_2 && orientation_3 != orientation_4) ||
		(orientation_1 == TUI_POINT_ORIENTATION_COLLINEAR && _tuiPoint2BetweenCollinearPoint2(line_1_start, line_2_start, line_1_end)) ||
		(orientation_2 == TUI_POINT_ORIENTATION_COLLINEAR && _tuiPoint2BetweenCollinearPoint2(line_1_start, line_2_end, line_1_end)) ||
		(orientation_3 == TUI_POINT_ORIENTATION_COLLINEAR && _tuiPoint2BetweenCollinearPoint2(line_2_start, line_1_start, line_2_end)) ||
		(orientation_4 == TUI_POINT_ORIENTATION_COLLINEAR && _tuiPoint2BetweenCollinearPoint2(line_2_start, line_1_end, line_2_end));
}

TuiBoolean tuiLineIntersectsRect(const TuiLine line, const TuiRect rect)
{
	return tuiRectIntersectsLine(rect, line);
}

TuiBoolean tuiLineIntersectsCircle(const TuiLine line, const TuiCircle circle)
{
	return tuiCircleIntersectsLine(circle, line);
}