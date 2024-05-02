#pragma once

#include "stdint.h"
#include "cstddef"

namespace Neos
{

  namespace Networking
  {

   typedef struct TTcpIpConfig
   {
    union IpAddress
    {
      uint8_t addressBytes[4];
      uint32_t addressValue;
    } IpAddress;
    uint16_t port;
   } TTcpIpConfig;

   typedef struct TReceivedMessage
   {
    uint8_t* payload;
    size_t payloadSize;
   } TReceivedMessage;
  }
}
