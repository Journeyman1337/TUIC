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
#include <TUIC/crop_ring.h>
#include <TUIC/box.h>
#include <TUIC/circle.h>
#include <TUIC/point2.h>
#include <TUIC/line.h>
#include <TUIC/rect.h>
#include <TUIC/ring.h>
#include "grid_shapes_inline.h"
#include "math_inline.h"
#include <stdlib.h>
#include <TUIC/easing.h>

TuiCropRing tuiCropRing(const int center_x, const int center_y, const float radius, const float depth, const int crop_x, const int crop_y, const int crop_width, const int crop_height)
{
	TuiCropRing crop_ring = { center_x, center_y, radius, depth, crop_x, crop_y, crop_width, crop_height };
	return crop_ring;
}

TuiPoint2 tuiCropRingGetRingCenterPoint2(const TuiCropRing crop_ring)
{
	TuiPoint2 ret = { crop_ring.center_x, crop_ring.center_y };
	return ret;
}

int tuiCropRingGetRingLeftX(const TuiCropRing crop_ring)
{
	const int left_x = crop_ring.center_x - (int)roundf(fabsf(crop_ring.radius));
	return left_x;
}

int tuiCropRingGetRingRightX(const TuiCropRing crop_ring)
{
	const int right_x = crop_ring.center_x + (int)roundf(fabsf(crop_ring.radius));
	return right_x;
}

int tuiCropRingGetRingTopY(const TuiCropRing crop_ring)
{
	const int top_y = crop_ring.center_y - (int)roundf(fabsf(crop_ring.radius));
	return top_y;
}

int tuiCropRingGetRingBottomY(const TuiCropRing crop_ring)
{
	const int bottom_y = crop_ring.center_y + (int)roundf(fabsf(crop_ring.radius));
	return bottom_y;
}

float tuiCropRingGetInnerRingRadius(const TuiCropRing crop_ring)
{
	const float inner_radius = fabsf(crop_ring.radius) - fabsf(crop_ring.depth);
	return inner_radius;
}

int tuiCropRingGetInnerRingLeftX(const TuiCropRing crop_ring)
{
	const float inner_radius = tuiCropRingGetInnerRingRadius(crop_ring);
	const int inner_left_x = crop_ring.center_x - (int)roundf(inner_radius);
	return inner_left_x;
}

int tuiCropRingGetInnerRingRightX(const TuiCropRing crop_ring)
{
	const float inner_radius = tuiCropRingGetInnerRingRadius(crop_ring);
	const int inner_right_x = crop_ring.center_x + (int)roundf(inner_radius);
	return inner_right_x;
}

int tuiCropRingGetInnerRingTopY(const TuiCropRing crop_ring)
{
	const float inner_radius = tuiCropRingGetInnerRingRadius(crop_ring);
	const int inner_top_y = crop_ring.center_y - (int)roundf(inner_radius);
	return inner_top_y;
}

int tuiCropRingGetInnerRingBottomY(const TuiCropRing crop_ring)
{
	const float inner_radius = tuiCropRingGetInnerRingRadius(crop_ring);
	const int inner_bottom_y = crop_ring.center_y + (int)roundf(inner_radius);
	return inner_bottom_y;
}

int tuiCropRingGetRingDimensions(const TuiCropRing crop_ring)
{
	const int dimensions = (int)(roundf(fabsf(crop_ring.radius)) * 2.0f);
	return dimensions;
}

int tuiCropRingGetRingInnerDimensions(const TuiCropRing crop_ring)
{
	const float inner_radius = tuiCropRingGetInnerRingRadius(crop_ring);
	const int inner_dimensions = (int)roundf(inner_radius) * 2;
	return inner_dimensions;
}

int tuiCropRingGetCropFarX(const TuiCropRing crop_ring)
{
	const int crop_far_x = (crop_ring.crop_width == 0) ? crop_ring.crop_x : crop_ring.crop_x + abs(crop_ring.crop_width) - 1;
	return crop_far_x;
}
 
int tuiCropRingGetCropFarY(const TuiCropRing crop_ring)
{
	const int crop_far_y = (crop_ring.crop_height == 0) ? crop_ring.crop_y : crop_ring.crop_y + abs(crop_ring.crop_height) - 1;
	return crop_far_y;
}

int tuiCropRingGetLeftX(const TuiCropRing crop_ring)
{
	const int ring_left_x = tuiCropRingGetRingLeftX(crop_ring);
	const int crop_left_x = crop_ring.crop_x;
	const int crop_right_x = tuiCropRingGetCropFarX(crop_ring);
	const int crop_ring_left_x = CLAMP(crop_left_x, crop_right_x, ring_left_x);
	return crop_ring_left_x;
}

int tuiCropRingGetRightX(const TuiCropRing crop_ring)
{
	const int ring_right_x = tuiCropRingGetRingRightX(crop_ring);
	const int crop_left_x = crop_ring.crop_x;
	const int crop_right_x = tuiCropRingGetCropFarX(crop_ring);
	const int crop_ring_right_x = CLAMP(crop_left_x, crop_right_x, ring_right_x);
	return crop_ring_right_x;
}

