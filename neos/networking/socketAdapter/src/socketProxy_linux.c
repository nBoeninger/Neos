
#include "socketProxy_linux.h"

#include "sys/socket.h"
#include <unistd.h>

int close_proxy(int socket)
{
  close(socket);
}

int socket_proxy(int domain, int type, int protocol)
{
  return socket(domain, type, protocol);
}

int setsockopt_proxy(int socket, int level, int option_name, const void* option_value, socklen_t option_len)
{
  return setsockopt(socket, level, option_name, option_value, option_len);
}

int bind_proxy(int socket, const struct sockaddr* addr, socklen_t addrlen)
{
  return bind(socket, addr, addrlen);
}

int listen_proxy(int socket, int backlog)
{
  return listen(socket, backlog);
}

int accept_proxy(int socket, struct sockaddr* addr, socklen_t* addrlen)
{
  return accept(socket, addr, addrlen);
}

int connect_proxy(int socket, struct sockaddr* addr, socklen_t addlen)
{
  return connect(socket, addr, addlen);
}

size_t send_proxy(int socket, const void* buffer, size_t size, int flags)
{
  return send(socket, buffer, size, flags);
}

size_t read_proxy(int socket, void* buffer, size_t count)
{
  return read(socket, buffer, count);
}

