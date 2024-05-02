#pragma once

#include "socketAdapter.hpp"
#include "TTcpIp.hpp"

namespace Neos
{
  namespace Networking
  {
    class ITcpIp
    {
      public:

        ITcpIp() {};
        ITcpIp(TTcpIpConfig config);
        ~ITcpIp(); 

        virtual bool Start() = 0; 
        virtual bool Send(const void* buffer, size_t size) = 0;
        virtual size_t Read(int socket) = 0;

      protected:
        SocketAdapter m_socketAdapter;
        TSockAddr_in m_tcpAddr;
    };
  }
}