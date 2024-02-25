#include <functional>

#include "gtest/gtest.h"
#include "linkedList.hpp"

#define TESTLISTLENGHT 10
#define INTLISTVALUE 5

TEST(LinkedListTest, BasicsOnEmptyList)
{
   LinkedList<int> intList = LinkedList<int>();
   ASSERT_TRUE(intList.getLen() == 0) << "Expected a lenght of 0!";
   ASSERT_TRUE(intList.removeID(0) == false) << "Removing of unknown ID succeeded, ID = 0";
   ASSERT_TRUE(intList.save(0) == false) << "Unable to save element to List";
   ASSERT_TRUE(intList.getLen() == 1) << "List Lenght not 1!";
}

TEST(LinkedListTest, CanSaveAndRemoveToList)
{
   LinkedList<int> intList = LinkedList<int>();
   for(int i = 0; i < TESTLISTLENGHT; i++)
   {
      intList.save(i);
   }
   ASSERT_TRUE(intList.getLen() == TESTLISTLENGHT) << "List Length invalid";
   ASSERT_TRUE(intList.removeID(1) == true) << "Removing ID not succeeded, ID = 1";
   ASSERT_TRUE(intList.getLen() == TESTLISTLENGHT-1) << "Incorrect List Length after removing";
   
   ASSERT_TRUE(intList.removeID(INTLISTVALUE) == true) << "Removing ID not succeeded, ID = " << INTLISTVALUE;
   ASSERT_TRUE(intList.removeID(INTLISTVALUE) == false) << "Removing ID succeeded, ID = " << INTLISTVALUE;
   
   for (int i = 0; i < TESTLISTLENGHT; i++)
   {
      intList.save(INTLISTVALUE);
   }

   ASSERT_TRUE(intList.getLen() == ((TESTLISTLENGHT*2)-2) ) << "Incorrect List Lenght after adding";

   for (int i = 0; i < TESTLISTLENGHT; i++)
   {
      ASSERT_TRUE(intList.removeID(INTLISTVALUE) == true) << "Removing Element failed at position " << i;
   }
   
   ASSERT_TRUE(intList.getLen() == ((TESTLISTLENGHT-2))) << "Incorrect List Length: " << intList.getLen();
}

TEST(LinkedListTest, CanGetFrontElement)
{
   LinkedList<int> intList;

   auto t = intList.getFront();

   for (int i = 0; i < TESTLISTLENGHT; i++)
   {
      intList.save(i);
   }
   int returnedFront = intList.getFront();
   ASSERT_TRUE(returnedFront == 0) << "Incorrect Value return, expected 1, got " << returnedFront;
   
   int test = 0;
}

typedef void(*TestFunction)(void);

TEST(LinkedListTest, CanSaveFunctionsInList)
{
   LinkedList<TestFunction> functionList;
   TestFunction test = [](){};
   functionList.save(test);
   ASSERT_TRUE(functionList.getLen() == 1) << "FunctionList invalid list lenght";
}