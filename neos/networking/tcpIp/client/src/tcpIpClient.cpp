#include "tcpIpClient.hpp"
#include "sleep.h"

namespace Neos
{

  namespace Networking
  {

    TcpIpClient::TcpIpClient(TTcpIpConfig clientConfig) :
      ITcpIp(clientConfig), m_connectionRetries(CONNECTION_RETRIES)
    {
    }

    TcpIpClient::TcpIpClient(TTcpIpConfig clientConfig, uint8_t conncetionRetries) :
      ITcpIp(clientConfig), m_connectionRetries(conncetionRetries)
    {
    }

    TcpIpClient::~TcpIpClient()
    {
    }

    bool TcpIpClient::Start()
    {
      int ret = -1;
      for (int tries = 0; tries <= m_connectionRetries; tries++)
      {
        ret = m_socketAdapter.Connect((struct sockaddr*)&m_tcpAddr, sizeof(m_tcpAddr));
        if (ret == 0)
        {
          break;
        }
        sleepForSec(1);
      }

      char testMsg[10] = "TEST";
      send(m_socketAdapter.GetSocket(), testMsg, 5, 0);
      sleepForSec(100);
      return (ret > 0) ? true : false;
    }

  }
}