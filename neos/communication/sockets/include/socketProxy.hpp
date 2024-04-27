/**
 * @brief The Socket Proxy Module
 * @details This module provides an layer of abstraction 
 *            for the sockets used by the TcpIP Server Class
 *            Something between proxy and adapter...
*/

#include "eConfigs.hpp"
#include "sysDefines.hpp"

#if TARGET == LINUX
  #include "sys/socket.h"
  #include <unistd.h>
#elif TARGET == ESP32
// TODO FIll in libs
#endif

//TODO: fill in documentations

namespace Neos
{
 namespace Communication
 {

  /**
   * @brief The SocketProxy Class
   */
  class SocketProxy
  {
    public:
      SocketProxy();
      ~SocketProxy();

      /**
       * @brief Create a Socket
       * @param domain 
       * @param type 
       * @param protocol 
       * @return int socket
      */
      int Socket(int domain, int type, int protocol);

      /**
       * @brief Set the socket options
       * @param socket 
       * @param level 
       * @param option_name 
       * @param option_value 
       * @param option_len 
       * @return 
       */
      int Setsockopt(int socket, int level, int option_name, const void* option_value, socklen_t option_len);

      /**
       * @brief  Bind a Socket to an Address
       * @param sockfd 
       * @param addr 
       * @param addrlen 
       * @return 
       */
      int Bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen);

      /**
       * @brief Listen for connections
       * @param sockfd 
       * @param backlog 
       * @return 
       */
      int Listen(int sockfd, int backlog);

      int Accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen);

      int GetSocket();

    private:
      int m_socket;
  };
 }
}
