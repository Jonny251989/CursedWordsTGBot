#include "worker.hpp"

Worker::Worker(std::shared_ptr<Queue> queue_ptr):queue_ptr_(queue_ptr){

}

void Worker::run(){
    std::cout<<"Here\n";
    while(true){
        if(auto task = queue_ptr_->front())
            task->execute();
        if (queue_ptr_->pop())
            continue;
    }
}

Worker::~Worker(){

}