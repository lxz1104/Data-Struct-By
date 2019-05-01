cmake_minimum_required(VERSION 3.13)
project(MyString C)

set(CMAKE_C_STANDARD 99)

add_executable(MyString main.c SeqString.c SeqString.h)