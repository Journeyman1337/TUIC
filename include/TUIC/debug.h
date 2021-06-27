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
enum TuiErrorCode
{
	/*!
	 * @brief TUI error for situations where an unkown error has occured.
	 */
	TUI_ERROR_UNKOWN = 0,
	/*!
	 * @brief TUI error for backend specific errors.
	 * 
	 * When this error is passed into a debug callback function, the 2nd argument is contains a textual description of the error. 
	 * This is different from all other errors, which have the function name where the error was called passed into the 2nd argument.
	 */
	TUI_ERROR_BACKEND_SPECIFIC = 1,
	/*!
	 * @brief TUI error for when a @ref TuiInstance is destroyed when there are still one or more attached @ref TuiGlyphAtlas objects.
	 */
	TUI_ERROR_DANGLING_GLYPH_ATLAS = 2,
	/*!
	 * @brief TUI error for when a @ref TuiInstance is destroyed when there are still one or more attached @ref TuiPalette objects.
	 */
	TUI_ERROR_DANGLING_PALETTE = 3,
	/*!
	 * @brief TUI error for when a @ref TuiInstance is destroyed when there are still one or more attached @ref TuiPanel objects.
	 */
	TUI_ERROR_DANGLING_PANEL = 4,
	/*!
	 * @brief TUI error for when a @ref TuiInstance is destroyed when there are still one or more attached @ref TuiTexture objects.
	 */
	TUI_ERROR_DANGLING_TEXTURE = 5,
	/*!
	 * @brief TUI error for when trying to use an opqaue object attached to a damaged @ref TuiInstance or a damanged @ref TuiInstance.
	 */
	 TUI_ERROR_DAMAGED_INSTANCE = 6,
	/*!
	 * @brief TUI error for when a @ref TuiInstance is destroyed when there are still one or more attached @ref TuiPanel objects.
	 */
	TUI_ERROR_INCOMPATIBLE_BLEND_MODE = 7,
	/*!
	 * @brief TUI error for when a emplacing a @ref TuiImage into another and they are not compatible with one another.
	 */
	TUI_ERROR_INCOMPATIBLE_IMAGES = 8,
	/*!
	 * @brief TUI error for when a @ref TuiAtlasType is invalid.
	 */
	TUI_ERROR_INVALID_ATLAS_TYPE = 9,
	/*!
	 * @brief TUI error for when batch data dimensions are less than or equal to 0.
	 */
	TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS = 10,
	/*!
	 * @brief TUI error for when batch dimensions are less than or equal to 0.
	 */
	TUI_ERROR_INVALID_BATCH_DIMENSIONS = 12,
	/*!
	 * @brief TUI error for when a batch setter is used for a @ref TuiBatch that is intended for a different @ref TuiDetailMode.
	 */
	TUI_ERROR_INVALID_BATCH_SETTER = 13,
	/*!
	 * @brief TUI error for when a @ref TuiBlendMode is invalid.
	 */
	TUI_ERROR_INVALID_BLEND_MODE = 14,
	/*!
	 * @brief TUI error for when attempting to create a codepage glyph atlas with pixel dimensions that are not divisible by 16 and less than or equal to 0.
	 */
	TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS = 15,
	/*!
	 * @brief TUI error for when there is an invalid color channel count specified.
	 */
	TUI_ERROR_INVALID_CHANNEL_COUNT = 16,
	/*!
	 * @brief TUI error for when a @ref TuiDetailFlag is invalid.
	 */
	TUI_ERROR_INVALID_DETAIL_FLAG = 17,
	/*!
	 * @brief TUI error for when a @ref TuiDetailMode is invalid.
	 */
	TUI_ERROR_INVALID_DETAIL_MODE = 18,
	/*!
	 * @brief TUI error for when a @ref TuiFilterMode is invalid.
	 */
	TUI_ERROR_INVALID_FILTER_MODE = 19,
	/*!
	 * @brief TUI error for when the glyph count of a @ref TuiGlyphAtlas is less than or equal to 0.
	 */
	TUI_ERROR_INVALID_GLYPH_COUNT = 20,
	/*!
	 * @brief TUI error for glyph width of height is less than or equal to 0.
	 */
	TUI_ERROR_INVALID_GLYPH_DIMENSIONS = 21,
	/*!
	 * @brief TUI error for then the pixel width or height of a @ref TuiImage is less than or equal to 0.
	 */
	TUI_ERROR_INVALID_IMAGE_DIMENSIONS = 22,
	/*!
	 * @brief TUI error for when the pixel width or height of a @ref TuiInstance is less than or equal to 0.
	 */
	TUI_ERROR_INVALID_INSTANCE_DIMENSIONS = 23,
	/*!
	 * @brief TUI error for when a @ref TuiPalette is given a color count less than or equal to 0 or greater than 256.
	 */
	TUI_ERROR_INVALID_PALETTE_COLOR_COUNT = 24,
	/*!
	 * @brief TUI error for when the pixel width or height of a @ref TuiPanel is less than or equal to 0.
	 */
	TUI_ERROR_INVALID_PANEL_DIMENSIONS = 25,
	/*!
	 * @brief TUI error for when the pixel width or height of a raw pixel array is less than or equal to 0.
	 */
	TUI_ERROR_INVALID_PIXEL_DIMENSIONS = 26,
	/*!
	 * @brief TUI error for when a @ref TuiImage has failed to be loaded from an image file.
	 */
	TUI_ERROR_LOAD_IMAGE_FAILURE = 27,
	/*!
	 * @brief TUI error for when a @ref TuiImage has been loaded with an unexpected channel count.
	 */
	TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS = 28,
	/*!
	 * @brief TUI error for when a @ref TuiBatch is NULL.
	 */
	TUI_ERROR_NULL_BATCH = 29,
	/*!
	 * @brief TUI error for when a batch data array is NULL.
	 */
	TUI_ERROR_NULL_BATCH_DATA = 30,
	/*!
	 * @brief TUI error for when a colors array is NULL.
	 */
	TUI_ERROR_NULL_COLORS = 31,
	/*!
	 * @brief TUI error for when a @ref TuiGlyphAtlas is NULL.
	 */
	TUI_ERROR_NULL_GLYPH_ATLAS = 32,
	/*!
	 * @brief TUI error for when a glyph bounding box array is NULL.
	 */
	TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES = 33,
	/*!
	 * @brief TUI error for when a @ref TuiImage is NULL.
	 */
	TUI_ERROR_NULL_IMAGE = 34,
	/*!
	 * @brief TUI error for when a @ref TuiInstance is NULL.
	 */
	TUI_ERROR_NULL_INSTANCE = 35,
	/*!
	 * @brief TUI error for when a @ref TuiPalette is NULL.
	 */
	TUI_ERROR_NULL_PALETTE = 36,
	/*!
	 * @brief TUI error for when a @ref TuiPanel is NULL.
	 */
	TUI_ERROR_NULL_PANEL = 37,
	/*!
	 * @brief TUI error for when a file path is NULL.
	 */
	TUI_ERROR_NULL_PATH = 38,
	/*!
	 * @brief TUI error for when a pixel array is NULL.
	 */
	TUI_ERROR_NULL_PIXELS = 39,
	/*!
	 * @brief TUI error for when a target @ref TuiImage is NULL.
	 */
	TUI_ERROR_NULL_TARGET_IMAGE = 40,
	/*!
	 * @brief TUI error for when a target @ref TuiPanel is NULL.
	 */
	TUI_ERROR_NULL_TARGET_PANEL = 41,
	/*!
	 * @brief TUI error for when a @ref TuiTexture is NULL.
	 */
	TUI_ERROR_NULL_TEXTURE = 42,
	/*!
	 * @brief TUI error for when a texture coordinates array is NULL.
	 */
	TUI_ERROR_NULL_TEXTURE_COORDINATES = 43,
	/*!
	 * @brief TUI error for when attempting to draw a @ref TuiBatch or batch data with a @ref TuiDetailMode that requires a @ref TuiPalette and none is provided.
	 */
	TUI_ERROR_PALETTE_REQUIRED = 44,
	/*!
	 * @brief TUI error for when a @ref TuiImage has failed to be resized.
	 */
	TUI_ERROR_RESIZE_IMAGE_FAILURE = 45,
	/*!
	 * @brief TUI error for when a @ref TuiGlyphAtlas uses an unmatching @ref TuiInstance.
	 */
	TUI_ERROR_UNMATCHING_ATLAS_INSTANCE = 46,
	/*!
	 * @brief TUI error for when a @ref TuiPalette uses an unmatching @ref TuiInstance.
	 */
	TUI_ERROR_UNMATCHING_PALETTE_INSTANCE = 47,
	/*!
	* @brief TUI error for when a @ref TuiPanel uses an unmatching @ref TuiInstance.
	*/
	TUI_ERROR_UNMATCHING_PANEL_INSTANCE = 48
};
/*! @name Error Code Names
 * These are the const string names of @ref TuiErrorCode enum values.
 *  @{ */
