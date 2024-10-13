#include <stdio.h>
#include <tgbot/tgbot.h>
#include <iostream>
#include <ostream>
#include "queue.hpp"
#include "task.hpp"
#include "memory"
#include <string>
#include "server.hpp"
#include "parser.hpp"

int main(int argc, char *argv[]) {

    std::string token = "-list fde_2-234fs  -token                     7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo  -number AAH0;3!=Cx-0w+UQ ";

    Parser parser{{"-token", "-list", "-number"}};
    std::unordered_map<std::string, std::string> tokens;

    try{
        tokens = parser.parsing_string(token);
    }

    catch(std::invalid_argument const& ex){
        std::cout<<ex.what();
        tokens = parser.getTokens();
        for(std::pair<std::string, std::string> pair : tokens)
            std::cout<<pair.first<<" ";
        std::cout<<"\n";
        std::exit(EXIT_FAILURE);
    }
    
    std::shared_ptr<Queue<Task>> ptr_queue = std::make_shared<Queue<Task>>();

    std::unique_ptr<TgBot::Bot> ptr_bot= std::make_unique<TgBot::Bot>(tokens["-token"]);

    Logger::getInstance().setName(ptr_bot->getApi().getMe()->username);
    Logger::getInstance().setLevel(Logger::Levels::Debug);

    Server server(std::move(ptr_bot), ptr_queue);

    server.start();

    return 0;
}

