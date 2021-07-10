#include <TUIC/tuic.h>
#include "objects.h"
#include <GLFW/glfw3.h>
#include "opengl33.h"
#include "glfw_error_check.h"

static void glfwWindowPosCallback(GLFWwindow* window, int xpos, int ypos)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->WindowMoveCallback(instance, xpos, ypos);
}

static void glfwWindowCloseCallback(GLFWwindow* window)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->WindowCloseCallback(instance);
}

static void glfwWindowRefreshCallback(GLFWwindow* window)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	if (instance->WindowRefreshCallback != NULL)
	{
		instance->WindowRefreshCallback(instance);
	}
}

static void glfwWindowFocusCallback(GLFWwindow* window, int focused)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->WindowFocusCallback(instance, (TuiBoolean)focused);
}

static void glfwWindowIconifyCallback(GLFWwindow* window, int iconified)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->WindowIconifyCallback(instance, (TuiBoolean)iconified);
}

static void glfwWindowMaximizeCallback(GLFWwindow* window, int maximized)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->WindowMaximizeCallback(instance, (TuiBoolean)maximized);
}

static void glfwWindowFramebufferSizeCallback(GLFWwindow* window, int pixel_width, int pixel_height)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->WindowResizeCallback(instance, pixel_width, pixel_height);
}

static void glfwWindowContentScaleCallback(GLFWwindow* window, int pixel_width, int pixel_height)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->WindowContentScaleCallback(instance, pixel_width, pixel_height);
}

static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int button_state, int key_mod)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->KeyboardKeyCallback(instance, (TuiKey)key, scancode, (TuiButtonState)button_state, (TuiKeyMod)key_mod);
}

static void glfwCharCallback(GLFWwindow* window, unsigned int charcode)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->CharCallback(instance, charcode);
}

static void glfwMouseButtonCallback(GLFWwindow* window, int mouse_button, int button_state, int key_mod)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->MouseButtonCallback(instance, (TuiMouseButton)mouse_button, (TuiButtonState)button_state, (TuiKeyMod)key_mod);
}

static void glfwCursorMoveCallback(GLFWwindow* window, double xpos, double ypos)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->CursorMoveCallback(instance, xpos, ypos);
}

static void glfwCursorEnterCallback(GLFWwindow* window, int entered)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->CursorEnterCallback(instance, (TuiBoolean)entered);
}

static void glfwScrollCallback(GLFWwindow* window, double xscroll, double yscroll)
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->MouseScrollCallback(instance, xscroll, yscroll);
}

static void glfwDropCallback(GLFWwindow* window, int path_count, const char* paths[])
{
	TuiInstance instance = (TuiInstance)glfwGetWindowUserPointer(window);
	instance->FileDropCallback(instance, path_count, paths);
}


static size_t sInstanceCount = 0;

TuiInstance tuiInstanceCreateWindow(int pixel_width, int pixel_height, const char* title, TuiWindowCreateInfo* create_info)
{
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_INSTANCE_DIMENSIONS, __func__);
		return;
	}


	glfwDefaultWindowHints();
	GLFW_CHECK_ERROR_RETURN(NULL)
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
		glfwWindowHint(GLFW_FLOATING, create_info->topmost);
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
	GLFW_CHECK_ERROR_RETURN(NULL)
	GLFWwindow* window = glfwCreateWindow(pixel_width, pixel_height, title, NULL, NULL);
	GLFW_CHECK_ERROR_RETURN(NULL)
	

	TuiInstance instance = (TuiInstance_s*)tuiAllocate(sizeof(TuiInstance_s));
	instance->PanelCount = 0;
	instance->PixelWidth = (size_t)pixel_width;
	instance->PixelHeight = (size_t)pixel_height;
	instance->AtlasCount = 0;
	instance->PaletteCount = 0;
	instance->IsDamaged = TUI_FALSE;
	instance->window = window;
	instance->UserPointer = NULL;
	instance->WindowMoveCallback = NULL;
	instance->WindowRefreshCallback = NULL;
	instance->WindowFocusCallback = NULL;
	instance->WindowIconifyCallback = NULL;
	instance->WindowMaximizeCallback = NULL;
	instance->WindowResizeCallback = NULL;
	instance->WindowContentScaleCallback = NULL;
	instance->MouseButtonCallback = NULL;
	instance->CursorMoveCallback = NULL;
	instance->CursorEnterCallback = NULL;
	instance->MouseScrollCallback = NULL;
	instance->KeyboardKeyCallback = NULL;
	instance->CharCallback = NULL;
	instance->FileDropCallback = NULL;
	glfwSetWindowUserPointer(window, instance);
	glfwMakeContextCurrent(window);
	tuiInstanceCreate_Opengl33(instance, ((void*)glfwGetProcAddress));
	glfwSetWindowRefreshCallback(window, glfwWindowRefreshCallback);
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
	info.topmost = TUI_FALSE;
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
	if (instance->AtlasCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_ATLAS, __func__);
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
	GLFW_CHECK_ERROR()
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
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
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
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
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

	glfwSwapBuffers(instance->window);
	GLFW_CHECK_ERROR()
}

