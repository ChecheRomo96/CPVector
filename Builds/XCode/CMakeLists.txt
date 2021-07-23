cmake_minimum_required(VERSION 3.14)
project(EVectorXcode CXX)
set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/EmbeddedVector)


add_executable( EVectorXcode main.cpp ) 
