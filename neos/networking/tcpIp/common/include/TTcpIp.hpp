#pragma once

#include "stdint.h"

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
  }

}
