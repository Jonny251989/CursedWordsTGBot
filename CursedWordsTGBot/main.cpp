#include <stdio.h>
#include <tgbot/tgbot.h>
#include <iostream>
#include <ostream>
#include "server.hpp"
#include "queue.hpp"
#include "task.hpp"
#include <string>


int main(int argc, char *argv[]) {

   std::shared_ptr<Queue<Task>> ptr_queue = std::make_shared<Queue<Task>>();
   Server server(argv[1], ptr_queue);
   server.start();

    return 0;
}

