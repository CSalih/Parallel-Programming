# Parallel Programming
Topics:
* parallel programming concepts
* shared memory parallelization using OpenMP
* performance-oriented programming
* proper experiment orchestration and benchmarking
* parallel programming tools


## Content
| Exec               | Topics                                    | Notes             |
|--------------------|-------------------------------------------|-------------------|
| [Skripts](Common)  | Benchmark script                          |                   |
| [1](Assignment1)   | Scaling characteristics                   |                   |
| [2](Assignment2)   | Performance-oriented programming          | cachegrind, perf  |
| [3](Assignment3)   | OpenMP - Basics                           |                   |
| [4](Assignment4)   | OpenMP - Parallel                         | Mergesort         |
| [5](Assignment5)   | OpenMP - Affinity                         |                   |
| [6](Assignment6)   | OpenMP - Tasks                            |                   |
| [7](Assignment7)   | OpenMP - Barrier                          | NQueens           |
| [8](Assignment8)   | Data and control dependencies             |                   |
| [9](Assignment9)   | Dependencies analysis                     |                   |
| [10](Assignment10) | Profiling                                 | gprof             |
| [11](Assignment11) | Program optimizations                     |                   |
| [12](Assignment12) | Vectorizing                               |                   |


## Requirements
* GNU C/C++ compiler (Clang not tested, MSVC works limited)
* CMake Version `3.8+`

If you want to use this project on Windows you can configure [WSL on Windows 10](https://docs.microsoft.com/en-us/windows/wsl/install-win10).


## Setup
We recommend using [VS Code](https://code.visualstudio.com/) with the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools&ssr=false#overview) and [C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) extension as text editor. Before we can start you have to configure CMake Tools [Getting Started](https://vector-of-bool.github.io/docs/vscode-cmake-tools/getting_started.html).

Type in the command pallette (`STRG + Shift + P`) of VS Code.
```
> CMake: Quick Start
```

## Build
### VS Code
Build a specific executable type in the command pallette:
```
> CMake: Build Target
```
now you can select the executable you want to build. To Build all executable:
```
> CMake: Build
```

Executable is located in the `build` folder. For more details please read the official documentation of [CMake Tools: Building](https://vector-of-bool.github.io/docs/vscode-cmake-tools/building.html).


### CMake cli

``` bash
$ cd Project_Dir/Assignment[N]
$ mkdir build
$ cd build
$ cmake ..
$ make
```
