//
// Created by Pugemon on 07.04.2025.
//

#include <psprtc.h>

namespace pugstd::chrono::internal
{

auto get_cpu_ticks() noexcept -> u64
{
  u64 current;
  sceRtcGetCurrentTick(&current);
  return current;
}

} // namespace pugstd::chrono::internal