/*!
 * @brief String name of @ref TUI_ERROR_UNKOWN.
 */
extern const char* kTui_Error_Unkown_Name;
/*!
 * @brief String name of @ref TUI_ERROR_BACKEND_SPECIFIC.
 */
extern const char* kTui_Error_Backend_Specific_Name;
/*!
 * @brief String name of @ref TUI_ERROR_DANGLING_GLYPH_ATLAS.
 */
extern const char* kTui_Error_Dangling_Glyph_Atlas_Name;
/*!
 * @brief String name of @ref TUI_ERROR_DANGLING_PALETTE.
 */
extern const char* kTui_Error_Dangling_Palette_Name;
/*!
 * @brief String name of @ref TUI_ERROR_DANGLING_PANEL.
 */
extern const char* kTui_Error_Dangling_Panel_Name;
/*!
 * @brief String name of @ref TUI_ERROR_DANGLING_TEXTURE.
 */
extern const char* kTui_Error_Dangling_Texture_Name;
/*!
 * @brief String name of @ref TUI_ERROR_DAMAGED_INSTANCE.
 */
extern const char* kTui_Error_Damaged_Instance_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INCOMPATIBLE_BLEND_MODE.
 */
extern const char* kTui_Error_Incompatible_Blend_Mode_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INCOMPATIBLE_IMAGES.
 */
