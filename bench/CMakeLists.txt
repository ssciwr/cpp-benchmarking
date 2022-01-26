add_executable(bench1 bench.cpp map_b1.cpp)
target_link_libraries(bench1 PUBLIC cppbench benchmark::benchmark)

add_executable(bench2 bench.cpp map_b2.cpp)
target_link_libraries(bench2 PUBLIC cppbench benchmark::benchmark)

add_executable(bench3 bench.cpp map_b3.cpp)
target_link_libraries(bench3 PUBLIC cppbench benchmark::benchmark)

add_executable(bench4 bench.cpp map_b4.cpp)
target_link_libraries(bench4 PUBLIC cppbench benchmark::benchmark)

add_executable(bench5 bench.cpp map_b5.cpp)
target_link_libraries(bench5 PUBLIC cppbench benchmark::benchmark)

add_executable(bench6 bench.cpp map_b6.cpp)
target_link_libraries(bench6 PUBLIC cppbench benchmark::benchmark)

add_executable(bench7 bench.cpp map_b7.cpp)
target_link_libraries(bench7 PUBLIC cppbench benchmark::benchmark)

if(CPPBENCH_WITH_ABSEIL)
  target_compile_definitions(bench5 PRIVATE CPPBENCH_WITH_ABSEIL)
  target_link_libraries(bench5 PRIVATE absl::flat_hash_map)
  target_compile_definitions(bench6 PRIVATE CPPBENCH_WITH_ABSEIL)
  target_link_libraries(bench6 PRIVATE absl::flat_hash_map)
  target_compile_definitions(bench7 PRIVATE CPPBENCH_WITH_ABSEIL)
  target_link_libraries(bench7 PRIVATE absl::flat_hash_map)
endif()