void tuiInstanceSwapInterval(TuiInstance instance, int interval)
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

	glfwMakeContextCurrent(instance->window);
	glfwSwapInterval(interval);
	GLFW_CHECK_ERROR()
}

const char* tuiInstanceGetClipboardString(TuiInstance instance)
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

	const char* str = glfwGetClipboardString(instance->window);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return str;
}

void tuiInstanceSetClipboardString(TuiInstance instance, const char* string)
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
	if (string == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_STRING, __func__);
		return;
	}

	glfwSetClipboardString(instance->window, string);
	GLFW_CHECK_ERROR()
}

TuiCursorMode tuiInstanceGetCursorMode(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_CURSOR_MODE_INVALID;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_CURSOR_MODE_INVALID;
	}

	TuiCursorMode cursor_mode = (TuiCursorMode)glfwGetInputMode(instance->window, GLFW_CURSOR);
	GLFW_CHECK_ERROR_RETURN(TUI_CURSOR_MODE_INVALID)
	return cursor_mode;
}

void tuiInstanceSetCursorMode(TuiInstance instance, TuiCursorMode cursor_mode)
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
	if (tuiCursorModeIsValid(cursor_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_CURSOR_MODE, __func__);
		return;
	}

	glfwSetInputMode(instance->window, GLFW_CURSOR, (int)cursor_mode);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiInstanceGetStickyKeys(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int sticky_keys = glfwGetInputMode(instance->window, GLFW_STICKY_KEYS);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (sticky_keys == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetStickyKeys(TuiInstance instance, TuiBoolean sticky_keys_mode)
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

	glfwSetInputMode(instance->window, GLFW_STICKY_KEYS, (int)sticky_keys_mode);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiInstanceGetStickyMouseButtons(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int sticky_mouse_buttons = glfwGetInputMode(instance->window, GLFW_STICKY_MOUSE_BUTTONS);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (sticky_mouse_buttons == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetStickyMouseButtons(TuiInstance instance, TuiBoolean sticky_mouse_buttons)
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

	glfwSetInputMode(instance->window, GLFW_STICKY_MOUSE_BUTTONS, (int)sticky_mouse_buttons);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiInstanceGetLockKeyMods(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int lock_key_mods = glfwGetInputMode(instance->window, GLFW_LOCK_KEY_MODS);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (lock_key_mods == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetLockKeyMods(TuiInstance instance, TuiBoolean lock_key_mods)
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

	glfwSetInputMode(instance->window, GLFW_LOCK_KEY_MODS, (int)lock_key_mods);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiInstanceGetRawMouseMotion(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int raw_mouse_motion = glfwGetInputMode(instance->window, GLFW_RAW_MOUSE_MOTION);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (raw_mouse_motion == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetRawMouseMotion(TuiInstance instance, TuiBoolean raw_mouse_motion)
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
	if (glfwRawMouseMotionSupported() == GLFW_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION, __func__);
		return;
	}

	glfwSetInputMode(instance->window, GLFW_RAW_MOUSE_MOTION, (int)raw_mouse_motion);
	GLFW_CHECK_ERROR()
}

TuiButtonState tuiInstanceGetKey(TuiInstance instance, TuiKey key)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_BUTTON_INVALID;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_BUTTON_INVALID;
	}
	if (tuiKeyIsValid(key) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_KEY, __func__);
		return TUI_BUTTON_INVALID;
	}
	
	TuiButtonState button_state = (TuiButtonState)glfwGetKey(instance->window, key);
	GLFW_CHECK_ERROR_RETURN(TUI_BUTTON_INVALID)
	return button_state;
}

TuiButtonState tuiInstanceGetMouseButton(TuiInstance instance, TuiMouseButton mouse_button)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_BUTTON_INVALID;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_BUTTON_INVALID;
	}
	if (tuiMouseButtonIsValid(mouse_button) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_MOUSE_BUTTON, __func__);
		return TUI_BUTTON_INVALID;
	}

	TuiButtonState button_state = (TuiButtonState)glfwGetMouseButton(instance->window, mouse_button);
	GLFW_CHECK_ERROR_RETURN(TUI_BUTTON_INVALID);
	return button_state;
}

