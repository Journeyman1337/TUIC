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
/*! \file rect_it.h
 */
#ifndef TUIC_RECT_IT_H //header guard
#define TUIC_RECT_IT_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>


/*! @name Rect Iterator Functions
 *
 * Functions for manipulating @ref TuiRectIt.
 *  @{ */
 /*!
  * @brief Create a @ref TuiRectIt to iterator over the points within a @ref TuiRect.
  *
  * @param rect The @ref TuiRect to iterate.
  *
  * @returns The created @ref TuiLineIt.
  *
  * @errors This function can have no errors.
  *
  * @requirements This function can be called freely, even if TUIC is not currently initialized.
  *
  * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
  */
TuiRectIt tuiRectIt(const TuiRect rect);
/*!
 * @brief Get if a @ref TuiRectIt position is out of its @ref TuiRect.
 *
 * @param it The @ref TuiRectIt to check.
 *
 * @returns If the itereator's position is out of the rect.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiRectDone(const TuiRectIt it);
/*!
 * @brief Step a @ref TuiRectIt forward.
 *
 * @param it The @ref TuiRectIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiRectItStepForward(TuiRectIt* const it);
/*!
 * @brief Step a @ref TuiRectIt backward.
 *
 * @param it The @ref TuiRectIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiRectItStepBackward(TuiRectIt* const it);
/*!
 * @brief Set the position of a @ref TuiRectIt to its start position.
 *
 * @param it The @ref TuiRectIt to set the position to start.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiRectItSetStart(TuiRectIt* const it);
/*!
 * @brief Get the @ref TuiRect being iterated over by a @ref TuiRectIt.
 *
 * @param it The @ref TuiRectIt to get the line from.
 *
 * @returns The @ref TuiRect the iterator is iterating over.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiRect tuiRectItGetRect(const TuiRectIt it);
/*!
 * @brief Get the @ref TuiPoint2 at the current position of a @ref TuiRectIt.
 *
 * @param it The @ref TuiRectIt to get the point from.
 *
 * @returns The @ref TuiPoint2 at the iterator's current position.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiRectItGetPoint2(const TuiRectIt it);
/*! @} */


/*! @name Rect Iterator Macro Functions
 *
 * Macros for easily writing @ref TuiRectIt loops.
 *  @{ */
/*!
 * @brief Macro function for easily constructing a rect iterator for loop without body.
 *
 * @param rect The @ref TuiRect to iterate over. Can pass in a function that returns a @ref TuiRect.
 * @param iterator The name of the variable that will store the @ref TuiRectIt.
 *
 * @requirements This macro function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
#define TUI_RECT_ITERATE(rect, iterator) for(TuiLineIt iterator = tuiRectIt(rect); !tuiRectDone(iterator); tuiRectItStepForward(&iterator))
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard