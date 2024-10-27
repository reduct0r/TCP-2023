cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)

project(lab8)

set(SOURCE_FILES
    main.cpp
    Point.hpp
    Graduate.hpp
    LabWork2_No8.h
)

# Вывод каждого пути файлов для проверки
foreach(FILE ${SOURCE_FILES})
    message(STATUS "Including source file: ${FILE}")
endforeach()

add_executable(lab8 ${SOURCE_FILES})
