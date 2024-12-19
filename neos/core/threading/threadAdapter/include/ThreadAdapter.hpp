#pragma once

#if TARGET == LINUX
  #include "ThreadProxy_posix.h"

#endif

namespace Neos
{

  typedef struct TThreadAttributes
  {
    int schedulingPriority;
    int schedulingPolicy;
    int stackSize;
  }TThreadAttributes;

  class ThreadAdapter
  {
    public:

      ThreadAdapter(TThreadAttributes attributes, const char * threadName);
      ~ThreadAdapter();

      void Initialize();
      void Run();
      void Start();
      void Stop();
      void Kill();

      static TFunctionReturn RunFunction(void* context);

    private:

      const char* m_threadName;
      TThreadAttributes m_attributes;
      TThreadParameter m_parameter;
      TThreadHandler m_threadHandler;
  };

}
