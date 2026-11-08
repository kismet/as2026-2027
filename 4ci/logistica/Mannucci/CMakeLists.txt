cmake_minimum_required(VERSION 4.2)
project(Logistica)

set(CMAKE_CXX_STANDARD 20)

add_executable(Logistica main.cpp
        gestioneLogistica/logisticaTypes.h
        gestioneLogistica/logistica.h
        gestioneLogistica/logistica.cpp)
