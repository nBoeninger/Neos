#pragma once

#if TARGET == LINUX
  #include "FileProxy_linux.h"
#endif

#include <string>

namespace Neos
{

  class FileHandler
  {
    public:
      FileHandler(const char* filename);
      ~FileHandler();

      void Write(std::string message);

    private:
      FileDescriptor* m_fileDescriptor;
  };
}