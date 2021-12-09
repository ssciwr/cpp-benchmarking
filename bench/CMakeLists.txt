add_executable(bench0 bench.cpp small_map_b0.cpp)
target_link_libraries(bench0 PUBLIC cppbench benchmark::benchmark)

add_executable(bench1 bench.cpp small_map_b1.cpp)
target_link_libraries(bench1 PUBLIC cppbench benchmark::benchmark)

add_executable(bench bench.cpp small_map_b.cpp)
target_link_libraries(bench PUBLIC cppbench benchmark::benchmark)
