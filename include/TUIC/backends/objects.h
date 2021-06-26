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
/*! \file macros.h
 */
#ifndef TUIC_OPAQUE_OBJECTS_H // header guard
#define TUIC_OPAQUE_OBJECTS_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <stdint.h>
#include <TUIC/types.h>
/*! @name Backend Interface Callback Types
 * These callback types reperesent every command that can possibly be sent to a backend, and are used as the abstraction layer between backends and TUIC.
 *  @{ */
/*!
 * @brief Callback type used for destroying the API data of a @ref TuiInstance.
 * 
 * @param instance The @ref TuiInstance.
 */
typedef void(*tuiInstanceDestroyCallback) (TuiInstance instance);
/*!
 * @brief Callback type used for clearing all pixels of the graphics context of a @ref TuiInstance with a color.
 * 
 * @param instance The @ref TuiInstance.
 * @param r The value of the clear color's red channel.
 * @param g The value of the clear color's green channel.
 * @param b The value of the clear color's blue channel.
 * @param a The value of the clear color's alpha channel.
 */
typedef void(*tuiInstanceClearColorCallback) (TuiInstance instance, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
/*!
 * @brief Callback type for resizing the main screen of a @ref TuiInstance.
 *
 * @param instance The @ref TuiInstance.
 * @param screen_width The new width of the main screen in pixels.
 * @param screen_height The new height of the main screen in pixels.
 * @returns The @ref TuiInstance.
 */
typedef void(*tuiInstanceResizeScreenCallback)(TuiInstance instance, size_t screen_width, size_t screen_height);
/*!
 * @brief Callback type for drawing batch data the main screen of a @ref TuiInstance.
 *
 * @param instance The @ref TuiInstance.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw.
 * @param detail_mode The @ref TuiDetailMode of the batch data.
 * @param tiles_wide The width of the batch data in tiles.
 * @param tiles_tall The height of the batch data in tiles.
 * @param sparse_index The amount of tiles to render if this batch data uses a detail mode with @ref TUI_LAYOUT_FLAG_SPARSE.
 * @param batch_data A pointer to the raw batch tile data array.
 * @param left_x The leftmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param right_x The rightmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param top_y The topmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param bottom_y The bottommost pixel to draw the batch data in the screen of the @ref TuiInstance.
 */
typedef void(*tuiInstanceDrawBatchDataCallback) (TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, size_t detail_mode, size_t tiles_wide, size_t tiles_tall, size_t sparse_index, const uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Callback type used for creating the API data of a @ref TuiGlyphAtlas.
 * 
 * @param atlas The @ref TuiGlyphAtlas.
 * @param pixel_data The raw pixels of the @ref TuiImage.
 * @param glyph_bounding_boxes The raw bounding box array if this atlas uses type @ref TUI_ATLAS_COORDS.
 */
typedef void(*tuiGlyphAtlasCreateCallback) (TuiGlyphAtlas atlas, const uint8_t* pixel_data, const float* raw_glyph_uvs);
/*!
 * @brief Callback type used for destroying the API data of a @ref TuiGlyphAtlas.
 * 
 * @param atlas The @ref TuiGlyphAtlas.
 */
typedef void(*tuiGlyphAtlasDestroyCallback) (TuiGlyphAtlas atlas);
/*!
 * @brief Callback type used for creating the API data of a @ref TuiPalette.
 * 
 * @param palette The @ref TuiPalette.
 * @param pixel_data The raw palette colors.
 */
typedef void(*tuiPaletteCreateCallback) (TuiPalette palette, const uint8_t* color_data);
/*!
 * @brief Callback type used for destroying the API data of a @ref TuiPalette.
 * 
 * @param palette The @ref TuiPalette.
 * @param color_data The color array.
 */
typedef void(*tuiPaletteDestroyCallback) (TuiPalette palette);
/*!
 * @brief Callback type used for creating the API data of a @ref TuiPanel.
 * 
 * @param panel The @ref TuiPanel. 
 */
typedef void(*tuiPanelCreateCallback) (TuiPanel panel);
/*!
 * @brief Callback type used for destroying the API data of a @ref TuiPanel.
 * 
 * @param panel The @ref TuiPanel.
 */
typedef void(*tuiPanelDestroyCallback) (TuiPanel panel);
/*!
 * @brief Callback type for drawing batch data to a @ref TuiPanel.
 *
 * @param instance The @ref TuiPanel.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw.
 * @param detail_mode The @ref TuiDetailMode of the batch data.
 * @param tiles_wide The width of the batch data in tiles.
 * @param tiles_tall The height of the batch data in tiles.
 * @param sparse_index The amount of tiles to render if this batch data uses a detail mode with @ref TUI_LAYOUT_FLAG_SPARSE.
 * @param batch_data A pointer to the raw batch tile data array.
 * @param left_x The leftmost pixel to draw the batch data in the framebuffer of the @ref TuiPanel.
 * @param right_x The rightmost pixel to draw the batch data in the framebuffer of the @ref TuiPanel.
 * @param top_y The topmost pixel to draw the batch data in the framebuffer of the @ref TuiPanel.
 * @param bottom_y The bottommost pixel to draw the batch data in the framebuffer of the @ref TuiPanel.
 */
typedef void(*tuiPanelDrawBatchDataCallback) (TuiPanel panel, TuiGlyphAtlas atlas, TuiPalette palette, size_t detail_mode, size_t tiles_wide, size_t tiles_tall, size_t sparse_index, const uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Callback type used for getting the raw pixels of a @ref TuiPanel.
 * 
 * @param panel The @ref TuiPanel.
 * @param width A pointer to where the width will be stored and where you pass in the existing width if pixel_ptr is not NULL. If this is NULL, it is ignored.
 * @param height  A pointer to where the height will be stored and where you pass in the existing height if pixel_ptr is not NULL. If this is NULL, it is ignored.
 * @param pixel_ptr A pointer to an already existing pixel array to fill and reallocate if it is not the right size. If NULL, a new array is allocated instead.
 */
typedef uint8_t* (*tuiPanelGetPixelsCallback) (TuiPanel Panel, size_t* width, size_t* height, uint8_t* pixel_ptr);
/*!
 * @brief Callback type used for rendering a @ref TuiPanel to the screen of its @ref TuiInstance.
 *
 * @param panel The @ref TuiPanel.
 * @param left_x The leftmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param right_x The rightmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param top_y The topmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param bottom_y The bottommost pixel to draw the batch data in the screen of the @ref TuiInstance.
 */
typedef void(*tuiPanelRenderCallback) (TuiPanel panel, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Callback type used for rendering a @ref TuiPanel to another.
 *
 * @param panel The @ref TuiPanel.
 * @param target_panel The target @ref TuiPanel.
 * @param left_x The leftmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param right_x The rightmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param top_y The topmost pixel to draw the batch data in the screen of the @ref TuiInstance.
 * @param bottom_y The bottommost pixel to draw the batch data in the screen of the @ref TuiInstance.
 */
typedef void(*tuiPanelRenderToPanelCallback) (TuiPanel panel, TuiPanel target_panel, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Callback type used for clearing all pixels of @ref TuiPanel with a color.
 * 
 * @param panel The @ref TuiPanel.
 * @param r The value of the clear color's red channel.
 * @param g The value of the clear color's green channel.
 * @param b The value of the clear color's blue channel.
 * @param a The value of the clear color's alpha channel.
 */
typedef void(*tuiPanelClearColorCallback) (TuiPanel panel, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
/*!
 * @brief Callback type used for resizing the framebuffer of a @ref TuiPanel.
 *
 * @param panel The @ref TuiPanel.
 * @param new_width The new width of the framebuffer.
 * @param new_height THe new height of the framebuffer.
 */
typedef void(*tuiPanelSetSizeCallback) (TuiPanel panel, size_t new_width, size_t new_height);
/*! @} */
/*! @name Opaque Object Full Declarations
 * These structs are represent the hidden types behind TUIC opaque objects.
 *  @{ */
/*
 * @brief The struct behind @ref TuiInstance opaque objects. 
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiInstance_s
{
	/*!
	 * @brief Callback for destroying the API data of a @ref TuiInstance.
	 */
	tuiInstanceDestroyCallback InstanceDestroy;
	/*!
	 * @brief Callback for clearing all pixels of the graphics context of a @ref TuiInstance with a color.
	 */
	tuiInstanceClearColorCallback InstanceClearColor;
	/*!
	 * @brief Callback for resizing the main screen of a @ref TuiInstance.
	 */
	tuiInstanceResizeScreenCallback InstanceResizeScreen;
	/*!
	 * @brief Callback for drawing batch data to the main screen of a @ref TuiInstance.
	 */
	tuiInstanceDrawBatchDataCallback InstanceDrawBatchData;
	/*!
	 * @brief Callback for creating the API data of a @ref TuiGlyphAtlas.
	 */
	tuiGlyphAtlasCreateCallback GlyphCreate;
	/*!
	 * @brief Callback for destroying the API data of a @ref TuiGlyphAtlas.
	 */
	tuiGlyphAtlasDestroyCallback GlyphDestroy;
	/*!
	 * @brief Callback for creating the API data of a @ref TuiPalette.
	 */
	tuiPaletteCreateCallback PaletteCreate;
	/*!
	 * @brief Callback for destroying the API data of a @ref TuiPalette.
	 */
	tuiPaletteDestroyCallback PaletteDestroy;
	/*!
	 * @brief Callback for creating the API data of a @ref TuiPanel.
	 */
	tuiPanelCreateCallback PanelCreate;
	/*!
	 * @brief Callback for destroying the API data of a @ref TuiPanel.
	 */
	tuiPanelDestroyCallback PanelDestroy;
	/*!
	 * @brief Callback for drawing batch data to a @ref TuiPanel.
	 */
	tuiPanelDrawBatchDataCallback PanelDrawBatchData;
	/*!
	 * @brief Callback for getting the raw pixels of a @ref TuiPanel.
	 */
	tuiPanelGetPixelsCallback PanelGetPixels;
	/*!
	 * @brief Callback for rendering a @ref TuiPanel to the grapics context of its @ref TuiInstance.
	 */
	tuiPanelRenderCallback PanelRender;
	/*!
	 * @brief Callback for rendering a @ref TuiPanel to the a different one.
	 */
	tuiPanelRenderToPanelCallback PanelRenderToPanel;
	/*!
	 * @brief Callback for clearing all pixels of @ref TuiPanel with a color.
	 */
	tuiPanelClearColorCallback PanelClearColor;
	/*!
	 * @brief Callback for resizing the framebuffer of a @ref TuiPanel.
	 */
	tuiPanelSetSizeCallback PanelSetSize;
	/*!
	 * @brief The amount of @ref TuiPanel objects that currently exist attached to this @ref TuiInstance.
	 */
	size_t PanelCount;
	/*!
	 * @brief The amount of @ref TuiGlyphAtlas objects that currently exist attached to this @ref TuiInstance.
	 */
	size_t GlyphAtlasCount;
	/*!
	 * @brief The amount of @ref TuiPalette objects that currently exist attached to this @ref TuiInstance.
	 */
	size_t PaletteCount;
	/*!
	 * @brief If this @ref TuiInstance is damaged.
	 */
	int IsDamaged;
	/*!
	 * @brief The pixel width of the screen of the TuiInstance.
	 */
	size_t PixelWidth;
	/*!
	 * @brief The pixel height of the screen of the TuiInstance.
	 */
	size_t PixelHeight;
	/*!
	 * @brief A pointer to backend specific API data.
	 */
	void* ApiData;
} TuiInstance_s;
/*
 * @brief The struct behind @ref TuiGlyphAtlas opaque objects.
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiGlyphAtlas_s
{
	/*!
	 * @brief The @ref TuiInstance that this object is attached to.
	 */
	TuiInstance Instance;

	int BlendMode;
	/*!
	 * @brief The atlas type that this @ref TuiGlyphAtlas uses.
	 */
	size_t AtlasType;
	/*!
	 * @brief The amount of channels in the texture of this @ref TuiGlyphAtlas.
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
	 * @brief The amount of glyphs wide, used if this @ref TuiGlyphAtlas uses atlas type @ref TUI_ATLAS_GRID.
	 */
	size_t GridGlyphsWide;
	/*!
	 * @brief The amount of glyphs tall, used if this @ref TuiGlyphAtlas uses atlas type @ref TUI_ATLAS_GRID.
	 */
	size_t GridGlyphsTall;
	/*!
	 * @brief A pointer to backend specific API data.
	 */
	void* ApiData;
} TuiGlyphAtlas_s;
/*
 * @brief The struct behind @ref TuiPalette opaque objects.
 *
 * Properties of this struct are not meant to be edited directly when unless in a backend implementation to avoid undefined behaviour.
 */
typedef struct TuiPalette_s
{
	/*!
	 * @brief The @ref TuiInstance that this object is attached to.
	 */
	TuiInstance Instance;
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
	 * @brief The @ref TuiInstance that this object is attached to.
	 */
	TuiInstance Instance;
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
	uint8_t IsLargeSparseWide;
	/*!
	 * @brief If this is a @ref TuiBatch that uses @ref TUI_LAYOUT_FLAG_SPARSE and requires two bytes for the tile y position instead of one.
	 */
	uint8_t IsLargeSparseTall;
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