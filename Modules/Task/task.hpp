#pragma once

#include <memory>
#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <string>
#include "logger.hpp"
#include "classificator.hpp"
#include "reactor.hpp"

class ITask{
public:
    virtual void execute() = 0;
    ~ITask() = default;
};

class IClassificator;
class IReactor;
class CRTask: public ITask{
public:
    CRTask(std::shared_ptr<IClassificator> classificator, std::shared_ptr<IReactor> react);
    virtual void execute() override;
    ~CRTask();
protected:
    std::shared_ptr<IClassificator> classificator_; 
    std::shared_ptr<IReactor> reactor_; 
};


class CursedWordDetectingTask: public CRTask{
public:
    CursedWordDetectingTask(std::shared_ptr<IClassificator> classificator, std::shared_ptr<IReactor> react, std::string mss, std::string cht, std::string fN, std::string lN, std::int64_t id);
    virtual void execute() override;
    ~CursedWordDetectingTask();
private:
    std::string message;
    std::string chat_title;
    std::string firstName;
    std::string lastName;
    std::int64_t id_m;
};