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

void delay_sec(uint32_t delay_sec);

#if __cplusplus
}
#endif