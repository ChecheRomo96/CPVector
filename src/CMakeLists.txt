# Store this directory as a variable called CPVECTOR_SRC_DIRECTORY to reference in deeper directories
set( CPVECTOR_SRC_DIRECTORY  ${CMAKE_CURRENT_LIST_DIR})

# Initialize HEADER_LIST as an empty string list
set( HEADERS_LIST "" )

# Append Headers
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPVector.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPVector_BuildSettings.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPVector_Template.h")

# Add Subdirectories
add_subdirectory(Sorting)

# Create the CPVector library (STATIC is not justified tho) and include the directories needed to compile
add_library(CPVector INTERFACE)

# Include directories for install and for build 
target_include_directories( 
	CPVector INTERFACE 
	$<INSTALL_INTERFACE:include/CPVector> 
	$<BUILD_INTERFACE:${CPVECTOR_SRC_DIRECTORY}> 
)

# CPVector install process
if( INSTALL STREQUAL "ON")

	install(
		FILES ${HEADERS_LIST} 
		DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CPVector 
	)

	install(
		TARGETS CPVector 
		EXPORT CPVectorExport
		DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/CPVector
	)

	install(
		EXPORT CPVectorExport
		FILE CPVector-config.cmake
		DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/CPVector
	)

endif()