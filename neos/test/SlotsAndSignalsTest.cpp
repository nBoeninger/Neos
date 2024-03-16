#include <iostream>

#include "gtest/gtest.h"
#include "signals.hpp"

#define BUFFERSIZE 40

static int checkValue;

void onTest(int input)
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

  void onSignalReceivedINT(int input)
  {
    receivedValueINT = input;
  };
  int receivedValueINT;

  void onSignalReceivedSTRUCT(EmittedDataStruct input)
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
  Neos::Signal<int> testSignal;
  testSignal.Connect(onTest);
  testSignal.Emit(2);
  ASSERT_TRUE(checkValue == 2) << "CheckValue not as expected, got " << checkValue << " expected 2";
}

TEST(SlotAndSignalTest, CanConnectClassFunctionsAndEmit)
{
  Neos::Signal<int> testSignal;
  TestClass testClass;
  testSignal.Connect(&testClass, &TestClass::onSignalReceivedINT);
  testSignal.Emit(42);
  ASSERT_TRUE(testClass.receivedValueINT == 42) << "ReceivedValue not as expected, got " << testClass.receivedValueINT << " expected 42";   
}

TEST(SlotsAndSignalsTest, CanEmitStructs)
{
  Neos::Signal<EmittedDataStruct> testSignal;
  TestClass testClass;
  testSignal.Connect(&testClass, &TestClass::onSignalReceivedSTRUCT);
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
/*
class TestClass_1
{
public:
    void on_sig_test_rcv(int data);
    Signal<int> signal_class_1;
};

void TestClass_1::on_sig_test_rcv(int data)
{
    int t = 0;
}

class TestClass_2
{
public:
    void on_sig_test_rcv(int data);
    Signal<int> signal_class_2;
};

void TestClass_2::on_sig_test_rcv(int data)
{
    int t = 0;
}

void test_sig_slot(void)
{
    auto c_1 = TestClass_1();
    auto c_2 = TestClass_2();

    c_1.signal_class_1.connect(&c_2, &TestClass_2::on_sig_test_rcv);
    c_1.signal_class_1.emit(47);

    std::cout << "waiting\n";

}

void test_linked_list(void)
{
    LinkedList<int> t;
    LinkedList<int> t;
    t.save(5);
    t.save(17);
    t.save(25);
    int test = t.getFront();

}

int main() 
{
    test_linked_list();
    test_sig_slot();
}*/