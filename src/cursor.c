#include <TUIC/cursor.h>
#include "image_inline.h"
#include <GLFW/glfw3.h>
#include <TUIC/debug.h>
#include <TUIC/system.h>
#include <TUIC/boolean.h>

static size_t sCursorCount;

TuiCursor tuiCursorCreate(TuiImage image, int xhot, int yhot)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	if (image == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return NULL;
	}

	GLFWimage glfw_image = _TuiImageToGlfwImage(image, __func__);
	if (glfw_image.width == 0)
	{
		return NULL;
	}
	sCursorCount++;
	return glfwCreateCursor(&glfw_image, xhot, yhot);
}

TuiCursor tuiCursorCreateStandard(TuiCursorShape shape)
{
	if (tuiIsActive() == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INACTIVE_SYSTEM, __func__);
		return;
	}
	// TODO if (tuiCursorShapeIsValid(shape) == TUI_FALSE)
	{
		// TODO tuiDebugError(TUI_ERROR_INVALID_CURSOR_SHAPE, __func__);
		return NULL;
	}
	sCursorCount++;
	return glfwCreateStandardCursor(shape);
}

void tuiCursorDestroy(TuiCursor cursor)
{
	if (cursor == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_CURSOR, __func__);
		return;
	}
	sCursorCount--;
	glfwDestroyCursor(cursor);
}

int tuiGetCursorCount()
{
	return (int)sCursorCount;
}
