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
#include <boost/algorithm/string.hpp>

std::string get_arguments_string(size_t argc, char**argv){
    std::vector<std::string> arguments_command_line;
    for(size_t i = 1; i < argc; i++)
        arguments_command_line.push_back(argv[i]);
    std::string joined_string = boost::algorithm::join(arguments_command_line, " ");
    return joined_string;
}

int main(int argc, char *argv[]) {

    std::string token = get_arguments_string(argc, argv);
    Parser parser{{"-token"}};
    std::unordered_map<std::string, std::string> tokens;
    try{
        tokens = parser.parse_string(token);
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

