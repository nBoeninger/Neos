#include <string.h>
#include <stdlib.h>
#include "stateMachine.h"

bool StateMachine_Initialize(stateMachine_t* stateMachine, size_t tableSize, void* context)
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

  for (int i = 0; i <= tableSize; i++)
  {
    stateMachine->stateTable[i].stateId = i;
    stateMachine->stateTable[i].onEnter = NULL;
    stateMachine->stateTable[i].onExit  = NULL;
    stateMachine->stateTable[i].onState = NULL;
    stateMachine->stateTable[i].onStateChanged = NULL;
  }
  return true;
}

bool StateMachine_AddState(stateMachine_t* stateMachine, stateTable_t stateTable)
{
  if ((stateMachine->addedStates >= stateMachine->tableSize)
    || (stateTable.stateId >= stateMachine->tableSize)
  )
  {
    return false;
  }

  stateMachine->stateTable[stateMachine->addedStates] = stateTable;
  stateMachine->addedStates++;
  return true;
}

bool StateMachine_SwitchToState(stateMachine_t* stateMachine, uint8_t stateId)
{
  if ((stateId >= stateMachine->tableSize)
    || (stateId == stateMachine->currentState)
    || (stateId > stateMachine->addedStates)
  )
  {
    return false;
  }


  if ((stateMachine->currentState != StateMachine_INITSTATE)
      && (stateMachine->stateTable[stateMachine->currentState].onExit != NULL)
  )
  {
    stateMachine->stateTable[stateMachine->currentState].onExit(stateMachine->context);
  }
  stateMachine->currentState = stateId;

  if(stateMachine->stateTable[stateMachine->currentState].onEnter != NULL)
  {
    stateMachine->stateTable[stateMachine->currentState].onEnter(stateMachine->context);
  }
  if(stateMachine->stateTable[stateMachine->currentState].onState != NULL)
  {
    stateMachine->stateTable[stateMachine->currentState].onState(stateMachine->context);
  }
  if(stateMachine->stateTable[stateMachine->currentState].onStateChanged != NULL)
  {
    stateMachine->stateTable[stateMachine->currentState].onStateChanged(stateMachine->context);
  }
}

uint8_t StateMachine_GetCurrentState(stateMachine_t* stateMachine)
{
  return stateMachine->currentState;
}