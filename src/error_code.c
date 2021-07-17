#include <TUIC/error_code.h>
#include "string.h"

#define TO_STRING(value) #value

const char* kTui_Error_Unknown_Name = TO_STRING(TUI_ERROR_UNKNOWN);
const char* kTui_Error_None_Name = TO_STRING(TUI_ERROR_NONE);
const char* kTui_Error_Already_Initialized_Name = TO_STRING(TUI_ERROR_ALREADY_INITIALIZED);
const char* kTui_Error_Dangling_Atlas_Name = TO_STRING(TUI_ERROR_DANGLING_ATLAS);
const char* kTui_Error_Dangling_Cursor_Name = TO_STRING(TUI_ERROR_DANGLING_CURSOR);
const char* kTui_Error_Dangling_Window_Name = TO_STRING(TUI_ERROR_DANGLING_WINDOW);
const char* kTui_Error_Dangling_Palette_Name = TO_STRING(TUI_ERROR_DANGLING_PALETTE);
const char* kTui_Error_Dangling_Panel_Name = TO_STRING(TUI_ERROR_DANGLING_PANEL);
const char* kTui_Error_Dangling_Texture_Name = TO_STRING(TUI_ERROR_DANGLING_TEXTURE);
const char* kTui_Error_Desktop_Format_Unavailable_Name = TO_STRING(TUI_ERROR_DESKTOP_FORMAT_UNAVAILABLE);
const char* kTui_Error_Desktop_Not_Initialized_Name = TO_STRING(TUI_ERROR_DESKTOP_NOT_INITIALIZED);
const char* kTui_Error_Desktop_No_Graphics_Context_Name = TO_STRING(TUI_ERROR_DESKTOP_NO_GRAPHICS_CONTEXT);
const char* kTui_Error_Desktop_Out_Of_Memory_Name = TO_STRING(TUI_ERROR_DESKTOP_OUT_OF_MEMORY);
const char* kTui_Error_Desktop_Platform_Name = TO_STRING(TUI_ERROR_DESKTOP_PLATFORM);
const char* kTui_Error_Graphics_Backend_Specific_Name = TO_STRING(TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC);
const char* kTui_Error_Incompatible_Blend_Mode_Name = TO_STRING(TUI_ERROR_INCOMPATIBLE_BLEND_MODE);
const char* kTui_Error_Incompatible_Images_Name = TO_STRING(TUI_ERROR_INCOMPATIBLE_IMAGES);
const char* kTui_Error_Invalid_Aspect_Ratio_Name = TO_STRING(TUI_ERROR_INVALID_ASPECT_RATIO);
const char* kTui_Error_Invalid_Atlas_Type_Name = TO_STRING(TUI_ERROR_INVALID_ATLAS_TYPE);
const char* kTui_Error_Invalid_Batch_Data_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS);
const char* kTui_Error_Invalid_Batch_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_BATCH_DIMENSIONS);
const char* kTui_Error_Invalid_Batch_Setter_Name = TO_STRING(TUI_ERROR_INVALID_BATCH_SETTER);
const char* kTui_Error_Invalid_Blend_Mode_Name = TO_STRING(TUI_ERROR_INVALID_BLEND_MODE);
const char* kTui_Error_Invalid_Button_State_Name = TO_STRING(TUI_ERROR_INVALID_BUTTON_STATE);
const char* kTui_Error_Invalid_Channel_Count_Name = TO_STRING(TUI_ERROR_INVALID_CHANNEL_COUNT);
const char* kTui_Error_Invalid_Codepage_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS);
const char* kTui_Error_Invalid_Cursor_Mode_Name = TO_STRING(TUI_ERROR_INVALID_CURSOR_MODE);
const char* kTui_Error_Invalid_Cursor_Shape_Name = TO_STRING(TUI_ERROR_INVALID_CURSOR_SHAPE);
const char* kTui_Error_Invalid_Detail_Flag_Name = TO_STRING(TUI_ERROR_INVALID_DETAIL_FLAG);
const char* kTui_Error_Invalid_Detail_Mode_Name = TO_STRING(TUI_ERROR_INVALID_DETAIL_MODE);
const char* kTui_Error_Invalid_Filter_Mode_Name = TO_STRING(TUI_ERROR_INVALID_FILTER_MODE);
const char* kTui_Error_Invalid_Glyph_Count_Name = TO_STRING(TUI_ERROR_INVALID_GLYPH_COUNT);
const char* kTui_Error_Invalid_Glyph_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_GLYPH_DIMENSIONS);
const char* kTui_Error_Invalid_Image_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_IMAGE_DIMENSIONS);
const char* kTui_Error_Invalid_Window_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_WINDOW_DIMENSIONS);
const char* kTui_Error_Invalid_Joystick_Hat_State_Name = TO_STRING(TUI_ERROR_INVALID_JOYSTICK_HAT_STATE);
const char* kTui_Error_Invalid_Joystick_Id_Name = TO_STRING(TUI_ERROR_INVALID_JOYSTICK_ID);
const char* kTui_Error_Invalid_Key_Name = TO_STRING(TUI_ERROR_INVALID_KEY);
const char* kTui_Error_Invalid_Key_Mod_Name = TO_STRING(TUI_ERROR_INVALID_KEY_MOD);
const char* kTui_Error_Invalid_Mouse_Button_Name = TO_STRING(TUI_ERROR_INVALID_MOUSE_BUTTON);
const char* kTui_Error_Invalid_Palette_Color_Count_Name = TO_STRING(TUI_ERROR_INVALID_PALETTE_COLOR_COUNT);
const char* kTui_Error_Invalid_Panel_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_PANEL_DIMENSIONS);
const char* kTui_Error_Invalid_Pixel_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_PIXEL_DIMENSIONS);
const char* kTui_Error_Invalid_Time_Name = TO_STRING(TUI_ERROR_INVALID_TIME);
const char* kTui_Error_Invalid_Transparent_Framebuffer_Opacity_Name = TO_STRING(TUI_ERROR_INVALID_TRANSPARENT_FRAMEBUFFER_OPACITY);
const char* kTui_Error_Invalid_Window_Size_Limits_Name = TO_STRING(TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS);
const char* kTui_Error_Load_Image_Failure_Name = TO_STRING(TUI_ERROR_LOAD_IMAGE_FAILURE);
const char* kTui_Error_Load_Image_Unexpected_Channels_Name = TO_STRING(TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS);
const char* kTui_Error_No_Current_Context_Name = TO_STRING(TUI_ERROR_NO_CURRENT_CONTEXT);
const char* kTui_Error_Null_Atlas_Name = TO_STRING(TUI_ERROR_NULL_ATLAS);
const char* kTui_Error_Null_Batch_Name = TO_STRING(TUI_ERROR_NULL_BATCH);
const char* kTui_Error_Null_Batch_Data_Name = TO_STRING(TUI_ERROR_NULL_BATCH_DATA);
const char* kTui_Error_Null_Colors_Name = TO_STRING(TUI_ERROR_NULL_COLORS);
const char* kTui_Error_Null_Cursor_Name = TO_STRING(TUI_ERROR_NULL_CURSOR);
const char* kTui_Error_Null_Glyph_Bounding_Boxes_Name = TO_STRING(TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES);
const char* kTui_Error_Null_Image_Name = TO_STRING(TUI_ERROR_NULL_IMAGE);
const char* kTui_Error_Null_Window_Name = TO_STRING(TUI_ERROR_NULL_WINDOW);
const char* kTui_Error_Null_Palette_Name = TO_STRING(TUI_ERROR_NULL_PALETTE);
const char* kTui_Error_Null_Panel_Name = TO_STRING(TUI_ERROR_NULL_PANEL);
const char* kTui_Error_Null_Path_Name = TO_STRING(TUI_ERROR_NULL_PATH);
const char* kTui_Error_Null_Pixels_Name = TO_STRING(TUI_ERROR_NULL_PIXELS);
const char* kTui_Error_Null_String_Name = TO_STRING(TUI_ERROR_NULL_STRING);
const char* kTui_Error_Null_Target_Image_Name = TO_STRING(TUI_ERROR_NULL_TARGET_IMAGE);
const char* kTui_Error_Null_Target_Panel_Name = TO_STRING(TUI_ERROR_NULL_TARGET_PANEL);
const char* kTui_Error_Null_Texture_Name = TO_STRING(TUI_ERROR_NULL_TEXTURE);
const char* kTui_Error_Null_Texture_Coordinates_Name = TO_STRING(TUI_ERROR_NULL_TEXTURE_COORDINATES);
const char* kTui_Error_Palette_Required_Name = TO_STRING(TUI_ERROR_PALETTE_REQUIRED);
const char* kTui_Error_Resize_Image_Failure_Name = TO_STRING(TUI_ERROR_RESIZE_IMAGE_FAILURE);
const char* kTui_Error_Unavailable_Graphics_API_Name = TO_STRING(TUI_ERROR_UNAVAILABLE_GRAPHICS_API);
const char* kTui_Error_Unavailable_Graphics_API_Version_Name = TO_STRING(TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION);
const char* kTui_Error_Unmatching_Atlas_Window_Name = TO_STRING(TUI_ERROR_UNMATCHING_ATLAS_WINDOW);
const char* kTui_Error_Unmatching_Palette_Window_Name = TO_STRING(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE);
const char* kTui_Error_Unmatching_Panel_Window_Name = TO_STRING(TUI_ERROR_UNMATCHING_PANEL_WINDOW);
const char* kTui_Error_Unsupported_Cursor_Shape_Name = TO_STRING(TUI_ERROR_UNSUPPORTED_CURSOR_SHAPE);
const char* kTui_Error_Unsupported_Raw_Mouse_Motion_Name = TO_STRING(TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION);

