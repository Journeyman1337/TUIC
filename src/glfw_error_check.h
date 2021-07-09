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
#ifndef TUIC_GLFW_ERROR_CHECK_H //header guard
#define TUIC_GLFW_ERROR_CHECK_H
#include <TUIC/debug.h>
#include <GLFW/glfw3.h>
#include <TUIC/boolean.h>

#define GLFW_CHECK_ERROR_RETURN(error_return) { \
			int glfw_error_code = GLFW_NO_ERROR; \
			TuiBoolean error_occured = TUI_FALSE; \
			while ((glfw_error_code = glfwGetError(NULL)) != GLFW_NO_ERROR) \
			{ \
				switch (glfw_error_code) \
				{ \
				case GLFW_NOT_INITIALIZED: \
					tuiDebugError(TUI_ERROR_DESKTOP_NOT_INITIALIZED, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_NO_CURRENT_CONTEXT: \
					tuiDebugError(TUI_ERROR_NO_CURRENT_CONTEXT, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_INVALID_ENUM: \
				case GLFW_INVALID_VALUE: \
					tuiDebugError(TUI_ERROR_UNKNOWN, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_OUT_OF_MEMORY: \
					tuiDebugError(TUI_ERROR_DESKTOP_OUT_OF_MEMORY, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_API_UNAVAILABLE: \
					tuiDebugError(TUI_ERROR_UNAVAILABLE_GRAPHICS_API, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_VERSION_UNAVAILABLE: \
					tuiDebugError(TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_PLATFORM_ERROR: \
					tuiDebugError(TUI_ERROR_DESKTOP_PLATFORM, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_FORMAT_UNAVAILABLE: \
					tuiDebugError(TUI_ERROR_DESKTOP_FORMAT_UNAVAILABLE, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_NO_WINDOW_CONTEXT: \
					tuiDebugError(TUI_ERROR_DESKTOP_NO_GRAPHICS_CONTEXT, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				} \
			} \
			if (error_occured == TUI_TRUE) \
			{ \
				return error_return; \
			} \
		}

#define GLFW_CHECK_ERROR() { \
			int glfw_error_code = GLFW_NO_ERROR; \
			TuiBoolean error_occured = TUI_FALSE; \
			while ((glfw_error_code = glfwGetError(NULL)) != GLFW_NO_ERROR) \
			{ \
				switch (glfw_error_code) \
				{ \
				case GLFW_NOT_INITIALIZED: \
					tuiDebugError(TUI_ERROR_DESKTOP_NOT_INITIALIZED, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_NO_CURRENT_CONTEXT: \
					tuiDebugError(TUI_ERROR_NO_CURRENT_CONTEXT, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_INVALID_ENUM: \
				case GLFW_INVALID_VALUE: \
					tuiDebugError(TUI_ERROR_UNKNOWN, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_OUT_OF_MEMORY: \
					tuiDebugError(TUI_ERROR_DESKTOP_OUT_OF_MEMORY, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_API_UNAVAILABLE: \
					tuiDebugError(TUI_ERROR_UNAVAILABLE_GRAPHICS_API, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_VERSION_UNAVAILABLE: \
					tuiDebugError(TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_PLATFORM_ERROR: \
					tuiDebugError(TUI_ERROR_DESKTOP_PLATFORM, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_FORMAT_UNAVAILABLE: \
					tuiDebugError(TUI_ERROR_DESKTOP_FORMAT_UNAVAILABLE, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				case GLFW_NO_WINDOW_CONTEXT: \
					tuiDebugError(TUI_ERROR_DESKTOP_NO_GRAPHICS_CONTEXT, __func__); \
					error_occured = TUI_TRUE; \
					break; \
				} \
			} \
			if (error_occured == TUI_TRUE) \
			{ \
				return; \
			} \
		}

#define GLFW_CLEAR_ERRORS()	while(glfwGetError(NULL)) {}

#endif //header guard