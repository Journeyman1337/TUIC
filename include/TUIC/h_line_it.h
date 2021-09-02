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
/*! \file h_line_it.h
 */
#ifndef TUIC_H_LINE_IT_H //header guard
#define TUIC_H_LINE_IT_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>


/*! @name HLine Iterator Functions
 *
 * Functions for manipulating @ref TuiHLineIt.
 *  @{ */
 /*!
  * @brief Create a @ref TuiHLineIt at a @ref TuiHLine start point.
  *
  * @param h_line The @ref TuiHLine to iterate.
  *
  * @returns The created @ref TuiHLineIt.
  *
  * @errors This function can have no errors.
  *
  * @requirements This function can be called freely, even if TUIC is not currently initialized.
  *
  * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
  */
TuiHLineIt tuiHLineItStart(const TuiHLine h_line);
/*!
 * @brief Create a @ref TuiHLineIt at a @ref TuiHLine end point.
 *
 * @param h_line The @ref TuiHLine to iterate.
 *
 * @returns The created @ref TuiHLineIt.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiHLineIt tuiHLineItEnd(const TuiHLine h_line);
/*!
 * @brief Get if a @ref TuiHLineIt position before the start of its h_line.
 *
 * @param it The @ref TuiHLineIt to check.
 *
 * @returns If the itereator's position is before the start of its h_line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiHLineItBeforeStart(const TuiHLineIt it);
/*!
 * @brief Get if a @ref TuiHLineIt position after the end of its h_line.
 *
 * @param it The @ref TuiHLineIt to check.
 *
 * @returns If the itereator's position is after the end of its h_line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiHLineItAfterEnd(const TuiHLineIt it);
/*!
 * @brief Step a @ref TuiHLineIt forward.
 *
 * @param it The @ref TuiHLineIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiHLineItStepForward(TuiHLineIt* const it);
/*!
 * @brief Step a @ref TuiHLineIt backward.
 *
 * @param it The @ref TuiHLineIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiHLineItStepBackward(TuiHLineIt* const it);
/*!
 * @brief Set the position of a @ref TuiHLineIt to its start position.
 *
 * @param it The @ref TuiHLineIt to set the position to start.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiHLineItSetStart(TuiHLineIt* const it);
/*!
 * @brief Set the position of a @ref TuiHLineIt to its end position.
 *
 * @param it The @ref TuiHLineIt to set the position to end.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiHLineItSetEnd(TuiHLineIt* const it);
/*!
 * @brief Get the @ref TuiHLine being iterated over by a @ref TuiHLineIt.
 *
 * @param it The @ref TuiHLineIt to get the h_line from.
 *
 * @returns The @ref TuiHLine the iterator is iterating over.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiHLine tuiHLineItGetHLine(const TuiHLineIt it);
/*!
 * @brief Get the @ref TuiPoint2 at the current position of a @ref TuiHLineIt.
 *
 * @param it The @ref TuiHLineIt to get the point from.
 *
 * @returns The @ref TuiPoint2 at the iterator's current position.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiHLineItGetPoint2(const TuiHLineIt it);
/*!
 * @brief Get the percentage of the current position of a @ref TuiHLineIt to its end.
 *
 * @param it The @ref TuiHLineIt to get the percentage from.
 *
 * @returns The percentage of the current position to its end.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
float tuiHLineItGetPercent(const TuiHLineIt it);
/*! @} */


/*! @name HLine Iterator Macro Functions
 *
 * Macros for easily writing @ref TuiHLineIt loops.
 *  @{ */
/*!
 * @brief Macro function for easily constructing a h_line iterator for loop without body.
 *
 * @param h_line The @ref TuiHLine to iterate over. Can pass in a function that returns a @ref TuiHLine.
 * @param iterator The name of the variable that will store the @ref TuiHLineIt.
 *
 * @requirements This macro function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
#define TUI_LINE_ITERATE(h_line, iterator) for(TuiHLineIt iterator = tuiHLineItStart(h_line); !tuiHLineItAfterEnd(iterator); tuiHLineItStepForward(&iterator))
/*!
 * @brief Macro function for easily constructing a h_line reverse iterator for loop without body.
 *
 * @param h_line The @ref TuiHLine to iterate over. Can pass in a function that returns a @ref TuiHLine.
 * @param iterator The name of the variable that will store the @ref TuiHLineIt.
 *
 * @requirements This macro function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
#define TUI_LINE_ITERATE_REVERSE(h_line, iterator) for(TuiHLineIt iterator = tuiHLineItEnd(h_line); !tuiHLineItBeforeStart(iterator); tuiHLineItStepBackward(&iterator))
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard