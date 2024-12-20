#pragma once

#if TARGET == LINUX
  #include "ThreadProxy_posix.h"
#endif

#include "Logging.hpp"

namespace Neos
{

  typedef struct ThreadAttributes_t
  {
    int schedulingPriority;
    int schedulingPolicy;
    int stackSize;
  }ThreadAttributes_t;

  class ThreadAdapter
  {
    public:

      ThreadAdapter(ThreadAttributes_t attributes, const char* threadName, Logging* logger);
      ThreadAdapter(ThreadAttributes_t attributes, const char * threadName);
      ~ThreadAdapter();

      void Initialize();
      void Run();
      void Start();
      void Stop();
      void Kill();

      static FunctionReturn_t RunFunction(void* context);

    protected:
      void LogInfo(std::string message);
      void LogError(std::string message);

    private:

      void CreateThreadParameter();

      const char* m_threadName;
      ThreadAttributes_t m_attributes;
      ThreadParameter_t m_parameter;
      ThreadHandler_t m_threadHandler;
      Logging* m_logger;
  };

}
