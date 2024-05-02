#pragma once

#if __cplusplus
extern "C" {
#endif

#include "sys/socket.h"
#include <unistd.h>

int close_proxy(int socket);
int socket_proxy(int domain, int type, int protocol);
int setsockopt_proxy(int socket, int level, int option_name, const void* option_value, socklen_t option_len);
int bind_proxy(int socket, const struct sockaddr* addr, socklen_t addrlen);
int listen_proxy(int socket, int backlog);
int accept_proxy(int socket, struct sockaddr* addr, socklen_t* addrlen);
int connect_proxy(int socket, struct sockaddr* addr, socklen_t addlen);
size_t send_proxy(int socket, const void* buffer, size_t size, int flags);
size_t read_proxy(int socket, void* buffer, size_t count);

#if __cplusplus
}
#endif