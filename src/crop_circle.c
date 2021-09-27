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
#include <TUIC/crop_circle.h>
#include <TUIC/circle.h>
#include <TUIC/point2.h>
#include <TUIC/line.h>
#include <TUIC/rect.h>
#include <TUIC/ring.h>
#include "grid_shapes_inline.h"
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>

TuiCropCircle tuiCropCircle(const int center_x, const int center_y, const float radius, const int crop_x, const int crop_y, const int crop_width, const int crop_height)
{
	TuiCropCircle ret = { center_x, center_y, radius, crop_x, crop_y, crop_width, crop_height };
	return ret;
}

TuiPoint2 tuiCropCircleGetCircleCenterPoint2(const TuiCropCircle crop_circle)
{
	TuiPoint2 ret = { crop_circle.center_x, crop_circle.center_y };
	return ret;
}

int tuiCropCircleGetCircleLeftX(const TuiCropCircle crop_circle)
{
	const int circle_left_x = crop_circle.center_x - (int)roundf(fabsf(crop_circle.radius));
	return circle_left_x;
}

int tuiCropCircleGetCircleRightX(const TuiCropCircle crop_circle)
{
	const int circle_right_x = crop_circle.center_x + (int)roundf(fabsf(crop_circle.radius));
	return circle_right_x;
}

int tuiCropCircleGetCircleTopY(const TuiCropCircle crop_circle)
{
	const int circle_top_y = crop_circle.center_y - (int)roundf(fabsf(crop_circle.radius));
	return circle_top_y;
}

int tuiCropCircleGetCircleBottomY(const TuiCropCircle crop_circle)
{
	const int circle_bottom_y = crop_circle.center_y + (int)roundf(fabsf(crop_circle.radius));
	return circle_bottom_y;
}

int tuiCropCircleGetCircleDimensions(const TuiCropCircle crop_circle)
{
	const int circle_dimensions = (int)(roundf(fabsf(crop_circle.radius)) * 2.0f);
	return circle_dimensions;
}

TuiRect tuiCropCircleGetCircleBoundingRect(const TuiCropCircle crop_circle)
{
	const int circle_left_x = tuiCropCircleGetCircleLeftX(crop_circle);
	const int circle_top_y = tuiCropCircleGetCircleTopY(crop_circle);
	const int circle_dimensions = tuiCropCircleGetCircleDimensions(crop_circle);
	const TuiRect ret = tuiRect(circle_left_x, circle_top_y, circle_dimensions, circle_dimensions);
	return ret;
}
int tuiCropCircleGetCropFarX(const TuiCropCircle crop_circle)
{
		const int crop_far_x = (crop_circle.crop_width == 0) ? crop_circle.crop_x : crop_circle.crop_x + abs(crop_circle.crop_width) - 1;
		return crop_far_x;
}

int tuiCropCircleGetCropFarY(const TuiCropCircle crop_circle)
{
	const int crop_far_y = (crop_circle.crop_height == 0) ? crop_circle.crop_y : crop_circle.crop_y + abs(crop_circle.crop_height) - 1;
	return crop_far_y;
}

int tuiCropCircleGetLeftX(const TuiCropCircle crop_circle)
{
	const int circle_left_x = tuiCropCircleGetCircleLeftX(crop_circle);
	const int crop_far_x = tuiCropCircleGetCropFarX(crop_circle);
	const int crop_circle_left_x = CLAMP(circle_left_x, crop_circle.crop_x, crop_far_x);
	return crop_circle_left_x;
}

int tuiCropCircleGetRightX(const TuiCropCircle crop_circle)
{
	const int circle_right_x = tuiCropCircleGetCircleRightX(crop_circle);
	const int crop_far_x = tuiCropCircleGetCropFarX(crop_circle);
	const int crop_circle_right_x = CLAMP(circle_right_x, crop_circle.crop_x, crop_far_x);
	return crop_circle_right_x;
}

int tuiCropCircleGetTopY(const TuiCropCircle crop_circle)
{
	const int circle_top_y = tuiCropCircleGetCircleTopY(crop_circle);
	const int crop_far_y = tuiCropCircleGetCropFarY(crop_circle);
	const int crop_circle_top_y = CLAMP(circle_top_y, crop_circle.crop_y, crop_far_y);
	return crop_circle_top_y;
}

int tuiCropCircleGetBottomY(const TuiCropCircle crop_circle)
{
	const int circle_bottom_y = tuiCropCircleGetCircleBottomY(crop_circle);
	const int crop_far_y = tuiCropCircleGetCropFarY(crop_circle);
	const int crop_circle_bottom_y = CLAMP(circle_bottom_y, crop_circle.crop_y, crop_far_y);
	return crop_circle_bottom_y;
}

TuiRect tuiCropCircleGetCropRect(const TuiCropCircle crop_circle)
{
	const TuiRect crop_rect = { crop_circle.crop_x, crop_circle.crop_y, crop_circle.crop_width, crop_circle.crop_height };
	return crop_rect;
}

