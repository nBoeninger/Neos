#include "tcpIpServer.hpp"

namespace Neos
{
  namespace Communication
  {
    TcpIpServer::TcpIpServer():
    m_socket(AF_INET, SOCK_STREAM, 0)
    {

    }

    TcpIpServer::~TcpIpServer()
    {

    }
  }
}