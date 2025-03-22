//
// Created by Pugemon on 18.03.2025.
//

#include <windows.h>
#include "../mutex.hpp"

#define OBJ_TO_CS(obj) static_cast<CRITICAL_SECTION*>(obj)

namespace pugstd::internal
{

void* mutex_init()
{
  auto* CS = new CRITICAL_SECTION();
  InitializeCriticalSection(CS);
  return CS;
}

void mutex_free(void* obj)
{
  auto* cs = OBJ_TO_CS(obj);
  DeleteCriticalSection(cs);
  delete cs;
}

void mutex_lock(void* obj)
{
  EnterCriticalSection(OBJ_TO_CS(obj));
}

bool mutex_try_lock(void* obj)
{
  return TryEnterCriticalSection(OBJ_TO_CS(obj));
}

void mutex_unlock(void* obj)
{
  LeaveCriticalSection(OBJ_TO_CS(obj));
}

void* recursive_mutex_init()
{
  return mutex_init();
}

void recursive_mutex_free(void* obj)
{
  mutex_free(obj);
}

void recursive_mutex_lock(void* obj)
{
  mutex_lock(obj);
}

bool recursive_mutex_try_lock(void* obj)
{
  return mutex_try_lock(obj);
}

void recursive_mutex_unlock(void* obj)
{
  mutex_unlock(obj);
}

}  // namespace pugstd::internal