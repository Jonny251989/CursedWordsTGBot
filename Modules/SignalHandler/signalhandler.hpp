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

static void sendsignal(int signal);


private:
static int count_shutdown;
static std::unordered_map<int, std::function<void()>> signals;

};

