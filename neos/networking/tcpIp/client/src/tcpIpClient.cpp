#include "tcpIpClient.hpp"
#include "sleep.h"

namespace Neos
{

  namespace Networking
  {

    TcpIpClient::TcpIpClient(TcpIpConfig_t clientConfig) :
      ITcpIp(clientConfig), m_connectionRetries(CONNECTION_RETRIES)
    {
    }

    TcpIpClient::TcpIpClient(TcpIpConfig_t clientConfig, uint8_t conncetionRetries) :
      ITcpIp(clientConfig), m_connectionRetries(conncetionRetries)
    {
    }

    TcpIpClient::~TcpIpClient()
    {
    }

    bool TcpIpClient::Connect()
    {
      int ret = -1;
      for (int tries = 0; tries <= m_connectionRetries; tries++)
      {
        ret = m_socketAdapter.Connect((struct sockaddr*)&m_tcpAddr, sizeof(m_tcpAddr));
        if (ret == 0)
        {
          return true;
        }
        delay_sec(1);
      }
      return false;
    }

    bool TcpIpClient::Send(const void* buffer, size_t size)
    {
      size_t ret = m_socketAdapter.Send(buffer, size, 0);
      return (ret > 0) ? true : false;
    }

    size_t TcpIpClient::Read(int socketfd)
    {
      return true;
    }

  }
}