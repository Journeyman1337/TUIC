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
/*! \file point3.h
 */
#ifndef TUIC_POINT3_H //header guard
#define TUIC_POINT3_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>


/*! @name 3D Point Functions
 *
 * Functions for manipulating @ref TuiPoint3.
 *  @{ */
/*!
 * @brief Create a @ref TuiPoint3.
 *
 * @param x The x position of the point.
 * @param y The y position of the point.
 * @param z The z position of the point.
 *
 * @returns The created @ref Point3.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint3 tuiPoint3(const int x, const int y, const int z);
/*!
 * @brief Get the magnitude of a @ref TuiPoint3.
 *
 * @param point3 A pointer to the point. This must not be @ref TUI_NULL.
 *
 * @returns The magnitude (distance to origin).
 *
 * @errors This function can have no error codes.
 * 
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
float tuiPoint3GetMagnitude(const TuiPoint3 point3);
/*!
 * @brief Get the distance between two @ref TuiPoint3.
 *
 * @param point3_1 The first point.
 * @param point3_2 The second point.
 *
 * @returns The distance between the points.
 *
 * @errors This function can have no error codes.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
float tuiPoint3Distance(const TuiPoint3 point3_1, const TuiPoint3 point3_2);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard