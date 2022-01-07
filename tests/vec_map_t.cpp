#include "cppbench/vec_map.hpp"
#include <algorithm>
#include <catch2/catch.hpp>
#include <map>
#include <random>

using namespace cppbench;

using KeyType = int;

TEMPLATE_TEST_CASE("vec_map", "[map]", (cppbench::vec_map<KeyType, KeyType>),
                   (cppbench::sorted_vec_map<KeyType, KeyType>)) {
  std::mt19937 gen(12345);
  std::uniform_int_distribution<KeyType> dist(-4096, 4096);
  std::vector<KeyType> keys(10000);
  std::generate(keys.begin(), keys.end(),
                [&dist, &gen]() { return dist(gen); });

  TestType m1;
  std::map<KeyType, KeyType> m2;
  for (auto key : keys) {
    auto val{dist(gen)};
    m1.insert({key, val});
    m2.insert({key, val});
    REQUIRE(m1.size() == m2.size());
  }
  for (auto key : keys) {
    REQUIRE(m1.find(key) == m2.find(key)->second);
  }
}
