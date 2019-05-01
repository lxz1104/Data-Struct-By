cmake_minimum_required(VERSION 3.13)
project(SequenceList C)

set(CMAKE_C_STANDARD 99)

add_executable(SequenceList main.c SequenceList.c SequenceList.h)