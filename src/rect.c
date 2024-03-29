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
#include <TUIC/rect.h>
#include <TUIC/point2.h>
#include <TUIC/line.h>
#include <TUIC/circle.h>
#include <TUIC/ring.h>
#include <TUIC/box.h>
#include "grid_shapes_inline.h"
#include "math_inline.h"
#include <stdlib.h>
#include <TUIC/easing.h>

TuiRect tuiRect(const int x, const int y, const int width, const int height)
{
	TuiRect ret = { x, y, width, height };
	return ret;
}

static inline int _tuiRectGetLeftX(const TuiRect rect)
{
	const int rect_left_x = rect.x;
	return rect_left_x;
}

static inline int _tuiRectGetRightX(const TuiRect rect)
{
	const int rect_right_x = (rect.width == 0) ? rect.x : rect.x + abs(rect.width) - 1;
	return rect_right_x;
}

static inline int _tuiRectGetTopY(const TuiRect rect)
{
	const int rect_top_y = rect.y;
	return rect_top_y;
}

static inline int _tuiRectGetBottomY(const TuiRect rect)
{
	const int rect_bottom_y = (rect.height == 0) ? rect.y : rect.y + abs(rect.height) - 1;
	return rect_bottom_y;
}

int tuiRectGetFarX(const TuiRect rect)
{
	const int far_x = (rect.width == 0) ? rect.x : rect.x + abs(rect.width) - 1;
	return far_x;
}

int tuiRectGetFarY(const TuiRect rect)
{
	const int far_y = (rect.height == 0) ? rect.y : rect.y + abs(rect.height) - 1;
	return far_y;
}

int tuiRectGetTileWidth(const TuiRect rect)
{
	const int tile_width = abs(rect.width);
	return tile_width;
}

int tuiRectGetTileHeight(const TuiRect rect)
{
	const int tile_height = abs(rect.height);
	return tile_height;
}
TuiBoolean tuiRectIsFlippedWide(const TuiRect rect)
{
	const TuiBoolean flipped_wide = rect.width < 0;
	return flipped_wide;
}

TuiBoolean tuiRectIsFlippedTall(const TuiRect rect)
{
	const TuiBoolean flipped_tall = rect.height < 0;
	return flipped_tall;
}

TuiBoolean tuiRectIsDegenerate(const TuiRect rect)
{
	TuiBoolean degenerate = (rect.width == 0) || (rect.height == 0);
	return degenerate;
}

TuiBox tuiRectGetBox(const TuiRect rect, const int depth)
{
	TuiBox ret = { rect.x, rect.y, rect.width, rect.height, depth };
	return ret;
}

TuiPoint2 tuiRectGetTopLeftCornerPoint2(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	TuiPoint2 ret = { rect_left_x, rect_top_y };
	return ret;
}

TuiPoint2 tuiRectGetTopRightCornerPoint2(const TuiRect rect)
{
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	TuiPoint2 ret = { rect_right_x, rect_top_y };
	return ret;
}

TuiPoint2 tuiRectGetBottomLeftCornerPoint2(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiPoint2 ret = { rect_left_x, rect_bottom_y };
	return ret;
}

TuiPoint2 tuiRectGetBottomRightCornerPoint2(const TuiRect rect)
{
	const int right_x = _tuiRectGetRightX(rect);
	const int bottom_y = _tuiRectGetBottomY(rect);
	TuiPoint2 ret = { right_x, bottom_y };
	return ret;
}

TuiLine tuiRectGetLeftBorderLine(const TuiRect rect, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiLine ret = { rect_left_x, rect_top_y + corner_change, rect_left_x, rect_bottom_y - corner_change }; // clockwise
	return ret;
}

TuiLine tuiRectGetRightBorderLine(const TuiRect rect, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiLine ret = { rect_right_x, rect_bottom_y - corner_change, rect_right_x, rect_top_y + corner_change }; // clockwise
	return ret;
}