void tuiInstanceGetCursorPos(TuiInstance instance, double* xpos, double* ypos)
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

	glfwGetCursorPos(instance->window, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiInstanceSetCursorPos(TuiInstance instance, double xpos, double ypos)
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

	glfwSetCursorPos(instance->window, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiInstanceSetWindowTitle(TuiInstance instance, const char* title)
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
	if (title == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_STRING, __func__);
		return;
	}

	glfwSetWindowTitle(instance->window, title);
	GLFW_CHECK_ERROR()
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
	GLFW_CHECK_ERROR()
}

void tuiInstanceSetWindowIcon(TuiInstance instance, int count, const TuiImage* images)
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

	// TODO glfwSetWindowIcon(instance->window, count, );
}

void tuiInstanceGetWindowPos(TuiInstance instance, int* xpos, int* ypos)
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

	glfwGetWindowPos(instance->window, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiInstanceSetWindowPos(TuiInstance instance, int xpos, int ypos)
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

	glfwSetWindowPos(instance->window, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiInstanceSetWindowSizeLimits(TuiInstance instance, int minwidth, int minheight, int maxwidth, int maxheight)
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
	if (minwidth <= 0 || minheight <= 0 || maxwidth <= 0 || maxheight <= 0 || maxwidth < minwidth || maxheight < minheight)
	{
		tuiDebugError(TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS, __func__);
		return;
	}

	glfwSetWindowSizeLimits(instance->window, minwidth, minheight, maxwidth, maxheight);
	GLFW_CHECK_ERROR()
}

void tuiInstanceEnableWindowFixedAspectRatio(TuiInstance instance, int numer, int denom)
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
	if (numer <= 0 || denom <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_ASPECT_RATIO, __func__);
		return;
	}

	glfwSetWindowAspectRatio(instance->window, numer, denom);
	GLFW_CHECK_ERROR()
}

void tuiInstanceDisableWindowFixedAspectRatio(TuiInstance instance)
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

	glfwSetWindowAspectRatio(instance->window, GLFW_DONT_CARE, GLFW_DONT_CARE);
	GLFW_CHECK_ERROR()
}

void tuiInstanceGetWindowContentScale(TuiInstance instance, float* xscale, float* yscale)
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

	glfwGetWindowContentScale(instance->window, xscale, yscale);
	GLFW_CHECK_ERROR()
}

float tuiInstanceGetWindowOpacity(TuiInstance instance)
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

	float opacity = glfwGetWindowOpacity(instance->window);
	GLFW_CHECK_ERROR_RETURN(-1.0f)
	return opacity;
}

void tuiInstanceSetWindowOpacity(TuiInstance instance, float opacity)
{
	opacity = (opacity > 1.0f) ? 1.0f : (opacity < 0.0f) ? 0.0f : opacity;

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
	if (opacity != 1.0f && glfwGetWindowAttrib(instance->window, GLFW_TRANSPARENT_FRAMEBUFFER) == GLFW_TRUE)
	{
		tuiDebugError(TUI_ERROR_INVALID_TRANSPARENT_FRAMEBUFFER_OPACITY, __func__);
		return;
	}
	GLFW_CHECK_ERROR()
	glfwSetWindowOpacity(instance->window, opacity);
	GLFW_CHECK_ERROR()
}

void tuiInstanceIconifyWindow(TuiInstance instance)
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

	glfwIconifyWindow(instance->window);
	GLFW_CHECK_ERROR()
}

