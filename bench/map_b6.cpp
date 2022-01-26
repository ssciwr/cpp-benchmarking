#include "bench.hpp"
#include "cppbench/vec_map.hpp"
#include <benchmark/benchmark.h>
#include <limits>
#include <map>
#include <random>
#include <unordered_map>

using KeyType = std::uint32_t;

// no-op "Map" that does nothing to allow us to measure overhead of random key
// selection in benchmark
template <typename Key, typename Value> struct no_op_map {
  void insert(const std::pair<Key, Value> &p) {}
  Value find(Key key) { return 0; }
};

template <typename Map> static void bench_map(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(12345);
  auto keys{generate_keys<KeyType>(n, gen)};
  Map map;
  for (auto key : keys) {
    map.insert({key, key});
  }
  // distribution to pick a random index from the keys vector
  std::uniform_int_distribution<std::size_t> idist(0, n - 1);
  for (auto _ : state) {
    // pick a random key at every iteration: expensive but cost independent of
    // map
    auto key{keys[idist(gen)]};
    benchmark::DoNotOptimize(map.find(key));
  }
  state.SetComplexityN(n);
}

constexpr int nmax{4096};
BENCHMARK_TEMPLATE(bench_map, no_op_map<KeyType, KeyType>)
    ->RangeMultiplier(nmax)
    ->Range(1, nmax);
BENCHMARK_TEMPLATE(bench_map, cppbench::vec_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax);
BENCHMARK_TEMPLATE(bench_map, std::map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax);
BENCHMARK_TEMPLATE(bench_map, std::unordered_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax);
BENCHMARK_TEMPLATE(bench_map, cppbench::sorted_vec_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax);
