
#include "socketAdapter.hpp"

namespace Neos
{
  namespace Networking
  {

    SocketAdapter::~SocketAdapter()
    {
      close(m_socket);
    }

    SocketAdapter::SocketAdapter(int domain, int type, int protocol) :
    m_domain(domain), m_protocol(protocol), m_type(type)
    {
    }

    int SocketAdapter::CreateSocket()
    {
      m_socket = socket(m_domain, m_type, m_protocol);
      return m_socket;
    }

    int SocketAdapter::Setsockopt(int level, int option_name, const void* option_value, socklen_t option_len)
    {
      return setsockopt(m_socket, level, option_name, option_value, option_len);
    }
    
    int SocketAdapter::Bind(const struct sockaddr* addr, socklen_t addrlen)
    {
      m_addr = addr;
      m_addrlen = addrlen;
      return bind(m_socket, m_addr, m_addrlen);
    }

    int SocketAdapter::Listen(int backlog)
    {
      return listen(m_socket, backlog);
    }

    int SocketAdapter::Accept(struct sockaddr* addr)
    {
      return accept(m_socket, addr, &m_addrlen);
    }

    int SocketAdapter::GetSocket()
    {
      return m_socket;
    }
  }
}