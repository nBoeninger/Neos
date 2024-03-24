#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdint.h>

#define StateMachine_MAXSIZE 16
#define StateMachine_INITSTATE -1

/**
 * @brief The State Machine Module
*/

/**
 * @brief The State Table Struct
 * @param stateId The state id, not used internal, just for reading!
 * @param onEnter Function that will be called on entering the state
 * @param onExit Function that will be called on exiting the state
 * @param OnState Function that will be called after entering the state
 * @param onStateChanged Function that will be called when changing a state
*/
typedef struct stateTable_t
{
  uint8_t stateId;
  void (*onEnter)(void* context);
  void (*onExit)(void* context);
  void (*onState)(void* context); 
  void (*onStateChanged) (void* context);
} stateTable_t;

/**
 * @brief The State Machine Data Struct
*/
typedef struct stateMachine_t
{
  size_t tableSize;
  int8_t currentState;
  uint8_t addedStates;
  stateTable_t stateTable[StateMachine_MAXSIZE];
  void* context;

} stateMachine_t;

/**
 * @brief Initialize the State Machine
 * @param[in] stateMachine: The State Machine Data Struct
 * @param[in] stateTable: The State Table Memory
 * @param[in] tableSize: The size of the StateTable
 * @return true if successfull
*/
bool StateMachine_Initialize(stateMachine_t* stateMachine, size_t tableSize, void* context);

/**
 * @brief Add a State to the Machine
 * @param[in] stateMachine: The State Machine Data Struct
 * @param[in] stateTable: The Table to be added
 * @return true if successfull
*/
bool StateMachine_AddState(stateMachine_t* stateMachine, stateTable_t stateTable);

/**
 * @brief Switch to State
 * @details Switchtes to the state if possible
 * @param[in] stateMachine: The State Machine Data Struct
 * @param[in] stateId: The StateId to switch to
 * @return true if successfull
*/
bool StateMachine_SwitchToState(stateMachine_t* stateMachine, uint8_t stateId);

/**
 * @brief Get the current State
 * @return the StateId
*/
uint8_t StateMachine_GetCurrentState(stateMachine_t* stateMachine);


#ifdef __cplusplus
}
#endif