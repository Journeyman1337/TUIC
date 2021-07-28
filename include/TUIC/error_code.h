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
/*! \file error_code.h
 */
#ifndef TUIC_ERROR_CODE_H //header guard
#define TUIC_ERROR_CODE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>

typedef enum TuiErrorCode
{
	TUI_ERROR_UNKNOWN = -1,
	TUI_ERROR_NONE = 0,
	TUI_ERROR_ALREADY_INITIALIZED = 1,
	TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC = 2,
	TUI_ERROR_DANGLING_ATLAS = 3,
	TUI_ERROR_DANGLING_CURSOR = 4,
	TUI_ERROR_DANGLING_PALETTE = 5,
	TUI_ERROR_DANGLING_PANEL = 6,
	TUI_ERROR_DANGLING_TEXTURE = 7,
	TUI_ERROR_DANGLING_WINDOW = 8,
	TUI_ERROR_GLFW_ENUM = 9,
	TUI_ERROR_GLFW_FORMAT_UNAVAILABLE = 10,
	TUI_ERROR_GLFW_INVALID_VERSION = 11,
	TUI_ERROR_GLFW_NO_GRAPHICS_CONTEXT = 12,
	TUI_ERROR_GLFW_NOT_INITIALIZED = 13,
	TUI_ERROR_GLFW_OUT_OF_MEMORY = 14,
	TUI_ERROR_GLFW_PLATFORM = 15,
	TUI_ERROR_GLFW_WINDOW_CREATION_FAILED = 16,
	TUI_ERROR_GLFW_VALUE = 17,
	TUI_ERROR_INCOMPATIBLE_BLEND_MODE = 18,
	TUI_ERROR_INCOMPATIBLE_IMAGES = 19,
	TUI_ERROR_INVALID_ASPECT_RATIO = 20,
	TUI_ERROR_INVALID_ATLAS_TYPE = 21,
	TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS = 22,
	TUI_ERROR_INVALID_BATCH_DIMENSIONS = 23,
	TUI_ERROR_INVALID_BATCH_SETTER = 24,
	TUI_ERROR_INVALID_BLEND_MODE = 25,
	TUI_ERROR_INVALID_BUTTON_STATE = 26,
	TUI_ERROR_INVALID_CHANNEL_COUNT = 27,
	TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS = 28,
	TUI_ERROR_INVALID_CURSOR_MODE = 29,
	TUI_ERROR_INVALID_CURSOR_SHAPE = 30,
	TUI_ERROR_INVALID_DETAIL_FLAG = 31,
	TUI_ERROR_INVALID_DETAIL_MODE = 32,
	TUI_ERROR_INVALID_FILTER_MODE = 33,
	TUI_ERROR_INVALID_GLYPH_COUNT = 34,
	TUI_ERROR_INVALID_GLYPH_DIMENSIONS = 35,
	TUI_ERROR_INVALID_IMAGE_DIMENSIONS = 36,
	TUI_ERROR_INVALID_KEYBOARD_KEY = 37,
	TUI_ERROR_INVALID_KEYBOARD_MOD = 38,
	TUI_ERROR_INVALID_MOUSE_BUTTON = 39,
	TUI_ERROR_INVALID_PALETTE_COLOR_COUNT = 40,
	TUI_ERROR_INVALID_PANEL_DIMENSIONS = 41,
	TUI_ERROR_INVALID_PIXEL_DIMENSIONS = 42,
	TUI_ERROR_INVALID_TIME = 43,
	TUI_ERROR_INVALID_WINDOW_FRAMEBUFFER_DIMENSIONS = 44,
	TUI_ERROR_INVALID_WINDOW_VIEWPORT_DIMENSIONS = 45,
	TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS = 46,
	TUI_ERROR_LOAD_IMAGE_FAILURE = 47,
	TUI_ERROR_NOT_INITIALIZED = 48,
	TUI_ERROR_NULL_ATLAS = 49,
	TUI_ERROR_NULL_BATCH = 50,
	TUI_ERROR_NULL_BATCH_DATA = 51,
	TUI_ERROR_NULL_COLORS = 52,
	TUI_ERROR_NULL_CURSOR = 53,
	TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES = 54,
	TUI_ERROR_NULL_IMAGE = 55,
	TUI_ERROR_NULL_MONITOR = 56,
	TUI_ERROR_NULL_PALETTE = 57,
	TUI_ERROR_NULL_PANEL = 58,
	TUI_ERROR_NULL_PATH = 59,
	TUI_ERROR_NULL_PIXELS = 60,
	TUI_ERROR_NULL_STRING = 61,
	TUI_ERROR_NULL_SUBJECT_PANEL = 62,
	TUI_ERROR_NULL_SUBJECT_WINDOW = 63,
	TUI_ERROR_NULL_TARGET_IMAGE = 64,
	TUI_ERROR_NULL_TEXTURE = 65,
	TUI_ERROR_NULL_TEXTURE_COORDINATES = 66,
	TUI_ERROR_NULL_WINDOW = 67,
	TUI_ERROR_PALETTE_REQUIRED = 68,
	TUI_ERROR_RESIZE_IMAGE_FAILURE = 69,
	TUI_ERROR_UNAVAILABLE_GRAPHICS_API = 70,
	TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION = 71,
	TUI_ERROR_UNSUPPORTED_CURSOR_SHAPE = 72,
	TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION = 73,
	TUI_ERROR_UNSUPPORTED_WINDOW_ICONS = 74,
	TUI_ERROR_FIRST = TUI_ERROR_UNKNOWN,
	TUI_ERROR_LAST = TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION
} TuiErrorCode;

