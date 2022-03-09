######################################################################################################
# Setting up the project

	##################################################################################################
	# C Make Minimum Version
		
		cmake_minimum_required(VERSION 3.14)
	#
	##################################################################################################
	# Project Name Version and Languaje, print and add preprocessor flag
		
		project(CPVector VERSION 0.0.1 LANGUAGES CXX)
		message(STATUS "Building ${CMAKE_PROJECT_NAME} Version = ${CMAKE_PROJECT_VERSION}...")

		string(TOUPPER ${CMAKE_PROJECT_NAME} PROJECT_NAME_UPPER)
		add_definitions( -D${PROJECT_NAME_UPPER}_VERSION="${CMAKE_PROJECT_VERSION}" )
	#
	##################################################################################################
	# Set up C++ Version

		set(CMAKE_CXX_STANDARD 14) 
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
	#
	##################################################################################################
#
######################################################################################################
# Append Source

	add_subdirectory(src)
#
######################################################################################################
# Append Examples

	if( CPVECTOR_BUILD_EXAMPLES  STREQUAL "ON")
		add_subdirectory(examples)
	endif()
#
######################################################################################################
