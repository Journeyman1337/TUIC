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
#include <TUIC/v_line.h>
#include <TUIC/line.h>
#include <TUIC/point2.h>
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>


TuiVLine tuiVLine(const int start_x, const int end_x, const int y)
{
	TuiVLine ret = { start_x, end_x, y };
	return ret;
}

TuiPoint2 tuiVLineGetStartPoint2(const TuiVLine v_line)
{
	TuiPoint2 ret = { v_line.x, v_line.start_y };
	return ret;
}

TuiPoint2 tuiVLineGetEndPoint2(const TuiVLine v_line)
{
	TuiPoint2 ret = { v_line.x, v_line.end_y };
	return ret;
}

TuiLine tuiVLineGetLine(const TuiVLine v_line)
{
	TuiLine ret = { v_line.x, v_line.start_y, v_line.x, v_line.end_y };
	return ret;
}

int tuiVLineGetLength(const TuiVLine v_line)
{
	return abs(v_line.end_y - v_line.start_y);
}

TuiBoolean tuiVLineContainsPoint2(const TuiVLine v_line, const TuiPoint2 point2)
{
	const int max_v_line_y = (v_line.start_y > v_line.end_y) ? v_line.start_y : v_line.end_y;
	const int min_v_line_y = (v_line.start_y < v_line.end_y) ? v_line.start_y : v_line.end_y;
	return (point2.x == v_line.x && point2.y >= min_v_line_y && point2.y <= max_v_line_y);
}

TuiBoolean tuiVLineContainsLine(const TuiLine line, const TuiVLine v_line)
{
	if (line.start_x == v_line.x && line.end_x == v_line.x)
	{
		const int max_v_line_y = (v_line.start_y > v_line.end_y) ? v_line.start_y : v_line.end_y;
		const int min_v_line_y = (v_line.start_y < v_line.end_y) ? v_line.start_y : v_line.end_y;
		return (line.start_y >= max_v_line_y && line.end_y >= max_v_line_y && line.start_y <= min_v_line_y && line.end_y <= min_v_line_y);
	}
	return TUI_FALSE;
}

TuiBoolean tuiVLineIntersectsLine(const TuiVLine v_line, const TuiLine line)
{
	return tuiLineIntersectsVLine(line, v_line);
}

TuiBoolean tuiVLineIntersectsHLine(const TuiVLine v_line, const TuiHLine h_line)
{
	const int max_v_line_y = (v_line.start_y > v_line.end_y) ? v_line.start_y : v_line.end_y;
	const int min_v_line_y = (v_line.start_y < v_line.end_y) ? v_line.start_y : v_line.end_y;
	const int max_h_line_x = (h_line.start_x > h_line.end_x) ? h_line.start_x : h_line.end_x;
	const int min_h_line_x = (h_line.start_x < h_line.end_x) ? h_line.start_x : h_line.end_x;
	return (max_v_line_y >= h_line.y && min_v_line_y <= h_line.y && max_h_line_x >= v_line.x && min_h_line_x <= v_line.x);
}
