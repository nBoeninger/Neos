#include "ThreadAdapter.hpp"
#include "SysDefines.hpp"


Neos::ThreadAdapter::ThreadAdapter(TThreadAttributes attributes, const char* threadName):
  m_threadName(threadName), m_attributes(attributes)
{
  ThreadProxy_setschedparam(m_attributes.schedulingPolicy, m_attributes.schedulingPriority, m_attributes.stackSize, &m_parameter); 
}

Neos::ThreadAdapter::~ThreadAdapter()
{

}

void Neos::ThreadAdapter::Kill()
{

}

void Neos::ThreadAdapter::Start()
{
  int ret = ThreadProxy_create(&m_threadHandler, Neos::ThreadAdapter::RunFunction, this, &m_parameter);
}

void Neos::ThreadAdapter::Stop()
{

}

TFunctionReturn Neos::ThreadAdapter::RunFunction(void* context)
{
  Neos::ThreadAdapter* self =  static_cast<Neos::ThreadAdapter*>(context);
  return nullptr;
}