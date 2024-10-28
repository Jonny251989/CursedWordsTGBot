#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "task.hpp"
#include "queue.hpp"


class Worker{
    public:

    Worker(std::shared_ptr<Queue> queue_ptr);
    void run();
    void terminate();
    ~Worker();

    private:
    std::shared_ptr<Queue> queue_ptr_;
    bool shutdown_requested = true;
};