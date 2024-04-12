#include <functional>

#include "gtest/gtest.h"
#include "dataObject.hpp"

TEST(DataObjectTest, CreateEmptyObject)
{
  Neos::DataStructures::DataObject<int> Test(7);
  Test = 8;
}