const char* kTui_Error_Unknown_Description = "An unkown error has occured. This may be a bug with TUIC library.";
const char* kTui_Error_None_Description = "No error has occured.";
const char* kTui_Error_Already_Initialized_Description = "TUIC has already been initialized.";
const char* kTui_Error_Dangling_Atlas_Description = "Attempting to destroy a TuiWindow with one or more dangling TuiAtlas.";
const char* kTui_Error_Dangling_Cursor_Description = "Attempting to terminate TUIC with one or more dangling TuiCursor.";
const char* kTui_Error_Dangling_Window_Description = "Attempting to terminate TUIC with one or more dangling TuiWindow.";
const char* kTui_Error_Dangling_Palette_Description = "Attempting to destroy a TuiWindow with one or more dangling TuiPalette.";
const char* kTui_Error_Dangling_Panel_Description = "Attempting to destroy a TuiWindow with one or more dangling TuiPanel.";
const char* kTui_Error_Dangling_Texture_Description = "Attempting to destroy a TuiWindow with one or more dangling TuiTexture.";
const char* kTui_Error_Desktop_Format_Unavailable_Description = "A desktop format unavailable error has occured.";
const char* kTui_Error_Desktop_Not_Initialized_Description = "Attempting to use a desktop related function when the desktop system is not initialized.";
const char* kTui_Error_Desktop_No_Graphics_Context_Description = "Attempting to use a graphics API without a graphics context. This is a bug with TUIC library.";
const char* kTui_Error_Desktop_Out_Of_Memory_Description = "The desktop system is out of memory.";
const char* kTui_Error_Desktop_Platform_Description = "An action is not possible on the current desktop operating system.";
const char* kTui_Error_Graphics_Backend_Specific_Description = "An error has occured that is specific the the active graphics backend.";
const char* kTui_Error_Incompatible_Blend_Mode_Description = "Attempting to draw a batch with a TuiDetailMode and TuiBlendMode that are not compatible.";
const char* kTui_Error_Incompatible_Images_Description = "Attempting to use images with unmatching channel counts.";
const char* kTui_Error_Invalid_Aspect_Ratio_Description = "Aspect ratio numerator and denominator must be greater than zero.";
const char* kTui_Error_Invalid_Atlas_Type_Description = "The given TuiAtlasType is invalid.";
const char* kTui_Error_Invalid_Batch_Data_Dimensions_Description = "Batch data dimensions must be greater than zero.";
const char* kTui_Error_Invalid_Batch_Dimensions_Description = "TuiBatch dimensions must be greater than zero.";
const char* kTui_Error_Invalid_Batch_Setter_Description = "Setter function used for the incorrect detail mode for a TuiBatch.";
const char* kTui_Error_Invalid_Blend_Mode_Description = "The TuiBlendMode is invalid.";
const char* kTui_Error_Invalid_Button_State_Description = "The TuiButtonState is invalid.";
const char* kTui_Error_Invalid_Channel_Count_Description = "The channel count is not supported by the operation.";
const char* kTui_Error_Invalid_Codepage_Dimensions_Description = "The image pixel dimensions must be divisible by 16.";
const char* kTui_Error_Invalid_Cursor_Mode_Description = "The TuiCursorMode is invalid.";
const char* kTui_Error_Invalid_Cursor_Shape_Description = "The TuiCursorShape is invalid.";
const char* kTui_Error_Invalid_Detail_Flag_Description = "The TuiDetailFlag is invalid.";
const char* kTui_Error_Invalid_Detail_Mode_Description = "The TuiDetailMode is invalid.";
const char* kTui_Error_Invalid_Filter_Mode_Description = "The TuiFilterMode is invalid.";
const char* kTui_Error_Invalid_Glyph_Count_Description = "The glyph count must be greater than zero.";
const char* kTui_Error_Invalid_Glyph_Dimensions_Description = "The glyph dimensions of a TuiAtlas must be greater than zero.";
const char* kTui_Error_Invalid_Image_Dimensions_Description = "The pixel dimensions of a TuiImage must be greater than zero.";
const char* kTui_Error_Invalid_Window_Dimensions_Description = "The pixel dimensions of a TuiWindow must be greater than zero.";
const char* kTui_Error_Invalid_Joystick_Hat_State_Description = "The TuiJoyustickHatState is invalid.";
const char* kTui_Error_Invalid_Joystick_Id_Description = "The TuiJoystickId is invalid.";
const char* kTui_Error_Invalid_Key_Description = "The TuiKey is invalid.";
const char* kTui_Error_Invalid_Key_Mod_Description = "The TuiKeyMod is invalid.";
const char* kTui_Error_Invalid_Mouse_Button_Description = "The TuiMouseButton is invalid.";
const char* kTui_Error_Invalid_Palette_Color_Count_Description = "The color count of a TuiPalette must be greater than 0 and less than or equal to 256.";
const char* kTui_Error_Invalid_Panel_Dimensions_Description = "The pixel dimensions of a TuiPanel must be greater than zero.";
const char* kTui_Error_Invalid_Pixel_Dimensions_Description = "The dimensions of a pixel array must be greater than zero.";
const char* kTui_Error_Invalid_Time_Description = "The system time must be greater than or equal to 0.0 and less than 18446744073.0.";
const char* kTui_Error_Invalid_Transparent_Framebuffer_Opacity_Description = "The opacity of a window with a transparent framebuffer must be 1.0f.";
const char* kTui_Error_Invalid_Window_Size_Limits_Description = "Window size limits must be greater than zero and the max limits must be greater than the min limits.";
const char* kTui_Error_Load_Image_Failure_Description = "The TuiImage failed to be loaded from a file.";
const char* kTui_Error_Load_Image_Unexpected_Channels_Description = "The TuiImage was loaded from a file with an unexpected channel count.";
const char* kTui_Error_No_Current_Context_Description = "An operation was attempted without a graphics context. This is a bug in TUIC library.";
const char* kTui_Error_Null_Atlas_Description = "The TuiAtlas is NULL.";
const char* kTui_Error_Null_Batch_Description = "The TuiBatch is NULL.";
const char* kTui_Error_Null_Batch_Data_Description = "The batch data array is NULL.";
const char* kTui_Error_Null_Colors_Description = "The colors array is NULL.";
const char* kTui_Error_Null_Cursor_Description = "The TuiCursor is NULL.";
const char* kTui_Error_Null_Glyph_Bounding_Boxes_Description = "The glyph bounding boxes array is NULL.";
const char* kTui_Error_Null_Image_Description = "The TuiImage is NULL.";
const char* kTui_Error_Null_Window_Description = "The TuiWindow is NULL.";
const char* kTui_Error_Null_Palette_Description = "The TuiPalette is NULL.";
const char* kTui_Error_Null_Panel_Description = "The TuiPanel is NULL.";
const char* kTui_Error_Null_Path_Description = "The file path is NULL.";
const char* kTui_Error_Null_Pixels_Description = "The pixels array is NULL.";
const char* kTui_Error_Null_String_Description = "The string is NULL";
const char* kTui_Error_Null_Target_Image_Description = "The target TuiImage is NULL.";
const char* kTui_Error_Null_Target_Panel_Description = "The target TuiPanel is NULL.";
const char* kTui_Error_Null_Texture_Description = "The TuiTexture is NULL.";
const char* kTui_Error_Null_Texture_Coordinates_Description = "The texture coordinates array is NULL.";
const char* kTui_Error_Palette_Required_Description = "Attempting to render batch data without a TuiPalette when one is required for its TuiDetailMode.";
const char* kTui_Error_Resize_Image_Failure_Description = "Failed to resize a TuiImage.";
const char* kTui_Error_Unavailable_Graphics_API_Description = "The graphics API is unavailable on this device.";
const char* kTui_Error_Unavailable_Graphics_API_Version_Description = "The graphics API version is unavailable on this device.";
const char* kTui_Error_Unmatching_Atlas_Window_Description = "The TuiAtlas belongs to the graphics context of a different TuiWindow.";
const char* kTui_Error_Unmatching_Palette_Window_Description = "The TuiPalette belongs to the graphics context of a different TuiWindow.";
const char* kTui_Error_Unmatching_Panel_Window_Description = "The TuiPanel belongs to the graphics context of a different TuiWindow.";
const char* kTui_Error_Unsupported_Cursor_Shape_Description = "The current desktop platform does not support the given standard TuiCursorShape.";
const char* kTui_Error_Unsupported_Raw_Mouse_Motion_Description = "Raw mouse motion is not supported on this device.";

