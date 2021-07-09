#include <TUIC/debug.h>
#include <stddef.h>

void tui_default_debug_callback(int error_type, const char* str) {}

static tuiDebugErrorCallback sDebugCallback = tui_default_debug_callback;

void tuiSetDebugErrorCallback(tuiDebugErrorCallback callback)
{
	if (callback == NULL)
	{
		sDebugCallback = tui_default_debug_callback;
	}
	else
	{
		sDebugCallback = callback;
	}
}

void tuiDebugError(int error_code, const char* msg)
{
	sDebugCallback(error_code, msg);
}