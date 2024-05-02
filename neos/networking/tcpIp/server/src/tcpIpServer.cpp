#include "tcpIpServer.hpp"
#include "htonAdapter.h"
#include "sleep.h"

namespace Neos
{
  namespace Networking
  {
    TcpIpServer::TcpIpServer(TTcpIpConfig serverConfig):
      ITcpIp(serverConfig), m_activeBuffer(0)
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

    void TcpIpServer::Run()
    {
      while(1)
      {
        socklen_t addrLen = sizeof(m_tcpAddr);
        int newsockfd = m_socketAdapter.Accept((struct sockaddr*)&m_tcpAddr);
        if (newsockfd < 0)
        {
          return;
        }
        bool succes = this->Read(newsockfd);
      }
    }

    size_t TcpIpServer::Read(int socket)
    {
      size_t ret =  m_socketAdapter.Read(socket, &m_msgBuffer[m_activeBuffer], sizeof(m_msgBuffer));
     
      SMessageReceived.Emit({
        .payload = m_msgBuffer[m_activeBuffer],
        .payloadSize = ret,
      });

      if(m_activeBuffer >= NBR_OF_BUFFERS-1)
      {
        m_activeBuffer = 0;
      }
      else
      {
        m_activeBuffer++;
      }
      return ret;
    }

    bool TcpIpServer::Send(const void* buffer, size_t size)
    {
      return true;
    }
  }
}