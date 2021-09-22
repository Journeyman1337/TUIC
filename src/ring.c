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
#include <TUIC/ring.h>
#include <TUIC/point2.h>
#include <TUIC/line.h>
#include <TUIC/rect.h>
#include <TUIC/circle.h>
#include "grid_shapes_inline.h"
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>

TuiRing tuiRing(const int center_x, const int center_y, const float radius, const float depth)
{
	TuiRing ret = { center_x, center_y, radius, depth };
	return ret;
}

TuiPoint2 tuiRingGetCenterPoint2(const TuiRing ring)
{
	TuiPoint2 ret = { ring.center_x, ring.center_y };
	return ret;
}

int tuiRingGetLeftX(const TuiRing ring)
{
	const int left_x = ring.center_x - (int)roundf(fabsf(ring.radius));
	return left_x;
}

int tuiRingGetRightX(const TuiRing ring)
{
	const int right_x = ring.center_x + (int)roundf(fabsf(ring.radius));
	return right_x;
}

int tuiRingGetTopY(const TuiRing ring)
{
	const int top_y = ring.center_y - (int)roundf(fabsf(ring.radius));
	return top_y;
}

int tuiRingGetBottomY(const TuiRing ring)
{
	const int bottom_y = ring.center_y + (int)roundf(fabsf(ring.radius));
	return bottom_y;
}

float tuiRingGetInnerRadius(const TuiRing ring)
{
	const float inner_radius = fabsf(ring.radius) - fabsf(ring.depth);
	return inner_radius;
}

int tuiRingGetInnerLeftX(const TuiRing ring)
{
	const float inner_radius = tuiRingGetInnerRadius(ring);
	const int inner_left_x = ring.center_x - (int)roundf(inner_radius);
	return inner_left_x;
}

int tuiRingGetInnerRightX(const TuiRing ring)
{
	const float inner_radius = tuiRingGetInnerRadius(ring);
	const int inner_right_x = ring.center_x + (int)roundf(inner_radius);
	return inner_right_x;
}

int tuiRingGetInnerTopY(const TuiRing ring)
{
	const float inner_radius = tuiRingGetInnerRadius(ring);
	const int inner_top_y = ring.center_y - (int)roundf(inner_radius);
	return inner_top_y;
}

int tuiRingGetInnerBottomY(const TuiRing ring)
{
	const float inner_radius = tuiRingGetInnerRadius(ring);
	const int inner_bottom_y = ring.center_y + (int)roundf(inner_radius);
}

int tuiRingGetDimensions(const TuiRing ring)
{
	const int dimensions = (int)(roundf(fabsf(ring.radius)) * 2.0f);
	return dimensions;
}

int tuiRingGetInnerDimensions(const TuiRing ring)
{
	const int inner_radius = tuiRingGetInnerRadius(ring);
	const int inner_dimensions = inner_radius * 2;
	return inner_dimensions;
}

TuiCircle tuiRingGetCircle(const TuiRing ring)
{
	const TuiCircle ret = { ring.center_x, ring.center_y, ring.radius };
	return ret;
}

TuiCircle tuiRingGetInnerCircle(const TuiRing ring)
{
	const TuiCircle ret = { ring.center_x, ring.center_y, tuiRingGetInnerRadius(ring) };
	return ret;
}

TuiRect tuiRingGetBoundingRect(const TuiRing ring)
{
	const int left_x = tuiRingGetLeftX(ring);
	const int top_y = tuiRingGetTopY(ring);
	const int dimensions = tuiRingGetDimensions(ring);
	const TuiRect ret = tuiRect(left_x, top_y, dimensions, dimensions);
	return ret;
}

TuiRect tuiRingGetInnerBoundingRect(const TuiRing ring)
{
	const int inner_left_x = tuiRingGetInnerLeftX(ring);
	const int inner_top_y = tuiRingGetInnerTopY(ring);
	const int inner_dimensions = tuiRingGetInnerDimensions(ring);
	const TuiRect ret = tuiRect(inner_left_x, inner_top_y, inner_dimensions, inner_dimensions);
	return ret;
}

TuiPoint2 tuiRingGetLeftPoint2(const TuiRing ring)
{
	const int left_x = tuiRingGetLeftX(ring);
	const TuiPoint2 ret = { left_x, ring.center_y };
	return ret;
}

TuiPoint2 tuiRingGetRightPoint2(const TuiRing ring)
{
	const int right_x = tuiRingGetRightX(ring);
	const TuiPoint2 ret = { right_x, ring.center_y };
	return ret;
}

TuiPoint2 tuiRingGetTopPoint2(const TuiRing ring)
{
	const int top_y = tuiRingGetTopY(ring);
	const TuiPoint2 ret = { ring.center_x, top_y };
	return ret;
}

TuiPoint2 tuiRingGetBottomPoint2(const TuiRing ring)
{
	const int bottom_y = tuiRingGetBottomY(ring);
	const TuiPoint2 ret = { ring.center_x, bottom_y };
	return ret;
}

TuiPoint2 tuiRingGetInnerLeftPoint2(const TuiRing ring)
{
	const int inner_left_x = tuiRingGetInnerLeftX(ring);
	const TuiPoint2 ret = { inner_left_x, ring.center_y };
	return ret;
}

TuiPoint2 tuiRingGetInnerRightPoint2(const TuiRing ring)
{
	const int inner_right_x = tuiRingGetInnerRightX(ring);
	const TuiPoint2 ret = { inner_right_x, ring.center_y };
	return ret;
}

TuiPoint2 tuiRingGetInnerTopPoint2(const TuiRing ring)
{
	const int  inner_top_y = tuiRingGetInnerTopY(ring);
	const TuiPoint2 ret = { ring.center_x,  inner_top_y };
	return ret;
}

TuiPoint2 tuiRingGetInnerBottomPoint2(const TuiRing ring)
{
	const int  inner_bottom_y = tuiRingGetInnerBottomY(ring);
	const TuiPoint2 ret = { ring.center_x,  inner_bottom_y };
	return ret;
}

TuiBoolean tuiRingIsDegenerate(const TuiRing ring)
{
	const float abs_radius = fabsf(ring.radius);
	const float abs_depth = fabsf(ring.depth);
	const TuiBoolean is_degenerate = (abs_radius < 0.5f || abs_depth < 0.5f);
	return is_degenerate;
}

TuiBoolean tuiRingContainsPoint2(const TuiRing ring, const TuiPoint2 point2)
{
	const float abs_radius = fabsf(ring.radius);
	const float abs_depth = fabsf(ring.depth);
	if (abs_radius < 0.5f || abs_depth < 0.5f) return TUI_FALSE;
	const float inner_radius = abs_radius - abs_depth;
	const float point_ring_center_distance = _tuiIntPointDistance(ring.center_x, ring.center_y, point2.x, point2.y);
	const TuiBoolean point_in_ring = (point_ring_center_distance >= inner_radius && point_ring_center_distance <= abs_radius);
	return point_in_ring;
}

TuiBoolean tuiRingIntersetsLine(const TuiRing ring, const TuiLine line)
{
	const float abs_radius = fabsf(ring.radius);
	const float abs_depth = fabsf(ring.depth);
	if (abs_radius < 0.5f || abs_depth < 0.5f) return TUI_FALSE;
	const float inner_radius = abs_radius - abs_depth;
	const TuiCircle inner_circle = { ring.center_x, ring.center_y, inner_radius };
	const TuiBoolean inner_circle_contains_line = tuiCircleContainsLine(inner_circle, line);
	if (inner_circle_contains_line) return TUI_TRUE;
	const TuiCircle outer_circle = { ring.center_x, ring.center_y, ring.radius };
	const TuiBoolean outer_circle_intersects_line = tuiCircleIntersectsLine(outer_circle, line);
	if (outer_circle_intersects_line) return TUI_TRUE;
}

TuiBoolean tuiRingIntersectsRect(const TuiRing ring, const TuiRect rect)
{
	if (tuiRectIsDegenerate(rect)) return TUI_FALSE;
	const float abs_radius = fabsf(ring.radius);
	const float abs_depth = fabsf(ring.depth);
	if (abs_radius < 0.5f || abs_depth < 0.5f) return TUI_FALSE;
	const float inner_radius = abs_radius - abs_depth;
	const TuiCircle ring_circle = { ring.center_x, ring.center_y, ring.radius };
	const TuiCircle ring_inner_circle = { ring.center_x, ring.center_y, inner_radius };
	const TuiBoolean ring_intersects_rect_border = (
		tuiCircleIntersectsLine(ring_circle, tuiRectGetLeftInnerBorderLine(rect, TUI_TRUE)) ||
		tuiCircleIntersectsLine(ring_circle, tuiRectGetRightInnerBorderLine(rect, TUI_TRUE)) ||
		tuiCircleIntersectsLine(ring_circle, tuiRectGetTopInnerBorderLine(rect, TUI_TRUE)) ||
		tuiCircleIntersectsLine(ring_circle, tuiRectGetBottomInnerBorderLine(rect, TUI_TRUE)) ||
		tuiCircleIntersectsLine(ring_inner_circle, tuiRectGetLeftInnerBorderLine(rect, TUI_TRUE)) ||
		tuiCircleIntersectsLine(ring_inner_circle, tuiRectGetRightInnerBorderLine(rect, TUI_TRUE)) ||
		tuiCircleIntersectsLine(ring_inner_circle, tuiRectGetTopInnerBorderLine(rect, TUI_TRUE)) ||
		tuiCircleIntersectsLine(ring_inner_circle, tuiRectGetBottomInnerBorderLine(rect, TUI_TRUE))
		);
	if (ring_intersects_rect_border) return TUI_TRUE;
	const TuiBoolean circle_contains_rect = tuiRingContainsPoint2(ring, tuiRectGetTopLeftCornerPoint2(rect));
	return circle_contains_rect;
}

TuiBoolean tuiRingIntersectsCircle(const TuiRing ring, const TuiCircle circle)
{
	if (tuiCircleIsDegenerate(circle)) return TUI_FALSE;
	const float abs_radius = fabsf(ring.radius);
	const float abs_depth = fabsf(ring.depth);
	if (abs_radius < 0.5f || abs_depth < 0.5f) return TUI_FALSE;
	const float inner_radius = abs_radius - abs_depth;
	const TuiCircle inner_circle = { ring.center_x, ring.center_y, inner_radius };
	const TuiBoolean inner_circle_contains_circle = tuiCircleContainsCircle(inner_circle, circle);
	if (inner_circle_contains_circle) return TUI_FALSE;
	const TuiCircle outer_circle = { ring.center_x, ring.center_y, ring.radius };
	const TuiBoolean outer_circle_intersects_circle = tuiCircleIntersectsCircle(outer_circle, circle);
	if (outer_circle_intersects_circle) return TUI_TRUE;
}

TuiBoolean tuiRingIntersectsRing(const TuiRing ring_1, const TuiRing ring_2)
{
	const float ring_1_abs_radius = fabsf(ring_1.radius);
	const float ring_1_abs_depth = fabsf(ring_1.depth);
	if (ring_1_abs_radius < 0.5f || ring_1_abs_depth < 0.5f) return TUI_FALSE;
	const float ring_2_abs_radius = fabsf(ring_2.radius);
	const float ring_2_abs_depth = fabsf(ring_2.depth);
	if (ring_2_abs_radius < 0.5f || ring_2_abs_depth < 0.5f) return TUI_FALSE;
	const float ring_1_inner_radius = ring_1_abs_radius - ring_1_abs_depth;
	const TuiCircle  ring_1_inner_circle = { ring_1.center_x, ring_1.center_y,  ring_1_inner_radius };
	const TuiCircle ring_2_outer_circle = { ring_2.center_x, ring_2.center_y, ring_2.radius };
	const TuiBoolean ring_1_inner_circle_contains_ring_2 = tuiCircleContainsCircle(ring_1_inner_circle, ring_2_outer_circle);
	if (ring_1_inner_circle_contains_ring_2) return TUI_FALSE;
	const float ring_2_inner_radius = ring_2_abs_radius - ring_2_abs_depth;
	const TuiCircle ring_2_inner_circle = { ring_2.center_x, ring_2.center_y, ring_2_inner_radius };
	const TuiCircle ring_1_outer_circle = { ring_1.center_x, ring_1.center_y, ring_1.radius };
	const TuiBoolean ring_2_inner_circle_contains_ring_1 = tuiCircleContainsCircle(ring_2_inner_circle, ring_1_outer_circle);
	if (ring_2_inner_circle_contains_ring_1) return TUI_FALSE;
	const TuiBoolean ring_1_intersects_ring_2_outer_circle = tuiCircleIntersectsCircle(ring_1_outer_circle, ring_2_outer_circle);
	if (ring_1_intersects_ring_2_outer_circle) return TUI_TRUE;
	const TuiBoolean ring_1_intersects_ring_2_inner_circle = tuiCircleIntersectsCircle(ring_1_outer_circle, ring_2_inner_circle);
	if (ring_1_intersects_ring_2_inner_circle) return TUI_TRUE;
}