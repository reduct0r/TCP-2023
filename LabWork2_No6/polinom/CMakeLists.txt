cmake_minimum_required(VERSION 3.8)

set(project "polinom")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        polinom.cpp)

set(${project}_HEADERS
        polinom.h
        term.h
        MyVector.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
