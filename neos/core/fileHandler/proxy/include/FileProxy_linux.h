#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#define FileDescriptor FILE

FileDescriptor* FileProxy_open(const char* pathToFile, const char* mode);
void FileProxy_close(FileDescriptor* fileHandler);
void FileProxy_put(FileDescriptor* fileHandler, const char * message);

#ifdef __cplusplus
}
#endif