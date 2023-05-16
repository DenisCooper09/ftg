cmake_minimum_required(VERSION 3.25)
project(fractal_tree_generator)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        source/main.cpp
        )

add_executable(fractal_tree_generator ${SOURCE_FILES})
