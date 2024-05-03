#include "htonProxy.h"

uint32_t HtonlProxy_htonl(uint32_t net)
{
  #if TARGET == LINUX
    return htonl(net);
  #elif
    return __builtin_bswap32(net);
  #endif
}

uint16_t HtonlProxy_htons(uint16_t net)
{
  #if TARGET == LINUX
    return htons(net);
  #elif
    return __builtin_bswap16(net);
  #endif
}
