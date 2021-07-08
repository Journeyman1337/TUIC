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
	glfwSetWindowUserPointer(window, instance);
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

inline static void _InstanceFramebufferResize(TuiInstance instance, int pixel_width, int pixel_height)
{
	if (pixel_width == instance->PixelWidth && pixel_height == instance->PixelHeight)
	{
		return;
	}
	instance->PixelWidth = (size_t)pixel_width;
	instance->PixelHeight = (size_t)pixel_height;
	tuiInstanceResizeScreen_Opengl33(instance, pixel_width, pixel_height);
}

void tuiInstanceResize(TuiInstance instance, int pixel_width, int pixel_height)
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
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_INSTANCE_DIMENSIONS, __func__);
		return;
	}

	glfwSetWindowSize(instance->window, pixel_width, pixel_height);
	_InstanceFramebufferResize(instance, pixel_width, pixel_height);
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

void tuiInstanceDrawBatch(TuiInstance instance, TuiAtlas atlas, TuiPalette palette, TuiBatch batch)
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

void tuiInstanceDrawBatchData(TuiInstance instance, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data)
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

void tuiInstanceDrawBatchTransformed(TuiInstance instance, TuiAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y)
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

void tuiInstanceDrawBatchDataTransformed(TuiInstance instance, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y)
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

void tuiInstanceSetWindowDefaultIcon(TuiInstance instance)
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

	glfwSetWindowIcon(instance->window, 0, NULL);
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
	opacity = (opacity > 1.0f) ? 1.0f : (opacity < 0.0f) ? 0.0f : opacity;

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


TuiBoolean tuiInstanceWindowShouldClose(TuiInstance instance)
{
	if (glfwWindowShouldClose(instance->window) == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
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

static int mini(int x, int y)
{
	return x < y ? x : y;
}

static int maxi(int x, int y)
{
	return x > y ? x : y;
}

//taken from https://stackoverflow.com/a/31526753
static inline TuiMonitor _GetCurrentMonitor(GLFWwindow* window)
{
	GLFWmonitor* monitor = glfwGetWindowMonitor(window);
	if (monitor != NULL)
	{
		return (TuiMonitor)monitor;
	}

	int nmonitors, i;
	int wx, wy, ww, wh;
	int mx, my, mw, mh;
	int overlap, bestoverlap;

	GLFWmonitor** monitors;
	const GLFWvidmode* mode;

	bestoverlap = 0;

	glfwGetWindowPos(window, &wx, &wy);
	glfwGetWindowSize(window, &ww, &wh);
	monitors = glfwGetMonitors(&nmonitors);

	for (i = 0; i < nmonitors; i++) {
		mode = glfwGetVideoMode(monitors[i]);
		glfwGetMonitorPos(monitors[i], &mx, &my);
		mw = mode->width;
		mh = mode->height;

		overlap =
			maxi(0, mini(wx + ww, mx + mw) - maxi(wx, mx)) *
			maxi(0, mini(wy + wh, my + mh) - maxi(wy, my));

		if (bestoverlap < overlap) {
			bestoverlap = overlap;
			monitor = monitors[i];
		}
	}

	return (TuiMonitor)monitor;
}

TuiMonitor tuiInstanceGetWindowMonitor(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return NULL;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return NULL;
	}
	return _GetCurrentMonitor(instance->window);
}

void tuiInstanceSetWindowFullscreen(TuiInstance instance, TuiMonitor monitor, int refresh_rate)
{
	if (monitor == NULL)
	{
		monitor = _GetCurrentMonitor(instance->window);
	}
	glfwSetWindowMonitor(instance->window, monitor, 0, 0, instance->PixelWidth, instance->PixelHeight, refresh_rate);
}

void tuiInstanceSetWindowFullscreenResize(TuiInstance instance, TuiMonitor monitor, int refresh_rate, int pixel_width, int pixel_height)
{
	if (monitor == NULL)
	{
		monitor = _GetCurrentMonitor(instance->window);
	}
	glfwSetWindowMonitor(instance->window, monitor, 0, 0, pixel_width, pixel_height, refresh_rate);
	_InstanceFramebufferResize(instance, pixel_width, pixel_height);
}

void tuiInstanceSetWindowWindowed(TuiInstance instance, int xpos, int ypos)
{
	glfwSetWindowMonitor(instance->window, NULL, xpos, ypos, instance->PixelWidth, instance->PixelHeight, GLFW_DONT_CARE);
}

void tuiInstanceSetWindowWindowedResize(TuiInstance instance, int xpos, int ypos, int pixel_width, int pixel_height)
{
	glfwSetWindowMonitor(instance->window, NULL, xpos, ypos, pixel_width, pixel_height, GLFW_DONT_CARE);
	_InstanceFramebufferResize(instance, pixel_width, pixel_height);
}

TuiBoolean tuiInstanceWindowIsFullscreen(TuiInstance instance)
{
	if (glfwGetWindowMonitor(instance->window) == NULL)
	{
		return TUI_FALSE;
	}
	return TUI_TRUE;
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

static tuiWindowPosFunction sWindowPosCallback = NULL;

static inline void glfwWindowPosCallback(GLFWwindow* window, int xpos, int ypos)
{
	sWindowPosCallback((TuiInstance)glfwGetWindowUserPointer(window), xpos, ypos);
}

tuiWindowPosFunction tuiInstanceSetWindowPosCallback(TuiInstance instance, tuiWindowPosFunction callback)
{
	tuiWindowPosFunction old_callback = sWindowPosCallback;
	sWindowPosCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowPosCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowPosCallback(instance->window, glfwWindowPosCallback);
	}
	return old_callback;
}

static tuiWindowSizeFunction sWindowSizeCallback = NULL;

static inline void glfwWindowSizeCallback(GLFWwindow* window, int width, int height)
{
	sWindowSizeCallback((TuiInstance)glfwGetWindowUserPointer(window), width, width);
}

tuiWindowSizeFunction tuiInstanceSetWindowSizeCallback(TuiInstance instance, tuiWindowSizeFunction callback)
{
	tuiWindowSizeFunction old_callback = sWindowSizeCallback;
	sWindowSizeCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowSizeCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowSizeCallback(instance->window, glfwWindowSizeCallback);
	}
	return old_callback;
}

