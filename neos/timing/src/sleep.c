
#include "sleep.h"

void sleepForSec(uint32_t sleep_s)
{
  if (sleep_s < 0)
  {
    return;
  }
  sleep(sleep_s);
}