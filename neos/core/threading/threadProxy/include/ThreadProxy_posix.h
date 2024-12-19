#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>
#include "stdint.h"

#define TThreadHandler pthread_t
#define TFunctionReturn void*
#define TThreadParameter pthread_attr_t

int ThreadProxy_create(TThreadHandler* threadHandle, void*(*TRunFunction)(void*), void* context, TThreadParameter* parameter);

int ThreadProxy_setschedparam(int schedulingPolicy, int schedulingPriority, int stackSize, TThreadParameter* parameter);

#ifdef __cplusplus
}
#endif
