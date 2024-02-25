#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

/**
 * @brief The LinkedList Module
**/

#include <cstdint>
#include <cstddef>
#include <memory>

/**
 * @brief A List Element Struct
 * @details The List Element contains the next pointer,
 *          aswell as the data to hold as an Template
 * **/
template<class T>
struct ListElement
{
public:
    ListElement(): next(nullptr){};

    ListElement<T>* next;
    T data;
};

/**
 * @brief The Linked List Class
 * **/
template<class T>
class LinkedList
{
public:

    // Constructor
    LinkedList(): m_head(nullptr), m_list_lenght(0){};
    ~LinkedList();

    /**
     * @brief Save a value to the List
     * @return succesfull ?
     * **/
    bool save(T value);

    // get the first element of list
    T getFront();

    // get current list length
    size_t getLen();

    // remove item from list, return uint32_t
    bool remove(uint64_t value);

protected:
    ListElement<T>* m_head;
    size_t m_listLenght;
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
        this -> m_listLenght-- ;
    }
    m_head = nullptr;

}

template<class T>
bool LinkedList<T>::save(T value)
{
    // get the adress of our new memory 
    ListElement<T> *p_memElem = (new ListElement<T>);
    if (p_memElem == nullptr)
    {
        return false;
    }
    
    p_mem_elem -> data = value;

    // insert first element
    if (m_head == nullptr)
    {
        m_head = p_memElem;
        this -> m_listLenght++;
        return false;
    }

    // start at the m_head
    ListElement<T>* p_tmpHead = m_head;

    // go through the list until we reach the null
    while (p_tmpHead != nullptr)
    {
        if (p_tmpHhead -> next == nullptr)
        {
            p_tmpHead -> next = p_memElem;
            this -> m_listLenght++;
            return true;
        }
        p_tmpHead = p_tmpHead -> next;
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
        ListElement<T>* deleteId = m_head;

        m_head = m_head -> next;
        this -> m_listLenght--;
        return ret;
    }
    // somethings missing here :D ...
}

template<class T>
size_t LinkedList<T>::getLen()
{
    return this -> m_listLenght;
}

template<class T>
bool LinkedList<T>::remove(uint64_t id)
{
    // get the id of the value     
    
    ListElement<T>* p_tmpCurr = m_head;
    ListElement<T>* p_tmpPrev = m_head;
    while (p_tmpCurr != nullptr)
    {
        uint64_t elemId = *((uint64_t*)(&(p_tmpCurr -> data)));
        if (elemId == id)
        {
            // rearrange list
            // and free the no longer needed memory
            p_tmpPrev -> next  = p_tmpCurr -> next;
            this -> m_listLenght--;
            return true;
        }

        p_tmpPrev = p_tmpCurr;
        p_tmpCurr = p_tmpCurr->next;
    }
    return false;
}

#endif