//
// Created by Pugemon on 07.04.2025.
//

#include "pugstd/chrono/cycle_counter.hpp"
#include "cycle_counter.hpp"

namespace pugstd::chrono
{

cpu_clock::time_point cpu_clock::now() noexcept
{
  return time_point(duration(internal::get_cpu_ticks()));
}

} // namespace pugstd::chrono