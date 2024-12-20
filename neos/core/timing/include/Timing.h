#pragma once

#if __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include <string.h>

void Delay(uint32_t delay_ms);

int GetCurrentTicks();

void GetCurrentDate(char* buffer);

#if __cplusplus
}
#endif