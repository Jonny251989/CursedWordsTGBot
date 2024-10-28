#include "signalhandler.hpp"


SignalHandler::SignalHandler(std::vector<int> vec_of_signals, std::function<void()> handler){
    for(const auto& signal: vec_of_signals)
        std::signal(signal, handler);
    
}
SignalHandler::~SignalHandler() {}