#include "tcpIpServer.hpp"
#include "htonProxy.h"
#include "sleep.h"

namespace Neos
{
  namespace Networking
  {
    TcpIpServer::TcpIpServer(TcpIpConfig_t serverConfig):
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

    int TcpIpServer::WaitForConnections()
    {
      socklen_t addrLen = sizeof(m_tcpAddr);
      int newsockfd = m_socketAdapter.Accept((struct sockaddr*)&m_tcpAddr);
      if (newsockfd < 0)
      {
        return -1;
      }
      return newsockfd;
    }

    size_t TcpIpServer::Read(int socketfd)
    {
      size_t ret =  m_socketAdapter.Read(socketfd, &m_msgBuffer, sizeof(m_msgBuffer));
     
      SMessageReceived.Emit({
        .payload = m_msgBuffer,
        .payloadSize = ret,
      });

     return ret;
    }

    bool TcpIpServer::Send(const void* buffer, size_t size)
    {
      return true;
    }
  }
}