#include <benchmark/benchmark.h>

void peak(benchmark::State &state)
{
  volatile float x = 1;
  for (auto _ : state) {
    x = x * 3 + 1;
  }

  // compute FLOP/s and FLOP/cycle
  constexpr double flop_per_iteration = 2;
  state.counters["FLOP"] = {flop_per_iteration,
                            benchmark::Counter::kIsIterationInvariantRate};
  if (state.counters.contains("CYCLES")) {
    state.counters["FLOP/cycle"] = {flop_per_iteration / state.counters["CYCLES"],
                                    benchmark::Counter::kIsIterationInvariant};
  }
}

// Register the function as a benchmark
BENCHMARK(peak);

// Run the benchmark
BENCHMARK_MAIN();
