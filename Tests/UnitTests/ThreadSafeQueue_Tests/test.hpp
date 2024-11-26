#pragma once

#include <gtest/gtest.h>
#include <memory>
#include <string>
#include "task.hpp"
#include "queue.hpp"
#include <thread>
#include <experimental/random>

inline std::string generated_words(size_t size){
    std::string word = "";
    for(size_t i = 0; i < size; i++){
        char ch = std::experimental::randint(65,122);
        word += ch;
    }
    return word;
}

struct TestTask {
    std::string message_;
    std::string name_;
    TestTask(std::string message, std::string name) : message_(message), name_(name) {};
    ~TestTask(){};

    bool operator== (const TestTask& task) const {
        return (task.message_== this->message_) && (task.name_== this->name_);
    }
};

class ThreadSafeQueueTest : public ::testing::Test{

protected:
    void SetUp() override;
    void TearDown() override;
};