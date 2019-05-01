cmake_minimum_required(VERSION 3.13)
project(LinearList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinearList main.cpp SeqList.h Node.h LinkedList.h)