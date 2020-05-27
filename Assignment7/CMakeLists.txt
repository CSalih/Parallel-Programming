# CMakeList.txt : CMake project for ParallelProgramming
cmake_minimum_required (VERSION 2.8)

# Project name
project (Assignment7)

# Add source to this project's executable.
add_executable(Parallel "Task1/Parallel.c")
add_executable(Seriell "Task1/Seriell.c")

add_executable(NQueensSeq "Task2/NQueensSeq.c")
add_executable(NQueensParallel "Task2/NQueensParallel.c")

set_target_properties(Seriell PROPERTIES COMPILE_FLAGS "-O3" )

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

# Need for OpenMP
include(FindOpenMP)
if(OPENMP_FOUND)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif(OPENMP_FOUND)