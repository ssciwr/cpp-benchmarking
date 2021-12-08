#include "cppbench/small_map.hpp"
#include <algorithm>
#include <catch2/catch.hpp>
#include <map>
#include <random>

using namespace cppbench;

TEST_CASE("SmallMap", "[map]") {
  std::mt19937 gen(12345);
  std::uniform_int_distribution<> dist(-4096, 4096);
  std::vector<int> keys(10000);
  std::generate(keys.begin(), keys.end(),
                [&dist, &gen]() { return dist(gen); });

  cppbench::small_map<int, int> m1;
  std::map<int, int> m2;
  for (auto key : keys) {
    auto val{dist(gen)};
    m1.insert({key, val});
    m2.insert({key, val});
    REQUIRE(m1.size() == m2.size());
  }
  for (auto key : keys) {
    CAPTURE(m1.find(key));
    CAPTURE(m2.find(key)->second);
    REQUIRE(m1.find(key) == m2.find(key)->second);
  }
}
