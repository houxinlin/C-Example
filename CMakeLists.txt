cmake_minimum_required(VERSION 3.20)
project(C_Example C)

set(CMAKE_C_STANDARD 99)
add_executable(C_Example  example/ip地址.c)
SET(CMAKE_C_FLAGS -pthread)