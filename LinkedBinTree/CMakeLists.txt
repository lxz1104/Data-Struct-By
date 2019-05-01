cmake_minimum_required(VERSION 3.13)
project(LinkedBinTree C)

set(CMAKE_C_STANDARD 99)

add_executable(LinkedBinTree main.c LinkedBinTree.c  LinkedStack.c LinkedQueue.c LinkedQueue.h)