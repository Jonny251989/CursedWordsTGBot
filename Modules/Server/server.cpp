#include "server.hpp"


    Server::Server(std::unique_ptr<TgBot::Bot> ptr_bot, std::shared_ptr<Queue<ITask>> queue): ptr_bot_(std::move(ptr_bot)), queue_(queue){

        ptr_bot_->getEvents().onCommand("start", [&](TgBot::Message::Ptr message) {
            ptr_bot_->getApi().sendMessage(message->chat->id, "Hi!");
        });
        ptr_bot_->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
        // Логируем текст полученного сообщения
        printf("Received message: %s\n", message->text.c_str());

        // Отправляем ответ в тот же чат
        std::string response = "You said: " + message->text;
        ptr_bot_->getApi().sendMessage(message->chat->id, response);
    });
        ptr_bot_->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
        if (message->from->isBot) {
            // Сообщение от бота
            printf("Message received from bot: %s\n", message->text.c_str());
        } else {
            // Сообщение от пользователя
            printf("Message received from user: %s\n", message->text.c_str());
        }
            if (StringTools::startsWith(message->text, "/start")) {
                return;
            }
            std::cout<<"ID chat: "<<message->chat->id<<"\n";
            if (!queue_->push(std::make_unique<CursedWordDetectingTask>(std::make_shared<SimpleClassificator>(message->text),
             std::make_shared<EchoReactor>(ptr_bot_, message->text, message->chat->id, message->from)))){

                Logger::getInstance().logInfo(Logger::Levels::Critical, "Queue is full!"); 
                std::this_thread::sleep_for (std::chrono::milliseconds(100));
            }
        });


    }

    void Server::start(){
        try {
                TgBot::TgLongPoll longPoll(*ptr_bot_);

                while (!shutdown_requested) {
                    Logger::getInstance().logInfo(Logger::Levels::Info, "Long poll started");
                    longPoll.start();
                }
            } catch (TgBot::TgException& e) {
                Logger::getInstance().logInfo(Logger::Levels::Fatal, e.what());
            }
    }

    void Server::terminate(){
        shutdown_requested = true;
    }

    Server::~Server(){

    }