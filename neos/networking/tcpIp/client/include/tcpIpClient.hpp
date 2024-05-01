#pragma once

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

   class TcpIpClient
   {
      public:
        TcpIpClient(){};
        TcpIpClient(TTcpIpConfig config);
        ~TcpIpClient();

        void StartClient();

      private:
        SocketAdapter m_socketAdapter;
        TSockAddr_in m_clientAddr;

   };

  }
}