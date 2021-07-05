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
/*! \file instance.h
 */
#ifndef TUIC_INSTANCE_H //header guard
#define TUIC_INSTANCE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>
#include <TUIC/detail_mode.h>
#include <TUIC/mouse_button.h>
#include <TUIC/key.h>
#include <TUIC/button_state.h>
#include <TUIC/window_attribute.h>
#include <TUIC/cursor_mode.h>

/*! @name TuiInstance functions
 *
 * These functions are used for manipulating @ref TuiInstance opaque objects. Create functions for TuiInstance objects can only be found in backend headers (such as opengl33.h).
 *
 *  @{ */

TuiInstance tuiInstanceCreate(int pixel_width, int pixel_height, const char* title);
/*!
 * @brief Destroy a @ref TuiInstance and properly dispose of all of its internal data.
 *
 * This function should be called when a @ref TuiInstance object is no longer needed, typically before application exit or when replacing an existing instance with a new one that uses a different graphics backend. All opaque objects that use this instance need to be destroyed first, or otherwise a debug error message will be sent to the callback.
 *
 * @param instance The @ref TuiInstance to destroy.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiInstanceDestroy(TuiInstance instance);

int tuiGetInstanceCount();
/*!
 * @brief Clear the color of the main screen of a @ref TuiInstance graphics context.
 *
 * Clearing the color of the screen will change every pixel to be the color valuse passed into the parameters.
 *
 * @param instance The @ref TuiInstance object that contains the graphics context.
 * @param r The red color value.
 * @param g The green color value.
 * @param b The blue color value.
 * @param a The alpha color value.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiInstanceClearColor(TuiInstance instance, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
/*!
 * @brief Tell an instance that its graphics context was damaged.
 *
 * After an instance is damaged, all objects attached to the instance no longer work and must be manually destroyed and remade.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiInstanceSetDamaged(TuiInstance instance);
/*!
 * @brief Get if a @ref TuiInstance was damaged.
 * 
 * @returns A @ref TuiBoolean showing if it was damaged. @ref TUI_FALSE is returned on error.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
int tuiInstanceGetDamaged(TuiInstance instance);
/*!
 * @brief Resize the main screen of the graphics context of a @ref TuiInstance.
 *
 * @param instance The @ref TuiInstance.
 * @param screen_width The new width of the screen in pixels.
 * @param screen_height The new height of the screen in pixels.
 * @returns The @ref TuiInstance.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_INVALID_INSTANCE_DIMENSIONS if screen_width or screen_height is less than or equal to 0.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiInstanceResizeScreen(TuiInstance instnace, int screen_width, int screen_height);
/*!
* @brief Get the pixel width of a @ref TuiInstance.
*
* @returns The pixel width. 0 is returned on error.
*
* @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
*/
int tuiInstanceGetPixelWidth(TuiInstance instance);
/*!
* @brief Get the pixel height of a @ref TuiInstance.
*
* @returns The pixel height. 0 is returned on error.
*
* @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
*/
int tuiInstanceGetPixelHeight(TuiInstance instance);
/*!
 * @brief  Get the pixel dimensions of a @ref TuiInstance.
 *
 * @param image The @ref TuiInstance.
 * @param width A pointer to where the width will be stored. If this is NULL or an error occurs, it is ignored.
 * @param height A pointer to where the height will be stored. If this is NULL or an error occurs, it is ignored.
 *
 * @errors Throws @TUI_ERROR_NULL_INSTANCE if instance is NULL.
 */
