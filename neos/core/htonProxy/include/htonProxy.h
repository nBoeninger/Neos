#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "eConfigs.hpp"
#include "sysDefines.hpp"
#include "stdint.h"

#if TARGET == LINUX
  #include "sys/socket.h"
  #include <unistd.h>
  #include <arpa/inet.h>

#elif TARGET == ESP32
// TODO FIll in libs
#endif

uint32_t HtonlProxy_htonl(uint32_t net);

uint16_t HtonlProxy_htons(uint16_t net);

#ifdef __cplusplus
}
#endif