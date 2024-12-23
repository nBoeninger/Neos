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

  class Thread
  {
    public:

      Thread(ThreadAttributes_t attributes, const char* threadName, Logging* logger);
      Thread(ThreadAttributes_t attributes, const char * threadName);
      ~Thread();

      void Initialize();
      void Run();
      void Start();
      void Stop();
      void Kill();

      static FunctionReturn_t RunFunction(void* context);

    protected:

      template<typename... Args>
      void LogInfo(const char* message, Args&& ...args);
      
      template<typename... Args>
      void LogError(const char* message, Args&& ...args);

    private:

      void CreateThreadParameter();

      const char* m_threadName;
      ThreadAttributes_t m_attributes;
      ThreadParameter_t m_parameter;
      ThreadHandler_t m_threadHandler;
      Logging* m_logger;
  };

  template<typename... Args>
  void Thread::LogInfo(const char* message, Args&& ...args)
  {
    if(m_logger != nullptr)
    {
      m_logger -> Info(m_threadName, message, args...);
    }
  }

  template<typename... Args>
  void Thread::LogError(const char* message, Args&& ...args)
  {
    int t = 0;
    if(m_logger != nullptr)
    {
      m_logger -> Error(m_threadName, message, args...);
    }
  }
}
