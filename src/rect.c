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
#include "grid_shapes_inline.h"
#include <math.h>
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
	return (rect.width == 0) ? rect.x : rect.x + abs(rect.width) - 1;
}

int tuiRectGetFarY(const TuiRect rect)
{
	return (rect.height == 0) ? rect.y : rect.y + abs(rect.height) - 1;
}

int tuiRectGetPhysicalWidth(const TuiRect rect)
{
	return abs(rect.width);
}

int tuiRectGetPhysicalHeight(const TuiRect rect)
{
	return abs(rect.height);
}
TuiBoolean tuiRectIsFlippedWide(const TuiRect rect)
{
	return rect.width < 0;
}

TuiBoolean tuiRectIsFlippedTall(const TuiRect rect)
{
	return rect.height < 0;
}

TuiBoolean tuiRectIsDegenerate(const TuiRect rect)
{
	TuiBoolean degenerate = (rect.width == 0) || (rect.height == 0);
	return degenerate;
}

TuiPoint2 tuiRectGetTopLeftInnerCornerPoint2(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	TuiPoint2 ret = { rect_left_x, rect_top_y };
	return ret;
}

TuiPoint2 tuiRectGetTopRightInnerCornerPoint2(const TuiRect rect)
{
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	TuiPoint2 ret = { rect_right_x, rect_top_y };
	return ret;
}

TuiPoint2 tuiRectGetBottomLeftInnerCornerPoint2(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiPoint2 ret = { rect_left_x, rect_bottom_y };
	return ret;
}

TuiPoint2 tuiRectGetBottomRightInnerCornerPoint2(const TuiRect rect)
{
	const int right_x = _tuiRectGetRightX(rect);
	const int bottom_y = _tuiRectGetBottomY(rect);
	TuiPoint2 ret = { right_x, bottom_y };
	return ret;
}

TuiLine tuiRectGetRightInnerBorderLine(const TuiRect rect, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiLine ret = { rect_right_x, rect_bottom_y - corner_change, rect_right_x, rect_top_y + corner_change }; // clockwise
	return ret;
}

TuiLine tuiRectGetLeftInnerBorderLine(const TuiRect rect, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiLine ret = { rect_left_x, rect_top_y + corner_change, rect_left_x, rect_bottom_y - corner_change }; // clockwise
	return ret;
}

TuiLine tuiRectGetTopInnerBorderLine(const TuiRect rect, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	TuiLine ret = { rect_left_x + corner_change, rect_top_y, rect_right_x - corner_change, rect_top_y }; // clockwise
	return ret;
}

TuiLine tuiRectGetBottomInnerBorderLine(const TuiRect rect, const TuiBoolean corners)
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

TuiRect tuiRectGetCroppedRect(const TuiRect rect, const TuiRect crop_rect)
{
	if (tuiRectIsDegenerate(rect) || tuiRectIsDegenerate(crop_rect))
	{
		TuiRect ret = { 0, 0, 0, 0 };
		return ret;
	}
	const int crop_far_x = tuiRectGetFarX(crop_rect);
	const int crop_far_y = tuiRectGetFarY(crop_rect);
	const int rect_far_x = tuiRectGetFarX(crop_rect);
	const int rect_far_y = tuiRectGetFarY(crop_rect);
	const int ret_x = CLAMP(crop_rect.x, crop_far_x, rect.x);
	const int ret_y = CLAMP(crop_rect.y, crop_far_y, rect.y);
	const int ret_far_x = CLAMP(crop_rect.x, crop_far_x, rect_far_x);
	const int ret_far_y = CLAMP(crop_rect.y, crop_far_y, rect_far_y);
	const int ret_width = ret_far_x - ret_x;
	const int ret_height = ret_far_y - ret_y;
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

TuiBoolean tuiRectIntersectsLine(const TuiRect rect, const TuiLine line)
{
	if (tuiRectIsDegenerate(rect))
	{
		return TUI_FALSE;
	}
	TuiBoolean rect_intersects_line = 
		tuiLineIntersectsLine(line, tuiRectGetLeftInnerBorderLine(rect, TUI_TRUE)) ||
		tuiLineIntersectsLine(line, tuiRectGetTopInnerBorderLine(rect, TUI_TRUE)) ||
		tuiLineIntersectsLine(line, tuiRectGetRightInnerBorderLine(rect, TUI_TRUE)) ||
		tuiLineIntersectsLine(line, tuiRectGetBottomInnerBorderLine(rect, TUI_TRUE));
	return rect_intersects_line;
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