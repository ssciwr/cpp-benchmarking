#include "cppbench/sorted_vec_map.hpp"
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
  std::uniform_int_distribution<KeyType> dist(-123456, 123456);
  std::vector<KeyType> keys(100000);
  std::generate(keys.begin(), keys.end(),
                [&dist, &gen]() { return dist(gen); });
  std::map<KeyType, KeyType> std_map;
  TestType test_map;
  // check insert & find consistent with std::map
  for (auto key : keys) {
    auto val{dist(gen)};
    test_map.insert({key, val});
    std_map.insert({key, val});
    REQUIRE(test_map.size() == std_map.size());
    REQUIRE(test_map.find(key) == std_map.find(key)->second);
  }
  // check all keys again vs std::map
  for (auto key : keys) {
    REQUIRE(test_map.find(key) == std_map.find(key)->second);
  }
  // missing key returns default constructed value type
  REQUIRE(test_map.find(666666) == int{});
  REQUIRE(test_map.find(-666666) == int{});
}
