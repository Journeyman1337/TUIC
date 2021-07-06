#include <TUIC/tuic.h>
#include "objects.h"
#include <GLFW/glfw3.h>
#include "opengl33.h"

static size_t sInstanceCount = 0;

TuiInstance tuiInstanceCreate(int pixel_width, int pixel_height, const char* title, TuiWindowCreateInfo* create_info)
{
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_INSTANCE_DIMENSIONS, __func__);
		return;
	}
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return NULL;
	}

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	if (create_info != NULL)
	{ 
		glfwWindowHint(GLFW_RESIZABLE, create_info->resizable);
		glfwWindowHint(GLFW_VISIBLE, create_info->visible);
		glfwWindowHint(GLFW_DECORATED, create_info->decorated);
		glfwWindowHint(GLFW_FOCUSED, create_info->focused);
		glfwWindowHint(GLFW_AUTO_ICONIFY, create_info->auto_iconify);
		glfwWindowHint(GLFW_FLOATING, create_info->floating);
		glfwWindowHint(GLFW_MAXIMIZED, create_info->maximized);
		glfwWindowHint(GLFW_CENTER_CURSOR, create_info->center_cursor);
		glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, create_info->transparent_framebuffer);
		glfwWindowHint(GLFW_FOCUS_ON_SHOW, create_info->focus_on_show);
		glfwWindowHint(GLFW_SCALE_TO_MONITOR, create_info->scale_to_monitor);
	}
	else
	{
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
		glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
		glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
		glfwWindowHint(GLFW_AUTO_ICONIFY, GLFW_TRUE);
		glfwWindowHint(GLFW_FLOATING, GLFW_FALSE);
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
		glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_FALSE);
		glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_FALSE);
		glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
		glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);
	}
	GLFWwindow* window = glfwCreateWindow(pixel_width, pixel_height, title, NULL, NULL);
	if (window == NULL)
	{
		printf("Failed to create GLFW window.\n");
		glfwTerminate();
		return -1;
	}

	TuiInstance instance = (TuiInstance_s*)tuiAllocate(sizeof(TuiInstance_s));
	instance->PanelCount = 0;
	instance->PixelWidth = (size_t)pixel_width;
	instance->PixelHeight = (size_t)pixel_height;
	instance->GlyphAtlasCount = 0;
	instance->PaletteCount = 0;
	instance->IsDamaged = TUI_FALSE;
	instance->window = window;

	glfwMakeContextCurrent(window);

	tuiInstanceCreate_Opengl33(instance, ((void*)glfwGetProcAddress));
	sInstanceCount++;
	return instance;
}

TuiWindowCreateInfo tuiWindowCreateInfo()
{
	TuiWindowCreateInfo info;
	info.resizable = TUI_FALSE;
	info.visible = TUI_TRUE;
	info.decorated = TUI_TRUE;
	info.focused = TUI_TRUE;
	info.auto_iconify = TUI_TRUE;
	info.floating = TUI_FALSE;
	info.maximized = TUI_FALSE;
	info.center_cursor = TUI_FALSE;
	info.transparent_framebuffer = TUI_FALSE;
	info.focus_on_show = TUI_TRUE;
	info.scale_to_monitor = TUI_FALSE;
	return info;
}

void tuiInstanceDestroy(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	int dangling = TUI_FALSE;
	if (instance->PanelCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_PANEL, __func__);
		dangling = TUI_TRUE;
	}
	if (instance->GlyphAtlasCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_GLYPH_ATLAS, __func__);
		dangling = TUI_TRUE;
	}
	if (instance->PaletteCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_PALETTE, __func__);
		dangling = TUI_TRUE;
	}
	if (instance->TextureCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_TEXTURE, __func__);
		dangling = TUI_TRUE;
	}
	if (dangling == TUI_TRUE)
	{
		return;
	}

	tuiInstanceDestroy_Opengl33(instance);
	tuiFree(instance);
	sInstanceCount--;
}

int tuiGetInstanceCount()
{
	return sInstanceCount;
}

void tuiInstanceClearColor(TuiInstance instance, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}

	tuiInstanceClearColor_Opengl33(instance, r, g, b, a);
}

