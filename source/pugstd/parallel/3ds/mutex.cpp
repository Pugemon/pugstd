//
// Created by Pugemon on 18.03.2025.
//

#include <3ds/synchronization.h>
#include "../mutex.hpp"

#define OBJ_TO_LIGHTLOCK(obj) static_cast<LightLock*>(obj)
#define OBJ_TO_RECURSIVELOCK(obj) static_cast<RecursiveLock*>(obj)

namespace pugstd::internal
{

void* mutex_init()
{
  LightLock* lock = new LightLock();
  LightLock_Init(lock);
  return lock;
}

void mutex_free(void* obj)
{
  delete OBJ_TO_LIGHTLOCK(obj);
}

void mutex_lock(void* obj)
{
  LightLock_Lock(OBJ_TO_LIGHTLOCK(obj));
}

bool mutex_try_lock(void* obj)
{
  return LightLock_TryLock(OBJ_TO_LIGHTLOCK(obj)) == 0;
}

void mutex_unlock(void* obj)
{
  LightLock_Unlock(OBJ_TO_LIGHTLOCK(obj));
}

void* recursive_mutex_init()
{
  RecursiveLock* lock = new RecursiveLock();
  RecursiveLock_Init(lock);
  return lock;
}

void recursive_mutex_free(void* obj)
{
  delete OBJ_TO_RECURSIVELOCK(obj);
}

void recursive_mutex_lock(void* obj)
{
  RecursiveLock_Lock(OBJ_TO_RECURSIVELOCK(obj));
}

bool recursive_mutex_try_lock(void* obj)
{
  return RecursiveLock_TryLock(OBJ_TO_RECURSIVELOCK(obj));
}

void recursive_mutex_unlock(void* obj)
{
  RecursiveLock_Unlock(OBJ_TO_RECURSIVELOCK(obj));
}

} // namespace pugstd::internal