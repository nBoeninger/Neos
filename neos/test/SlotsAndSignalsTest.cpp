#include <iostream>

#include "gtest/gtest.h"
#include "signals.hpp"


TEST(SignalsSlotTest, CanInit)
{
    Signal<int> test;
    
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