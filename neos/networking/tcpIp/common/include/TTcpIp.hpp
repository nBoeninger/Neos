#pragma once

#include "stdint.h"
#include "cstddef"

namespace Neos
{

  namespace Networking
  {

   typedef struct TcpIpConfig
   {
    union IpAddress
    {
      uint8_t addressBytes[4];
      uint32_t addressValue;
    } IpAddress;
    uint16_t port;
   } TcpIpConfig_t;

   typedef struct ReceivedMessage
   {
    uint8_t* payload;
    size_t payloadSize;
   } ReceivedMessage_t;

    typedef struct SendedMessage
    {
      // define msg at some point
      void * dummy;
    } SendedMessage_t;

  }
}
