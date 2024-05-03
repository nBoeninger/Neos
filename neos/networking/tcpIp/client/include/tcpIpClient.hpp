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
        TcpIpClient(TcpIpConfig_t clientConfig, uint8_t connectionRetries);
        TcpIpClient(TcpIpConfig_t clientConfig);

        ~TcpIpClient();

        bool Connect();
        size_t Read(int socketfd);
        bool Send(const void* buffer, size_t size);

      private:
        uint8_t m_connectionRetries;

     };

  }
}