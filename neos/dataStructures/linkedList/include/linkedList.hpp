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

    /**
     * @brief Create a empty LinkedList
    */
    LinkedList(): m_head(nullptr), m_listLenght(0){};
    ~LinkedList();

    /**
     * @brief Save a value to the List
     * @return succesfull ?
     * **/
    bool save(T value);

    /**
     * @brief Get the first element
     * @return the first element, nullptr if no element exist
    */
    T getFront();

    /**
     * @brief Get the length of the List
     * @return A size_t of the length
    */
    size_t getLen();

    /**
     * @brief RemoveID from the list
     * @details This removes a id from the List. When multiple ids are found
     *            only the first is removed from the list 
     * @return succesfull?
     * */    
    bool removeID(uint64_t id);

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
    
    p_memElem -> data = value;

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
        if (p_tmpHead -> next == nullptr)
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
    //what do we do when none ?
    //return nullptr;
}

template<class T>
size_t LinkedList<T>::getLen()
{
    return this -> m_listLenght;
}

template<class T>
bool LinkedList<T>::removeID(uint64_t id)
{
    // get the id of the value     
    
    ListElement<T>* p_tmpCurr = m_head;
    ListElement<T>* p_tmpNxt = nullptr;
    while (p_tmpCurr != nullptr)
    {
        uint64_t elemId = *((uint64_t*)(&(p_tmpCurr -> data)));
        if (elemId == id)
        {
            // rearrange list
            // and free the no longer needed memory
            p_tmpNxt -> next  = p_tmpCurr -> next;

            delete p_tmpCurr; 
            this -> m_listLenght--;
            return true;
        }

        p_tmpNxt = p_tmpCurr;
        p_tmpCurr = p_tmpCurr->next;
    }
    return false;
}

#endif