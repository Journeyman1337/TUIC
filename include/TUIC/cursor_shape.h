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
/*! \file cursor_shape.h
 */
 #ifndef TUIC_CURSOR_SHAPE_H //header guard
#define TUIC_CURSOR_SHAPE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif

enum TuiCursorShape
{
	TUI_ARROW_CURSOR          = 0x00036001,
	TUI_IBEAM_CURSOR          = 0x00036002,
	TUI_CROSSHAIR_CURSOR      = 0x00036003,
	TUI_POINTING_HAND_CURSOR  = 0x00036004,
	TUI_RESIZE_EW_CURSOR      = 0x00036005,
	TUI_RESIZE_NS_CURSOR      = 0x00036006,
	TUI_RESIZE_NWSE_CURSOR    = 0x00036007,
	TUI_RESIZE_NESW_CURSOR    = 0x00036008,
	TUI_RESIZE_ALL_CURSOR     = 0x00036009,
	TUI_NOT_ALLOWED_CURSOR    = 0x0003600A,
	TUI_HRESIZE_CURSOR        = TUI_RESIZE_EW_CURSOR,
	TUI_VRESIZE_CURSOR        = TUI_RESIZE_NS_CURSOR,
	TUI_HAND_CURSOR           = TUI_POINTING_HAND_CURSOR
};

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard