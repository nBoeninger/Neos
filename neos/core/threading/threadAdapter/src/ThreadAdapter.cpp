#include "ThreadAdapter.hpp"
#include "SysDefines.hpp"

Neos::ThreadAdapter::ThreadAdapter(ThreadAttributes_t attributes, const char* threadName, Logging* logger):
  m_threadName(threadName), m_attributes(attributes), m_logger(logger)
{
  CreateThreadParameter();
}

Neos::ThreadAdapter::ThreadAdapter(ThreadAttributes_t attributes, const char* threadName):
  m_threadName(threadName), m_attributes(attributes)
{
  m_logger = nullptr;
  CreateThreadParameter();
}

Neos::ThreadAdapter::~ThreadAdapter()
{

}

void Neos::ThreadAdapter::CreateThreadParameter()
{
  int ret = ThreadProxy_initParameter(&m_parameter);
  if (ret != 0)
  {
    char buffer[60];
    sprintf(buffer, "Init thread parameter failed with error code: %d", ret);
    LogError(buffer);
  }

  ret = ThreadProxy_setSchedPolicy(m_attributes.schedulingPolicy, &m_parameter);
  if (ret != 0)
  {
    char buffer[60];
    sprintf(buffer, "Set scheduling policy failed with error code: %d", ret);
    LogError(buffer);
  }

  ret = ThreadProxy_setSchedPriority(m_attributes.schedulingPriority, &m_parameter);
  if (ret != 0)
  {
    char buffer[60];
    sprintf(buffer, "Set scheduling priority failed with error code: %d", ret);
    LogError(buffer);
  }

  ret = ThreadProxy_setStackSize(m_attributes.stackSize, &m_parameter);
  if (ret != 0)
  {
    char buffer[60];
    sprintf(buffer, "Set stacksize failed with error code: %d", ret);
    LogError(buffer);
  }
}

void Neos::ThreadAdapter::Kill()
{

}

void Neos::ThreadAdapter::Start()
{
  int ret = ThreadProxy_create(&m_threadHandler, Neos::ThreadAdapter::RunFunction, this, &m_parameter);
  if (ret != 0)
  {
    char buffer[60];
    sprintf(buffer, "Creating thread failed with error code: %d", ret);
    LogError(buffer);
  }
  else
  {
    LogInfo("Thread started");
  }
}

void Neos::ThreadAdapter::Stop()
{

}

FunctionReturn_t Neos::ThreadAdapter::RunFunction(void* context)
{
  Neos::ThreadAdapter* self =  static_cast<Neos::ThreadAdapter*>(context);
  return nullptr;
}

void Neos::ThreadAdapter::LogInfo(std::string message)
{
  if(m_logger != nullptr)
  {
    m_logger -> Info(message, m_threadName);
  }
}

void Neos::ThreadAdapter::LogError(std::string message)
{
  if(m_logger != nullptr)
  {
    m_logger -> Error(message, m_threadName);
  }
}