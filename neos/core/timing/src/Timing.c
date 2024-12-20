#include "Timing.h"
#include "stdio.h"

#if TARGET == LINUX
  #include <time.h>

  int GetCurrentTicks()
  {
    return (int)time(NULL);
  }

  void GetCurrentDate(char* buffer)
  {
    struct tm* ptr;
    time_t test = time(NULL);
    ptr = localtime(&test);
    sprintf(buffer, "%s", asctime(ptr));
  }

#elif TARGET == ESP32
// TODO FIll in libs

#endif

void Delay(uint32_t delay_ms)
{
  if (delay_ms < 0)
  {
    return;
  }
  uint32_t currentTicks = GetCurrentTicks();
  uint32_t startTicks = GetCurrentTicks();

  while ((currentTicks - startTicks) < delay_ms)
  {
    currentTicks = GetCurrentTicks();
  }
}
