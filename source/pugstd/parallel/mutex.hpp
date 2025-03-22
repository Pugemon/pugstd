//
// Created by Pugemon on 18.03.2025.
//

#pragma once

#include "pugstd/parallel/mutex.hpp"

namespace pugstd::internal
{

void* mutex_init();

void* recursive_mutex_init();

void mutex_free(void* obj);

void recursive_mutex_free(void* obj);

void mutex_lock(void* obj);

void recursive_mutex_lock(void* obj);

bool mutex_try_lock(void* obj);

bool recursive_mutex_try_lock(void* obj);

void mutex_unlock(void* obj);

void recursive_mutex_unlock(void* obj);

}  // namespace pugstd::internal
