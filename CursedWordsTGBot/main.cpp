
#include <vector>
#include <string>
#include <stdio.h>
#include <tgbot/tgbot.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "server.h"
#include "test.h"
#include "queue.hpp"


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}




// int main() {

//     Server server;
//     //server.start();

//     std::thread server_t(&Server::start, &server);
//     server_t.detach();
    
    
//     return 0;
// }