
#include "sleep.h"

void delay_sec(uint32_t delay_sec)
{
  if (delay_sec < 0)
  {
    return;
  }
  sleep(delay_sec);
}