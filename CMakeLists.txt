cmake_minimum_required(VERSION 3.21)
project(breadth_first_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(breadth_first_cpp main.cpp read_adj_list.cpp read_adj_list.h parse_arguments.cpp parse_arguments.h)

# Providing make with install target.
install(TARGETS breadth_first_cpp DESTINATION bin)