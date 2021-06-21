file(GLOB implemntation_lib_files
	Example-00-Implementation/*
)
add_library(Example-00-Implementation ${implemntation_lib_files})
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
target_link_libraries(Example-00-Implementation
	PUBLIC
		${PROJECT_NAME}
		glfw
		GLEW::GLEW
)
set_property(TARGET Example-00-Implementation PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:Example-00-Implementation>)
# cmake function for adding an example project
function(add_example Name)
	# create the executable for the example
	add_executable(${Name}
		${Name}/main.c
	)
	# link the implementation library
	target_link_libraries(${Name}
		PUBLIC
			Example-00-Implementation
	)
	# grab the content file paths
	file(GLOB asset_files
		assets/*
	)
	# copy the content files to the executable output folder post build
	add_custom_command(TARGET ${Name} POST_BUILD    
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			${asset_files}
			$<TARGET_FILE_DIR:${Name}>
	)
	# tell visual studio to use the output folder as the working directory instead of the project folder
	set_property(TARGET ${Name} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${Name}>)
endfunction()

add_example(Example-01-Basic-Panel)
add_example(Example-02-Channel-Replace-Blend-Modes)
add_example(Example-03-Panel-Transformed-Rendering)
add_example(Example-04-Dynamic-Resizing)
add_example(Example-05-Basic-Text-Rendering)
add_example(Example-06-Simple-Topdown-Character)
add_example(Example-07-Mouse-Input)
add_example(Example-08-Matrix-Rain)