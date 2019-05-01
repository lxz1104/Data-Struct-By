cmake_minimum_required(VERSION 3.13)
project(LinkStack C)

set(CMAKE_C_STANDARD 99)

link_libraries(psapi)

add_executable(LinkStack main.c LinkedStack.c LinkedStack.h)