TuiCircle tuiCropCircleGetCircle(const TuiCropCircle crop_circle)
{
	const TuiCircle circle = { crop_circle.center_x, crop_circle.center_y, crop_circle.radius };
	return circle;
}

TuiRect tuiCropCircleGetBoundingRect(const TuiCropCircle crop_circle)
{
	return tuiRectCrop(tuiCropCircleGetCircleBoundingRect(crop_circle), tuiCropCircleGetCropRect(crop_circle));
}

TuiPoint2 tuiCropCircleGetLeftPoint2(const TuiCropCircle crop_circle)
{
	const int crop_far_x = tuiCropCircleGetCropFarX(crop_circle);
	const int crop_far_y = tuiCropCircleGetCropFarY(crop_circle);
	const int circle_left_x = tuiCropCircleGetCircleLeftX(crop_circle);
	const int x = CLAMP(circle_left_x, crop_circle.crop_x, crop_far_x);
	const int y = CLAMP(crop_circle.center_y, crop_circle.crop_y, crop_far_y);
	const TuiPoint2 ret = { x, y };
	return ret;
}

TuiPoint2 tuiCropCircleGetRightPoint2(const TuiCropCircle crop_circle)
{
	const int crop_far_x = tuiCropCircleGetCropFarX(crop_circle);
	const int crop_far_y = tuiCropCircleGetCropFarY(crop_circle);
	const int circle_right_x = tuiCropCircleGetCircleRightX(crop_circle);
	const int x = CLAMP(circle_right_x, crop_circle.crop_x, crop_far_x);
	const int y = CLAMP(crop_circle.center_y, crop_circle.crop_y, crop_far_y);
	const TuiPoint2 ret = { x, y };
	return ret;
}

TuiPoint2 tuiCropCircleGetTopPoint2(const TuiCropCircle crop_circle)
{
	const int crop_far_x = tuiCropCircleGetCropFarX(crop_circle);
	const int crop_far_y = tuiCropCircleGetCropFarY(crop_circle);
	const int circle_top_y = tuiCropCircleGetCircleTopY(crop_circle);
	const int x = CLAMP(crop_circle.center_x, crop_circle.crop_x, crop_far_x);
	const int y = CLAMP(circle_top_y, crop_circle.crop_y, crop_far_y);
	const TuiPoint2 ret = { x, y };
	return ret;
}

TuiPoint2 tuiCropCircleGetBottomPoint2(const TuiCropCircle crop_circle)
{
	const int crop_far_x = tuiCropCircleGetCropFarX(crop_circle);
	const int crop_far_y = tuiCropCircleGetCropFarY(crop_circle);
	const int circle_bottom_y = tuiCropCircleGetCircleBottomY(crop_circle);
	const int x = CLAMP(crop_circle.center_x, crop_circle.crop_x, crop_far_x);
	const int y = CLAMP(circle_bottom_y, crop_circle.crop_y, crop_far_y);
	const TuiPoint2 ret = { x, y };
	return ret;
}

TuiBoolean tuiCropCircleIsDegenerate(const TuiCropCircle crop_circle)
{
	const TuiBoolean circle_is_degenerate = (fabsf(crop_circle.radius) <= 0.5f);
	if (circle_is_degenerate) return TUI_TRUE;
	const TuiBoolean crop_rect_is_degenerate = (crop_circle.crop_width == 0 || crop_circle.crop_height == 0);
	return crop_rect_is_degenerate;
}

TuiBoolean tuiCropCircleContainsPoint2(const TuiCropCircle crop_circle, const TuiPoint2 point2)
{
	TuiBoolean crop_rect_contains_point2 = tuiRectContainsPoint2(tuiCropCircleGetCropRect(crop_circle), point2);
	if (!crop_rect_contains_point2) return TUI_FALSE;
	TuiBoolean circle_contains_point2 = tuiCircleContainsPoint2(tuiCropCircleGetCircle(crop_circle), point2);
	return circle_contains_point2;
}

TuiBoolean tuiCropCircleContainsLine(const TuiCropCircle crop_circle, const TuiLine line)
{
	TuiBoolean crop_rect_contains_line = tuiRectContainsLine(tuiCropCircleGetCropRect(crop_circle), line);
	if (!crop_rect_contains_line) return TUI_FALSE;
	TuiBoolean circle_contains_line = tuiCircleContainsLine(tuiCropCircleGetCircle(crop_circle), line);
	return circle_contains_line;
}

TuiBoolean tuiCropCircleContainsRect(const TuiCropCircle crop_circle, const TuiRect rect)
{
	TuiBoolean crop_rect_contains_rect = tuiRectContainsRect(tuiCropCircleGetCropRect(crop_circle), rect);
	if (!crop_rect_contains_rect) return TUI_FALSE;
	TuiBoolean circle_contains_rect = tuiCircleContainsRect(tuiCropCircleGetCircle(crop_circle), rect);
	return circle_contains_rect;
}