extern const char* kTui_Error_Unknown_Name;
extern const char* kTui_Error_None_Name;
extern const char* kTui_Error_Already_Initialized_Name;
extern const char* kTui_Error_Graphics_Backend_Specific_Name;
extern const char* kTui_Error_Dangling_Atlas_Name;
extern const char* kTui_Error_Dangling_Cursor_Name;
extern const char* kTui_Error_Dangling_Palette_Name;
extern const char* kTui_Error_Dangling_Panel_Name;
extern const char* kTui_Error_Dangling_Texture_Name;
extern const char* kTui_Error_Dangling_Window_Name;
extern const char* kTui_Error_Glfw_Enum_Name;
extern const char* kTui_Error_Glfw_Format_Unavailable_Name;
extern const char* kTui_Error_Glfw_Invalid_Version_Name;
extern const char* kTui_Error_Glfw_No_Graphics_Context_Name;
extern const char* kTui_Error_Glfw_Not_Initialized_Name;
extern const char* kTui_Error_Glfw_Out_Of_Memory_Name;
extern const char* kTui_Error_Glfw_Platform_Name;
extern const char* kTui_Error_Glfw_Window_Creation_Failed_Name;
extern const char* kTui_Error_Glfw_Value_Name;
extern const char* kTui_Error_Incompatible_Blend_Mode_Name;
extern const char* kTui_Error_Incompatible_Images_Name;
extern const char* kTui_Error_Invalid_Aspect_Ratio_Name;
extern const char* kTui_Error_Invalid_Atlas_Type_Name;
extern const char* kTui_Error_Invalid_Batch_Data_Dimensions_Name;
extern const char* kTui_Error_Invalid_Batch_Dimensions_Name;
extern const char* kTui_Error_Invalid_Batch_Setter_Name;
extern const char* kTui_Error_Invalid_Blend_Mode_Name;
extern const char* kTui_Error_Invalid_Button_State_Name;
extern const char* kTui_Error_Invalid_Channel_Count_Name;
extern const char* kTui_Error_Invalid_Codepage_Dimensions_Name;
extern const char* kTui_Error_Invalid_Cursor_Mode_Name;
extern const char* kTui_Error_Invalid_Cursor_Shape_Name;
extern const char* kTui_Error_Invalid_Detail_Flag_Name;
extern const char* kTui_Error_Invalid_Detail_Mode_Name;
extern const char* kTui_Error_Invalid_Filter_Mode_Name;
extern const char* kTui_Error_Invalid_Glyph_Count_Name;
extern const char* kTui_Error_Invalid_Glyph_Dimensions_Name;
extern const char* kTui_Error_Invalid_Image_Dimensions_Name;
extern const char* kTui_Error_Invalid_Keyboard_Key_Name;
extern const char* kTui_Error_Invalid_Keyboard_Mod_Name;
extern const char* kTui_Error_Invalid_Mouse_Button_Name;
extern const char* kTui_Error_Invalid_Palette_Color_Count_Name;
extern const char* kTui_Error_Invalid_Panel_Dimensions_Name;
extern const char* kTui_Error_Invalid_Pixel_Dimensions_Name;
extern const char* kTui_Error_Invalid_Time_Name;
extern const char* kTui_Error_Invalid_Window_Framebuffer_Dimensions_Name;
extern const char* kTui_Error_Invalid_Window_Viewport_Dimensions_Name;
extern const char* kTui_Error_Invalid_Window_Size_Limits_Name;
extern const char* kTui_Error_Load_Image_Failure_Name;
extern const char* kTui_Error_Not_Initialized_Name;
extern const char* kTui_Error_Null_Atlas_Name;
extern const char* kTui_Error_Null_Batch_Name;
extern const char* kTui_Error_Null_Batch_Data_Name;
extern const char* kTui_Error_Null_Colors_Name;
extern const char* kTui_Error_Null_Cursor_Name;
extern const char* kTui_Error_Null_Glyph_Bounding_Boxes_Name;
extern const char* kTui_Error_Null_Image_Name;
extern const char* kTui_Error_Null_Monitor_Name;
extern const char* kTui_Error_Null_Palette_Name;
extern const char* kTui_Error_Null_Panel_Name;
extern const char* kTui_Error_Null_Path_Name;
extern const char* kTui_Error_Null_Pixels_Name;
extern const char* kTui_Error_Null_String_Name;
extern const char* kTui_Error_Null_Subject_Panel_Name;
extern const char* kTui_Error_Null_Subject_Window_Name;
extern const char* kTui_Error_Null_Target_Image_Name;
extern const char* kTui_Error_Null_Texture_Name;
extern const char* kTui_Error_Null_Texture_Coordinates_Name;
extern const char* kTui_Error_Null_Window_Name;
extern const char* kTui_Error_Palette_Required_Name;
extern const char* kTui_Error_Resize_Image_Failure_Name;
extern const char* kTui_Error_Unavailable_Graphics_Api_Name;
extern const char* kTui_Error_Unavailable_Graphics_Api_Version_Name;
extern const char* kTui_Error_Unsupported_Cursor_Shape_Name;
extern const char* kTui_Error_Unsupported_Raw_Mouse_Motion_Name;
extern const char* kTui_Error_Unsupported_Window_Icons_Name;

extern const char* kTui_Error_Unknown_Description;
extern const char* kTui_Error_None_Description;
extern const char* kTui_Error_Already_Initialized_Description;
extern const char* kTui_Error_Graphics_Backend_Specific_Description;
extern const char* kTui_Error_Dangling_Atlas_Description;
extern const char* kTui_Error_Dangling_Cursor_Description;
extern const char* kTui_Error_Dangling_Palette_Description;
extern const char* kTui_Error_Dangling_Panel_Description;
extern const char* kTui_Error_Dangling_Texture_Description;
extern const char* kTui_Error_Dangling_Window_Description;
extern const char* kTui_Error_Glfw_Enum_Description;
extern const char* kTui_Error_Glfw_Format_Unavailable_Description;
extern const char* kTui_Error_Glfw_Invalid_Version_Description;
extern const char* kTui_Error_Glfw_No_Graphics_Context_Description;
extern const char* kTui_Error_Glfw_Not_Initialized_Description;
extern const char* kTui_Error_Glfw_Out_Of_Memory_Description;
extern const char* kTui_Error_Glfw_Platform_Description;
extern const char* kTui_Error_Glfw_Window_Creation_Failed_Description;
extern const char* kTui_Error_Glfw_Value_Description;
extern const char* kTui_Error_Incompatible_Blend_Mode_Description;
extern const char* kTui_Error_Incompatible_Images_Description;
extern const char* kTui_Error_Invalid_Aspect_Ratio_Description;
extern const char* kTui_Error_Invalid_Atlas_Type_Description;
extern const char* kTui_Error_Invalid_Batch_Data_Dimensions_Description;
extern const char* kTui_Error_Invalid_Batch_Dimensions_Description;
extern const char* kTui_Error_Invalid_Batch_Setter_Description;
extern const char* kTui_Error_Invalid_Blend_Mode_Description;
extern const char* kTui_Error_Invalid_Button_State_Description;
extern const char* kTui_Error_Invalid_Channel_Count_Description;
extern const char* kTui_Error_Invalid_Codepage_Dimensions_Description;
extern const char* kTui_Error_Invalid_Cursor_Mode_Description;
extern const char* kTui_Error_Invalid_Cursor_Shape_Description;
extern const char* kTui_Error_Invalid_Detail_Flag_Description;
extern const char* kTui_Error_Invalid_Detail_Mode_Description;
extern const char* kTui_Error_Invalid_Filter_Mode_Description;
extern const char* kTui_Error_Invalid_Glyph_Count_Description;
extern const char* kTui_Error_Invalid_Glyph_Dimensions_Description;
extern const char* kTui_Error_Invalid_Image_Dimensions_Description;
extern const char* kTui_Error_Invalid_Keyboard_Key_Description;
extern const char* kTui_Error_Invalid_Keyboard_Mod_Description;
extern const char* kTui_Error_Invalid_Mouse_Button_Description;
extern const char* kTui_Error_Invalid_Palette_Color_Count_Description;
extern const char* kTui_Error_Invalid_Panel_Dimensions_Description;
extern const char* kTui_Error_Invalid_Pixel_Dimensions_Description;
extern const char* kTui_Error_Invalid_Time_Description;
extern const char* kTui_Error_Invalid_Window_Framebuffer_Dimensions_Description;
extern const char* kTui_Error_Invalid_Window_Viewport_Dimensions_Description;
extern const char* kTui_Error_Invalid_Window_Size_Limits_Description;
extern const char* kTui_Error_Load_Image_Failure_Description;
extern const char* kTui_Error_Not_Initialized_Description;
extern const char* kTui_Error_Null_Atlas_Description;
extern const char* kTui_Error_Null_Batch_Description;
extern const char* kTui_Error_Null_Batch_Data_Description;
extern const char* kTui_Error_Null_Colors_Description;
extern const char* kTui_Error_Null_Cursor_Description;
extern const char* kTui_Error_Null_Glyph_Bounding_Boxes_Description;
extern const char* kTui_Error_Null_Image_Description;
extern const char* kTui_Error_Null_Monitor_Description;
extern const char* kTui_Error_Null_Palette_Description;
extern const char* kTui_Error_Null_Panel_Description;
extern const char* kTui_Error_Null_Path_Description;
extern const char* kTui_Error_Null_Pixels_Description;
extern const char* kTui_Error_Null_String_Description;
extern const char* kTui_Error_Null_Subject_Panel_Description;
extern const char* kTui_Error_Null_Subject_Window_Description;
extern const char* kTui_Error_Null_Target_Image_Description;
extern const char* kTui_Error_Null_Texture_Description;
extern const char* kTui_Error_Null_Texture_Coordinates_Description;
extern const char* kTui_Error_Null_Window_Description;
extern const char* kTui_Error_Palette_Required_Description;
extern const char* kTui_Error_Resize_Image_Failure_Description;
extern const char* kTui_Error_Unavailable_Graphics_Api_Description;
extern const char* kTui_Error_Unavailable_Graphics_Api_Version_Description;
extern const char* kTui_Error_Unsupported_Cursor_Shape_Description;
extern const char* kTui_Error_Unsupported_Raw_Mouse_Motion_Description;
extern const char* kTui_Error_Unsupported_Window_Icons_Description;

TuiBoolean tuiErrorCodeIsValid(TuiErrorCode code);

const char* tuiErrorCodeToString(TuiErrorCode error_code);

int tuiStringToErrorCode(const char* str);

const char* tuiErrorCodeGetDescription(int error_code);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard