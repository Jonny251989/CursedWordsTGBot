#pragma once

#include <csignal>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <string>
#include "logger.hpp"

class SignalHandler{
    
public:
SignalHandler(std::vector<int> signals, std::function<void()> handler);
~SignalHandler();

private:
    std::vector<int> signals_;
    std::function<void()> handler_;
    static void invoke(int);
};