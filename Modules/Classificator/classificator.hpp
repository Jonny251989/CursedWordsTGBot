#pragma once

#include <memory>
#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <string>
#include "logger.hpp"
#include "task.hpp"

class CRTask;

class IClassificator{
public:
    virtual bool check(const CRTask&) = 0;
    ~IClassificator() = default;
};

class CursedWordDetectingClassificator: public IClassificator{
public:
    CursedWordDetectingClassificator();
    virtual bool check(const CRTask&) override;
    ~CursedWordDetectingClassificator();
private:

};