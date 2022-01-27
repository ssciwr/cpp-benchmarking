#pragma once

#include <algorithm>
#include <vector>

namespace cppbench {

// Simple map using a sorted vector, O(log(N)) look-up
template <typename Key, typename Value> class sorted_vec_map {
private:
  std::vector<Key> keys;
  std::vector<Value> vals;

public:
  void insert(const std::pair<Key, Value> &p) {
    auto it{std::lower_bound(keys.begin(), keys.end(), p.first)};
    if (it != keys.end() && *it == p.first) {
      // insert is a no-op if key already exists
      return;
    }
    vals.insert(vals.begin() + std::distance(keys.begin(), it), p.second);
    keys.insert(it, p.first);
  }

  Value find(Key k) const {
    auto res{std::lower_bound(keys.cbegin(), keys.cend(), k)};
    if (res != keys.cend() && *res == k) {
      return vals[std::distance(keys.cbegin(), res)];
    }
    return {};
  }

  [[nodiscard]] std::size_t size() const { return keys.size(); }
};

} // namespace cppbench
