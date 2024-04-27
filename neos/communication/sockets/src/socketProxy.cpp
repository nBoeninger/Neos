
#include "socketProxy.hpp"

namespace Neos
{
  namespace Communication
  {

    SocketProxy::SocketProxy():
      m_socket(-1)
    {
    }

    SocketProxy::~SocketProxy()
    {
      close(m_socket);
    }

    int SocketProxy::Socket(int domain, int type, int protocol)
    {
      m_socket = socket(domain, type, protocol);
      return m_socket;
    }

    int SocketProxy::Setsockopt(int socket, int level, int option_name, const void* option_value, socklen_t option_len)
    {
      return setsockopt(socket, level, option_name, option_value, option_len);
    }
    
    int SocketProxy::Bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen)
    {
      return bind(sockfd, addr, addrlen);
    }

    int SocketProxy::Listen(int sockfd, int backlog)
    {
      return listen(sockfd, backlog);
    }

    int SocketProxy::Accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen)
    {
      return accept(sockfd, addr, addrlen);
    }

    int SocketProxy::GetSocket()
    {
      return m_socket;
    }
  }
}