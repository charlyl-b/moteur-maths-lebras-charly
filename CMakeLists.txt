cmake_minimum_required(VERSION 3.16)

project(R5A12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(".")

# Linux: install libsfml-dev package.
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

add_executable(R5A12 main.cpp GameWindow.cpp GameWindow.h)
target_link_libraries(R5A12 sfml-graphics sfml-window sfml-system)