void tuiInstanceSetDamaged(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}

	instance->IsDamaged = TUI_TRUE;
}

int tuiInstanceGetDamaged(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}

	return instance->IsDamaged;
}

void tuiInstanceResizeScreen(TuiInstance instance, int screen_width, int screen_height)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (screen_width <= 0 || screen_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_INSTANCE_DIMENSIONS, __func__);
		return;
	}

	glfwSetWindowSize(instance->window, screen_width, screen_height);
	instance->PixelWidth = (int)screen_width;
	instance->PixelHeight = (int)screen_height;
	tuiInstanceResizeScreen_Opengl33(instance, screen_width, screen_height);
}

int tuiInstanceGetPixelWidth(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return 0;
	}

	return (size_t)instance->PixelWidth;
}

int tuiInstanceGetPixelHeight(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return 0;
	}

	return (size_t)instance->PixelHeight;
}

void tuiInstanceGetPixelDimensons(TuiInstance instance, int* width, int* height)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}

	if (width != NULL)
	{
		*width = instance->PixelWidth;
	}
	if (height != NULL)
	{
		*height = instance->PixelHeight;
	}
}

void tuiInstanceDrawBatch(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return;
	}
	if (batch == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (tuiDetailHasPalette(batch->DetailMode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugError(TUI_ERROR_PALETTE_REQUIRED, __func__);
		return;
	}
	if (atlas->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE, __func__);
		return;
	}
	if (palette != NULL && palette->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}

	tuiInstanceDrawBatchData_Opengl33(instance, atlas, palette, batch->DetailMode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, 0, instance->PixelWidth, 0, instance->PixelHeight);
}

void tuiInstanceDrawBatchData(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (batch_data == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH_DATA, __func__);
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS, __func__);
		return;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return;
	}
	if (tuiDetailHasPalette(detail_mode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugError(TUI_ERROR_PALETTE_REQUIRED, __func__);
		return;
	}
	if (atlas->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE, __func__);
		return;
	}
	if (palette != NULL && palette->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}

	tuiInstanceDrawBatchData_Opengl33(instance, atlas, palette, (size_t)detail_mode, (size_t)tiles_wide, (size_t)tiles_tall, (size_t)sparse_index, batch_data, 0, instance->PixelWidth, 0, instance->PixelHeight);

}

void tuiInstanceDrawBatchTransformed(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return;
	}
	if (batch == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (tuiDetailHasPalette(batch->DetailMode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugError(TUI_ERROR_PALETTE_REQUIRED, __func__);
		return;
	}
	if (atlas->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE, __func__);
		return;
	}
	if (palette != NULL && palette->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}

	tuiInstanceDrawBatchData_Opengl33(instance, atlas, palette, batch->DetailMode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, left_x, right_x, top_y, bottom_y);
}

void tuiInstanceDrawBatchDataTransformed(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (batch_data == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH_DATA, __func__);
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS, __func__);
		return;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return;
	}
	if (tuiDetailHasPalette(detail_mode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugError(TUI_ERROR_PALETTE_REQUIRED, __func__);
		return;
	}
	if (atlas->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE, __func__);
		return;
	}
	if (palette != NULL && palette->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}

	tuiInstanceDrawBatchData_Opengl33(instance, atlas, palette, (size_t)detail_mode, (size_t)tiles_wide, (size_t)tiles_tall, sparse_index, batch_data, left_x, right_x, top_y, bottom_y);
}

void tuiInstanceSwapBuffers(TuiInstance instance)
{
	glfwSwapBuffers(instance->window);
}

void tuiInstanceSwapInterval(TuiInstance instance, int interval)
{
	glfwMakeContextCurrent(instance->window);
	glfwSwapInterval(interval);
}

const char* tuiInstanceGetClipboardString(TuiInstance instance)
{
	return glfwGetClipboardString(instance->window);
}

void tuiInstanceSetClipboardString(TuiInstance instance, const char* string)
{
	glfwSetClipboardString(instance->window, string);
}

TuiCursorMode tuiInstanceGetCursorMode(TuiInstance instance)
{
	return (TuiCursorMode)glfwGetInputMode(instance->window, GLFW_CURSOR);
}

