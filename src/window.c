#include <TUIC/tuic.h>
#include "objects.h"
#include <GLFW/glfw3.h>
#include "opengl33.h"
#include "glfw_error_check.h"

static void glfwWindowPosCallback(GLFWwindow* glfw_window, int xpos, int ypos)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->WindowMoveCallback(window, xpos, ypos);
}

static void glfwWindowCloseCallback(GLFWwindow* glfw_window)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->WindowCloseCallback(window);
}

static void glfwWindowRefreshCallback(GLFWwindow* glfw_window)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->WindowRefreshCallback(window);
}

static void glfwWindowFocusCallback(GLFWwindow* glfw_window, int focused)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->WindowFocusCallback(window, (TuiBoolean)focused);
}

static void glfwWindowIconifyCallback(GLFWwindow* glfw_window, int iconified)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->WindowIconifyCallback(window, (TuiBoolean)iconified);
}

static void glfwWindowMaximizeCallback(GLFWwindow* glfw_window, int maximized)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->WindowMaximizeCallback(window, (TuiBoolean)maximized);
}

static void glfwWindowFramebufferSizeCallback(GLFWwindow* glfw_window, int pixel_width, int pixel_height)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->WindowResizeCallback(window, pixel_width, pixel_height);
}

static void glfwWindowContentScaleCallback(GLFWwindow* glfw_window, int pixel_width, int pixel_height)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->WindowContentScaleCallback(window, pixel_width, pixel_height);
}

static void glfwKeyCallback(GLFWwindow* glfw_window, int key, int scancode, int button_state, int key_mod)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->KeyboardKeyCallback(window, (TuiKey)key, scancode, (TuiButtonState)button_state, (TuiKeyMod)key_mod);
}

static void glfwCharCallback(GLFWwindow* glfw_window, unsigned int charcode)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->CharCallback(window, charcode);
}

static void glfwMouseButtonCallback(GLFWwindow* glfw_window, int mouse_button, int button_state, int key_mod)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->MouseButtonCallback(window, (TuiMouseButton)mouse_button, (TuiButtonState)button_state, (TuiKeyMod)key_mod);
}

static void glfwCursorMoveCallback(GLFWwindow* glfw_window, double xpos, double ypos)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->CursorMoveCallback(window, xpos, ypos);
}

static void glfwCursorEnterCallback(GLFWwindow* glfw_window, int entered)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->CursorEnterCallback(window, (TuiBoolean)entered);
}

static void glfwScrollCallback(GLFWwindow* glfw_window, double xscroll, double yscroll)
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->MouseScrollCallback(window, xscroll, yscroll);
}

static void glfwDropCallback(GLFWwindow* glfw_window, int path_count, const char* paths[])
{
	TuiWindow window = (TuiWindow)glfwGetWindowUserPointer(glfw_window);
	window->FileDropCallback(window, path_count, paths);
}

static size_t sWindowCount = 0;

TuiWindow tuiWindowCreate(int pixel_width, int pixel_height, const char* title, TuiWindowCreateInfo* create_info)
{
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_WINDOW_DIMENSIONS, __func__);
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
	GLFWwindow* glfw_window = glfwCreateWindow(pixel_width, pixel_height, title, NULL, NULL);
	GLFW_CHECK_ERROR_RETURN(NULL)
	
	TuiWindow window = (TuiWindow_s*)tuiAllocate(sizeof(TuiWindow_s));
	window->PanelCount = 0;
	window->PixelWidth = (size_t)pixel_width;
	window->PixelHeight = (size_t)pixel_height;
	window->AtlasCount = 0;
	window->PaletteCount = 0;
	window->GlfwWindow = glfw_window;
	window->UserPointer = NULL;
	window->WindowMoveCallback = NULL;
	window->WindowRefreshCallback = NULL;
	window->WindowFocusCallback = NULL;
	window->WindowIconifyCallback = NULL;
	window->WindowMaximizeCallback = NULL;
	window->WindowResizeCallback = NULL;
	window->WindowContentScaleCallback = NULL;
	window->MouseButtonCallback = NULL;
	window->CursorMoveCallback = NULL;
	window->CursorEnterCallback = NULL;
	window->MouseScrollCallback = NULL;
	window->KeyboardKeyCallback = NULL;
	window->CharCallback = NULL;
	window->FileDropCallback = NULL;
	glfwSetWindowUserPointer(glfw_window, window);
	glfwMakeContextCurrent(glfw_window);
	tuiWindowCreate_Opengl33(window, ((void*)glfwGetProcAddress));
	sWindowCount++;
	return window;
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

