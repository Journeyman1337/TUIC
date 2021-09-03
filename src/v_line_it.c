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
#include <TUIC/v_line_it.h>
#include <TUIC/v_line.h>
#include <math.h>
#include <TUIC/easing.h>


TuiVLineIt tuiVLineItStart(const TuiVLine v_line)
{
	const int length = tuiVLineGetLength(v_line);
	TuiVLineIt ret = { v_line.x, v_line.start_y, v_line.end_y, length, 0 };
	return ret;
}

TuiVLineIt tuiVLineItEnd(const TuiVLine v_line)
{
	const int length = tuiVLineGetLength(v_line);
	TuiVLineIt ret = { v_line.x, v_line.start_y, v_line.end_y, length, length - 1 };
	return ret;
}

TuiBoolean tuiVLineItBeforeStart(const TuiVLineIt it)
{
	return it.position < 0;
}

TuiBoolean tuiVLineItAfterEnd(const TuiVLineIt it)
{
	return it.position >= it.length;
}

void tuiVLineItStepForward(TuiVLineIt* const it)
{
	if (it == TUI_NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->position++;
}

void tuiVLineItStepBackward(TuiVLineIt* const it)
{
	if (it == TUI_NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->position--;
}

void tuiVLineItSetStart(TuiVLineIt* const it)
{
	if (it == TUI_NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->position = 0;
}

void tuiVLineItSetEnd(TuiVLineIt* const it)
{
	if (it == TUI_NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_GRID_SHAPE_ITERATOR, __func__);
		return;
	}

	it->position = it->length - 1;
}

TuiVLine tuiVLineItGetVLine(const TuiVLineIt it)
{
	TuiVLine ret = { it.x, it.start_y, it.end_y };
	return ret;
}

TuiPoint2 tuiVLineItGetPoint2(const TuiVLineIt it)
{
	const float percent = tuiVLineItGetPercent(it);
	const int x = it.x;
	const int y = it.start_y + it.position;
	TuiPoint2 ret = { x, y };
	return ret;
}

float tuiVLineItGetPercent(const TuiVLineIt it)
{
	if (it.length == 1) // avoid divide by 0 error later
	{
		return 1.0f;
	}

	return (float)it.position / (float)(it.length - 1);
}
