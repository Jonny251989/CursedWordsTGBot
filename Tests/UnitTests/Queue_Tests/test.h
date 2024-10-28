#pragma once

#include <gtest/gtest.h>
#include <memory>
#include "task.hpp"
#include "queue.hpp"

struct TestTask {
    std::string str;
}

class QueueTest : public ::testing::Test{

protected:
    void SetUp() override;

    void TearDown() override;
    
    Queue<TestTask> queue;
};

