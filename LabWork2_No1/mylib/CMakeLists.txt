cmake_minimum_required(VERSION 3.8)

set(project "mylib")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        mylib.cpp)

set(${project}_HEADERS
        mylib.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
