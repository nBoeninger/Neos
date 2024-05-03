#pragma once

/**
 * @brief The Socket Adapter Module
 * @details This module provides an layer of abstraction 
 *            for the sockets used by the TcpIP Server Class
 *            TheAdapter calls the "proxy" functions which will t
 *            hen call the kernel functions.
*/

#include "eConfigs.hpp"
#include "sysDefines.hpp"
#include "stdint.h"

#if TARGET == LINUX
  #include "socketProxy_linux.h"
#elif TARGET == ESP32
// TODO FIll in libs
#endif

//TODO: fill in documentations

namespace Neos
{
  namespace Networking
  {

    /**
     * @brief TSockAddr_in, adapter for the real struct handled by the kernel 
     */
    typedef struct TSockAddr_in 
    {
      int16_t sin_family;
      uint16_t sin_port;
      struct in_addr
      {
        uint32_t s_addr;
      } sin_addr;
      uint8_t sin_zero[8];
    }TSockAddr_in;

    /**
     * @brief The SocketProxy Class
     */
    class SocketAdapter
    {
      public:

        SocketAdapter(){};

        /**
         * @brief Create a Socket
         * @param domain 
         * @param type 
         * @param protocol 
         * @return int socket
        */
        SocketAdapter(int domain, int type, int protocol);
        ~SocketAdapter();

        int CreateSocket();

        /**
         * @brief Set the socket options
         * @param level 
         * @param option_name 
         * @param option_value 
         * @param option_len 
         * @return 
         */
        int Setsockopt(int level, int option_name, const void* option_value, socklen_t option_len);

        /**
         * @brief  Bind a Socket to an Address
         * @param addr 
         * @param addrlen 
         * @return 
         */
        int Bind(const struct sockaddr* addr, socklen_t addrlen);

        /**
         * @brief Listen for connections
         * @param sockfd 
         * @param backlog 
         * @return 
         */
        int Listen(int backlog);

        /**
         * @brief Accept a Connection
         * @param addr 
         * @return 
         */
        int Accept(struct sockaddr* addr);

        /**
         * @brief Connect to a socket
         * @param addr 
         * @param addrelen
         * @return 
         */
        int Connect(struct sockaddr* addr, socklen_t addlen);

        /**
         * @brief Getter for the socket
         * @return 
         */
        int GetSocket();

        size_t Send(const void* buffer, size_t size, int flags);
        size_t Read(int socket, void* buffer, size_t count);

      private:
        int m_socket;
        int m_domain;
        int m_protocol;
        int m_type;
        TSockAddr_in m_addrIn;
        const struct sockaddr* m_addr;
        socklen_t m_addrlen;
    };
 }
}
