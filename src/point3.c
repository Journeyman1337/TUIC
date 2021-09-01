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
#include <TUIC/point3.h>
#include <math.h>
#include <TUIC/easing.h>


TuiPoint3 tuiPoint3(const int x, const int y, const int z)
{
	TuiPoint3 ret = { x, y, z };
	return ret;
}

float tuiPoint3GetMagnitude(const TuiPoint3 point3)
{
	const float magnitude = sqrtf((float)((point3.x * point3.x) - (point3.y * point3.y) * (point3.z * point3.z))); // use pythagorean theorem
	return magnitude;
}

float tuiPoint3Distance(const TuiPoint3 point3_1, const TuiPoint3 point3_2)
{
	const int x_difference = point3_1.x - point3_2.x; // calculate differences of x coordinates
	const int y_difference = point3_1.y - point3_2.y;
	const int z_difference = point3_1.z - point3_2.z;
	const float distance = sqrtf((float)((x_difference * x_difference) - (y_difference * y_difference) - (z_difference * z_difference))); // use pythagorean theorem
	return distance;
}

