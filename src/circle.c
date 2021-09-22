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
#include <TUIC/circle.h>
#include <TUIC/point2.h>
#include <TUIC/line.h>
#include <TUIC/rect.h>
#include "grid_shapes_inline.h"
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>


TuiCircle tuiCircle(const int center_x, const int center_y, const float radius)
{
	TuiCircle ret = { center_x, center_y, radius };
	return ret;
}

TuiPoint2 tuiCircleGetCenterPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { circle.center_x, circle.center_y };
	return ret;
}

int tuiCircleGetLeftX(const TuiCircle circle)
{
	return circle.center_x - (int)roundf(fabsf(circle.radius));
}

int tuiCircleGetRightX(const TuiCircle circle)
{
	return circle.center_x + (int)roundf(fabsf(circle.radius));
}

int tuiCircleGetTopY(const TuiCircle circle)
{
	return circle.center_y - (int)roundf(fabsf(circle.radius));
}

int tuiCircleGetBottomY(const TuiCircle circle)
{
	return circle.center_y + (int)roundf(fabsf(circle.radius));
}

int tuiCircleGetDimensions(const TuiCircle circle)
{
	return  (int)(roundf(fabsf(circle.radius)) * 2.0f);
}

TuiRect tuiCircleGetBoundingRect(const TuiCircle circle)
{
	const int left_x = tuiCircleGetLeftX(circle);
	const int top_y = tuiCircleGetTopY(circle);
	const int dimensions = tuiCircleGetDimensions(circle);
	const TuiRect ret = tuiRect(left_x, top_y, dimensions, dimensions);
	return ret;
}

TuiPoint2 tuiCircleGetLeftPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { tuiCircleGetLeftX(circle), circle.center_y };
	return ret;
}

TuiPoint2 tuiCircleGetTopPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { circle.center_x,  tuiCircleGetTopY(circle)};
	return ret;
}

TuiPoint2 tuiCircleGetRightPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { tuiCircleGetRightX(circle), circle.center_y };
	return ret;
}


TuiPoint2 tuiCircleGetBottomPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { circle.center_x, tuiCircleGetBottomY(circle) };
	return ret;
}

TuiBoolean tuiCircleIsDegenerate(const TuiCircle circle)
{
	return (fabsf(circle.radius) <= 0.5f);
}

TuiBoolean tuiCircleContainsPoint2(const TuiCircle circle, const TuiPoint2 point2)
{
	const float abs_radius = fabsf(circle.radius);
	if (abs_radius < 0.5f) return TUI_FALSE;
	const float point_circle_center_distance = _tuiIntPointDistance(circle.center_x, circle.center_y, point2.x, point2.y);
	return point_circle_center_distance < abs_radius;
}

TuiBoolean tuiCircleContainsLine(const TuiCircle circle, const TuiLine line)
{
	if (tuiCircleIsDegenerate(circle)) return TUI_FALSE;
	return tuiCircleContainsPoint2(circle, tuiLineGetStartPoint2(line)) && tuiCircleContainsPoint2(circle, tuiLineGetEndPoint2(line));
}

TuiBoolean tuiCircleContainsRect(const TuiCircle circle, const TuiRect rect)
{
	if (tuiCircleIsDegenerate(circle) || tuiRectIsDegenerate(rect)) return TUI_FALSE;
	return
		tuiCircleContainsPoint2(circle, tuiRectGetTopRightCornerPoint2(rect)) &&
		tuiCircleContainsPoint2(circle, tuiRectGetTopLeftCornerPoint2(rect)) &&
		tuiCircleContainsPoint2(circle, tuiRectGetBottomRightCornerPoint2(rect)) &&
		tuiCircleContainsPoint2(circle, tuiRectGetBottomLeftCornerPoint2(rect));
}

TuiBoolean tuiCircleContainsCircle(const TuiCircle circle_1, const TuiCircle circle_2)
{
	if (tuiCircleIsDegenerate(circle_1) || tuiCircleIsDegenerate(circle_2)) return TUI_FALSE;
	return
		tuiCircleContainsPoint2(circle_1, tuiCircleGetCenterPoint2(circle_2)) &&
		tuiCircleContainsPoint2(circle_1, tuiCircleGetLeftPoint2(circle_2)) &&
		tuiCircleContainsPoint2(circle_1, tuiCircleGetTopPoint2(circle_2)) &&
		tuiCircleContainsPoint2(circle_1, tuiCircleGetRightPoint2(circle_2)) &&
		tuiCircleContainsPoint2(circle_1, tuiCircleGetBottomPoint2(circle_2));
}

TuiBoolean tuiCircleIntersectsLine(const TuiCircle circle, const TuiLine line)
{
	const float abs_radius = fabsf(circle.radius);
	if (abs_radius < 0.5f) return TUI_FALSE;
	const float point_line_distance = _tuiIntPointLineDistance(circle.center_x, circle.center_y, line.start_x, line.start_y, line.end_x, line.end_y);
	return point_line_distance <= abs_radius;
}

TuiBoolean tuiCircleIntersectsRect(const TuiCircle circle, const TuiRect rect)
{
	if (tuiRectIsDegenerate(rect)) return TUI_FALSE;
	const float abs_radius = fabsf(circle.radius);
	if (abs_radius < 0.5f) return TUI_FALSE;
	const TuiBoolean circle_intersects_rect_border = (
			tuiCircleIntersectsLine(circle, tuiRectGetLeftInnerBorderLine(rect, TUI_TRUE)) ||
			tuiCircleIntersectsLine(circle, tuiRectGetRightInnerBorderLine(rect, TUI_TRUE)) ||
			tuiCircleIntersectsLine(circle, tuiRectGetTopInnerBorderLine(rect, TUI_TRUE)) ||
			tuiCircleIntersectsLine(circle, tuiRectGetBottomInnerBorderLine(rect, TUI_TRUE))
		);
	if (circle_intersects_rect_border) return TUI_TRUE;
	const TuiBoolean circle_contains_rect = tuiCircleContainsPoint2(circle, tuiRectGetTopLeftCornerPoint2(rect));
	return circle_contains_rect;
}

TuiBoolean tuiCircleIntersectsCircle(const TuiCircle circle_1, const TuiCircle circle_2)
{
	const float abs_radius_1 = fabsf(circle_1.radius);
	const float abs_radius_2 = fabsf(circle_2.radius);
	if (abs_radius_1 < 0.5f || abs_radius_2 < 0.5f) return TUI_FALSE;
	const float point_distance = tuiPoint2GetDistanceToPoint2(tuiCircleGetCenterPoint2(circle_1), tuiCircleGetCenterPoint2(circle_2));
	const float combined_radius = abs_radius_1 + abs_radius_2;
	return (point_distance < combined_radius);
}
