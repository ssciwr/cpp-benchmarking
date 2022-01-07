#include "bench.hpp"
#include "cppbench/vec_map.hpp"
#include <map>
#include <random>
#include <unordered_map>

using KeyType = std::uint32_t;

template <typename Map> static void bench_map(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(12345);
  auto keys{generate_keys<KeyType>(n, gen)};
  Map map;
  for (auto key : keys) {
    map.insert({key, key});
  }
  // here we were accidentally improving the cache friendliness of the std::map
  // by asking for keys in the same order that they were inserted into the map,
  // can make this a bit more realistic by shuffling them before we start
  std::shuffle(keys.begin(), keys.end(), gen);

  for (auto _ : state) {
    for (auto key : keys) {
      benchmark::DoNotOptimize(map.find(key));
    }
  }
  state.SetComplexityN(n * n);
}

constexpr int nmax{1024};
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
