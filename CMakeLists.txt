cmake_minimum_required(VERSION 3.25)
project(fractal_tree_generator)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        source/main.cpp
        )

add_executable(fractal_tree_generator ${SOURCE_FILES})

set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(fractal_tree_generator sfml-graphics)
