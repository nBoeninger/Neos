#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>
#include "stdint.h"

#define ThreadHandler_t pthread_t
#define FunctionReturn_t void*
#define ThreadParameter_t pthread_attr_t

int ThreadProxy_create(ThreadHandler_t* threadHandle, void*(*TRunFunction)(void*), void* context, ThreadParameter_t* parameter);

int ThreadProxy_initParameter(ThreadParameter_t* parameter);
int ThreadProxy_setSchedPriority(int schedulingPriority, ThreadParameter_t* parameter);
int ThreadProxy_setSchedPolicy(int schedulingPolicy, ThreadParameter_t* parameter);
int ThreadProxy_setStackSize(int stackSize, ThreadParameter_t* parameter);

#ifdef __cplusplus
}
#endif
