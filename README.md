# Welcome to cpp_benchmarking

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/lkeegan/cpp-benchmarking/CI)](https://github.com/lkeegan/cpp-benchmarking/actions?query=workflow%3ACI)
[![codecov](https://codecov.io/gh/lkeegan/cpp-benchmarking/branch/main/graph/badge.svg)](https://codecov.io/gh/lkeegan/cpp-benchmarking)


# Prerequisites

Building cpp_benchmarking requires the following software installed:

* A C++17-compliant compiler
* CMake `>= 3.9`

# Building cpp_benchmarking

The following sequence of commands builds cpp_benchmarking.
It assumes that your current working directory is the top-level directory
of the freshly cloned repository:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

The build process can be customized with the following CMake variables,
which can be set by adding `-D<var>={ON, OFF}` to the `cmake` call:

* `BUILD_TESTING`: Enable building of the test suite (default: `ON`)

# Documentation

cpp_benchmarking *should* provide a documentation.
