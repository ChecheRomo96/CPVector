######################################################################################################
# Setting up the project

	##################################################################################################
	# C Make Minimum Version
		
		cmake_minimum_required(VERSION 3.14)
	#
	##################################################################################################
	# Project Name Version and Languaje, print and add preprocessor flag
		
		project(CPVector VERSION 1.0.0 LANGUAGES CXX)
		message(STATUS "Building ${PROJECT_NAME} Version = ${PROJECT_VERSION}...")

		string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
	#
	##################################################################################################
	# Set up C++ Version

		set(CMAKE_CXX_STANDARD 14) 
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
	#
	##################################################################################################
#
######################################################################################################
# Compile Configuration

	set(CPVECTOR_BUILD_EXAMPLES TRUE CACHE BOOL "Build CPVector Examples")
#
######################################################################################################
# Append Source

	add_subdirectory(src)
	target_compile_definitions(CPVector INTERFACE ${PROJECT_NAME_UPPER}_VERSION="${PROJECT_VERSION}" )

#
######################################################################################################
# Append Examples

	if( ${CPVECTOR_BUILD_EXAMPLES} )
		message("Building ${CMAKE_PROJECT_NAME} Examples...")
		add_subdirectory(examples)
	endif()
#
######################################################################################################
