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
#include <TUIC/rect_it.h>
#include <TUIC/rect.h>
#include <TUIC/error_code.h>
#include <TUIC/debug.h>
#include <math.h>
#include <TUIC/easing.h>

TuiRectIt tuiRectIt(const TuiRect rect)
{
	TuiRectIt ret = { rect.x, tuiRectGetFarX(rect), rect.y, tuiRectGetFarY(rect), rect.x, rect.y };
	return ret;
}

TuiBoolean tuiRectDone(const TuiRectIt it)
{
	return it.cur_x_position > it.right_x || it.cur_y_position > it.bottom_y || it.cur_x_position < it.left_x || it.cur_y_position < it.top_y;
}

void tuiRectItStepForward(TuiRectIt* const it)
{
	if (it == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	if (it->cur_x_position < it->right_x)
	{
		it->cur_x_position++;
	}
	else
	{
		it->cur_y_position++;
		it->cur_x_position = it->left_x;
	}
}

void tuiRectItStepBackward(TuiRectIt* const it)
{
	if (it == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	if (it->cur_x_position > it->left_x)
	{
		it->cur_x_position--;
	}
	else
	{
		it->cur_y_position--;
		it->cur_x_position = it->right_x;
	}
}

void tuiRectItSetStart(TuiRectIt* const it)
{
	if (it == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->cur_x_position = it->left_x;
	it->cur_y_position = it->top_y;
}

TuiRect tuiRectItGetRect(const TuiRectIt it)
{
	TuiRect rect = { it.left_x, it.top_y, it.right_x - it.left_x, it.bottom_y - it.top_y };
	return rect;
}

TuiPoint2 tuiRectItGetPoint2(const TuiRectIt it)
{
	TuiPoint2 point2 = { it.cur_x_position, it.cur_y_position };
	return point2;
}
