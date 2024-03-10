#pragma once

/**
 * @brief The ValidReturn Module
 * @details returns true if a returned values is valid and can be read
*/

namespace Neos
{
  namespace DataStructures
  {

    template<class T>
    struct ValidReturn
    {
      ValidReturn(T retValue) : m_ret(retValue), m_valid(true){}; 
      ValidReturn() : m_valid(false){};

      bool operator==(const ValidReturn<T>& lhs);
      bool operator==(const bool& lhs);
      bool operator!();
      operator T();

      T m_ret;
      bool m_valid;
    };

    template<class T>
    bool ValidReturn<T>::operator==(const ValidReturn<T>& lhs) 
    {
      return this == lhs.m_valid;
    }

    template<class T>
    bool ValidReturn<T>::operator==(const bool& lhs)
    {
      return this->m_valid == lhs;
    }

    template<class T>
    bool ValidReturn<T>::operator!()
    {
      return !this->m_valid;
    }

    template<class T>
    ValidReturn<T>::operator T()
    {
      return this -> m_ret;
    }

  }
}