static tuiWindowCloseFunction sWindowCloseCallback = NULL;

static inline void glfwWindowCloseCallback(GLFWwindow* window)
{
	sWindowCloseCallback((TuiInstance)glfwGetWindowUserPointer(window));
}

tuiWindowCloseFunction tuiInstanceSetWindowCloseCallback(TuiInstance instance, tuiWindowCloseFunction callback)
{
	tuiWindowCloseFunction old_callback = sWindowCloseCallback;
	sWindowCloseCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowCloseCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowCloseCallback(instance->window, glfwWindowCloseCallback);
	}
	return old_callback;
}

static tuiWindowRefreshFunction sWindowRefreshCallback = NULL;

static inline void glfwWindowRefreshCallback(GLFWwindow* window)
{
	sWindowRefreshCallback((TuiInstance)glfwGetWindowUserPointer(window));
}

tuiWindowRefreshFunction tuiInstanceSetWindowRefreshCallback(TuiInstance instance, tuiWindowRefreshFunction callback)
{
	tuiWindowRefreshFunction old_callback = sWindowRefreshCallback;
	sWindowRefreshCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowRefreshCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowRefreshCallback(instance->window, glfwWindowRefreshCallback);
	}
	return old_callback;
}

static tuiWindowFocusFunction sWindowFocusCallback = NULL;

static inline void glfwWindowFocusCallback(GLFWwindow* window, int focused)
{
	sWindowFocusCallback((TuiInstance)glfwGetWindowUserPointer(window),(TuiBoolean)focused);
} 

tuiWindowFocusFunction tuiInstanceSetWindowFocusCallback(TuiInstance instance, tuiWindowFocusFunction callback)
{
	tuiWindowRefreshFunction old_callback = sWindowFocusCallback;
	sWindowFocusCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowFocusCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowFocusCallback(instance->window, glfwWindowFocusCallback);
	}
	return old_callback;
}

