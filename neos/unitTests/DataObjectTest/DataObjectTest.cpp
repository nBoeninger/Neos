#include <functional>

#include "gtest/gtest.h"
#include "DataObject.hpp"

TEST(DataObjectTest, CreateEmptyObject)
{
  Neos::DataStructures::DataObject<int> Test(7);
  Test = 8;
}
