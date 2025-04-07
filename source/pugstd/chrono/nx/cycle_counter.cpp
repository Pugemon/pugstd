//
// Created by Pugemon on 07.04.2025.
//

#include <switch/arm/counter.h>

#include "../cycle_counter.hpp"

namespace pugstd::chrono::internal
{

auto get_cpu_ticks() noexcept -> u64
{
  /**
   * @brief
   * Nintendo Switch CPU ticks has a fixed rate at 19200000
   * It is basically 52 ns per tick
   * The formula 625 / 12 is equivalent to 1e9 / 19200000
   * @see armTicksToNs() converts cpu ticks to nanoseconds
   **/
  armTicksToNs(armGetSystemTick());
}

} // namespace pugstd::chrono::internal