static tuiWindowIconifyFunction sWindowIconifyCallback = NULL;

static inline void glfwWindowIconifyCallback(GLFWwindow* window, int iconified)
{
	sWindowIconifyCallback((TuiInstance)glfwGetWindowUserPointer(window), (TuiBoolean)iconified);
}

tuiWindowIconifyFunction tuiInstanceSetWindowIconifyCallback(TuiInstance instance, tuiWindowIconifyFunction callback)
{
	tuiWindowIconifyFunction old_callback = sWindowIconifyCallback;
	sWindowIconifyCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowIconifyCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowIconifyCallback(instance->window, glfwWindowIconifyCallback);
	}
	return old_callback;
}

static tuiWindowMaximizeFunction sWindowMaximizeCallback = NULL;

static inline void glfwWindowMaximizeCallback(GLFWwindow* window, int maximized)
{
	sWindowMaximizeCallback((TuiInstance)glfwGetWindowUserPointer(window), (TuiBoolean)maximized);
}

tuiWindowMaximizeFunction tuiInstanceSetWindowMaximizeCallback(TuiInstance instance, tuiWindowMaximizeFunction callback)
{ 
	tuiWindowMaximizeFunction old_callback = sWindowMaximizeCallback;
	sWindowMaximizeCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowMaximizeCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowMaximizeCallback(instance->window, glfwWindowMaximizeCallback);
	}
	return old_callback;
}

static tuiWindowFramebufferSizeFunction sWindowFramebufferSizeCallback = NULL;

static inline void glfwWindowFramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	sWindowFramebufferSizeCallback((TuiInstance)glfwGetWindowUserPointer(window), width, height);
}

tuiWindowFramebufferSizeFunction tuiInstanceSetFramebufferSizeCallback(TuiInstance instance, tuiWindowFramebufferSizeFunction callback)
{
	tuiWindowFramebufferSizeFunction old_callback = sWindowFramebufferSizeCallback;
	sWindowFramebufferSizeCallback = callback;
	if (callback == NULL)
	{
		glfwSetFramebufferSizeCallback(instance->window, NULL);
	}
	else
	{
		glfwSetFramebufferSizeCallback(instance->window, glfwWindowFramebufferSizeCallback);
	}
	return old_callback;
}

static tuiWindowContentScaleFunction sWindowContentScaleCallback = NULL;

static inline void glfwWindowContentScaleCallback(GLFWwindow* window, int pixel_width, int pixel_height)
{
	sWindowContentScaleCallback((TuiInstance)glfwGetWindowUserPointer(window), pixel_width, pixel_height);
}

tuiWindowContentScaleFunction tuiInstanceSetWindowContentScaleCallback(TuiInstance instance, tuiWindowContentScaleFunction callback)
{
	tuiWindowContentScaleFunction old_callback = sWindowContentScaleCallback;
	sWindowContentScaleCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowContentScaleCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowContentScaleCallback(instance->window, glfwWindowContentScaleCallback);
	}
	return old_callback;
}

static tuiKeyFunction sKeyCallback = NULL;

static inline void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int button_state, int key_mod)
{
	sKeyCallback((TuiInstance)glfwGetWindowUserPointer(window), (TuiKey)key, scancode, (TuiButtonState)button_state, (TuiKeyMod)key_mod);
}

tuiKeyFunction tuiInstanceSetKeyCallback(TuiInstance instance, tuiKeyFunction callback)
{
	tuiKeyFunction old_callback = sKeyCallback;
	sKeyCallback = callback;
	if (callback == NULL)
	{
		glfwSetKeyCallback(instance->window, NULL);
	}
	else
	{
		glfwSetKeyCallback(instance->window, glfwKeyCallback);
	}
	return old_callback;
}

static tuiCharFunction sCharCallback = NULL;

static inline void glfwCharCallback(GLFWwindow* window, unsigned int charcode)
{
	sCharCallback((TuiInstance)glfwGetWindowUserPointer(window), charcode);
}

