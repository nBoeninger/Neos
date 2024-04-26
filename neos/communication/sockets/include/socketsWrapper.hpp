
#include "eConfigs.hpp"
#include "sysDefines.hpp"

#if TARGET == LINUX
#include "sys/socket.h"
#include <unistd.h>
#elif TARGET == ESP32
// TODO FIll in libs
#endif


namespace Neos
{
 namespace Communication
 {
  class SocketsWrapper
  {
    public:
      SocketsWrapper(int domain, int type, int protocol);
      ~SocketsWrapper();
    private:
      int m_domain;
      int m_type;
      int m_protocol;
      int m_socket;
  };
 }
}
