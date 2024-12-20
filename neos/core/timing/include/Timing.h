#pragma once

#if __cplusplus
extern "C" {
#endif

#include "stdint.h"

void Delay(uint32_t delay_ms);

int GetCurrentTicks();

#if __cplusplus
}
#endif