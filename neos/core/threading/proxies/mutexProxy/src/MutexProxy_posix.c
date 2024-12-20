#include "MutexProxy_posix.h"

int MutexProxy_init(MutexHandler_t* mutex, MutexParameter_t* parameter)
{
  return pthread_mutex_init(mutex, parameter);
}

int MutexProxy_lock(MutexHandler_t *mutex)
{
  return pthread_mutex_lock(mutex);
}

int MutexProxy_trylock(MutexHandler_t *mutex)
{
  return pthread_mutex_trylock(mutex);
}

int MutexProxy_unlock(MutexHandler_t *mutex)
{
  return pthread_mutex_unlock(mutex);
}

