cmake_minimum_required(VERSION 3.0)
project("RVC" C)

include(CTest)

add_subdirectory(external)

add_subdirectory(RVC_HW)
add_subdirectory(RVC_SW)
add_subdirectory(RVC_Test)

add_executable(RVC main.c)
target_link_libraries(RVC PRIVATE RVC_SW RVC_HW)

set_target_properties(RVC PROPERTIES OUTPUT_NAME RVC
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)