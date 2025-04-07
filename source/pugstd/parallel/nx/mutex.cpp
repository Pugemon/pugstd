//
// Created by Pugemon on 18.03.2025.
//

#include <switch/kernel/mutex.h>
#include "../mutex.hpp"

#define OBJ_TO_MUTEX(obj) static_cast<Mutex*>(obj)
#define OBJ_TO_RMUTEX(obj)   static_cast<RMutex*>(obj)


namespace pugstd::internal
{

void* mutex_init()
{
  Mutex* mutex = new Mutex{};
  mutexInit(mutex);
  return mutex;
}

void mutex_free(void* obj)
{
  mutex_unlock(obj);
  delete OBJ_TO_MUTEX(obj);
}

void mutex_lock(void* obj)
{
  mutexLock(OBJ_TO_MUTEX(obj));
}

bool mutex_try_lock(void* obj)
{
  mutexTryLock(OBJ_TO_MUTEX(obj)) == 0;
}

void mutex_unlock(void* obj)
{
  mutexUnlock(OBJ_TO_MUTEX(obj));
}

void* recursive_mutex_init()
{
  RMutex* rmutex = new RMutex{};
  rmutexInit(rmutex);
  return rmutex;
}

void recursive_mutex_free(void* obj)
{
  recursive_mutex_unlock(obj);
  delete OBJ_TO_RMUTEX(obj);
}

void recursive_mutex_lock(void* obj)
{
  rmutexLock(OBJ_TO_RMUTEX(obj));
}

bool recursive_mutex_try_lock(void* obj)
{
  return rmutexTryLock(OBJ_TO_RMUTEX(obj)) == 0;
}

void recursive_mutex_unlock(void* obj)
{
  rmutexUnlock(OBJ_TO_RMUTEX(obj));
}

} // namespace pugstd::internal