
#include "gtest/gtest.h"
#include <thread>

#include "tcpIpServer.hpp"
#include "tcpIpClient.hpp"


TEST(TcpIpTest, CanInitAndConnect)
{
  Neos::Networking::TTcpIpConfig serverConfig = {
    {127,0,0,1}, 
    .port = 8000,
  };

  Neos::Networking::TcpIpServer testServer = Neos::Networking::TcpIpServer(serverConfig);  
  ASSERT_TRUE(testServer.Start()) << "Starting the server failed";
  std::thread serverThread(&Neos::Networking::TcpIpServer::RunServer, testServer);

  Neos::Networking::TcpIpClient testClient = Neos::Networking::TcpIpClient(serverConfig);
  ASSERT_TRUE(testClient.Start()) << "Starting the client failled";

  serverThread.join();
}