void tuiInstanceRestoreWindow(TuiInstance instance)
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

	glfwRestoreWindow(instance->window);
	GLFW_CHECK_ERROR()
}


TuiBoolean tuiInstanceWindowShouldClose(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int should_close = glfwWindowShouldClose(instance->window);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (should_close == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetWindowShouldClose(TuiInstance instance, TuiBoolean should_close)
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

	glfwSetWindowShouldClose(instance->window, should_close);
	GLFW_CHECK_ERROR()
}

void tuiInstanceMaximizeWindow(TuiInstance instance)
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

	glfwMaximizeWindow(instance->window);
	GLFW_CHECK_ERROR()
}

void tuiInstanceShowWindow(TuiInstance instance)
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

	glfwShowWindow(instance->window);
	GLFW_CHECK_ERROR()
}

void tuiInstanceHideWindow(TuiInstance instance)
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

	glfwHideWindow(instance->window);
	GLFW_CHECK_ERROR()
}

void tuiInstanceFocusWindow(TuiInstance instance)
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
	glfwFocusWindow(instance->window);
	GLFW_CHECK_ERROR()
}

void tuiInstanceRequestWindowAttention(TuiInstance instance)
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
	glfwRequestWindowAttention(instance->window);
	GLFW_CHECK_ERROR()
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
	TuiMonitor monitor = _GetCurrentMonitor(instance->window);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return monitor;
}

void tuiInstanceSetWindowFullscreen(TuiInstance instance, TuiMonitor monitor, int refresh_rate)
{
	if (monitor == NULL)
	{
		monitor = _GetCurrentMonitor(instance->window);
	}
	glfwSetWindowMonitor(instance->window, monitor, 0, 0, instance->PixelWidth, instance->PixelHeight, refresh_rate);
	GLFW_CHECK_ERROR()
}

void tuiInstanceSetWindowFullscreenResize(TuiInstance instance, TuiMonitor monitor, int refresh_rate, int pixel_width, int pixel_height)
{
	if (monitor == NULL)
	{
		monitor = _GetCurrentMonitor(instance->window);
		GLFW_CHECK_ERROR()
	}
	glfwSetWindowMonitor(instance->window, monitor, 0, 0, pixel_width, pixel_height, refresh_rate);
	GLFW_CHECK_ERROR()
	_InstanceFramebufferResize(instance, pixel_width, pixel_height);
}

void tuiInstanceSetWindowWindowed(TuiInstance instance, int xpos, int ypos)
{
	glfwSetWindowMonitor(instance->window, NULL, xpos, ypos, instance->PixelWidth, instance->PixelHeight, GLFW_DONT_CARE);
	GLFW_CHECK_ERROR()
}

void tuiInstanceSetWindowWindowedResize(TuiInstance instance, int xpos, int ypos, int pixel_width, int pixel_height)
{
	glfwSetWindowMonitor(instance->window, NULL, xpos, ypos, pixel_width, pixel_height, GLFW_DONT_CARE);
	GLFW_CHECK_ERROR()
	_InstanceFramebufferResize(instance, pixel_width, pixel_height);
}

TuiBoolean tuiInstanceWindowIsFullscreen(TuiInstance instance)
{
	TuiMonitor monitor = glfwGetWindowMonitor(instance->window);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (monitor == NULL)
	{
		return TUI_FALSE;
	}
	return TUI_TRUE;
}

