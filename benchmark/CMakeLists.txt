function(add_benchmark name)
  add_executable(${name} ${ARGN})
  target_link_libraries(${name} PRIVATE benchmark::benchmark)
  add_custom_target(run_${name}
    COMMAND $<TARGET_FILE:${name}> --benchmark_counters_tabular=true --benchmark_perf_counters=CYCLES,INSTRUCTIONS
    COMMENT "benchmarking ${name}")
endfunction()

add_benchmark(peakflop peak_flop.cpp)
