#include "pugstd/pugstd.hpp"

pugstd::pugstd()
    : m_name {"pugstd"}
{
}

auto pugstd::name() const -> char const*
{
  return m_name.c_str();
}

