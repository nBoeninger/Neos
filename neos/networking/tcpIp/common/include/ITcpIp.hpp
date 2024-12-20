#pragma once

#include "SocketAdapter.hpp"
#include "TTcpIp.hpp"
#include "Signals.hpp"

namespace Neos
{
  namespace Networking
  {
    class ITcpIp
    {

      #define MSG_BUFFER 1024
    
      public:
        Neos::Communication::Signal<ReceivedMessage_t> SMessageReceived;
        Neos::Communication::Signal<SendedMessage_t> SMessageSended;

      public:

        ITcpIp() {};
        ITcpIp(TcpIpConfig_t config);
        ~ITcpIp(); 

        bool Send(const void* buffer, size_t size);
        size_t Read(int socketfd);

      protected:
        SocketAdapter m_socketAdapter;
        SockAddr_t m_tcpAddr;

        uint8_t m_msgBuffer[MSG_BUFFER];
    };
  }
}