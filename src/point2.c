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


TuiPoint2 tuiPoint2(const int x, const int y)
{
	TuiPoint2 ret = { x, y };
	return ret;
}

float tuiPoint2GetMagnitude(const TuiPoint2 point2)
{
	const float magnitude = sqrtf((float)abs((point2.x * point2.x) + (point2.y * point2.y))); // use pythagorean theorem
	return magnitude;
}

float tuiPoint2Distance(const TuiPoint2 point2_1, const TuiPoint2 point2_2)
{
	const int x_difference = point2_1.x - point2_2.x; // calculate difference of x coordinates
	const int y_difference = point2_1.y - point2_2.y; // calculate difference of y coordinates
	const float distance = sqrtf((float)abs((x_difference * x_difference) + (y_difference * y_difference))); // use pythagorean theorem
	return distance;
}

int tuiPoint2GetCrossProduct(const TuiPoint2 point2_1, const TuiPoint2 point2_2)
{
	return (point2_1.x * point2_2.x) - (point2_1.y * point2_2.y);
}

float tuiPoint2GetDotProduct(const TuiPoint2 point2_1, const TuiPoint2 point2_2)
{
	const float point2_1_magnitude = tuiPoint2GetMagnitude(point2_1);
	const float point2_2_magnitude = tuiPoint2GetMagnitude(point2_2);
	const float point2_1_unit_x = (float)point2_1.x / point2_1_magnitude;
	const float point2_1_unit_y = (float)point2_1.y / point2_1_magnitude;
	const float point2_2_unit_x = (float)point2_2.x / point2_2_magnitude;
	const float point2_2_unit_y = (float)point2_2.y / point2_2_magnitude;
	return (point2_1_unit_x * point2_2_unit_x) + (point2_1_unit_y * point2_2_unit_y);
}
