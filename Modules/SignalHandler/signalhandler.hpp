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
    SignalHandler(std::vector<int> signals, const std::function<void()> handler);
    ~SignalHandler();
};

