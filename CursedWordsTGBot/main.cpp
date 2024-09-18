#include <stdio.h>
#include <tgbot/tgbot.h>
#include <iostream>
#include <ostream>
#include "server.h"
#include <string>


int main(int argc, char *argv[]) {

   std::string token = "7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo";
   Server server(token);
   server.start();

    return 0;
}

