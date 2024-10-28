#include "queue.hpp"


    Queue::Queue(const size_t limit): limit_(limit){

    }

    bool Queue::push(std::unique_ptr<Task> task){
        if(deque.size() < limit_){
            
            std::unique_lock<std::mutex> lock(mutex);         
            deque.push_back(std::move(task));

            return true;
        }
        return false;
    }

	size_t Queue::size(){
        std::lock_guard lg(mutex);
        return deque.size();
    }

    bool Queue::empty(){
        return deque.empty();
    }
    
    std::unique_ptr<Task>Queue::front(){
        
        if(!deque.empty()){
            std::lock_guard lg(mutex);
            return std::move(deque.front());
        }
        return nullptr;
    };

    bool Queue::pop(){
        
        if(!deque.empty()){         
            std::unique_lock<std::mutex> lock(mutex); // Блокируем мьютекс
            cond.wait(lock, [this] { return !deque.empty(); }); // Ждем, пока не появятся данные
            deque.pop_front();
            return true;
        }
        return false;
    }

    Queue::~Queue(){
            
    }