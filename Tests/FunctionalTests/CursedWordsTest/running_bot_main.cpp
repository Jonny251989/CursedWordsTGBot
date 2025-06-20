
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "run_bot.hpp"


int main() {
    const char* token = std::getenv("TELEGRAM_TOKEN_2");
    
    std::jthread mainThread([&]() {
        run_bot("7763682966:AAEFBGifblSqB5of8cyS5WKjC6kK6pxTIuY");
    });
    // run_bot("7763682966:AAEFBGifblSqB5of8cyS5WKjC6kK6pxTIuY");


    // std::this_thread::sleep_for(std::chrono::seconds(30));
    // std::raise(SIGINT);
    return 0;
}