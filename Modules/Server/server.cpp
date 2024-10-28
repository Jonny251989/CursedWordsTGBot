#include "server.hpp"


    Server::Server(std::unique_ptr<TgBot::Bot> ptr_bot, std::shared_ptr<Queue> queue): ptr_bot_(std::move(ptr_bot)), queue_(queue){

        ptr_bot_->getEvents().onCommand("start", [&](TgBot::Message::Ptr message) {
            ptr_bot_->getApi().sendMessage(message->chat->id, "Hi!");
        });

        ptr_bot_->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {

            if (StringTools::startsWith(message->text, "/start")) {
                return;
            }

            queue_->push(std::make_unique<CursedWordDetectingTask>(message->text, message->chat->title, message->from->firstName, message->from->lastName, message->from->id));
            ptr_bot_->getApi().sendMessage(message->chat->id, "Your message is: " + message->text);

        });
    }

    void Server::start(){
        try {
                TgBot::TgLongPoll longPoll(*ptr_bot_);

                while (shutdown_requested) {
                    Logger::getInstance().logInfo(Logger::Levels::Info, "Long poll started");
                    longPoll.start();
                }
            } catch (TgBot::TgException& e) {
                Logger::getInstance().logInfo(Logger::Levels::Fatal, e.what());
            }
    }


    void Server::terminate(){
        shutdown_requested = false;
    }

    Server::~Server(){

    }

