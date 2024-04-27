
#include "gtest/gtest.h"
#include "tcpIpServer.hpp"

TEST(TcpIpTest, CanInit)
{
  Neos::Communication::TTcpIpServerConfig serverConfig = {
    {127,0,0,1}, 
    .port = 8000,
  };
  Neos::Communication::TcpIpServer testServer = Neos::Communication::TcpIpServer(serverConfig);
  testServer.StartServer();
  testServer.RunServer();
}