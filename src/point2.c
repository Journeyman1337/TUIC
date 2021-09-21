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
#include <TUIC/point2.h>
#include <math.h>
#include <stdlib.h> //for abs on mac
#include <TUIC/easing.h>
#include "grid_shapes_inline.h"


TuiPoint2 tuiPoint2(const int x, const int y)
{
	TuiPoint2 ret = { x, y };
	return ret;
}

float tuiPoint2GetMagnitude(const TuiPoint2 point2)
{
	return _tuiIntPointMagnitude(point2.x, point2.y);
}

float tuiPoint2GetDistanceToPoint2(const TuiPoint2 point2_1, const TuiPoint2 point2_2)
{
	return _tuiIntPointDistance(point2_1.x, point2_1.y, point2_2.x, point2_2.y);
}

float tuiPoint2GetDistanceToLine(const TuiPoint2 point2, const TuiLine line)
{
	return _tuiIntPointLineDistance(point2.x, point2.y, line.start_x, line.start_y, line.end_x, line.end_y);
}

int tuiPoint2GetCrossProductZ(const TuiPoint2 point2_1, const TuiPoint2 point2_2)
{
	return _tuiIntCrossProductZ(point2_1.x, point2_1.y, point2_2.x, point2_2.y);
}

float tuiPoint2GetUnitCrossProductZ(const TuiPoint2 point2_1, const TuiPoint2 point2_2)
{
	return _tuiIntUnitCrossProductZ(point2_1.x, point2_1.y, point2_2.x, point2_2.y);
}

int tuiPoint2GetDotProduct(const TuiPoint2 point2_1, const TuiPoint2 point2_2)
{
	return _tuiIntDotProduct(point2_1.x, point2_1.y, point2_2.x, point2_2.y);
}

float tuiPoint2GetUnitDotProduct(const TuiPoint2 point2_1, const TuiPoint2 point2_2)
{
	return _tuiIntUnitDotProduct(point2_1.x, point2_1.y, point2_2.x, point2_2.y);
}

TuiBoolean tuiPoint2Collinear(const TuiPoint2 point2_1, const TuiPoint2 point2_2, const TuiPoint2 point2_3)
{
	return _tuiPoint2Collienar(point2_1, point2_2, point2_3);
}