TuiLine tuiRectGetTopBorderLine(const TuiRect rect, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	TuiLine ret = { rect_left_x + corner_change, rect_top_y, rect_right_x - corner_change, rect_top_y }; // clockwise
	return ret;
}

TuiLine tuiRectGetBottomBorderLine(const TuiRect rect, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiLine ret = { rect_right_x - corner_change, rect_bottom_y, rect_left_x + corner_change, rect_bottom_y }; // clockwise
	return ret;
}

TuiRect tuiRectGetInnerRect(const TuiRect rect, const int depth)
{
	TuiRect ret = { rect.x + depth, rect.y + depth, rect.width - (SIGN(rect.width) * depth * 2), rect.height - (SIGN(rect.height) * depth * 2) };
	return ret;
}

TuiRect tuiRectCrop(const TuiRect rect, const TuiRect crop_rect)
{
	if (tuiRectIsDegenerate(rect) || tuiRectIsDegenerate(crop_rect))
	{
		TuiRect ret = { 0, 0, 0, 0 };
		return ret;
	}
	const int crop_far_x = tuiRectGetFarX(crop_rect);
	const int crop_far_y = tuiRectGetFarY(crop_rect);
	const int rect_far_x = tuiRectGetFarX(rect);
	const int rect_far_y = tuiRectGetFarY(rect);
	const int ret_x = CLAMP(rect.x, crop_rect.x, crop_far_x);
	const int ret_y = CLAMP(rect.y, crop_rect.y, crop_far_y);
	const int ret_far_x = CLAMP(rect_far_x, crop_rect.x, crop_far_x);
	const int ret_far_y = CLAMP(rect_far_y, crop_rect.y, crop_far_y);
	const int ret_width = ret_far_x - ret_x + 1;
	const int ret_height = ret_far_y - ret_y + 1;
	TuiRect ret = {  ret_x, ret_y, ret_width * SIGN(rect.width), ret_height * SIGN(rect.height) };
	return ret;
}

TuiBoolean tuiRectContainsPoint2(const TuiRect rect, const TuiPoint2 point2)
{
	if (tuiRectIsDegenerate(rect))
	{
		return TUI_FALSE;
	}
	const int rect_far_x = rect.x + abs(rect.width) - 1;
	const int rect_far_y = rect.y + abs(rect.height) - 1;
	TuiBoolean rect_contains_point2 =
		(rect.x <= point2.x) && (rect_far_x >= point2.x) &&
		(rect.y <= point2.y) && (rect_far_y >= point2.y);
	return rect_contains_point2;
}

TuiBoolean tuiRectContainsLine(const TuiRect rect, const TuiLine line)
{
	if (tuiRectIsDegenerate(rect))
	{
		return TUI_FALSE;
	}
	const int rect_far_x = rect.x + abs(rect.width) - 1;
	const int rect_far_y = rect.y + abs(rect.height) - 1;
	TuiBoolean rect_contains_line =
		(rect.x <= line.start_x) && (rect_far_x >= line.start_x) &&
		(rect.x <= line.end_x) && (rect_far_x >= line.end_x) &&
		(rect.y <= line.start_y) && (rect_far_y >= line.start_y) &&
		(rect.y <= line.end_y) && (rect_far_y >= line.end_y);
	return rect_contains_line;
}

TuiBoolean tuiRectContainsRect(const TuiRect rect_1, const TuiRect rect_2)
{
	if (tuiRectIsDegenerate(rect_1) || tuiRectIsDegenerate(rect_2))
	{
		return TUI_FALSE;
	}
	const int rect_1_far_x = rect_1.x + abs(rect_1.width) - 1;
	const int rect_1_far_y = rect_1.y + abs(rect_1.height) - 1;
	const int rect_2_far_x = rect_2.x + abs(rect_2.width) - 1;
	const int rect_2_far_y = rect_2.y + abs(rect_2.height) - 1;
	TuiBoolean rect_contains_line =
		(rect_1.x <= rect_2.x) && (rect_1_far_x >= rect_2.x) &&
		(rect_1.x <= rect_2_far_x) && (rect_1_far_x >= rect_2_far_x) &&
		(rect_1.y <= rect_2.y) && (rect_1_far_y >= rect_2.y) &&
		(rect_1.y <= rect_2_far_y) && (rect_1_far_y >= rect_2_far_y);
	return rect_contains_line;
}

