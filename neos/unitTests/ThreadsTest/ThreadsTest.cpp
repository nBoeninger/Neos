
#include "gtest/gtest.h"
#include "ThreadAdapter.hpp"
#include "Timing.h"

TEST(ThreadsTest, CanCreateThread)
{
  Neos::Logging logger = Neos::Logging("Test", Neos::ELogLevel::ERROR);
  Neos::ThreadAdapter thread_one = Neos::ThreadAdapter(Neos::ThreadAttributes_t{
    .schedulingPriority = 0,
    .schedulingPolicy = 0,
    .stackSize = 100,
  }, "TestThread", &logger);

  thread_one.Start();

  Delay(10);
}
