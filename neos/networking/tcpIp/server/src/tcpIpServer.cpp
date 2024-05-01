#include "tcpIpServer.hpp"
#include "htonAdapter.h"

namespace Neos
{
  namespace Networking
  {
    TcpIpServer::TcpIpServer(TTcpIpConfig serverConfig):
      ITcpIp(serverConfig)
    {
      const int enable = 1; 
      m_socketAdapter.Setsockopt(SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));
      if (m_socketAdapter.Bind((struct sockaddr*)&m_tcpAddr, sizeof(m_tcpAddr)) != 0)
      {
        // TODO Error logging
        return;
      }
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

      //TESTING!!!!!!!!
      char buffer[1024];
      while(1)
      {
        size_t valread = read(newsockfd, &buffer, 1024-1);

      }
    }
  }
}