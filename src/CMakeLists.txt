add_library(cppbench vec_map.cpp)
target_include_directories(
  cppbench PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
                  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
