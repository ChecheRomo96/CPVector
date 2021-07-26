cmake_minimum_required(VERSION 3.14)

project(EVector CXX)

set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

if( EVECTOR_BUILD_TESTS  STREQUAL "ON")
	add_subdirectory(tests)
endif()