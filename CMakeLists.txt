# Set up CMake project
cmake_minimum_required(VERSION 3.21)
project(breadth_first_cpp)

# Set compile options
set(CMAKE_CXX_STANDARD 20)

# Setting CMake build options, adding path for binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Lots of warnings
add_compile_options(-Wall -Wextra -pedantic)

# Find appropriate packages
find_package(nlohmann_json REQUIRED)

# Adding C++ files needed for compilation.
add_executable(breadth_first_cpp main.cpp read_adj_list.cpp read_adj_list.hpp parse_arguments.cpp parse_arguments.hpp)

# Linking appropriate libraries to target.
target_link_libraries(breadth_first_cpp nlohmann_json)

# Providing make with install target.
install(TARGETS breadth_first_cpp DESTINATION bin)