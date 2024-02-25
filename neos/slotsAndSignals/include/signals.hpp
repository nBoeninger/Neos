#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include "linkedList.hpp"
#include <cstddef>
#include <functional>

// Slot implementaion
template<class T>
class Slot 
{
public:
    Slot(std::function<void(T)>func): m_func(func){};   
    Slot(){};
    void call(T val);
    uint64_t get_id();

private:
    std::function<void (T)>m_func;
};

template<class T>
uint64_t Slot<T>::get_id()
{
    void (*func_address)(T) = *(this -> m_func);
    uint64_t id = *((uint64_t*) (&func_address));
    return id;
}

template<class T>
void Slot<T>::call(T val)
{
    this -> m_func(val);
}

// The Signal implementation. It inherit from the Linked
// List. The connected Slots are saved in the List.
template<class T>
class Signal: LinkedList<Slot<T>>
{
public:
    Signal(){};
    
    // connect functions
    void connect(std::function<void(T)> s);
    
    template <typename Ctx>
    void connect(Ctx *inst, void (Ctx::*func)(T))
    {  
        this -> save(Slot<T>([=](T t){(inst->*func)(t);}));
    };

    void emit(T value);
    void disconnect(Slot<T> s);
};


template<class T>
void Signal<T>::connect(std::function<void(T)> s)
{
    this -> save(s);
}

template<class T>
void Signal<T>::disconnect(Slot<T> s)
{
    this -> removeID(s.get_id());
}

template<class T>
void Signal<T>::emit(T value)
{
    
    ListElement<Slot<T>>* p_tmpHead = this -> m_head;

    while (p_tmpHead != nullptr)
    {
        p_tmpHead -> data.call(value);
        p_tmpHead = p_tmpHead -> next;
    }

}

#endif