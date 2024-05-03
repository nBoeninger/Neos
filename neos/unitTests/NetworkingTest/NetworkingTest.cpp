
#include "gtest/gtest.h"
#include <thread>

#include "tcpIpServer.hpp"
#include "tcpIpClient.hpp"
#include "TTcpIp.hpp"

#define TEST_RUNS 10
volatile int received = 0;

void On_MsgReceived(Neos::Networking::ReceivedMessage_t msg)
{
  received = 1;
}

void RunServer(Neos::Networking::TcpIpConfig_t config) 
{
  for (int i = 0; i < TEST_RUNS; i++)
  {
    {
      Neos::Networking::TcpIpServer tcpServer = Neos::Networking::TcpIpServer(config);  
      tcpServer.SMessageReceived.Connect(On_MsgReceived);
      ASSERT_TRUE(tcpServer.Start()) << "Starting the server failed";
      int connectionfd = tcpServer.WaitForConnections();
      ASSERT_FALSE(connectionfd < 0) << "Server didn't accept connection";
      tcpServer.Read(connectionfd);
    }
    sleep(1);
  }
}

void RunClient(Neos::Networking::TcpIpConfig_t config)
{
  for(int i = 0; i<TEST_RUNS; i++)
  {
    {
      Neos::Networking::TcpIpClient tcpClient = Neos::Networking::TcpIpClient(config);
      ASSERT_TRUE(tcpClient.Connect()) << "Starting the client failled";
      uint8_t testBuffer[] = {'4', '2', '3', '7', 'a', 'k'}; 
      tcpClient.Send(testBuffer, sizeof(testBuffer));
    }
    sleep(1);
  }
}

TEST(TcpIpTest, CanInitAndConnect)
{
  Neos::Networking::TcpIpConfig_t config = {
    {127,0,0,1}, 
    .port = 8000,
  };

  std::thread serverThread(RunServer, config);
  std::thread clientThread(RunClient, config);

  serverThread.join();
  clientThread.join();

}