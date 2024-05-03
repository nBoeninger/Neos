#pragma once

#include "socketAdapter.hpp"
#include "TTcpIp.hpp"
#include "signals.hpp"

namespace Neos
{
  namespace Networking
  {
    class ITcpIp
    {
      public:
        Neos::Communication::Signal<ReceivedMessage_t> SMessageReceived;
        Neos::Communication::Signal<SendedMessage_t> SMessageSended;

      public:

        ITcpIp() {};
        ITcpIp(TcpIpConfig_t config);
        ~ITcpIp(); 

        virtual bool Send(const void* buffer, size_t size) = 0;
        virtual size_t Read(int socketfd) = 0;

      protected:
        SocketAdapter m_socketAdapter;
        TSockAddr_in m_tcpAddr;
    };
  }
}