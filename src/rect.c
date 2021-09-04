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
#include <TUIC/h_line.h>
#include <TUIC/v_line.h>
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
	const int rect_right_x = (rect.width <= 0) ? rect.x : rect.x + rect.width - 1;
	return rect_right_x;
}

static inline int _tuiRectGetTopY(const TuiRect rect)
{
	const int rect_top_y = rect.y;
	return rect_top_y;
}

static inline int _tuiRectGetBottomY(const TuiRect rect)
{
	const int rect_bottom_y = (rect.height <= 0) ? rect.y : rect.y + rect.height - 1;
	return rect_bottom_y;
}

int tuiRectGetFarX(const TuiRect rect)
{
	const int rect_far_x = (rect.width <= 0) ? rect.x : rect.x + rect.width - 1;
	return rect_far_x;
}

int tuiRectGetFarY(const TuiRect rect)
{
	const int rect_far_y = (rect.height <= 0) ? rect.y : rect.y + rect.height - 1;
	return rect_far_y;
}

TuiBoolean tuiRectIsDegenerate(const TuiRect rect)
{
	TuiBoolean degenerate = (rect.width < 0) || (rect.height < 0);
	return degenerate;
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

TuiLine tuiRectGetTopLeftCornerLine(const TuiRect rect, const int depth)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_corner_end_x = rect_left_x + depth;
	const int rect_corner_end_y = rect_top_y + depth;
	TuiLine ret = { rect_left_x, rect_top_y, rect_corner_end_x, rect_corner_end_y };
	return ret;
}

TuiLine tuiRectGetTopRightCornerLine(const TuiRect rect, const int depth)
{
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_corner_end_x = rect_right_x - depth;
	const int rect_corner_end_y = rect_top_y + depth;
	TuiLine ret = { rect_right_x, rect_top_y, rect_corner_end_x, rect_corner_end_y };
}

TuiLine tuiRectGetBottomLeftCornerLine(const TuiRect rect, const int depth)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	const int rect_corner_end_x = rect_left_x + depth;
	const int rect_corner_end_y = rect_bottom_y - depth;
	TuiLine ret = { rect_left_x, rect_bottom_y, rect_corner_end_x, rect_corner_end_y };
	return ret;
}

TuiLine tuiRectGetBottomRightCornerLine(const TuiRect rect, const int depth)
{
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	const int rect_corner_end_x = rect_right_x - depth;
	const int rect_corner_end_y = rect_bottom_y - depth;
	TuiLine ret = { rect_right_x, rect_bottom_y, rect_corner_end_x, rect_corner_end_y };
	return ret;
}

TuiVLine tuiRectGetRightVLine(const TuiRect rect)
{
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiVLine ret = { rect_right_x, rect_bottom_y,  rect_top_y }; // clockwise
	return ret;
}

TuiLine tuiRectGetRightLine(const TuiRect rect)
{
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiLine ret = { rect_right_x, rect_bottom_y, rect_right_x, rect_top_y }; // clockwise
	return ret;
}

TuiVLine tuiRectGetLeftVLine(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiVLine ret = { rect_left_x, rect_top_y, rect_bottom_y }; // clockwise
	return ret;
}

TuiLine tuiRectGetLeftLine(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiLine ret = { rect_left_x, rect_top_y, rect_left_x, rect_bottom_y }; // clockwise
	return ret;
}

TuiHLine tuiRectGetTopHLine(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	TuiHLine ret = { rect_left_x, rect_right_x, rect_top_y }; // clockwise
	return ret;
}

TuiLine tuiRectGetTopLine(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_top_y = _tuiRectGetTopY(rect);
	TuiLine ret = { rect_left_x, rect_top_y, rect_right_x, rect_top_y }; // clockwise
	return ret;
}

TuiHLine tuiRectGetBottomHLine(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiHLine ret = { rect_right_x, rect_left_x, rect_bottom_y }; // clockwise
	return ret;
}

TuiLine tuiRectGetBottomLine(const TuiRect rect)
{
	const int rect_left_x = _tuiRectGetLeftX(rect);
	const int rect_right_x = _tuiRectGetRightX(rect);
	const int rect_bottom_y = _tuiRectGetBottomY(rect);
	TuiLine ret = { rect_right_x, rect_bottom_y, rect_left_x, rect_bottom_y }; // clockwise
	return ret;
}

TuiBoolean tuiRectContainsPoint2(const TuiRect rect, const TuiPoint2 point2)
{
	if (rect.width <= 0 || rect.height <= 0)
	{
		return TUI_FALSE;
	}
	const int rect_far_x = rect.x + rect.width - 1;
	const int rect_far_y = rect.y + rect.height - 1;
	TuiBoolean rect_contains_point2 =
		(rect.x <= point2.x) && (rect_far_x >= point2.x) &&
		(rect.y <= point2.y) && (rect_far_y >= point2.y);
	return rect_contains_point2;
}

TuiBoolean tuiRectContainsLine(const TuiRect rect, const TuiLine line)
{
	if (rect.width <= 0 || rect.height <= 0)
	{
		return TUI_FALSE;
	}
	const int rect_far_x = rect.x + rect.width - 1;
	const int rect_far_y = rect.y + rect.height - 1;
	TuiBoolean rect_contains_line =
		(rect.x <= line.start_x) && (rect_far_x >= line.start_x) &&
		(rect.x <= line.end_x) && (rect_far_x >= line.end_x) &&
		(rect.y <= line.start_y) && (rect_far_y >= line.start_y) &&
		(rect.y <= line.end_y) && (rect_far_y >= line.end_y);
	return rect_contains_line;
}

TuiBoolean tuiRectContainsHLine(const TuiRect rect, const TuiHLine h_line)
{
	if (rect.width <= 0 || rect.height <= 0)
	{
		return TUI_FALSE;
	}
	const int rect_far_x = rect.x + rect.width - 1;
	const int rect_far_y = rect.y + rect.height - 1;
	TuiBoolean rect_contains_h_line =
		(rect.x <= h_line.start_x) && (rect_far_x >= h_line.start_x) &&
		(rect.x <= h_line.end_x) && (rect_far_x >= h_line.end_x) &&
		(rect.y <= h_line.y) && (rect_far_y >= h_line.y);
	return rect_contains_h_line;
}

TuiBoolean tuiRectContainsVLine(const TuiRect rect, const TuiVLine v_line)
{
	if (rect.width <= 0 || rect.height <= 0)
	{
		return TUI_FALSE;
	}
	const int rect_far_x = rect.x + rect.width - 1;
	const int rect_far_y = rect.y + rect.height - 1;
	TuiBoolean rect_contains_v_line =
		(rect.x <= v_line.x) && (rect_far_x >= v_line.x) &&
		(rect.x <= v_line.start_y) && (rect_far_y >= v_line.start_y) &&
		(rect.y <= v_line.end_y) && (rect_far_y >= v_line.end_y);
	return rect_contains_v_line;
}

TuiBoolean tuiRectContainsRect(const TuiRect rect_1, const TuiRect rect_2)
{
	if (rect_1.width <= 0 || rect_1.height <= 0 || rect_2.width <= 0 || rect_2.height <= 0)
	{
		return TUI_FALSE;
	}
	const int rect_1_far_x = rect_1.x + rect_1.width - 1;
	const int rect_1_far_y = rect_1.y + rect_1.height - 1;
	const int rect_2_far_x = rect_2.x + rect_2.width - 1;
	const int rect_2_far_y = rect_2.y + rect_2.height - 1;
	TuiBoolean rect_contains_line =
		(rect_1.x <= rect_2.x) && (rect_1_far_x >= rect_2.x) &&
		(rect_1.x <= rect_2_far_x) && (rect_1_far_x >= rect_2_far_x) &&
		(rect_1.y <= rect_2.y) && (rect_1_far_y >= rect_2.y) &&
		(rect_1.y <= rect_2_far_y) && (rect_1_far_y >= rect_2_far_y);
	return rect_contains_line;
}

TuiBoolean tuiRectIntersectsLine(const TuiRect rect, const TuiLine line)
{
	if (rect.width <= 0 || rect.height <= 0)
	{
		return TUI_FALSE;
	}
	TuiBoolean rect_intersects_line = 
		tuiLineIntersectsVLine(line, tuiRectGetLeftVLine(rect)) ||
		tuiLineIntersectsVLine(line, tuiRectGetRightVLine(rect)) ||
		tuiLineIntersectsHLine(line, tuiRectGetTopHLine(rect)) ||
		tuiLineIntersectsHLine(line, tuiRectGetBottomHLine(rect));
	return rect_intersects_line;
}

TuiBoolean tuiRectIntersectsHLine(const TuiRect rect, const TuiHLine h_line)
{
	if (rect.width <= 0 || rect.height <= 0)
	{
		return TUI_FALSE;
	}
	TuiBoolean rect_intersects_h_line =
		tuiHLineIntersectsVLine(h_line, tuiRectGetLeftVLine(rect)) ||
		tuiHLineIntersectsVLine(h_line, tuiRectGetRightVLine(rect)) ||
		tuiHLineIntersectsHLine(h_line, tuiRectGetTopHLine(rect)) ||
		tuiHLineIntersectsHLine(h_line, tuiRectGetBottomHLine(rect));
	return rect_intersects_h_line;
}

TuiBoolean tuiRectIntersectsVLine(const TuiRect rect, const TuiVLine v_line)
{
	if (rect.width <= 0 || rect.height <= 0)
	{
		return TUI_FALSE;
	}
	TuiBoolean rect_intersects_v_line =
		tuiVLineIntersectsVLine(v_line, tuiRectGetLeftVLine(rect)) ||
		tuiVLineIntersectsVLine(v_line, tuiRectGetRightVLine(rect)) ||
		tuiVLineIntersectsHLine(v_line, tuiRectGetTopHLine(rect)) ||
		tuiVLineIntersectsHLine(v_line, tuiRectGetBottomHLine(rect));
	return rect_intersects_v_line;
}

TuiBoolean tuiRectIntersectsRect(const TuiRect rect_1, const TuiRect rect_2)
{
	if (rect_1.width <= 0 || rect_1.height <= 0 || rect_2.width <= 0 || rect_2.height <= 0)
	{
		return TUI_FALSE;
	}
	const int rect_1_far_x = rect_1.x + rect_1.width - 1;
	const int rect_1_far_y = rect_1.y + rect_1.height - 1;
	const int rect_2_far_x = rect_2.x + rect_2.width - 1;
	const int rect_2_far_y = rect_2.y + rect_2.height - 1;
	const TuiBoolean rect_intersects_rect =
		(rect_1_far_x >= rect_2.x) &&
		(rect_1.x <= rect_2_far_x) &&
		(rect_1_far_y >= rect_2.y) &&
		(rect_1.y <= rect_2_far_y);
	return rect_intersects_rect;
}