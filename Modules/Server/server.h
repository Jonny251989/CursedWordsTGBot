#ifndef SERVER_H
#define SERVER_H

#include <deque>
#include <vector>
#include <string>
#include <stdio.h>
#include <tgbot/tgbot.h>
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include "queue.hpp"
#include "task.h"


class Server{
private:
    TgBot::Bot bot;
    std::shared_ptr<Queue<Task>> queue;
    std::mutex m2;
public:

    Server(std::string token);


    void start();


    ~Server();
};



#endif // MODEL_H