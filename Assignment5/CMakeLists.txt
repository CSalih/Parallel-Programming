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
# e.g. add_executable (Example "Task1/main.cpp" "Task1/Example.cpp" "Task1/Example.h")

# target_link_libraries(Example PRIVATE OpenMP::OpenMP_CXX)   # Link OpenMP
# target_link_libraries(Example PRIVATE m)                    # Link math library
# target_link_libraries(Example PRIVATE pthread)              # Link pthread