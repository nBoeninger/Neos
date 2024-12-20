#include "Logging.hpp"
#include "FileHandler.hpp"
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
  }

  void Logging::Log(Neos::ELogLevel level, std::string logMessage, std::string contextName)
  {
    #if LOGGING
      if (level >= m_logLevel)
      {
        Neos::Mutex lock = Neos::Mutex();
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
    Neos::FileHandler handler = Neos::FileHandler(m_path.c_str());
    handler.Write(logMessage.c_str());
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

    char currentTime[MAX_DATE_LENGHT];
    GetCurrentDate(currentTime);
    std::string date = currentTime;
    int pos = date.find("\n");
    if (pos != 0)
    {
      date.erase(pos);
    }

    sprintf(buffer, "%s - %s - %s: %s\n", date.c_str(), contextName.c_str(), logLevelText.c_str(), logMessage.c_str());
    formatedLogMessage.append(buffer);
    
    return formatedLogMessage;
  }
}