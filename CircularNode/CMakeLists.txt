cmake_minimum_required(VERSION 3.13)
project(CircularNode C)

set(CMAKE_C_STANDARD 11)

add_executable(CircularNode main.c CircularLinkedList.c CircularLinkedList.h)