#include "Mutex.hpp"

Neos::Mutex::Mutex()
{
  MutexProxy_init(&m_handler, NULL);
  MutexProxy_lock(&m_handler);
}

Neos::Mutex::~Mutex()
{
  MutexProxy_unlock(&m_handler);
}
