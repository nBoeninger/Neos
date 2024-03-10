#include <functional>

#include "gtest/gtest.h"
#include "linkedList.hpp"

#define TESTLISTLENGHT 10
#define INTLISTVALUE 5

TEST(LinkedListTest, BasicsOnEmptyList)
{
   Neos::DataStructures::LinkedList<int> intList = Neos::DataStructures::LinkedList<int>();
   ASSERT_TRUE(intList.GetLen() == 0) << "Expected a lenght of 0!";
   ASSERT_TRUE(intList.RemoveID(0) == false) << "Removing of unknown ID succeeded, ID = 0";
   ASSERT_TRUE(intList.Save(0) == false) << "Unable to save element to List";
   ASSERT_TRUE(intList.GetLen() == 1) << "List Lenght not 1!";
}

TEST(LinkedListTest, CanSaveAndRemoveToList)
{
   Neos::DataStructures::LinkedList<int> intList = Neos::DataStructures::LinkedList<int>();
   for(int i = 0; i < TESTLISTLENGHT; i++)
   {
      intList.Save(i);
   }
   ASSERT_TRUE(intList.GetLen() == TESTLISTLENGHT) << "List Length invalid";
   ASSERT_TRUE(intList.RemoveID(1) == true) << "Removing ID not succeeded, ID = 1";
   ASSERT_TRUE(intList.GetLen() == TESTLISTLENGHT-1) << "Incorrect List Length after removing";
   
   ASSERT_TRUE(intList.RemoveID(INTLISTVALUE) == true) << "Removing ID not succeeded, ID = " << INTLISTVALUE;
   ASSERT_TRUE(intList.RemoveID(INTLISTVALUE) == false) << "Removing ID succeeded, ID = " << INTLISTVALUE;
   
   for (int i = 0; i < TESTLISTLENGHT; i++)
   {
      intList.Save(INTLISTVALUE);
   }

   ASSERT_TRUE(intList.GetLen() == ((TESTLISTLENGHT*2)-2) ) << "Incorrect List Lenght after adding";

   for (int i = 0; i < TESTLISTLENGHT; i++)
   {
      ASSERT_TRUE(intList.RemoveID(INTLISTVALUE) == true) << "Removing Element failed at position " << i;
   }
   
   ASSERT_TRUE(intList.GetLen() == ((TESTLISTLENGHT-2))) << "Incorrect List Length: " << intList.GetLen();
}

TEST(LinkedListTest, CanGetFrontElement)
{
   Neos::DataStructures::LinkedList<int> intList;

   auto t = intList.GetFront();

   for (int i = 0; i < TESTLISTLENGHT; i++)
   {
      intList.Save(i);
   }
   
   auto returnedFront = intList.GetFront();
   int checkValue = 0;
   if (returnedFront == true)
   {
    checkValue = returnedFront;  
   }

   ASSERT_TRUE(checkValue == 0) << "Incorrect Value return, expected 1, got " << checkValue;
   
}

typedef void(*TestFunction)(void);

TEST(LinkedListTest, CanSaveFunctionsInList)
{
   Neos::DataStructures::LinkedList<TestFunction> functionList;
   TestFunction test = [](){};
   functionList.Save(test);
   ASSERT_TRUE(functionList.GetLen() == 1) << "FunctionList invalid list lenght";
}