//
// Created by Pugemon on 18.03.2025.
//

#include <psp2/kernel/threadmgr/mutex.h>
#include "../mutex.hpp"

#define OBJ_TO_SCEUID(obj) static_cast<SceUID*>(obj)

namespace pugstd::internal
{

void* mutex_init()
{
  SceUID mutex = sceKernelCreateMutex(nullptr, 0, 0, nullptr);
  SceUID* obj = new SceUID();
  *obj = mutex;
  return obj;
}

void mutex_free(void* obj)
{
  SceUID* sceUidObj = OBJ_TO_SCEUID(obj);
  sceKernelDeleteMutex(sceUidObj);
  delete sceUidObj;
}

void mutex_lock(void* obj)
{
  sceKernelLockMutex(OBJ_TO_SCEUID(obj), 1, nullptr);
}

void mutex_unlock(void* obj)
{
  sceKernelUnlockMutex(OBJ_TO_SCEUID(obj), 1);
}

void* recursive_mutex_init()
{
  SceUID mutex = sceKernelCreateMutex(nullptr, SCE_KERNEL_MUTEX_ATTR_RECURSIVE, 0, nullptr);
  SceUID* obj = new SceUID();
  *obj = mutex;
  return obj;
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

} // namespace pugstd::internal