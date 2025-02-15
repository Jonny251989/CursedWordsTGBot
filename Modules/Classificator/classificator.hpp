#pragma once

#include <memory>
#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <string>
#include "logger.hpp"
#include "mutex"
#include <cstdio>  // для popen и pclose
#include <cstdlib>  // для std::stod
#include <chrono>
#include <stdexcept>
#include <Python.h>
#include <numpy/arrayobject.h>

class IClassificator{
public:
    virtual std::string check() = 0;
    virtual ~IClassificator() = default;
};

class SimpleClassificator: public IClassificator{
public:
    SimpleClassificator(const std::string& message);
    virtual std::string check() override;
    ~SimpleClassificator();


private:
    std::string message_;
};