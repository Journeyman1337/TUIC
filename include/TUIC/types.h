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
/*! \file types.h
* This file contains the type definitions of all opaque objects. <a href="annotated.html">The objects are listed on this page.</a> 
 */
#ifndef TUIC_TYPES_H // header guard
#define TUIC_TYPES_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif


#include <stdint.h> //needed for integer types
#include <stddef.h> //needed for size_t


/*!
 * \brief Value for when a pointer is not allocated.
 */
#define TUI_NULL 0


/*! @name Opaque Object Types
 * These types are obfuscated from users on purpose to prevent accidental undefined behaviour. To manipulate these objects and access their properties, use TUIC functions instead.
 *  @{ */
/*!
 * \brief A desktop window.
 */
typedef struct TuiWindow_s* TuiWindow;
/*!
 * \brief A GPU color palette.
 */
typedef struct TuiPalette_s* TuiPalette;
/*!
 * \brief A GPU texture atlas.
 */
typedef struct TuiAtlas_s* TuiAtlas;
/*!
 * \brief A GPU texture.
 */
typedef struct TuiTexture_s* TuiTexture;
/*!
 * \brief A container for batch rendering data.
 */
typedef struct TuiBatch_s* TuiBatch;
/*!
 * \brief A GPU framebuffer.
 */
typedef struct TuiPanel_s* TuiPanel;
/*!
 * \brief A CPU image.
 */
typedef struct TuiImage_s* TuiImage;
/*!
 * \brief A desktop mouse cursor.
 */
typedef struct GLFWcursor* TuiCursor;
/*!
 * \brief A device monitor.
 */
typedef struct GLFWmonitor* TuiMonitor;
/*! @} */


/*! @name Grid Shape Struct Types
 * These structs represent shapes made of tiles on a roguelike grid.
 *  @{ */
/*!
 * \brief A 2D tile coordinate position.
 */
typedef struct TuiPoint2
{
	/*!
	 * \brief The x coordinate of the point.
	 */
	int x;
	/*!
	 * \brief The y coordinate of the point.
	 */
	int y;
} TuiPoint2;
/*!
 * \brief A 3D tile coordinate position.
 */
typedef struct TuiPoint3
{
	/*!
	 * \brief The x coordinate of the point.
	 */
	int x;
	/*!
	 * \brief The y coordinate of the point.
	 */
	int y;
	/*!
	 * \brief The z coordinate of the point.
	 */
	int z;
} TuiPoint3;
/*!
 * \brief A 2D tile line segment with a start and an end.
 */
typedef struct TuiLine
{
	/*!
	 * \brief The x coordinate of the line start point.
	 */
	int start_x;
	/*!
	 * \brief The y coordinate of the line start point.
	 */
	int start_y;
	/*!
	 * \brief The x coordinate of the line end point.
	 */
	int end_x;
	/*!
	 * \brief The y coordinate of the line end point.
	 */
	int end_y;
} TuiLine;
/*!
 * \brief An iterator that goes over every point in a @ref TuiLine.
 */
typedef struct TuiLineIt
{
	/*!
	 * \brief The x coordinate of the line start point.
	 */
	const int start_x;
	/*!
	 * \brief The y coordinate of the line start point.
	 */
	const int start_y;
	/*!
	 * \brief The x coordinate of the line end point.
	 */
	const int end_x;
	/*!
	 * \brief The y coordinate of the line end point.
	 */
	const int end_y;
	/*!
	 * \brief The diagonal length of the line.
	 */
	const int diagonal_length;
	/*!
	 * \brief The Bresenham index of the line iterator algorithm.
	 */
	int position;
} TuiLineIt;
/*! @} */
#ifdef __cplusplus // extern C guard
}
#endif
#endif // header guard