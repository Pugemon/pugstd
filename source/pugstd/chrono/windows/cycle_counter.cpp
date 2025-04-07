//
// Created by Pugemon on 07.04.2025.
//

#include "../cycle_counter.hpp"
#include <windows.h>

namespace pugstd::chrono::internal
{

auto get_cpu_ticks() noexcept -> uint64_t
{
  LARGE_INTEGER freq;
  LARGE_INTEGER count;
  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&count);
  return static_cast<uint64_t>(count.QuadPart / freq.QuadPart);
}

} // namespace pugstd::chrono::internal