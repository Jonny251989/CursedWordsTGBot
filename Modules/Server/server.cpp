#include "server.h"


    Server::Server(std::string token): bot(token){
        queue = std::make_shared<Queue<Task>>();
        std::cout<<"CONSTRUCT\n";
    }


    void Server::start(){


        std::lock_guard l_q(m2);
        std::cout<<"BEGIN\n";
        
        bot.getEvents().onCommand("start", [&](TgBot::Message::Ptr message) {
            bot.getApi().sendMessage(message->chat->id, "Hi!");
        });
        bot.getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
            printf("User wrote %s\n", message->text.c_str());

            (queue.get())->push(Task(message->text, message->chat->title, message->from->firstName, message->from->lastName, message->from->id));
            
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
    }

    Server::~Server(){

    }