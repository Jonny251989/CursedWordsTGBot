#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "task.hpp"
#include "queue.hpp"


class Worker{
    public:

    Worker(std::shared_ptr<Queue<CursedWordDetectingTask>> queue_ptr);

    void work();

    ~Worker();

    private:
    std::shared_ptr<Queue<CursedWordDetectingTask>> queue_ptr_;
};