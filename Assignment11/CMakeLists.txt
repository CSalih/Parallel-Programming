# CMakeList.txt : CMake project for ParallelProgramming
cmake_minimum_required (VERSION 2.8)

# Project name
project (Assignment11)

# Add source to this project's executable.
add_executable(ScalarArchitecture "Task1/ScalarArchitecture.c")
add_executable(Transformation "Task2/Transformation.c")

set_target_properties(ScalarArchitecture PROPERTIES COMPILE_FLAGS "-O3" )
set_target_properties(Transformation PROPERTIES COMPILE_FLAGS "-O3" )
target_link_libraries(Transformation PRIVATE m)


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