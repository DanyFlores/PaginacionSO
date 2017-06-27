cmake_minimum_required(VERSION 3.7)
project(Paginacion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp node.h list.h .idea/procesosPaginacion.h)
add_executable(Paginacion ${SOURCE_FILES})