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
#include <TUIC/line_it.h>
#include <TUIC/line.h>
#include <math.h>
#include <TUIC/easing.h>


TuiLineIt tuiLineItStart(const TuiLine line)
{
	const int diagonal_length = tuiLineGetDiagonalLength(line);
	TuiLineIt ret = { line.start_x, line.start_y, line.end_x, line.end_y, diagonal_length, 0 };
	return ret;
}

TuiLineIt tuiLineItEnd(const TuiLine line)
{
	const int diagonal_length = tuiLineGetDiagonalLength(line);
	TuiLineIt ret = { line.start_x, line.start_y, line.end_x, line.end_y, diagonal_length, diagonal_length - 1 };
	return ret;
}

TuiBoolean tuiLineItBeforeStart(const TuiLineIt it)
{
	return it.position < 0;
}

TuiBoolean tuiLineItAfterEnd(const TuiLineIt it)
{
	return it.position >= it.diagonal_length;
}

void tuiLineItStepForward(TuiLineIt* const it)
{
	if (it == TUI_NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->position++;
}

void tuiLineItStepBackward(TuiLineIt* const it)
{
	if (it == TUI_NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->position--;
}

void tuiLineItSetStart(TuiLineIt* const it)
{
	if (it == TUI_NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->position = 0;
}

void tuiLineItSetEnd(TuiLineIt* const it)
{
	if (it == TUI_NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->position = it->diagonal_length - 1;
}

TuiLine tuiLineItGetLine(const TuiLineIt it)
{
	TuiLine ret = { it.start_x, it.start_y, it.end_x, it.end_y };
	return ret;
}

TuiPoint2 tuiLineItGetPoint2(const TuiLineIt it)
{
	const float percent = tuiLineItGetPercent(it);
	const int x = (int)tuiLerp((float)it.start_x, (float)it.end_x, percent);
	const int y = (int)tuiLerp((float)it.start_y, (float)it.end_y, percent);
	TuiPoint2 ret = { x, y };
	return ret;
}

float tuiLineItGetPercent(const TuiLineIt it)
{
	if (it.diagonal_length == 1) // avoid divide by 0 error later
	{
		return 1.0f;
	}

	return (float)it.position / (float)(it.diagonal_length - 1);
}
