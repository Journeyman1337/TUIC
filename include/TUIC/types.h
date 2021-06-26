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
#include <stdint.h>
/*! @name Opaque Object Types
 * These structs are defined in the header file \"tuic/backends/objects.h\", but you are not meant to access their properties directly except when implementing a backend to avoid undefined behaviour. Instead, you are meant to only manipulate these objects by passing these opaque types into functions included in the library.
 *  @{ */
/*!
 * @brief TUI rendering context. TuiPalette, @ref TuiGlyphAtlas, and @ref TuiPanel objects are all attached to a TuiInstance. You must create the TuiInstance before these other objects, and destroy it last. These objects should only be used on a single thread. TuiInstance create functions are always backend specific. This object is opaque, and its members are not meant to be accessed directly unless implementing a backend. Use functions functions from instance.h or opengl33.h instead.
 */
typedef struct TuiInstance_s* TuiInstance;
/*!
 * @brief A TUI palette that can have up to 256 colors with RGB componenets. These objects should only be used on the same thread as its @ref TuiInstance. This object is opaque, and its members are not meant to be accessed directly unless implementing a backend. Use the functions in palette.h instead
 */
typedef struct TuiPalette_s* TuiPalette;
/*!
 * @brief TUI glyph image atlas. This object contains a image for rendering glyphs as well as definitions of where glyphs are in the image. These objects should only be used on the same thread as its @ref TuiInstance. This object is opaque, and its members are not meant to be accessed directly unless implementing a backend. Use the functions in glyph_atlas.h instead.
 */
typedef struct TuiGlyphAtlas_s* TuiGlyphAtlas;

typedef struct TuiTexture_s* TuiTexture;
/*!
 * @brief TUI rendering data container, which contains data about tiles to draw. TuiBatch objects are passable between multiple threads and are independent of @ref TuiInstance objects. This object is opaque, and its members are not meant to be accessed directly. Use the functions in batch.h instead.
 */
typedef struct TuiBatch_s* TuiBatch;
/*!
 * @brief TUI rendering panel. This is a framebuffer for rendering @ref TuiBatch objects and other @ref TuiPanel objects to. These objects should only be used on the same thread as its @ref TuiInstance. This object is opaque, and its members are not meant to be accessed directly unless implementing a backend. Use the functions in panel.h instead.
 */
typedef struct TuiPanel_s* TuiPanel;
/*!
 * @brief Image loaded from a file or generated through code. This object contains an image texture, which can be loaded into a @ref TuiGlyphAtlas. TuiImage objects are passable between multiple threads and are independent of @ref TuiInstance objects. This object is opaque, and its members are not meant to be accessed directly. Use the functions in image.h instead.
 */
typedef struct TuiImage_s* TuiImage;
/*! @} */
#ifdef __cplusplus // extern C guard
}
#endif
#endif // header guard