int tuiCropRingGetTopY(const TuiCropRing crop_ring)
{
	const int ring_top_y = tuiCropRingGetRingTopY(crop_ring);
	const int crop_top_y = crop_ring.crop_y;
	const int crop_bottom_y = tuiCropRingGetCropFarY(crop_ring);
	const int crop_ring_top_y = CLAMP(crop_top_y, crop_bottom_y, ring_top_y);
	return crop_ring_top_y;
}

int tuiCropRingGetBottomY(const TuiCropRing crop_ring)
{
	const int ring_bottom_y = tuiCropRingGetRingBottomY(crop_ring);
	const int crop_top_y = crop_ring.crop_y;
	const int crop_bottom_y = tuiCropRingGetCropFarY(crop_ring);
	const int crop_ring_bottom_y = CLAMP(crop_top_y, crop_bottom_y, ring_bottom_y);
	return crop_ring_bottom_y;
}

TuiRing tuiCropRingGetRing(const TuiCropRing crop_ring)
{
	TuiRing ret = { crop_ring.center_x, crop_ring.center_y, crop_ring.radius, crop_ring.depth };
	return ret;
}

TuiCircle tuiCropRingGetRingCircle(const TuiCropRing crop_ring)
{
	const TuiCircle ret = { crop_ring.center_x, crop_ring.center_y, crop_ring.radius };
	return ret;
}

TuiCircle tuiCropRingGetRingInnerCircle(const TuiCropRing crop_ring)
{
	const TuiCircle ret = { crop_ring.center_x, crop_ring.center_y, tuiCropRingGetInnerRingRadius(crop_ring) };
	return ret;
}

TuiRect tuiCropRingGetRingBoundingRect(const TuiCropRing crop_ring)
{
	const int left_x = tuiCropRingGetRingLeftX(crop_ring);
	const int top_y = tuiCropRingGetRingTopY(crop_ring);
	const int dimensions = tuiCropRingGetRingDimensions(crop_ring);
	const TuiRect ret = tuiRect(left_x, top_y, dimensions, dimensions);
	return ret;
}

TuiRect tuiCropRingGetRingInnerBoundingRect(const TuiCropRing crop_ring)
{
	const int inner_left_x = tuiCropRingGetInnerRingLeftX(crop_ring);
	const int inner_top_y = tuiCropRingGetInnerRingTopY(crop_ring);
	const int inner_dimensions = tuiCropRingGetRingInnerDimensions(crop_ring);
	const TuiRect ret = tuiRect(inner_left_x, inner_top_y, inner_dimensions, inner_dimensions);
	return ret;
}

TuiRect tuiCropRingGetBoundingRect(const TuiCropRing crop_ring)
{
	const int left_x = tuiCropRingGetLeftX(crop_ring);
	const int top_y = tuiCropRingGetTopY(crop_ring);
	const int dimensions = tuiCropRingGetRingDimensions(crop_ring);
	const TuiRect ret = tuiRect(left_x, top_y, dimensions, dimensions);
	return ret;
}

TuiRect tuiCropRingGetCropRect(const TuiCropRing crop_ring)
{
	TuiRect ret = { crop_ring.crop_x, crop_ring.crop_y, crop_ring.crop_width, crop_ring.crop_height };
	return ret;
}

TuiPoint2 tuiCropRingGetRingLeftPoint2(const TuiCropRing crop_ring)
{
	const int ring_left_x = tuiCropRingGetRingLeftX(crop_ring);
	TuiPoint2 ret = { ring_left_x, crop_ring.center_y };
	return ret;
}

TuiPoint2 tuiCropRingGetRingRightPoint2(const TuiCropRing crop_ring)
{
	const int ring_right_x = tuiCropRingGetRingRightX(crop_ring);
	TuiPoint2 ret = { ring_right_x, crop_ring.center_y };
	return ret;
}

TuiPoint2 tuiCropRingGetRingTopPoint2(const TuiCropRing crop_ring)
{
	const int ring_top_y = tuiCropRingGetRingTopY(crop_ring);
	TuiPoint2 ret = { crop_ring.center_x, ring_top_y };
	return ret;
}

TuiPoint2 tuiCropRingGetRingBottomPoint2(const TuiCropRing crop_ring)
{
	const int ring_bottom_y = tuiCropRingGetRingBottomY(crop_ring);
	TuiPoint2 ret = { crop_ring.center_x, ring_bottom_y };
	return ret;
}

TuiPoint2 tuiCropRingGetRingInnerLeftPoint2(const TuiCropRing crop_ring)
{
	const int inner_ring_left_x = tuiCropRingGetInnerRingLeftX(crop_ring);
	TuiPoint2 ret = { inner_ring_left_x, crop_ring.center_y };
	return ret;
}

TuiPoint2 tuiCropRingGetRingInnerRightPoint2(const TuiCropRing crop_ring)
{
	const int inner_ring_right_x = tuiCropRingGetInnerRingRightX(crop_ring);
	TuiPoint2 ret = { inner_ring_right_x, crop_ring.center_y };
	return ret;
}