TuiBoolean tuiInstanceGetWindowFocused(TuiInstance instance)
{ 
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int focused = glfwGetWindowAttrib(instance->window, GLFW_FOCUSED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (focused == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiInstanceGetWindowIconified(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int iconified = glfwGetWindowAttrib(instance->window, GLFW_ICONIFIED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (iconified == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiInstanceGetWindowMaximized(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int maximized = glfwGetWindowAttrib(instance->window, GLFW_MAXIMIZED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (maximized == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiInstanceGetWindowMouseEntered(TuiInstance instance)
{ 
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int mouse_entered = glfwGetWindowAttrib(instance->window, GLFW_HOVERED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (mouse_entered == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiInstanceGetWindowVisible(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int visible = glfwGetWindowAttrib(instance->window, GLFW_VISIBLE);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (visible == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiInstanceGetWindowResizable(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int resizable = glfwGetWindowAttrib(instance->window, GLFW_RESIZABLE);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (resizable == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetWindowResizable(TuiInstance instance, TuiBoolean resizable)
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

	glfwSetWindowAttrib(instance->window, GLFW_RESIZABLE, (int)resizable);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiInstanceGetWindowDecorated(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int decorated = glfwGetWindowAttrib(instance->window, GLFW_DECORATED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (decorated == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetWindowDecorated(TuiInstance instance, TuiBoolean decorated)
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

	glfwSetWindowAttrib(instance->window, GLFW_DECORATED, (int)decorated);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiInstanceGetWindowAutoIconify(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int auto_iconify = glfwGetWindowAttrib(instance->window, GLFW_AUTO_ICONIFY);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (auto_iconify == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetWindowAutoIconify(TuiInstance instance, TuiBoolean auto_iconify)
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

	glfwSetWindowAttrib(instance->window, GLFW_AUTO_ICONIFY, (int)auto_iconify);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiInstanceGetWindowTopmost(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int topmost =glfwGetWindowAttrib(instance->window, GLFW_FLOATING);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (topmost == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetWindowTopmost(TuiInstance instance, TuiBoolean topmost)
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

	glfwSetWindowAttrib(instance->window, GLFW_FLOATING, (int)topmost);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiInstanceGetWindowTransparentFramebuffer(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int transparent_framebuffer = glfwGetWindowAttrib(instance->window, GLFW_TRANSPARENT_FRAMEBUFFER);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (transparent_framebuffer == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiInstanceGetWindowFocusOnShow(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return TUI_FALSE;
	}

	int focus_on_show = glfwGetWindowAttrib(instance->window, GLFW_FOCUS_ON_SHOW);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (focus_on_show == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiInstanceSetWindowFocusOnShow(TuiInstance instance, TuiBoolean focus_on_show)
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

	glfwSetWindowAttrib(instance->window, GLFW_FOCUS_ON_SHOW, (int)focus_on_show);
	GLFW_CHECK_ERROR()
}

void tuiInstanceSetUserPointer(TuiInstance instance, void* ptr)
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

	instance->UserPointer = ptr;
}

void* tuiInstanceGetUserPointer(TuiInstance instance)
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

	return instance->UserPointer;
}

void tuiInstanceSetCursor(TuiInstance instance, TuiCursor cursor)
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

	glfwSetCursor(instance->window, cursor);
	GLFW_CHECK_ERROR()
}

tuiWindowMoveFunction tuiInstanceSetWindowMoveCallback(TuiInstance instance, tuiWindowMoveFunction callback)
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

	tuiWindowMoveFunction old_callback = instance->WindowMoveCallback;
	instance->WindowMoveCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowPosCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowPosCallback(instance->window, glfwWindowPosCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowCloseFunction tuiInstanceSetWindowCloseCallback(TuiInstance instance, tuiWindowCloseFunction callback)
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

	tuiWindowCloseFunction old_callback = instance->WindowCloseCallback;
	instance->WindowCloseCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowCloseCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowCloseCallback(instance->window, glfwWindowCloseCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowRefreshFunction tuiInstanceSetWindowRefreshCallback(TuiInstance instance, tuiWindowRefreshFunction callback)
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

	tuiWindowRefreshFunction old_callback = instance->WindowRefreshCallback;
	instance->WindowRefreshCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowRefreshCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowRefreshCallback(instance->window, glfwWindowRefreshCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowFocusFunction tuiInstanceSetWindowFocusCallback(TuiInstance instance, tuiWindowFocusFunction callback)
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

	tuiWindowRefreshFunction old_callback = instance->WindowFocusCallback;
	instance->WindowFocusCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowFocusCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowFocusCallback(instance->window, glfwWindowFocusCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowIconifyFunction tuiInstanceSetWindowIconifyCallback(TuiInstance instance, tuiWindowIconifyFunction callback)
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

	tuiWindowIconifyFunction old_callback = instance->WindowIconifyCallback;
	instance->WindowIconifyCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowIconifyCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowIconifyCallback(instance->window, glfwWindowIconifyCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowMaximizeFunction tuiInstanceSetWindowMaximizeCallback(TuiInstance instance, tuiWindowMaximizeFunction callback)
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

	tuiWindowMaximizeFunction old_callback = instance->WindowMaximizeCallback;
	instance->WindowMaximizeCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowMaximizeCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowMaximizeCallback(instance->window, glfwWindowMaximizeCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowResizeFunction tuiInstanceSetResizeCallback(TuiInstance instance, tuiWindowResizeFunction callback)
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

	tuiWindowResizeFunction old_callback = instance->WindowResizeCallback;
	instance->WindowResizeCallback = callback;
	if (callback == NULL)
	{
		glfwSetFramebufferSizeCallback(instance->window, NULL);
	}
	else
	{
		glfwSetFramebufferSizeCallback(instance->window, glfwWindowFramebufferSizeCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowContentScaleFunction tuiInstanceSetWindowContentScaleCallback(TuiInstance instance, tuiWindowContentScaleFunction callback)
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

	tuiWindowContentScaleFunction old_callback = instance->WindowContentScaleCallback;
	instance->WindowContentScaleCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowContentScaleCallback(instance->window, NULL);
	}
	else
	{
		glfwSetWindowContentScaleCallback(instance->window, glfwWindowContentScaleCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiKeyboardKeyFunction tuiInstanceSetKeyCallback(TuiInstance instance, tuiKeyboardKeyFunction callback)
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

	tuiKeyboardKeyFunction old_callback = instance->KeyboardKeyCallback;
	instance->KeyboardKeyCallback = callback;
	if (callback == NULL)
	{
		glfwSetKeyCallback(instance->window, NULL);
	}
	else
	{
		glfwSetKeyCallback(instance->window, glfwKeyCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiCharFunction tuiInstanceSetCharCallback(TuiInstance instance, tuiCharFunction callback)
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

	tuiCharFunction old_callback = instance->CharCallback;
	instance->CharCallback = callback;
	if (callback == NULL)
	{
		glfwSetCharCallback(instance->window, NULL);
	}
	else
	{
		glfwSetCharCallback(instance->window, glfwCharCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiMouseButtonFunction tuiInstanceSetMouseButtonCallback(TuiInstance instance, tuiMouseButtonFunction callback)
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

	tuiMouseButtonFunction old_callback = instance->MouseButtonCallback;
	instance->MouseButtonCallback = callback;
	if (callback == NULL)
	{
		glfwSetMouseButtonCallback(instance->window, NULL);
	}
	else
	{
		glfwSetMouseButtonCallback(instance->window, glfwMouseButtonCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiCursorMoveFunction tuiInstanceSetCursorMoveCallback(TuiInstance instance, tuiCursorMoveFunction callback)
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

	tuiCursorMoveFunction old_callback = instance->CursorMoveCallback;
	instance->CursorMoveCallback = callback;
	if (callback == NULL)
	{
		glfwSetCursorPosCallback(instance->window, NULL);
	}
	else
	{
		glfwSetCursorPosCallback(instance->window, glfwCursorMoveCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiCursorEnterFunction tuiInstanceSetCursorEnterCallback(TuiInstance instance, tuiCursorEnterFunction callback)
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

	tuiCursorEnterFunction old_callback = instance->CursorEnterCallback;
	instance->CursorEnterCallback = callback;
	if (callback == NULL)
	{
		glfwCursorEnterCallback(instance->window, NULL);
	}
	else
	{
		glfwCursorEnterCallback(instance->window, glfwCursorEnterCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiMouseScrollFunction tuiInstanceSetMouseScrollCallback(TuiInstance instance, tuiMouseScrollFunction callback)
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

	tuiMouseScrollFunction old_callback = instance->MouseScrollCallback;
	instance->MouseScrollCallback = callback;
	if (callback == NULL)
	{
		glfwSetScrollCallback(instance->window, NULL);
	}
	else
	{
		glfwSetScrollCallback(instance->window, glfwScrollCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiFileDropFunction tuiInstanceSetFileDropCallback(TuiInstance instance, tuiFileDropFunction callback)
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

	tuiFileDropFunction old_callback = instance->FileDropCallback;
	instance->FileDropCallback = callback;
	if (callback == NULL)
	{
		glfwSetDropCallback(instance->window, NULL);
	}
	else
	{
		glfwSetDropCallback(instance->window, glfwDropCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}
