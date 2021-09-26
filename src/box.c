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
#include <TUIC/box.h>
#include <TUIC/circle.h>
#include <TUIC/point2.h>
#include <TUIC/line.h>
#include <TUIC/rect.h>
#include <TUIC/ring.h>
#include "grid_shapes_inline.h"
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>

TuiBox tuiBox(const int x, const int y, const int width, const int height, const int depth)
{
	TuiBox ret = { x, y, width, height, depth };
	return ret;
}

static inline int _tuiBoxGetLeftX(const TuiBox box)
{
	const int rect_left_x = box.x;
	return rect_left_x;
}

static inline int _tuiBoxGetRightX(const TuiBox box)
{
	const int rect_right_x = (box.width == 0) ? box.x : box.x + abs(box.width) - 1;
	return rect_right_x;
}

static inline int _tuiBoxGetTopY(const TuiBox box)
{
	const int rect_top_y = box.y;
	return rect_top_y;
}

static inline int _tuiBoxGetBottomY(const TuiBox box)
{
	const int rect_bottom_y = (box.height == 0) ? box.y : box.y + abs(box.height) - 1;
	return rect_bottom_y;
}

int tuiBoxGetFarX(const TuiBox box)
{
	const int far_x = (box.width == 0) ? box.x : box.x + abs(box.width) - 1;
	return far_x;
}

int tuiBoxGetFarY(const TuiBox box)
{
	const int far_y = (box.height == 0) ? box.y : box.y + abs(box.height) - 1;
	return far_y;
}

int tuiBoxGetTileWidth(const TuiBox box)
{
	const int tile_width = abs(box.width);
	return tile_width;
}

int tuiBoxGetTileHeight(const TuiBox box)
{
	const int tile_height = abs(box.height);
	return tile_height;
}

TuiBoolean tuiBoxIsFlippedWide(const TuiBox box)
{
	const TuiBoolean flipped_wide = box.width < 0;
	return flipped_wide;
}

TuiBoolean tuiBoxIsFlippedTall(const TuiBox box)
{
	const TuiBoolean flipped_tall = box.height < 0;
	return flipped_tall;
}

TuiBoolean tuiBoxIsDegenerate(const TuiBox box)
{
	TuiBoolean degenerate = (box.width == 0) || (box.height == 0) || (box.depth == 0);
	return degenerate;
}

TuiRect tuiBoxGetRect(const TuiBox box)
{
	TuiRect ret = { box.x, box.y, box.width, box.height };
	return ret;
}

TuiRect tuiBoxGetInnerRect(const TuiBox box)
{
	const int abs_depth = abs(box.depth);
	TuiRect ret = { box.x + abs_depth, box.y + abs_depth, box.x + abs(box.width) - 1 - abs_depth, box.y + abs(box.height) - 1 - abs_depth };
	return ret;
}

TuiPoint2 tuiBoxGetTopLeftCornerPoint2(const TuiBox box)
{
	const int box_left_x = _tuiBoxGetLeftX(box);
	const int box_top_y = _tuiBoxGetTopY(box);
	TuiPoint2 ret = { box_left_x, box_top_y };
	return ret;
}

TuiPoint2 tuiBoxGetTopRightCornerPoint2(const TuiBox box)
{
	const int box_right_x = _tuiBoxGetRightX(box);
	const int box_top_y = _tuiBoxGetTopY(box);
	TuiPoint2 ret = { box_right_x, box_top_y };
	return ret;
}

TuiPoint2 tuiBoxGetBottomLeftCornerPoint2(const TuiBox box)
{
	const int box_left_x = _tuiBoxGetLeftX(box);
	const int box_bottom_y = _tuiBoxGetBottomY(box);
	TuiPoint2 ret = { box_left_x, box_bottom_y };
	return ret;
}

TuiPoint2 tuiBoxGetBottomRightCornerPoint2(const TuiBox box)
{
	const int box_right_x = _tuiBoxGetRightX(box);
	const int box_bottom_y = _tuiBoxGetBottomY(box);
	TuiPoint2 ret = { box_right_x, box_bottom_y };
	return ret;
}

TuiLine tuiBoxGetLeftBorderLine(const TuiBox box, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int box_left_x = _tuiBoxGetLeftX(box);
	const int box_top_y = _tuiBoxGetTopY(box);
	const int box_bottom_y = _tuiBoxGetBottomY(box);
	TuiLine ret = { box_left_x, box_top_y + corner_change, box_left_x, box_top_y - corner_change }; // clockwise
	return ret;
}

TuiLine tuiBoxGetRightBorderLine(const TuiBox box, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int box_right_x = _tuiBoxGetRightX(box);
	const int box_top_y = _tuiBoxGetTopY(box);
	const int box_bottom_y = _tuiBoxGetBottomY(box);
	TuiLine ret = { box_right_x, box_bottom_y - corner_change, box_right_x, box_top_y + corner_change }; // clockwise
	return ret;
}

TuiLine tuiBoxGetTopBorderLine(const TuiBox box, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int box_left_x = _tuiBoxGetLeftX(box);
	const int box_right_x = _tuiBoxGetRightX(box);
	const int box_top_y = _tuiBoxGetTopY(box);
	TuiLine ret = { box_left_x + corner_change, box_top_y, box_right_x - corner_change, box_top_y }; // clockwise
	return ret;
}

TuiLine tuiBoxGetBottomBorderLine(const TuiBox box, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int box_left_x = _tuiBoxGetLeftX(box);
	const int box_right_x = _tuiBoxGetRightX(box);
	const int box_bottom_y = _tuiBoxGetBottomY(box);
	TuiLine ret = { box_right_x - corner_change, box_bottom_y, box_left_x + corner_change, box_bottom_y }; // clockwise
	return ret;
}

TuiBoolean tuiBoxContainsPoint2(const TuiBox box, const TuiPoint2 point2)
{
	if (tuiBoxIsDegenerate(box)) return TUI_FALSE;
	if (tuiRectContainsPoint2(tuiBoxGetInnerRect(box), point2)) return TUI_FALSE;
	return tuiRectContainsPoint2(tuiBoxGetRect(box), point2);
}

TuiBoolean tuiBoxIntersectsLine(const TuiBox box, const TuiLine line)
{
	if (tuiBoxIsDegenerate(box)) return TUI_FALSE;
	if (tuiRectContainsLine(tuiBoxGetInnerRect(box), line)) return TUI_FALSE;
	return (tuiRectIntersectsLine(tuiBoxGetRect(box), line));
}

TuiBoolean tuiBoxIntersectsRect(const TuiBox box, const TuiRect rect)
{
	if (tuiBoxIsDegenerate(box) || tuiRectIsDegenerate(rect)) return TUI_FALSE;
	if (tuiRectContainsRect(tuiBoxGetInnerRect(box), rect)) return TUI_FALSE;
	return (tuiRectIntersectsRect(tuiBoxGetRect(box), rect));
}

TuiBoolean tuiBoxIntersectsBox(const TuiBox box_1, const TuiBox box_2)
{
	if (tuiBoxIsDegenerate(box_1) || tuiBoxIsDegenerate(box_2)) return TUI_FALSE;
	const TuiRect box_1_inner_rect = tuiBoxGetInnerRect(box_1);
	const TuiRect box_2_rect = tuiBoxGetRect(box_2);
	if (tuiRectContainsRect(box_1_inner_rect, box_2_rect)) return TUI_FALSE;
	const TuiRect box_2_inner_rect = tuiBoxGetInnerRect(box_2);
	const TuiRect box_1_rect = tuiBoxGetRect(box_1);
	if (tuiRectContainsRect(box_2_inner_rect, box_1_rect)) return TUI_FALSE;
	return (
			tuiRectIntersectsRect(box_1_inner_rect, box_2_inner_rect) ||
			tuiRectIntersectsRect(box_1_inner_rect, box_2_rect) ||
			tuiRectIntersectsRect(box_2_inner_rect, box_1_inner_rect) ||
			tuiRectIntersectsRect(box_2_inner_rect, box_1_rect)
		);
}

TuiBoolean tuiBoxIntersectsCircle(const TuiBox box, const TuiCircle circle)
{
	if (tuiBoxIsDegenerate(box) || tuiCircleIsDegenerate(circle)) return TUI_FALSE;
	if (tuiRectContainsCircle(tuiBoxGetInnerRect(box), circle)) return TUI_FALSE;
	return (tuiRectIntersectsCircle(tuiBoxGetRect(box), circle));
}

TuiBoolean tuiBoxIntersectsRing(const TuiBox box, const TuiRing ring)
{
	const TuiCircle ring_circle = tuiRingGetCircle(ring);
	if (tuiBoxIsDegenerate(box) || tuiCircleIsDegenerate(ring_circle)) return TUI_FALSE;
	if (tuiRectContainsCircle(tuiBoxGetInnerRect(box), ring_circle)) return TUI_FALSE;
	return (tuiRectIntersectsCircle(tuiBoxGetRect(box), ring_circle));
}