void tuiInstanceSetCursorMode(TuiInstance instance, TuiCursorMode cursor_mode)
{
	glfwSetInputMode(instance->window, GLFW_CURSOR, (int)cursor_mode);
}

TuiBoolean tuiInstanceGetStickyKeys(TuiInstance instance)
{
	return (TuiBoolean)glfwGetInputMode(instance->window, GLFW_STICKY_KEYS);
}

void tuiInstanceSetStickyKeys(TuiInstance instance, TuiBoolean sticky_keys_mode)
{
	glfwSetInputMode(instance->window, GLFW_STICKY_KEYS, (int)sticky_keys_mode);
}

TuiBoolean tuiInstanceGetStickyMouseButtons(TuiInstance instance)
{
	return (TuiBoolean)glfwGetInputMode(instance->window, GLFW_STICKY_MOUSE_BUTTONS);
}

void tuiInstanceSetStickyMouseButtons(TuiInstance instance, TuiBoolean sticky_mouse_buttons)
{
	glfwSetInputMode(instance->window, GLFW_STICKY_MOUSE_BUTTONS, (int)sticky_mouse_buttons);
}

TuiBoolean tuiInstanceGetLockKeyMods(TuiInstance instance)
{
	return (TuiBoolean)glfwGetInputMode(instance->window, GLFW_LOCK_KEY_MODS);
}

void tuiInstanceSetLockKeyMods(TuiInstance instance, TuiBoolean lock_key_mods)
{
	glfwSetInputMode(instance->window, GLFW_LOCK_KEY_MODS, (int)lock_key_mods);
}

TuiBoolean tuiInstanceGetRawMouseMotion(TuiInstance instance)
{
	return (TuiBoolean)glfwGetInputMode(instance->window, GLFW_RAW_MOUSE_MOTION);
}

void tuiInstanceSetRawMouseMotion(TuiInstance instance, TuiBoolean raw_mouse_motion)
{
	if (glfwRawMouseMotionSupported() == GLFW_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INVALID_RAW_MOUSE_MOTION, __func__);
		return;
	}

	glfwSetInputMode(instance->window, GLFW_RAW_MOUSE_MOTION, (int)raw_mouse_motion);
}

TuiButtonState tuiInstanceGetKey(TuiInstance instance, TuiKey key)
{
	return glfwGetKey(instance->window, key);
}

TuiButtonState tuiInstanceGetMouseButton(TuiInstance instance, TuiMouseButton mouse_button)
{
	return glfwGetMouseButton(instance->window, mouse_button);
}

void tuiInstanceGetCursorPos(TuiInstance instance, double* xpos, double* ypos)
{
	glfwGetCursorPos(instance->window, xpos, ypos);
}

void tuiInstanceSetCursorPos(TuiInstance instance, double xpos, double ypos)
{
	glfwSetCursorPos(instance->window, xpos, ypos);
}

void tuiInstanceSetWindowTitle(TuiInstance instance, const char* title)
{
	glfwSetWindowTitle(instance->window, title);
}

void tuiInstanceSetWindowIcon(TuiInstance instance, int count, const TuiImage* images)
{

	// TODO glfwSetWindowIcon(instance->window, count, );
}

void tuiInstanceGetWindowPos(TuiInstance instance, int* xpos, int* ypos)
{
	glfwGetWindowPos(instance->window, xpos, ypos);
}

void tuiInstanceSetWindowPos(TuiInstance instance, int xpos, int ypos)
{
	glfwSetWindowPos(instance->window, xpos, ypos);
}

void tuiInstanceSetWindowSizeLimits(TuiInstance instance, int minwidth, int minheight, int maxwidth, int maxheight)
{
	glfwSetWindowSizeLimits(instance->window, minwidth, minheight, maxwidth, maxheight);
}

void tuiInstanceSetWindowAspectRatio(TuiInstance instance, int numer, int denom)
{
	glfwSetWindowAspectRatio(instance->window, numer, denom);
}

void tuiInstanceGetWindowContentScale(TuiInstance instance, float* xscale, float* yscale)
{
	return glfwGetWindowContentScale(instance->window, xscale, yscale);
}

float tuiInstanceGetWindowOpacity(TuiInstance instance)
{
	return glfwGetWindowOpacity(instance->window);
}

