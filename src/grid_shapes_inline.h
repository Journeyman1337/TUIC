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
#include "math.h"


// Get the highest value between two values.
#define MAX(a, b) ((a > b) ? a : b)
// Get the lowest value between two values.
#define MIN(a, b) ((a < b) ? a : b)
// Clamp a value between a minimum and maximum value.
#define CLAMP(min, max, value) value < min ? min : (value > max ? max : value)
// Get the sign of a value (1 if number is positive or 0, or -1 if number is negative).
#define SIGN(x) ((x > 0) - (x < 0))

// The orientation of three points.
typedef enum TuiPointOrientation
{
	// The points are on the same line.
	TUI_POINT_ORIENTATION_COLLINEAR = 0,
	// The points make a clockwise triangle.
	TUI_POINT_ORIENTATION_CLOCKWISE = 1,
	// The points make a counterclockwise triangle.
	TUI_POINT_ORIENTATION_COUNTERCLOCKWISE = 2
} TuiPointOrientation;

// Get the orientation between three points.
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

static inline TuiBoolean _tuiPoint2Collienar(const TuiPoint2 point2_1, const TuiPoint2 point2_2, const TuiPoint2 point2_3)
{
	const int determinant = point2_1.x * (point2_2.y - point2_3.y) +
		point2_2.x * (point2_3.y - point2_1.y) +
		point2_3.x * (point2_1.y - point2_2.y);

	return (determinant == 0);
}

static inline float _tuiIntPointMagnitude(const int x, const int y)
{
	return sqrtf((float)abs((x * x) + (y * y))); // point distance formula (based on pythagorean theorem)
}

static inline float _tuiIntPointDistance(const int x_1, const int y_1, const int x_2, const int y_2)
{
	const int x_distance = x_2 - x_1;
	const int y_distance = y_2 - y_1;
	return _tuiIntPointMagnitude(x_distance, y_distance);
}

static inline int _tuiIntCrossProductZ(const int x_1, const int y_1, const int x_2, const int y_2)
{
	return (x_1 * y_2) - (x_2 * y_1);
}

static inline float _tuiIntUnitCrossProductZ(const int x_1, const int y_1, const int x_2, const int y_2)
{
	const int cross_z = _tuiIntCrossProductZ(x_1, y_1, x_2, y_2);
	const float magnitude_1 = _tuiIntPointMagnitude(x_1, y_1);
	const float magnitude_2 = _tuiIntPointMagnitude(x_2, y_2);
	if (magnitude_1 == 0.0f || magnitude_2 == 0.0f) return 0.0f;
	return (float)cross_z / (magnitude_1 * magnitude_2);
}

static inline int _tuiIntDotProduct(const int x_1, const int y_1, const int x_2, const int y_2)
{
	return (x_1 * x_2) + (y_2 * y_1);
}

static inline float _tuiIntUnitDotProduct(const int x_1, const int y_1, const int x_2, const int y_2)
{
	const int dot = _tuiIntDotProduct(x_1, y_1, x_2, y_2);
	const float distance = _tuiIntPointDistance(x_1, x_2, y_1, y_2);
	if (distance == 0.0f) return 0.0f;
	return (float)dot / (distance * distance);
}

static inline float _tuiIntPointLineDistance(const int p_x, const int p_y, const int l_sx, const int l_sy, const int l_ex, const int l_ey)
{
	if (l_sx == l_ex && l_sy == l_ey)
	{
		return _tuiIntPointDistance(p_x, p_y, l_sx, l_sy);
	}
	const TuiPoint2 line_translation = { l_ex - l_sx, l_ey - l_sy };
	const TuiPoint2 line_start_point_translation = { p_x - l_sx, p_y - l_sy };
	const TuiPoint2 line_end_point_translation = { p_x - l_ex, p_y - l_ey };
	if (_tuiIntDotProduct(line_translation.x, line_translation.y, line_start_point_translation.x, line_start_point_translation.y) < 0)
	{
		return _tuiIntPointDistance(l_sx, l_sy, p_x, p_y);
	}
	else if (_tuiIntDotProduct(line_translation.x, line_translation.y, line_end_point_translation.x, line_end_point_translation.y) > 0)
	{
		return _tuiIntPointDistance(l_ex, l_ey, p_x, p_y);
	}
	else
	{
		const float line_length = _tuiIntPointDistance(l_sx, l_sy, l_ex, l_ey);
		const int numerator = abs(((l_ex - l_sx) * (l_sy - p_y)) - ((l_sx - p_x) * (l_ey - l_sy)));
		return (float)numerator / line_length;
	}
}

#endif //header guard