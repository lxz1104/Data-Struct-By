cmake_minimum_required(VERSION 3.13)
project(StaticLinkList C)

set(CMAKE_C_STANDARD 99)

add_executable(StaticLinkList main.c StaticLinkList.c StaticLinkList.h)