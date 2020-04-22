# CMakeList.txt : CMake project for ParallelProgramming
cmake_minimum_required (VERSION 3.8)

# Project name
project ("Assignment5" LANGUAGES C CXX)

# Compiler configuration
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

SET(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Need for OpenMP
find_package(OpenMP REQUIRED)


# Add source to this project's executable.
add_executable(Mergesort "Task3/main.cpp" "Task3/Mergesort.cpp" "Task3/Mergesort.h")
add_executable(Flush "Task2/flush.c")

target_link_libraries(Mergesort PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(Flush PRIVATE OpenMP::OpenMP_CXX)

set_target_properties(Flush PROPERTIES COMPILE_FLAGS "-O3" )


# target_link_libraries(Example PRIVATE OpenMP::OpenMP_CXX)   # Link OpenMP
# target_link_libraries(Example PRIVATE m)                    # Link math library
# target_link_libraries(Example PRIVATE pthread)              # Link pthread