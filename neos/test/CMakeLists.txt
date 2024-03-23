set(This NeosUnitTest)

add_subdirectory(ValidReturnTest)
add_subdirectory(SlotsAndSignalsTest)
add_subdirectory(StateMachineTest)
add_subdirectory(LinkedListTest)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(Sources ${TEST_SOURCES})

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
  gtest_main
  ValidReturn
  SlotsAndSignals
  StateMachine
  LinkedList
)

##add_test(neosUnitTests ${This})