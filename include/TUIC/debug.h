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
/*! \file debug.h
 */
#ifndef TUIC_DEBUG_H //header guard
#define TUIC_DEBUG_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

/*! @brief These are error codes passed into the set @ref TuiDebugCallback function.
 */
typedef enum TuiErrorCode
{
	TUI_ERROR_UNKNOWN = -1,
	TUI_ERROR_NONE = 0,
	TUI_ERROR_ALREADY_INITIALIZED = 1,
	TUI_ERROR_DAMAGED_INSTANCE = 2,
	TUI_ERROR_DANGLING_ATLAS = 3,
	TUI_ERROR_DANGLING_CURSOR = 4,
	TUI_ERROR_DANGLING_INSTANCE = 5,
	TUI_ERROR_DANGLING_PALETTE = 6,
	TUI_ERROR_DANGLING_PANEL = 7,
	TUI_ERROR_DANGLING_TEXTURE = 8,
	TUI_ERROR_DESKTOP_FORMAT_UNAVAILABLE = 9,
	TUI_ERROR_DESKTOP_NOT_INITIALIZED = 10,
	TUI_ERROR_DESKTOP_NO_GRAPHICS_CONTEXT = 11,
	TUI_ERROR_DESKTOP_OUT_OF_MEMORY = 12,
	TUI_ERROR_DESKTOP_PLATFORM = 13,
	TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC = 14,
	TUI_ERROR_INCOMPATIBLE_BLEND_MODE = 15,
	TUI_ERROR_INCOMPATIBLE_IMAGES = 16,
	TUI_ERROR_INVALID_ASPECT_RATIO = 17,
	TUI_ERROR_INVALID_ATLAS_TYPE = 18,
	TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS = 19,
	TUI_ERROR_INVALID_BATCH_DIMENSIONS = 20,
	TUI_ERROR_INVALID_BATCH_SETTER = 21,
	TUI_ERROR_INVALID_BLEND_MODE = 22,
	TUI_ERROR_INVALID_BUTTON_STATE = 23,
	TUI_ERROR_INVALID_CHANNEL_COUNT = 24,
	TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS = 25,
	TUI_ERROR_INVALID_CURSOR_MODE = 27,
	TUI_ERROR_INVALID_CURSOR_SHAPE = 28,
	TUI_ERROR_INVALID_DETAIL_FLAG = 29,
	TUI_ERROR_INVALID_DETAIL_MODE = 30,
	TUI_ERROR_INVALID_FILTER_MODE = 31,
	TUI_ERROR_INVALID_GLYPH_COUNT = 32,
	TUI_ERROR_INVALID_GLYPH_DIMENSIONS = 33,
	TUI_ERROR_INVALID_IMAGE_DIMENSIONS = 34,
	TUI_ERROR_INVALID_INSTANCE_DIMENSIONS = 35,
	TUI_ERROR_INVALID_JOYSTICK_HAT_STATE = 36,
	TUI_ERROR_INVALID_JOYSTICK_ID = 37,
	TUI_ERROR_INVALID_KEY = 38,
	TUI_ERROR_INVALID_KEY_MOD = 39,
	TUI_ERROR_INVALID_MOUSE_BUTTON = 40,
	TUI_ERROR_INVALID_PALETTE_COLOR_COUNT = 41,
	TUI_ERROR_INVALID_PANEL_DIMENSIONS = 42,
	TUI_ERROR_INVALID_PIXEL_DIMENSIONS = 43,
	TUI_ERROR_INVALID_TIME = 44,
	TUI_ERROR_INVALID_TRANSPARENT_FRAMEBUFFER_OPACITY = 45,
	TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS = 46,
	TUI_ERROR_LOAD_IMAGE_FAILURE = 47,
	TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS = 48,
	TUI_ERROR_NO_CURRENT_CONTEXT = 49,
	TUI_ERROR_NULL_ATLAS = 50,
	TUI_ERROR_NULL_BATCH = 51,
	TUI_ERROR_NULL_BATCH_DATA = 52,
	TUI_ERROR_NULL_COLORS = 53,
	TUI_ERROR_NULL_CURSOR = 54,
	TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES = 55,
	TUI_ERROR_NULL_IMAGE = 56,
	TUI_ERROR_NULL_INSTANCE = 57,
	TUI_ERROR_NULL_PALETTE = 58,
	TUI_ERROR_NULL_PANEL = 59,
	TUI_ERROR_NULL_PATH = 60,
	TUI_ERROR_NULL_PIXELS = 61,
	TUI_ERROR_NULL_STRING = 62,
	TUI_ERROR_NULL_TARGET_IMAGE = 63,
	TUI_ERROR_NULL_TARGET_PANEL = 64,
	TUI_ERROR_NULL_TEXTURE = 65,
	TUI_ERROR_NULL_TEXTURE_COORDINATES = 66,
	TUI_ERROR_PALETTE_REQUIRED = 67,
	TUI_ERROR_RESIZE_IMAGE_FAILURE = 68,
	TUI_ERROR_UNAVAILABLE_GRAPHICS_API = 69,
	TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION = 70,
	TUI_ERROR_UNMATCHING_ATLAS_INSTANCE = 71,
	TUI_ERROR_UNMATCHING_PALETTE_INSTANCE = 72,
	TUI_ERROR_UNMATCHING_PANEL_INSTANCE = 73,
	TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION = 74,
	TUI_ERROR_FIRST = TUI_ERROR_UNKNOWN,
	TUI_ERROR_LAST = TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION
} TuiErrorCode;
/*! @name Error Code Names
 * These are the const string names of @ref TuiErrorCode enum values.
 *  @{ */
