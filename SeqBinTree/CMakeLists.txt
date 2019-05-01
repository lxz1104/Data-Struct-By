cmake_minimum_required(VERSION 3.13)
project(SeqBinTree C)

set(CMAKE_C_STANDARD 99)

add_executable(SeqBinTree main.c SeqTree.c SeqTree.h)