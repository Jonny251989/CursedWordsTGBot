#include <stdio.h>
#include <tgbot/tgbot.h>
#include <iostream>
#include <ostream>

#include "logger.hpp"
#include "parser.hpp"
#include "server.hpp"
#include "worker.hpp"
#include <vector>
#include <string>
#include <algorithm>


int main(int argc, char *argv[]) {

    Parser parser{{"-token"}};
    std::unordered_map<std::string, std::string> tokens;

    try{
        tokens = parser.parse_string("-token  7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    }
    catch(std::invalid_argument const& ex){
        Logger::getInstance().logInfo(Logger::Levels::Info, ex.what());
        std::exit(EXIT_FAILURE);
    }

    std::unique_ptr<TgBot::Bot> ptr_bot = std::make_unique<TgBot::Bot>(tokens["-token"]);

    Logger::getInstance().setName(ptr_bot->getApi().getMe()->username);
    Logger::getInstance().setLevel(Logger::Levels::Debug);

    std::shared_ptr<Queue> ptr_queue = std::make_shared<Queue>();

    Server server(std::move(ptr_bot), ptr_queue);
    Worker worker(ptr_queue);

    //std::thread server_thread(&Server::start, &server);
    std::thread worker_thread(&Worker::run, &worker);
    server.start();

    //server_thread.detach();
    worker_thread.detach();

   
    return 0;
}

