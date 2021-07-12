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
/*! \file objects.h
 */
#ifndef TUIC_OPAQUE_OBJECTS_H // header guard
#define TUIC_OPAQUE_OBJECTS_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <stdint.h>
#include <TUIC/types.h>
#include <GLFW/glfw3.h>
#include <TUIC/blend_mode.h>
#include <TUIC/filter_mode.h>
#include <TUIC/desktop_callback.h>

/*! @} */
/*! @name Opaque Object Full Declarations
 * These structs are represent the hidden types behind TUIC opaque objects.
 *  @{ */

typedef struct TuiWindow_s
{
	void* UserPointer;

	tuiWindowMoveFunction WindowMoveCallback;

	tuiWindowCloseFunction WindowCloseCallback;

	tuiWindowRefreshFunction WindowRefreshCallback;

	tuiWindowFocusFunction WindowFocusCallback;

	tuiWindowIconifyFunction WindowIconifyCallback;

	tuiWindowMaximizeFunction WindowMaximizeCallback;

	tuiWindowResizeFunction WindowResizeCallback;

	tuiWindowContentScaleFunction WindowContentScaleCallback;

	tuiMouseButtonFunction MouseButtonCallback;

	tuiCursorMoveFunction CursorMoveCallback;

	tuiCursorEnterFunction CursorEnterCallback;

	tuiMouseScrollFunction MouseScrollCallback;

	tuiKeyboardKeyFunction KeyboardKeyCallback;

	tuiCharFunction CharCallback;

	tuiFileDropFunction FileDropCallback;

	GLFWwindow* GlfwWindow;
	/*!
	 * @brief The amount of @ref TuiPanel objects that currently exist attached to this @ref TuiWindow.
	 */
	size_t PanelCount;
	/*!
	 * @brief The amount of @ref TuiAtlas objects that currently exist attached to this @ref TuiWindow.
	 */
	size_t AtlasCount;
	/*!
	 * @brief The amount of @ref TuiTexture objects that currently exist attached to this @ref TuiWindow.
	 */
	size_t TextureCount;
	/*!
	 * @brief The amount of @ref TuiPalette objects that currently exist attached to this @ref TuiWindow.
	 */
	size_t PaletteCount;
	/*!
	 * @brief The pixel width of the screen of the TuiWindow.
	 */
	size_t PixelWidth;
	/*!
	 * @brief The pixel height of the screen of the TuiWindow.
	 */
	size_t PixelHeight;
	/*!
	 * @brief A pointer to backend specific API data.
	 */
	void* ApiData;
} TuiWindow_s;
/*
 * @brief The struct behind @ref TuiAtlas opaque objects.
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiAtlas_s
{
	TuiWindow Window;
	/*!
	 * @brief The @ref TuiBlendMode.
	 */
	TuiBlendMode BlendMode;
	/*!
	 * @brief The atlas type that this @ref TuiAtlas uses.
	 */
	size_t AtlasType;
	/*!
	 * @brief The amount of channels in the texture of this @ref TuiAtlas.
	 */
	size_t ChannelCount;
	/*!
	 * @brief The width of the texture in pixels.
	 */
	size_t PixelWidth;
	/*!
	 * @brief The height of the texture in pixels.
	 */
	size_t PixelHeight;
	/*!
	 * @brief The width of a single tile in pixels when rendered to a panel.
	 */
	size_t TileWidth;
	/*!
	 * @brief The height of a single tile in pixels when rendered to a panel.
	 */
	size_t TileHeight;
	/*!
	 * @brief The size of the image pixel data array.
	 */
	size_t PixelDataSize;
	/*!
	 * @brief The amount of glyphs in this atlas.
	 */
	size_t GlyphCount;
	/*!
	 * @brief The amount of glyphs wide, used if this @ref TuiAtlas uses atlas type @ref TUI_ATLAS_GRID.
	 */
	size_t GridGlyphsWide;
	/*!
	 * @brief The amount of glyphs tall, used if this @ref TuiAtlas uses atlas type @ref TUI_ATLAS_GRID.
	 */
	size_t GridGlyphsTall;
	/*!
	 * @brief A pointer to backend specific API data.
	 */
	void* ApiData;
} TuiAtlas_s;
/*
 * @brief The struct behind @ref TuiTexture opaque objects.
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiTexture_s
{
	/*!
	 * @brief The @ref TuiWindow that this object is attached to.
	 */
	TuiWindow Window;
	/*!
	 * @brief The @ref TuiFilterMode.
	 */
	TuiFilterMode FilterMode;
	/*!
	 * @brief The width of the texture in pixels.
	 */
	size_t PixelWidth;
	/*!
	 * @brief The height of the texture in pixels.
	 */
	size_t PixelHeight;
	/*!
	 * @brief The amount of channels in the texture of this @ref TuiTexture.
	 */
	size_t ChannelCount;
	/*!
	 * @brief A pointer to backend specific API data.
	 */
	void* ApiData;
} TuiTexture_s;
/*
 * @brief The struct behind @ref TuiPalette opaque objects.
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiPalette_s
{
	/*!
	 * @brief The @ref TuiWindow that this object is attached to.
	 */
	TuiWindow Window;
	/*!
	 * @brief The channels per color in this @ref TuiPalette.
	 */
	int ChannelCount;
	/*!
	 * @brief The amount of colors in this @ref TuiPalette.
	 */
	size_t ColorCount;	
	/*!
	 * @brief A pointer to backend specific API data.
	 */
	void* ApiData;
} TuiPalette_s;
/*
 * @brief The struct behind @ref TuiPanel opaque objects.
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiPanel_s
{
	/*!
	 * @brief The @ref TuiWindow that this object is attached to.
	 */
	TuiWindow Window;
	/*!
	 * @brief The width of the framebuffer in pixels.
	 */
	size_t FramebufferWidth;
	/*!
	 * @brief The height of the framebuffer in pixels.
	 */
	size_t FramebufferHeight;
	/*!
	 * @brief A pointer to backend specific API data.
	 */
	void* ApiData;
} TuiPanel_s;
/*
 * @brief The struct behind @ref TuiBatch opaque objects.
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiBatch_s
{
	/*!
	 * @brief The detail mode that this @ref TuiBatch uses.
	 */
	size_t DetailMode;
	/*!
	 * @brief A pointer to the data array of this @ref TuiBatch.
	 */
	uint8_t* Data;
	/*!
	 * @brief The amount of space in the data array of this @ref TuiBatch that is designated for tiles (BytesPerTile * TilesWide * TilesTall).
	 */
	size_t UsedDataSize;
	/*!
	 * @brief The total amount of allocated space for thie @ref TuiBatch including reserved space not needed for the current batch dimensions.
	 */
	size_t ReservedDataSize;
	/*!
	 * @brief The total bytes per tile.
	 */
	size_t BytesPerTile;
	/*!
	 * @brief The total amount of tiles in this @ref TuiBatch.
	 */
	size_t TileCount;
	/*!
	 * @brief The width of this @ref TuiBatch in tiles.
	 */
	size_t TilesWide;
	/*!
	 * @brief The height of this @ref TuiBatch in tiles.
	 */
	size_t TilesTall;
	/*!
	 * @brief If this is a @ref TuiBatch that uses @ref TUI_LAYOUT_FLAG_SPARSE and requires two bytes for the tile x position instead of one.
	 */
	TuiBoolean IsLargeSparseWide;
	/*!
	 * @brief If this is a @ref TuiBatch that uses @ref TUI_LAYOUT_FLAG_SPARSE and requires two bytes for the tile y position instead of one.
	 */
	TuiBoolean IsLargeSparseTall;
	/*!
	 * @brief A pointer to the used indices 2d array used to prevent sparse batches from rendering to the same tile position twice.
	 */
	uint16_t* SparseUsedIndices;
	/*!
	 * @brief The size of the SparseUsedIndices array.
	 */
	size_t SparseUsedIndicesSize;
} TuiBatch_s;
/*
 * @brief The struct behind @ref TuiImage opaque objects.
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiImage_s
{
	/*!
	 * @brief The amount of channels in this @ref TuiImage.
	 */
	size_t ChannelCount;
	/*!
	 * @brief The width of this @ref TuiImage in pixels
	 */
	size_t PixelWidth;
	/*!
	 * @brief The height of this @ref TuiImage in pixels.
	 */
	size_t PixelHeight;
	/*!
	 * @brief The size of thepixel data of this @ref TuiImage in bytes.
	 */
	size_t PixelDataSize;
	/*!
	 * @brief The pixel data array.
	 */
	uint8_t* PixelData;
} TuiImage_s;
/*! @} */
#ifdef __cplusplus // extern C guard
}
#endif
#endif // header guard