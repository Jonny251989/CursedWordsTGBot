#pragma once

#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <string>
#include "logger.hpp"
#include "task.hpp"

class IReactor{
public:
    virtual std::string send_message() = 0;
    ~IReactor() = default;
};


class CursedWordDetectingReactor: public IReactor{
public:
    CursedWordDetectingReactor();
    virtual std::string send_message() override;
    ~CursedWordDetectingReactor();
private:

};