find_package(Doxygen)
if (DOXYGEN_FOUND)
	set(TUIC_DOXYGEN_SOURCES
		"${TUI_SOURCE_DIR}/docs/main.dox"
		"${TUI_SOURCE_DIR}/include/tuic/tuic.h"
		"${TUI_SOURCE_DIR}/include/tuic/heap.h"
		"${TUI_SOURCE_DIR}/include/tuic/types.h"
		"${TUI_SOURCE_DIR}/include/tuic/enums.h"
		"${TUI_SOURCE_DIR}/include/tuic/debug.h"
		"${TUI_SOURCE_DIR}/include/tuic/instance.h"
		"${TUI_SOURCE_DIR}/include/tuic/panel.h"
		"${TUI_SOURCE_DIR}/include/tuic/palette.h"
		"${TUI_SOURCE_DIR}/include/tuic/glyph_atlas.h"
		"${TUI_SOURCE_DIR}/include/tuic/batch.h"
		"${TUI_SOURCE_DIR}/include/tuic/image.h"
		"${TUI_SOURCE_DIR}/include/tuic/texture.h"
		"${TUI_SOURCE_DIR}/include/tuic/backends/objects.h"
		"${TUI_SOURCE_DIR}/include/tuic/backends/opengl33.h"
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