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


std::string get_arguments_string(size_t argc, char**argv){
    std::string arguments_command_line = "";
    for(size_t i = 1; i < argc; i++){
        if(i != argc - 1)
            arguments_command_line = arguments_command_line + argv[i] + " ";
        else
            arguments_command_line = arguments_command_line + argv[i];       
    }
    return arguments_command_line;
}

int main(int argc, char *argv[]) {

    std::string arguments_command_line = get_arguments_string(argc, argv);
    std::cout << "arguments:"<<arguments_command_line<<"\n";
    
    Parser parser{{"-token"}};
    std::unordered_map<std::string, std::string> tokens;
    try{
        tokens = parser.parse_string(arguments_command_line);
    }
    catch(std::invalid_argument const& ex){
        Logger::getInstance().logInfo(Logger::Levels::Info, ex.what());
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

