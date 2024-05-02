#pragma once

#include "ITcpIp.hpp"
#include "TTcpIp.hpp"
#include "socketAdapter.hpp"
#include "stdint.h"

namespace Neos
{
  namespace Networking
  {

    /**
     * @brief The Tcp Client Module
    */

    #define CONNECTION_RETRIES 5

    class TcpIpClient : ITcpIp
    {
      public:
        TcpIpClient() : ITcpIp() {};
        TcpIpClient(TTcpIpConfig clientConfig, uint8_t connectionRetries);
        TcpIpClient(TTcpIpConfig clientConfig);

        ~TcpIpClient();

        bool Start();
        size_t Read(int socket);
        bool Send(const void* buffer, size_t size);

      private:
        uint8_t m_connectionRetries;

     };

  }
}