# CMakeList.txt : CMake project for ParallelProgramming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(OpenMP REQUIRED)

# Add source to this project's executable.
add_executable (RowMajorOMP "Task2/Hadamard.c")
add_executable (ColMajorOMP "Task2/Hadamard.c")

set_target_properties(ColMajor PROPERTIES COMPILE_FLAGS "-DCOL_MAJOR")
target_link_libraries(RowMajorOMP PRIVATE OpenMP::OpenMP_C)
target_link_libraries(ColMajorOMP PRIVATE OpenMP::OpenMP_C)

# TODO: Add tests and install targets if needed.
