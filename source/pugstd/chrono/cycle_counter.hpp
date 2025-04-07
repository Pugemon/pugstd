//
// Created by Pugemon on 07.04.2025.
//

#pragma once
#include <cstdint>
namespace pugstd::chrono::internal
{

auto get_cpu_ticks() noexcept -> uint64_t;

} // namespace pugstd::chrono::internal
