include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

function(check_submodules_present)
	file(READ "${CMAKE_SOURCE_DIR}/.gitmodules" gitmodules)
	string(REGEX MATCHALL "path *= *[^ \t\r\n]*" gitmodules ${gitmodules})

	foreach(module ${gitmodules})
		# Get module name
		string(REGEX REPLACE "path *= *" "" module ${module})

		# Stat the folder and get ammount of entries
		file(GLOB RESULT "${CMAKE_SOURCE_DIR}/${module}/*")
		list(LENGTH RESULT RES_LEN)

		# If the module has no files, bring fatal error
		if(RES_LEN EQUAL 0)
			# directory is empty
			message(FATAL_ERROR "Submodule ${module} is empty. "
				"Please run: git submodule update --init --recursive")
		endif()
	endforeach()
endfunction()

check_submodules_present()

## Unity
add_library(Unity STATIC "${CMAKE_CURRENT_SOURCE_DIR}/Unity/src/unity.c")
target_include_directories(Unity PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Unity/src")
set_property(TARGET Unity PROPERTY FOLDER external)

## CMock
add_library(CMock STATIC "${CMAKE_CURRENT_SOURCE_DIR}/CMock/src/cmock.c")
target_include_directories(CMock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/CMock/src")
set_property(TARGET CMock PROPERTY FOLDER external)
target_link_libraries(CMock Unity)