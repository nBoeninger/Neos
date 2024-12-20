#include "FileHandler.hpp"

Neos::FileHandler::FileHandler(const char* filename) :
  m_fileDescriptor(FileProxy_open(filename, "a"))
{

}

Neos::FileHandler::~FileHandler()
{
  FileProxy_close(m_fileDescriptor);
}

void Neos::FileHandler::Write(std::string message)
{
  FileProxy_put(m_fileDescriptor, message.c_str());
}