#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cstdint>
#include <cstddef>
#include <memory>

template<class T>
struct ListElement
{
public:
    ListElement(): next(nullptr){};

    ListElement<T>* next;
    T data;
};

template<class T>
class LinkedList
{
public:

    // Constructor
    LinkedList(): m_head(nullptr), m_list_lenght(0){};
    ~LinkedList();

    // save val to List
    bool save(T value);

    // get the first element of list
    T getFront();

    // get current list length
    size_t getLen();

    // remove item from list, return uint32_t
    bool remove(uint64_t value);

protected:
    ListElement<T>* m_head;
    size_t m_list_lenght;
};

template<class T>
LinkedList<T>::~LinkedList()
{
    // Clean everything up in the list
    ListElement<T> *p_current = m_head;
    ListElement<T> *p_nxt = nullptr;

    while (p_current != nullptr)
    {
        p_nxt = p_current -> next;
        delete p_current;
        p_current = p_nxt;
        this -> m_list_lenght-- ;
    }
    m_head = nullptr;

}

template<class T>
bool LinkedList<T>::save(T value)
{
    // get the adress of our new memory 
    ListElement<T> *p_mem_elem = (new ListElement<T>);
    if (p_mem_elem == nullptr)
    {
        return false;
    }
    
    p_mem_elem -> data = value;

    // insert first element
    if (m_head == nullptr)
    {
        m_head = p_mem_elem;
        this -> m_list_lenght++;
        return false;
    }

    // start at the m_head
    ListElement<T>* p_tmp_head = m_head;

    // go through the list until we reach the null
    while (p_tmp_head != nullptr)
    {
        if (p_tmp_head -> next == nullptr)
        {
            p_tmp_head -> next = p_mem_elem;
            this -> m_list_lenght++;
            return true;
        }
        p_tmp_head = p_tmp_head -> next;
    }
    // we shouldn't get here...
    return false;
}

template<class T>
T LinkedList<T>::getFront()
{
    if (m_head != nullptr)
    {
        T ret = m_head -> data;
        ListElement<T>* del_id = m_head;

        m_head = m_head -> next;
        this -> m_list_lenght--;
        return ret;
    }
}

template<class T>
size_t LinkedList<T>::getLen()
{
    return this -> m_list_lenght;
}

template<class T>
bool LinkedList<T>::remove(uint64_t id)
{
    // get the id of the value     
    
    ListElement<T>* p_tmp_curr = m_head;
    ListElement<T>* p_tmp_prev = m_head;
    while (p_tmp_curr != nullptr)
    {
        uint64_t elem_id = *((uint64_t*)(&(p_tmp_curr -> data)));
        if (elem_id == id)
        {
            // rearrange list
            // and free the no longer needed memory
            p_tmp_prev -> next  = p_tmp_curr -> next;
            this -> m_list_lenght--;
            return true;
        }

        p_tmp_prev = p_tmp_curr;
        p_tmp_curr = p_tmp_curr->next;
    }
    return false;
}

#endif