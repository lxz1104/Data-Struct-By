cmake_minimum_required(VERSION 3.13)
project(ParentTree C)

set(CMAKE_C_STANDARD 99)

add_executable(ParentTree main.c ParentTree.c ParentTree.h)