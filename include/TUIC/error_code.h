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
	TUI_ERROR_DANGLING_ATLAS = 2,
	TUI_ERROR_DANGLING_CURSOR = 3,
	TUI_ERROR_DANGLING_INSTANCE = 4,
	TUI_ERROR_DANGLING_PALETTE = 5,
	TUI_ERROR_DANGLING_PANEL = 6,
	TUI_ERROR_DANGLING_TEXTURE = 7,
	TUI_ERROR_DESKTOP_FORMAT_UNAVAILABLE = 8,
	TUI_ERROR_DESKTOP_NOT_INITIALIZED = 9,
	TUI_ERROR_DESKTOP_NO_GRAPHICS_CONTEXT = 10,
	TUI_ERROR_DESKTOP_OUT_OF_MEMORY = 11,
	TUI_ERROR_DESKTOP_PLATFORM = 12,
	TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC = 13,
	TUI_ERROR_INCOMPATIBLE_BLEND_MODE = 14,
	TUI_ERROR_INCOMPATIBLE_IMAGES = 15,
	TUI_ERROR_INVALID_ASPECT_RATIO = 16,
	TUI_ERROR_INVALID_ATLAS_TYPE = 17,
	TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS = 18,
	TUI_ERROR_INVALID_BATCH_DIMENSIONS = 19,
	TUI_ERROR_INVALID_BATCH_SETTER = 20,
	TUI_ERROR_INVALID_BLEND_MODE = 21,
	TUI_ERROR_INVALID_BUTTON_STATE = 22,
	TUI_ERROR_INVALID_CHANNEL_COUNT = 23,
	TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS = 24,
	TUI_ERROR_INVALID_CURSOR_MODE = 25,
	TUI_ERROR_INVALID_CURSOR_SHAPE = 26,
	TUI_ERROR_INVALID_DETAIL_FLAG = 27,
	TUI_ERROR_INVALID_DETAIL_MODE = 28,
	TUI_ERROR_INVALID_FILTER_MODE = 29,
	TUI_ERROR_INVALID_GLYPH_COUNT = 30,
	TUI_ERROR_INVALID_GLYPH_DIMENSIONS = 31,
	TUI_ERROR_INVALID_IMAGE_DIMENSIONS = 32,
	TUI_ERROR_INVALID_INSTANCE_DIMENSIONS = 33,
	TUI_ERROR_INVALID_JOYSTICK_HAT_STATE = 34,
	TUI_ERROR_INVALID_JOYSTICK_ID = 35,
	TUI_ERROR_INVALID_KEY = 36,
	TUI_ERROR_INVALID_KEY_MOD = 37,
	TUI_ERROR_INVALID_MOUSE_BUTTON = 38,
	TUI_ERROR_INVALID_PALETTE_COLOR_COUNT = 39,
	TUI_ERROR_INVALID_PANEL_DIMENSIONS = 40,
	TUI_ERROR_INVALID_PIXEL_DIMENSIONS = 41,
	TUI_ERROR_INVALID_TIME = 42,
	TUI_ERROR_INVALID_TRANSPARENT_FRAMEBUFFER_OPACITY = 43,
	TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS = 44,
	TUI_ERROR_LOAD_IMAGE_FAILURE = 45,
	TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS = 46,
	TUI_ERROR_NO_CURRENT_CONTEXT = 47,
	TUI_ERROR_NULL_ATLAS = 48,
	TUI_ERROR_NULL_BATCH = 49,
	TUI_ERROR_NULL_BATCH_DATA = 50,
	TUI_ERROR_NULL_COLORS = 51,
	TUI_ERROR_NULL_CURSOR = 52,
	TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES = 53,
	TUI_ERROR_NULL_IMAGE = 54,
	TUI_ERROR_NULL_INSTANCE = 55,
	TUI_ERROR_NULL_PALETTE = 56,
	TUI_ERROR_NULL_PANEL = 57,
	TUI_ERROR_NULL_PATH = 58,
	TUI_ERROR_NULL_PIXELS = 59,
	TUI_ERROR_NULL_STRING = 60,
	TUI_ERROR_NULL_TARGET_IMAGE = 61,
	TUI_ERROR_NULL_TARGET_PANEL = 62,
	TUI_ERROR_NULL_TEXTURE = 63,
	TUI_ERROR_NULL_TEXTURE_COORDINATES = 64,
	TUI_ERROR_PALETTE_REQUIRED = 65,
	TUI_ERROR_RESIZE_IMAGE_FAILURE = 66,
	TUI_ERROR_UNAVAILABLE_GRAPHICS_API = 67,
	TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION = 68,
	TUI_ERROR_UNMATCHING_ATLAS_INSTANCE = 69,
	TUI_ERROR_UNMATCHING_PALETTE_INSTANCE = 70,
	TUI_ERROR_UNMATCHING_PANEL_INSTANCE = 71,
	TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION = 72,
	TUI_ERROR_FIRST = TUI_ERROR_UNKNOWN,
	TUI_ERROR_LAST = TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION
} TuiErrorCode;

