#include "Logging.hpp"
#include "SysDefines.hpp"
#include "Timing.h"

namespace Neos
{

  Logging::Logging(std::string filename, std::string path, ELogLevel logLevel) : m_filename(filename), m_path(path), m_logLevel(logLevel)
  {
    Initialize();
  }

  Logging::Logging(std::string filename, ELogLevel logLevel) : m_filename(filename), m_path(LOGGING_PATH), m_logLevel(logLevel)
  {
    Initialize();
  }

  void Logging::Initialize()
  {
    m_filename.append(".log");
    m_path.append(m_filename);
    m_fileDescriptor = nullptr;
  }

  void Logging::Log(Neos::ELogLevel level, std::string logMessage, std::string contextName)
  {
    #if LOGGING
      if (level >= m_logLevel)
      {
        std::string formatedLogMessage = FormatMessage(logMessage, contextName, level);
        WriteToFile(formatedLogMessage);
        
        #if LOGGING_STREAM
          WriteToStream(formatedLogMessage);
        #endif

      }
    #endif
  }

  void Logging::Debug(std::string logMessage, std::string contextName)
  {
    Log(ELogLevel::DEBUG, logMessage, contextName);
  }

  void Logging::Info(std::string logMessage, std::string contextName)
  {
    Log(ELogLevel::INFO, logMessage, contextName);
  }

  void Logging::Warning(std::string logMessage, std::string contextName)
  {
    Log(ELogLevel::WARNING, logMessage, contextName);
  }

  void Logging::Error(std::string logMessage, std::string contextName)
  {
    Log(ELogLevel::ERROR, logMessage, contextName);
  }

  void Logging::Critical(std::string logMessage, std::string contextName)
  {
    Log(ELogLevel::CRITICAL, logMessage, contextName);
  }

  void Logging::WriteToFile(std::string logMessage)
  {
    
    m_fileDescriptor = FileProxy_open(m_path.c_str(), "a");
    if (m_fileDescriptor != nullptr)
    {
      FileProxy_put(m_fileDescriptor, logMessage.c_str());
      FileProxy_close(m_fileDescriptor);
    }
  }

  void Logging::WriteToStream(std::string logMessage)
  {
    //TODO: fill me
  }

  std::string Logging::FormatMessage(std::string logMessage, std::string contextName, ELogLevel logLevel)
  {
    std::string formatedLogMessage;
    char buffer[MAX_LOG_MESSAGE_LENGHT];
    std::string logLevelText;

    switch (logLevel)
    {
    case ELogLevel::DEBUG:
    {
      logLevelText = "Debug";
    }
    break;
    case ELogLevel::INFO: 
    {
      logLevelText = "Info";  
    }
    break;
    case ELogLevel::WARNING:
    {
      logLevelText = "Warning";
    }
    break;
    case ELogLevel::ERROR:
    {
      logLevelText = "Error";
    }
    break;
    case ELogLevel::CRITICAL:
    {
      logLevelText = "Critical";
    }
    break;
    default:
      break;
    }

    sprintf(buffer, "%d - %s - %s: %s\n", GetCurrentTicks(), contextName.c_str(), logLevelText.c_str(), logMessage.c_str());
    formatedLogMessage.append(buffer);
    
    return formatedLogMessage;
  }

}