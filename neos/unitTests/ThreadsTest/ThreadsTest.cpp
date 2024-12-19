
#include "gtest/gtest.h"
#include "ThreadAdapter.hpp"
#include "Sleep.h"

TEST(ThreadsTest, CanCreateThread)
{
  Neos::ThreadAdapter thread_one = Neos::ThreadAdapter(Neos::TThreadAttributes{
    .schedulingPriority = 0,
    .schedulingPolicy = 0,
    .stackSize = 100,
  }, "TestThread");

  thread_one.Start();

  sleep(10);
}
