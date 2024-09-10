#pragma once

#include <deque>
#include <string>
#include <thread>
#include <mutex>
#include "task.h"
#include <optional>
#include <functional>

template <typename T>
class Queue {

private:
const size_t limit = 100;
std::deque<T> deque;
std::mutex m1;


public:

    Queue();
    bool push(T);
	size_t size();
    std::optional<std::reference_wrapper<T>> front();
    bool pop();

    T& operator[](size_t i);

    ~Queue();
};

template <typename T>
Queue<T>::Queue(){

}

template <typename T>
bool Queue<T>::push(T task){
    std::lock_guard lg(m1);
    if(deque.size() <= limit){
        deque.push_back(task);
        return true;
    }

    return false;
}

template <typename T>
std::optional<std::reference_wrapper<T>> Queue<T>::front(){
    std::lock_guard lg(m1);
    if(!deque.empty()){
        return std::ref(deque.front());
    }
    return std::nullopt;
}

template <typename T>
bool Queue<T>::pop(){
    std::lock_guard lg(m1);
    if(!deque.empty()){
        deque.pop_front();
        return true;
    }
    return false;
}

template <typename T>
size_t Queue<T>::size(){
    std::lock_guard lg(m1);
    return deque.size();
}

template <typename T>
Queue<T>::~Queue(){

}

