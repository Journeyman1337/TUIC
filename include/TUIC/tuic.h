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
/*! \file tuic.h
 * The global include for the TUIC library. This header file includes all other headers meant to be used outside of backend implementation.
 */

#include <TUIC/atlas_type.h>
#include <TUIC/batch.h>
#include <TUIC/blend_mode.h>
#include <TUIC/boolean.h>
#include <TUIC/button_state.h>
#include <TUIC/configuration.h>
#include <TUIC/context_backend.h>
#include <TUIC/cursor.h>
#include <TUIC/cursor_shape.h>
#include <TUIC/debug.h>
#include <TUIC/desktop_callback.h>
#include <TUIC/detail_flag.h>
#include <TUIC/detail_mode.h>
#include <TUIC/filter_mode.h>
#include <TUIC/glyph_atlas.h>
#include <TUIC/graphics_backend.h>
#include <TUIC/heap.h>
#include <TUIC/image.h>
#include <TUIC/instance.h>
#include <TUIC/joystick_hat_state.h>
#include <TUIC/joystick_id.h>
#include <TUIC/key.h>
#include <TUIC/key_mod.h>
#include <TUIC/monitor.h>
#include <TUIC/mouse_button.h>
#include <TUIC/palette.h>
#include <TUIC/panel.h>
#include <TUIC/system.h>
#include <TUIC/texture.h>
#include <TUIC/types.h>
#include <TUIC/window_attribute.h>