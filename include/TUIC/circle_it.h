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
/*! \file circle_it.h
 */
#ifndef TUIC_CIRCLE_IT_H //header guard
#define TUIC_CIRCLE_IT_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/grid_shape_types.h>
#include <TUIC/boolean.h>


/*! @name Circle Iterator Functions
 *
 * Functions for manipulating @ref TuiCircleIt.
 *  @{ */
/*!
* @brief Create a @ref TuiCircleIt to iterator over the points within a @ref TuiCircle.
*
* @param circle The @ref TuiCircle to iterate.
*
* @returns The created @ref TuiCircleIt.
*
* @errors This function can have no errors.
*
* @requirements This function can be called freely, even if TUIC is not currently initialized.
*
* @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
*/
TuiCircleIt tuiCircleIt(const TuiCircle circle);
/*!
 * @brief Get if a @ref TuiCircleIt position is out of its @ref TuiCircle.
 *
 * @param it The @ref TuiCircleIt to check.
 *
 * @returns If the itereator's position is out of the circle.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCircleItDone(const TuiCircleIt it);
/*!
 * @brief Step a @ref TuiCircleIt forward.
 *
 * @param it The @ref TuiCircleIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiCircleItStepForward(TuiCircleIt* const it);
/*!
 * @brief Set the position of a @ref TuiCircleIt to its start position.
 *
 * @param it The @ref TuiCircleIt to set the position to start.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiCircleItSetStart(TuiCircleIt* const it);
/*!
 * @brief Get the @ref TuiCircle being iterated over by a @ref TuiCircleIt.
 *
 * @param it The @ref TuiCircleIt to get the circle from.
 *
 * @returns The @ref TuiCircle the iterator is iterating over.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCircle tuiCircleItGetCircle(const TuiCircleIt it);
/*!
 * @brief Get the @ref TuiPoint2 at the current position of a @ref TuiCircleIt.
 *
 * @param it The @ref TuiCircleIt to get the point from.
 *
 * @returns The @ref TuiPoint2 at the iterator's current position.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiCircleItGetPoint2(const TuiCircleIt it);
/*! @} */


/*! @name Circle Iterator Macro Functions
 *
 * Macros for easily writing @ref TuiCircleIt loops.
 *  @{ */
/*!
 * @brief Macro function for easily constructing a circle iterator for loop without body.
 *
 * @param circle The @ref TuiCircle to iterate over. Can pass in a function that returns a @ref TuiCircle.
 * @param iterator The name of the variable that will store the @ref TuiCircleIt.
 *
 * @requirements This macro function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
#define TUI_CIRCLE_ITERATE(circle, iterator) for(TuiCircleIt iterator = tuiCircleIt(circle); !tuiCircleItDone(iterator); tuiCircleItStepForward(&iterator))
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard--