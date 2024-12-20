
#include "gtest/gtest.h"
#include "Logging.hpp"


TEST(LoggingTest, CanCreateLogFile)
{
  Neos::Logging logger = Neos::Logging("Test", Neos::ELogLevel::DEBUG);
  logger.Log(Neos::DEBUG, "TestLog Message", "");

}