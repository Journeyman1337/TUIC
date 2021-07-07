#include <TUIC/debug.h>
#include "objects.h"
#include <string.h>

#define TO_STRING(value) #value

const char* kTui_Error_Unknown_Name = TO_STRING(TUI_ERROR_UNKNOWN);
const char* kTui_Error_Backend_Specific_Name = TO_STRING(TUI_ERROR_BACKEND_SPECIFIC);
const char* kTui_Error_Dangling_Glyph_Atlas_Name = TO_STRING(TUI_ERROR_DANGLING_GLYPH_ATLAS);
const char* kTui_Error_Dangling_Palette_Name = TO_STRING(TUI_ERROR_DANGLING_PALETTE);
const char* kTui_Error_Dangling_Panel_Name = TO_STRING(TUI_ERROR_DANGLING_PANEL);
const char* kTui_Error_Dangling_Texture_Name = TO_STRING(TUI_ERROR_DANGLING_TEXTURE);
const char* kTui_Error_Damaged_Instance_Name = TO_STRING(TUI_ERROR_DAMAGED_INSTANCE);
const char* kTui_Error_Incompatible_Blend_Mode_Name = TO_STRING(TUI_ERROR_INCOMPATIBLE_BLEND_MODE);
const char* kTui_Error_Incompatible_Images_Name = TO_STRING(TUI_ERROR_INCOMPATIBLE_IMAGES);
const char* kTui_Error_Invalid_Atlas_Type_Name = TO_STRING(TUI_ERROR_INVALID_ATLAS_TYPE);
const char* kTui_Error_Invalid_Batch_Data_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS);
const char* kTui_Error_Invalid_Batch_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_BATCH_DIMENSIONS);
const char* kTui_Error_Invalid_Batch_Setter_Name = TO_STRING(TUI_ERROR_INVALID_BATCH_SETTER);
const char* kTui_Error_Invalid_Blend_Mode_Name = TO_STRING(TUI_ERROR_INVALID_BLEND_MODE);
const char* kTui_Error_Invalid_Codepage_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS);
const char* kTui_Error_Invalid_Channel_Count_Name = TO_STRING(TUI_ERROR_INVALID_CHANNEL_COUNT);
const char* kTui_Error_Invalid_Detail_Flag_Name = TO_STRING(TUI_ERROR_INVALID_DETAIL_FLAG);
const char* kTui_Error_Invalid_Filter_Mode_Name = TO_STRING(TUI_ERROR_INVALID_FILTER_MODE);
const char* kTui_Error_Invalid_Detail_Mode_Name = TO_STRING(TUI_ERROR_INVALID_DETAIL_MODE);
const char* kTui_Error_Invalid_Glyph_Count_Name = TO_STRING(TUI_ERROR_INVALID_GLYPH_COUNT);
const char* kTui_Error_Invalid_Glyph_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_GLYPH_DIMENSIONS);
const char* kTui_Error_Invalid_Image_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_IMAGE_DIMENSIONS);
const char* kTui_Error_Invalid_Instance_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_INSTANCE_DIMENSIONS);
const char* kTui_Error_Invalid_Palette_Color_Count_Name = TO_STRING(TUI_ERROR_INVALID_PALETTE_COLOR_COUNT);
const char* kTui_Error_Invalid_Panel_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_PANEL_DIMENSIONS);
const char* kTui_Error_Invalid_Pixel_Dimensions_Name = TO_STRING(TUI_ERROR_INVALID_PIXEL_DIMENSIONS);
const char* kTui_Error_Load_Image_Failure_Name = TO_STRING(TUI_ERROR_LOAD_IMAGE_FAILURE);
const char* kTui_Error_Load_Image_Unexpected_Channels_Name = TO_STRING(TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS);
const char* kTui_Error_Null_Batch_Name = TO_STRING(TUI_ERROR_NULL_BATCH);
const char* kTui_Error_Null_Batch_Data_Name = TO_STRING(TUI_ERROR_NULL_BATCH_DATA);
const char* kTui_Error_Null_Colors_Name = TO_STRING(TUI_ERROR_NULL_COLORS);
const char* kTui_Error_Null_Glyph_Atlas_Name = TO_STRING(TUI_ERROR_NULL_GLYPH_ATLAS);
const char* kTui_Error_Null_Glyph_Bounding_Boxes_Name = TO_STRING(TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES);
const char* kTui_Error_Null_Image_Name = TO_STRING(TUI_ERROR_NULL_IMAGE);
const char* kTui_Error_Null_Instance_Name = TO_STRING(TUI_ERROR_NULL_INSTANCE);
const char* kTui_Error_Null_Palette_Name = TO_STRING(TUI_ERROR_NULL_PALETTE);
const char* kTui_Error_Null_Panel_Name = TO_STRING(TUI_ERROR_NULL_PANEL);
const char* kTui_Error_Null_Path_Name = TO_STRING(TUI_ERROR_NULL_PATH);
const char* kTui_Error_Null_Pixels_Name = TO_STRING(TUI_ERROR_NULL_PIXELS);
const char* kTui_Error_Null_Target_Image_Name = TO_STRING(TUI_ERROR_NULL_TARGET_IMAGE);
const char* kTui_Error_Null_Target_Panel_Name = TO_STRING(TUI_ERROR_NULL_TARGET_PANEL);
const char* kTui_Error_Null_Texture_Name = TO_STRING(TUI_ERROR_NULL_TEXTURE);
const char* kTui_Error_Null_Texture_Coordinates_Name = TO_STRING(TUI_ERROR_NULL_TEXTURE_COORDINATES);
const char* kTui_Error_Palette_Required_Name = TO_STRING(TUI_ERROR_PALETTE_REQUIRED);
const char* kTui_Error_Resize_Image_Failure_Name = TO_STRING(TUI_ERROR_RESIZE_IMAGE_FAILURE);
const char* kTui_Error_Unmatching_Atlas_Instance_Name = TO_STRING(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE);
const char* kTui_Error_Unmatching_Palette_Instance_Name = TO_STRING(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE);
const char* kTui_Error_Unmatching_Panel_Instance_Name = TO_STRING(TUI_ERROR_UNMATCHING_PANEL_INSTANCE);

