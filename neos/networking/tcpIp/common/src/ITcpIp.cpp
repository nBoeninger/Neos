#include "ITcpIP.hpp"
#include "htonAdapter.h"

namespace Neos
{
  namespace Networking
  {
    ITcpIp::ITcpIp(TTcpIpConfig config)
    {
      m_tcpAddr.sin_family = AF_INET;
      m_tcpAddr.sin_port = htonsAdapter(config.port);
      m_tcpAddr.sin_addr.s_addr = config.IpAddress.addressValue;

      m_socketAdapter = SocketAdapter(AF_INET, SOCK_STREAM, 0);
      m_socketAdapter.CreateSocket();

      const int enable = 1;

      m_socketAdapter.Setsockopt(SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

      if (m_socketAdapter.Bind((struct sockaddr*)&m_tcpAddr, sizeof(m_tcpAddr)) != 0)
      {
        // TODO Error logging
        return;
      }
    }

    ITcpIp::~ITcpIp()
    {

    }
  }
}