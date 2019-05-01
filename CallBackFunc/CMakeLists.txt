cmake_minimum_required(VERSION 3.13)
project(CallBackFunc C)

set(CMAKE_C_STANDARD 99)

add_executable(CallBackFunc main.c CallBackFunc.c CallBackFunc.h)