#include "bench.hpp"
#include "cppbench/vec_map.hpp"
#ifdef CPPBENCH_WITH_ABSEIL
#include <absl/container/flat_hash_map.h>
#endif
#include <benchmark/benchmark.h>
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
  // fill ~1gig of RAM with identical maps
  auto nmaps{1024 * 1024 * 32 / n};
  std::vector<Map> maps(nmaps);
  for (auto &map : maps) {
    for (auto key : keys) {
      map.insert({key, key});
    }
  }
  // distribution to pick a random index from the maps vector
  std::uniform_int_distribution<std::size_t> imap(0, nmaps - 1);
  // distribution to pick a random index from the keys vector
  std::uniform_int_distribution<std::size_t> idist(0, n - 1);
  for (auto _ : state) {
    // pick a random map at every iteration: simulates occasional "cold cache"
    // use rather than constant in-cache use of map
    auto &map{maps[imap(gen)]};
    // pick a random key at every iteration: expensive but cost independent of
    // map
    auto key{keys[idist(gen)]};
    benchmark::DoNotOptimize(map.find(key));
  }
  state.SetComplexityN(n);
}

constexpr int nmin{4};
constexpr int nmax{4096};
BENCHMARK_TEMPLATE(bench_map, cppbench::vec_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(nmin, nmax);
BENCHMARK_TEMPLATE(bench_map, std::map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(nmin, nmax);
BENCHMARK_TEMPLATE(bench_map, std::unordered_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(nmin, nmax);
BENCHMARK_TEMPLATE(bench_map, cppbench::sorted_vec_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(nmin, nmax);
#ifdef CPPBENCH_WITH_ABSEIL
BENCHMARK_TEMPLATE(bench_map, absl::flat_hash_map<KeyType, KeyType>)
    ->RangeMultiplier(2)
    ->Range(nmin, nmax);
#endif
