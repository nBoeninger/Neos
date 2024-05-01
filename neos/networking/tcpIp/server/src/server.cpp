#include "server.hpp"
#include "htonAdapter.h"

namespace Neos
{
  namespace Networking
  {
    TcpIpServer::TcpIpServer(TTcpIpConfig serverConfig):
      ITcpIp(serverConfig)
    {
     
    }

    TcpIpServer::~TcpIpServer()
    {

    }

    bool TcpIpServer::Start()
    {
      return m_socketAdapter.Listen(SOMAXCONN) == 0;
    }

    void TcpIpServer::RunServer()
    {
      socklen_t addrLen = sizeof(m_tcpAddr);
      int newsockfd = m_socketAdapter.Accept((struct sockaddr*)&m_tcpAddr);
      if (newsockfd < 0)
      {
        return;
      }

    }
  }
}