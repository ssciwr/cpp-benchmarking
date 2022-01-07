#pragma once

#include <algorithm>
#include <vector>

namespace cppbench {

// Map using an unsorted vector, O(N) look-up
template <typename Key, typename Value> class vec_map {
private:
  std::vector<Key> keys;
  std::vector<Value> values;

public:
  void insert(const std::pair<Key, Value> &p) {
    if (std::find(keys.cbegin(), keys.cend(), p.first) != keys.cend()) {
      // insert is a no-op if key already exists
      return;
    }
    keys.push_back(p.first);
    values.push_back(p.second);
  }

  Value find(Key k) const {
    for (std::size_t i = 0; i < keys.size(); ++i) {
      if (keys[i] == k) {
        return values[i];
      }
    }
    return {};
  }

  [[nodiscard]] std::size_t size() const { return keys.size(); }
};

// Map using a sorted vector, O(log(N)) look-up
template <typename Key, typename Value> class sorted_vec_map {
private:
  std::vector<Key> keys;
  std::vector<Value> vals;

public:
  void insert(const std::pair<Key, Value> &p) {
    auto it{std::lower_bound(keys.begin(), keys.end(), p.first)};
    if(it != keys.end() && *it == p.first){
      // insert is a no-op if key already exists
      return;
    }
    vals.insert(vals.begin() + std::distance(keys.begin(), it), p.second);
    keys.insert(it, p.first);
  }

  Value find(Key k) const {
    auto res{std::lower_bound(keys.cbegin(), keys.cend(), k)};
    if (res != keys.cend() && *res == k){
      return vals[std::distance(keys.cbegin(), res)];
    }
    return {};
  }

  [[nodiscard]] std::size_t size() const { return keys.size(); }
};

} // namespace cppbench
