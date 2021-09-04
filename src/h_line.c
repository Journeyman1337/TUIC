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
#include <TUIC/h_line.h>
#include <TUIC/line.h>
#include <TUIC/v_line.h>
#include <TUIC/point2.h>
#include <TUIC/rect.h>
#include <math.h>
#include <stdlib.h>
#include <TUIC/easing.h>


TuiHLine tuiHLine(const int start_x, const int end_x, const int y)
{
	TuiHLine ret = { start_x, end_x, y };
	return ret;
}

TuiPoint2 tuiHLineGetStartPoint2(const TuiHLine h_line)
{
	TuiPoint2 ret = { h_line.start_x, h_line.y };
	return ret;
}

TuiPoint2 tuiHLineGetEndPoint2(const TuiHLine h_line)
{
	TuiPoint2 ret = { h_line.end_x, h_line.y };
	return ret;
}

TuiLine tuiHLineGetLine(const TuiHLine h_line)
{
	TuiLine ret = { h_line.start_x, h_line.y, h_line.end_x, h_line.y };
	return ret;
}

int tuiHLineGetLength(const TuiHLine h_line)
{
	return abs(h_line.end_x - h_line.start_x);
}

TuiBoolean tuiHLineContainsPoint2(const TuiHLine h_line, const TuiPoint2 point2)
{
	const int max_h_line_x = (h_line.start_x > h_line.end_x) ? h_line.start_x : h_line.end_x;
	const int min_h_line_x = (h_line.start_x < h_line.end_x) ? h_line.start_x : h_line.end_x;
	return (point2.y == h_line.y && point2.x >= min_h_line_x && point2.y <= max_h_line_x);
}

TuiBoolean tuiHLineContainsLine(const TuiLine line, const TuiHLine h_line)
{
	if (line.start_y == h_line.y && line.end_y == h_line.y)
	{
		const int max_h_line_x = (h_line.start_x > h_line.end_x) ? h_line.start_x : h_line.end_x;
		const int min_h_line_x = (h_line.start_x < h_line.end_x) ? h_line.start_x : h_line.end_x;
		return (line.start_x >= max_h_line_x && line.end_x >= max_h_line_x && line.start_x <= min_h_line_x && line.end_x <= min_h_line_x);
	}
	return TUI_FALSE;
}

TuiBoolean tuiHLineIntersectsLine(const TuiHLine h_line, const TuiLine line)
{
	return tuiLineIntersectsHLine(line, h_line);
}

TuiBoolean tuiHLineIntersectsVLine(const TuiHLine h_line, const TuiVLine v_line)
{
	return tuiVLineIntersectsHLine(v_line, h_line);
}

TuiBoolean tuiHLineIntersectsRect(const TuiHLine h_line, const TuiRect rect)
{
	return tuiRectIntersectsHLine(rect, h_line);
}
