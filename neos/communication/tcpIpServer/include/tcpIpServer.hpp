#pragma once

#include "socketProxy.hpp"
#include "stdint.h"

#include "sysDefines.hpp"
#include "eConfigs.hpp"

#if TARGET == LINUX
  #include <arpa/inet.h>
#elif TARGET == ESP32
  //....
#endif

namespace Neos
{
  namespace Communication
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
        SocketProxy m_socket;
        TTcpIpServerConfig m_serverConfig;
        struct sockaddr_in m_hostAddr;
    };
  }
}