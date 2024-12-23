#include "Logging.hpp"
#include "FileHandler.hpp"
#include "SysDefines.hpp"
#include "Timing.h"

#include "cstring"
#include <cstdarg>

namespace Neos
{

  Logging::Logging(const char* filename, const char* path, ELogLevel logLevel) : m_path(path), m_logLevel(logLevel)
  {
    Initialize(filename);
  }

  Logging::Logging(const char* filename, ELogLevel logLevel) : m_path(LOGGING_PATH), m_logLevel(logLevel)
  {
    Initialize(filename);
  }

  void Logging::Initialize(const char* filename)
  {
    if (strlen(m_filename) < MAX_FILE_NAME_LENGHT)
    {
      sprintf(m_filename, "%s.log", filename);
      m_path.append(m_filename);
      int t = 0;
    }
  }

  void Logging::WriteToFile(std::string logMessage)
  {
    Neos::FileHandler handler = Neos::FileHandler(m_path.c_str());
    handler.Write(logMessage);
  }

  void Logging::WriteToStream(const char* logMessage)
  {
    //TODO: fill me
  }

  std::string Logging::FormatMessage(const char* logMessage, const char* contextName, ELogLevel logLevel)
  {
    std::string formatedLogMessage;
    char buffer[MAX_TOTAL_LOG_MESSAGE_LENGHT];
    char logLevelText[MAX_LEVEL_LENGHT];
    char currentTime[MAX_DATE_LENGHT];

    switch (logLevel)
    {
    case ELogLevel::DEBUG:
    {
      sprintf(logLevelText, "Debug");
    }
    break;
    case ELogLevel::INFO: 
    {
      sprintf(logLevelText, "Info");
    }
    break;
    case ELogLevel::WARNING:
    {
      sprintf(logLevelText, "Warning");
    }
    break;
    case ELogLevel::ERROR:
    {
      sprintf(logLevelText, "Error");
    }
    break;
    case ELogLevel::CRITICAL:
    {
      sprintf(logLevelText, "Critical");
    }
    break;
    default:
      break;
    }

    GetCurrentDate(currentTime);
    std::string date = currentTime;
    int pos = date.find("\n");
    if (pos != 0)
    {
      date.erase(pos);
    }

    sprintf(buffer, "%s - %s - %s: %s\n", date.c_str(), contextName, logLevelText, logMessage);
    formatedLogMessage = buffer;
    return formatedLogMessage;
  }
}