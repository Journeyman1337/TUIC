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
#include <TUIC/circle_it.h>
#include <TUIC/circle.h>
#include <TUIC/error_code.h>
#include <TUIC/debug.h>
#include <math.h>
#include <TUIC/easing.h>


TuiCircleIt tuiCircleIt(const TuiCircle circle)
{
	const int top_y = tuiCircleGetTopY(circle);
	const int bottom_y = tuiCircleGetBottomY(circle);
	const float first_row_y_distance = (float)(top_y - circle.center_y);
	const float first_row_x_distance = sqrtf(circle.radius * circle.radius - first_row_y_distance * first_row_y_distance); // pythagorean theorem
	const int first_row_left_x = circle.center_x - (int)ceilf(first_row_x_distance);
	const int first_row_right_x = circle.center_x + (int)floorf(first_row_x_distance);
	TuiCircleIt ret = { circle.radius, circle.center_x, circle.center_y, top_y , bottom_y, first_row_left_x, first_row_right_x, first_row_left_x, top_y };
	return ret;
}

TuiBoolean tuiCircleItDone(const TuiCircleIt it)
{
	return (it.cur_y_position > it.bottom_y);
}

void tuiCircleItStepForward(TuiCircleIt* const it)
{
	if (it == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	if (it->cur_x_position == it->row_right_x)
	{
		it->cur_y_position++;
		if (it->cur_y_position > it->bottom_y) return;
		const float row_y_distance = (float)(it->cur_y_position - it->center_y);
		const float row_x_distance = sqrtf(it->radius * it->radius - row_y_distance * row_y_distance); // pythagorean theorem
		it->row_left_x = it->center_x - (int)ceilf(row_x_distance);
		it->row_right_x = it->center_x + (int)floorf(row_x_distance);
		it->cur_x_position = it->row_left_x;
	}
	else
	{
		it->cur_x_position++;
	}
}

void tuiCircleItSetStart(TuiCircleIt* const it)
{
	if (it == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->cur_y_position = it->top_y;
	if (it->cur_y_position > it->bottom_y) return;
	const float row_y_distance = (float)(it->cur_y_position - it->center_y);
	const float row_x_distance = sqrtf(it->radius * it->radius - row_y_distance * row_y_distance); //pythagorean theorem
	it->row_left_x = it->center_x - (int)ceilf(row_x_distance);
	it->row_right_x = it->center_x + (int)floorf(row_x_distance);
	it->cur_x_position = it->row_left_x;
}

TuiCircle tuiCircleItGetCircle(const TuiCircleIt it)
{
	TuiCircle ret = { it.center_x, it.center_y, it.radius };
	return ret;
}

TuiPoint2 tuiCircleItGetPoint2(const TuiCircleIt it)
{
	TuiPoint2 ret = { it.cur_x_position, it.cur_y_position };
	return ret;
}



