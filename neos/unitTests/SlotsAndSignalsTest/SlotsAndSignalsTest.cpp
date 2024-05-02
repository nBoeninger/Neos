#include <iostream>

#include "gtest/gtest.h"
#include "signals.hpp"

#define BUFFERSIZE 40

static int checkValue;

void On_Test(int input)
{
    checkValue = input;
}

typedef struct EmittedDataStruct
{
  int integer;
  float floating;
  char charbuffer[BUFFERSIZE];
} EmittedDataStruct;

class TestClass
{
  public:
  TestClass() : receivedValueINT(0){};

  void On_SignalReceivedINT(int input)
  {
    receivedValueINT = input;
  };
  int receivedValueINT;

  void On_SignalReceivedSTRUCT(EmittedDataStruct input)
  {
    for (int bufferSize = 0; bufferSize < BUFFERSIZE; bufferSize++)
    {
        receivedValueSTRUCT.charbuffer[bufferSize] = input.charbuffer[bufferSize];
    }

    receivedValueSTRUCT.integer = input.integer;
    receivedValueSTRUCT.floating = input.floating;
  }
  EmittedDataStruct receivedValueSTRUCT;

};

TEST(SlotAndSingalsTest, CanConnectFunctionsAndEmit)
{
  Neos::Communication::Signal<int> testSignal;
  testSignal.Connect(On_Test);
  testSignal.Emit(2);
  ASSERT_TRUE(checkValue == 2) << "CheckValue not as expected, got " << checkValue << " expected 2";
}

TEST(SlotAndSignalTest, CanConnectClassFunctionsAndEmit)
{
  Neos::Communication::Signal<int> testSignal;
  TestClass testClass;
  testSignal.Connect(&testClass, &TestClass::On_SignalReceivedINT);
  testSignal.Emit(42);
  ASSERT_TRUE(testClass.receivedValueINT == 42) << "ReceivedValue not as expected, got " << testClass.receivedValueINT << " expected 42";   
}

TEST(SlotsAndSignalsTest, CanEmitStructs)
{
  Neos::Communication::Signal<EmittedDataStruct> testSignal;
  TestClass testClass;
  testSignal.Connect(&testClass, &TestClass::On_SignalReceivedSTRUCT);
  EmittedDataStruct testStruct;
  testStruct.integer = 77;
  testStruct.floating = 4.78f;
  testStruct.charbuffer[0] = 'a';
  testStruct.charbuffer[20] = 'b';
  testStruct.charbuffer[39] = 'c';
  testSignal.Emit(testStruct);
  
  ASSERT_TRUE(testClass.receivedValueSTRUCT.integer == testStruct.integer) << "ReceivedValue in Struct not as expected, INTEGER";
  ASSERT_TRUE(testClass.receivedValueSTRUCT.floating == testStruct.floating) << "ReceivedValue in Struct not as expected, FLOAT";
  ASSERT_TRUE(testClass.receivedValueSTRUCT.charbuffer[0] ==  testStruct.charbuffer[0]) << "ReceivedValue in Struct not as expected, CHARBUFFER[0]";
  ASSERT_TRUE(testClass.receivedValueSTRUCT.charbuffer[20] == testStruct.charbuffer[20]) << "ReceivedValue in Struct not as expected, CHARBUFFER[20]";
  ASSERT_TRUE(testClass.receivedValueSTRUCT.charbuffer[39] == testStruct.charbuffer[39]) << "ReceivedValue in Struct not as expected, CHARBUFFER[39]";
}

TEST(SlotAndSignalTest, CanEmitMultipleFunctions)
{
    
}