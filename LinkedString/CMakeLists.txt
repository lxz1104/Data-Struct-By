cmake_minimum_required(VERSION 3.13)
project(LinkedString C)

set(CMAKE_C_STANDARD 99)

add_executable(LinkedString main.c LinkedString.c LinkedString.h StatusLib.h)