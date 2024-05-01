#pragma once

#include "TTcpIp.hpp"
#include "ITcpIP.hpp"
#include "socketAdapter.hpp"
#include "stdint.h"

namespace Neos
{
  namespace Networking
  {
    class TcpIpServer : ITcpIp
    {
      public:

        TcpIpServer() : ITcpIp() {};
        TcpIpServer(TTcpIpConfig serverConfig);

        ~TcpIpServer();

        bool Start();
        void RunServer();
    };
  }
}