const char* kTui_Error_Unknown_Description = "An unknown error has occured.";
const char* kTui_Error_Backend_Specific_Description = "A backend specific error has occured.";
const char* kTui_Error_Dangling_Glyph_Atlas_Description = "A TuiInstance has been destroyed with one or more dangling TuiAtlas.";
const char* kTui_Error_Dangling_Palette_Description = "A TuiInstance has been destroyed with one or more dangling TuiPalette";
const char* kTui_Error_Dangling_Panel_Description = "A TuiInstance has been destroyed with one or more dangling TuiPanel.";
const char* kTui_Error_Dangling_Texture_Description = "A TuiInstance has been destroyed with one or more dangling TuiTexture.";
const char* kTui_Error_Damaged_Instance_Description = "A TuiInstance is damaged so all associated opaque objects must be remade.";
const char* kTui_Error_Incompatible_Blend_Mode_Description = "The provided blend mode is incompatible with the provided detail mode.";
const char* kTui_Error_Incompatible_Images_Description = "The TuiImage and target TuiImage are incompatible with each other.";
const char* kTui_Error_Invalid_Atlas_Type_Description = "The provided atlas type is invalid.";
const char* kTui_Error_Invalid_Batch_Data_Dimensions_Description = "The dimensions of batch data must be greater than 0.";
const char* kTui_Error_Invalid_Batch_Dimensions_Description = "The dimensions of a TuiBatch must be greater than 0.";
const char* kTui_Error_Invalid_Batch_Setter_Description = "Setter function used for the incorrect detail mode for this TuiBatch.";
const char* kTui_Error_Invalid_Blend_Mode_Description = "The provided blend mode is invalid.";
const char* kTui_Error_Invalid_Codepage_Dimensions_Description = "The image pixel dimensions must be divisible by 16.";
const char* kTui_Error_Invalid_Channel_Count_Description = "The color channel count is not supported.";
const char* kTui_Error_Invalid_Detail_Flag_Description = "The provided detail flag is invalid.";
const char* kTui_Error_Invalid_Detail_Mode_Description = "The provided detail mode is invalid.";
const char* kTui_Error_Invalid_Filter_Mode_Description = "The provided filter mode is invalid.";
const char* kTui_Error_Invalid_Glyph_Count_Description = "The glyph count must be greater than 0.";
const char* kTui_Error_Invalid_Glyph_Dimensions_Description = "The glyph dimensions of a TuiAtlas must be greater than 0.";
const char* kTui_Error_Invalid_Image_Dimensions_Description = "The pixel dimensions of a TuiImage must be greater than 0.";
const char* kTui_Error_Invalid_Instance_Dimensions_Description = "The pixel dimensions of a TuiScreen must be greater than 0.";
const char* kTui_Error_Invalid_Palette_Color_Count_Description = "The color count of a TuiPalette must be greater than 0 and less than or equal to 256.";
const char* kTui_Error_Invalid_Panel_Dimensions_Description = "The dimensions of a TuiPanel must be greater than 0.";
const char* kTui_Error_Invalid_Pixel_Dimensions_Description = "The dimensions of a pixel array must be greater than 0.";
const char* kTui_Error_Load_Image_Failure_Description = "Failed to load TuiImage from file.";
const char* kTui_Error_Load_Image_Unexpected_Channels_Description = "Loaded TuiImage from file with unexpected channel count.";
const char* kTui_Error_Null_Batch_Description = "The provided TuiBatch is NULL.";
const char* kTui_Error_Null_Batch_Data_Description = "The provided batch data is NULL.";
const char* kTui_Error_Null_Colors_Description = "The provided colors array is NULL.";
const char* kTui_Error_Null_Glyph_Atlas_Description = "The provided TuiAtlas is NULL.";
const char* kTui_Error_Null_Glyph_Bounding_Boxes_Description = "The provided glyph bounding boxes array is NULL.";
const char* kTui_Error_Null_Image_Description = "The provided TuiImage is NULL.";
const char* kTui_Error_Null_Instance_Description = "The provided TuiInstance is NULL.";
const char* kTui_Error_Null_Palette_Description = "The provided TuiPalette is NULL.";
const char* kTui_Error_Null_Panel_Description = "The provided TuiPanel is NULL.";
const char* kTui_Error_Null_Path_Description = "The provided path is NULL.";
const char* kTui_Error_Null_Pixels_Description = "The provided pixels array is NULL.";
const char* kTui_Error_Null_Target_Image_Description = "The provided target TuiImage is NULL.";
const char* kTui_Error_Null_Target_Panel_Description = "The provided target TuiPanel is NULL.";
const char* kTui_Error_Null_Texture_Description = "The provided TuiTexture is NULL.";
const char* kTui_Error_Null_Texture_Coordinates_Description = "The provided texture coordinates array is NULL.";
const char* kTui_Error_Palette_Required_Description = "Can not draw tiles of detail mode without a TuiPalette.";
const char* kTui_Error_Resize_Image_Failure_Description = "Failed to resize TuiImage.";
const char* kTui_Error_Unmatching_Atlas_Instance_Description = "The provided TuiAtlas has an unmatching TuiInstance.";
const char* kTui_Error_Unmatching_Palette_Instance_Description = "The provided TuiPalette has an unmatching TuiInstacne.";
const char* kTui_Error_Unmatching_Panel_Instance_Description = "The provided TuiPanel has an unmatching TuiInstance.";


