#pragma once

#if __cplusplus
extern "C" {
#endif

#include "stdint.h"

#if TARGET == LINUX
  #include <time.h>
#elif TARGET == ESP32
// TODO FIll in libs
#endif

void sleepForSec(uint32_t sleep_s);

#if __cplusplus
}
#endif