void tuiWindowDestroy(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	int dangling = TUI_FALSE;
	if (window->PanelCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_PANEL, __func__);
		dangling = TUI_TRUE;
	}
	if (window->AtlasCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_ATLAS, __func__);
		dangling = TUI_TRUE;
	}
	if (window->PaletteCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_PALETTE, __func__);
		dangling = TUI_TRUE;
	}
	if (window->TextureCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_TEXTURE, __func__);
		dangling = TUI_TRUE;
	}
	if (dangling == TUI_TRUE)
	{
		return;
	}

	tuiWindowDestroy_Opengl33(window);
	tuiFree(window);
	sWindowCount--;
}

int tuiGetWindowCount()
{
	return sWindowCount;
}

void tuiWindowClearColor(TuiWindow window, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowClearColor_Opengl33(window, r, g, b, a);
}

inline static void _WindowFramebufferResize(TuiWindow window, int pixel_width, int pixel_height)
{
	if (pixel_width == window->PixelWidth && pixel_height == window->PixelHeight)
	{
		return;
	}
	window->PixelWidth = (size_t)pixel_width;
	window->PixelHeight = (size_t)pixel_height;
}

void tuiWindowResize(TuiWindow window, int pixel_width, int pixel_height)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_WINDOW_DIMENSIONS, __func__);
		return;
	}

	glfwSetWindowSize(window->GlfwWindow, pixel_width, pixel_height);
	GLFW_CHECK_ERROR()
	_WindowFramebufferResize(window, pixel_width, pixel_height);
}

int tuiWindowGetPixelWidth(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return 0;
	}

	return (size_t)window->PixelWidth;
}

int tuiWindowGetPixelHeight(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return 0;
	}

	return (size_t)window->PixelHeight;
}

void tuiWindowGetPixelDimensons(TuiWindow window, int* width, int* height)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	if (width != NULL)
	{
		*width = window->PixelWidth;
	}
	if (height != NULL)
	{
		*height = window->PixelHeight;
	}
}

TuiImage tuiWindowGetImage(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return NULL;
	}

	size_t p_width = 0;
	size_t p_height = 0;
	uint8_t* pixel_data = tuiWindowGetPixels_Opengl33(window, &p_width, &p_height, NULL);
	TuiImage image = _CreateImage(p_width, p_height, 4, pixel_data, TUI_FALSE, __func__);
	return image;
}

void tuiWindowWriteImage(TuiWindow window, TuiImage image)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (image == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return;
	}

	image->PixelData = tuiWindowGetPixels_Opengl33(window, &image->PixelWidth, &image->PixelHeight, image->PixelData);
}

uint8_t* tuiWindowGetPixels(TuiWindow window, int* pixel_width, int* pixel_height, uint8_t* fill_pixels)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return NULL;
	}

	size_t o_width, o_height;
	fill_pixels = tuiWindowGetPixels_Opengl33(window, &o_width, &o_height, fill_pixels);
	*pixel_width = (int)o_width;
	*pixel_height = (int)o_height;
	return fill_pixels;
}

void tuiWindowDrawBatch(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiBatch batch)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
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
	if (atlas->Window != window)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_WINDOW, __func__);
		return;
	}
	if (palette != NULL && palette->Window != window)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}

	tuiWindowDrawBatchData_Opengl33(window, atlas, palette, batch->DetailMode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, 0, window->PixelWidth, 0, window->PixelHeight);
}

void tuiWindowDrawBatchData(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
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
	if (atlas->Window != window)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_WINDOW, __func__);
		return;
	}
	if (palette != NULL && palette->Window != window)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}

	tuiWindowDrawBatchData_Opengl33(window, atlas, palette, (size_t)detail_mode, (size_t)tiles_wide, (size_t)tiles_tall, (size_t)sparse_index, batch_data, 0, window->PixelWidth, 0, window->PixelHeight);

}

void tuiWindowDrawBatchTransformed(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
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
	if (atlas->Window != window)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_WINDOW, __func__);
		return;
	}
	if (palette != NULL && palette->Window != window)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}

	tuiWindowDrawBatchData_Opengl33(window, atlas, palette, batch->DetailMode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, left_x, right_x, top_y, bottom_y);
}

