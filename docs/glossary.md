# Guidelines

# Variables Names
Variables are named in camelCase. Pointer are indicated with an p_.  
Member variables are indicated with an m_.

Variables may contain one of the following shortcuts:
   - curr = current
   - nxt = next
   - tmp = temporary
   - mem = memory
   - elem = element

# NewTypes
New types are indicated with an _t after the typename. New types start with an captial letter.
Files including the definition of new types may start with an capital T, if they only include type definitions.

# Class Names
Classes are written in PascalCase.
## Class Functions
Class Functions start with a Capital Letter
## Signals Names
Signals will start with an capital S.

# Slots
Slots starts with the Prefix On, followed by one underscore -> On_FunctionName.

# Comments
Comments are written to describe the why, not the how, since the code explains that.
Classes, Functions, Structs are commented in Doxygen Style.

# Namespaces
The cpp files will be wrapped around in namespaces. The c files will be have the Module Name as an indication. Example: StateMachine_Initialize etc.
