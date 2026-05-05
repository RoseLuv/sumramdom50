cmake_minimum_required(VERSION 3.10)

project(sumrandom50)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(sumrandom50
    src/main.cpp
    src/controller.cpp
    src/digit.cpp
    src/number.cpp
)

add_compile_options(-g -Wall -Wextra -Wpedantic)

