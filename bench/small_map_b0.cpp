#include "bench.hpp"
#include "cppbench/small_map.hpp"
#include <limits>
#include <map>
#include <random>
#include <unordered_map>

using KeyType = std::uint32_t;

static void bench_small_map(benchmark::State &state) {
  auto n{state.range(0)};
  std::mt19937 gen(12345);
  auto keys{generate_keys<KeyType>(n, gen)};
  cppbench::small_map<KeyType, KeyType> map;
  for (auto key : keys) {
    map.insert({key, key});
  }
  for (auto _ : state) {
    // 0. compiler optimizes away this entire statement, zero runtime:
    // map.find(keys[0])

    // 1. force compiler to put result of statement into a register/memory
    // now get non-zero time, but no N-dependence. Why? We're always asking for
    // the first key in the vector! benchmark::DoNotOptimize(map.find(keys[0]));

    // 2. ask for a key roughly in the middle of the vector as a more
    // representative case now get a more realistic linear dependence on N
    benchmark::DoNotOptimize(map.find(keys[n / 2 + 1]));

    // 3. ask for all keys to get average benchmark over all possible keys
    // note: we are now doing N finds per iteration, so also need to multiply
    // complexity by N consistent results with just looking up the middle key,
    // which makes sense for(auto key : keys){
    //    benchmark::DoNotOptimize(map.find(key));
    // }
  }
  state.SetComplexityN(n);
}

constexpr int nmax{1024};
BENCHMARK(bench_small_map)->RangeMultiplier(2)->Range(1, nmax)->Complexity();
