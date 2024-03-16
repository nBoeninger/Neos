#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include "linkedList.hpp"
#include <cstddef>
#include <functional>

/**
 * @brief The SlotsAndSignals Module
 * @details A easy Implementation of Signals and Slots
 *             Slots can be connected to Signals which will be called
 *             after the Signal is emitted. The Slot will be called 
 *             within in the signals context!. 
*/

namespace Neos
{
  
  // Slot implementaion
  template<class T>
  class Slot 
  {
  public:
      Slot(std::function<void(T)>func): m_func(func){};   
      Slot(){};
      void Call(T val);
      uint64_t GetId();
  
  private:
      std::function<void (T)>m_func;
  };
  
  template<class T>
  uint64_t Slot<T>::GetId()
  {
      void (*func_address)(T) = *(this -> m_func);
      uint64_t id = *((uint64_t*) (&func_address));
      return id;
  }
  
  template<class T>
  void Slot<T>::Call(T val)
  {
      this -> m_func(val);
  }
  
  // The Signal implementation. It inherit from the Linked
  // List. The connected Slots are saved in the List.
  template<class T>
  class Signal: DataStructures::LinkedList<Slot<T>>
  {
  public:
      Signal(){};
      
      // connect functions
      void Connect(std::function<void(T)> s);
      
      template <typename Ctx>
      void Connect(Ctx *inst, void (Ctx::*func)(T))
      {  
          this -> Save(Slot<T>([=](T t){(inst->*func)(t);}));
      };
  
      void Emit(T value);
      void Disconnect(Slot<T> s);
  };
  
  
  template<class T>
  void Signal<T>::Connect(std::function<void(T)> s)
  {
      this -> Save(s);
  }
  
  template<class T>
  void Signal<T>::Disconnect(Slot<T> s)
  {
      this -> RemoveID(s.get_id());
  }
  
  template<class T>
  void Signal<T>::Emit(T value)
  {
      
      DataStructures::ListElement<Slot<T>>* p_tmpHead = this -> m_head;
  
      while (p_tmpHead != nullptr)
      {
          p_tmpHead -> data.Call(value);
          p_tmpHead = p_tmpHead -> next;
      }
  
  }
 
}

#endif