# Set up CMake project
cmake_minimum_required(VERSION 3.21)
project(breadth_first_cpp)

# Set compile options
set(CMAKE_CXX_STANDARD 20)

# Setting CMake build options, adding path for binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Release mode by default, unless specified
# https://stackoverflow.com/questions/48832233/
# have-a-cmake-project-default-to-the-release-build-type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif ()

# Lots of warnings
add_compile_options(-Wall -Wextra -pedantic)

# Find appropriate packages
find_package(nlohmann_json REQUIRED)

# Adding C++ files needed for compilation
add_executable(
        breadth_first_cpp
        include/graph.hpp
        src/graph.cpp
        src/main.cpp
        include/parse_arguments.hpp
        src/parse_arguments.cpp
        include/print_path.hpp
        src/print_path.cpp
)

# Set include directory
target_include_directories(breadth_first_cpp PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link appropriate libraries to target
target_link_libraries(breadth_first_cpp nlohmann_json)

# Provide make with install target
install(TARGETS breadth_first_cpp DESTINATION bin)