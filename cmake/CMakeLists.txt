cmake_minimum_required(VERSION 3.5)
project(demo1)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

message("default build type is ${CMAKE_BUILD_TYPE}")
add_executable(demo1 ${SOURCE_FILES})