TuiBoolean tuiCropCircleContainsCircle(const TuiCropCircle crop_circle, const TuiCircle circle)
{
	TuiBoolean crop_rect_contains_circle = tuiRectContainsCircle(tuiCropCircleGetCropRect(crop_circle), circle);
	if (!crop_rect_contains_circle) return TUI_FALSE;
	TuiBoolean circle_contains_circle = tuiCircleContainsCircle(tuiCropCircleGetCircle(crop_circle), circle);
	return circle_contains_circle;
}

TuiBoolean tuiCropCircleContainsCropCircle(const TuiCropCircle crop_circle_1, const TuiCropCircle crop_circle_2)
{
	const TuiRect crop_circle_1_crop_rect = tuiCropCircleGetCropRect(crop_circle_1);
	const TuiCircle crop_circle_2_circle = tuiCropCircleGetCircle(crop_circle_2);
	TuiBoolean crop_rect_1_contains_circle_2 = tuiRectContainsCircle(crop_circle_1_crop_rect, crop_circle_2_circle);
	if (!crop_rect_1_contains_circle_2) return TUI_FALSE;
	const TuiRect crop_circle_2_crop_rect = tuiCropCircleGetCropRect(crop_circle_2);
	const TuiCircle crop_circle_1_circle = tuiCropCircleGetCircle(crop_circle_1);
	TuiBoolean crop_rect_2_contains_circle_1 = tuiRectContainsCircle(crop_circle_1_crop_rect, crop_circle_1_circle);
	if (!crop_rect_2_contains_circle_1) return TUI_FALSE;
	TuiBoolean circle_1_contains_circle_2 = tuiCircleContainsCircle(crop_circle_1_circle, crop_circle_2_circle);
	return circle_1_contains_circle_2;
}

TuiBoolean tuiCropCircleIntersectsLine(const TuiCropCircle crop_circle, const TuiLine line)
{
	TuiBoolean crop_rect_intersects_line = tuiRectIntersectsLine(tuiCropCircleGetCropRect(crop_circle), line);
	if (!crop_rect_intersects_line) return TUI_FALSE;
	TuiBoolean circle_intersects_line = tuiCircleIntersectsLine(tuiCropCircleGetCircle(crop_circle), line);
	return circle_intersects_line;
}

TuiBoolean tuiCropCircleIntersectsRect(const TuiCropCircle crop_circle, const TuiRect rect)
{
	TuiBoolean crop_rect_intersects_rect = tuiRectIntersectsRect(tuiCropCircleGetCropRect(crop_circle), rect);
	if (!crop_rect_intersects_rect) return TUI_FALSE;
	TuiBoolean circle_intersects_rect = tuiCircleIntersectsRect(tuiCropCircleGetCircle(crop_circle), rect);
	return circle_intersects_rect;
}

TuiBoolean tuiCropCircleIntersectsCircle(const TuiCropCircle crop_circle, const TuiCircle circle)
{
	TuiBoolean crop_rect_intersects_circle = tuiRectIntersectsCircle(tuiCropCircleGetCropRect(crop_circle), circle);
	if (!crop_rect_intersects_circle) return TUI_FALSE;
	TuiBoolean circle_intersects_circle = tuiCircleIntersectsCircle(tuiCropCircleGetCircle(crop_circle), circle);
	return circle_intersects_circle;
}

TuiBoolean tuiCropCircleIntersectsCropCircle(const TuiCropCircle crop_circle_1, const TuiCropCircle crop_circle_2)
{
	const TuiRect crop_circle_1_crop_rect = tuiCropCircleGetCropRect(crop_circle_1);
	const TuiCircle crop_circle_2_circle = tuiCropCircleGetCircle(crop_circle_2);
	TuiBoolean crop_rect_1_intersects_circle_2 = tuiRectIntersectsCircle(crop_circle_1_crop_rect, crop_circle_2_circle);
	if (!crop_rect_1_intersects_circle_2) return TUI_FALSE;
	const TuiRect crop_circle_2_crop_rect = tuiCropCircleGetCropRect(crop_circle_2);
	const TuiCircle crop_circle_1_circle = tuiCropCircleGetCircle(crop_circle_1);
	TuiBoolean crop_rect_2_intersects_circle_1 = tuiRectIntersectsCircle(crop_circle_1_crop_rect, crop_circle_1_circle);
	if (!crop_rect_2_intersects_circle_1) return TUI_FALSE;
	TuiBoolean circle_1_intersects_circle_2 = tuiCircleIntersectsCircle(crop_circle_1_circle, crop_circle_2_circle);
	return circle_1_intersects_circle_2;
}

TuiBoolean tuiCropCircleIntersectsRing(const TuiCropCircle crop_circle, const TuiRing ring)
{
	TuiBoolean crop_rect_intersects_ring = tuiRectIntersectsRing(tuiCropCircleGetCropRect(crop_circle), ring);
	if (!crop_rect_intersects_ring) return TUI_FALSE;
	TuiBoolean circle_intersects_ring = tuiCircleIntersectsRing(tuiCropCircleGetCircle(crop_circle), ring);
	return circle_intersects_ring;
}