void tuiInstanceGetPixelDimensons(TuiInstance instance, int* width, int* height);
/*!
 * @brief Draw a @ref TuiBatch to the screen of a @ref TuiInstance.
 *
 * @param instance The @ref TuiInstance.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw. If not used, pass NULL.
 * @param batch The @ref TuiBatch to draw to the framebuffer.
 * @param blend_mode The blend mode to use for this draw.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_NULL_BATCH if batch is NULL.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE if the @ref TuiInstance of atlas does not match instance.
 * Throws @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE if palette is not NULL and its @ref TuiInstance does not match instance.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiInstanceDrawBatch(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch);
/*!
 * @brief Draw a @ref TuiBatch to the screen of a @ref TuiInstance.
 *
 * @param instance The @ref TuiInstance.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw. If not used, pass NULL.
 * @param batch The @ref TuiBatch to draw to the framebuffer.
 * @param blend_mode The blend mode to use for this draw.
 *
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_NULL_BATCH_SATA if batch_data is NULL.
 * Throws @ref TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS if tiles_wide or tiles_tall is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_DETAIL_MODE if detail_mode is an invalid @ref TuiDetailMode.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE if the @ref TuiInstance of atlas does not match instance.
 * Throws @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE if palette is not NULL and its @ref TuiInstance does not match instance.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiInstanceDrawBatchData(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data);
/*!
 * @brief Draw a @ref TuiBatch to the scren of a @ref TuiInstance with a transformation.
 *
 * @param instance The @ref TuiInstance.
 * @param atlas The @ref TuiGlyphAtlas to use for this draw.
 * @param palette The @ref TuiPalette to use for this draw. If not used, pass NULL.
 * @param batch The @ref TuiBatch to draw to the framebuffer.
 * @param blend_mode The blend mode to use for this draw.
 * @param left_x The leftmost x pixel coordinate of the draw rect.
 * @param right_x The rightmost x pixel coordinate of the draw rect.
 * @param top_y The topmost y pixel coordinate of the draw rect.
 * @param bottom_y The bottomost y pixel coordinate of the draw rect.
 * 
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_NULL_BATCH if batch is NULL.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE if the @ref TuiInstance of atlas does not match instance.
 * Throws @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE if palette is not NULL and its @ref TuiInstance does not match instance.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiInstanceDrawBatchTransformed(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y);
/*!
 * @brief Draw batch data to a @ref TuiInstance with a transformation.
 *
 * @param instance The @ref TuiInstance.
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
 * @errors Throws @ref TUI_ERROR_NULL_INSTANCE if instance is NULL.
 * Throws @ref TUI_ERROR_DAMAGED_INSTANCE if instance is damaged.
 * Throws @ref TUI_ERROR_NULL_GLYPH_ATLAS if atlas is NULL.
 * Throws @ref TUI_ERROR_NULL_BATCH_SATA if batch_data is NULL.
 * Throws @ref TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS if tiles_wide or tiles_tall is less than or equal to 0.
 * Throws @ref TUI_ERROR_INVALID_DETAIL_MODE if detail_mode is an invalid @ref TuiDetailMode.
 * Throws @ref TUI_ERROR_PALETTE_REQUIRED if palette is NULL and a palette is required by the @ref TuiDetailMode of the @ref TuiBatch.
 * Throws @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE if the @ref TuiInstance of atlas does not match instance.
 * Throws @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE if palette is not NULL and its @ref TuiInstance does not match instance.
 * Throws @ref TUI_ERROR_BACKEND_SPECIFIC and may or may not return if backend specific errors occur.
 */
void tuiInstanceDrawBatchDataTransformed(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y);

void tuiInstanceSwapBuffers(TuiInstance instance);

void tuiInstanceSwapInterval(TuiInstance instance, int interval);

const char* tuiInstanceGetClipboardString(TuiInstance instance);

void tuiInstanceSetClipboardString(TuiInstance instance, const char* string);

TuiCursorMode tuiInstanceGetCursorMode(TuiInstance instance);

void tuiInstanceSetCursorMode(TuiInstance instance, TuiCursorMode cursor_mode);

TuiBoolean tuiInstanceGetStickyKeys(TuiInstance instance);

void tuiInstanceSetStickyKeys(TuiInstance instance, TuiBoolean sticky_keys_mode);

TuiBoolean tuiInstanceGetStickyMouseButtons(TuiInstance instance);

void tuiInstanceSetStickyMouseButtons(TuiInstance instance, TuiBoolean sticky_mouse_buttons);

TuiBoolean tuiInstanceGetLockKeyMods(TuiInstance instance);

void tuiInstanceSetLockKeyMods(TuiInstance instance, TuiBoolean lock_key_mods);

TuiBoolean tuiInstanceGetRawMouseMotion(TuiInstance instance);

void tuiInstanceSetRawMouseMotion(TuiInstance instance, TuiBoolean raw_mouse_motion);

TuiButtonState tuiInstanceGetKey(TuiInstance instance, TuiKey key);

TuiButtonState tuiInstanceGetMouseButton(TuiInstance instance, TuiMouseButton mouse_button);

void tuiInstanceGetCursorPos(TuiInstance instance, double *xpos, double *ypos);

void tuiInstanceSetCursorPos(TuiInstance instance, double xpos, double ypos);

void tuiDefaultWindowHints();

void tuiWindowHint(TuiWindowAttribute hint, int value);

