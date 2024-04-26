#pragma once

#include "socketsWrapper.hpp"

namespace Neos
{
  namespace Communication
  {

    class TcpIpServer
    {
      public:
        TcpIpServer();
        ~TcpIpServer();
      private:
        SocketsWrapper m_socket;
    };
  }
}