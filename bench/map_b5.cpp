#include "bench.hpp"
#include "cppbench/sorted_vec_map.hpp"
#include "cppbench/vec_map.hpp"
#ifdef CPPBENCH_WITH_ABSEIL
#include <absl/container/flat_hash_map.h>
#endif
#include <map>
#include <random>
#include <unordered_map>

using KeyType = std::uint32_t;

constexpr int nmax{4096};

template <typename Map> static void bench_map(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(12345);
  auto keys{generate_keys<KeyType>(n, gen)};
  Map map;
  for (auto key : keys) {
    map.insert({key, key});
  }
  for (auto _ : state) {
    // do the same number of map.find calls for all n
    for (int64_t i = 0; i < nmax; i += n) {
      for (auto key : keys) {
        benchmark::DoNotOptimize(map.find(key));
      }
    }
  }
  state.SetComplexityN(n * nmax);
}

BENCHMARK_TEMPLATE(bench_map, cppbench::vec_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax)
    ->Complexity();
BENCHMARK_TEMPLATE(bench_map, std::map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax)
    ->Complexity();
BENCHMARK_TEMPLATE(bench_map, std::unordered_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax)
    ->Complexity();
BENCHMARK_TEMPLATE(bench_map, cppbench::sorted_vec_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax)
    ->Complexity();
#ifdef CPPBENCH_WITH_ABSEIL
BENCHMARK_TEMPLATE(bench_map, absl::flat_hash_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(1, nmax)
    ->Complexity();
#endif
