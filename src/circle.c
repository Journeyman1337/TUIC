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
	return (int)roundf((float)circle.center_x - circle.radius);
}

int tuiCircleGetRightX(const TuiCircle circle)
{
	return (int)roundf((float)circle.center_x + circle.radius);
}

int tuiCircleGetTopY(const TuiCircle circle)
{
	return (int)roundf((float)circle.center_y - circle.radius);
}

int tuiCircleGetBottomY(const TuiCircle circle)
{
	return (int)roundf((float)circle.center_y + circle.radius);
}

TuiRect tuiCircleGetBoundingRect(const TuiCircle circle)
{
	const int left_x = tuiCircleGetLeftX(circle);
	const int right_x = tuiCircleGetRightX(circle);
	const int top_y = tuiCircleGetTopY(circle);
	const int bottom_y = tuiCircleGetBottomY(circle);
	const TuiRect ret = tuiRect(left_x, top_y, right_x - left_x, bottom_y - top_y);
	return ret;
}

TuiPoint2 tuiCircleGetTopPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { circle.center_x,  tuiCircleGetTopY(circle)};
	return ret;
}

TuiPoint2 tuiCircleGetLeftPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { tuiCircleGetLeftX(circle), circle.center_y };
	return ret;
}

TuiPoint2 tuiCircleGetBottomPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { circle.center_x, tuiCircleGetBottomY(circle) };
	return ret;
}

TuiPoint2 tuiCircleGetRightPoint2(const TuiCircle circle)
{
	TuiPoint2 ret = { tuiCircleGetRightX(circle), circle.center_y };
	return ret;
}

TuiBoolean tuiCircleIsDegenerate(const TuiCircle circle)
{
	return (circle.radius < 0);
}

TuiBoolean tuiCircleContainsPoint2(const TuiCircle circle, const TuiPoint2 point2)
{
	const float circle_border_squared_distance = (float)((point2.x * point2.x) + (point2.y * point2.y)) - (circle.radius * circle.radius);
	return circle_border_squared_distance <= 0.0f;
}

TuiBoolean tuiCircleContainsLine(const TuiCircle circle, const TuiLine line)
{
	return tuiCircleContainsPoint2(circle, tuiLineGetStartPoint2(line)) && tuiCircleContainsPoint2(circle, tuiLineGetEndPoint2(line));
}

TuiBoolean tuiCircleContainsRect(const TuiCircle circle, const TuiRect rect)
{
	return
		tuiCircleContainsPoint2(circle, tuiRectGetTopRightInnerCornerPoint2(rect)) &&
		tuiCircleContainsPoint2(circle, tuiRectGetTopLeftInnerCornerPoint2(rect)) &&
		tuiCircleContainsPoint2(circle, tuiRectGetBottomRightInnerCornerPoint2(rect)) &&
		tuiCircleContainsPoint2(circle, tuiRectGetBottomLeftInnerCornerPoint2(rect));
}

TuiBoolean tuiCircleContainsCircle(const TuiCircle circle_1, const TuiCircle circle_2)
{
	return
		tuiCircleContainsPoint2(circle_1, tuiCircleGetCenterPoint2(circle_2)) &&
		tuiCircleContainsPoint2(circle_1, tuiCircleGetLeftPoint2(circle_2)) &&
		tuiCircleContainsPoint2(circle_1, tuiCircleGetTopPoint2(circle_2)) &&
		tuiCircleContainsPoint2(circle_1, tuiCircleGetRightPoint2(circle_2)) &&
		tuiCircleContainsPoint2(circle_1, tuiCircleGetBottomPoint2(circle_2));
}

TuiBoolean tuiCircleIntersectsLine(const TuiCircle circle, const TuiLine line)
{
	if (circle.radius < 0.5f) return TUI_FALSE;
	TuiPoint2 start_point = tuiLineGetStartPoint2(line);
	TuiPoint2 end_point = tuiLineGetEndPoint2(line);
	if (tuiCircleContainsPoint2(circle, start_point) || tuiCircleContainsPoint2(circle, end_point)) return TUI_TRUE;
	const float line_length = tuiLineGetLength(line);
	const float dot_product = (((circle.center_x - line.start_x) * (line.end_x - line.start_x)) + ((circle.center_y - line.start_y) * (line.end_y - line.start_y))) / (line_length * line_length);
	const float closest_x = roundf(line.start_x + (dot_product * (line.end_x - line.start_x)));
	const float closest_y = roundf(line.start_y + (dot_product * (line.end_y - line.start_y)));
	if (!_tuiPoint2BetweenCollinearPoint2(start_point, end_point, tuiPoint2((int)closest_x, (int)closest_y))) return TUI_FALSE;
	const float distance_x = closest_x - circle.center_x;
	const float distance_y = closest_y - circle.center_y;
	const float distance = sqrtf((distance_x * distance_x) + (distance_y * distance_y));
	return (distance <= circle.radius);
}

TuiBoolean tuiCircleIntersectsRect(const TuiCircle circle, const TuiRect rect)
{
	if (rect.width <= 0 || rect.height <= 0 || circle.radius < 0.5f) return TUI_FALSE;
	const TuiPoint2 closest_rect_point = tuiPoint2(CLAMP(rect.x, rect.x + rect.width - 1, circle.center_x), CLAMP(rect.y, rect.y + rect.height - 1, circle.center_y));
	const float point_distance = tuiPoint2GetDistance(tuiCircleGetCenterPoint2(circle), closest_rect_point);
	return (point_distance <= circle.radius);
}

TuiBoolean tuiCircleIntersectsCircle(const TuiCircle circle_1, const TuiCircle circle_2)
{
	if (circle_1.radius < 0.5f || circle_2.radius < 0.5f) return TUI_FALSE;
	const float point_distance = tuiPoint2GetDistance(tuiCircleGetCenterPoint2(circle_1), tuiCircleGetCenterPoint2(circle_2));
	const float combined_radius = circle_1.radius + circle_2.radius;
	return (point_distance < combined_radius);
}
