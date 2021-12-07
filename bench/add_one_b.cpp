#include "cppbench/add_one.hpp"
#include <benchmark/benchmark.h>

static void bench_add_one(benchmark::State &state) {
  int d{0};
  for (auto _ : state) {
    cppbench::add_one(d);
  }
}

BENCHMARK(bench_add_one)->Range(1, 64)->Complexity();
