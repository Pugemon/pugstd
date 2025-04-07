//
// Created by Pugemon on 07.04.2025.
//

#pragma once

#include <chrono>
#include <ratio>

#include "pugstd/pugstd_export.hpp"
namespace pugstd::chrono
{

PUGSTD_EXPORT struct cpu_clock
{
  using rep = uint64_t;
  using period = std::nano;
  using duration = std::chrono::duration<rep, period>;
  using time_point = std::chrono::time_point<cpu_clock>;

  static constexpr bool is_steady = true;

  static time_point now() noexcept;
};

} // namespace pugstd::crono
