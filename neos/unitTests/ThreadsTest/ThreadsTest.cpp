
#include "gtest/gtest.h"
#include "Thread.hpp"
#include "Timing.h"

TEST(ThreadsTest, CanCreateThread)
{
  Neos::Logging logger = Neos::Logging("Test", Neos::ELogLevel::ERROR);
  Neos::Thread thread_one = Neos::Thread(Neos::ThreadAttributes_t{
    .schedulingPriority = 0,
    .schedulingPolicy = 0,
    .stackSize = 100,
  }, "TestThread", &logger);

  thread_one.Start();

  Delay(10);
}
