add_executable(bench bench.cpp add_one_b.cpp)
target_link_libraries(bench PUBLIC cppbench benchmark::benchmark)
