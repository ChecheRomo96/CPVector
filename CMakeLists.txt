cmake_minimum_required(VERSION 3.14)

project(CPVector VERSION 0.0.1 LANGUAGES CXX)

message("Building ${PROJECT_NAME} Version = ${PROJECT_VERSION}...")
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
target_compile_definitions(CPVector INTERFACE ${PROJECT_NAME_UPPER}_VERSION="${PROJECT_VERSION}" )

if( BUILD_EXAMPLES  STREQUAL "ON")
	add_subdirectory(examples)
endif()