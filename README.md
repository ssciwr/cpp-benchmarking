# C++ Benchmarking

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/ssciwr/cpp-benchmarking/CI)](https://github.com/ssciwr/cpp-benchmarking/actions?query=workflow%3ACI)
[![codecov](https://codecov.io/gh/ssciwr/cpp-benchmarking/branch/main/graph/badge.svg)](https://codecov.io/gh/ssciwr/cpp-benchmarking)

Sample code to accompany the SSC compact course Performance benchmarking C++ applications.

- [pdf slides](https://github.com/ssciwr/cpp-benchmarking/raw/main/slides/slides.pdf)
- [pdf course description](https://ssc.iwr.uni-heidelberg.de/sites/default/files/ssc-benchmarking.pdf)

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

This code contains two very simple map implementations,
[vec_map](include/cppbench/vec_map.hpp) and [sorted_vec_map](include/cppbench/sorted_vec_map.hpp),
along with benchmarks of these and other map implementations.

## Micro-benchmarks

- [bench](bench) contains some micro-benchmarks using the [Google Benchmark](https://github.com/google/benchmark) library
- [plots](plots) contains some sample output & plots of these benchmarks and a simple Python script to make the plots

![plots/bench5.png](plots/bench5.png)

## Profiling

- [perf](perf) contains some scripts and plots using perf to profile performance

![perf/branch_miss.png](perf/branch_miss.png)
![perf/cache_miss.png](perf/cache_miss.png)

## Simulation

![sim/graph.png](sim/graph.png)

## Acknowledgements

This repo was quickly set up using the SSC [C++ Project Cookiecutter](https://github.com/ssciwr/cookiecutter-cpp-project).
