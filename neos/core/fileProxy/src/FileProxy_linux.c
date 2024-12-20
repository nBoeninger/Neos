#include "FileProxy_linux.h"

FileDescriptor* FileProxy_open(const char* pathToFile, const char* mode)
{
  return fopen(pathToFile, mode);
}

void FileProxy_close(FileDescriptor* fileHandler)
{
  fclose(fileHandler);
}

void FileProxy_put(FileDescriptor* fileHandler, const char * message)
{
  fputs(message, fileHandler);
}