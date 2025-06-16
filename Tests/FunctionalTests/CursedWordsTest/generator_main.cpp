#include "generator.hpp"
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

int main() {
    const char* token = std::getenv("TELEGRAM_TOKEN");
    
    if (!token) {
        std::cerr << "Missing environment variables!" << std::endl;
        return 1;
    }

    Generator generator(token);
    generator.generator();

    return 0;
}