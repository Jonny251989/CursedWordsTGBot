#pragma once

#include <deque>
#include <mutex>
#include <optional>
#include <memory>
#include <condition_variable>

#include "task.hpp"

class Queue {

public:

    Queue(const size_t limit = 100);

    bool push( std::unique_ptr<Task> task);
	size_t size();
    bool empty();
    std::unique_ptr<Task> front();
    bool pop();

    ~Queue();

    private:

    const size_t limit_;
    std::deque<std::unique_ptr<Task>> deque;
    std::mutex mutex;
    std::condition_variable cond;

};


