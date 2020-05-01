# CMakeList.txt : CMake project for ParallelProgramming
cmake_minimum_required (VERSION 3.8)

# Project name
project ("Assignment6" LANGUAGES C)

# Compiler configuration
SET(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Need for OpenMP
find_package(OpenMP REQUIRED)

# Add source to this project's executable.
add_executable(CalcFolderSize "Task1/CalcFolderSize.c")
add_executable(HeatStencil "Task2/HeatStencil.c")

# Link 
target_link_libraries(CalcFolderSize PRIVATE OpenMP::OpenMP_C)
target_link_libraries(HeatStencil PRIVATE OpenMP::OpenMP_C)
target_link_libraries(HeatStencil PRIVATE m)


# Compiler flags
set_target_properties(CalcFolderSize PROPERTIES COMPILE_FLAGS "-D_BSD_SOURCE" )
