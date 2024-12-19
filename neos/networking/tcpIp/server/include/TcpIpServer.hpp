#pragma once

#include "TTcpIp.hpp"
#include "ITcpIp.hpp"
#include "SocketAdapter.hpp"
#include "Signals.hpp"
#include "stdint.h"

namespace Neos
{
  namespace Networking
  {

   class TcpIpServer :  public ITcpIp
    {
      public:

        TcpIpServer() : ITcpIp() {};
        TcpIpServer(TcpIpConfig_t serverConfig);

        ~TcpIpServer();

        bool Start();
        int WaitForConnections();
    };
  }
}