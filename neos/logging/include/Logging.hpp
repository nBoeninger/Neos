#pragma once

#include "SysDefines.hpp"
#include "Mutex.hpp"
#include <string>
#include <sstream>
#include <memory>

namespace Neos
{

  static const uint8_t MAX_TOTAL_LOG_MESSAGE_LENGHT = 255;
  const uint8_t MAX_DATE_LENGHT = 25;
  const uint8_t MAX_LEVEL_LENGHT = 10;
  const uint8_t MAX_FILE_NAME_LENGHT = 40;
  const uint8_t MAX_LOG_MESSAGE_LENGTH = MAX_TOTAL_LOG_MESSAGE_LENGHT-MAX_DATE_LENGHT-MAX_LEVEL_LENGHT;

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

      Logging(const char* filename, const char* path, ELogLevel logLevel, const char* contextName);
      Logging(const char* filename, const char* path, ELogLevel logLevel);
      Logging(const char* filename, ELogLevel logLevel, const char* contextName);
      Logging(const char* filename, ELogLevel logLevel);

      template<typename ...Args>
      void Log(ELogLevel level, const char* contextName, const char* message, Args&& ...args);

      template<typename ...Args>
      void Debug(const char*    contextName, const char* message, Args&& ...args)
      {Log(ELogLevel::DEBUG, contextName, message, args...);};

      template<typename ...Args>
      void Info(const char*     contextName, const char* message, Args&& ...args)
      {Log(ELogLevel::INFO, contextName, message, args...);};

      template<typename ...Args>
      void Warning(const char*  contextName, const char* message, Args&& ...args)
      {Log(ELogLevel::WARNING, contextName, message, args...);};

      template<typename ...Args>
      void Error(const char*    contextName, const char* message, Args&& ...args)
      {Log(ELogLevel::ERROR, contextName, message, args...);};

      template<typename ...Args>
      void Critical(const char* contextName, const char* message, Args&& ...args)
      {Log(ELogLevel::CRITICAL, contextName, message, args...);};

    private:

      template<typename ...Args>
      std::string LogSprintf(const char* formatedString, Args&& ...args );

      void Initialize(const char* filename);

      void WriteToFile(std::string logMessage);
      void WriteToStream(const char* logMessage);

      std::string FormatMessage(const char* logMessage, const char* contextName, ELogLevel logLevel);

      char m_filename[MAX_FILE_NAME_LENGHT];
      std::string m_path;
      ELogLevel m_logLevel;
  };

  template<typename ...Args>
  std::string Logging::LogSprintf(const char * formatedString, Args&& ...args)
  {
      int size = snprintf( nullptr, 0, formatedString, args... );
      std::string res;
      res.resize( size );
      snprintf( & res[ 0 ], size + 1, formatedString, args... );
      return res;
  }

  template<typename ...Args>
  void Logging::Log(Neos::ELogLevel level, const char* contextName, const char* message, Args&& ...args)
  { 
    #if LOGGING

      std::string buffer = LogSprintf(message, args...);
            
      if (level >= m_logLevel)
      {
        Neos::Mutex lock = Neos::Mutex();
        std::string formatedLogMessage = FormatMessage(buffer.c_str(), contextName, level);
        WriteToFile(formatedLogMessage);
        
        #if LOGGING_STREAM
          WriteToStream(formatedLogMessage);
        #endif

      }
    #endif
  };

}
