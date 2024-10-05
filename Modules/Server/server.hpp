#pragma once

#include <cstdlib>
#include <deque>
#include <string>
#include <stdio.h>
#include <tgbot/tgbot.h>
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <signal.h>
#include "queue.hpp"
#include "task.hpp"


template <typename T>
class Server{
private:
    TgBot::Bot bot_;
    std::shared_ptr<Queue<T>> queue_;
    std::mutex m_;
    inline static bool shutdown_requested_ = true;
public:

    Server(const std::string& token, std::shared_ptr<Queue<T>> queue): bot_(token), queue_(queue){

        bot_.getEvents().onCommand("start", [&](TgBot::Message::Ptr message) {
            bot_.getApi().sendMessage(message->chat->id, "Hi!");
        });

        bot_.getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {

            if (StringTools::startsWith(message->text, "/start")) {
                return;
            }

            {
                std::lock_guard lg(m_);
                (queue.get())->push(T(message->text, message->chat->title, message->from->firstName, message->from->lastName, message->from->id));
            }
            std::cout << "message:" << message->text << "\n";
            bot_.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);

        });

        signal(SIGINT, signal_handler);
        signal(SIGTERM, signal_handler);
    }

    void start(){
        try {
                TgBot::TgLongPoll longPoll(bot_);

                while (shutdown_requested_) {
                    longPoll.start();
                }
            } 
            catch (TgBot::TgException& e) {
                
            }
    }

    static void signal_handler(int signal){
        static size_t count_shutdown = 0;
        if(count_shutdown){
            std::cout<<"\nEXIT FROM PROGRAMM!\n";
            std::exit(EXIT_FAILURE);
        }
        std::cout<<"\nEXIT FROM SERVER!\n";
        shutdown_requested_ = false;
        count_shutdown++;
    }

    ~Server(){

    }
};

