cmake_minimum_required(VERSION 3.15)

set(This LinkedListTest)

set(Sources
    LinkedListTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    LinkedList
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