TuiPoint2 tuiCropRingGetRingInnerTopPoint2(const TuiCropRing crop_ring)
{
	const int inner_ring_top_y = tuiCropRingGetInnerRingTopY(crop_ring);
	TuiPoint2 ret = { crop_ring.center_x, inner_ring_top_y };
	return ret;
}

TuiPoint2 tuiCropRingGetRingInnerBottomPoint2(const TuiCropRing crop_ring)
{
	const int inner_ring_bottom_y = tuiCropRingGetInnerRingBottomY(crop_ring);
	TuiPoint2 ret = { crop_ring.center_x, inner_ring_bottom_y };
	return ret;
}

TuiBoolean tuiCropRingIsDegenerate(const TuiCropRing crop_ring)
{
	const float abs_radius = fabsf(crop_ring.radius);
	const float abs_depth = fabsf(crop_ring.depth);
	const TuiBoolean is_degenerate = (abs_radius < 0.5f || abs_depth < 0.5f || abs_radius < abs_depth || crop_ring.crop_width == 0 || crop_ring.crop_height == 0);
	return is_degenerate;
}

TuiBoolean tuiCropRingContainsPoint2(const TuiCropRing crop_ring, const TuiPoint2 point2)
{
	TuiBoolean crop_rect_contains_point2 = tuiRectContainsPoint2(tuiCropRingGetCropRect(crop_ring), point2);
	if (!crop_rect_contains_point2) return TUI_FALSE;
	TuiBoolean ring_contains_point2 = tuiRingContainsPoint2(tuiCropRingGetRing(crop_ring), point2);
	return ring_contains_point2;
}

TuiBoolean tuiCropRingIntersetsLine(const TuiCropRing crop_ring, const TuiLine line)
{
	TuiBoolean crop_rect_intersects_line = tuiRectIntersectsLine(tuiCropRingGetCropRect(crop_ring), line);
	if (!crop_rect_intersects_line) return TUI_FALSE;
	TuiBoolean ring_intersects_line = tuiRingIntersetsLine(tuiCropRingGetRing(crop_ring), line);
	return ring_intersects_line;
}

TuiBoolean tuiCropRingIntersectsRect(const TuiCropRing crop_ring, const TuiRect rect)
{
	TuiBoolean crop_rect_intersects_rect = tuiRectIntersectsRect(tuiCropRingGetCropRect(crop_ring), rect);
	if (!crop_rect_intersects_rect) return TUI_FALSE;
	TuiBoolean ring_intersects_rect = tuiRingIntersectsRect(tuiCropRingGetRing(crop_ring), rect);
	return ring_intersects_rect;
}

TuiBoolean tuiCropRingIntersectsCircle(const TuiCropRing crop_ring, const TuiCircle circle)
{
	TuiBoolean crop_rect_intersects_circle = tuiRectIntersectsCircle(tuiCropRingGetCropRect(crop_ring), circle);
	if (!crop_rect_intersects_circle) return TUI_FALSE;
	TuiBoolean ring_intersects_circle = tuiRingIntersectsCircle(tuiCropRingGetRing(crop_ring), circle);
	return ring_intersects_circle;
}

TuiBoolean tuiCropRingIntersectsRing(const TuiCropRing crop_ring, const TuiRing ring)
{
	TuiBoolean crop_rect_intersects_ring = tuiRectIntersectsRing(tuiCropRingGetCropRect(crop_ring), ring);
	if (!crop_rect_intersects_ring) return TUI_FALSE;
	TuiBoolean ring_intersects_ring = tuiRingIntersectsRing(tuiCropRingGetRing(crop_ring), ring);
	return ring_intersects_ring;
}

TuiBoolean tuiCropRingIntersectsCropRing(const TuiCropRing crop_ring_1, const TuiCropRing crop_ring_2)
{
	const TuiRect crop_ring_1_crop_rect = tuiCropRingGetCropRect(crop_ring_1);
	const TuiRing crop_ring_2_ring = tuiCropRingGetRing(crop_ring_2);
	TuiBoolean crop_rect_1_intersects_ring_2 = tuiRectIntersectsRing(crop_ring_1_crop_rect, crop_ring_2_ring);
	if (!crop_rect_1_intersects_ring_2) return TUI_FALSE;
	const TuiRect crop_ring_2_crop_rect = tuiCropRingGetCropRect(crop_ring_2);
	const TuiRing crop_ring_1_ring = tuiCropRingGetRing(crop_ring_1);
	TuiBoolean crop_rect_2_intersects_ring_1 = tuiRectIntersectsRing(crop_ring_2_crop_rect, crop_ring_1_ring);
	if (!crop_rect_2_intersects_ring_1) return TUI_FALSE;
	TuiBoolean ring_1_intersects_ring_2 = tuiRingIntersectsRing(crop_ring_1_ring, crop_ring_2_ring);
	return ring_1_intersects_ring_2;
}
