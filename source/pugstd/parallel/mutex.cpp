//
// Created by Pugemon on 18.03.2025.
//

#include "mutex.hpp"

#include <pugstd/parallel/mutex.hpp>

namespace pugstd
{

mutex::mutex() noexcept
    : m_mutex(internal::mutex_init())
{
}

mutex::~mutex() noexcept
{
  internal::mutex_free(m_mutex);
}

void mutex::lock()
{
  internal::mutex_lock(m_mutex);
}

bool mutex::try_lock()
{
  return internal::mutex_try_lock(m_mutex);
}

void mutex::unlock() noexcept
{
  internal::mutex_unlock(m_mutex);
}

recursive_mutex::recursive_mutex() noexcept
    : m_rmutex(internal::recursive_mutex_init())
{
}

recursive_mutex::~recursive_mutex()
{
  internal::recursive_mutex_free(m_rmutex);
}

void recursive_mutex::lock()
{
  internal::recursive_mutex_lock(m_rmutex);
}

bool recursive_mutex::try_lock()
{
  return internal::recursive_mutex_try_lock(m_rmutex);
}

void recursive_mutex::unlock() noexcept
{
  internal::recursive_mutex_unlock(m_rmutex);
}

}  // namespace pugstd