extern const char* kTui_Error_Unknown_Name;
extern const char* kTui_Error_None_Name;
extern const char* kTui_Error_Already_Initialized_Name;
extern const char* kTui_Error_Dangling_Atlas_Name;
extern const char* kTui_Error_Dangling_Cursor_Name;
extern const char* kTui_Error_Dangling_Instance_Name;
extern const char* kTui_Error_Dangling_Palette_Name;
extern const char* kTui_Error_Dangling_Panel_Name;
extern const char* kTui_Error_Dangling_Texture_Name;
extern const char* kTui_Error_Desktop_Format_Unavailable_Name;
extern const char* kTui_Error_Desktop_Not_Initialized_Name;
extern const char* kTui_Error_Desktop_No_Graphics_Context_Name;
extern const char* kTui_Error_Desktop_Out_Of_Memory_Name;
extern const char* kTui_Error_Desktop_Platform_Name;
extern const char* kTui_Error_Graphics_Backend_Specific_Name;
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
extern const char* kTui_Error_Invalid_Instance_Dimensions_Name;
extern const char* kTui_Error_Invalid_Joystick_Hat_State_Name;
extern const char* kTui_Error_Invalid_Joystick_Id_Name;
extern const char* kTui_Error_Invalid_Key_Name;
extern const char* kTui_Error_Invalid_Key_Mod_Name;
extern const char* kTui_Error_Invalid_Mouse_Button_Name;
extern const char* kTui_Error_Invalid_Palette_Color_Count_Name;
extern const char* kTui_Error_Invalid_Panel_Dimensions_Name;
extern const char* kTui_Error_Invalid_Pixel_Dimensions_Name;
extern const char* kTui_Error_Invalid_Time_Name;
extern const char* kTui_Error_Invalid_Transparent_Framebuffer_Opacity_Name;
extern const char* kTui_Error_Invalid_Window_Size_Limits_Name;
extern const char* kTui_Error_Load_Image_Failure_Name;
extern const char* kTui_Error_Load_Image_Unexpected_Channels_Name;
extern const char* kTui_Error_No_Current_Context_Name;
extern const char* kTui_Error_Null_Atlas_Name;
extern const char* kTui_Error_Null_Batch_Name;
extern const char* kTui_Error_Null_Batch_Data_Name;
extern const char* kTui_Error_Null_Colors_Name;
extern const char* kTui_Error_Null_Cursor_Name;
extern const char* kTui_Error_Null_Glyph_Bounding_Boxes_Name;
extern const char* kTui_Error_Null_Image_Name;
extern const char* kTui_Error_Null_Instance_Name;
extern const char* kTui_Error_Null_Palette_Name;
extern const char* kTui_Error_Null_Panel_Name;
extern const char* kTui_Error_Null_Path_Name;
extern const char* kTui_Error_Null_Pixels_Name;
extern const char* kTui_Error_Null_String_Name;
extern const char* kTui_Error_Null_Target_Image_Name;
extern const char* kTui_Error_Null_Target_Panel_Name;
extern const char* kTui_Error_Null_Texture_Name;
extern const char* kTui_Error_Null_Texture_Coordinates_Name;
extern const char* kTui_Error_Palette_Required_Name;
extern const char* kTui_Error_Resize_Image_Failure_Name;
extern const char* kTui_Error_Unavailable_Graphics_API_Name;
extern const char* kTui_Error_Unavailable_Graphics_API_Version_Name;
extern const char* kTui_Error_Unmatching_Atlas_Instance_Name;
extern const char* kTui_Error_Unmatching_Palette_Instance_Name;
extern const char* kTui_Error_Unmatching_Panel_Instance_Name;
extern const char* kTui_Error_Unsupported_Raw_Mouse_Motion_Name;

