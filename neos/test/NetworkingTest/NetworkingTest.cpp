
#include "gtest/gtest.h"
#include "server.hpp"

TEST(TcpIpTest, CanInitAndConnect)
{
  Neos::Networking::TTcpIpConfig serverConfig = {
    {127,0,0,1}, 
    .port = 8000,
  };
  Neos::Networking::TcpIpServer testServer = Neos::Networking::TcpIpServer(serverConfig);
  ASSERT_TRUE(testServer.Start()) << "Starting the server failed";
  //testServer.RunServer();
}