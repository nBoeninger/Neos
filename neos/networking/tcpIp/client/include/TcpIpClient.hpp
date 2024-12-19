#pragma once

#include "ITcpIp.hpp"
#include "TTcpIp.hpp"
#include "SocketAdapter.hpp"
#include "stdint.h"

namespace Neos
{
  namespace Networking
  {

    /**
     * @brief The Tcp Client Module
    */

    #define CONNECTION_RETRIES 5

    class TcpIpClient : public ITcpIp
    {
      public:
        TcpIpClient() : ITcpIp() {};
        TcpIpClient(TcpIpConfig_t clientConfig, uint8_t connectionRetries);
        TcpIpClient(TcpIpConfig_t clientConfig);

        ~TcpIpClient();

        bool Connect();

      private:
        uint8_t m_connectionRetries;

     };

  }
}