cmake_minimum_required(VERSION 4.2)
project(Preparazione_Verifica)

set(CMAKE_CXX_STANDARD 20)

add_executable(Preparazione_Verifica main.cpp
        inc/types.h
        inc/gestione.h
        src/gestione.cpp)
