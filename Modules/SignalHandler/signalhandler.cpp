#include "signalhandler.hpp"


SignalHandler::SignalHandler(std::vector<int> vec_of_signals, std::function<void()> handler){
    for(const auto& signal: vec_of_signals)
        signals[signal] = handler;
    
}


void SignalHandler::sendsignal(int signal_){
        if(count_shutdown){
            Logger::getInstance().logInfo(Logger::Levels::Fatal, "Recieved shutdown signal. Stop polling");
            std::exit(EXIT_FAILURE);
        }
        count_shutdown++;

        if (signals.find(signal_) != signals.end())       
            signals[signal_]();

        Logger::getInstance().logInfo(Logger::Levels::Critical, "Recieved second shutdown signal. Exiting!");     
}

SignalHandler::~SignalHandler(){

}

int SignalHandler::count_shutdown = 0;

std::unordered_map<int, std::function<void()>> SignalHandler::signals;