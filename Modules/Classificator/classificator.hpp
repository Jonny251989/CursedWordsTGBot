#pragma once

#include <memory>
#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <string>
#include "logger.hpp"
#include "mutex"
#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
#include <boost/python.hpp>

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

    pybind11::module_ script_;

private:
    std::string message_;
};