void tuiInstanceSetWindowOpacity(TuiInstance instance, float opacity)
{
	glfwSetWindowOpacity(instance->window, opacity);
}

void tuiInstanceIconifyWindow(TuiInstance instance)
{
	glfwIconifyWindow(instance->window);
}

void tuiInstanceRestoreWindow(TuiInstance instance)
{
	glfwRestoreWindow(instance->window);
}


int tuiInstanceWindowShouldClose(TuiInstance instance)
{
	return glfwWindowShouldClose(instance->window);
}

void tuiInstanceSetWindowShouldClose(TuiInstance instance, TuiBoolean should_close)
{
	glfwSetWindowShouldClose(instance->window, should_close);
}

void tuiInstanceMaximizeWindow(TuiInstance instance)
{
	glfwMaximizeWindow(instance->window);
}

void tuiInstanceShowWindow(TuiInstance instance)
{
	glfwShowWindow(instance->window);
}

void tuiInstanceHideWindow(TuiInstance instance)
{
	glfwHideWindow(instance->window);
}

void tuiInstanceFocusWindow(TuiInstance instance)
{
	glfwFocusWindow(instance->window);
}

void tuiInstanceRequestWindowAttention(TuiInstance instance)
{
	glfwRequestWindowAttention(instance->window);
}

TuiMonitor tuiInstanceGetWindowMonitor(TuiInstance instance)
{
	return glfwGetWindowMonitor(instance->window);
}

void tuiInstanceSetWindowMonitor(TuiInstance instance, TuiMonitor monitor, int xpos, int ypos, int width, int height, int refreshRate)
{
	glfwSetWindowMonitor(instance->window, monitor, xpos, ypos, width, height, refreshRate);
}

TuiBoolean tuiInstanceGetWindowFocused(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_FOCUSED);
}

TuiBoolean tuiInstanceGetWindowIconified(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_ICONIFIED);
}

TuiBoolean tuiInstanceGetWindowMaximized(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_MAXIMIZED);
}

TuiBoolean tuiInstanceGetWindowMouseEntered(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_HOVERED);
}

TuiBoolean tuiInstanceGetWindowVisible(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_VISIBLE);
}

TuiBoolean tuiInstanceGetWindowResizable(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_RESIZABLE);
}

void tuiInstanceSetWindowResizable(TuiInstance instance, TuiBoolean resizable)
{
	glfwSetWindowAttrib(instance->window, GLFW_RESIZABLE, (int)resizable);
}

TuiBoolean tuiInstanceGetWindowDecorated(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_DECORATED);
}

void tuiInstanceSetWindowDecorated(TuiInstance instance, TuiBoolean decorated)
{
	glfwSetWindowAttrib(instance->window, GLFW_DECORATED, (int)decorated);
}

TuiBoolean tuiInstanceGetWindowAutoIconify(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_AUTO_ICONIFY);
}

void tuiInstanceSetWindowAutoIconify(TuiInstance instance, TuiBoolean auto_iconify)
{
	glfwSetWindowAttrib(instance->window, GLFW_AUTO_ICONIFY, (int)auto_iconify);
}

TuiBoolean tuiInstanceGetWindowFloating(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_FLOATING);
}

void tuiInstanceSetWindowFloating(TuiInstance instance, TuiBoolean floating)
{
	glfwSetWindowAttrib(instance->window, GLFW_FLOATING, (int)floating);
}

TuiBoolean tuiInstanceGetWindowTransparentFramebuffer(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_TRANSPARENT_FRAMEBUFFER);
}

TuiBoolean tuiInstanceGetWindowFocusOnShow(TuiInstance instance)
{
	return (TuiBoolean)glfwGetWindowAttrib(instance->window, GLFW_FOCUS_ON_SHOW);
}

void tuiInstanceSetWindowFocusOnShow(TuiInstance instance, TuiBoolean focus_on_show)
{
	glfwSetWindowAttrib(instance->window, GLFW_FOCUS_ON_SHOW, (int)focus_on_show);
}

void tuiInstanceSetUserPtr(TuiInstance instance, void* ptr)
{
	instance->UserPtr = ptr;
}

