#pragma once

/**
 * @brief The DataObject Module
*/

#include "signals.hpp"

namespace Neos
{
  namespace DataStructures
  {

    /**
     * @brief The DataObject Class
     * @details A DataObject can be any type and will emit signals a Changed Signal
     *          as soon as the Object value changes. No Signal will be emitted when initialzing! 
    */
    template<class T>
    class DataObject
    {
      public:

      /**
       * @brief Create an emtpty dataObject, ctor
      */
      DataObject(){};
      DataObject(T value) : m_value(value) {};

      /**
       * @brief The value setter
      */
      void SetValue(T value);
      
      /**
       * @brief The value getter
      */
      T GetValue();

      /**
       * @brief The changed signal
      */
      Communication::Signal<T> changed;

      DataObject& operator=(const T& lhr)
      {
        this->SetValue(lhr);
        return *this;
      }; 

      private:

      T m_value;

    };

    template<class T>
    T DataObject<T>::GetValue()
    {
     return m_value; 
    }

    template<class T>
    void DataObject<T>::SetValue(T value)
    {
      m_value = value;
      changed.Emit(m_value);
    }

  }
}