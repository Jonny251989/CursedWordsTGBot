#include "generator.hpp"
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

int main() {
    const char* token = std::getenv("TELEGRAM_TOKEN_2");
    
    Generator generator("7212434431:AAFLuR1mQTqpageO7x575hkQzW7DzJTXdNs");
    generator.generator();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}