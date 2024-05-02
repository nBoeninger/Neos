#include "socketAdapter.hpp"

namespace Neos
{
  namespace Networking
  {

    SocketAdapter::~SocketAdapter()
    {
      close_proxy(m_socket);
    }

    SocketAdapter::SocketAdapter(int domain, int type, int protocol) :
    m_domain(domain), m_protocol(protocol), m_type(type), m_socket(-1)
    {
    }

    int SocketAdapter::CreateSocket()
    {
      m_socket = socket_proxy(m_domain, m_type, m_protocol);
      return m_socket;
    }

    int SocketAdapter::Setsockopt(int level, int option_name, const void* option_value, socklen_t option_len)
    {
      return setsockopt_proxy(m_socket, level, option_name, option_value, option_len);
    }
    
    int SocketAdapter::Bind(const struct sockaddr* addr, socklen_t addrlen)
    {
      m_addr = addr;
      m_addrlen = addrlen;
      return bind_proxy(m_socket, m_addr, m_addrlen);
    }

    int SocketAdapter::Listen(int backlog)
    {
      return listen_proxy(m_socket, backlog);
    }

    int SocketAdapter::Accept(struct sockaddr* addr)
    {
      return accept_proxy(m_socket, addr, &m_addrlen);
    }

    int SocketAdapter::Connect(struct sockaddr* addr, socklen_t addlen)
    {
      return connect_proxy(m_socket, addr, addlen);
    }

    int SocketAdapter::GetSocket()
    {
      return m_socket;
    }

    size_t SocketAdapter::Read(int socket, void* buffer, size_t count)
    {
      return read_proxy(socket, buffer, count);
    }

    size_t SocketAdapter::Send(const void* buffer, size_t size, int flags)
    {
      return send_proxy(m_socket, buffer, size, flags);
    }
  }
}