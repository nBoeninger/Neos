#pragma once

#if TARGET == LINUX
  #include "MutexProxy_posix.h"
#endif

namespace Neos
{

  typedef struct MutexAttribute_t
  {
    int protocol;
    int pshared;
    int prioceiling;
    int type;

  }MutexAttribute_t;

  class Mutex
  {
    public:
      Mutex();
      ~Mutex();

    private:
      MutexHandler_t m_handler;
  };
}