void tuiWindowDrawBatchDataTransformed(TuiWindow window, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
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
	if (atlas->Window != window)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_WINDOW, __func__);
		return;
	}
	if (palette != NULL && palette->Window != window)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}

	tuiWindowDrawBatchData_Opengl33(window, atlas, palette, (size_t)detail_mode, (size_t)tiles_wide, (size_t)tiles_tall, sparse_index, batch_data, left_x, right_x, top_y, bottom_y);
}

void tuiWindowDrawPanel(TuiWindow window, TuiPanel panel)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}

	tuiWindowDrawPanel_Opengl33(window, panel, 0, window->PixelWidth, 0, window->PixelHeight);
}

void tuiWindowDrawPanelTransformed(TuiWindow window, TuiPanel panel, int left_x, int right_x, int top_y, int bottom_y)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}

	tuiWindowDrawPanel_Opengl33(window, panel, left_x, right_x, top_y, bottom_y);
}

void tuiWindowDrawTexture(TuiWindow window, TuiTexture texture)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (texture == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}

	tuiWindowDrawTexture_Opengl33(window, texture, 0, window->PixelWidth, 0, window->PixelHeight);
}

void tuiWindowDrawTextureTransformed(TuiWindow window, TuiTexture texture, int left_x, int right_x, int top_y, int bottom_y)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (texture == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}

	tuiWindowDrawTexture_Opengl33(window, texture, left_x, right_x, top_y, bottom_y);
}

void tuiWindowDrawAtlas(TuiWindow window, TuiAtlas atlas)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}

	tuiWindowDrawAtlas_Opengl33(window, atlas, 0, window->PixelWidth, 0, window->PixelHeight);
}

void tuiWindowDrawAtlasTransformed(TuiWindow window, TuiAtlas atlas, int left_x, int right_x, int top_y, int bottom_y)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}

	tuiWindowDrawAtlas_Opengl33(window, atlas, left_x, right_x, top_y, bottom_y);
}

void tuiWindowDrawWindow(TuiWindow window, TuiWindow subject_window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (subject_window == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_SUBJECT_WINDOW, __func__);
		return;
	}

	tuiWindowDrawWindow_Opengl33(window, subject_window, 0, window->PixelWidth, 0, window->PixelHeight);
}

void tuiWindowDrawWindowTransformed(TuiWindow window, TuiWindow subject_window, int left_x, int right_x, int top_y, int bottom_y)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (subject_window == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_SUBJECT_WINDOW, __func__);
		return;
	}

	tuiWindowDrawWindow_Opengl33(window, subject_window, left_x, right_x, top_y, bottom_y);
}

void tuiWindowSwapBuffers(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSwapBuffers(window->GlfwWindow);
	GLFW_CHECK_ERROR()
}

void tuiWindowSwapInterval(TuiWindow window, int interval)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwMakeContextCurrent(window->GlfwWindow);
	glfwSwapInterval(interval);
	GLFW_CHECK_ERROR()
}

const char* tuiWindowGetClipboardString(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return NULL;
	}

	const char* str = glfwGetClipboardString(window->GlfwWindow);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return str;
}

void tuiWindowSetClipboardString(TuiWindow window, const char* string)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (string == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_STRING, __func__);
		return;
	}

	glfwSetClipboardString(window->GlfwWindow, string);
	GLFW_CHECK_ERROR()
}

TuiCursorMode tuiWindowGetCursorMode(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_CURSOR_MODE_INVALID;
	}

	TuiCursorMode cursor_mode = (TuiCursorMode)glfwGetInputMode(window->GlfwWindow, GLFW_CURSOR);
	GLFW_CHECK_ERROR_RETURN(TUI_CURSOR_MODE_INVALID)
	return cursor_mode;
}

