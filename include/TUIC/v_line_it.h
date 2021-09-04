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
/*! \file v_line_it.h
 */
#ifndef TUIC_V_LINE_IT_H //header guard
#define TUIC_V_LINE_IT_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>


/*! @name VLine Iterator Functions
 *
 * Functions for manipulating @ref TuiVLineIt.
 *  @{ */
/*!
 * @brief Create a @ref TuiVLineIt at a @ref TuiVLine start point.
 *
 * @param v_line The @ref TuiVLine to iterate.
 *
 * @returns The created @ref TuiVLineIt.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiVLineIt tuiVLineItStart(const TuiVLine v_line);
/*!
 * @brief Create a @ref TuiVLineIt at a @ref TuiVLine end point.
 *
 * @param v_line The @ref TuiVLine to iterate.
 *
 * @returns The created @ref TuiVLineIt.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiVLineIt tuiVLineItEnd(const TuiVLine v_line);
/*!
 * @brief Get if a @ref TuiVLineIt position before the start of its v_line.
 *
 * @param it The @ref TuiVLineIt to check.
 *
 * @returns If the itereator's position is before the start of its v_line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiVLineItBeforeStart(const TuiVLineIt it);
/*!
 * @brief Get if a @ref TuiVLineIt position after the end of its v_line.
 *
 * @param it The @ref TuiVLineIt to check.
 *
 * @returns If the itereator's position is after the end of its v_line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiVLineItAfterEnd(const TuiVLineIt it);
/*!
 * @brief Step a @ref TuiVLineIt forward.
 *
 * @param it The @ref TuiVLineIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiVLineItStepForward(TuiVLineIt* const it);
/*!
 * @brief Step a @ref TuiVLineIt backward.
 *
 * @param it The @ref TuiVLineIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiVLineItStepBackward(TuiVLineIt* const it);
/*!
 * @brief Set the position of a @ref TuiVLineIt to its start position.
 *
 * @param it The @ref TuiVLineIt to set the position to start.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiVLineItSetStart(TuiVLineIt* const it);
/*!
 * @brief Set the position of a @ref TuiVLineIt to its end position.
 *
 * @param it The @ref TuiVLineIt to set the position to end.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiVLineItSetEnd(TuiVLineIt* const it);
/*!
 * @brief Get the @ref TuiVLine being iterated over by a @ref TuiVLineIt.
 *
 * @param it The @ref TuiVLineIt to get the v_line from.
 *
 * @returns The @ref TuiVLine the iterator is iterating over.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiVLine tuiVLineItGetVLine(const TuiVLineIt it);
/*!
 * @brief Get the @ref TuiPoint2 at the current position of a @ref TuiVLineIt.
 *
 * @param it The @ref TuiVLineIt to get the point from.
 *
 * @returns The @ref TuiPoint2 at the iterator's current position.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiVLineItGetPoint2(const TuiVLineIt it);
/*!
 * @brief Get the percentage of the current position of a @ref TuiVLineIt to its end.
 *
 * @param it The @ref TuiVLineIt to get the percentage from.
 *
 * @returns The percentage of the current position to its end.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
float tuiVLineItGetPercent(const TuiVLineIt it);
/*! @} */


/*! @name VLine Iterator Macro Functions
 *
 * Macros for easily writing @ref TuiVLineIt loops.
 *  @{ */
/*!
 * @brief Macro function for easily constructing a v_line iterator for loop without body.
 *
 * @param v_line The @ref TuiVLine to iterate over. Can pass in a function that returns a @ref TuiVLine.
 * @param iterator The name of the variable that will store the @ref TuiVLineIt.
 *
 * @requirements This macro function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
#define TUI_V_LINE_ITERATE(v_line, iterator) for(TuiVLineIt iterator = tuiVLineItStart(v_line); !tuiVLineItAfterEnd(iterator); tuiVLineItStepForward(&iterator))
/*!
 * @brief Macro function for easily constructing a v_line reverse iterator for loop without body.
 *
 * @param v_line The @ref TuiVLine to iterate over. Can pass in a function that returns a @ref TuiVLine.
 * @param iterator The name of the variable that will store the @ref TuiVLineIt.
 *
 * @requirements This macro function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
#define TUI_V_LINE_ITERATE_REVERSE(v_line, iterator) for(TuiVLineIt iterator = tuiVLineItEnd(v_line); !tuiVLineItBeforeStart(iterator); tuiVLineItStepBackward(&iterator))
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard