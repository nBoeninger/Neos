
#include "gtest/gtest.h"
#include "stateMachine.h"

static int testingStates;

void OnEnterStateOne(void *context)
{
  testingStates = 1;  
}
void OnStateOne(void *context)
{
  testingStates++;;
}
void OnExitStateOne(void *context)
{
  testingStates++; 
}
void OnEnterStateTwo(void *context)
{
  testingStates++;
}
void OnStateTwo(void *context)
{
  testingStates++;
}
void OnExitStateTwo(void *context)
{
  testingStates++;
}
void OnStateChangedThree(void *context)
{
  testingStates = 42;
}

TEST(StateMachineTest, CanInit)
{
  stateMachine_t stateMachine;
  size_t tableSize = 10;
  stateTable_t stateTable[tableSize];
  bool isInitialized = StateMachine_Initialize(&stateMachine, stateTable, tableSize, nullptr);
  ASSERT_TRUE(isInitialized) << "Unable to Initialize StateMachine";
}

TEST(StateMachineTest, CanAddStates)
{
  stateMachine_t stateMachine;
  size_t tableSize = 10;
  stateTable_t stateTable[tableSize];
  StateMachine_Initialize(&stateMachine, stateTable, tableSize, nullptr);

  stateTable_t state_1 = {
    .stateId = 0x00,
    .onEnter = nullptr,
    .onExit = nullptr,
    .onState = nullptr,
  };

  bool stateWasAdded = StateMachine_AddState(&stateMachine, state_1);
  ASSERT_TRUE(stateWasAdded) << "Unable to add State to State Machine";
}

TEST(StateMachineTest, CanAddAndCallState)
{
  stateMachine_t stateMachine;
  size_t tableSize = 10;
  stateTable_t stateTable[tableSize];
  StateMachine_Initialize(&stateMachine, stateTable, tableSize, nullptr);

  stateTable_t states[] = {
    {
      .stateId = 0x00,
      .onEnter = OnEnterStateOne,
      .onExit = OnExitStateOne,
      .onState = OnStateOne,
      .onStateChanged = NULL,
    },
    {
     .stateId = 0x01,
     .onEnter = OnEnterStateTwo,
     .onExit = OnExitStateTwo,
     .onState = OnStateTwo, 
    },
    {
      .onStateChanged = OnStateChangedThree,
    }
  };

  StateMachine_AddState(&stateMachine, states[0]);
  StateMachine_AddState(&stateMachine, states[1]);
  StateMachine_AddState(&stateMachine, states[2]);

  StateMachine_SwitchToState(&stateMachine, 0x00);
  ASSERT_TRUE(testingStates == 2) << "StatesCount invalid, expected 3 got: " << testingStates;
  
  StateMachine_SwitchToState(&stateMachine, 0x01);
  ASSERT_TRUE(testingStates == 5) << "StatesCount invalid, expected 5, got: " << testingStates;

  StateMachine_SwitchToState(&stateMachine, 0x02);
  ASSERT_TRUE(testingStates == 42) << "StatesCount invalid, expected 42, got: " << testingStates;
}
