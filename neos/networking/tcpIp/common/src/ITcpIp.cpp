#include "ITcpIp.hpp"
#include "HtonProxy.h"

namespace Neos
{
  namespace Networking
  {


    ITcpIp::ITcpIp(TcpIpConfig_t config)
    {
      m_tcpAddr.sin_family = AF_INET;
      m_tcpAddr.sin_port = HtonlProxy_htons(config.port);
      m_tcpAddr.sin_addr.s_addr = config.IpAddress.addressValue;

      m_socketAdapter = SocketAdapter(AF_INET, SOCK_STREAM, 0);
      m_socketAdapter.CreateSocket();
   }

    ITcpIp::~ITcpIp()
    {

    }

    bool ITcpIp::Send(const void* buffer, size_t size)
    {
      size_t ret = m_socketAdapter.Send(buffer, size, 0);
      return (ret > 0) ? true : false;
    }

    size_t ITcpIp::Read(int socketfd)
    {
      size_t ret = m_socketAdapter.Read(socketfd, &m_msgBuffer, sizeof(m_msgBuffer));

      SMessageReceived.Emit({
        .payload = m_msgBuffer,
        .payloadSize = ret,
      });

      return ret;

    }
  }
}