void tui_default_debug_callback(int error_type, const char* str) {}

static tuiDebugErrorCallback sDebugCallback = tui_default_debug_callback;

const char* tuiErrorCodeToString(int error_code)
{
	switch (error_code)
	{
	case TUI_ERROR_UNKNOWN:
		return kTui_Error_Unknown_Name;
	case TUI_ERROR_BACKEND_SPECIFIC:
		return kTui_Error_Backend_Specific_Name;
	case TUI_ERROR_DANGLING_GLYPH_ATLAS:
		return kTui_Error_Dangling_Glyph_Atlas_Name;
	case TUI_ERROR_DANGLING_PALETTE:
		return kTui_Error_Dangling_Palette_Name;
	case TUI_ERROR_DANGLING_PANEL:
		return kTui_Error_Dangling_Panel_Name;
	case TUI_ERROR_DANGLING_TEXTURE:
		return kTui_Error_Dangling_Texture_Name;
	case TUI_ERROR_DAMAGED_INSTANCE:
		return kTui_Error_Damaged_Instance_Name;
	case TUI_ERROR_INCOMPATIBLE_BLEND_MODE:
		return kTui_Error_Incompatible_Blend_Mode_Name;
	case TUI_ERROR_INCOMPATIBLE_IMAGES:
		return kTui_Error_Incompatible_Images_Name;
	case TUI_ERROR_INVALID_ATLAS_TYPE:
		return kTui_Error_Invalid_Atlas_Type_Name;
	case TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS:
		return kTui_Error_Invalid_Batch_Data_Dimensions_Name;
	case TUI_ERROR_INVALID_BATCH_DIMENSIONS:
		return kTui_Error_Invalid_Batch_Dimensions_Name;
	case TUI_ERROR_INVALID_BATCH_SETTER:
		return kTui_Error_Invalid_Batch_Setter_Name;
	case TUI_ERROR_INVALID_BLEND_MODE:
		return kTui_Error_Invalid_Blend_Mode_Name;
	case TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS:
		return kTui_Error_Invalid_Codepage_Dimensions_Name;
	case TUI_ERROR_INVALID_CHANNEL_COUNT:
		return kTui_Error_Invalid_Channel_Count_Name;
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
	case TUI_ERROR_INVALID_INSTANCE_DIMENSIONS:
		return kTui_Error_Invalid_Instance_Dimensions_Name;
	case TUI_ERROR_INVALID_PALETTE_COLOR_COUNT:
		return kTui_Error_Invalid_Palette_Color_Count_Name;
	case TUI_ERROR_INVALID_PANEL_DIMENSIONS:
		return kTui_Error_Invalid_Panel_Dimensions_Name;
	case TUI_ERROR_INVALID_PIXEL_DIMENSIONS:
		return kTui_Error_Invalid_Pixel_Dimensions_Name;
	case TUI_ERROR_LOAD_IMAGE_FAILURE:
		return kTui_Error_Load_Image_Failure_Name;
	case TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS:
		return kTui_Error_Load_Image_Unexpected_Channels_Name;
	case TUI_ERROR_NULL_BATCH:
		return kTui_Error_Null_Batch_Name;
	case TUI_ERROR_NULL_BATCH_DATA:
		return kTui_Error_Null_Batch_Data_Name;
	case TUI_ERROR_NULL_COLORS:
		return kTui_Error_Null_Colors_Name;
	case TUI_ERROR_NULL_GLYPH_ATLAS:
		return kTui_Error_Null_Glyph_Atlas_Name;
	case TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES:
		return kTui_Error_Null_Glyph_Bounding_Boxes_Name;
	case TUI_ERROR_NULL_IMAGE:
		return kTui_Error_Null_Image_Name;
	case TUI_ERROR_NULL_INSTANCE:
		return kTui_Error_Null_Instance_Name;
	case TUI_ERROR_NULL_PALETTE:
		return kTui_Error_Null_Palette_Name;
	case TUI_ERROR_NULL_PANEL:
		return kTui_Error_Null_Panel_Name;
	case TUI_ERROR_NULL_PATH:
		return kTui_Error_Null_Path_Name;
	case TUI_ERROR_NULL_PIXELS:
		return kTui_Error_Null_Pixels_Name;
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
	case TUI_ERROR_UNMATCHING_ATLAS_INSTANCE:
		return kTui_Error_Unmatching_Atlas_Instance_Name;
	case TUI_ERROR_UNMATCHING_PALETTE_INSTANCE:
		return kTui_Error_Unmatching_Palette_Instance_Name;
	case TUI_ERROR_UNMATCHING_PANEL_INSTANCE:
		return kTui_Error_Unmatching_Panel_Instance_Name;
	}
	return kTui_Error_Unknown_Name;
}

int tuiStringToErrorCode(const char* string)
{
	if (strcmp(string, kTui_Error_Unknown_Name) == 0)
	{
		return TUI_ERROR_UNKNOWN;
	}
	else if (strcmp(string, kTui_Error_Backend_Specific_Name) == 0)
	{
		return TUI_ERROR_BACKEND_SPECIFIC;
	}
	else if (strcmp(string, kTui_Error_Dangling_Glyph_Atlas_Name) == 0)
	{
		return TUI_ERROR_DANGLING_GLYPH_ATLAS;
	}
	else if (strcmp(string, kTui_Error_Dangling_Palette_Name) == 0)
	{
		return TUI_ERROR_DANGLING_PALETTE;
	}
	else if (strcmp(string, kTui_Error_Dangling_Panel_Name) == 0)
	{
		return TUI_ERROR_DANGLING_PANEL;
	}
	else if (strcmp(string, kTui_Error_Dangling_Texture_Name) == 0)
	{
		return TUI_ERROR_DANGLING_TEXTURE;
	}
	else if (strcmp(string, kTui_Error_Damaged_Instance_Name) == 0)
	{
		return TUI_ERROR_DAMAGED_INSTANCE;
	}
	else if (strcmp(string, kTui_Error_Incompatible_Blend_Mode_Name) == 0)
	{
		return TUI_ERROR_INCOMPATIBLE_BLEND_MODE;
	}
	else if (strcmp(string, kTui_Error_Incompatible_Images_Name) == 0)
	{
		return TUI_ERROR_INCOMPATIBLE_IMAGES;
	}
	else if (strcmp(string, kTui_Error_Invalid_Atlas_Type_Name) == 0)
	{
		return TUI_ERROR_INVALID_ATLAS_TYPE;
	}
	else if (strcmp(string, kTui_Error_Invalid_Batch_Data_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS;
	}
	else if (strcmp(string, kTui_Error_Invalid_Batch_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_BATCH_DIMENSIONS;
	}
	else if (strcmp(string, kTui_Error_Invalid_Batch_Setter_Name) == 0)
	{
		return TUI_ERROR_INVALID_BATCH_SETTER;
	}
	else if (strcmp(string, kTui_Error_Invalid_Blend_Mode_Name) == 0)
	{
		return TUI_ERROR_INVALID_BLEND_MODE;
	}
	else if (strcmp(string, kTui_Error_Invalid_Codepage_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS;
	}
	else if (strcmp(string, kTui_Error_Invalid_Channel_Count_Name) == 0)
	{
		return TUI_ERROR_INVALID_CHANNEL_COUNT;
	}
	else if (strcmp(string, kTui_Error_Invalid_Detail_Flag_Name) == 0)
	{
		return TUI_ERROR_INVALID_DETAIL_FLAG;
	}
	else if (strcmp(string, kTui_Error_Invalid_Detail_Mode_Name) == 0)
	{
		return TUI_ERROR_INVALID_DETAIL_MODE;
	}
	else if (strcmp(string, kTui_Error_Invalid_Filter_Mode_Name) == 0)
	{
		return TUI_ERROR_INVALID_FILTER_MODE;
	}
	else if (strcmp(string, kTui_Error_Invalid_Glyph_Count_Name) == 0)
	{
		return TUI_ERROR_INVALID_GLYPH_COUNT;
	}
	else if (strcmp(string, kTui_Error_Invalid_Glyph_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_GLYPH_DIMENSIONS;
	}
	else if (strcmp(string, kTui_Error_Invalid_Image_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_IMAGE_DIMENSIONS;
	}
	else if (strcmp(string, kTui_Error_Invalid_Instance_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_INSTANCE_DIMENSIONS;
	}
	else if (strcmp(string, kTui_Error_Invalid_Palette_Color_Count_Name) == 0)
	{
		return TUI_ERROR_INVALID_PALETTE_COLOR_COUNT;
	}
	else if (strcmp(string, kTui_Error_Invalid_Panel_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_PANEL_DIMENSIONS;
	}
	else if (strcmp(string, kTui_Error_Invalid_Pixel_Dimensions_Name) == 0)
	{
		return TUI_ERROR_INVALID_PIXEL_DIMENSIONS;
	}
	else if (strcmp(string, kTui_Error_Load_Image_Failure_Name) == 0)
	{
		return TUI_ERROR_LOAD_IMAGE_FAILURE;
	}
	else if (strcmp(string, kTui_Error_Load_Image_Unexpected_Channels_Name) == 0)
	{
		return TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS;
	}
	else if (strcmp(string, kTui_Error_Null_Batch_Name) == 0)
	{
		return TUI_ERROR_NULL_BATCH;
	}
	else if (strcmp(string, kTui_Error_Null_Batch_Data_Name) == 0)
	{
		return TUI_ERROR_NULL_BATCH_DATA;
	}
	else if (strcmp(string, kTui_Error_Null_Colors_Name) == 0)
	{
		return TUI_ERROR_NULL_COLORS;
	}
	else if (strcmp(string, kTui_Error_Null_Glyph_Atlas_Name) == 0)
	{
		return TUI_ERROR_NULL_GLYPH_ATLAS;
	}
	else if (strcmp(string, kTui_Error_Null_Glyph_Bounding_Boxes_Name) == 0)
	{
		return TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES;
	}
	else if (strcmp(string, kTui_Error_Null_Image_Name) == 0)
	{
		return TUI_ERROR_NULL_IMAGE;
	}
	else if (strcmp(string, kTui_Error_Null_Instance_Name) == 0)
	{
		return TUI_ERROR_NULL_INSTANCE;
	}
	else if (strcmp(string, kTui_Error_Null_Palette_Name) == 0)
	{
		return TUI_ERROR_NULL_PALETTE;
	}
	else if (strcmp(string, kTui_Error_Null_Panel_Name) == 0)
	{
		return TUI_ERROR_NULL_PANEL;
	}
	else if (strcmp(string, kTui_Error_Null_Path_Name) == 0)
	{
		return TUI_ERROR_NULL_PATH;
	}
	else if (strcmp(string, kTui_Error_Null_Pixels_Name) == 0)
	{
		return TUI_ERROR_NULL_PIXELS;
	}
	else if (strcmp(string, kTui_Error_Null_Target_Image_Name) == 0)
	{
		return TUI_ERROR_NULL_TARGET_IMAGE;
	}
	else if (strcmp(string, kTui_Error_Null_Target_Panel_Name) == 0)
	{
		return TUI_ERROR_NULL_TARGET_PANEL;
	}
	else if (strcmp(string, kTui_Error_Null_Texture_Name) == 0)
	{
		return TUI_ERROR_NULL_TEXTURE;
	}
	else if (strcmp(string, kTui_Error_Null_Texture_Coordinates_Name) == 0)
	{
		return TUI_ERROR_NULL_TEXTURE_COORDINATES;
	}
	else if (strcmp(string, kTui_Error_Palette_Required_Name) == 0)
	{
		return TUI_ERROR_PALETTE_REQUIRED;
	}
	else if (strcmp(string, kTui_Error_Resize_Image_Failure_Name) == 0)
	{
		return TUI_ERROR_RESIZE_IMAGE_FAILURE;
	}
	else if (strcmp(string, kTui_Error_Unmatching_Atlas_Instance_Name) == 0)
	{
		return TUI_ERROR_UNMATCHING_ATLAS_INSTANCE;
	}
	else if (strcmp(string, kTui_Error_Unmatching_Palette_Instance_Name) == 0)
	{
		return TUI_ERROR_UNMATCHING_PALETTE_INSTANCE;
	}
	else if (strcmp(string, kTui_Error_Unmatching_Panel_Instance_Name) == 0)
	{
		return TUI_ERROR_UNMATCHING_PANEL_INSTANCE;
	}
	return 0;
}

const char* tuiErrorCodeGetDescription(int error_code)
{
	switch (error_code)
	{
	case TUI_ERROR_UNKNOWN:
		return kTui_Error_Unknown_Description;
	case TUI_ERROR_BACKEND_SPECIFIC:
		return kTui_Error_Backend_Specific_Description;
	case TUI_ERROR_DANGLING_GLYPH_ATLAS:
		return kTui_Error_Dangling_Glyph_Atlas_Description;
	case TUI_ERROR_DANGLING_PALETTE:
		return kTui_Error_Dangling_Palette_Description;
	case TUI_ERROR_DANGLING_PANEL:
		return kTui_Error_Dangling_Panel_Description;
	case TUI_ERROR_DANGLING_TEXTURE:
		return kTui_Error_Dangling_Texture_Description;
	case TUI_ERROR_DAMAGED_INSTANCE:
		return kTui_Error_Damaged_Instance_Description;
	case TUI_ERROR_INCOMPATIBLE_BLEND_MODE:
		return kTui_Error_Incompatible_Blend_Mode_Description;
	case TUI_ERROR_INCOMPATIBLE_IMAGES:
		return kTui_Error_Incompatible_Images_Description;
	case TUI_ERROR_INVALID_ATLAS_TYPE:
		return kTui_Error_Invalid_Atlas_Type_Description;
	case TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS:
		return kTui_Error_Invalid_Batch_Data_Dimensions_Description;
	case TUI_ERROR_INVALID_BATCH_DIMENSIONS:
		return kTui_Error_Invalid_Batch_Dimensions_Description;
	case TUI_ERROR_INVALID_BATCH_SETTER:
		return kTui_Error_Invalid_Batch_Setter_Description;
	case TUI_ERROR_INVALID_BLEND_MODE:
		return kTui_Error_Invalid_Blend_Mode_Description;
	case TUI_ERROR_INVALID_CODEPAGE_DIMENSIONS:
		return kTui_Error_Invalid_Codepage_Dimensions_Description;
	case TUI_ERROR_INVALID_CHANNEL_COUNT:
		return kTui_Error_Invalid_Channel_Count_Description;
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
	case TUI_ERROR_INVALID_INSTANCE_DIMENSIONS:
		return kTui_Error_Invalid_Instance_Dimensions_Description;
	case TUI_ERROR_INVALID_PALETTE_COLOR_COUNT:
		return kTui_Error_Invalid_Palette_Color_Count_Description;
	case TUI_ERROR_INVALID_PANEL_DIMENSIONS:
		return kTui_Error_Invalid_Panel_Dimensions_Description;
	case TUI_ERROR_INVALID_PIXEL_DIMENSIONS:
		return kTui_Error_Invalid_Pixel_Dimensions_Description;
	case TUI_ERROR_LOAD_IMAGE_FAILURE:
		return kTui_Error_Load_Image_Failure_Description;
	case TUI_ERROR_LOAD_IMAGE_UNEXPECTED_CHANNELS:
		return kTui_Error_Load_Image_Unexpected_Channels_Description;
	case TUI_ERROR_NULL_BATCH:
		return kTui_Error_Null_Batch_Description;
	case TUI_ERROR_NULL_BATCH_DATA:
		return kTui_Error_Null_Batch_Data_Description;
	case TUI_ERROR_NULL_COLORS:
		return kTui_Error_Null_Colors_Description;
	case TUI_ERROR_NULL_GLYPH_ATLAS:
		return kTui_Error_Null_Glyph_Atlas_Description;
	case TUI_ERROR_NULL_GLYPH_BOUNDING_BOXES:
		return kTui_Error_Null_Glyph_Bounding_Boxes_Description;
	case TUI_ERROR_NULL_IMAGE:
		return kTui_Error_Null_Image_Description;
	case TUI_ERROR_NULL_INSTANCE:
		return kTui_Error_Null_Instance_Description;
	case TUI_ERROR_NULL_PALETTE:
		return kTui_Error_Null_Palette_Description;
	case TUI_ERROR_NULL_PANEL:
		return kTui_Error_Null_Panel_Description;
	case TUI_ERROR_NULL_PATH:
		return kTui_Error_Null_Path_Description;
	case TUI_ERROR_NULL_PIXELS:
		return kTui_Error_Null_Pixels_Description;
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
	case TUI_ERROR_UNMATCHING_ATLAS_INSTANCE:
		return kTui_Error_Unmatching_Atlas_Instance_Description;
	case TUI_ERROR_UNMATCHING_PALETTE_INSTANCE:
		return kTui_Error_Unmatching_Palette_Instance_Description;
	case TUI_ERROR_UNMATCHING_PANEL_INSTANCE:
		return kTui_Error_Unmatching_Panel_Instance_Description;
}
return kTui_Error_Unknown_Name;
}

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