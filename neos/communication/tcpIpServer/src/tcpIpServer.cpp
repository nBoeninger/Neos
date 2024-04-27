#include "tcpIpServer.hpp"

namespace Neos
{
  namespace Communication
  {
    TcpIpServer::TcpIpServer(TTcpIpServerConfig serverConfig)
    {
      m_serverConfig.port = htons(serverConfig.port);
      m_serverConfig.IpAddress.addressValue = htonl(serverConfig.IpAddress.addressValue);
      
      m_hostAddr.sin_family = AF_INET;
      m_hostAddr.sin_port = m_serverConfig.port;
      m_hostAddr.sin_addr.s_addr = htonl(INADDR_ANY);

      m_socket = SocketProxy();
      int serverSocket = m_socket.Socket(m_hostAddr.sin_family, SOCK_STREAM, 0);
      if (serverSocket < 0)
      {
        // TODO Error logging
        return;
      }
      const int enable = 1;
      m_socket.Setsockopt(m_socket.GetSocket(), SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));
      if (m_socket.Bind(m_socket.GetSocket(), (struct sockaddr*)&m_hostAddr, sizeof(m_hostAddr)) != 0)
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
      if (m_socket.Listen(m_socket.GetSocket(), SOMAXCONN) != 0)
      {
        //TODO Error logging
        return;
      }
    }

    void TcpIpServer::RunServer()
    {
      int addrLen = sizeof(m_hostAddr);
      while(1)
      {
        int newsockfd = m_socket.Accept(m_socket.GetSocket(), (struct sockaddr*)&m_hostAddr, (socklen_t*)&addrLen);
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