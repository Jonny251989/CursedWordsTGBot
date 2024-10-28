#include "worker.hpp"

Worker::Worker(std::shared_ptr<Queue<ITask>> queue_ptr):queue_ptr_(queue_ptr){

}

void Worker::terminate(){
    shutdown_requested = true;
}

void Worker::run(){
    decltype(queue_ptr_->take()) task_ptr;
    while (!shutdown_requested || (task_ptr = queue_ptr_->take())){
        if (!task_ptr)
            task_ptr->execute();
    }
}

Worker::~Worker(){

}