#include "bench.hpp"
#include "cppbench/vec_map.hpp"
#include <random>

using KeyType = std::uint32_t;

static void bench_map(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(12345);
  auto keys{generate_keys<KeyType>(n, gen)};
  cppbench::vec_map<KeyType, KeyType> map;
  for (auto key : keys) {
    map.insert({key, key});
  }
  for (auto _ : state) {
    benchmark::DoNotOptimize(map.find(keys[0]));
  }
  state.SetComplexityN(n);
}

constexpr int nmax{1024};
BENCHMARK(bench_map)->RangeMultiplier(2)->Range(1, nmax)->Complexity();
