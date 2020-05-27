# CMakeList.txt : CMake project for ParallelProgramming
cmake_minimum_required (VERSION 2.8)

# Project name
project (Assignment8)

# Add source to this project's executable.
add_executable(Analysis "Task2/Analysis.c")

set_target_properties(Analysis PROPERTIES COMPILE_FLAGS "-O2 -ftree-vectorize -fopt-info-vec-all" )

# Compiler configuration
if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
  endif ()
else ()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)

  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)
endif()