#include "worker.hpp"

Worker::Worker(std::shared_ptr<Queue> queue_ptr):queue_ptr_(queue_ptr){

}

void Worker::terminate(){
    shutdown_requested = false;
}

void Worker::run(){
    while(shutdown_requested){

        if(auto task_ptr = queue_ptr_->front()){
            task_ptr->execute();
            queue_ptr_->pop();
        }
    }
}

Worker::~Worker(){

}