#include <string>

#include "pugstd/pugstd.hpp"

auto main() -> int
{
  auto const exported = pugstd {};

  return std::string("pugstd") == exported.name() ? 0 : 1;
}
