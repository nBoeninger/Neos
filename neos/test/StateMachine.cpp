
#include "gtest/gtest.h"
#include "stateMachine.h"

static uint8_t stateId;

void OnEnterStateOne(void *context)
{
  int t = 0;  
}
void OnStateOne(void *context)
{
  int t = 0;
}
void OnExitStateOne(void *context)
{
  int t = 0; 
}
void OnEnterStateTwo(void *context)
{
  int t = 0;  
}
void OnStateTwo(void *context)
{
  int t = 0;
}
void OnExitStateTwo(void *context)
{
  int t = 0; 
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

  StateMachine_AddState(&stateMachine, stateTable_t{
    .stateId = 0x00,
    .onEnter = OnEnterStateOne,
    .onExit = OnExitStateOne,
    .onState = OnStateOne,
  });
   StateMachine_AddState(&stateMachine, stateTable_t{
    .stateId = 0x01,
    .onEnter = OnEnterStateTwo,
    .onExit = OnExitStateTwo,
    .onState = OnStateTwo,
  });
  
  StateMachine_SwitchToState(&stateMachine, 0x00);
  StateMachine_SwitchToState(&stateMachine, 0x01);
}