tuiCharFunction tuiInstanceSetCharCallback(TuiInstance instance, tuiCharFunction callback)
{
	tuiCharFunction old_callback = sCharCallback;
	sCharCallback = callback;
	if (callback == NULL)
	{
		glfwSetCharCallback(instance->window, NULL);
	}
	else
	{
		glfwSetCharCallback(instance->window, glfwCharCallback);
	}
	return old_callback;
}

static tuiMouseButtonFunction sMouseButtonCallback = NULL;

static inline void glfwMouseButtonCallback(GLFWwindow* window, int mouse_button, int button_state, int mod)
{
	sMouseButtonCallback((TuiInstance)glfwGetWindowUserPointer(window), (TuiMouseButton)mouse_button, (TuiButtonState)button_state, (TuiKeyMod)mod);
}

tuiMouseButtonFunction tuiInstanceSetMouseButtonCallback(TuiInstance instance, tuiMouseButtonFunction callback)
{
	tuiMouseButtonFunction old_callback = sMouseButtonCallback;
	sMouseButtonCallback = callback;
	if (callback == NULL)
	{
		glfwSetMouseButtonCallback(instance->window, NULL);
	}
	else
	{
		glfwSetMouseButtonCallback(instance->window, glfwMouseButtonCallback);
	}
	return old_callback;
}

static tuiCursorPosFunction sCursorPosCallback = NULL;

static inline void glfwCursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	sCursorPosCallback((TuiInstance)glfwGetWindowUserPointer(window), xpos, ypos);
}

tuiCursorPosFunction tuiInstanceSetCursorPosCallback(TuiInstance instance, tuiCursorPosFunction callback)
{
	tuiCursorPosFunction old_callback = sCursorPosCallback;
	sCursorPosCallback = callback;
	if (callback == NULL)
	{
		glfwSetCursorPosCallback(instance->window, NULL);
	}
	else
	{
		glfwSetCursorPosCallback(instance->window, glfwCursorPosCallback);
	}
	return old_callback;
}

static tuiCursorEnterFunction sCursorEnterCallback = NULL;

static inline void glfwCursorEnterCallback(GLFWwindow* window, int entered)
{
	sCursorEnterCallback((TuiInstance)glfwGetWindowUserPointer(window), entered);
}

tuiCursorEnterFunction tuiInstanceSetCursorEnterCallback(TuiInstance instance, tuiCursorEnterFunction callback)
{
	tuiCursorEnterFunction old_callback = sCursorEnterCallback;
	sCursorEnterCallback = callback;
	if (callback == NULL)
	{
		glfwCursorEnterCallback(instance->window, NULL);
	}
	else
	{
		glfwCursorEnterCallback(instance->window, glfwCursorEnterCallback);
	}
	return old_callback;
}

static tuiScrollFunction sScrollCallback = NULL;

static inline void glfwCursorScrollCallback(GLFWwindow* window, double xscroll, double yscroll)
{
	sScrollCallback((TuiInstance)glfwGetWindowUserPointer(window), xscroll, yscroll);
}

tuiScrollFunction tuiInstanceSetScrollCallback(TuiInstance instance, tuiScrollFunction callback)
{
	tuiScrollFunction old_callback = sScrollCallback;
	sScrollCallback = callback;
	if (callback == NULL)
	{
		glfwSetScrollCallback(instance->window, NULL);
	}
	else
	{
		glfwSetScrollCallback(instance->window, glfwCursorScrollCallback);
	}
	return old_callback;
}

static tuiDropFunction sDropCallback = NULL;

static inline void glfwDropCallback(GLFWwindow* window, int path_count, const char* paths[])
{
	sDropCallback((TuiInstance)glfwGetWindowUserPointer(window), path_count, paths);
}

tuiDropFunction tuiInstanceSetDropCallback(TuiInstance instance, tuiDropFunction callback)
{
	tuiDropFunction old_callback = sDropCallback;
	sDropCallback = callback;
	if (callback == NULL)
	{
		glfwSetDropCallback(instance->window, NULL);
	}
	else
	{
		glfwSetDropCallback(instance->window, glfwDropCallback);
	}
	return old_callback;
}
