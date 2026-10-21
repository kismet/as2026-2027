cmake_minimum_required(VERSION 4.0)
project(as2026_2027)

set(CMAKE_CXX_STANDARD 14)

include_directories(4ci/set/Tosi)
include_directories(4ci/set/Tosi/insiemi)

add_executable(as2026_2027
        4ci/set/Tosi/insiemi/library.cpp
        4ci/set/Tosi/insiemi/library.h
        4ci/set/Tosi/insiemi/library_types.h
        4ci/set/Tosi/main.cpp)
