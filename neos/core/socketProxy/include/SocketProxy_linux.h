#pragma once

#if __cplusplus
extern "C" {
#endif

#include "sys/socket.h"
#include <unistd.h>

int SocketProxy_close(int socketfd);
int SocketProxy_socket(int domain, int type, int protocol);
int SocketProxy_setsockopt(int socketfd, int level, int option_name, const void* option_value, socklen_t option_len);
int SocketProxy_bind(int socketfd, const struct sockaddr* addr, socklen_t addrlen);
int SocketProxy_listen(int socketfd, int backlog);
int SocketProxy_accept(int socketfd, struct sockaddr* addr, socklen_t* addrlen);
int SocketProxy_connect(int socketfd, struct sockaddr* addr, socklen_t addlen);
size_t SocketProxy_send(int socketfd, const void* buffer, size_t size, int flags);
size_t SocketProxy_read(int socketfd, void* buffer, size_t count);

#if __cplusplus
}
#endif