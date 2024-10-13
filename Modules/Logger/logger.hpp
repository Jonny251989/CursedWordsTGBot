#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <memory>
#include <string>
#include <chrono>
#include <ctime>
#include <source_location>

class Logger {

public:
    enum class Levels {Debug, Info, Critical, Fatal};
    
    // Получение единственного экземпляра логгера
    static Logger& getInstance();

    void setLevel(const Levels& level);

    void setName(const std::string& name);

    // Запись информационного сообщения
    void logInfo(const Levels& level, const std::string& message, const std::source_location location = std::source_location::current());

private:
    Logger() = default;

    ~Logger();

    // Запрет копирования и перемещения
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    std::mutex logMutex;   // Мьютекс для потокобезопасности
    std::string bot_name_;
    Levels level_;
    inline static std::map<Levels, std::string> levels_{
        {Levels::Debug, "Debug"},
        {Levels::Info, "Info"},
        {Levels::Critical, "Critical"},
        {Levels::Fatal, "Fatal"}
    };
};