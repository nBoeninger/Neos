
#include "gtest/gtest.h"
#include "validReturn.hpp"

TEST(ValidReturnTest, CanInit)
{
  Neos::DataStructures::ValidReturn<int> t;
  ASSERT_FALSE(t) << "T Value was valid! Should have been invalid";
}

TEST(ValidReturnTest, CanAssign)
{
  Neos::DataStructures::ValidReturn<int> t;
  t = 1;
  ASSERT_TRUE(t == true) << "T Value was invalid!";
}

TEST(ValidReturnTest, CanAssignNewVar)
{
  Neos::DataStructures::ValidReturn<int> t(42);
  int test = t;
  ASSERT_TRUE(test = 42) << "T Value unabled to be cast!";
}

TEST(ValidReturnTest, CanCheckInIf)
{
  Neos::DataStructures::ValidReturn<int> t(42);
  ASSERT_TRUE(t == true) << "T Value unable to check!";
}