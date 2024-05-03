#pragma once

#include "TTcpIp.hpp"
#include "ITcpIp.hpp"
#include "socketAdapter.hpp"
#include "stdint.h"
#include "signals.hpp"

namespace Neos
{
  namespace Networking
  {

    #define MSG_BUFFER 1024

    class TcpIpServer :  public ITcpIp
    {
      public:

        TcpIpServer() : ITcpIp() {};
        TcpIpServer(TcpIpConfig_t serverConfig);

        ~TcpIpServer();

        bool Start();
        int WaitForConnections();
        size_t Read(int socketfd);
        bool Send(const void* buffer, size_t size);

      private:
        uint8_t m_msgBuffer[MSG_BUFFER];

    };
  }
}