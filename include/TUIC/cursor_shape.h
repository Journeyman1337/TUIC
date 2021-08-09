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
/*! \file cursor_shape.h
 */
 #ifndef TUIC_CURSOR_SHAPE_H //header guard
#define TUIC_CURSOR_SHAPE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*! @name Cursor shape
 s*  @{ */
/*!
 * @brie Default mouse cursor shapes.
 */
typedef enum TuiCursorShape
{
	/*!
	 * \brief The cursor shape is invalid.
	 *
	 * This cursor shape is returned when an error occurs, and is also used to specify that no cursor shape is
	 * defined.
	 */
	TUI_CURSOR_SHAPE_INVALID		  = 0,
	/*!
	 * \brief The default arrow cursor shape.
	 */
	TUI_CURSOR_SHAPE_ARROW          = 0x00036001,
	/*!
	 * \brief The cursor shape used for selecting or inserting text.
	 */
	TUI_CURSOR_SHAPE_IBEAM          = 0x00036002,
	/*!
	 * \brief A plus sign shaped cursor.
	 */
	TUI_CURSOR_SHAPE_CROSSHAIR      = 0x00036003,
	/*!
	 * \brief A pointing hand cursor, normally used when hovering over hyperlinks or buttons.
	 */
	TUI_CURSOR_SHAPE_POINTING_HAND  = 0x00036004,
	/*!
	 * \brief The east-west resize cursor.
	 */
	TUI_CURSOR_SHAPE_RESIZE_EW      = 0x00036005,
	/*!
	 * \brief The north-south resize cursor
	 */
	TUI_CURSOR_SHAPE_RESIZE_NS      = 0x00036006,
	/*!
	 * \brief THe northwest-southeast resize cursor.
	 */
	TUI_CURSOR_SHAPE_RESIZE_NWSE    = 0x00036007,
	/*!
	 * \brief The northeast-southwest resize cursor.
	*/
	TUI_CURSOR_SHAPE_RESIZE_NESW    = 0x00036008,
	/*!
	 * \brief The resize cursor for all directions.
	 */
	TUI_CURSOR_SHAPE_RESIZE_ALL     = 0x00036009,
	/*!
	 * \brief The cursor for not allowed actions.
	 */
	TUI_CURSOR_SHAPE_NOT_ALLOWED    = 0x0003600A,
	/*!
	 * \brief The east-west resize cursor.
	 */
	TUI_CURSOR_SHAPE_HRESIZE        = TUI_CURSOR_SHAPE_RESIZE_EW,
	/*!
	 * \brief The north-south resize cursor.
	 */
	TUI_CURSOR_SHAPE_VRESIZE        = TUI_CURSOR_SHAPE_RESIZE_NS,
	/*!
	 * \brief The first valid cursor shape.
	 */
	TUI_CURSOR_SHAPE_FIRST		    = TUI_CURSOR_SHAPE_ARROW,
	/*!
	 * \briefThe last valid cursor shape.
	 */
	TUI_CURSOR_SHAPE_LAST			= TUI_CURSOR_SHAPE_NOT_ALLOWED
}TuiCursorShape;
/*! @} */


/*! @name TuiCursorMode names
 *  @{ */
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_ARROW.
 */
extern const char* kTui_Cursor_Shape_Arrow_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_IBEAM.
 */
extern const char* kTui_Cursor_Shape_Ibeam_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_CROSSHAIR.
 */
extern const char* kTui_Cursor_Shape_Crosshair_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_POINTING_HAND.
 */
extern const char* kTui_Cursor_Shape_Pointing_Hand_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_RESIZE_EW and @ref TUI_CURSOR_SHAPE_HRESIZE.
 */
extern const char* kTui_Cursor_Shape_Resize_EW_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_RESIZE_NS and @ref TUI_CURSOR_SHAPE_VRESIZE.
 */
extern const char* kTui_Cursor_Shape_Resize_NS_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_RESIZE_NWSE.
 */
extern const char* kTui_Cursor_Shape_Resize_NWSE_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_RESIZE_NESW.
 */
extern const char* kTui_Cursor_Shape_Resize_NESW_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_RESIZE_ALL.
 */
extern const char* kTui_Cursor_Shape_Resize_All_Name;
/*!
 * @brief String name of @ref TUI_CURSOR_SHAPE_NOT_ALLOWED.
 */
extern const char* kTui_Cursor_Shape_Not_Allowed_Name;
/*! @} */


/*! @name TuiCursorShape functions
 *
 * Functions for dealing with @ref TuiCursorShape enum values.
 *  @{ */
/*!
 * @brief Determine if a @ref TuiCursorShape enum is valid.
 *
 * @param cursor_shape The @ref TuiCursorShape to check.
 *
 * @returns The @ref TuiBoolean result. If cursor_shape is a valid @ref TuiCursorShape, it
 * returns @ref TuiTrue. Otherwise, it returns @ref TuiFalse.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCursorShapeIsValid(TuiCursorShape cursor_shape);
/*!
 * @brief Retrieve the string name associated with a @ref TuiCursorShape enum.
 *
 * @param cursor_shape The @ref TuiCursorShape to get the name of.
 *
 * @returns The string name. NULL is returned if cursor_shape is an invalid @ref TuiCursorShape.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiCursorShapeToString(TuiCursorShape cursor_shape);
/*!
 * @brief Determine the #ref TuiCursorShape enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The TuiCursorMode. @ref TUI_CURSOR_SHAPE_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiCursorShape tuiStringToCursorShape(const char* str);
/*!
 * @brief Determine if a @ref TuiCursorShape is supported by the current platform.
 *
 * @param cursor_shape The @ref TuiCursorShape to check.
 *
 * @returns The @ref TuiBoolean result. If it cursor_shape is a @ref TuiCursorShape supported on the current platform, it
 * returns @ref TuiTrue. Otherwise, it returns @ref TuiFalse.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function must be called only while TUIC is initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiCursorShapeSupported(TuiCursorShape cursor_shape);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard