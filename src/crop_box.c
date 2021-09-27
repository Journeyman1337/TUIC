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
#include <TUIC/crop_box.h>
#include <TUIC/circle.h>
#include <TUIC/point2.h>
#include <TUIC/line.h>
#include <TUIC/rect.h>
#include <TUIC/ring.h>
#include "grid_shapes_inline.h"
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>


TuiCropBox tuiCropBox(const int x, const int y, const int width, const int height, const int depth)
{
	TuiCropBox ret = { x, y, width, height, depth };
	return ret;
}

static inline int _tuiCropBoxGetBoxLeftX(const TuiCropBox crop_box)
{
	const int crop_box_left_x = crop_box.x;
	return crop_box_left_x;
}

static inline int _tuiCropBoxGetBoxRightX(const TuiCropBox crop_box)
{
	const int crop_box_right_x = (crop_box.width == 0) ? crop_box.x : crop_box.x + abs(crop_box.width) - 1;
	return crop_box_right_x;
}

static inline int _tuiCropBoxGetBoxTopY(const TuiCropBox crop_box)
{
	const int crop_box_top_y = crop_box.y;
	return crop_box_top_y;
}

static inline int _tuiCropBoxGetBoxBottomY(const TuiCropBox crop_box)
{
	const int crop_box_bottom_y = (crop_box.height == 0) ? crop_box.y : crop_box.y + abs(crop_box.height) - 1;
	return crop_box_bottom_y;
}

int tuiCropBoxGetBoxFarX(const TuiCropBox crop_box)
{
	const int box_far_x = (crop_box.width == 0) ? crop_box.x : crop_box.x + abs(crop_box.width) - 1;
	return box_far_x;
}

int tuiCropBoxGetBoxFarY(const TuiCropBox crop_box)
{
	const int box_far_y = (crop_box.height == 0) ? crop_box.y : crop_box.y + abs(crop_box.height) - 1;
	return box_far_y;
}

int tuiCropBoxGetBoxTileWidth(const TuiCropBox crop_box)
{
	const int tile_width = abs(crop_box.width);
	return tile_width;
}

int tuiCropBoxGetBoxTileHeight(const TuiCropBox crop_box)
{
	const int tile_height = abs(crop_box.height);
	return tile_height;
}

int tuiCropBoxGetLeftX(const TuiCropBox crop_box)
{
	const int crop_far_x = tuiCropBoxGetCropFarX(crop_box);
	const int left_x = CLAMP(crop_box.x, crop_box.crop_x, crop_far_x);
	return left_x;
}

int tuiCropBoxGetRightX(const TuiCropBox crop_box)
{
	const int crop_far_x = tuiCropBoxGetCropFarX(crop_box);
	const int box_far_x = tuiCropBoxGetBoxFarX(crop_box);
	const int right_x = CLAMP(box_far_x, crop_box.crop_x, crop_far_x);
	return right_x;
}

int tuiCropBoxGetTopY(const TuiCropBox crop_box)
{
	const int crop_far_y = tuiCropBoxGetCropFarY(crop_box);
	const int top_y = CLAMP(crop_box.y, crop_box.crop_y, crop_far_y);
	return top_y;
}

int tuiCropBoxGetBottomY(const TuiCropBox crop_box)
{
	const int crop_far_y = tuiCropBoxGetCropFarY(crop_box);
	const int box_far_y = tuiCropBoxGetBoxFarY(crop_box);
	const int bottom_y = CLAMP(box_far_y, crop_box.crop_y, crop_far_y);
	return bottom_y;
}

TuiBoolean tuiCropBoxIsFlippedWide(const TuiCropBox crop_box)
{
	const TuiBoolean flipped_wide = crop_box.width < 0;
	return flipped_wide;
}

TuiBoolean tuiCropBoxIsFlippedTall(const TuiCropBox crop_box)
{
	const TuiBoolean flipped_tall = crop_box.height < 0;
	return flipped_tall;
}

TuiBoolean tuiCropBoxIsDegenerate(const TuiCropBox crop_box)
{
	TuiBoolean box_degenerate = (crop_box.width == 0 || crop_box.height == 0);
	if (box_degenerate) return TUI_TRUE;
	TuiBoolean crop_degenerate = (crop_box.crop_width == 0 || crop_box.crop_height == 0);
	return crop_degenerate;
}

TuiRect tuiCropBoxGetBoundingRect(const TuiCropBox crop_box)
{
	const int left_x = tuiCropBoxGetLeftX(crop_box);
	const int right_x = tuiCropBoxGetRightX(crop_box);
	const int top_y = tuiCropBoxGetTopY(crop_box);
	const int bottom_y = tuiCropBoxGetBottomY(crop_box);
	const TuiRect ret = { left_x, top_y, abs(right_x - left_x) + 1, abs(bottom_y - top_y) + 1 };
	return ret;
}

TuiRect tuiCropBoxGetCropRect(const TuiCropBox crop_box)
{
	TuiRect ret = { crop_box.crop_x, crop_box.crop_y, crop_box.crop_width, crop_box.crop_height };
}

int tuiCropBoxGetCropFarX(const TuiCropBox crop_box)
{
	const int crop_far_x = (crop_box.crop_width == 0) ? crop_box.crop_x : crop_box.crop_x + abs(crop_box.crop_width) - 1;
	return crop_far_x;
}

int tuiCropBoxGetCropFarY(const TuiCropBox crop_box)
{
	const int crop_far_y = (crop_box.crop_height == 0) ? crop_box.crop_y : crop_box.crop_y + abs(crop_box.crop_height) - 1;
	return crop_far_y;
}

int tuiCropCircleGetCropFarX(const TuiCropBox crop_box)
{
	const int crop_far_x = (crop_box.crop_width == 0) ? crop_box.crop_x : crop_box.crop_x + abs(crop_box.crop_width) - 1;
	return crop_far_x;
}

int tuiCropCircleGetCropFarY(const TuiCropBox crop_box)
{
	const int crop_far_y = (crop_box.crop_height == 0) ? crop_box.crop_y : crop_box.crop_y + abs(crop_box.crop_height) - 1;
	return crop_far_y;
}

TuiBox tuiCropBoxGetBox(const TuiCropBox crop_box)
{
	const TuiBox ret = { crop_box.x, crop_box.y, crop_box.width, crop_box.height, crop_box.depth };
}

TuiPoint2 tuiCropBoxGetBoxTopLeftCornerPoint2(const TuiCropBox crop_box)
{
	const int crop_box_left_x = _tuiCropBoxGetBoxLeftX(crop_box);
	const int crop_box_top_y = _tuiCropBoxGetBoxTopY(crop_box);
	TuiPoint2 ret = { crop_box_left_x, crop_box_top_y };
	return ret;
}

TuiPoint2 tuiCropBoxGetBoxTopRightCornerPoint2(const TuiCropBox crop_box)
{
	const int crop_box_right_x = _tuiCropBoxGetBoxRightX(crop_box);
	const int crop_box_top_y = _tuiCropBoxGetBoxTopY(crop_box);
	TuiPoint2 ret = { crop_box_right_x, crop_box_top_y };
	return ret;
}

TuiPoint2 tuiCropBoxGetBoxBottomLeftCornerPoint2(const TuiCropBox crop_box)
{
	const int crop_box_left_x = _tuiCropBoxGetBoxLeftX(crop_box);
	const int crop_box_bottom_y = _tuiCropBoxGetBoxBottomY(crop_box);
	TuiPoint2 ret = { crop_box_left_x, crop_box_bottom_y };
	return ret;
}

TuiPoint2 tuiCropBoxGetBoxBottomRightCornerPoint2(const TuiCropBox crop_box)
{
	const int crop_box_right_x = _tuiCropBoxGetBoxRightX(crop_box);
	const int crop_box_bottom_y = _tuiCropBoxGetBoxBottomY(crop_box);
	TuiPoint2 ret = { crop_box_right_x, crop_box_bottom_y };
	return ret;
}

TuiLine tuiCropBoxGetBoxLeftBorderLine(const TuiCropBox crop_box, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int box_left_x = _tuiCropBoxGetBoxLeftX(crop_box);
	const int box_top_y = _tuiCropBoxGetBoxTopY(crop_box);
	const int box_bottom_y = _tuiCropBoxGetBoxBottomY(crop_box);
	TuiLine ret = { box_left_x, box_top_y + corner_change, box_left_x, box_bottom_y - corner_change }; // clockwise
	return ret;
}

TuiLine tuiCropBoxGetBoxRightBorderLine(const TuiCropBox crop_box, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int box_right_x = _tuiCropBoxGetBoxRightX(crop_box);
	const int box_top_y = _tuiCropBoxGetBoxTopY(crop_box);
	const int box_bottom_y = _tuiCropBoxGetBoxBottomY(crop_box);
	TuiLine ret = { box_right_x, box_bottom_y - corner_change, box_right_x, box_top_y + corner_change }; // clockwise
	return ret;
}

TuiLine tuiCropBoxGetBoxTopBorderLine(const TuiCropBox crop_box, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int box_left_x = _tuiCropBoxGetBoxLeftX(crop_box);
	const int box_right_x = _tuiCropBoxGetBoxRightX(crop_box);
	const int box_top_y = _tuiCropBoxGetBoxTopY(crop_box);
	TuiLine ret = { box_left_x + corner_change, box_top_y, box_right_x - corner_change, box_top_y }; // clockwise
	return ret;
}

TuiLine tuiCropBoxGetBoxBottomBorderLine(const TuiCropBox crop_box, const TuiBoolean corners)
{
	const int corner_change = (corners) ? 0 : 1;
	const int box_left_x = _tuiCropBoxGetBoxLeftX(crop_box);
	const int box_right_x = _tuiCropBoxGetBoxRightX(crop_box);
	const int box_bottom_y = _tuiCropBoxGetBoxBottomY(crop_box);
	TuiLine ret = { box_right_x - corner_change, box_bottom_y, box_left_x + corner_change, box_bottom_y }; // clockwise
	return ret;
}

TuiBoolean tuiCropBoxContainsPoint2(const TuiCropBox crop_box, const TuiPoint2 point2)
{
	TuiBoolean crop_rect_contains_point2 = tuiRectContainsPoint2(tuiCropBoxGetCropRect(crop_box), point2);
	if (!crop_rect_contains_point2) return TUI_FALSE;
	TuiBoolean circle_contains_point2 = tuiBoxContainsPoint2(tuiCropBoxGetBox(crop_box), point2);
	return circle_contains_point2;
}

TuiBoolean tuiCropBoxIntersectsLine(const TuiCropBox crop_box, const TuiLine line)
{
	TuiBoolean crop_rect_intersects_line = tuiRectIntersectsLine(tuiCropBoxGetCropRect(crop_box), line);
	if (!crop_rect_intersects_line) return TUI_FALSE;
	TuiBoolean box_intersects_line = tuiBoxIntersectsLine(tuiCropBoxGetBox(crop_box), line);
	return box_intersects_line;
}

TuiBoolean tuiCropBoxIntersectsRect(const TuiCropBox crop_box, const TuiRect rect)
{
	TuiBoolean crop_rect_intersects_rect = tuiRectIntersectsRect(tuiCropBoxGetCropRect(crop_box), rect);
	if (!crop_rect_intersects_rect) return TUI_FALSE;
	TuiBoolean box_intersects_rect = tuiBoxIntersectsRect(tuiCropBoxGetBox(crop_box), rect);
	return box_intersects_rect;
}

TuiBoolean tuiCropBoxIntersectsBox(const TuiCropBox crop_box, const TuiBox box)
{
	TuiBoolean crop_rect_intersects_box = tuiRectIntersectsBox(tuiCropBoxGetCropRect(crop_box), box);
	if (!crop_rect_intersects_box) return TUI_FALSE;
	TuiBoolean box_intersects_box = tuiBoxIntersectsBox(tuiCropBoxGetBox(crop_box), box);
	return box_intersects_box;
}

TuiBoolean tuiCropBoxIntersectsCropBox(const TuiCropBox crop_box_1, const TuiCropBox crop_box_2)
{
	const TuiRect crop_box_1_crop_rect = tuiCropBoxGetCropRect(crop_box_1);
	const TuiBox crop_box_2_box = tuiCropBoxGetBox(crop_box_2);
	TuiBoolean crop_rect_1_intersects_box_2 = tuiRectIntersectsBox(crop_box_1_crop_rect, crop_box_2_box);
	if (!crop_rect_1_intersects_box_2) return TUI_FALSE;
	const TuiRect crop_box_2_crop_rect = tuiCropBoxGetCropRect(crop_box_2);
	const TuiBox crop_box_1_box = tuiCropBoxGetBox(crop_box_1);
	TuiBoolean crop_rect_2_intersects_box_1 = tuiRectIntersectsBox(crop_box_2_crop_rect, crop_box_1_box);
	if (!crop_rect_2_intersects_box_1) return TUI_FALSE;
	TuiBoolean box_1_intersects_box_2 = tuiBoxIntersectsBox(crop_box_1_box, crop_box_2_box);
	return box_1_intersects_box_2;
}

TuiBoolean tuiCropBoxIntersectsCircle(const TuiCropBox crop_box, const TuiCircle circle)
{
	TuiBoolean crop_rect_intersects_circle = tuiRectIntersectsCircle(tuiCropBoxGetCropRect(crop_box), circle);
	if (!crop_rect_intersects_circle) return TUI_FALSE;
	TuiBoolean circle_intersects_circle = tuiBoxIntersectsCircle(tuiCropBoxGetBox(crop_box), circle);
	return circle_intersects_circle;
}

TuiBoolean tuiCropBoxIntersectsRing(const TuiCropBox crop_box, const TuiRing ring)
{
	TuiBoolean crop_rect_intersects_ring = tuiRectIntersectsRing(tuiCropBoxGetCropRect(crop_box), ring);
	if (!crop_rect_intersects_ring) return TUI_FALSE;
	TuiBoolean circle_intersects_ring = tuiBoxIntersectsRing(tuiCropBoxGetBox(crop_box), ring);
	return circle_intersects_ring;
}