extern const char* kTui_Error_Incompatible_Images_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_ATLAS_TYPE.
 */
extern const char* kTui_Error_Invalid_Atlas_Type_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Batch_Data_Dimensions_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_BATCH_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Batch_Dimensions_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_BATCH_SETTER.
 */
extern const char* kTui_Error_Invalid_Batch_Setter_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_BLEND_MODE.
 */
extern const char* kTui_Error_Invalid_Blend_Mode_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Codepage_Dimensions_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_CHANNEL_COUNT.
 */
extern const char* kTui_Error_Invalid_Channel_Count_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_DETAIL_FLAG.
 */
extern const char* kTui_Error_Invalid_Detail_Flag_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_DETAIL_MODE.
 */
extern const char* kTui_Error_Invalid_Detail_Mode_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_FILTER_MODE.
 */
extern const char* kTui_Error_Invalid_Filter_Mode_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_GLYPH_COUNT.
 */
extern const char* kTui_Error_Invalid_Glyph_Count_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_GLYPH_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Glyph_Dimensions_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_IMAGE_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Image_Dimensions_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_INSTANCE_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Instance_Dimensions_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_PALETTE_COLOR_COUNT.
 */
extern const char* kTui_Error_Invalid_Palette_Color_Count_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_PANEL_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Panel_Dimensions_Name;
/*!
 * @brief String name of @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Pixel_Dimensions_Name;
/*!
 * @brief String name of @ref TUI_ERROR_LOAD_IMAGE_FAILURE.
 */
extern const char* kTui_Error_Load_Image_Failure_Name;
/*!
 * @brief String name of @ref TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS.
 */
extern const char* kTui_Error_Load_Image_Unexpected_Channels_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_BATCH.
 */
extern const char* kTui_Error_Null_Batch_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_BATCH_DATA.
 */
extern const char* kTui_Error_Null_Batch_Data_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_COLORS.
 */
extern const char* kTui_Error_Null_Colors_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_GLYPH_ATLAS.
 */
extern const char* kTui_Error_Null_Glyph_Atlas_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES.
 */
extern const char* kTui_Error_Null_Glyph_Bounding_Boxes_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_IMAGE.
 */
extern const char* kTui_Error_Null_Image_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_INSTANCE.
 */
extern const char* kTui_Error_Null_Instance_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_PALETTE.
 */
extern const char* kTui_Error_Null_Palette_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_PANEL.
 */
extern const char* kTui_Error_Null_Panel_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_PATH.
 */
extern const char* kTui_Error_Null_Path_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_PIXELS.
 */
extern const char* kTui_Error_Null_Pixels_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_TARGET_IMAGE.
 */
extern const char* kTui_Error_Null_Target_Image_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_TARGET_PANEL.
 */
extern const char* kTui_Error_Null_Target_Panel_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_TEXTURE.
 */
extern const char* kTui_Error_Null_Texture_Name;
/*!
 * @brief String name of @ref TUI_ERROR_NULL_TEXTURE_COORDINATES.
 */
extern const char* kTui_Error_Null_Texture_Coordinates_Name;
/*!
 * @brief String name of @ref TUI_ERROR_PALETTE_REQUIRED.
 */
extern const char* kTui_Error_Palette_Required_Name;
/*!
 * @brief String name of @ref TUI_ERROR_RESIZE_IMAGE_FAILURE.
 */
extern const char* kTui_Error_Resize_Image_Failure_Name;
/*!
 * @brief String name of @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE.
 */
extern const char* kTui_Error_Unmatching_Atlas_Instance_Name;
/*!
 * @brief String name of @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE.
 */
extern const char* kTui_Error_Unmatching_Palette_Instance_Name;
/*!
 * @brief String name of @ref TUI_ERROR_UNMATCHING_PANEL_INSTANCE.
 */
extern const char* kTui_Error_Unmatching_Panel_Instance_Name;
/*!
 * @brief String name of @ref TUI_ERROR_UNKOWN.
 */
/*! @} */
/*! @name Error Code Descriptions
 * These are the const string descriptions of @ref TuiErrorCode enum values.
 *  @{ */
/*!
 * @brief String description of @ref TUI_ERROR_UNKOWN.
 */
extern const char* kTui_Error_Unkown_Description;
/*!
 * @brief String description of @ref TUI_ERROR_BACKEND_SPECIFIC.
 */
extern const char* kTui_Error_Backend_Specific_Description;
/*!
 * @brief String description of @ref TUI_ERROR_DANGLING_GLYPH_ATLAS.
 */
extern const char* kTui_Error_Dangling_Glyph_Atlas_Description;
/*!
 * @brief String description of @ref TUI_ERROR_DANGLING_PANEL.
 */
extern const char* kTui_Error_Dangling_Palette_Description;
/*!
 * @brief String description of @ref TUI_ERROR_DANGLING_PANEL.
 */
extern const char* kTui_Error_Dangling_Panel_Description;
/*!
 * @brief String description of @ref TUI_ERROR_DANGLING_TEXTURE.
 */
extern const char* kTui_Error_Dangling_Texture_Description;
/*!
 * @brief String name of @ref TUI_ERROR_DAMAGED_INSTANCE.
 */
extern const char* kTui_Error_Damaged_Instance_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INCOMPATIBLE_BLEND_MODE.
 */
extern const char* kTui_Error_Incompatible_Blend_Mode_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INCOMPATIBLE_IMAGES.
 */
extern const char* kTui_Error_Incompatible_Images_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_ATLAS_TYPE.
 */
extern const char* kTui_Error_Invalid_Atlas_Type_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Batch_Data_Dimensions_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_BATCH_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Batch_Dimensions_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_BATCH_SETTER.
 */
extern const char* kTui_Error_Invalid_Batch_Setter_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_BLEND_MODE.
 */
extern const char* kTui_Error_Invalid_Blend_Mode_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Codepage_Dimensions_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_CHANNEL_COUNT.
 */
extern const char* kTui_Error_Invalid_Channel_Count_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_DETAIL_FLAG.
 */
extern const char* kTui_Error_Invalid_Detail_Flag_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_DETAIL_MODE.
 */
extern const char* kTui_Error_Invalid_Detail_Mode_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_FILTER_MODE.
 */
extern const char* kTui_Error_Invalid_Filter_Mode_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_GLYPH_COUNT.
 */
extern const char* kTui_Error_Invalid_Glyph_Count_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_GLYPH_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Glyph_Dimensions_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_IMAGE_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Image_Dimensions_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_INSTANCE_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Instance_Dimensions_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_PALETTE_COLOR_COUNT.
 */
extern const char* kTui_Error_Invalid_Palette_Color_Count_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_PANEL_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Panel_Dimensions_Description;
/*!
 * @brief String description of @ref TUI_ERROR_INVALID_PIXEL_DIMENSIONS.
 */
extern const char* kTui_Error_Invalid_Pixel_Dimensions_Description;
/*!
 * @brief String description of @ref TUI_ERROR_LOAD_IMAGE_FAILURE.
 */
extern const char* kTui_Error_Load_Image_Failure_Description;
/*!
 * @brief String description of @ref TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS.
 */
extern const char* kTui_Error_Load_Image_Unexpected_Channels_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_BATCH.
 */
extern const char* kTui_Error_Null_Batch_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_BATCH_DATA.
 */
extern const char* kTui_Error_Null_Batch_Data_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_COLORS.
 */
extern const char* kTui_Error_Null_Colors_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_GLYPH_ATLAS.
 */
extern const char* kTui_Error_Null_Glyph_Atlas_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES.
 */
extern const char* kTui_Error_Null_Glyph_Bounding_Boxes_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_IMAGE.
 */
extern const char* kTui_Error_Null_Image_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_INSTANCE.
 */
extern const char* kTui_Error_Null_Instance_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_PALETTE.
 */
extern const char* kTui_Error_Null_Palette_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_PANEL.
 */
extern const char* kTui_Error_Null_Panel_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_PATH.
 */
extern const char* kTui_Error_Null_Path_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_PIXELS.
 */
extern const char* kTui_Error_Null_Pixels_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_TARGET_IMAGE.
 */
extern const char* kTui_Error_Null_Target_Image_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_TARGET_PANEL.
 */
extern const char* kTui_Error_Null_Target_Panel_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_TEXTURE.
 */
extern const char* kTui_Error_Null_Texture_Description;
/*!
 * @brief String description of @ref TUI_ERROR_NULL_TEXTURE_COORDINATES.
 */
extern const char* kTui_Error_Null_Texture_Coordinates_Description;
/*!
 * @brief String description of @ref TUI_ERROR_PALETTE_REQUIRED.
 */
extern const char* kTui_Error_Palette_Required_Description;
/*!
 * @brief String description of @ref TUI_ERROR_RESIZE_IMAGE_FAILURE.
 */
extern const char* kTui_Error_Resize_Image_Failure_Description;
/*!
 * @brief String description of @ref TUI_ERROR_UNMATCHING_ATLAS_INSTANCE.
 */
extern const char* kTui_Error_Unmatching_Atlas_Instance_Description;
/*!
 * @brief String description of @ref TUI_ERROR_UNMATCHING_PALETTE_INSTANCE.
 */
extern const char* kTui_Error_Unmatching_Palette_Instance_Description;
/*!
 * @brief String description of @ref TUI_ERROR_UNMATCHING_PANEL_INSTANCE.
 */
extern const char* kTui_Error_Unmatching_Panel_Instance_Description;
/*! @} */
/*! @name Error Code Manipilation Functions
 *  @{ */
/*!
 * @brief Get string name of a @ref TuiErrorCode.
 *
 * @param error_code The @ref TuiErrorCode.
 *
 * @returns The string name.
 */
const char* tuiErrorCodeToString(int error_code);
/*!
 * @brief Get a @ref TuiErrorCode from a string name.
 *
 * @param string The string name.
 *
 * @returns The @ref TuiErrorCode.
 */
int tuiStringToErrorCode(const char* string);
/*!
 * @brief Get string description of a @ref TuiErrorCode.
 *
 * @param error_code The @ref TuiErrorCode.
 *
 * @returns The string description.
 */
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