extern const char* kTui_Error_Unknown_Name;
extern const char* kTui_Error_None_Name;
extern const char* kTui_Error_Already_Initialized_Name;
extern const char* kTui_Error_Damaged_Instance_Name;
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
/*! @} */
/*! @name Error Code Descriptions
 * These are the const string descriptions of @ref TuiErrorCode enum values.
 *  @{ */
extern const char* kTui_Error_Unknown_Description;
extern const char* kTui_Error_None_Description;
extern const char* kTui_Error_Already_Initialized_Description;
extern const char* kTui_Error_Backend_Specific_Description;
extern const char* kTui_Error_Damaged_Instance_Description;
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
/*! @} */
/*! @name Error Code Manipilation Functions
 *  @{ */

TuiBoolean tuiErrorCodeIsValid(TuiErrorCode code);

const char* tuiErrorCodeToString(TuiErrorCode error_code);

int tuiStringToErrorCode(const char* str);

const char* tuiErrorCodeGetDescription(int error_code);
/*! @} */
/*! @name Debug Output
 *
 * These functions and callbacks are used for controling how TUIC handles debug output.
 *
 *  @{ */ 
/*!
 * @brief Callback type used to set the debug callback handler.
 */
typedef void(*tuiDebugErrorCallback) (int error_code, const char* msg);
/*!
 * @brief Set the callback function to handle debug output from TUI.
 *
 * After passing a callback function, TUIC will call that function and pass in debug output. Setting the callback to NULL will disable the callback.
 */
void tuiSetDebugErrorCallback(tuiDebugErrorCallback callback);
/*!
 * @brief Send a debug message to the debug callback function.
 *
 * @param error_code The @ref TuiErrorCode.
 * @param msg For errors with @ref TuiErrorCode @ref TUI_ERROR_BACKEND_SPECIFIC, this is a string description of the error. For all other error codes, this is the name of the function where the error occured.
 *
 * This function sends a message to the currently set debug callback function. If none was set or it was set to NULL, nothing will happen.
 */
void tuiDebugError(int error_code, const char* msg);
/*! @} */
#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard