# cpp-benchmarking

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/ssciwr/cpp-benchmarking/CI)](https://github.com/ssciwr/cpp-benchmarking/actions?query=workflow%3ACI)
[![codecov](https://codecov.io/gh/ssciwr/cpp-benchmarking/branch/main/graph/badge.svg)](https://codecov.io/gh/ssciwr/cpp-benchmarking)

Sample code to accompany the compact course [Performance benchmarking C++ applications](https://ssc.iwr.uni-heidelberg.de/sites/default/files/ssc-benchmarking.pdf)

Course slides: todo

## Getting started

To clone the repo and compile the code:

```
git clone --recursive https://github.com/ssciwr/cpp-benchmarking.git
cd cpp-benchmarking
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

To enable the optional abseil dependency:

- install abseil, e.g. `brew install abseil` on mac, `sudo apt-get install libabsl-dev` on ubuntu
- enable it when configuring cmake: `-DCPPBENCH_WITH_ABSEIL=ON`

## Micro-benchmarks

`./bench/benchX` compare the performance of some different map implementations using the [Google Benchmark](https://github.com/google/benchmark) library.

## Profiling

todo

## Simulation

todo

This repo was quickly set up using the SSC [C++ Project Cookiecutter](https://github.com/ssciwr/cookiecutter-cpp-project).
