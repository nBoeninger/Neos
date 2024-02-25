
#include "gtest/gtest.h"
#include "linkedList.hpp"

TEST(LinkedListTest, CanCreateEmptyList)
{
   LinkedList<int> intList = LinkedList<int>();
   ASSERT_TRUE(intList.getLen() == 0);
   ASSERT_TRUE(intList.remove(0) == false);
}