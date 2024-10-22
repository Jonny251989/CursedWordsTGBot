#include "worker.hpp"

Worker::Worker(std::shared_ptr<Queue<CursedWordDetectingTask>> queue_ptr):queue_ptr_(queue_ptr){

}

void Worker::work(){

    while(queue_ptr_->size()){
        std::optional<std::reference_wrapper<CursedWordDetectingTask>> task = queue_ptr_->front();
        task.value().get().execute();
        if (queue_ptr_->pop())
            continue;
    }
}

Worker::~Worker(){

}