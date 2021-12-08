#pragma once

#include <algorithm>
#include <vector>

namespace cppbench {

template <typename Key, typename Value> class small_map {
private:
  std::vector<Key> keys;
  std::vector<Value> vals;

public:
  void insert(const std::pair<Key, Value> &p) {
    for (std::size_t i = 0; i < keys.size(); ++i) {
      if (keys[i] == p.first) {
        return;
      }
    }
    keys.push_back(p.first);
    vals.push_back(p.second);
  }

  Value find(Key k) const {
    for (std::size_t i = 0; i < keys.size(); ++i) {
      if (keys[i] == k) {
        return vals[i];
      }
    }
    return {};
  }

  std::size_t size() const { return keys.size(); }
};

} // namespace cppbench
