# CMakeList.txt : CMake project for ParallelProgramming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Assignment2")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

SET(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Add source to this project's executable.
add_executable (CacheMiss "Task2/CacheMiss.cpp" "Task2/Cache.cpp" "Task2/Cache.h")
add_executable (RowMajor "Task2/Hadamard.c")
add_executable (ColMajor "Task2/Hadamard.c")

add_executable (PiParallel "Task3/PiParallel.c")
add_executable (PiSerial "Task3/PiSerial.c")

set_target_properties(ColMajor PROPERTIES COMPILE_FLAGS "-DCOL_MAJOR")

target_link_libraries(PiParallel pthread)

# TODO: Add tests and install targets if needed.
