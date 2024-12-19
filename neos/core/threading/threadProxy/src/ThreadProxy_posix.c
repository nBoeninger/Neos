
#include "ThreadProxy_posix.h"

int ThreadProxy_create(TThreadHandler* threadHandle, void*(*TRunFunction)(void*), void* context, TThreadParameter* parameter)
{
  int ret = pthread_create(threadHandle, parameter, TRunFunction, context);
  return ret;
}

int ThreadProxy_setschedparam(int schedulingPolicy, int schedulingPriority, int stackSize, TThreadParameter* parameter)
{
  struct sched_param param;
  param.sched_priority = schedulingPriority;

  int ret = pthread_attr_init(parameter);
  ret = pthread_attr_setschedpolicy(parameter, schedulingPolicy);
  ret = pthread_attr_setstacksize(parameter, stackSize);
  ret = pthread_attr_setschedparam(parameter, &param);
  int t = 0;
 
}