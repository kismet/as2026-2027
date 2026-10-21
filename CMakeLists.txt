cmake_minimum_required(VERSION 4.2)
project(as2026_2027)

set(CMAKE_CXX_STANDARD 14)

include_directories("4ci/set/Libreria insiemi")

add_executable(as2026_2027
        "4ci/set/Libreria insiemi/corpoFunzioni.cpp"
        "4ci/set/Libreria insiemi/firme.h"
        "4ci/set/Libreria insiemi/types.h"
        4ci/set/main.cpp)
