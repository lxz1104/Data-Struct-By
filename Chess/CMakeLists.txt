cmake_minimum_required(VERSION 3.13)
project(Chess C)

set(CMAKE_C_STANDARD 99)

add_executable(Chess main.c GoBang.c  ChessData.c )