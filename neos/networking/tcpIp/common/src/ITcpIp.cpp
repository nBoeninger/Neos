#include "ITcpIp.hpp"
#include "htonAdapter.h"

namespace Neos
{
  namespace Networking
  {
    ITcpIp::ITcpIp(TTcpIpConfig config)
    {
      m_tcpAddr.sin_family = AF_INET;
      m_tcpAddr.sin_port = htonsAdapter(config.port);
      m_tcpAddr.sin_addr.s_addr = config.IpAddress.addressValue;

      m_socketAdapter = SocketAdapter(AF_INET, SOCK_STREAM, 0);
      m_socketAdapter.CreateSocket();
   }

    ITcpIp::~ITcpIp()
    {

    }
  }
}