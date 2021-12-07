cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(
  cppbench
  VERSION 0.0.1
  LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compilation options

# compile the library
add_subdirectory(src)

# compile the application
add_subdirectory(app)

# compile the tests
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(ext/Catch2)
  include(./ext/Catch2/contrib/Catch.cmake)
  add_subdirectory(tests)
endif()

# compile the benchmarks
set(BENCHMARK_ENABLE_TESTING OFF)
add_subdirectory(ext/benchmark)
add_subdirectory(bench)

# Add an alias target for use if this project is included as a subproject in
# another project
add_library(cppbench::cppbench ALIAS cppbench)

# Install targets and configuration
install(
  TARGETS cppbench
  EXPORT cppbench-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  EXPORT cppbench-config
  NAMESPACE cppbench::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cppbench)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
