cmake_minimum_required(VERSION 3.23)

set(project "lab7")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        main.cpp
        Ship.h
        Steamboat.h
        Sailboat.h
        Сorvette.h
)

add_subdirectory("MyVector")

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST} )

target_link_libraries(${project} MyVector)