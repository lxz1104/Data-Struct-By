cmake_minimum_required(VERSION 3.13)
project(YSUMap)

set(CMAKE_CXX_STANDARD 14)

#set(INC_DIR include)
#set(LINK_DIR lib)

#include_directories(${INC_DIR})
#link_directories(${LINK_DIR})

#link_libraries(jsoncpp)

add_executable(YSUMap main.cpp AdjListGraph.cpp)

#target_link_libraries(YSUMap jsoncpp)
