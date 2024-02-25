
#include "gtest/gtest.h"
#include "linkedList.hpp"

TEST(LinkedListTest, BasicsOnEmptyList)
{
   LinkedList<int> intList = LinkedList<int>();
   ASSERT_TRUE(intList.getLen() == 0) << "Expected a lenght of 0!";
   ASSERT_TRUE(intList.remove(0) == false) << "Removing of unknown ID succeeded!";
   ASSERT_TRUE(intList.save(0) == false) << "Unable to save element to List";
   ASSERT_TRUE(intList.getLen() != 1) << "List Lenght not 1!";
}