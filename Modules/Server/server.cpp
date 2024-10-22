#include "server.hpp"


    Server::Server(std::unique_ptr<TgBot::Bot> ptr_bot, std::shared_ptr<Queue<CursedWordDetectingTask>> queue): ptr_bot_(std::move(ptr_bot)), queue_(queue){

        ptr_bot_->getEvents().onCommand("start", [&](TgBot::Message::Ptr message) {
            ptr_bot_->getApi().sendMessage(message->chat->id, "Hi!");
        });

        ptr_bot_->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {

            if (StringTools::startsWith(message->text, "/start")) {
                return;
            }

            queue->push(CursedWordDetectingTask(message->text, message->chat->title, message->from->firstName, message->from->lastName, message->from->id));
            
            ptr_bot_->getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
            Logger::getInstance().logInfo(Logger::Levels::Info, message->text);
        });

        signal(SIGINT, signal_handler);
        signal(SIGTERM, signal_handler);
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

    void Server::signal_handler(int signal){
        static size_t count_shutdown = 0;
        if(count_shutdown){
            Logger::getInstance().logInfo(Logger::Levels::Fatal, "CRUSH PROGRAMM!");
            std::exit(EXIT_FAILURE);
        }
        shutdown_requested = false;
        count_shutdown++;
        Logger::getInstance().logInfo(Logger::Levels::Critical, "EXIT FROM SERVER!");  
    }

    Server::~Server(){

    }

bool Server::shutdown_requested = true;
