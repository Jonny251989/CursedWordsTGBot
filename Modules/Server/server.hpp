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
#include "logger.hpp"


class Server{

public:

    Server(std::unique_ptr<TgBot::Bot> ptr_bot, std::shared_ptr<Queue> queue);
    void start();
    static void signal_handler(int signal);
    ~Server();

private:
    std::unique_ptr<TgBot::Bot> ptr_bot_;
    std::shared_ptr<Queue> queue_;
    static bool shutdown_requested;
};

