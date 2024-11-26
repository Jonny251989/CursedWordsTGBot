#pragma once

#include <deque>
#include <mutex>
#include <optional>
#include <memory>
#include <condition_variable>

template <class Type>
class Queue {

public:
    Queue(const size_t limit = 100);
    bool push( std::unique_ptr<Type> task);
    std::unique_ptr<Type> take();
    ~Queue();

private:
    const size_t limit_;
    std::deque<std::unique_ptr<Type>> deque;
    std::mutex mutex;
};

template <class Type>
Queue<Type>::Queue(const size_t limit): limit_(limit){

}

template <class Type>
bool Queue<Type>::push(std::unique_ptr<Type> task){
    std::lock_guard lock(mutex);         
    if(deque.size() < limit_){
        deque.push_back(std::move(task));
        return true;
    }
    return false;
}

template <class Type>
std::unique_ptr<Type> Queue<Type>::take() {
    
    std::lock_guard lock(mutex);
    if(!deque.empty()){   
        auto item = std::move(deque.front());
        deque.pop_front();
        return item;
    }
    return nullptr;
}

template <class Type>
Queue<Type>::~Queue() {}