TuiBoolean tuiErrorCodeIsValid(TuiErrorCode code)
{
	if (
		(code >= TUI_ERROR_FIRST) &&
		(code <= TUI_ERROR_LAST)
		)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

const char* tuiErrorCodeToString(TuiErrorCode error_code)
{
	switch (error_code)
	{
	case TUI_ERROR_UNKNOWN:
		return kTui_Error_Unknown_Name;
	case TUI_ERROR_NONE:
		return kTui_Error_None_Name;
	case TUI_ERROR_ALREADY_INITIALIZED:
		return kTui_Error_Already_Initialized_Name;
	case TUI_ERROR_DANGLING_ATLAS:
		return kTui_Error_Dangling_Atlas_Name;
	case TUI_ERROR_DANGLING_CURSOR:
		return kTui_Error_Dangling_Cursor_Name;
	case TUI_ERROR_DANGLING_WINDOW:
		return kTui_Error_Dangling_Window_Name;
	case TUI_ERROR_DANGLING_PALETTE:
		return kTui_Error_Dangling_Palette_Name;
	case TUI_ERROR_DANGLING_PANEL:
		return kTui_Error_Dangling_Panel_Name;
	case TUI_ERROR_DANGLING_TEXTURE:
		return kTui_Error_Dangling_Texture_Name;
	case TUI_ERROR_DESKTOP_FORMAT_UNAVAILABLE:
		return kTui_Error_Desktop_Not_Initialized_Name;
	case TUI_ERROR_DESKTOP_NOT_INITIALIZED:
		return kTui_Error_Desktop_Not_Initialized_Name;
	case TUI_ERROR_DESKTOP_NO_GRAPHICS_CONTEXT:
		return kTui_Error_Desktop_No_Graphics_Context_Name;
	case TUI_ERROR_DESKTOP_OUT_OF_MEMORY:
		return kTui_Error_Desktop_Out_Of_Memory_Name;
	case TUI_ERROR_DESKTOP_PLATFORM:
		return kTui_Error_Desktop_Platform_Name;
	case TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC:
		return kTui_Error_Graphics_Backend_Specific_Name;
	case TUI_ERROR_INCOMPATIBLE_BLEND_MODE:
		return kTui_Error_Incompatible_Blend_Mode_Name;
	case TUI_ERROR_INVALID_ASPECT_RATIO:
		return kTui_Error_Invalid_Aspect_Ratio_Name;
	case TUI_ERROR_INVALID_ATLAS_TYPE:
		return kTui_Error_Invalid_Atlas_Type_Name;
	case TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS:
		return kTui_Error_Invalid_Batch_Dimensions_Name;
	case TUI_ERROR_INVALID_BATCH_SETTER:
		return kTui_Error_Invalid_Batch_Setter_Name;
	case TUI_ERROR_INVALID_BLEND_MODE:
		return kTui_Error_Invalid_Blend_Mode_Name;
	case TUI_ERROR_INVALID_BUTTON_STATE:
		return kTui_Error_Invalid_Channel_Count_Name;
	case TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS:
		return kTui_Error_Invalid_Codepage_Dimensions_Name;
	case TUI_ERROR_INVALID_CURSOR_MODE:
		return kTui_Error_Invalid_Cursor_Mode_Name;
	case TUI_ERROR_INVALID_CURSOR_SHAPE:
		return kTui_Error_Invalid_Cursor_Shape_Name;
	case TUI_ERROR_INVALID_DETAIL_FLAG:
		return kTui_Error_Invalid_Detail_Flag_Name;
	case TUI_ERROR_INVALID_DETAIL_MODE:
		return kTui_Error_Invalid_Detail_Mode_Name;
	case TUI_ERROR_INVALID_FILTER_MODE:
		return kTui_Error_Invalid_Filter_Mode_Name;
	case TUI_ERROR_INVALID_GLYPH_COUNT:
		return kTui_Error_Invalid_Glyph_Count_Name;
	case TUI_ERROR_INVALID_GLYPH_DIMENSIONS:
		return kTui_Error_Invalid_Glyph_Dimensions_Name;
	case TUI_ERROR_INVALID_IMAGE_DIMENSIONS:
		return kTui_Error_Invalid_Image_Dimensions_Name;
	case TUI_ERROR_INVALID_WINDOW_DIMENSIONS:
		return kTui_Error_Invalid_Window_Dimensions_Name;
	case TUI_ERROR_INVALID_JOYSTICK_HAT_STATE:
		return kTui_Error_Invalid_Joystick_Hat_State_Name;
	case TUI_ERROR_INVALID_JOYSTICK_ID:
		return kTui_Error_Invalid_Joystick_Id_Name;
	case TUI_ERROR_INVALID_KEY:
		return kTui_Error_Invalid_Key_Name;
	case TUI_ERROR_INVALID_KEY_MOD:
		return kTui_Error_Invalid_Key_Mod_Name;
	case TUI_ERROR_INVALID_MOUSE_BUTTON:
		return kTui_Error_Invalid_Mouse_Button_Name;
	case TUI_ERROR_INVALID_PALETTE_COLOR_COUNT:
		return kTui_Error_Invalid_Palette_Color_Count_Name;
	case TUI_ERROR_INVALID_PANEL_DIMENSIONS:
		return kTui_Error_Invalid_Panel_Dimensions_Name;
	case TUI_ERROR_INVALID_PIXEL_DIMENSIONS:
		return kTui_Error_Invalid_Pixel_Dimensions_Name;
	case TUI_ERROR_INVALID_TIME:
		return kTui_Error_Invalid_Time_Name;
	case TUI_ERROR_INVALID_TRANSPARENT_FRAMEBUFFER_OPACITY:
		return kTui_Error_Invalid_Transparent_Framebuffer_Opacity_Name;
	case TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS:
		return kTui_Error_Invalid_Window_Size_Limits_Name;
	case TUI_ERROR_LOAD_IMAGE_FAILURE:
		return kTui_Error_Load_Image_Failure_Name;
	case TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS:
		return kTui_Error_Load_Image_Unexpected_Channels_Name;
	case TUI_ERROR_NO_CURRENT_CONTEXT:
		return kTui_Error_No_Current_Context_Name;
	case TUI_ERROR_NULL_ATLAS:
		return kTui_Error_Null_Atlas_Name;
	case TUI_ERROR_NULL_BATCH:
		return kTui_Error_Null_Batch_Name;
	case TUI_ERROR_NULL_BATCH_DATA:
		return kTui_Error_Null_Batch_Data_Name;
	case TUI_ERROR_NULL_CURSOR:
		return kTui_Error_Null_Cursor_Name;
	case TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES:
		return kTui_Error_Null_Glyph_Bounding_Boxes_Name;
	case TUI_ERROR_NULL_IMAGE:
		return kTui_Error_Null_Image_Name;
	case TUI_ERROR_NULL_WINDOW:
		return kTui_Error_Null_Window_Name;
	case TUI_ERROR_NULL_PALETTE:
		return kTui_Error_Null_Palette_Name;
	case TUI_ERROR_NULL_PANEL:
		return kTui_Error_Null_Panel_Name;
	case TUI_ERROR_NULL_PATH:
		return kTui_Error_Null_Path_Name;
	case TUI_ERROR_NULL_PIXELS:
		return kTui_Error_Null_Pixels_Name;
	case TUI_ERROR_NULL_STRING:
		return kTui_Error_Null_String_Name;
	case TUI_ERROR_NULL_TARGET_IMAGE:
		return kTui_Error_Null_Target_Image_Name;
	case TUI_ERROR_NULL_TARGET_PANEL:
		return kTui_Error_Null_Target_Panel_Name;
	case TUI_ERROR_NULL_TEXTURE:
		return kTui_Error_Null_Texture_Name;
	case TUI_ERROR_NULL_TEXTURE_COORDINATES:
		return kTui_Error_Null_Texture_Coordinates_Name;
	case TUI_ERROR_PALETTE_REQUIRED:
		return kTui_Error_Palette_Required_Name;
	case TUI_ERROR_RESIZE_IMAGE_FAILURE:
		return kTui_Error_Resize_Image_Failure_Name;
	case TUI_ERROR_UNAVAILABLE_GRAPHICS_API:
		return kTui_Error_Unavailable_Graphics_API_Name;
	case TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION:
		return kTui_Error_Unavailable_Graphics_API_Version_Name;
	case TUI_ERROR_UNMATCHING_ATLAS_WINDOW:
		return kTui_Error_Unmatching_Atlas_Window_Name;
	case TUI_ERROR_UNMATCHING_PALETTE_INSTANCE:
		return kTui_Error_Unmatching_Palette_Window_Name;
	case TUI_ERROR_UNMATCHING_PANEL_WINDOW:
		return kTui_Error_Unmatching_Panel_Window_Name;
	case TUI_ERROR_UNSUPPORTED_CURSOR_SHAPE:
		return kTui_Error_Unsupported_Cursor_Shape_Name;
	case TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION:
		return kTui_Error_Unsupported_Raw_Mouse_Motion_Name;
	default:
		return kTui_Error_Unknown_Name;
	}
}

int tuiStringToErrorCode(const char* str)
{
	if (strcmp(str, kTui_Error_Unknown_Name) == 0)
	{
		return TUI_ERROR_UNKNOWN;
	}
	else if (strcmp(str, kTui_Error_None_Name) == 0)
	{
		return TUI_ERROR_NONE;
	}
	else if (strcmp(str, kTui_Error_Already_Initialized_Name) == 0)
	{
		return TUI_ERROR_ALREADY_INITIALIZED;
	}
	else if (strcmp(str, kTui_Error_Dangling_Atlas_Name) == 0)
	{
		return TUI_ERROR_DANGLING_ATLAS;
	}
	else if (strcmp(str, kTui_Error_Dangling_Cursor_Name) == 0)
	{
		return TUI_ERROR_DANGLING_CURSOR;
	}
	else if (strcmp(str, kTui_Error_Dangling_Window_Name) == 0)
	{
		return TUI_ERROR_DANGLING_WINDOW;
	}
	else if (strcmp(str, kTui_Error_Dangling_Palette_Name) == 0)
	{
		return TUI_ERROR_DANGLING_PALETTE;
	}
	else if (strcmp(str, kTui_Error_Dangling_Panel_Name) == 0)
	{
		return TUI_ERROR_DANGLING_PANEL;
	}
	else if (strcmp(str, kTui_Error_Dangling_Texture_Name) == 0)
	{
		return TUI_ERROR_DANGLING_TEXTURE;
	}
	else if (strcmp(str, kTui_Error_Desktop_Format_Unavailable_Name) == 0)
	{
		return TUI_ERROR_DESKTOP_FORMAT_UNAVAILABLE;
	}
	else if (strcmp(str, kTui_Error_Desktop_Not_Initialized_Name) == 0)
	{
		return TUI_ERROR_DESKTOP_NOT_INITIALIZED;
	}
	else if (strcmp(str, kTui_Error_Desktop_No_Graphics_Context_Name) == 0)
	{
		return TUI_ERROR_DESKTOP_NO_GRAPHICS_CONTEXT;
	}
	else if (strcmp(str, kTui_Error_Desktop_Out_Of_Memory_Name) == 0)
	{
		return TUI_ERROR_DESKTOP_OUT_OF_MEMORY;
	}
	else if (strcmp(str, kTui_Error_Desktop_Platform_Name) == 0)
	{
		return TUI_ERROR_DESKTOP_PLATFORM;
	}
	else if (strcmp(str, kTui_Error_Graphics_Backend_Specific_Name) == 0)
	{
		return TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC;
	}
	else if (strcmp(str, kTui_Error_Incompatible_Blend_Mode_Name) == 0)
	{
		return TUI_ERROR_INCOMPATIBLE_BLEND_MODE;
	}
	else if (strcmp(str, kTui_Error_Incompatible_Images_Name) == 0)
	{
		return TUI_ERROR_INCOMPATIBLE_IMAGES;
	}
	else if (strcmp(str, kTui_Error_Invalid_Aspect_Ratio_Name) == 0)
	{
		return TUI_ERROR_INVALID_ASPECT_RATIO;
	}
	else if (strcmp(str, kTui_Error_Invalid_Atlas_Type_Name) == 0)
	{
		return TUI_ERROR_INVALID_ATLAS_TYPE;
	}
	else if (strcmp(str, kTui_Error_Invalid_Batch_Data_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS;
	}
	else if (strcmp(str, kTui_Error_Invalid_Batch_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_BATCH_DIMENSIONS;
	}
	else if (strcmp(str, kTui_Error_Invalid_Batch_Setter_Name) == 0)
	{
		return TUI_ERROR_INVALID_BATCH_SETTER;
	}
	else if (strcmp(str, kTui_Error_Invalid_Blend_Mode_Name) == 0)
	{
		return TUI_ERROR_INVALID_BLEND_MODE;
	}
	else if (strcmp(str, kTui_Error_Invalid_Button_State_Name) == 0)
	{
		return TUI_ERROR_INVALID_BUTTON_STATE;
	}
	else if (strcmp(str, kTui_Error_Invalid_Channel_Count_Name) == 0)
	{
		return TUI_ERROR_INVALID_CHANNEL_COUNT;
	}
	else if (strcmp(str, kTui_Error_Invalid_Codepage_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS;
	}
	else if (strcmp(str, kTui_Error_Invalid_Cursor_Mode_Name) == 0)
	{
		return TUI_ERROR_INVALID_CURSOR_MODE;
	}
	else if (strcmp(str, kTui_Error_Invalid_Cursor_Shape_Name) == 0)
	{
		return TUI_ERROR_INVALID_CURSOR_SHAPE;
	}
	else if (strcmp(str, kTui_Error_Invalid_Detail_Flag_Name) == 0)
	{
		return TUI_ERROR_INVALID_DETAIL_FLAG;
	}
	else if (strcmp(str, kTui_Error_Invalid_Detail_Mode_Name) == 0)
	{
		return TUI_ERROR_INVALID_DETAIL_MODE;
	}
	else if (strcmp(str, kTui_Error_Invalid_Filter_Mode_Name) == 0)
	{
		return TUI_ERROR_INVALID_FILTER_MODE;
	}
	else if (strcmp(str, kTui_Error_Invalid_Glyph_Count_Name) == 0)
	{
		return TUI_ERROR_INVALID_GLYPH_COUNT;
	}
	else if (strcmp(str, kTui_Error_Invalid_Glyph_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_GLYPH_DIMENSIONS;
	}
	else if (strcmp(str, kTui_Error_Invalid_Image_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_IMAGE_DIMENSIONS;
	}
	else if (strcmp(str, kTui_Error_Invalid_Window_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_WINDOW_DIMENSIONS;
	}
	else if (strcmp(str, kTui_Error_Invalid_Joystick_Hat_State_Name) == 0)
	{
		return TUI_ERROR_INVALID_JOYSTICK_HAT_STATE;
	}
	else if (strcmp(str, kTui_Error_Invalid_Joystick_Id_Name) == 0)
	{
		return TUI_ERROR_INVALID_JOYSTICK_ID;
	}
	else if (strcmp(str, kTui_Error_Invalid_Key_Name) == 0)
	{
		return TUI_ERROR_INVALID_KEY;
	}
	else if (strcmp(str, kTui_Error_Invalid_Key_Mod_Name) == 0)
	{
		return TUI_ERROR_INVALID_KEY_MOD;
	}
	else if (strcmp(str, kTui_Error_Invalid_Mouse_Button_Name) == 0)
	{
		return TUI_ERROR_INVALID_MOUSE_BUTTON;
	}
	else if (strcmp(str, kTui_Error_Invalid_Palette_Color_Count_Name) == 0)
	{
		return TUI_ERROR_INVALID_PALETTE_COLOR_COUNT;
	}
	else if (strcmp(str, kTui_Error_Invalid_Panel_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_PANEL_DIMENSIONS;
	}
	else if (strcmp(str, kTui_Error_Invalid_Pixel_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_PIXEL_DIMENSIONS;
	}
	else if (strcmp(str, kTui_Error_Invalid_Time_Name) == 0)
	{
		return TUI_ERROR_INVALID_TIME;
	}
	else if (strcmp(str, kTui_Error_Invalid_Transparent_Framebuffer_Opacity_Name) == 0)
	{
		return TUI_ERROR_INVALID_TRANSPARENT_FRAMEBUFFER_OPACITY;
	}
	else if (strcmp(str, kTui_Error_Invalid_Window_Size_Limits_Name) == 0)
	{
		return TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS;
	}
	else if (strcmp(str, kTui_Error_Load_Image_Failure_Name) == 0)
	{
		return TUI_ERROR_LOAD_IMAGE_FAILURE;
	}
	else if (strcmp(str, kTui_Error_Load_Image_Unexpected_Channels_Name) == 0)
	{
		return TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS;
	}
	else if (strcmp(str, kTui_Error_No_Current_Context_Name) == 0)
	{
		return TUI_ERROR_NO_CURRENT_CONTEXT;
	}
	else if (strcmp(str, kTui_Error_Null_Atlas_Name) == 0)
	{
		return TUI_ERROR_NULL_ATLAS;
	}
	else if (strcmp(str, kTui_Error_Null_Batch_Name) == 0)
	{
		return TUI_ERROR_NULL_BATCH;
	}
	else if (strcmp(str, kTui_Error_Null_Batch_Data_Name) == 0)
	{
		return TUI_ERROR_NULL_BATCH_DATA;
	}
	else if (strcmp(str, kTui_Error_Null_Colors_Name) == 0)
	{
		return TUI_ERROR_NULL_COLORS;
	}
	else if (strcmp(str, kTui_Error_Null_Cursor_Name) == 0)
	{
		return TUI_ERROR_NULL_CURSOR;
	}
	else if (strcmp(str, kTui_Error_Null_Glyph_Bounding_Boxes_Name) == 0)
	{
		return TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES;
	}
	else if (strcmp(str, kTui_Error_Null_Image_Name) == 0)
	{
		return TUI_ERROR_NULL_IMAGE;
	}
	else if (strcmp(str, kTui_Error_Null_Window_Name) == 0)
	{
		return TUI_ERROR_NULL_WINDOW;
	}
	else if (strcmp(str, kTui_Error_Null_Palette_Name) == 0)
	{
		return TUI_ERROR_NULL_PALETTE;
	}
	else if (strcmp(str, kTui_Error_Null_Panel_Name) == 0)
	{
		return TUI_ERROR_NULL_PANEL;
	}
	else if (strcmp(str, kTui_Error_Null_Path_Name) == 0)
	{
		return TUI_ERROR_NULL_PATH;
	}
	else if (strcmp(str, kTui_Error_Null_Pixels_Name) == 0)
	{
		return TUI_ERROR_NULL_PIXELS;
	}
	else if (strcmp(str, kTui_Error_Null_String_Name) == 0)
	{
		return TUI_ERROR_NULL_STRING;
	}
	else if (strcmp(str, kTui_Error_Null_Target_Image_Name) == 0)
	{
		return TUI_ERROR_NULL_TARGET_IMAGE;
	}
	else if (strcmp(str, kTui_Error_Null_Target_Panel_Name) == 0)
	{
		return TUI_ERROR_NULL_TARGET_PANEL;
	}
	else if (strcmp(str, kTui_Error_Null_Texture_Name) == 0)
	{
		return TUI_ERROR_NULL_TEXTURE;
	}
	else if (strcmp(str, kTui_Error_Null_Texture_Coordinates_Name) == 0)
	{
		return TUI_ERROR_NULL_TEXTURE_COORDINATES;
	}
	else if (strcmp(str, kTui_Error_Palette_Required_Name) == 0)
	{
		return TUI_ERROR_PALETTE_REQUIRED;
	}
	else if (strcmp(str, kTui_Error_Resize_Image_Failure_Name) == 0)
	{
		return TUI_ERROR_RESIZE_IMAGE_FAILURE;
	}
	else if (strcmp(str, kTui_Error_Unavailable_Graphics_API_Name) == 0)
	{
		return TUI_ERROR_UNAVAILABLE_GRAPHICS_API;
	}
	else if (strcmp(str, kTui_Error_Unavailable_Graphics_API_Version_Name) == 0)
	{
		return TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION;
	}
	else if (strcmp(str, kTui_Error_Unmatching_Atlas_Window_Name) == 0)
	{
		return TUI_ERROR_UNMATCHING_ATLAS_WINDOW;
	}
	else if (strcmp(str, kTui_Error_Unmatching_Palette_Window_Name) == 0)
	{
		return TUI_ERROR_UNMATCHING_PALETTE_INSTANCE;
	}
	else if (strcmp(str, kTui_Error_Unmatching_Panel_Window_Name) == 0)
	{
		return TUI_ERROR_UNMATCHING_PANEL_WINDOW;
	}
	else if (strcmp(str, kTui_Error_Unsupported_Cursor_Shape_Name) == 0)
	{
		return TUI_ERROR_UNSUPPORTED_CURSOR_SHAPE;
	}
	else if (strcmp(str, kTui_Error_Unsupported_Raw_Mouse_Motion_Name) == 0)
	{
		return TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION;
	}

	return TUI_ERROR_UNKNOWN;
}

const char* tuiErrorCodeGetDescription(int error_code)
{
	switch (error_code)
	{
	case TUI_ERROR_UNKNOWN:
		return kTui_Error_Unknown_Description;
	case TUI_ERROR_NONE:
		return kTui_Error_None_Description;
	case TUI_ERROR_ALREADY_INITIALIZED:
		return kTui_Error_Already_Initialized_Description;
	case TUI_ERROR_DANGLING_ATLAS:
		return kTui_Error_Dangling_Atlas_Description;
	case TUI_ERROR_DANGLING_CURSOR:
		return kTui_Error_Dangling_Cursor_Description;
	case TUI_ERROR_DANGLING_WINDOW:
		return kTui_Error_Dangling_Window_Description;
	case TUI_ERROR_DANGLING_PALETTE:
		return kTui_Error_Dangling_Palette_Description;
	case TUI_ERROR_DANGLING_PANEL:
		return kTui_Error_Dangling_Panel_Description;
	case TUI_ERROR_DANGLING_TEXTURE:
		return kTui_Error_Dangling_Texture_Description;
	case TUI_ERROR_DESKTOP_FORMAT_UNAVAILABLE:
		return kTui_Error_Desktop_Not_Initialized_Description;
	case TUI_ERROR_DESKTOP_NOT_INITIALIZED:
		return kTui_Error_Desktop_Not_Initialized_Description;
	case TUI_ERROR_DESKTOP_NO_GRAPHICS_CONTEXT:
		return kTui_Error_Desktop_No_Graphics_Context_Description;
	case TUI_ERROR_DESKTOP_OUT_OF_MEMORY:
		return kTui_Error_Desktop_Out_Of_Memory_Description;
	case TUI_ERROR_DESKTOP_PLATFORM:
		return kTui_Error_Desktop_Platform_Description;
	case TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC:
		return kTui_Error_Graphics_Backend_Specific_Description;
	case TUI_ERROR_INCOMPATIBLE_BLEND_MODE:
		return kTui_Error_Incompatible_Blend_Mode_Description;
	case TUI_ERROR_INVALID_ASPECT_RATIO:
		return kTui_Error_Invalid_Aspect_Ratio_Description;
	case TUI_ERROR_INVALID_ATLAS_TYPE:
		return kTui_Error_Invalid_Atlas_Type_Description;
	case TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS:
		return kTui_Error_Invalid_Batch_Dimensions_Description;
	case TUI_ERROR_INVALID_BATCH_SETTER:
		return kTui_Error_Invalid_Batch_Setter_Description;
	case TUI_ERROR_INVALID_BLEND_MODE:
		return kTui_Error_Invalid_Blend_Mode_Description;
	case TUI_ERROR_INVALID_BUTTON_STATE:
		return kTui_Error_Invalid_Channel_Count_Description;
	case TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS:
		return kTui_Error_Invalid_Codepage_Dimensions_Description;
	case TUI_ERROR_INVALID_CURSOR_MODE:
		return kTui_Error_Invalid_Cursor_Mode_Description;
	case TUI_ERROR_INVALID_CURSOR_SHAPE:
		return kTui_Error_Invalid_Cursor_Shape_Description;
	case TUI_ERROR_INVALID_DETAIL_FLAG:
		return kTui_Error_Invalid_Detail_Flag_Description;
	case TUI_ERROR_INVALID_DETAIL_MODE:
		return kTui_Error_Invalid_Detail_Mode_Description;
	case TUI_ERROR_INVALID_FILTER_MODE:
		return kTui_Error_Invalid_Filter_Mode_Description;
	case TUI_ERROR_INVALID_GLYPH_COUNT:
		return kTui_Error_Invalid_Glyph_Count_Description;
	case TUI_ERROR_INVALID_GLYPH_DIMENSIONS:
		return kTui_Error_Invalid_Glyph_Dimensions_Description;
	case TUI_ERROR_INVALID_IMAGE_DIMENSIONS:
		return kTui_Error_Invalid_Image_Dimensions_Description;
	case TUI_ERROR_INVALID_WINDOW_DIMENSIONS:
		return kTui_Error_Invalid_Window_Dimensions_Description;
	case TUI_ERROR_INVALID_JOYSTICK_HAT_STATE:
		return kTui_Error_Invalid_Joystick_Hat_State_Description;
	case TUI_ERROR_INVALID_JOYSTICK_ID:
		return kTui_Error_Invalid_Joystick_Id_Description;
	case TUI_ERROR_INVALID_KEY:
		return kTui_Error_Invalid_Key_Description;
	case TUI_ERROR_INVALID_KEY_MOD:
		return kTui_Error_Invalid_Key_Mod_Description;
	case TUI_ERROR_INVALID_MOUSE_BUTTON:
		return kTui_Error_Invalid_Mouse_Button_Description;
	case TUI_ERROR_INVALID_PALETTE_COLOR_COUNT:
		return kTui_Error_Invalid_Palette_Color_Count_Description;
	case TUI_ERROR_INVALID_PANEL_DIMENSIONS:
		return kTui_Error_Invalid_Panel_Dimensions_Description;
	case TUI_ERROR_INVALID_PIXEL_DIMENSIONS:
		return kTui_Error_Invalid_Pixel_Dimensions_Description;
	case TUI_ERROR_INVALID_TIME:
		return kTui_Error_Invalid_Time_Description;
	case TUI_ERROR_INVALID_TRANSPARENT_FRAMEBUFFER_OPACITY:
		return kTui_Error_Invalid_Transparent_Framebuffer_Opacity_Description;
	case TUI_ERROR_INVALID_WINDOW_SIZE_LIMITS:
		return kTui_Error_Invalid_Window_Size_Limits_Description;
	case TUI_ERROR_LOAD_IMAGE_FAILURE:
		return kTui_Error_Load_Image_Failure_Description;
	case TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS:
		return kTui_Error_Load_Image_Unexpected_Channels_Description;
	case TUI_ERROR_NO_CURRENT_CONTEXT:
		return kTui_Error_No_Current_Context_Description;
	case TUI_ERROR_NULL_ATLAS:
		return kTui_Error_Null_Atlas_Description;
	case TUI_ERROR_NULL_BATCH:
		return kTui_Error_Null_Batch_Description;
	case TUI_ERROR_NULL_BATCH_DATA:
		return kTui_Error_Null_Batch_Data_Description;
	case TUI_ERROR_NULL_CURSOR:
		return kTui_Error_Null_Cursor_Description;
	case TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES:
		return kTui_Error_Null_Glyph_Bounding_Boxes_Description;
	case TUI_ERROR_NULL_IMAGE:
		return kTui_Error_Null_Image_Description;
	case TUI_ERROR_NULL_WINDOW:
		return kTui_Error_Null_Window_Description;
	case TUI_ERROR_NULL_PALETTE:
		return kTui_Error_Null_Palette_Description;
	case TUI_ERROR_NULL_PANEL:
		return kTui_Error_Null_Panel_Description;
	case TUI_ERROR_NULL_PATH:
		return kTui_Error_Null_Path_Description;
	case TUI_ERROR_NULL_PIXELS:
		return kTui_Error_Null_Pixels_Description;
	case TUI_ERROR_NULL_STRING:
		return kTui_Error_Null_String_Description;
	case TUI_ERROR_NULL_TARGET_IMAGE:
		return kTui_Error_Null_Target_Image_Description;
	case TUI_ERROR_NULL_TARGET_PANEL:
		return kTui_Error_Null_Target_Panel_Description;
	case TUI_ERROR_NULL_TEXTURE:
		return kTui_Error_Null_Texture_Description;
	case TUI_ERROR_NULL_TEXTURE_COORDINATES:
		return kTui_Error_Null_Texture_Coordinates_Description;
	case TUI_ERROR_PALETTE_REQUIRED:
		return kTui_Error_Palette_Required_Description;
	case TUI_ERROR_RESIZE_IMAGE_FAILURE:
		return kTui_Error_Resize_Image_Failure_Description;
	case TUI_ERROR_UNAVAILABLE_GRAPHICS_API:
		return kTui_Error_Unavailable_Graphics_API_Description;
	case TUI_ERROR_UNAVAILABLE_GRAPHICS_API_VERSION:
		return kTui_Error_Unavailable_Graphics_API_Version_Description;
	case TUI_ERROR_UNMATCHING_ATLAS_WINDOW:
		return kTui_Error_Unmatching_Atlas_Window_Description;
	case TUI_ERROR_UNMATCHING_PALETTE_INSTANCE:
		return kTui_Error_Unmatching_Palette_Window_Description;
	case TUI_ERROR_UNMATCHING_PANEL_WINDOW:
		return kTui_Error_Unmatching_Panel_Window_Description;
	case TUI_ERROR_UNSUPPORTED_CURSOR_SHAPE:
		return kTui_Error_Unsupported_Cursor_Shape_Description;
	case TUI_ERROR_UNSUPPORTED_RAW_MOUSE_MOTION:
		return kTui_Error_Unsupported_Raw_Mouse_Motion_Description;
	default:
		return kTui_Error_Unknown_Description;
	}
}