# CMakeList.txt : CMake project for ParallelProgramming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(OpenMP REQUIRED)

# Add source to this project's executable.
add_executable (Mergesort "Task3/main.cpp" "Task3/Mergesort.cpp" "Task3/Mergesort.h")
add_executable (Atomic "Task1/Atomic.c")
add_executable (Critical "Task1/Critical.c")
add_executable (Reduction "Task1/Reduction.c")
add_executable (Pthread "Task1/Pthread.c")

# Task 2
add_executable (ex2 "Task2/ex2.c")
add_executable (ex2_b "Task2/ex2_b.c")


target_link_libraries(Mergesort PRIVATE OpenMP::OpenMP_CXX)

target_link_libraries(Atomic PRIVATE OpenMP::OpenMP_C)
target_link_libraries(Critical PRIVATE OpenMP::OpenMP_C)
target_link_libraries(Reduction PRIVATE OpenMP::OpenMP_C)
target_link_libraries(ex2 PRIVATE OpenMP::OpenMP_C)
target_link_libraries(ex2_b PRIVATE OpenMP::OpenMP_C)


target_link_libraries(Atomic PRIVATE m)
target_link_libraries(Critical PRIVATE m)
target_link_libraries(Reduction PRIVATE m)
target_link_libraries(Pthread PRIVATE m pthread)

# TODO: Add tests and install targets if needed.
