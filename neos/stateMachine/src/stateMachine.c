#include <string.h>

#include "stateMachine.h"

bool StateMachine_Initialize(stateMachine_t* stateMachine, stateTable_t* stateTable, size_t tableSize, void* context)
{
  if ((tableSize == 0)
    || (tableSize >= StateMachine_MAXSIZE)
  )
  {
    return false;
  }

  stateMachine->currentState = StateMachine_INITSTATE;
  stateMachine->addedStates = 0;
  stateMachine->tableSize = tableSize;
  stateMachine->stateTable = stateTable;
}

bool StateMachine_AddState(stateMachine_t* stateMachine, stateTable_t stateTable)
{
  if (stateMachine->addedStates >= stateMachine->tableSize)
  {
    return false;
  }

  stateMachine->stateTable[stateMachine->addedStates].onEnter = stateTable.onEnter;
  stateMachine->stateTable[stateMachine->addedStates].onExit = stateTable.onExit;
  stateMachine->stateTable[stateMachine->addedStates].onState = stateTable.onState;
  stateMachine->stateTable[stateMachine->addedStates].stateId = stateTable.stateId;

  stateMachine->addedStates++;
  return true;
}

bool StateMachine_SwitchToState(stateMachine_t* stateMachine, uint8_t stateId)
{
  if ((stateId > stateMachine->tableSize)
      || (stateId == stateMachine->currentState)
      || (stateId > stateMachine->addedStates)
    )
  {
    return false;
  }
  if (stateMachine->currentState != StateMachine_INITSTATE)
  {
    stateMachine->stateTable[stateMachine->currentState].onExit(stateMachine->context);
  }

  stateMachine->currentState = stateId;
  stateMachine->stateTable[stateMachine->currentState].onEnter(stateMachine->context);
  stateMachine->stateTable[stateMachine->currentState].onState(stateMachine->context);
}