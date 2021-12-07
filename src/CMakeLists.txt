add_library(cpp-benchmarking cpp-benchmarking.cpp)
target_include_directories(
  cpp-benchmarking PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
                          $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