void tuiWindowHintString(TuiWindowAttribute hint, const char* value);

int tuiInstanceWindowShouldClose(TuiInstance instance);

void tuiInstanceSetWindowShouldClose(TuiInstance instance, TuiBoolean should_close);

void tuiInstanceSetWindowTitle(TuiInstance instance, const char* title);

void tuiInstanceSetWindowIcon(TuiInstance instance, int count, const TuiImage* images);

void tuiInstanceGetWindowPos(TuiInstance instance, int* xpos, int* ypos);

void tuiInstanceSetWindowPos(TuiInstance instance, int xpos, int ypos); 

void tuiInstanceSetWindowSizeLimits(TuiInstance instance, int minwidth, int minheight, int maxwidth, int maxheight);

void tuiInstanceSetWindowAspectRatio(TuiInstance instance, int numer, int denom);

void tuiInstanceGetWindowContentScale(TuiInstance instance, float* xscale, float* yscale);

float tuiInstanceGetWindowOpacity(TuiInstance instance);

void tuiInstanceSetWindowOpacity(TuiInstance instance, float opacity);

void tuiInstanceIconifyWindow(TuiInstance instance);

void tuiInstanceRestoreWindow(TuiInstance instance);

void tuiInstanceMaximizeWindow(TuiInstance instance);

void tuiInstanceShowWindow(TuiInstance instance);

void tuiInstanceHideWindow(TuiInstance instance);

void tuiInstanceFocusWindow(TuiInstance instance);

void tuiInstanceRequestWindowAttention(TuiInstance instance);

TuiMonitor tuiInstanceGetWindowMonitor(TuiInstance instance);

void tuiInstanceSetWindowMonitor(TuiInstance instance, TuiMonitor monitor, int xpos, int ypos, int width, int height, int refreshRate);

int tuiInstanceGetWindowAttrib(TuiInstance instance, TuiWindowAttribute attrib);

void tuiInstanceSetWindowAttrib(TuiInstance instance, TuiWindowAttribute attrib, int value);

void tuiInstanceSetUserPtr(TuiInstance instance, void* ptr);

void* tuiInstanceGetUserPtr(TuiInstance instance);

void tuiInstanceSetCursor(TuiInstance instance, TuiCursor cursor);

tuiWindowPosFunction tuiInstanceSetWindowPosCallback(TuiInstance instance, tuiWindowPosFunction callback);

tuiWindowSizeFunction tuiInstanceSetWindowSizeCallback(TuiInstance instance, tuiWindowSizeFunction callback);

tuiWindowCloseFunction tuiInstanceSetWindowCloseCallback(TuiInstance instance, tuiWindowCloseFunction callback);

tuiWindowRefreshFunction tuiInstanceSetWindowRefreshCallback(TuiInstance instance, tuiWindowRefreshFunction callback);

tuiWindowFocusFunction tuiInstanceSetWindowFocusCallback(TuiInstance instance, tuiWindowFocusFunction callback);

tuiWindowIconifyFunction tuiInstanceSetWindowIconifyCallback(TuiInstance instance, tuiWindowIconifyFunction callback);

tuiWindowMaximizeFunction tuiInstanceSetWindowMaximizeCallback(TuiInstance instance, tuiWindowMaximizeFunction callback);

tuiFramebufferSizeFunction tuiInstanceSetFramebufferSizeCallback(TuiInstance instance, tuiFramebufferSizeFunction callback);

tuiWindowContentScaleFunction tuiInstanceSetWindowContentScaleCallback(TuiInstance instance, tuiWindowContentScaleFunction callback);

tuiKeyFunction tuiInstanceSetKeyCallback(TuiInstance instance, tuiKeyFunction callback);

tuiCharFunction tuiInstanceSetCharCallback(TuiInstance instance, tuiCharFunction callback);

tuiMouseButtonFunction tuiInstanceSetMouseButtonCallback(TuiInstance instance, tuiMouseButtonFunction callback);

tuiCursorPosFunction tuiInstanceSetCursorPosCallback(TuiInstance instance, tuiCursorPosFunction callback);

tuiCursorEnterFunction tuiInstanceSetCursorEnterCallback(TuiInstance instance, tuiCursorEnterFunction callback);

tuiScrollFunction tuiInstanceSetScrollCallback(TuiInstance instance, tuiScrollFunction callback);

tuiDropFunction tuiInstanceSetDropCallback(TuiInstance instance, tuiDropFunction callback);

/*! @} */
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard