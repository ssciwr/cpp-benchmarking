#include "cpp-benchmarking/cpp-benchmarking.hpp"
#include <iostream>

int main(){
  int result = cppbenchmarking::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}