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
add_executable(Task1 "Task1/task1.c")
add_executable(Close "Task1/task1close.c")
add_executable(Spread "Task1/task1spread.c")

add_executable(Flush "Task2/flush.c")
add_executable(NoFlush "Task2/noflush.c")

add_executable(MergesortRecursive "Task3/main.cpp" "Task3/Mergesort.cpp" "Task3/Mergesort.h")


# Link 
target_link_libraries(Task1 PRIVATE OpenMP::OpenMP_C)
target_link_libraries(Close PRIVATE OpenMP::OpenMP_C)
target_link_libraries(Spread PRIVATE OpenMP::OpenMP_C)
target_link_libraries(Flush PRIVATE OpenMP::OpenMP_C)
target_link_libraries(NoFlush PRIVATE OpenMP::OpenMP_C)
target_link_libraries(MergesortRecursive PRIVATE OpenMP::OpenMP_CXX)

# Compiler flags
set_target_properties(Flush PROPERTIES COMPILE_FLAGS "-O3" )
set_target_properties(NoFlush PROPERTIES COMPILE_FLAGS "-O3" )
set_target_properties(Task1 PROPERTIES COMPILE_FLAGS "-O3" )
set_target_properties(Close PROPERTIES COMPILE_FLAGS "-O3" )
set_target_properties(Flush PROPERTIES COMPILE_FLAGS "-O3" )