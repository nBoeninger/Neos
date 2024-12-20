#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>

#define MutexHandler_t pthread_mutex_t
#define MutexParameter_t pthread_mutexattr_t

int MutexProxy_init(MutexHandler_t *mutex, MutexParameter_t* parameter);
int MutexProxy_lock(MutexHandler_t *mutex);
int MutexProxy_trylock(MutexHandler_t *mutex);
int MutexProxy_unlock(MutexHandler_t *mutex);

#ifdef __cplusplus
}
#endif