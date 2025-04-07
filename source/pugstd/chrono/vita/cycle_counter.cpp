//
// Created by Pugemon on 07.04.2025.
//

#include <vitasdk.h>

namespace pugstd::chrono::internal
{

auto get_cpu_ticks() noexcept -> SceUInt64
{
  SceRtcTick current;
  sceRtcGetCurrentTick(&current);
  return current.tick;
}

} // namespace pugstd::chrono::internal