void tuiWindowSetCursorMode(TuiWindow window, TuiCursorMode cursor_mode)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (tuiCursorModeIsValid(cursor_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_CURSOR_MODE, __func__);
		return;
	}

	glfwSetInputMode(window->GlfwWindow, GLFW_CURSOR, (int)cursor_mode);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiWindowGetStickyKeys(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int sticky_keys = glfwGetInputMode(window->GlfwWindow, GLFW_STICKY_KEYS);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (sticky_keys == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetStickyKeys(TuiWindow window, TuiBoolean sticky_keys_mode)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetInputMode(window->GlfwWindow, GLFW_STICKY_KEYS, (int)sticky_keys_mode);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiWindowGetStickyMouseButtons(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int sticky_mouse_buttons = glfwGetInputMode(window->GlfwWindow, GLFW_STICKY_MOUSE_BUTTONS);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (sticky_mouse_buttons == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetStickyMouseButtons(TuiWindow window, TuiBoolean sticky_mouse_buttons)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetInputMode(window->GlfwWindow, GLFW_STICKY_MOUSE_BUTTONS, (int)sticky_mouse_buttons);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiWindowGetLockKeyMods(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int lock_key_mods = glfwGetInputMode(window->GlfwWindow, GLFW_LOCK_KEY_MODS);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (lock_key_mods == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetLockKeyMods(TuiWindow window, TuiBoolean lock_key_mods)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetInputMode(window->GlfwWindow, GLFW_LOCK_KEY_MODS, (int)lock_key_mods);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiWindowGetRawMouseMotion(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int raw_mouse_motion = glfwGetInputMode(window->GlfwWindow, GLFW_RAW_MOUSE_MOTION);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (raw_mouse_motion == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetRawMouseMotion(TuiWindow window, TuiBoolean raw_mouse_motion)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (glfwRawMouseMotionSupported() == GLFW_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION, __func__);
		return;
	}

	glfwSetInputMode(window->GlfwWindow, GLFW_RAW_MOUSE_MOTION, (int)raw_mouse_motion);
	GLFW_CHECK_ERROR()
}

TuiButtonState tuiWindowGetKey(TuiWindow window, TuiKey key)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_BUTTON_INVALID;
	}
	if (tuiKeyIsValid(key) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_KEY, __func__);
		return TUI_BUTTON_INVALID;
	}
	
	TuiButtonState button_state = (TuiButtonState)glfwGetKey(window->GlfwWindow, key);
	GLFW_CHECK_ERROR_RETURN(TUI_BUTTON_INVALID)
	return button_state;
}

TuiButtonState tuiWindowGetMouseButton(TuiWindow window, TuiMouseButton mouse_button)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_BUTTON_INVALID;
	}
	if (tuiMouseButtonIsValid(mouse_button) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_MOUSE_BUTTON, __func__);
		return TUI_BUTTON_INVALID;
	}

	TuiButtonState button_state = (TuiButtonState)glfwGetMouseButton(window->GlfwWindow, mouse_button);
	GLFW_CHECK_ERROR_RETURN(TUI_BUTTON_INVALID);
	return button_state;
}

void tuiWindowGetCursorPosition(TuiWindow window, double* xpos, double* ypos)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwGetCursorPos(window->GlfwWindow, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetCursorPosition(TuiWindow window, double xpos, double ypos)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetCursorPos(window->GlfwWindow, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetTitle(TuiWindow window, const char* title)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (title == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_STRING, __func__);
		return;
	}

	glfwSetWindowTitle(window->GlfwWindow, title);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetDefaultIcon(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowIcon(window->GlfwWindow, 0, NULL);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetIcon(TuiWindow window, int count, const TuiImage* images)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	// TODO glfwSetWindowIcon(window->window, count, );
}

void tuiWindowGetPosition(TuiWindow window, int* xpos, int* ypos)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwGetWindowPos(window->GlfwWindow, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetPosition(TuiWindow window, int xpos, int ypos)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowPos(window->GlfwWindow, xpos, ypos);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetSizeLimits(TuiWindow window, int minwidth, int minheight, int maxwidth, int maxheight)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (minwidth <= 0 || minheight <= 0 || maxwidth <= 0 || maxheight <= 0 || maxwidth < minwidth || maxheight < minheight)
	{
		tuiDebugError(TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS, __func__);
		return;
	}

	glfwSetWindowSizeLimits(window->GlfwWindow, minwidth, minheight, maxwidth, maxheight);
	GLFW_CHECK_ERROR()
}

void tuiWindowEnableFixedAspectRatio(TuiWindow window, int numer, int denom)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (numer <= 0 || denom <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_ASPECT_RATIO, __func__);
		return;
	}

	glfwSetWindowAspectRatio(window->GlfwWindow, numer, denom);
	GLFW_CHECK_ERROR()
}

void tuiWindowDisableFixedAspectRatio(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowAspectRatio(window->GlfwWindow, GLFW_DONT_CARE, GLFW_DONT_CARE);
	GLFW_CHECK_ERROR()
}

