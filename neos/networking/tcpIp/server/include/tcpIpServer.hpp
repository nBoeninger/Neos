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
    #define NBR_OF_BUFFERS 2

    class TcpIpServer : ITcpIp
    {
      // public signal
      public:
        Neos::Communication::Signal<TReceivedMessage> SMessageReceived;

      public:

        TcpIpServer() : ITcpIp() {};
        TcpIpServer(TTcpIpConfig serverConfig);

        ~TcpIpServer();

        bool Start();
        size_t Read(int socket);
        bool Send(const void* buffer, size_t size);

        void Run();

      private:
        uint8_t m_activeBuffer;
        uint8_t m_msgBuffer[NBR_OF_BUFFERS][MSG_BUFFER];
    };
  }
}