#pragma once

#include <deque>
#include <mutex>
#include <optional>
#include <condition_variable>

template <typename T>
class Queue {

public:
    Queue(const size_t limit_ = 100): limit(limit_){

    }
    bool push(T task){
        if(deque.size() < limit){
            std::lock_guard lg(m);
            deque.push_back(task);
            return true;
        }
        return false;
    }
	size_t size(){
        std::lock_guard lg(m);
        return deque.size();
    }
    std::optional<std::reference_wrapper<T>> front(){
        
        if(!deque.empty()){
            std::lock_guard lg(m);
            return std::ref(deque.front());
        }
        return std::nullopt;
    };
    bool pop(){
        
        if(!deque.empty()){         
            std::lock_guard lg(m);
            deque.pop_front();
            return true;
        }
        return false;
    }
    ~Queue(){
            
    }

private:
    const size_t limit;
    std::deque<T> deque;
    std::mutex m;
    std::condition_variable cond;

};


