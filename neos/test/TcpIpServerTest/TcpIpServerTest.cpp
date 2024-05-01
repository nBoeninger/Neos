
#include "gtest/gtest.h"
#include "tcpIpServer.hpp"

TEST(TcpIpTest, CanInit)
{
  Neos::Networking::TTcpIpServerConfig serverConfig = {
    {127,0,0,1}, 
    .port = 8000,
  };
  Neos::Networking::TcpIpServer testServer = Neos::Networking::TcpIpServer(serverConfig);
  testServer.StartServer();
  //testServer.RunServer();
}