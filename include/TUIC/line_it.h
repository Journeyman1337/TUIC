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
/*! \file line_it.h
 */
#ifndef TUIC_LINE_IT_H //header guard
#define TUIC_LINE_IT_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>


/*! @name Line Iterator Functions
 *
 * Functions for manipulating @ref TuiLineIt.
 *  @{ */
/*!
 * @brief Create a @ref TuiLineIt at a @ref TuiLine start point.
 *
 * @param line The @ref TuiLine to iterate.
 *
 * @returns The created @ref TuiLineIt.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLineIt tuiLineItStart(const TuiLine line);
/*!
 * @brief Create a @ref TuiLineIt at a @ref TuiLine end point.
 *
 * @param line The @ref TuiLine to iterate.
 *
 * @returns The created @ref TuiLineIt.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLineIt tuiLineItEnd(const TuiLine line);
/*!
 * @brief Get if a @ref TuiLineIt position before the start of its line.
 *
 * @param it The @ref TuiLineIt to check.
 *
 * @returns If the itereator's position is before the start of its line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiLineItBeforeStart(const TuiLineIt it);
/*!
 * @brief Get if a @ref TuiLineIt position after the end of its line.
 *
 * @param it The @ref TuiLineIt to check.
 *
 * @returns If the itereator's position is after the end of its line.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiLineItAfterEnd(const TuiLineIt it);
/*!
 * @brief Step a @ref TuiLineIt forward.
 *
 * @param it The @ref TuiLineIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiLineItStepForward(TuiLineIt* const it);
/*!
 * @brief Step a @ref TuiLineIt backward.
 *
 * @param it The @ref TuiLineIt to step.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiLineItStepBackward(TuiLineIt* const it);
/*!
 * @brief Set the position of a @ref TuiLineIt to its start position.
 *
 * @param it The @ref TuiLineIt to set the position to start.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiLineItSetStart(TuiLineIt* const it);
/*!
 * @brief Set the position of a @ref TuiLineIt to its end position.
 *
 * @param it The @ref TuiLineIt to set the position to end.
 *
 * @errors This function can have the error @ref TUI_ERROR_NULL_GRID_SHAPE_ITERATOR and immediatly return.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
void tuiLineItSetEnd(TuiLineIt* const it);
/*!
 * @brief Get the @ref TuiLine being iterated over by a @ref TuiLineIt.
 *
 * @param it The @ref TuiLineIt to get the line from.
 *
 * @returns The @ref TuiLine the iterator is iterating over.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiLine tuiLineItGetLine(const TuiLineIt it);
/*!
 * @brief Get the @ref TuiPoint2 at the current position of a @ref TuiLineIt.
 *
 * @param it The @ref TuiLineIt to get the point from.
 * 
 * @returns The @ref TuiPoint2 at the iterator's current position.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiPoint2 tuiLineItGetPoint2(const TuiLineIt it);
/*!
 * @brief Get the percentage of the current position of a @ref TuiLineIt to its end.
 *
 * @param it The @ref TuiLineIt to get the percentage from.
 *
 * @returns The percentage of the current position to its end.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
float tuiLineItGetPercent(const TuiLineIt it);
/*! @} */


/*! @name Line Iterator Macro Functions
 *
 * Macros for easily writing @ref TuiLineIt loops.
 *  @{ */
/*!
 * @brief Macro function for easily constructing a line iterator for loop without body.
 * 
 * @param line The @ref TuiLine to iterate over. Can pass in a function that returns a @ref TuiLine.
 * @param iterator The name of the variable that will store the @ref TuiLineIt.
 * 
 * @requirements This macro function can be called freely, even if TUIC is not currently initialized.
 * 
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
#define TUI_LINE_ITERATE(line, iterator) for(TuiLineIt iterator = tuiLineItStart(line); !tuiLineItAfterEnd(iterator); tuiLineItStepForward(&iterator))
/*!
 * @brief Macro function for easily constructing a line reverse iterator for loop without body.
 * 
 * @param line The @ref TuiLine to iterate over. Can pass in a function that returns a @ref TuiLine.
 * @param iterator The name of the variable that will store the @ref TuiLineIt.
 * 
 * @requirements This macro function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
#define TUI_LINE_ITERATE_REVERSE(line, iterator) for(TuiLineIt iterator = tuiLineItEnd(line); !tuiLineItBeforeStart(iterator); tuiLineItStepBackward(&iterator))
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard