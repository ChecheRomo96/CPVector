cmake_minimum_required(VERSION 3.14)
project(EVectorXcode CXX)
set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
include_directories(src/EmbeddedVector)

add_executable( EVectorLinux main.cpp ) 
