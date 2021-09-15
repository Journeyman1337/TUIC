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
#ifndef TUIC_GRID_SHAPES_INLINE_H //header guard
#define TUIC_GRID_SHAPES_INLINE_H
#include <TUIC/point2.h>
#include <TUIC/boolean.h>


#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define CLAMP(min, max, value) value < min ? min : (value > max ? max : value)
#define SIGN(x) ((x > 0) - (x < 0))


static inline int _Point2Cross(const TuiPoint2 point2_1, const TuiPoint2 point2_2, const TuiPoint2 point2_3)
{
	return (point2_3.x - point2_2.x) * (point2_2.y - point2_1.y) - (point2_2.x - point2_1.x) * (point2_3.y - point2_2.y);
}
static inline TuiBoolean _Point2OnCollinearLine(const TuiPoint2 line_start, const TuiPoint2 line_end, const TuiPoint2 point)
{
	return (
		(point.x <= MAX(line_start.x, line_end.x)) &&
		(point.x >= MIN(line_start.x, line_end.x)) &&
		(point.y <= MAX(line_start.y, line_end.y)) &&
		(point.y >= MIN(line_start.y, line_end.y))
		);
}


#endif //header guard