TuiBoolean tuiRectContainsCircle(const TuiRect rect, const TuiCircle circle)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	const int circle_left_x = tuiCircleGetLeftX(circle);
	const int circle_right_x = tuiCircleGetRightX(circle);
	const int circle_top_y = tuiCircleGetTopY(circle);
	const int circle_bottom_y = tuiCircleGetBottomY(circle);
	TuiBoolean rect_contains_circle = (
			rect_left_x <= circle_left_x &&
			rect_right_x >= circle_right_x &&
			rect_top_y <= circle_top_y &&
			rect_bottom_y >= circle_bottom_y
		);
	return rect_contains_circle;
}

TuiBoolean tuiRectIntersectsLine(const TuiRect rect, const TuiLine line)
{
	if (tuiRectIsDegenerate(rect))
	{
		return TUI_FALSE;
	}
	TuiBoolean line_intersects_rect_border = 
		tuiLineIntersectsLine(line, tuiRectGetLeftBorderLine(rect, TUI_TRUE)) ||
		tuiLineIntersectsLine(line, tuiRectGetTopBorderLine(rect, TUI_TRUE)) ||
		tuiLineIntersectsLine(line, tuiRectGetRightBorderLine(rect, TUI_TRUE)) ||
		tuiLineIntersectsLine(line, tuiRectGetBottomBorderLine(rect, TUI_TRUE));
	if (line_intersects_rect_border) return TUI_TRUE;
	const int rect_far_x = rect.x + abs(rect.width) - 1;
	const int rect_far_y = rect.y + abs(rect.height) - 1;
	TuiBoolean rect_contains_line =
		(line.start_x >= rect.x && line.start_x <= rect_far_x) &&
		(line.start_y >= rect.y && line.start_y <= rect_far_y) &&
		(line.end_x >= rect.x && line.end_x <= rect_far_x) &&
		(line.end_y >= rect.y && line.end_y <= rect_far_y);
	return rect_contains_line;
}

TuiBoolean tuiRectIntersectsRect(const TuiRect rect_1, const TuiRect rect_2)
{
	if (tuiRectIsDegenerate(rect_1) || tuiRectIsDegenerate(rect_2))
	{
		return TUI_FALSE;
	}
	const int rect_1_far_x = rect_1.x + abs(rect_1.width) - 1;
	const int rect_1_far_y = rect_1.y + abs(rect_1.height) - 1;
	const int rect_2_far_x = rect_2.x + abs(rect_2.width) - 1;
	const int rect_2_far_y = rect_2.y + abs(rect_2.height) - 1;
	const TuiBoolean rect_intersects_rect =
		(rect_1_far_x >= rect_2.x) &&
		(rect_1.x <= rect_2_far_x) &&
		(rect_1_far_y >= rect_2.y) &&
		(rect_1.y <= rect_2_far_y);
	return rect_intersects_rect;
}

TuiBoolean tuiRectIntersectsBox(const TuiRect rect, const TuiBox box)
{
	return tuiBoxIntersectsRect(box, rect);
}

TuiBoolean tuiRectIntersectsCircle(const TuiRect rect, const TuiCircle circle)
{
	return tuiCircleIntersectsRect(circle, rect);
}

TuiBoolean tuiRectIntersectsRing(const TuiRect rect, const TuiRing ring)
{
	return tuiRingIntersectsRect(ring, rect);
}
