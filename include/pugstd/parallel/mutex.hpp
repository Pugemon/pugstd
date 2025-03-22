//
// Created by Pugemon on 17.03.2025.
//
#pragma once

#include <mutex>

#include "pugstd/pugstd_export.hpp"
namespace pugstd
{

/**
 * @brief Мьютекс обеспечивает защиту от состояний гонки данных и позволяет
 * осуществлять потокобезопасную синхронизацию данных между потоками.
 * @see Раздел 30.4.1 стандарта C++11 (ранее C++0x)
 **/
PUGSTD_EXPORT class mutex
{
public:

  mutex() noexcept;
  ~mutex() noexcept;

  mutex(const mutex&)            = delete;
  mutex& operator=(const mutex&) = delete;


  void lock();
  bool try_lock();
  void unlock() noexcept;

private:
  void*  m_mutex;
};

/**
 * @brief Рекурсивный мьютекс реализует механизм блокировок с поддержкой рекурсии и семантикой исключительного владения.
 **/
PUGSTD_EXPORT class recursive_mutex
{
public:

  recursive_mutex() noexcept;
  ~recursive_mutex() noexcept;

  recursive_mutex(const recursive_mutex&)            = delete;
  recursive_mutex& operator=(const recursive_mutex&) = delete;


  void lock();
  bool try_lock();
  void unlock() noexcept;

private:
  void*  m_rmutex;
};

} // namespace pugstd
