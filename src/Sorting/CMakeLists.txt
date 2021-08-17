# Initialize HEADER_LIST as an empty string list
set( HEADERS_LIST "" )

# Append Headers
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPVector_Sorting.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPVector_SortingArray.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPVector_SortingDefinitions.h")
list( APPEND HEADERS_LIST "${CMAKE_CURRENT_LIST_DIR}/CPVector_SortingTemplates.h")

# CPVector install process
if( INSTALL STREQUAL "ON")

	install(
		FILES ${HEADERS_LIST} 
		DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CPVector/Sorting 
	)

endif()