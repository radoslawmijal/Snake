cmake_minimum_required(VERSION 3.26)
project(Snake)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Snake main.cpp
        Snake.cpp
        Snake.h
        Controller.cpp
        Controller.h
        View.h
        View.cpp)

file(COPY Images DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(Snake sfml-graphics)