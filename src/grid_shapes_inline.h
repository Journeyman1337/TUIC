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

typedef enum TuiPointOrientation
{
	TUI_POINT_ORIENTATION_COLLINEAR = 0,
	TUI_POINT_ORIENTATION_CLOCKWISE = 1,
	TUI_POINT_ORIENTATION_COUNTERCLOCKWISE = 2
} TuiPointOrientation;

static inline TuiPointOrientation _tuiGetPoint2Orientation(const TuiPoint2 a, const TuiPoint2 b, const TuiPoint2 c)
{
	const int orientation_determinant = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	TuiPointOrientation orientation =
		(orientation_determinant == 0) ?
			TUI_POINT_ORIENTATION_COLLINEAR :
		(orientation_determinant > 0) ?
			TUI_POINT_ORIENTATION_CLOCKWISE :
		// (orientation_determinant < 0) ?
			TUI_POINT_ORIENTATION_COUNTERCLOCKWISE;
	return orientation;
}	

static inline TuiBoolean _tuiPoint2BetweenCollinearPoint2(const TuiPoint2 surround_point_1, const TuiPoint2 surround_point_2, const TuiPoint2 between_point)
{
	return
		(
			surround_point_2.x <= MAX(surround_point_1.x, between_point.x) && 
			surround_point_2.x >= MIN(surround_point_1.x, between_point.x) &&
			surround_point_2.y <= MAX(surround_point_1.y, between_point.y) && 
			surround_point_2.y >= MIN(surround_point_1.y, between_point.y)
		);
}


#endif //header guard