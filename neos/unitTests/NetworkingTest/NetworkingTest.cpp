
#include "gtest/gtest.h"
#include <thread>

#include "tcpIpServer.hpp"
#include "tcpIpClient.hpp"
#include "TTcpIp.hpp"

static volatile int received = 0;

void On_MsgReceived(Neos::Networking::TReceivedMessage msg)
{
  received = 1;
}


TEST(TcpIpTest, CanInitAndConnect)
{
  Neos::Networking::TTcpIpConfig serverConfig = {
    {127,0,0,1}, 
    .port = 8000,
  };

  Neos::Networking::TcpIpServer testServer = Neos::Networking::TcpIpServer(serverConfig);  
  testServer.SMessageReceived.Connect(On_MsgReceived);

  ASSERT_TRUE(testServer.Start()) << "Starting the server failed";
  std::thread serverThread(&Neos::Networking::TcpIpServer::Run, testServer);
  
  Neos::Networking::TcpIpClient testClient = Neos::Networking::TcpIpClient(serverConfig);
  ASSERT_TRUE(testClient.Start()) << "Starting the client failled";
  ASSERT_TRUE(received == 0) << "Received value is false, wanted: " << 0 << ", received: " << received;

  uint8_t testBuffer[] = {'4', '2', '3', '7', 'a', 'k'}; 
  testClient.Send(testBuffer, sizeof(testBuffer));

  ASSERT_TRUE(received == 1) << "Received value is false, wanted: " << 1 << ", received: " << received;

}