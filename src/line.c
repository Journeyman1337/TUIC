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
#include "grid_shapes_inline.h"
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>


TuiLine tuiLine(const int start_x, const int start_y, const int end_x, const int end_y)
{
	TuiLine ret = { start_x, start_y, end_x, end_y };
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

float tuiLineGetLength(const TuiLine line)
{
	const int x_difference = line.start_x - line.end_x; // calculate difference of x coordinates
	const int y_difference = line.start_y - line.end_y; // calculate difference of y coordinates
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

int tuiLinesGetCrossProduct(const TuiLine line_1, const TuiLine line_2)
{
	return (line_1.end_x - line_1.start_x) * (line_2.end_y - line_2.start_y) + (line_2.end_x - line_2.start_x) * (line_1.end_y - line_1.start_y);
}

float tuiLinesGetDotProduct(const TuiLine line_1, const TuiLine line_2)
{
	const float line_1_length = tuiLineGetLength(line_1);
	const float line_2_length = tuiLineGetLength(line_2);
	const float line_1_unit_x = (float)(line_1.end_x - line_1.start_x) / line_1_length;
	const float line_1_unit_y = (float)(line_1.end_y - line_1.start_y) / line_1_length;
	const float line_2_unit_x = (float)(line_2.end_x - line_2.start_x) / line_2_length;
	const float line_2_unit_y = (float)(line_2.end_y - line_2.start_y) / line_2_length;
	return (line_1_unit_x * line_2_unit_x) + (line_1_unit_y * line_2_unit_y);
}

TuiBoolean tuiLinesParallel(const TuiLine line_1, const TuiLine line_2)
{
	const int cross_product = tuiLinesGetCrossProduct(line_1, line_2);
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
	const float dot_product = tuiLinesGetDotProduct(line_1, line_2);
	return (dot_product == 0.0f);
}

TuiBoolean tuiLineContainsPoint2(const TuiLine line, const TuiPoint2 point2)
{
	const float line_start_distance = tuiPoint2Distance(tuiLineGetStartPoint2(line), point2);
	const float line_end_distance = tuiPoint2Distance(tuiLineGetEndPoint2(line), point2);
	const float line_length = tuiLineGetLength(line);
	const TuiBoolean point_on_line = (line_length == line_start_distance + line_end_distance); // point is on line if distance from line start to point added to distance from line end to point is equal to line length
	return point_on_line;
}

TuiBoolean tuiLineContainsLine(const TuiLine line_1, const TuiLine line_2)
{
	const TuiBoolean lines_are_collinear = tuiLinesCollinear(line_1, line_2); // determine if lines are collinear.
	const int max_line_x = (line_1.start_x > line_1.end_x) ? line_1.start_x : line_1.end_x; // calculate largest line x.
	const int min_line_x = (line_1.start_x < line_1.end_x) ? line_1.start_x : line_1.end_x; // calculate smallest line x.
	const int max_line_y = (line_1.start_y > line_1.end_y) ? line_1.start_y : line_1.end_y; // calculate largest line y.
	const int min_line_y = (line_1.start_y < line_1.end_y) ? line_1.start_y : line_1.end_y; // calculate smallest line y.
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
	const TuiPoint2 line_1_start_point2 = tuiLineGetStartPoint2(line_1);
	const TuiPoint2 line_1_end_point2 = tuiLineGetEndPoint2(line_1);
	const TuiPoint2 line_2_start_point2 = tuiLineGetStartPoint2(line_2);
	const TuiPoint2 line_2_end_point2 = tuiLineGetEndPoint2(line_2);
	const int cross_1 = _Point2Cross(line_1_start_point2, line_2_start_point2, line_1_end_point2);
	const int cross_2 = _Point2Cross(line_1_start_point2, line_2_start_point2, line_2_end_point2);
	if (SIGN(cross_1) != SIGN(cross_2)) // if sign of cross_1 is not equal to sign of cross_2
	{
		return TUI_TRUE;
	}
	const int cross_3 = _Point2Cross(line_1_end_point2, line_2_end_point2, line_1_start_point2);
	const int cross_4 = _Point2Cross(line_1_end_point2, line_2_end_point2, line_2_start_point2);
	return (
		(SIGN(cross_3) != SIGN(cross_4)) || // if sign of cross_3 is not equal to sign of cross_4
		(cross_1 == 0 && _Point2OnCollinearLine(line_1_start_point2, line_2_start_point2, line_1_end_point2)) ||
		(cross_2 == 0 && _Point2OnCollinearLine(line_1_start_point2, line_2_start_point2, line_2_end_point2)) ||
		(cross_3 == 0 && _Point2OnCollinearLine(line_1_end_point2, line_2_end_point2, line_1_start_point2)) ||
		(cross_4 == 0 && _Point2OnCollinearLine(line_1_end_point2, line_2_end_point2, line_2_start_point2))
		);
}

TuiBoolean tuiLineIntersectsRect(const TuiLine line, const TuiRect rect)
{
	return tuiRectIntersectsLine(rect, line);
}
