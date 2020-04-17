# CMakeList.txt : CMake project for ParallelProgramming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Assignment1")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

SET(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_package(OpenMP REQUIRED)

# Add source to this project's executable.
add_executable (fast "fast.c")
add_executable (medium "medium.c")
add_executable (slow "slow.c")

target_link_libraries(fast PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(medium PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(slow PRIVATE OpenMP::OpenMP_CXX)


# TODO: Add tests and install targets if needed.
