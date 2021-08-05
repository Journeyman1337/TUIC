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
#include <stddef.h>

#include <stdint.h> //needed for integer types


/*! @name Opaque Object Types
 * These structs are defined in the header file \"tuic/backends/objects.h\", but you are not meant to access their properties directly except when implementing a backend to avoid undefined behaviour. Instead, you are meant to only manipulate these objects by passing these opaque types into functions included in the library.
 *  @{ */

typedef struct TuiWindow_s* TuiWindow;

typedef struct TuiPalette_s* TuiPalette;

typedef struct TuiAtlas_s* TuiAtlas;

typedef struct TuiTexture_s* TuiTexture;

typedef struct TuiBatch_s* TuiBatch;

typedef struct TuiPanel_s* TuiPanel;

typedef struct TuiImage_s* TuiImage;

typedef struct GLFWcursor* TuiCursor;

typedef struct GLFWmonitor* TuiMonitor;

/*! @} */
#ifdef __cplusplus // extern C guard
}
#endif
#endif // header guard