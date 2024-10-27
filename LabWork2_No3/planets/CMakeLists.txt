cmake_minimum_required(VERSION 3.8)

set(project "planets")
project(${project})

set(CMAKE_CXX_STANDARD 23)

set(${project}_SOURCES
        planets.cpp)

set(${project}_HEADERS
        planets.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
