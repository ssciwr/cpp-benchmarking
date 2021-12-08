#pragma once
#include <benchmark/benchmark.h>
#include <random>
#include <vector>

template <typename T>
std::vector<T> generate_keys(std::size_t n, std::mt19937 &gen) {
  std::vector<T> keys(n);
  std::uniform_int_distribution<T> dist(0, std::numeric_limits<T>::max());
  std::generate(keys.begin(), keys.end(),
                [&dist, &gen]() { return dist(gen); });
  return keys;
}
