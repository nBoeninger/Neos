
#include "ThreadProxy_posix.h"

int ThreadProxy_create(ThreadHandler_t* threadHandle, void*(*TRunFunction)(void*), void* context, ThreadParameter_t* parameter)
{
  return pthread_create(threadHandle, parameter, TRunFunction, context);
}

int ThreadProxy_initParameter(ThreadParameter_t* parameter)
{
  return pthread_attr_init(parameter);
}

int ThreadProxy_setSchedPriority(int schedulingPriority, ThreadParameter_t* parameter)
{
  struct sched_param param;
  param.sched_priority = schedulingPriority;
  return pthread_attr_setschedparam(parameter, &param);
}

int ThreadProxy_setSchedPolicy(int schedulingPolicy, ThreadParameter_t* parameter)
{
  return pthread_attr_setschedpolicy(parameter, schedulingPolicy);
}

int ThreadProxy_setStackSize(int stackSize, ThreadParameter_t* parameter)
{
  return pthread_attr_setstacksize(parameter, stackSize);
}
