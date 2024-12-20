#pragma once

#include "SysDefines.hpp"
#include "Mutex.hpp"
#include <string>

namespace Neos
{

  const uint8_t MAX_LOG_MESSAGE_LENGHT = 255;
  const uint8_t MAX_DATE_LENGHT = 40;

  enum ELogLevel 
  {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
  };

  class Logging
  {
    public:

      Logging(std::string filename, std::string path, ELogLevel logLevel, std::string contextName);
      Logging(std::string filename, std::string path, ELogLevel logLevel);
      Logging(std::string filename, ELogLevel logLevel, std::string contextName);
      Logging(std::string filename, ELogLevel logLevel);

      void Log(ELogLevel level, std::string logMessage, std::string contextName);

      void Debug(std::string logMessage, std::string contextName);
      void Info(std::string logMessage, std::string contextName);
      void Warning(std::string logMessage, std::string contextName);
      void Error(std::string logMessage, std::string contextName);
      void Critical(std::string logMessage, std::string contextName);

    private:

      void Initialize();

      void WriteToFile(std::string logMessage);
      void WriteToStream(std::string logMessage);

      std::string FormatMessage(std::string logMessage, std::string contextName, ELogLevel logLevel);

      std::string m_filename;
      std::string m_path;
      ELogLevel m_logLevel;
  };
}