void tuiWindowGetContentScale(TuiWindow window, float* xscale, float* yscale)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwGetWindowContentScale(window->GlfwWindow, xscale, yscale);
	GLFW_CHECK_ERROR()
}

float tuiWindowGetOpacity(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	float opacity = glfwGetWindowOpacity(window->GlfwWindow);
	GLFW_CHECK_ERROR_RETURN(-1.0f)
	return opacity;
}

void tuiWindowSetOpacity(TuiWindow window, float opacity)
{
	opacity = (opacity > 1.0f) ? 1.0f : (opacity < 0.0f) ? 0.0f : opacity;

	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}
	if (opacity != 1.0f && glfwGetWindowAttrib(window->GlfwWindow, GLFW_TRANSPARENT_FRAMEBUFFER) == GLFW_TRUE)
	{
		tuiDebugError(TUI_ERROR_INVALID_TRANSPARENT_FRAMEBUFFER_OPACITY, __func__);
		return;
	}
	GLFW_CHECK_ERROR()
	glfwSetWindowOpacity(window->GlfwWindow, opacity);
	GLFW_CHECK_ERROR()
}

void tuiWindowIconify(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwIconifyWindow(window->GlfwWindow);
	GLFW_CHECK_ERROR()
}

void tuiWindowRestore(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwRestoreWindow(window->GlfwWindow);
	GLFW_CHECK_ERROR()
}


