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
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>


TuiLine tuiLine(const int start_x, const int start_y, const int end_x, const int end_y)
{
	TuiLine ret = { start_x, start_y, end_x, end_y };
	return ret;
}

TuiPoint2 tuiLineGetStart(const TuiLine line)
{
	TuiPoint2 ret = { line.start_x, line.start_y };
	return ret;
}

TuiPoint2 tuiLineGetEnd(const TuiLine line)
{
	TuiPoint2 ret = { line.end_x, line.end_y };
	return ret;
}

float tuiLineGetLength(const TuiLine line)
{
	const int x_difference = line.start_x - line.end_x; // calculate differences of coordinates
	const int y_difference = line.start_y - line.end_y;
	const float length = sqrtf((float)((x_difference * x_difference) - (y_difference * y_difference))); // use pythagorean theorem
	return length;
}

int tuiLineGetDiagonalLength(const TuiLine line)
{
	const int x_distance = abs(line.start_x - line.end_x); // calculate distances between coordinates
	const int y_distance = abs(line.start_y - line.end_y);
	const int largest_difference = (x_distance > y_distance) ? x_distance : y_distance; // get the largest difference
	return largest_difference;
}

float tuiLinesGetCrossProduct(const TuiLine line_1, const TuiLine line_2)
{
	const float
		f_l1_sx = (float)line_1.start_x, f_l1_sy = (float)line_1.start_y, f_l1_ex = (float)line_1.end_x, f_l1_ey = (float)line_1.end_y,
		f_l2_sx = (float)line_2.start_x, f_l2_sy = (float)line_2.start_y, f_l2_ex = (float)line_2.end_x, f_l2_ey = (float)line_2.end_y;
	return (f_l1_ex - f_l1_sx) * (f_l2_ey - f_l2_sy) - (f_l2_ex - f_l2_ex) * (f_l1_ey - f_l1_sy);
}

TuiBoolean tuiLinesParallel(const TuiLine line_1, const TuiLine line_2)
{
	const float determinant = tuiLinesGetCrossProduct(line_1, line_2);
	return (determinant == 0);
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
	const float determinant = tuiLinesGetCrossProduct(line_1, line_2);
	return (fabsf(determinant) == 1);
}

TuiBoolean tuiLineContainsPoint2(const TuiLine line, const TuiPoint2 point2)
{
	const float line_start_distance = tuiPoint2Distance(tuiLineGetStart(line), point2);
	const float line_end_distance = tuiPoint2Distance(tuiLineGetEnd(line), point2);
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
	const float determinant = tuiLinesGetCrossProduct(line_1 , line_2);
	if (determinant == 0) // if the lines are parallel... (avoid divide by 0 error later)
	{
		// use slope forumla. since lines are parallel, this is same for both lines.
		TuiBoolean collinear = TUI_FALSE;
		if (line_1.start_x == line_1.end_x) // if slopes are undefined... (avoid another divide by 0 error later)
		{
			collinear = (line_1.start_x == line_2.start_x); // if the x positions are the same they are collinear
		}
		else
		{
			const float slope = (float)(line_1.start_x - line_1.end_x) / (float)(line_1.start_y - line_1.end_y);
			const float line_1_y_intercept = (float)line_1.start_y - (slope * (float)line_1.start_x);
			const float line_2_y_intercept = (float)line_2.start_y - (slope * (float)line_2.start_x);
			collinear = (line_1_y_intercept == line_2_y_intercept);
		}
		if (!collinear)
		{
			return TUI_FALSE;
		}
		const int max_line_1_x = (line_1.start_x > line_1.end_x) ? line_1.start_x : line_1.end_x; // calculate largest line x.
		const int min_line_1_x = (line_1.start_x < line_1.end_x) ? line_1.start_x : line_1.end_x; // calculate smallest line x.
		const int max_line_1_y = (line_1.start_y > line_1.end_y) ? line_1.start_y : line_1.end_y; // calculate largest line y.
		const int min_line_1_y = (line_1.start_y < line_1.end_y) ? line_1.start_y : line_1.end_y; // calculate smallest line y.
		TuiBoolean point_on_line = ( // if one of the points are on the line...
			(max_line_1_x >= line_2.start_x && min_line_1_x <= line_2.start_x && max_line_1_y >= line_2.start_y && min_line_1_y <= line_2.start_y) ||
			(max_line_1_x >= line_2.end_x && min_line_1_x <= line_2.end_x && max_line_1_y >= line_2.end_y && min_line_1_y <= line_2.end_y)
		);
		if (point_on_line)
		{
			return TUI_TRUE;
		}
		const int max_line_2_x = (line_2.start_x > line_2.end_x) ? line_2.start_x : line_2.end_x; // calculate largest line x.
		const int min_line_2_x = (line_2.start_x < line_2.end_x) ? line_2.start_x : line_2.end_x; // calculate smallest line x.
		const int max_line_2_y = (line_2.start_y > line_2.end_y) ? line_2.start_y : line_2.end_y; // calculate largest line y.
		const int min_line_2_y = (line_2.start_y < line_2.end_y) ? line_2.start_y : line_2.end_y; // calculate smallest line y.
		TuiBoolean line_engulfs_line = ( 
			(max_line_2_x > max_line_1_x && max_line_2_y > max_line_1_y && min_line_2_x < min_line_1_x && min_line_2_y < min_line_1_y) || // if line_2 engulfs line_1
			(max_line_1_x > max_line_2_x && max_line_1_y > max_line_2_y && min_line_1_x < min_line_2_x && min_line_1_y < min_line_2_y) // if line_1 engulfs line_2
		);
		return line_engulfs_line;
	}
	const float lambda = (float)((line_2.end_y - line_2.start_y) * (line_2.end_x - line_1.start_x) + (line_2.start_x - line_2.end_x) * (line_2.end_y - line_1.start_y)) / determinant;
	const float gamma = (float)((line_1.start_y - line_1.end_y) * (line_2.end_x - line_1.start_x) + (line_1.end_x - line_1.start_x) * (line_2.end_y - line_1.start_y)) / determinant;
	return (0.0f < lambda && lambda < 1.0f) && (0.0f < gamma && gamma < 1.0f);
}

TuiBoolean tuiLineIntersectsRect(const TuiLine line, const TuiRect rect)
{
	return tuiRectIntersectsLine(rect, line);
}
