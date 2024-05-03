
#include "socketProxy_linux.h"

#include "sys/socket.h"
#include <unistd.h>

int SocketProxy_close(int socketfd)
{
  close(socketfd);
}

int SocketProxy_socket(int domain, int type, int protocol)
{
  return socket(domain, type, protocol);
}

int SocketProxy_setsockopt(int socketfd, int level, int option_name, const void* option_value, socklen_t option_len)
{
  return setsockopt(socketfd, level, option_name, option_value, option_len);
}

int SocketProxy_bind(int socketfd, const struct sockaddr* addr, socklen_t addrlen)
{
  return bind(socketfd, addr, addrlen);
}

int SocketProxy_listen(int socketfd, int backlog)
{
  return listen(socketfd, backlog);
}

int SocketProxy_accept(int socketfd, struct sockaddr* addr, socklen_t* addrlen)
{
  return accept(socketfd, addr, addrlen);
}

int SocketProxy_connect(int socketfd, struct sockaddr* addr, socklen_t addlen)
{
  return connect(socketfd, addr, addlen);
}

size_t SocketProxy_send(int socketfd, const void* buffer, size_t size, int flags)
{
  return send(socketfd, buffer, size, flags);
}

size_t SocketProxy_read(int socketfd, void* buffer, size_t count)
{
  return read(socketfd, buffer, count);
}

