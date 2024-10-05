#pragma once

#include <iostream>
#include <fstream>
#include <mutex>
#include <memory>
#include <string>
#include <chrono>
#include <ctime>
//#include "date.h"
#include <source_location>

class Logger {
public:


    enum class Levels {Debug, Info, Critical, Fatal};


    // Получение единственного экземпляра логгера
    static Logger& getInstance() {
        static Logger instance; // Инициализация при первом вызове
        return instance;
    }

    void setLevel(const Levels& level){
        level_ = level;
    }

    void setName(const std::string& name){
        bot_name_ = name;
    }

    char* get_time(time_t unix_timestamp){
        char* time_buf = new char[80];
        struct tm ts;
        ts = *localtime(&unix_timestamp);
        strftime(time_buf, sizeof(time_buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
        std::cout<<"time_buf "<<time_buf<<std::endl;
        return time_buf;
    }

    // Запись информационного сообщения
    void logInfo(const Levels& level, const std::string& message, const std::source_location location = std::source_location::current()) {
        if(level >= level_){
            
            std::lock_guard<std::mutex> guard(logMutex);

            const auto p1 = std::chrono::system_clock::now();
            const auto time_date_stamp =  std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();

            std::tm* t = std::gmtime(&time_date_stamp);
            std::stringstream ss; 
            ss << std::put_time(t, "%Y-%m-%d %I:%M:%S %p");
            std::string output = ss.str();

            std::clog << "Name:"<<bot_name_<< "\nLevel: " << static_cast<std::underlying_type<Levels>::type>(level_)<<"\nMessage: "<< message <<
            "\nTime is "<< output <<"\nFile: "
              << location.file_name() << '('
              << location.line() << ':' 
              << location.column() << ")\n";
        }
    }

private:
    Logger() = default;

    ~Logger() {

    }

    // Запрет копирования и перемещения
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    std::mutex logMutex;   // Мьютекс для потокобезопасности
    std::string bot_name_;
    Levels level_;
};