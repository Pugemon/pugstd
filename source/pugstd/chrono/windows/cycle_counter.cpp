//
// Created by Pugemon on 07.04.2025.
//

#include "../cycle_counter.hpp"

#include <chrono>

namespace pugstd::chrono::internal
{

auto get_cpu_ticks() noexcept -> uint64_t
{
  using namespace std::chrono;
  return duration_cast<nanoseconds>(
      high_resolution_clock::now().time_since_epoch()).count();
}

} // namespace pugstd::chrono::internal