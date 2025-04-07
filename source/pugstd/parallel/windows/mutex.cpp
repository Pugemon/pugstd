//
// Created by Pugemon on 18.03.2025.
//

#include "../mutex.hpp"
#include <windows.h>

namespace pugstd::internal
{

void* mutex_init()
{
  std::mutex* p_mutex = new std::mutex;
  return p_mutex;
}

void mutex_free(void* obj)
{
  auto* p_mutex = static_cast<std::mutex*>(obj);
  p_mutex->unlock();
  delete p_mutex;
}

void mutex_lock(void* obj)
{
  static_cast<std::mutex*>(obj)->lock();
}

bool mutex_try_lock(void* obj)
{
  return static_cast<std::mutex*>(obj)->try_lock();
}

void mutex_unlock(void* obj)
{
  static_cast<std::mutex*>(obj)->unlock();
}

void* recursive_mutex_init()
{
  return new std::recursive_mutex;
}

void recursive_mutex_free(void* obj)
{
  auto* p_rmutex = static_cast<std::recursive_mutex*>(obj);
  p_rmutex->unlock();
  delete p_rmutex;
}

void recursive_mutex_lock(void* obj)
{
  static_cast<std::recursive_mutex*>(obj)->lock();
}

bool recursive_mutex_try_lock(void* obj)
{
  return static_cast<std::recursive_mutex*>(obj)->try_lock();
}

void recursive_mutex_unlock(void* obj)
{
  static_cast<std::recursive_mutex*>(obj)->unlock();
}

}  // namespace pugstd::internal