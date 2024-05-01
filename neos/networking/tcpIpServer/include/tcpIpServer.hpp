#pragma once

#include "socketAdapter.hpp"
#include "stdint.h"

namespace Neos
{
  namespace Networking
  {

    typedef struct TTcpIpServerConfig
    {
      union IpAddress
      {
        uint8_t adressBytes[4];
        uint32_t addressValue;
      } IpAddress;
      uint16_t port;
    } TTcpIpServerConfig;

    class TcpIpServer
    {
      public:

        TcpIpServer(){};
        TcpIpServer(TTcpIpServerConfig serverConfig);

        ~TcpIpServer();

        void StartServer();
        void RunServer();

      private:
        SocketAdapter m_socketAdapter;
        TTcpIpServerConfig m_serverConfig;
        TSockAddr_in m_hostAddr;
    };
  }
}