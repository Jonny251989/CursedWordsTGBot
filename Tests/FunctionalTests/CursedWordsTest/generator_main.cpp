#include "generator.hpp"
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

int main() {
    const char* token = std::getenv("TELEGRAM_TOKEN_2");
    
    Generator generator("7913850529:AAHRcgeMjun-7U0mWsh5TF2NPUE8WyLGkLU");
    //"7913850529:AAHRcgeMjun-7U0mWsh5TF2NPUE8WyLGkLU"
    generator.generator();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}