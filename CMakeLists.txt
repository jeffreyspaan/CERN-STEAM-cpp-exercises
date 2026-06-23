cmake_minimum_required(VERSION 3.30)
project(Exercises)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE STRING "" FORCE)

message("flags ${CMAKE_CXX_FLAGS_RELEASE}")

find_package(benchmark 1.9 QUIET)
if (NOT benchmark_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark
    GIT_TAG main)
  option(BENCHMARK_ENABLE_TESTING "" OFF)
  option(BENCHMARK_ENABLE_GTEST_TESTS "" OFF)
  option(BENCHMARK_ENABLE_LIBPFM "" ON) # for performance counters
  FetchContent_MakeAvailable(benchmark)
endif()

add_executable(test test/test.cpp)
target_link_libraries(test PRIVATE benchmark::benchmark)

add_subdirectory(histograms)
