
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

     TgBot::Bot bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
        bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
            bot.getApi().sendMessage(message->chat->id, "Hi!");
        });
        bot.getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
            printf("User wrote %s\n", message->text.c_str());

            
            if (StringTools::startsWith(message->text, "/start")) {
                return;
            }

            bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
        });
        
        try {
            printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());

            TgBot::TgLongPoll longPoll(bot);

            while (true) {
                printf("Long poll started\n");
                longPoll.start();
            }
        } catch (TgBot::TgException& e) {
            printf("error: %s\n", e.what());
        }

//   ::testing::InitGoogleTest(&argc, argv);
//   ::testing::InitGoogleMock(&argc, argv);
  
//   return RUN_ALL_TESTS();
}




// int main() {

//     Server server;
//     //server.start();

//     std::thread server_t(&Server::start, &server);
//     server_t.detach();
    
    
//     return 0;
// }