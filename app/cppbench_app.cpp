#include "cppbench/add_one.hpp"
#include <iostream>

int main() {
  int result = cppbench::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}