extern const char* kTui_Error_Unknown_Description;
extern const char* kTui_Error_None_Description;
extern const char* kTui_Error_Already_Initialized_Description;
extern const char* kTui_Error_Backend_Specific_Description;
extern const char* kTui_Error_Dangling_Atlas_Description;
extern const char* kTui_Error_Dangling_Cursor_Description;
extern const char* kTui_Error_Dangling_Instance_Description;
extern const char* kTui_Error_Dangling_Palette_Description;
extern const char* kTui_Error_Dangling_Panel_Description;
extern const char* kTui_Error_Dangling_Texture_Description;
extern const char* kTui_Error_Desktop_Format_Unavailable_Description;
extern const char* kTui_Error_Desktop_Not_Initialized_Description;
extern const char* kTui_Error_Desktop_No_Graphics_Context_Description;
extern const char* kTui_Error_Desktop_Out_Of_Memory_Description;
extern const char* kTui_Error_Desktop_Platform_Description;
extern const char* kTui_Error_Graphics_Backend_Specific_Description;
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
extern const char* kTui_Error_Invalid_Instance_Dimensions_Description;
extern const char* kTui_Error_Invalid_Joystick_Hat_State_Description;
extern const char* kTui_Error_Invalid_Joystick_Id_Description;
extern const char* kTui_Error_Invalid_Key_Description;
extern const char* kTui_Error_Invalid_Key_Mod_Description;
extern const char* kTui_Error_Invalid_Mouse_Button_Description;
extern const char* kTui_Error_Invalid_Palette_Color_Count_Description;
extern const char* kTui_Error_Invalid_Panel_Dimensions_Description;
extern const char* kTui_Error_Invalid_Pixel_Dimensions_Description;
extern const char* kTui_Error_Invalid_Time_Description;
extern const char* kTui_Error_Invalid_Transparent_Framebuffer_Opacity_Description;
extern const char* kTui_Error_Invalid_Window_Size_Limits_Description;
extern const char* kTui_Error_Load_Image_Failure_Description;
extern const char* kTui_Error_Load_Image_Unexpected_Channels_Description;
extern const char* kTui_Error_No_Current_Context_Description;
extern const char* kTui_Error_Null_Atlas_Description;
extern const char* kTui_Error_Null_Batch_Description;
extern const char* kTui_Error_Null_Batch_Data_Description;
extern const char* kTui_Error_Null_Colors_Description;
extern const char* kTui_Error_Null_Cursor_Description;
extern const char* kTui_Error_Null_Glyph_Bounding_Boxes_Description;
extern const char* kTui_Error_Null_Image_Description;
extern const char* kTui_Error_Null_Instance_Description;
extern const char* kTui_Error_Null_Palette_Description;
extern const char* kTui_Error_Null_Panel_Description;
extern const char* kTui_Error_Null_Path_Description;
extern const char* kTui_Error_Null_Pixels_Description;
extern const char* kTui_Error_Null_String_Description;
extern const char* kTui_Error_Null_Target_Image_Description;
extern const char* kTui_Error_Null_Target_Panel_Description;
extern const char* kTui_Error_Null_Texture_Description;
extern const char* kTui_Error_Null_Texture_Coordinates_Description;
extern const char* kTui_Error_Palette_Required_Description;
extern const char* kTui_Error_Resize_Image_Failure_Description;
extern const char* kTui_Error_Unavailable_Graphics_API_Description;
extern const char* kTui_Error_Unavailable_Graphics_API_Version_Description;
extern const char* kTui_Error_Unmatching_Atlas_Type_Description;
extern const char* kTui_Error_Unmatching_Palette_Instance_Description;
extern const char* kTui_Error_Unmatching_Panel_Instance_Description;
extern const char* kTui_Error_Unsupported_Raw_Mouse_Motion_Description;

TuiBoolean tuiErrorCodeIsValid(TuiErrorCode code);

const char* tuiErrorCodeToString(TuiErrorCode error_code);

int tuiStringToErrorCode(const char* str);

const char* tuiErrorCodeGetDescription(int error_code);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard