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
/*! \file panel.h
 */
#ifndef TUIC_PANEL_H //header guard
#define TUIC_PANEL_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
/*! @name TuiPanel functions
 *
 * These functions are used for manipulating @ref TuiPanel opaque objects.
 *
 * @{ */
/*!
 * @brief Create a @ref TuiPanel with the given pixel width and height.
 * 
 * @param pixel_width The width of the TuiPanel in pixels.
 * @param pixel_height The height of the TuiPanel in pixels
 *
 * @returns batch The created @ref TuiPanel object. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_INVALID_PANEL_DIMENSIONS if pixel_width or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiPanel tuiPanelCreate(TuiInstance instance, int pixel_width, int pixel_height);
/*!
 * @brief Destroy a @ref TuiPanel and correctly dispose of all of its resources.
 *
 * @param batch The @ref TuiPanel object to destroy.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelDestroy(TuiPanel panel);
/*!
 * @brief  Get the @ref TuiInstance of a  @ref TuiPanel.
 *
 * @param panel The @ref TuiPanel.
 *
 * @returns The @ref TuiInstance. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 */
TuiInstance tuiPanelGetInstance(TuiPanel panel);
/*!
 * @brief Get a @ref TuiImage of the framebuffer of a @ref TuiPanel.
 *
 * @param panel The @ref TuiPanel.
 * @param image The @ref TuiImage to replace. If this is NULL, a new image will be created instead.
 *
 * @returns The created @ref TuiImage. NULL is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
TuiImage tuiPanelGetImage(TuiPanel panel, TuiImage fill_image);
/*!
 * @brief Get the 4 channel raw pixel array of the framebuffer of a @ref TuiPanel.
 *
 * The returned pixel array can be safely deallocated using tuiFree() found in heap.h.
 * 
 * @param panel The @ref TuiPanel.
 * @param pixel_width A pointer to where the width of the panel in pixels will be stored. If NULL or an error occurs, it is ignored.
 * @param pixel_height A pointer to where the height of the panel in pixels will be stored. If NULL or an error occcurs, it is ignored.
 * @param fill_pixels An existing pixels array to reallocate. If this is NULL, a new array is allocated instead.
 * 
 * @returns The returned pixel array. NULL is returned on error.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
uint8_t* tuiPanelGetPixels(TuiPanel panel, int* pixel_width, int* pixel_height, uint8_t* fill_pixels);
/*!
 * @brief Clear the framebuffer of a @ref TuiPanel to a color.
 *
 * @param panel The @ref TuiPanel.
 * @param r The red color channel of the clear color.
 * @param g The green color channel of the clear color.
 * @param b The blue color channel of the clear color.
 * @param a The alpha color channel of the clear color.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL is panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelClearColor(TuiPanel panel, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
/*!
 * @brief Set the pixel dimensions of the framebuffer of a @ref TuiPanel.
 *
 * @param panel The @ref TuiPanel.
 * @param pixel_width The new width to set the framebuffer.
 * @param pixel_height The new height to set the framebuffer.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL is panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_INVALID_PANEL_DIMENSIONS if pixel_width or pixel_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelSetPixelDimensions(TuiPanel panel, int pixel_width, int pixel_height);
/*!
 * @brief Get the pixel dimensions of the framebuffer of a @ref TuiPanel.
 *
 * @param panel The @ref TuiPanel.
 * @param pixel_width Pointer to where the width of the framebuffer will be stored. If it is NULL or an erro occurs, it is ignored.
 * @param pixel_height Pointer to where the height of the framebuffer will be stored. If it is NULL or an error occurs, it is ignored.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_INVALID_PANEL_DIMENSIONS if pixel_width or pixel_height is less than or equal to 0.
 */
void tuiPanelGetPixelDimensions(TuiPanel panel, int* pixel_width, int* pixel_height);
/*!
 * @brief Returns the pixel width of a @ref TuiPanel.
 *
 * @param palette The @ref TuiPanel object.
 *
 * @returns The pixel width. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PANEL is panel is NULL.
 */
int tuiPanelGetPixelWidth(TuiPanel panel);
/*!
 * @brief Returns the pixel height of a @ref TuiPanel.
 *
 * @param palette The @ref TuiPanel object.
 *
 * @returns The pixel height. 0 is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PANEL is panel is NULL.
 */
int tuiPanelGetPixelHeight(TuiPanel panel);
/*!
 * @brief Draw a @ref TuiBatch to a @ref TuiPanel.
 *
 * @param panel The @ref TuiPanel.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw. If not used, pass NULL.
 * @param batch The @ref TuiBatch to draw to the framebuffer.
 * @param blend_mode The blend mode to use for this draw.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_NULL_BATCH is batch is NULL.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE if the @ref TuiInstance of atlas does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE if palette is not NULL and its @ref TuiInstance does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelDrawBatch(TuiPanel panel, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch);
/*!
 * @brief Draw a @ref TuiBatch to a @ref TuiPanel.
 *
 * @param panel The @ref TuiPanel.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw. If not used, pass NULL.
 * @param batch The @ref TuiBatch to draw to the framebuffer.
 * @param blend_mode The blend mode to use for this draw.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_NULL_BATCH_SATA if batch_data is NULL.
 * Throws @ref TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS if tiles_wide or tiles_tall is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_DETAIL_MODE if detail_mode is an invalid @ref TuiDetailMode.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE if the @ref TuiInstance of atlas does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE if palette is not NULL and its @ref TuiInstance does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelDrawBatchData(TuiPanel panel, TuiGlyphAtlas atlas, TuiPalette palette, int detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data);
/*!
 * @brief Draw a @ref TuiBatch to the scren of a @ref TuiPanel with a transformation.
 *
 * @param panel The @ref TuiPanel.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw. If not used, pass NULL.
 * @param batch The @ref TuiBatch to draw to the framebuffer.
 * @param blend_mode The blend mode to use for this draw.
 * @param left_x The leftmost x pixel coordinate of the draw rect.
 * @param right_x The rightmost x pixel coordinate of the draw rect.
 * @param top_y The topmost y pixel coordinate of the draw rect.
 * @param bottom_y The bottomost y pixel coordinate of the draw rect.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_NULL_BATCH if batch is NULL.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE if the @ref TuiInstance of atlas does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE if palette is not NULL and its @ref TuiInstance does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelDrawBatchTransformed(TuiPanel panel, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Draw batch data to a @ref TuiPanel with a transformation.
 *
 * @param panel The @ref TuiPanel.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw. If not used, pass NULL.
 * @param batch The @ref TuiBatch to draw to the framebuffer.
 * @param detail_mode The detail mode to use for this render.
 * @param blend_mode The blend mode to use for this draw.
 * @param tiles_wide The amount of tiles wide in the batch.
 * @param tiles_tall The amount of tiles tall in the batch.
 * @param batch_data A pointer to the raw batch byte array.
 * @param left_x The leftmost x pixel coordinate of the draw rect.
 * @param right_x The rightmost x pixel coordinate of the draw rect.
 * @param top_y The topmost y pixel coordinate of the draw rect.
 * @param bottom_y The bottomost y pixel coordinate of the draw rect.
 *
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_NULL_BATCH_SATA if batch_data is NULL.
 * Throws @ref TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS if tiles_wide or tiles_tall is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_DETAIL_MODE if detail_mode is an invalid @ref TuiDetailMode.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE if the @ref TuiInstance of atlas does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE if palette is not NULL and its @ref TuiInstance does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelDrawBatchDataTransformed(TuiPanel panel, TuiGlyphAtlas atlas, TuiPalette palette, int detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Render a @ref TuiPanel to the main graphics context framebuffer if its @ref TuiInstance.
 *
 * @param panel The @ref TuiPanel.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelRender(TuiPanel panel);
/*!
 * @brief Render a @ref TuiPanel to the main graphics context framebuffer of its @ref TuiInstance in a transformed position.
 *
 * @param panel The @ref TuiPanel.
 * @param left_x The framebuffer pixel x coordinate of the @ref TuiPanel left side.
 * @param right_x The framebuffer pixel x coordinate of the @ref TuiPanel right side.
 * @param top_y The framebuffer pixel y coordinate of the @ref TuiPanel top side.
 * @param bottom_y The framebuffer pixel y coordinat of the @ref TuiPanel bottom side.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelRenderTransformed(TuiPanel panel, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Render the framebuffer texture of a @ref TuiPanel to the framebuffer of a different one.
 *
 * @param panel The @ref TuiPanel to render.
 * @param target_panel The @ref TuiPanel rendered to.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_NULL_TARGET_PANEL if target_panel is NULL.
 * Throws @ref TUI_ERROR_UNMATCHING_PANEL_INSTANCE if the @ref TuiInstacne of target_panel does not match the @ref TuiInstance of panel.
 */
void tuiPanelRenderToPanel(TuiPanel panel, TuiPanel target_panel);
/*!
 * @brief Render the framebuffer texture of a @ref TuiPanel to the framebuffer of a different one with a transformation.
 *
 * @param panel The @ref TuiPanel to render.
 * @param target_panel The @ref TuiPanel rendered to.
 * @param left_x The framebuffer pixel x coordinate of the @ref TuiPanel left side.
 * @param right_x The framebuffer pixel x coordinate of the @ref TuiPanel right side.
 * @param top_y The framebuffer pixel y coordinate of the @ref TuiPanel top side.
 * @param bottom_y The framebuffer pixel y coordinat of the @ref TuiPanel bottom side.
 * 
 *
 * @errors Throws @ref TUI_ERROR_NULL_PANEL if panel is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if the @ref TuiInstance of panel is damaged.
 * Throws @ref TUI_ERROR_NULL_TARGET_PANEL if target_panel is NULL.
 * Throws @ref TUI_ERROR_UNMATCHING_PANEL_INSTANCE if the @ref TuiInstacne of target_panel does not match the @ref TuiInstance of panel.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiPanelRenderToPanelTransformed(TuiPanel panel, TuiPanel target_panel, int left_x, int right_x, int top_y, int bottom_y);
/*! @} */
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard