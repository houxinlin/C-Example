cmake_minimum_required(VERSION 3.20)
project(C_Example C)

set(CMAKE_C_STANDARD 99)
add_executable(C_Example example/获取当前时间.c)
SET(CMAKE_C_FLAGS -pthread)