TuiBoolean tuiWindowShouldClose(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int should_close = glfwWindowShouldClose(window->GlfwWindow);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (should_close == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetShouldClose(TuiWindow window, TuiBoolean should_close)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowShouldClose(window->GlfwWindow, should_close);
	GLFW_CHECK_ERROR()
}

void tuiWindowMaximize(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwMaximizeWindow(window->GlfwWindow);
	GLFW_CHECK_ERROR()
}

void tuiWindowShow(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwShowWindow(window->GlfwWindow);
	GLFW_CHECK_ERROR()
}

void tuiWindowHide(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwHideWindow(window->GlfwWindow);
	GLFW_CHECK_ERROR()
}

void tuiWindowFocus(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwFocusWindow(window->GlfwWindow);
	GLFW_CHECK_ERROR()
}

void tuiWindowRequestAttention(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwRequestWindowAttention(window->GlfwWindow);
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

TuiMonitor tuiWindowGetMonitor(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return NULL;
	}

	TuiMonitor monitor = _GetCurrentMonitor(window->GlfwWindow);
	GLFW_CHECK_ERROR_RETURN(NULL)
	return monitor;
}

void tuiWindowSetFullscreen(TuiWindow window, TuiMonitor monitor, int refresh_rate)
{
	if (monitor == NULL)
	{
		monitor = _GetCurrentMonitor(window->GlfwWindow);
	}
	glfwSetWindowMonitor(window->GlfwWindow, monitor, 0, 0, window->PixelWidth, window->PixelHeight, refresh_rate);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetFullscreenResize(TuiWindow window, TuiMonitor monitor, int refresh_rate, int pixel_width, int pixel_height)
{
	if (monitor == NULL)
	{
		monitor = _GetCurrentMonitor(window->GlfwWindow);
		GLFW_CHECK_ERROR()
	}
	glfwSetWindowMonitor(window->GlfwWindow, monitor, 0, 0, pixel_width, pixel_height, refresh_rate);
	GLFW_CHECK_ERROR()
	_WindowFramebufferResize(window, pixel_width, pixel_height);
}

void tuiWindowSetWindowed(TuiWindow window, int xpos, int ypos)
{
	glfwSetWindowMonitor(window->GlfwWindow, NULL, xpos, ypos, window->PixelWidth, window->PixelHeight, GLFW_DONT_CARE);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetWindowedResize(TuiWindow window, int xpos, int ypos, int pixel_width, int pixel_height)
{
	glfwSetWindowMonitor(window->GlfwWindow, NULL, xpos, ypos, pixel_width, pixel_height, GLFW_DONT_CARE);
	GLFW_CHECK_ERROR()
	_WindowFramebufferResize(window, pixel_width, pixel_height);
}

TuiBoolean tuiWindowIsFullscreen(TuiWindow window)
{
	TuiMonitor monitor = glfwGetWindowMonitor(window->GlfwWindow);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (monitor == NULL)
	{
		return TUI_FALSE;
	}
	return TUI_TRUE;
}

TuiBoolean tuiWindowGetFocused(TuiWindow window)
{ 
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int focused = glfwGetWindowAttrib(window->GlfwWindow, GLFW_FOCUSED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (focused == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiWindowGetIconified(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int iconified = glfwGetWindowAttrib(window->GlfwWindow, GLFW_ICONIFIED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (iconified == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiWindowGetMaximized(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int maximized = glfwGetWindowAttrib(window->GlfwWindow, GLFW_MAXIMIZED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (maximized == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiWindowGetMouseEntered(TuiWindow window)
{ 
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int mouse_entered = glfwGetWindowAttrib(window->GlfwWindow, GLFW_HOVERED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (mouse_entered == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiWindowGetVisible(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int visible = glfwGetWindowAttrib(window->GlfwWindow, GLFW_VISIBLE);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (visible == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiWindowGetResizable(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int resizable = glfwGetWindowAttrib(window->GlfwWindow, GLFW_RESIZABLE);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (resizable == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetResizable(TuiWindow window, TuiBoolean resizable)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowAttrib(window->GlfwWindow, GLFW_RESIZABLE, (int)resizable);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiWindowGetDecorated(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int decorated = glfwGetWindowAttrib(window->GlfwWindow, GLFW_DECORATED);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (decorated == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetDecorated(TuiWindow window, TuiBoolean decorated)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowAttrib(window->GlfwWindow, GLFW_DECORATED, (int)decorated);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiWindowGetAutoIconify(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int auto_iconify = glfwGetWindowAttrib(window->GlfwWindow, GLFW_AUTO_ICONIFY);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (auto_iconify == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetAutoIconify(TuiWindow window, TuiBoolean auto_iconify)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowAttrib(window->GlfwWindow, GLFW_AUTO_ICONIFY, (int)auto_iconify);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiWindowGetTopmost(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int topmost =glfwGetWindowAttrib(window->GlfwWindow, GLFW_FLOATING);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (topmost == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetTopmost(TuiWindow window, TuiBoolean topmost)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowAttrib(window->GlfwWindow, GLFW_FLOATING, (int)topmost);
	GLFW_CHECK_ERROR()
}

TuiBoolean tuiWindowGetTransparentFramebuffer(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int transparent_framebuffer = glfwGetWindowAttrib(window->GlfwWindow, GLFW_TRANSPARENT_FRAMEBUFFER);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (transparent_framebuffer == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

TuiBoolean tuiWindowGetFocusOnShow(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return TUI_FALSE;
	}

	int focus_on_show = glfwGetWindowAttrib(window->GlfwWindow, GLFW_FOCUS_ON_SHOW);
	GLFW_CHECK_ERROR_RETURN(TUI_FALSE)
	if (focus_on_show == GLFW_TRUE)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

void tuiWindowSetFocusOnShow(TuiWindow window, TuiBoolean focus_on_show)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetWindowAttrib(window->GlfwWindow, GLFW_FOCUS_ON_SHOW, (int)focus_on_show);
	GLFW_CHECK_ERROR()
}

void tuiWindowSetUserPointer(TuiWindow window, void* ptr)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	window->UserPointer = ptr;
}

void* tuiWindowGetUserPointer(TuiWindow window)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return NULL;
	}

	return window->UserPointer;
}

void tuiWindowSetCursor(TuiWindow window, TuiCursor cursor)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	glfwSetCursor(window->GlfwWindow, cursor);
	GLFW_CHECK_ERROR()
}

tuiWindowMoveFunction tuiWindowSetMoveCallback(TuiWindow window, tuiWindowMoveFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowMoveFunction old_callback = window->WindowMoveCallback;
	window->WindowMoveCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowPosCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetWindowPosCallback(window->GlfwWindow, glfwWindowPosCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowCloseFunction tuiWindowSetCloseCallback(TuiWindow window, tuiWindowCloseFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowCloseFunction old_callback = window->WindowCloseCallback;
	window->WindowCloseCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowCloseCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetWindowCloseCallback(window->GlfwWindow, glfwWindowCloseCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowRefreshFunction tuiWindowSetRefreshCallback(TuiWindow window, tuiWindowRefreshFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowRefreshFunction old_callback = window->WindowRefreshCallback;
	window->WindowRefreshCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowRefreshCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetWindowRefreshCallback(window->GlfwWindow, glfwWindowRefreshCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowFocusFunction tuiWindowSetFocusCallback(TuiWindow window, tuiWindowFocusFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowRefreshFunction old_callback = window->WindowFocusCallback;
	window->WindowFocusCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowFocusCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetWindowFocusCallback(window->GlfwWindow, glfwWindowFocusCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowIconifyFunction tuiWindowSetIconifyCallback(TuiWindow window, tuiWindowIconifyFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowIconifyFunction old_callback = window->WindowIconifyCallback;
	window->WindowIconifyCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowIconifyCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetWindowIconifyCallback(window->GlfwWindow, glfwWindowIconifyCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowMaximizeFunction tuiWindowSetMaximizeCallback(TuiWindow window, tuiWindowMaximizeFunction callback)
{ 
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowMaximizeFunction old_callback = window->WindowMaximizeCallback;
	window->WindowMaximizeCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowMaximizeCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetWindowMaximizeCallback(window->GlfwWindow, glfwWindowMaximizeCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowResizeFunction tuiWindowSetResizeCallback(TuiWindow window, tuiWindowResizeFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowResizeFunction old_callback = window->WindowResizeCallback;
	window->WindowResizeCallback = callback;
	if (callback == NULL)
	{
		glfwSetFramebufferSizeCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetFramebufferSizeCallback(window->GlfwWindow, glfwWindowFramebufferSizeCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiWindowContentScaleFunction tuiWindowSetContentScaleCallback(TuiWindow window, tuiWindowContentScaleFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiWindowContentScaleFunction old_callback = window->WindowContentScaleCallback;
	window->WindowContentScaleCallback = callback;
	if (callback == NULL)
	{
		glfwSetWindowContentScaleCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetWindowContentScaleCallback(window->GlfwWindow, glfwWindowContentScaleCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiKeyboardKeyFunction tuiWindowSetKeyboardKeyCallback(TuiWindow window, tuiKeyboardKeyFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiKeyboardKeyFunction old_callback = window->KeyboardKeyCallback;
	window->KeyboardKeyCallback = callback;
	if (callback == NULL)
	{
		glfwSetKeyCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetKeyCallback(window->GlfwWindow, glfwKeyCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiCharFunction tuiWindowSetCharCallback(TuiWindow window, tuiCharFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiCharFunction old_callback = window->CharCallback;
	window->CharCallback = callback;
	if (callback == NULL)
	{
		glfwSetCharCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetCharCallback(window->GlfwWindow, glfwCharCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiMouseButtonFunction tuiWindowSetMouseButtonCallback(TuiWindow window, tuiMouseButtonFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiMouseButtonFunction old_callback = window->MouseButtonCallback;
	window->MouseButtonCallback = callback;
	if (callback == NULL)
	{
		glfwSetMouseButtonCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetMouseButtonCallback(window->GlfwWindow, glfwMouseButtonCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiCursorMoveFunction tuiWindowSetCursorMoveCallback(TuiWindow window, tuiCursorMoveFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiCursorMoveFunction old_callback = window->CursorMoveCallback;
	window->CursorMoveCallback = callback;
	if (callback == NULL)
	{
		glfwSetCursorPosCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetCursorPosCallback(window->GlfwWindow, glfwCursorMoveCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiCursorEnterFunction tuiWindowSetCursorEnterCallback(TuiWindow window, tuiCursorEnterFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiCursorEnterFunction old_callback = window->CursorEnterCallback;
	window->CursorEnterCallback = callback;
	if (callback == NULL)
	{
		glfwCursorEnterCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwCursorEnterCallback(window->GlfwWindow, glfwCursorEnterCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiMouseScrollFunction tuiWindowSetMouseScrollCallback(TuiWindow window, tuiMouseScrollFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiMouseScrollFunction old_callback = window->MouseScrollCallback;
	window->MouseScrollCallback = callback;
	if (callback == NULL)
	{
		glfwSetScrollCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetScrollCallback(window->GlfwWindow, glfwScrollCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}

tuiFileDropFunction tuiWindowSetFileDropCallback(TuiWindow window, tuiFileDropFunction callback)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiFileDropFunction old_callback = window->FileDropCallback;
	window->FileDropCallback = callback;
	if (callback == NULL)
	{
		glfwSetDropCallback(window->GlfwWindow, NULL);
	}
	else
	{
		glfwSetDropCallback(window->GlfwWindow, glfwDropCallback);
	}
	GLFW_CHECK_ERROR_RETURN(NULL)
	return old_callback;
}