cmake_minimum_required(VERSION 3.10)
project(hw2 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw2 main.c)

target_link_libraries(hw2 PRIVATE -lm)