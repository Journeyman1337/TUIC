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
/*! \file blend_mode.h
 */
#ifndef TUIC_BLEND_MODE_H //header guard
#define TUIC_BLEND_MODE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/boolean.h>


/*! @name Blend modes
 *  @{ */
/*!
* @brief How the to blend the foreground and background colors with the channels of a @ref TuiAtlas when drawing batch data.
*/
typedef enum TuiBlendMode
{
	/*!
	 * \brief The blend mode is invalid.
	 *
	 * This blend mode is returned when an error occurs, and is also used to specify that no blend mode is
	 * defined.
	 */
	TUI_BLEND_INVALID = 0,
	/*!
	 * \brief No color blending occurs and the foreground and background colors are ignored.
	 */
	TUI_BLEND_NORMAL = 1,
	/*!
	 * \brief Blend mode that blends the glyph foreground color with the red color component of the atlas texture.
	 */
	TUI_BLEND_FG_RED = 2,
	/*!
	 * \brief Blend mode that blends the glyph foreground color with the green color component of the atlas texture.
	 */
	TUI_BLEND_FG_GREEN = 3,
	/*!
	 * \brief Blend mode that blends the glyph foreground color with the blue color component of the atlas texture.
	 */
	TUI_BLEND_FG_BLUE = 4,
	/*!
	 * \brief Blend mode that blends the atlas texture color based on the alpha channel to mix the foreground and background color, with an alpha value of 0 blending only the foreground color.
	 */
	TUI_BLEND_FG_ALPHA = 5,
	/*!
	 * \brief Blend mode that blends the glyph background color with the red color component of the glyph texture.
	 */
	TUI_BLEND_BG_RED = 6,
	/*!
	 * \brief Blend mode that blends the glyph background color with the red color component of the glyph texture.
	 */
	TUI_BLEND_BG_GREEN = 7,
	/*!
	 * \brief Blend mode that blends the glyph background color with the red color component of the glyph texture.
	 */
	TUI_BLEND_BG_BLUE = 8,
	/*!
	 * \brief Blend mode that blends the atlas texture color based on the alpha channel to mix the foreground and background color, with an alpha value of 0 blending only the background color.
	 */
	TUI_BLEND_BG_ALPHA = 9,
	/*!
	 * \brief The first valid blend mode value.
	 */
	TUI_BLEND_FIRST = TUI_BLEND_NORMAL,
	/*!
	 * \brief The last valid blend mode value.
	 */
	TUI_BLEND_LAST = TUI_BLEND_BG_ALPHA
} TuiBlendMode;
/*! @} */


/*! @name TuiBlendMode names
 *  @{ */
/*!
 * @brief String name of @ref TUI_BLEND_NORMAL.
 */
extern const char* kTui_Blend_NORMAL_Name;
/*!
 * @brief String name of @ref TUI_BLEND_FG_RED.
 */
extern const char* kTui_Blend_FG_RED_Name;
/*!
 * @brief String name of @ref TUI_BLEND_FG_GREEN.
 */
extern const char* kTui_Blend_FG_GREEN_Name;
/*!
 * @brief String name of @ref TUI_BLEND_FG_BLUE.
 */
extern const char* kTui_Blend_FG_BLUE_Name;
/*!
 * @brief String name of @ref TUI_BLEND_FG_ALPHA.
 */
extern const char* kTui_Blend_FG_ALPHA_Name;
/*!
 * @brief String name of @ref TUI_BLEND_BG_RED.
 */
extern const char* kTui_Blend_BG_RED_Name;
/*!
 * @brief String name of @ref TUI_BLEND_BG_GREEN.
 */
extern const char* kTui_Blend_BG_GREEN_Name;
/*!
 * @brief String name of @ref TUI_BLEND_BG_BLUE.
 */
extern const char* kTui_Blend_BG_BLUE_Name;
/*!
 * @brief String name of @ref TUI_BLEND_BG_ALPHA.
 */
extern const char* kTui_Blend_BG_ALPHA_Name;
/*! @} */


/*! @name TuiBlendMode functions
 *
 * Functions for dealing with @ref TuiBlendMode enum values.
 *  @{ */
/*!
 * @brief Determine if a @ref TuiBlendMode enum is valid.
 * 
 * @param blend_mode The @ref TuiBlendMode to check.
 * 
 * @returns The @ref TuiBoolean result. If it atlas_type is a valid @ref TuiBlendMode, it
 * returns @ref TuiTrue. Otherwise, it returns @ref TuiFalse.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBoolean tuiBlendIsValid(TuiBlendMode blend_mode);
/*!
 * @brief Retrieve the string name associated with a @ref TuiBlendMode enum.
 *
 * @param blend_mode The TuiBlendMode to get the name of.
 *
 * @returns The string name. NULL is returned if blend_mode is an invalid @ref TuiBlendMode.
 * 
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
const char* tuiBlendModeToString(TuiBlendMode blend_mode);
/*!
 * @brief Determine the @ref TuiBlendMode enum value associated with a string name.
 *
 * @param str The string name.
 *
 * @returns The @ref TuiBlendMode. @ref TUI_BLEND_INVALID is returned if no match is found.
 *
 * @errors This function can have no errors.
 *
 * @requirements This function can be called freely, even if TUIC is not currently initialized.
 *
 * @thread_safety This function does not access memory in ways that could cause a data race, so it is thread safe.
 */
TuiBlendMode tuiStringToBlendMode(const char* string);
/*! @} */


#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard