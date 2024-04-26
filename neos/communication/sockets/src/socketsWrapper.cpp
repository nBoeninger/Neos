
#include "socketsWrapper.hpp"

namespace Neos
{
  namespace Communication
  {

    SocketsWrapper::SocketsWrapper(int domain, int type, int protocol):
      m_domain(domain), m_protocol(protocol), m_type(type)
    {
      m_socket = socket(domain, type, protocol);
      if (m_socket < 0)
      {
        //TODO: Error logging
        return;
      }
    }

    SocketsWrapper::~SocketsWrapper()
    {
      close(m_socket);
    }
  }
}