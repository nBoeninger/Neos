#include "tcpIpServer.hpp"
#include "htonAdapter.h"

namespace Neos
{
  namespace Networking
  {
    TcpIpServer::TcpIpServer(TTcpIpServerConfig serverConfig)
    {
      m_hostAddr.sin_family = AF_INET;
      m_hostAddr.sin_port = htonsAdapter(serverConfig.port);
      m_hostAddr.sin_port = htonsAdapter(8000);
      m_hostAddr.sin_addr.s_addr = htonlAdapter(INADDR_ANY);

      m_socketAdapter = SocketAdapter(AF_INET, SOCK_STREAM, 0);
      m_socketAdapter.CreateSocket();

      const int enable = 1;

      m_socketAdapter.Setsockopt(SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

      if (m_socketAdapter.Bind((struct sockaddr*)&m_hostAddr, sizeof(m_hostAddr)) != 0)
      {
        // TODO Error logging
        return;
      }
    }

    TcpIpServer::~TcpIpServer()
    {

    }

    void TcpIpServer::StartServer()
    {
      if (m_socketAdapter.Listen(SOMAXCONN) != 0)
      {
        //TODO Error logging
        return;
      }
    }

    void TcpIpServer::RunServer()
    {
      socklen_t addrLen = sizeof(m_hostAddr);
      while(1)
      {
        int newsockfd = m_socketAdapter.Accept((struct sockaddr*)&m_hostAddr);
        if (newsockfd < 0)
        {
          continue;
        }
        else
        {
          break;
        }
      }
    }
  }
}