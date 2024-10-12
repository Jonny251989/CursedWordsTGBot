#include "logger.hpp"


    Logger& Logger::getInstance() {
        static Logger instance; // Инициализация при первом вызове
        return instance;
    }

    void Logger::setLevel(const Levels& level){
        level_ = level;
    }

    void Logger::setName(const std::string& name){
        bot_name_ = name;
    }

    // Запись информационного сообщения
    void Logger::logInfo(const Levels& level, const std::string& message, const std::source_location location) {
        if(level >= level_){

            const auto p1 = std::chrono::system_clock::now();
            const auto time_date_stamp =  (std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()) + std::chrono::hours(3)).count();

            std::tm* t = std::gmtime(&time_date_stamp);
            std::stringstream ss; 
            ss << std::put_time(t, "%Y-%m-%d %H:%M:%S");
            std::string output = ss.str();
        
            std::lock_guard<std::mutex> guard(logMutex);
            std::clog << "\n{ Name:"<<bot_name_
            << ", level: " << levels_[level_]
            <<", time: "<< output 
            <<", file:"
            << location.file_name() << '('
            << location.line() << ':' 
            << location.column() << ")"
            <<", message: "<< message <<" }\n";  
        }
    }


    Logger::~Logger() {

    }