void* tuiInstanceGetUserPtr(TuiInstance instance)
{
	return instance->UserPtr;
}

void tuiInstanceSetCursor(TuiInstance instance, TuiCursor cursor)
{
	glfwSetCursor(instance->window, cursor);
}

tuiWindowPosFunction tuiInstanceSetWindowPosCallback(TuiInstance instance, tuiWindowPosFunction callback)
{
	return (tuiWindowPosFunction)glfwSetWindowPosCallback(instance->window, callback);
}

tuiWindowSizeFunction tuiInstanceSetWindowSizeCallback(TuiInstance instance, tuiWindowSizeFunction callback)
{
	return (tuiWindowSizeFunction)glfwSetWindowSizeCallback(instance->window, callback);
}

tuiWindowCloseFunction tuiInstanceSetWindowCloseCallback(TuiInstance instance, tuiWindowCloseFunction callback)
{
	return (tuiWindowCloseFunction)glfwSetWindowCloseCallback(instance->window, callback);
}

tuiWindowRefreshFunction tuiInstanceSetWindowRefreshCallback(TuiInstance instance, tuiWindowRefreshFunction callback)
{
	return (tuiWindowRefreshFunction)glfwSetWindowRefreshCallback(instance->window, callback);
}

tuiWindowFocusFunction tuiInstanceSetWindowFocusCallback(TuiInstance instance, tuiWindowFocusFunction callback)
{
	return (tuiWindowFocusFunction)glfwSetWindowFocusCallback(instance->window, callback);
}

tuiWindowIconifyFunction tuiInstanceSetWindowIconifyCallback(TuiInstance instance, tuiWindowIconifyFunction callback)
{
	return (tuiWindowIconifyFunction)glfwSetWindowIconifyCallback(instance->window, callback);
}

tuiWindowMaximizeFunction tuiInstanceSetWindowMaximizeCallback(TuiInstance instance, tuiWindowMaximizeFunction callback)
{
	return (tuiWindowMaximizeFunction)glfwSetWindowMaximizeCallback(instance->window, callback);
}

tuiFramebufferSizeFunction tuiInstanceSetFramebufferSizeCallback(TuiInstance instance, tuiFramebufferSizeFunction callback)
{
	return (tuiFramebufferSizeFunction)glfwSetFramebufferSizeCallback(instance->window, callback);
}

tuiWindowContentScaleFunction tuiInstanceSetWindowContentScaleCallback(TuiInstance instance, tuiWindowContentScaleFunction callback)
{
	return (tuiWindowContentScaleFunction)glfwSetWindowContentScaleCallback(instance->window, callback);
}

tuiKeyFunction tuiInstanceSetKeyCallback(TuiInstance instance, tuiKeyFunction callback)
{
	return (tuiKeyFunction)glfwSetKeyCallback(instance->window, callback);
}

tuiCharFunction tuiInstanceSetCharCallback(TuiInstance instance, tuiCharFunction callback)
{
	return (tuiCharFunction)glfwSetCharCallback(instance->window, callback);
}

tuiMouseButtonFunction tuiInstanceSetMouseButtonCallback(TuiInstance instance, tuiMouseButtonFunction callback)
{
	return (tuiMouseButtonFunction)glfwSetMouseButtonCallback(instance->window, callback);
}

tuiCursorPosFunction tuiInstanceSetCursorPosCallback(TuiInstance instance, tuiCursorPosFunction callback)
{
	return (tuiCursorPosFunction)glfwSetCursorPosCallback(instance->window, callback);
}

tuiCursorEnterFunction tuiInstanceSetCursorEnterCallback(TuiInstance instance, tuiCursorEnterFunction callback)
{
	return (tuiCursorEnterFunction)glfwSetCursorEnterCallback(instance->window, callback);
}

tuiScrollFunction tuiInstanceSetScrollCallback(TuiInstance instance, tuiScrollFunction callback)
{
	return (tuiScrollFunction)glfwSetScrollCallback(instance->window, callback);
}

tuiDropFunction tuiInstanceSetDropCallback(TuiInstance instance, tuiDropFunction callback)
{
	return (tuiDropFunction)glfwSetDropCallback(instance->window, callback);
}
