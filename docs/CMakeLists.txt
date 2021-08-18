find_package(Doxygen)
if (DOXYGEN_FOUND)
	set(TUIC_DOXYGEN_SOURCES
		"${TUI_SOURCE_DIR}/docs/main.dox"
		"${TUI_SOURCE_DIR}/include/tuic/atlas.h"
		"${TUI_SOURCE_DIR}/include/tuic/atlas_type.h"
		"${TUI_SOURCE_DIR}/include/tuic/batch.h"
		"${TUI_SOURCE_DIR}/include/tuic/blend_mode.h"
		"${TUI_SOURCE_DIR}/include/tuic/boolean.h"
		"${TUI_SOURCE_DIR}/include/tuic/button_state.h"
		"${TUI_SOURCE_DIR}/include/tuic/cursor.h"
		"${TUI_SOURCE_DIR}/include/tuic/cursor_mode.h"
		"${TUI_SOURCE_DIR}/include/tuic/cursor_shape.h"
		"${TUI_SOURCE_DIR}/include/tuic/debug.h"
		"${TUI_SOURCE_DIR}/include/tuic/desktop_callback.h"
		"${TUI_SOURCE_DIR}/include/tuic/detail_flag.h"
		"${TUI_SOURCE_DIR}/include/tuic/detail_mode.h"
		"${TUI_SOURCE_DIR}/include/tuic/error_code.h"
		"${TUI_SOURCE_DIR}/include/tuic/events.h"
		"${TUI_SOURCE_DIR}/include/tuic/filter_mode.h"
		"${TUI_SOURCE_DIR}/include/tuic/heap.h"
		"${TUI_SOURCE_DIR}/include/tuic/image.h"
		"${TUI_SOURCE_DIR}/include/tuic/keyboard_key.h"
		"${TUI_SOURCE_DIR}/include/tuic/keyboard_mod.h"
		"${TUI_SOURCE_DIR}/include/tuic/monitor.h"
		"${TUI_SOURCE_DIR}/include/tuic/mouse_button.h"
		"${TUI_SOURCE_DIR}/include/tuic/palette.h"
		"${TUI_SOURCE_DIR}/include/tuic/panel.h"
		"${TUI_SOURCE_DIR}/include/tuic/system.h"
		"${TUI_SOURCE_DIR}/include/tuic/texture.h"
		"${TUI_SOURCE_DIR}/include/tuic/time.h"
		"${TUI_SOURCE_DIR}/include/tuic/tuic.h"
		"${TUI_SOURCE_DIR}/include/tuic/types.h"
		"${TUI_SOURCE_DIR}/include/tuic/window.h"
		)
		
	foreach(path IN LISTS TUIC_DOXYGEN_SOURCES)
		set(TUIC_DOXYGEN_INPUT "${TUIC_DOXYGEN_INPUT} \\\n\"${TUIC_SOURCE_DIR}/${path}\"")
	endforeach()

	set(TUIC_DOXYGEN_IN ${TUIC_SOURCE_DIR}/docs/Doxyfile.in)
    set(TUIC_DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)
	
	configure_file(${TUIC_DOXYGEN_IN} ${TUIC_DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")
	
	add_custom_target( TUIC_DOCS ALL
	COMMAND ${DOXYGEN_EXECUTABLE} ${TUIC_DOXYGEN_OUT}
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	COMMENT "Generating documentation with Doxygen"
	VERBATIM )

else (DOXYGEN_FOUND)
  message( SEND_ERROR "Unable to generate documentatation: Doxygen not installed. ")
endif()