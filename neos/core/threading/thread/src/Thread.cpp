#include "Thread.hpp"
#include "SysDefines.hpp"

Neos::Thread::Thread(ThreadAttributes_t attributes, const char* threadName, Logging* logger):
  m_threadName(threadName), m_attributes(attributes), m_logger(logger)
{
  CreateThreadParameter();
}

Neos::Thread::Thread(ThreadAttributes_t attributes, const char* threadName):
  m_threadName(threadName), m_attributes(attributes)
{
  m_logger = nullptr;
  CreateThreadParameter();
}

Neos::Thread::~Thread()
{

}

void Neos::Thread::CreateThreadParameter()
{
  int ret = ThreadProxy_initParameter(&m_parameter);
  if (ret != 0)
  {
    LogError("Init thread parameter failed with error code: %d", ret);
  }

  ret = ThreadProxy_setSchedPolicy(m_attributes.schedulingPolicy, &m_parameter);
  if (ret != 0)
  {
    LogError("Set scheduling policy failed with error code: %d", ret);
  }

  ret = ThreadProxy_setSchedPriority(m_attributes.schedulingPriority, &m_parameter);
  if (ret != 0)
  {
    LogError("Set scheduling priority failed with error code: %d", ret);
  }

  ret = ThreadProxy_setStackSize(m_attributes.stackSize, &m_parameter);
  if (ret != 0)
  {
    LogError("Set stacksize failed with error code: %d, %f", ret, 2.6);
  }
}

void Neos::Thread::Kill()
{

}

void Neos::Thread::Start()
{
  int ret = ThreadProxy_create(&m_threadHandler, Neos::Thread::RunFunction, this, &m_parameter);
  if (ret != 0)
  {
    LogError("Creating thread failed with error code: %d", ret);
  }
  else
  {
    LogInfo("Thread started");
  }
}

void Neos::Thread::Stop()
{

}

FunctionReturn_t Neos::Thread::RunFunction(void* context)
{
  Neos::Thread* self =  static_cast<Neos::Thread*>(context);
  return nullptr;
}
